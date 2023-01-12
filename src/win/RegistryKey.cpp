#include "win/RegistryKey.h"
using win::RegistryKey;

RegistryKey::RegistryValueProxy::RegistryValueProxy(RegistryKey const& key)
  : m_key{&key}
{
}

RegistryKey::RegistryValueProxy::RegistryValueProxy(RegistryKey const& key, std::wstring_view name)
  : m_key{&key},
	m_valueName{name}
{
}

RegistryKey::RegistryValueProxy&
RegistryKey::RegistryValueProxy::operator=(RegistryValue value)
{
	this->m_key->m_api->setValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName, value);
	return *this;
}

RegistryKey::RegistryValueProxy::operator
win::RegistryValue() const
{
	return this->m_key->m_api->getValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName);
}

void
RegistryKey::RegistryValueProxy::remove()
{
	this->m_key->m_api->removeValue(this->m_key->m_handle, {/*no-child*/}, this->m_valueName);
}

RegistryKey::RegistryKey(SharedRegistryKey handle, AccessRight rights, SharedRegistryApi api)
  : m_api{ThrowIfEmpty(api)}, 
    m_handle{handle}, 
    m_rights{rights}
{
}

RegistryKey::RegistryKey(SharedRegistryKey parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api)
  : m_api{api}, 
    m_handle{ThrowIfEmpty(api)->openKey(parent, child, rights)}, 
    m_rights{rights}
{
}

RegistryKey::RegistryKey(meta::create_new_t, SharedRegistryKey parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api)
  : m_api{api}, 
    m_handle{ThrowIfEmpty(api)->createKey(parent, child, rights)}, 
    m_rights{rights}
{
}

win::RegistryKey
RegistryKey::subkey(std::wstring_view child, std::optional<AccessRight> rights) const
{
	return RegistryKey{this->m_handle, child, rights ? *rights : this->m_rights};
}

RegistryKey::RegistryValueProxy
RegistryKey::operator[](meta::use_default_t) const
{
	return RegistryValueProxy{*this};
}

RegistryKey::RegistryValueProxy
RegistryKey::operator[](std::wstring_view name) const
{
	return RegistryValueProxy{*this, ThrowIfEmpty(name)};
}

void
RegistryKey::remove()
{
	this->m_api->removeKey(this->m_handle, {/*no-child*/});
}

win::RegistryKey
RegistryKey::subkey(meta::create_new_t, std::wstring_view child, std::optional<AccessRight> rights)
{
	return RegistryKey{create_new, this->m_handle, child, rights ? *rights : this->m_rights};
}
