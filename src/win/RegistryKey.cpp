#include "win/RegistryKey.h"
using namespace core;

win::RegistryKey::RegistryKey(SharedRegistryKey handle, KeyRight rights, SharedRegistryApi api)
  : m_api{ThrowIfEmpty(api)}, 
    m_handle{handle}, 
    m_rights{rights}
{
}

win::RegistryKey::RegistryKey(SharedRegistryKey parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api)
  : m_api{api}, 
    m_handle{ThrowIfEmpty(api)->openKey(parent, child, rights)}, 
    m_rights{rights}
{
}

win::RegistryKey::RegistryKey(meta::create_new_t, SharedRegistryKey parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api)
  : m_api{api}, 
    m_handle{ThrowIfEmpty(api)->createKey(parent, child, rights)}, 
    m_rights{rights}
{
}

win::RegistryKey
win::RegistryKey::subkey(std::wstring_view child, std::optional<KeyRight> rights) const
{
	return RegistryKey{this->m_handle, ThrowIfEmpty(child), rights ? *rights : this->m_rights};
}

void
win::RegistryKey::removeKey(std::wstring_view child)
{
	this->m_api->removeKey(this->m_handle, ThrowIfEmpty(child));
}

win::RegistryKey
win::RegistryKey::subkey(meta::create_new_t, std::wstring_view child, std::optional<KeyRight> rights)
{
	return RegistryKey{create_new, this->m_handle, ThrowIfEmpty(child), rights ? *rights : this->m_rights};
}
