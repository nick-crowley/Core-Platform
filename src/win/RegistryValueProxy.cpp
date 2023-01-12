#include "win/RegistryKey.h"
using win::RegistryKey;

RegistryKey::ConstRegistryValueProxy::ConstRegistryValueProxy(RegistryKey const& key, meta::use_default_t)
  : m_key{&key}
{
}

RegistryKey::ConstRegistryValueProxy::ConstRegistryValueProxy(RegistryKey const& key, std::wstring_view name)
  : m_key{&key},
	m_valueName{name}
{
}

RegistryKey::ConstRegistryValueProxy::operator
win::RegistryValue() const
{
	return this->m_key->m_api->getValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName);
}

RegistryKey::RegistryValueProxy&
RegistryKey::RegistryValueProxy::operator=(RegistryValue value)
{
	this->m_key->m_api->setValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName, value);
	return *this;
}

void
RegistryKey::RegistryValueProxy::remove()
{
	this->m_key->m_api->removeValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName);
}
