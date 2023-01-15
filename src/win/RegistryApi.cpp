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
	auto constexpr regQueryValueEx = win::function<3>(::RegQueryValueExW);
	auto constexpr regSetKeyValue = win::function(::RegSetKeyValueW);
}

win::SharedRegistryApi
win::registryApi()
{
	auto static api = std::make_shared<RegistryApi>();
	return api;
}

win::SharedRegistryKey
win::RegistryApi::createKey(SharedRegistryKey root, std::wstring_view path, AccessRight rights, Lifetime life) const
{
	auto const flags = life == NonVolatile ? REG_OPTION_NON_VOLATILE : REG_OPTION_VOLATILE;
	auto [key, disposition] = regCreateKeyEx(*root, path.data(), Reserved<DWORD>, nullptr, flags, rights, Unsecured);
	return SharedRegistryKey{key};
}

win::SharedRegistryKey
win::RegistryApi::openKey(SharedRegistryKey root, std::wstring_view path, AccessRight rights) const
{
	constexpr DWORD NotASymLink = NULL;
	return SharedRegistryKey{regOpenKeyEx(*root, path.data(), NotASymLink, rights)};
}


win::RegistryValue
win::RegistryApi::getValue(SharedRegistryKey root, std::wstring_view path, std::wstring_view name) const
{
	auto [type, data, size] = regQueryValueEx(*root, path.data(), Reserved<DWORD*>);
	auto value = std::make_unique<std::byte[]>(size);
	ThrowingLResult result = ::RegQueryValueExW(*root, path.data(), Reserved<DWORD*>, nullptr, (BYTE*)value.get(), &size);
	
	switch (type)
	{
	default:
		win::throw_exception(ERROR_UNSUPPORTED_TYPE);

	case REG_BINARY:
		return std::vector<std::byte>{&value[0], &value[size]};

	case REG_DWORD:
		return *boost::reinterpret_pointer_cast<std::uint32_t>(std::move(value));

	case REG_QWORD:
		return *boost::reinterpret_pointer_cast<std::uint64_t>(std::move(value));

	case REG_SZ:
	case REG_MULTI_SZ:
		break;
	}

	auto const str = boost::reinterpret_pointer_cast<wchar_t[]>(std::move(value));
	auto const nChars = size/sizeof(wchar_t);
	auto const first = ConstMultiStringIterator{{&str[0], &str[nChars]}};
	
	if (type == REG_SZ)
		return std::wstring{*first};
	else
		return std::vector<std::wstring>{first, ConstMultiStringIterator{}};
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
	else if (auto* str = std::get_if<std::wstring_view>(&value))
	{
		regSetKeyValue(*root, path.data(), name.data(), REG_SZ, str->data(), DWord{str->size()*sizeof(wchar_t)}); 
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
