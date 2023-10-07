/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2023, Nick Crowley. All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions
*    and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of
*    conditions and the following disclaimer in the documentation and/or other materials provided
*    with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
* FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
* WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* The views and conclusions contained in the software and documentation are those of the author 
* and should not be interpreted as representing official policies, either expressed or implied, of
* the projects which contain it.
*/
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "win/RegistryApi.h"
#include "win/Function.h"
#include "win/ApiHelpers.h"
#include "win/DWord.h"
#include "win/LResult.h"
#include "win/ConstMultiStringIterator.h"
using namespace core;

namespace
{
	auto constexpr regCreateKeyEx = win::function<2>(::RegCreateKeyExW);	
	auto constexpr regOpenKeyEx = win::function<1>(::RegOpenKeyExW);
	auto constexpr regDeleteKeyEx = win::function(::RegDeleteKeyExW);
	auto constexpr regDeleteKeyValue = win::function(::RegDeleteKeyValueW);
	auto constexpr regSetKeyValue = win::function(::RegSetKeyValueW);
}

win::SharedRegistryApi
win::registryApi()
{
	auto static api = std::make_shared<RegistryApi>();
	return api;
}

win::SharedRegistryKey
win::RegistryApi::createKey(SharedRegistryKey root, std::wstring_view path, KeyRight rights, Lifetime life) const
{
	auto const flags = life == NonVolatile ? REG_OPTION_NON_VOLATILE : REG_OPTION_VOLATILE;
	auto [key, disposition] = regCreateKeyEx(*root, path.data(), Reserved<DWORD>, nullptr, flags, DWord{rights}, Unsecured);
	return SharedRegistryKey{key};
}

win::SharedRegistryKey
win::RegistryApi::openKey(SharedRegistryKey root, std::wstring_view path, KeyRight rights) const
{
	constexpr DWORD NotASymLink = NULL;
	return SharedRegistryKey{regOpenKeyEx(*root, path.data(), NotASymLink, DWord{rights})};
}


win::RegistryValue
win::RegistryApi::getValue(SharedRegistryKey root, std::wstring_view name) const
{
	::DWORD dataType{}, size{};
	if (LResult r = ::RegQueryValueExW(*root, name.data(), Reserved<DWORD*>, &dataType, nullptr, &size); !r && r != ERROR_MORE_DATA)
		r.throwAlways("Failed to query registry value '{}'", to_utf8(name));
	auto bytes = std::make_unique<std::byte[]>(size);
	if (LResult r = ::RegQueryValueExW(*root, name.data(), Reserved<DWORD*>, nullptr, nstd::cast_to<BYTE*>(bytes.get()), &size); !r)
		r.throwAlways("Failed to read registry value '{}'", to_utf8(name));
	
	switch (dataType)
	{
	default:
		LResult{ERROR_UNSUPPORTED_TYPE}.throwAlways("Cannot read registry value '{}' of unsupported type {:#06x}", to_utf8(name), dataType);

	case REG_BINARY:
		return std::vector<std::byte>{&bytes[0], &bytes[size]};

	case REG_DWORD:
		return *boost::reinterpret_pointer_cast<std::uint32_t>(std::move(bytes));

	case REG_QWORD:
		return *boost::reinterpret_pointer_cast<std::uint64_t>(std::move(bytes));

	case REG_SZ:
	case REG_MULTI_SZ: {
		auto const chars = boost::reinterpret_pointer_cast<wchar_t[]>(std::move(bytes));
		auto const strings = std::wstring_view{&chars[0], &chars[size/sizeof(wchar_t)]};
	
		if (dataType == REG_SZ)
			// Returned strings may-not be null-terminated but only @c ConstMultiStringIterator can handle this
			return std::wstring{!strings.ends_with(L'\0') ? strings : strings.substr(0, strings.length()-1)};
		else
			return std::vector<std::wstring>{ConstMultiStringIterator{strings}, ConstMultiStringIterator{}};
	}}
}
	
void
win::RegistryApi::setValue(SharedRegistryKey root, std::wstring_view path, std::wstring_view name, RegistryValue value) const
{
	if (auto* bytes = std::get_if<std::vector<std::byte>>(&value))
	{
		regSetKeyValue(*root, path.data(), name.data(), REG_BINARY, bytes->data(), DWord{bytes->size()});
	}
	else if (auto* int32 = std::get_if<std::uint32_t>(&value))
	{
		regSetKeyValue(*root, path.data(), name.data(), REG_DWORD, int32, sizeof(uint32_t));
	}
	else if (auto* int64 = std::get_if<std::uint64_t>(&value))
	{
		regSetKeyValue(*root, path.data(), name.data(), REG_QWORD, int64, sizeof(uint64_t));
	}
	else if (auto* str = std::get_if<std::wstring>(&value))
	{
		regSetKeyValue(*root, path.data(), name.data(), REG_SZ, str->data(), DWord{str->size()*sizeof(wchar_t)}); 
	}
	else if (auto* wstr = std::get_if<std::wstring_view>(&value))
	{
		regSetKeyValue(*root, path.data(), name.data(), REG_SZ, wstr->data(), DWord{wstr->size()*sizeof(wchar_t)}); 
	}
	else if (auto* multi = std::get_if<std::vector<std::wstring>>(&value))
	{
		auto constexpr static concatenate = [](std::wstring const& total, std::wstring const& e){ return total + e + L'\0'; };

		std::wstring const flat = std::accumulate(multi->begin(), multi->end(), std::wstring{}, concatenate) + L'\0';
		regSetKeyValue(*root, path.data(), name.data(), REG_MULTI_SZ, flat.c_str(), DWord{flat.size()*sizeof(wchar_t)}); 
	}
}

void
win::RegistryApi::removeKey(SharedRegistryKey root, std::wstring_view name) const
{
	constexpr DWORD NotUsingWowFlag = NULL;
	regDeleteKeyEx(*root, name.data(), NotUsingWowFlag, Reserved<DWORD>);
}
		
void
win::RegistryApi::removeValue(SharedRegistryKey root, std::wstring_view path, std::wstring_view name) const
{
	regDeleteKeyValue(*root, path.data(), name.data());
}
