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
	public:
		class RegistryValueProxy
		{
			RegistryKey const* m_key;
			std::wstring_view m_valueName;

		public:
			explicit
			RegistryValueProxy(RegistryKey const& key);

			RegistryValueProxy(RegistryKey const& key, std::wstring_view name);

			satisfies(RegistryValueProxy,
				NotCopyable,
				NotMoveAssignable,
				IsMoveConstructible noexcept,
				NotEqualityComparable,
				NotSortable
			);
			
			RegistryValueProxy&
			operator=(RegistryValue value);

		public:
			implicit operator
			RegistryValue() const;

		public:
			void
			remove();
		};

	private:
		SharedRegistryApi m_api;
		SharedRegistryKey m_handle;
		AccessRight m_rights;

	public:
		//! @brief	Open existing key (identified by handle)
		RegistryKey(SharedRegistryKey handle, AccessRight rights, SharedRegistryApi api = registryApi());

		//! @brief	Open child of existing key  (identified by handle)
		RegistryKey(SharedRegistryKey parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi());
		
		//! @brief	Create child of key (identified by handle)
		RegistryKey(meta::create_new_t, SharedRegistryKey parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi());
		
		//! @brief	Open existing key
		RegistryKey(RegistryKey const& key, AccessRight rights, SharedRegistryApi api = registryApi())
		  : RegistryKey{key.m_handle, rights, api}
		{}

		//! @brief	Open child of existing key
		RegistryKey(RegistryKey const& parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi())
		  : RegistryKey{parent.m_handle, child, rights, api}
		{}

		//! @brief	Create child of key
		RegistryKey(meta::create_new_t, RegistryKey const& parent, std::wstring_view child, AccessRight rights, SharedRegistryApi api = registryApi())
		  : RegistryKey{meta::create_new, parent.m_handle, child, rights, api}
		{}
		
		satisfies(RegistryKey,
			IsCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);
			
	public:
		RegistryKey
		subkey(std::wstring_view child, std::optional<AccessRight> rights = std::nullopt) const;

		RegistryValueProxy
		operator[](meta::use_default_t) const;

		RegistryValueProxy
		operator[](std::wstring_view name) const;

	public:
		void
		remove();

		RegistryKey
		subkey(meta::create_new_t, std::wstring_view child, std::optional<AccessRight> rights = std::nullopt);
	};
}
