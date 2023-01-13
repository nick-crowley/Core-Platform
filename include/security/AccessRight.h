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
#ifndef security_AccessRight_h_included
#define security_AccessRight_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "corePlatform.h"
#include "security/CommonRight.h"
#include "security/CustomRight.h"
#include "security/GenericRight.h"
#include "security/KeyRight.h"
#include "security/StandardRight.h"

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Documentation o=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
* @brief	Access mask format
*
* @typedef	ACCESS_MASK
*
* @internal	
*
* 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
* GR GW GE GA -- -- -- AS ------- STANDARD --------- ------------- OBJECT SPECIFIC -----------------
*/

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta 
{
	template <typename T>
	concept AccessRight = meta::is_any_of_v<T, win::CommonRight, /*win::FileRight,*/ 
	                      win::GenericRight, win::KeyRight, win::StandardRight, 
	                      /*win::SystemRight,*/ /*win::ProcessRight,*/ /*win::TokenRight,*/ 
	                      win::CustomRight>;

	
	template <typename T>
	concept ConvertibleToAccessMask = std::is_arithmetic_v<T> && !std::is_same_v<T,::ACCESS_MASK>;
		
	template <typename T>
	concept ConvertibleFromAccessMask = std::is_arithmetic_v<T> && !is_any_of_v<T,bool,::ACCESS_MASK>;
	
}

namespace core::win
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Proxy for access-right enumeration(s)
	*
	* @details	Provides type-safe conversion and operators for access-right enumerations
	*/
	class AccessRight
	{
		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		using type = AccessRight;

		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		access_mask_t m_rights = NULL;      //!< Underlying access right mask

		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Construct from any supported access-right
		template <meta::AccessRight AnyRight>
		implicit
		AccessRight(AnyRight r)
			: m_rights(static_cast<access_mask_t>(r))
		{}
		
		//! @brief 	Prevent unwanted implicit conversions
		template <meta::ConvertibleToAccessMask Unwanted>
		implicit 
		AccessRight(Unwanted&&) = delete;

		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		satisfies(AccessRight,
			IsRegular,
			NotSortable
		);

		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief 	Provide an implicit conversion to @c ::DWORD
		implicit operator 
		access_mask_t() const
		{
			return this->m_rights;
		}
	
		//! @brief 	Provide an implicit conversion to @c CommonRight
		template <meta::AccessRight AnyRight>
		implicit operator 
		AnyRight() const {
			return static_cast<AnyRight>(this->m_rights);
		}
	
		//! @brief 	Prevent unwanted implicit conversions
		template <meta::ConvertibleFromAccessMask Unwanted>
		implicit operator
		Unwanted() const = delete;

		AccessRight
		operator~() const {
			return { static_cast<CustomRight>(~this->m_rights) };
		}
	
		AccessRight
		operator|(AccessRight const& rhs) const {
			return { static_cast<CustomRight>(this->m_rights | rhs.m_rights) };
		}
	
		AccessRight
		operator&(AccessRight const& rhs) const {
			return { static_cast<CustomRight>(this->m_rights & rhs.m_rights) };
		}

		// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		type&
		operator|=(AccessRight const& rhs) {
			this->m_rights |= rhs.m_rights;
			return *this;
		}
	
		type&
		operator&=(AccessRight const& rhs) {
			this->m_rights &= rhs.m_rights;
			return *this;
		}
	};

}      // namespace core::win
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win 
{
	template <meta::AccessRight AnyRight>
	AccessRight
	operator|(AnyRight const& lhs, AccessRight const& rhs)
	{
		return rhs | lhs;
	}

	template <meta::AccessRight AnyRight>
	AccessRight
	operator&(AnyRight const& lhs, AccessRight const& rhs)
	{
		return rhs & lhs;
	}
}      // namespace core::win
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_AccessRight_h_included
