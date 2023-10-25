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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Preprocessor Directives o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma once
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "win/SharedHandle.h"
#include "win/RegistryValue.h"
#include "win/RegistryApi.h"
#include "security/KeyRight.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	SharedRegistryKey const 
	inline ClassesRoot {HKEY_CLASSES_ROOT};

	SharedRegistryKey const 
	inline CurrentUser {HKEY_CURRENT_USER};

	SharedRegistryKey const 
	inline LocalMachine {HKEY_LOCAL_MACHINE};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Existing registry key
	*/
	class PlatformExport RegistryKey
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		class PlatformExport ConstRegistryValueProxy
		{
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
			
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		protected:
			RegistryKey const* m_key;
			std::wstring_view m_valueName;
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			ConstRegistryValueProxy(RegistryKey const& key, meta::use_default_t);

			ConstRegistryValueProxy(RegistryKey const& key, std::wstring_view name);
			
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(ConstRegistryValueProxy,
				NotCopyable,
				NotMoveAssignable,
				IsMoveConstructible noexcept,
				NotEqualityComparable,
				NotSortable
			);
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			std::vector<std::byte>
			as_bytes() const;

			std::vector<std::wstring>
			as_wstrings() const;
			
			RegistryValue
			get() const;
			
			template <nstd::Enumeration Enum>
			Enum
			to_enum() const {
				RegistryValue const v = this->get();
				Invariant(!std::holds_alternative<std::vector<std::byte>>(v)
					   && !std::holds_alternative<std::vector<std::wstring>>(v));
	
				if (std::holds_alternative<std::wstring>(v))
					return from_string<Enum>(narrow(std::get<std::wstring>(v), CodePage::Latin1));
				else if (std::holds_alternative<std::wstring_view>(v)) 
					return from_string<Enum>(narrow(std::get<std::wstring_view>(v), CodePage::Latin1));
				
				else if (std::holds_alternative<uint32_t>(v)) 
					return static_cast<Enum>(std::get<uint32_t>(v));
				else 
					return static_cast<Enum>(std::get<uint64_t>(v));
				
				static_assert(std::variant_size_v<win::RegistryValue> == 6);
			}
			
			std::wstring
			to_wstring() const;
			
			uint32_t
			to_uint32() const;
			
			uint64_t
			to_uint64() const;
			
			std::wstring
			wstr() const;

			implicit 
			operator RegistryValue() const;			
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};
		
		class PlatformExport RegistryValueProxy : public ConstRegistryValueProxy
		{
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			using base = ConstRegistryValueProxy;
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			RegistryValueProxy(RegistryKey& key, meta::use_default_t);

			RegistryValueProxy(RegistryKey& key, std::wstring_view name);
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(RegistryValueProxy,
				NotCopyable,
				NotMoveAssignable,
				IsMoveConstructible noexcept,
				NotEqualityComparable,
				NotSortable
			);
			
			RegistryValueProxy&
			operator=(RegistryValue value);
			
			template <nstd::Enumeration Enum>
			RegistryValueProxy&
			operator=(Enum value) {
				if (is_valid_enumerator<Enum>(value)) 
					this->set(widen(enumerator_name<Enum>(value), CodePage::Latin1));
				else if (sizeof(std::underlying_type_t<Enum>) <= sizeof(uint32_t))
					this->set(static_cast<uint32_t>(std::to_underlying(value)));
				else
					this->set(static_cast<uint64_t>(std::to_underlying(value)));
				return *this;
			}
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			void
			remove();
			
			void
			set(std::string) = delete;
			
			void
			set(std::string_view) = delete;

			void
			set(RegistryValue value);
		};
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedRegistryApi m_api;
		SharedRegistryKey m_handle;
		KeyRight m_rights;
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Open existing key (identified by handle)
		RegistryKey(SharedRegistryKey handle, KeyRight rights, SharedRegistryApi api = registryApi());

		//! @brief	Open child of existing key  (identified by handle)
		RegistryKey(SharedRegistryKey parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api = registryApi());
		
		//! @brief	Create child of key (identified by handle)
		RegistryKey(meta::create_new_t, SharedRegistryKey parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api = registryApi());
		
		//! @brief	Open existing key
		RegistryKey(RegistryKey const& key, KeyRight rights, SharedRegistryApi api = registryApi())
		  : RegistryKey{key.m_handle, rights, api}
		{}

		//! @brief	Open child of existing key
		RegistryKey(RegistryKey const& parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api = registryApi())
		  : RegistryKey{parent.m_handle, child, rights, api}
		{}

		//! @brief	Create child of key
		RegistryKey(meta::create_new_t, RegistryKey const& parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api = registryApi())
		  : RegistryKey{meta::create_new, parent.m_handle, child, rights, api}
		{}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(RegistryKey,
			IsCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		template <typename Self>
		auto
		operator[](this Self&& self, meta::use_default_t)
		{
			if constexpr (std::is_const_v<std::remove_reference_t<Self>>)
				return ConstRegistryValueProxy{self, use_default};
			else
				return RegistryValueProxy{self, use_default};
		}
		
		template <typename Self>
		auto
		operator[](this Self&& self, std::wstring_view name)
		{
			if constexpr (std::is_const_v<std::remove_reference_t<Self>>)
				return ConstRegistryValueProxy{self, name};
			else
				return RegistryValueProxy{self, name};
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		RegistryKey
		subkey(std::wstring_view child, std::optional<KeyRight> rights = nullopt) const;

		RegistryKey
		operator/(std::wstring_view child) const {
			return this->subkey(child);
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		removeKey(std::wstring_view child);

		RegistryKey
		subkey(meta::create_new_t, std::wstring_view child, std::optional<KeyRight> rights = nullopt);
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o