#include "win/RegistryKey.h"
using win::RegistryKey;

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
