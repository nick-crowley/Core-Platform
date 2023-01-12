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
		class ConstRegistryValueProxy
		{
		protected:
			RegistryKey const* m_key;
			std::wstring_view m_valueName;

		public:
			explicit
			ConstRegistryValueProxy(RegistryKey const& key, meta::use_default_t);

			ConstRegistryValueProxy(RegistryKey const& key, std::wstring_view name);

			satisfies(ConstRegistryValueProxy,
				NotCopyable,
				NotMoveAssignable,
				IsMoveConstructible noexcept,
				NotEqualityComparable,
				NotSortable
			);
			
		public:
			implicit operator
			RegistryValue() const;
		};
		
		class RegistryValueProxy : public ConstRegistryValueProxy
		{
			using base = ConstRegistryValueProxy;

		public:
			explicit
			RegistryValueProxy(RegistryKey& key, meta::use_default_t)
			  : base{key,use_default}
			{}

			RegistryValueProxy(RegistryKey& key, std::wstring_view name)
			  : base{key,name}
			{}

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

		template <typename Self, meta::AnyOf<std::wstring_view,meta::use_default_t> OptionalName>
		auto
		operator[](this Self&& self, OptionalName name)
		{
			if constexpr (std::is_const_v<Self>)
				return ConstRegistryValueProxy{*this, name};
			else
				return RegistryValueProxy{*this, name};
		}

	public:
		void
		removeKey(std::wstring_view child);

		RegistryKey
		subkey(meta::create_new_t, std::wstring_view child, std::optional<AccessRight> rights = std::nullopt);
	};
}
