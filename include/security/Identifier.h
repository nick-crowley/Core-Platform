/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2018, Nick Crowley. All rights reserved.
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
#ifndef security_Identifier_h_included
#define security_Identifier_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h" 
#include "core/VarLengthStructure.h"
#include "security/SecurityApi.h" 

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
// 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security
{
	namespace detail 
	{
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Variable-length security identifier wrapper
		*/
		template <nstd::AnyOf<::SID,::SID const> MaybeConstSid>
		class SidWrapper : public VarLengthStructure<MaybeConstSid>
		{	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			//! @brief	Aliases base type
			using base = VarLengthStructure<MaybeConstSid>;
	
			//! @brief	Import const-propagating field-wrapper
			template <typename Field> 
			using propagate_const_t = typename base::template propagate_const_t<Field>;
	
			//! @brief	Equally CV-qualified std::byte
			using MaybeConstByte = nstd::mirror_cv_t<MaybeConstSid,std::byte>;

		public:
			//! @brief	Aliases our type
			using type = SidWrapper<MaybeConstSid>;
			
			//! @brief	Non-const wrapper type
			using mutable_type = SidWrapper<::SID>;
			
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			propagate_const_t<::BYTE>                     Revision;
			propagate_const_t<::BYTE>                     SubAuthorityCount;
			propagate_const_t<::SID_IDENTIFIER_AUTHORITY> IdentifierAuthority;
			propagate_const_t<::DWORD*>					  SubAuthority; 
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] security identifier
			* 
			* @throws	std::invalid_argument		Missing argument
			*/
			implicit
			SidWrapper(MaybeConstSid* sid)
			  : base{ThrowIfNull(sid)},
				Revision(sid->Revision),
				SubAuthorityCount(sid->SubAuthorityCount),
				IdentifierAuthority(sid->IdentifierAuthority),
				SubAuthority(sid->SubAuthority)
			{}

			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] binary representation
			* 
			* @throws	std::invalid_argument		Missing argument
			*/
			explicit
			SidWrapper(std::span<MaybeConstByte> bytes)
				: SidWrapper{reinterpret_cast<MaybeConstSid*>(bytes.data())}
			{}
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(SidWrapper,
				NotDefaultConstructible,
				IsCopyConstructible,
				NotCopyAssignable,
				NotEqualityComparable,
				NotSortable
			);
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve size of structure, in bytes
			*/
			std::size_t
			size() const
			{
				return nstd::sizeof_v<::BYTE, ::BYTE, ::SID_IDENTIFIER_AUTHORITY> 
					 + nstd::sizeof_n<::DWORD>(this->SubAuthorityCount);
			}
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};
	}
	
	//! @brief	Wrapper for mutable security identifiers
	using SidWrapper = detail::SidWrapper<::SID>;

	//! @brief	Wrapper for const security identifiers
	using ConstSidWrapper = detail::SidWrapper<::SID const>;
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Security identifier
	*/
	class Identifier
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = Identifier;
		using ByteBuffer = std::vector<std::byte>;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		ByteBuffer        Storage;      //!< Storage for var-length SID structure
		SharedSecurityApi Api;          //!< Security API implementation

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Copy-construct from binary representation
		*
		* @param[in]	bytes	Binary representation of SID
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		Identifier(std::span<std::byte const> bytes, SharedSecurityApi api = security_api())
		  : Storage{ThrowIfEmpty(bytes).begin(),bytes.end()}, Api{ThrowIfEmpty(api)}
		{}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Move-construct from binary representation
		*
		* @param[in]	bytes	Binary representation of SID
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		Identifier(std::vector<std::byte>&& bytes, SharedSecurityApi api = security_api())
		  : Storage{std::move(ThrowIfEmpty(bytes))}, Api{ThrowIfEmpty(api)}
		{}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(Identifier,
			NotDefaultConstructible,
			IsCopyable,
			NotSortable,
			NotArithmetic
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct from string representation
		*
		* @param[in]    sid		SID string (in the standard S-R-I-S-S… format)
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument	Missing argument
		* @throws	std::system_error		Operation failed
		*/
		Identifier
		static fromString(std::wstring_view sid, SharedSecurityApi api = security_api())
		{
			return Identifier{ThrowIfEmpty(api)->stringToSid(ThrowIfEmpty(sid)), api};
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Lookup matching account (if any)
		std::optional<Account>
		account() const {
			return this->Api->lookupAccount(this->bytes(), nullopt);
		}
	
		//! @brief	Retrieve binary representation
		std::span<std::byte const>
		bytes() const {
			return this->Storage;
		}
	
		//! @brief	Compare identifier prefixes for equality
		bool
		equalPrefix(Identifier const& rhs) const {
			return this->Api->compareSidPrefix(this->bytes(), rhs.bytes());
		}

		//! @brief	Generate string representation
		std::wstring
		wstr() const {
			return this->Api->sidToString(this->bytes());
		}
	
		//! @brief	Identifier equality operator
		bool
		operator==(Identifier const& rhs) const {
			return this->Api->compareSid(this->bytes(), rhs.bytes());
		}

		//! @brief	Identifier inequality operator
		bool
		operator!=(Identifier const& rhs) const {
			return !this->Api->compareSid(this->bytes(), rhs.bytes());
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}      // namespace core::security
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_Identifier_h_included
