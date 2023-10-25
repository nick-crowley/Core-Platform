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
#include "win/RegistryKey.h"
#include "win/ApiHelpers.h"
using namespace core;

win::RegistryKey::ConstRegistryValueProxy::ConstRegistryValueProxy(RegistryKey const& key, meta::use_default_t)
  : m_key{&key}
{
}

win::RegistryKey::ConstRegistryValueProxy::ConstRegistryValueProxy(RegistryKey const& key, std::wstring_view name)
  : m_key{&key},
	m_valueName{name}
{
}

win::RegistryKey::RegistryValueProxy::RegistryValueProxy(RegistryKey& key, meta::use_default_t)
	: base{key,use_default}
{}

win::RegistryKey::RegistryValueProxy::RegistryValueProxy(RegistryKey& key, std::wstring_view name)
	: base{key,name}
{}

std::vector<std::byte>
win::RegistryKey::ConstRegistryValueProxy::as_bytes() const {
	RegistryValue const v = this->get();
	Invariant(std::holds_alternative<std::vector<std::byte>>(v));
	return std::get<std::vector<std::byte>>(v);
}

std::vector<std::wstring>
win::RegistryKey::ConstRegistryValueProxy::as_wstrings() const {
	RegistryValue const v = this->get();
	Invariant(std::holds_alternative<std::vector<std::wstring>>(v));
	return std::get<std::vector<std::wstring>>(v);
}

win::RegistryValue
win::RegistryKey::ConstRegistryValueProxy::get() const {
	return this->m_key->m_api->getValue(this->m_key->m_handle, this->m_valueName);
}

std::wstring
win::RegistryKey::ConstRegistryValueProxy::to_wstring() const {
	RegistryValue const v = this->get();
	Invariant(!std::holds_alternative<std::vector<std::byte>>(v)
	       && !std::holds_alternative<std::vector<std::wstring>>(v));
	
	if (std::holds_alternative<std::wstring>(v))
		return std::get<std::wstring>(v);

	else if (std::holds_alternative<std::wstring_view>(v)) {
		auto const sv = std::get<std::wstring_view>(v);
		return {sv.begin(), sv.end()};
	}
	else if (std::holds_alternative<uint32_t>(v)) {
		return std::to_wstring(std::get<uint32_t>(v));
	}
	else 
		return std::to_wstring(std::get<uint64_t>(v));
	
	static_assert(std::variant_size_v<win::RegistryValue> == 6);
}

uint32_t
win::RegistryKey::ConstRegistryValueProxy::to_uint32() const {
	RegistryValue const v = this->get();
	Invariant(!std::holds_alternative<std::vector<std::byte>>(v)
	       && !std::holds_alternative<std::vector<std::wstring>>(v));
	
	if (std::holds_alternative<std::wstring>(v))
		return std::stoul(std::get<std::wstring>(v));

	else if (std::holds_alternative<std::wstring_view>(v)) {
		auto const sv = std::get<std::wstring_view>(v);
		return std::stoul(std::wstring{sv.begin(), sv.end()});
	}
	else if (std::holds_alternative<uint32_t>(v)) 
		return std::get<uint32_t>(v);
	else {
		Invariant(std::get<uint64_t>(v) <= UINT32_MAX);
		return static_cast<uint32_t>(std::get<uint64_t>(v));
	}
	
	static_assert(std::variant_size_v<win::RegistryValue> == 6);
}

uint64_t
win::RegistryKey::ConstRegistryValueProxy::to_uint64() const {
	RegistryValue const v = this->get();
	Invariant(!std::holds_alternative<std::vector<std::byte>>(v)
	       && !std::holds_alternative<std::vector<std::wstring>>(v));
	
	if (std::holds_alternative<std::wstring>(v))
		return std::stoull(std::get<std::wstring>(v));

	else if (std::holds_alternative<std::wstring_view>(v)) {
		auto const sv = std::get<std::wstring_view>(v);
		return std::stoull(std::wstring{sv.begin(), sv.end()});
	}
	else if (std::holds_alternative<uint32_t>(v)) 
		return std::get<uint32_t>(v);
	else 
		return std::get<uint64_t>(v);
	
	static_assert(std::variant_size_v<win::RegistryValue> == 6);
}

std::wstring
win::RegistryKey::ConstRegistryValueProxy::wstr() const
{
	return this->to_wstring();
}

win::RegistryKey::ConstRegistryValueProxy::operator
win::RegistryValue() const
{
	return this->get();
}

win::RegistryKey::RegistryValueProxy&
win::RegistryKey::RegistryValueProxy::operator=(RegistryValue value)
{
	this->set(value);
	return *this;
}

void
win::RegistryKey::RegistryValueProxy::remove()
{
	this->m_key->m_api->removeValue(this->m_key->m_handle, win::Unused<std::wstring_view>, this->m_valueName);
}

void
win::RegistryKey::RegistryValueProxy::set(RegistryValue value)
{
	this->m_key->m_api->setValue(this->m_key->m_handle, win::Unused<std::wstring_view>, this->m_valueName, value);
}
