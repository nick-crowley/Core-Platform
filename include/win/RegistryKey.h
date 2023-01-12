#pragma once
#include "corePlatform.h"
#include "win/SmartHandle.h"
#include "win/RegistryValue.h"
#include "win/RegistryApi.h"
#include "security/KeyRight.h"

namespace win
{
	SharedRegistryKey const 
	inline ClassesRoot {HKEY_CLASSES_ROOT};

	SharedRegistryKey const 
	inline CurrentUser {HKEY_CURRENT_USER};

	SharedRegistryKey const 
	inline LocalMachine {HKEY_LOCAL_MACHINE};

	class RegistryKey
	{
		SharedRegistryApi m_api;
		SharedRegistryKey m_key;
		AccessRight m_rights;

	public:
		//! @brief	Open existing key
		RegistryKey(meta::open_existing_t, SharedRegistryKey handle, AccessRight rights, SharedRegistryApi api = registryApi());

		//! @brief	Open existing key
		RegistryKey(meta::open_existing_t, RegistryKey const& key, AccessRight rights, SharedRegistryApi api = registryApi());

		//! @brief	Open child of existing key
		RegistryKey(meta::open_existing_t, SharedRegistryKey parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi());

		//! @brief	Open child of existing key
		RegistryKey(meta::open_existing_t, RegistryKey const& parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi());

		//! @brief	Create child of existing key
		RegistryKey(meta::create_new_t, SharedRegistryKey parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi());
		
		//! @brief	Create child of existing key
		RegistryKey(meta::create_new_t, RegistryKey const& parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi());

		RegistryKey 
		createSubKey(std::wstring_view name) const;

		void 
		deleteSubKey(std::wstring_view name) const;
		
		RegistryValue 
		getValue() const;

		RegistryValue 
		getValue(std::wstring_view name) const;

		void 
		setValue(RegistryValue&& v) const;
		
		void 
		setValue(std::wstring_view name, RegistryValue&& v) const;
	};
}
