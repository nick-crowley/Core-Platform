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
#include "corePlatform.h" 
#include "core/VarLengthStructure.h"
#include "security/SecurityApi.h" 

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security::detail
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Variable-length security identifier wrapper
	*/
	template <meta::AnyOf<::SID,::SID const> MaybeConstSid>
	class SidWrapper : public VarLengthStructure<MaybeConstSid>
	{	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	private:
		//! @brief	Aliases base type
		using base = VarLengthStructure<MaybeConstSid>;
	
		//! @brief	Import const-propagating field-wrapper
		template <typename Field> 
		using propagate_const_t = typename base::template propagate_const_t<Field>;
	
		//! @brief	Equally CV-qualified std::byte
		using maybe_const_byte = meta::mirror_cv_t<MaybeConstSid,std::byte>;

	public:
		//! @brief	Aliases our type
		using type = SidWrapper<MaybeConstSid>;

		//! @brief	Aliases our sibling
		using other = SidWrapper<meta::toggle_const_t<MaybeConstSid>>;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		propagate_const_t<::BYTE>                     Revision;
		propagate_const_t<::BYTE>                     SubAuthorityCount;
		propagate_const_t<::SID_IDENTIFIER_AUTHORITY> IdentifierAuthority;
		propagate_const_t<::DWORD*>					  SubAuthority; 
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct from [possibly-const] security identifier
		* 
		* @throws	std::invalid_argument		Missing argument
		*/
		implicit
		SidWrapper(MaybeConstSid* sid)
		  : base{sid},
			Revision(ThrowIfEmpty(sid)->Revision),
			SubAuthorityCount(sid->SubAuthorityCount),
			IdentifierAuthority(sid->IdentifierAuthority),
			SubAuthority(sid->SubAuthority)
		{}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct from [possibly-const] binary representation
		* 
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		SidWrapper(std::span<maybe_const_byte> bytes)
			: SidWrapper{reinterpret_cast<MaybeConstSid*>(bytes.data())}
		{}
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		satisfies(SidWrapper,
			NotDefaultConstructible,
			IsCopyConstructible,
			NotCopyAssignable,
			NotEqualityComparable,
			NotSortable
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Retrieve size of structure, in bytes
		*/
		std::size_t
		size() const
		{
			return meta::sizeof_v<::BYTE, ::BYTE, ::SID_IDENTIFIER_AUTHORITY> 
			     + meta::sizeof_n<::DWORD>(this->SubAuthorityCount);
		}
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	};
}

namespace core::security
{
	class Identifier
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	private:
		using type = Identifier;
		using ByteBuffer = std::vector<std::byte>;
		using SidWrapper = detail::SidWrapper<::SID>; 
		using ConstSidWrapper = detail::SidWrapper<::SID const>; 

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	private:
		ByteBuffer        m_storage;      //!< Storage for var-length SID structure
		SharedSecurityApi m_api;          //!< Security API implementation

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Copy-construct from binary representation
		*
		* @param[in]	bytes	Binary representation of SID
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		Identifier(std::span<const std::byte> bytes, SharedSecurityApi api = security_api())
		  : m_storage{ThrowIfEmpty(bytes).begin(),bytes.end()}, m_api{ThrowIfEmpty(api)}
		{}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Move-construct from binary representation
		*
		* @param[in]	bytes	Binary representation of SID
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		Identifier(std::vector<std::byte>&& bytes, SharedSecurityApi api = security_api())
		  : m_storage{std::move(ThrowIfEmpty(bytes))}, m_api{ThrowIfEmpty(api)}
		{}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct from string representation
		*
		* @param[in]    sid		SID string (in the standard S-R-I-S-S… format)
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument	Missing argument
		* @throws	std::system_error		Operation failed
		*/
		explicit
		Identifier(std::wstring_view sid, SharedSecurityApi api = security_api())
		  : m_storage{ThrowIfEmpty(api)->stringToSid(ThrowIfEmpty(sid))}, 
			m_api{api}
		{}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		satisfies(Identifier,
			NotDefaultConstructible,
			IsCopyable,
			NotSortable
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		//! @brief	Retrieve binary representation
		std::span<std::byte const>
		bytes() const {
			return this->m_storage;
		}
	
		//! @brief	Compare identifier prefixes for equality
		bool
		equalPrefix(Identifier const& rhs) const {
			return this->m_api->compareSidPrefix(this->bytes(), rhs.bytes());
		}

		//! @brief	Generate string representation
		std::wstring
		str() const {
			return this->m_api->sidToString(this->bytes());
		}
	
		//! @brief	Identifier equality operator
		bool
		operator==(Identifier const& rhs) const {
			return this->m_api->compareSid(this->bytes(), rhs.bytes());
		}

		//! @brief	Identifier inequality operator
		bool
		operator!=(Identifier const& rhs) const {
			return !this->m_api->compareSid(this->bytes(), rhs.bytes());
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	};

}      // namespace core::security
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_Identifier_h_included
