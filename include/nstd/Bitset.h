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
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "nstd/Concepts.h"
#include "core/BitwiseEnum.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	//! brief	Non-standard bitset encapsulating enumeration bits rather than arbitrary bits
	template <Enumeration E>
	class bitset
	{
		template <Enumeration>
		friend class bitset;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		using type = bitset<E>;
		using reference = type&;
		using value_type = E;
		using underlying_t = std::underlying_type_t<value_type>;
		
	private:
		value_type constexpr
		inline static Zero = static_cast<value_type>(0);
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		value_type  Value = Zero;
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		constexpr 
		implicit
		bitset(value_type const& v) noexcept
			: Value{v}
		{}
		
		template <Enumeration E2>
		constexpr 
		explicit(!core::meta::CompatibleEnumeration<E,E2>)
		bitset(E2 const& v) noexcept
			: Value{static_cast<value_type>(v)}
		{}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(bitset,
			constexpr IsSemiRegular noexcept,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		template <Enumeration E2>
		bitset<E2> constexpr
		cast() const noexcept {
			return static_cast<E2>(this->Value);
		}
	
		template <Enumeration E2>
		bool constexpr
		test(E2 bits) const noexcept {
			return (this->Value & static_cast<value_type>(bits)) != Zero;
		}

		underlying_t constexpr
		value() const noexcept {
			return static_cast<underlying_t>(this->Value);
		}

		constexpr 
		implicit operator
		value_type() const noexcept {
			return this->Value;
		}
	
		template <core::meta::CompatibleEnumeration<E> E2>
		type constexpr 
		operator|(E2 const& r) const noexcept {
			return static_cast<value_type>(this->value() | std::to_underlying(r));
		}

		template <core::meta::CompatibleEnumeration<E> E2>
		type constexpr 
		operator&(E2 const& r) const noexcept {
			return static_cast<value_type>(this->value() & std::to_underlying(r));
		}
	
		template <core::meta::CompatibleEnumeration<E> E2>
		type constexpr 
		operator^(E2 const& r) const noexcept {
			return static_cast<value_type>(this->value() ^ std::to_underlying(r));
		}
	
		type constexpr 
		operator~() const noexcept {
			return static_cast<value_type>(~this->value());
		}
		
		template <core::meta::CompatibleEnumeration<E> E2>
		bool constexpr
		operator==(E2 const& rhs) const noexcept {
			return this->value() == std::to_underlying(rhs);
		}

		template <core::meta::CompatibleEnumeration<E> E2>
		bool constexpr
		operator!=(E2 const& rhs) const noexcept {
			return this->value() != std::to_underlying(rhs);
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		template <core::meta::CompatibleEnumeration<E> E2>
		reference constexpr 
		operator|=(E2 const& r) noexcept {
			this->Value = static_cast<value_type>(this->value() | std::to_underlying(r));
			return *this;
		}
		
		template <core::meta::CompatibleEnumeration<E> E2>
		reference constexpr 
		operator&=(E2 const& r) noexcept {
			this->Value = static_cast<value_type>(this->value() & std::to_underlying(r));
			return *this;
		}
			
		template <core::meta::CompatibleEnumeration<E> E2>
		reference constexpr 
		operator^=(E2 const& r) noexcept {
			this->Value = static_cast<value_type>(this->value() ^ std::to_underlying(r));
			return *this;
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

template <nstd::Enumeration E1, core::meta::CompatibleEnumeration<E1> E2>
nstd::bitset<E1> constexpr
operator|(E1 lhs, nstd::bitset<E2> rhs) noexcept {
	return nstd::bitset<E1>{lhs} | rhs;
}

template <nstd::Enumeration E1, core::meta::CompatibleEnumeration<E1> E2>
nstd::bitset<E1> constexpr
operator&(E1 lhs, nstd::bitset<E2> rhs) noexcept {
	return nstd::bitset<E1>{lhs} & rhs;
}

template <nstd::Enumeration E1, core::meta::CompatibleEnumeration<E1> E2>
nstd::bitset<E1> constexpr
operator^(E1 lhs, nstd::bitset<E2> rhs) noexcept {
	return nstd::bitset<E1>{lhs} ^ rhs;
}
	
template <nstd::Enumeration E1, core::meta::CompatibleEnumeration<E1> E2>
bool constexpr
operator==(E1 lhs, nstd::bitset<E2> rhs) noexcept {
	return nstd::bitset<E1>{lhs} == rhs;
}

template <nstd::Enumeration E1, core::meta::CompatibleEnumeration<E1> E2>
bool constexpr
operator!=(E1 lhs, nstd::bitset<E2> rhs) noexcept {
	return nstd::bitset<E1>{lhs} != rhs;
}

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o