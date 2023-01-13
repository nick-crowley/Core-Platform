#include "win/RegistryKey.h"
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

win::RegistryKey::ConstRegistryValueProxy::operator
win::RegistryValue() const
{
	return this->m_key->m_api->getValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName);
}

win::RegistryKey::RegistryValueProxy&
win::RegistryKey::RegistryValueProxy::operator=(RegistryValue value)
{
	this->m_key->m_api->setValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName, value);
	return *this;
}

void
win::RegistryKey::RegistryValueProxy::remove()
{
	this->m_key->m_api->removeValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName);
}
