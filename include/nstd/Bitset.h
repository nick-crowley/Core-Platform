#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/Concepts.h"
#include "core/BitwiseEnum.h"

namespace nstd
{
	template <Enumeration E>
	class bitset
	{
		template <Enumeration>
		friend class bitset;

		using type = bitset<E>;
		using reference = type&;
		using value_type = E;
		using underlying_t = std::underlying_type_t<value_type>;

	private:
		value_type constinit
		inline static Zero = static_cast<value_type>(0);

	private:
		value_type  Value = Zero;

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
		
		satisfies(bitset,
			constexpr IsSemiRegular noexcept,
			NotSortable
		);

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
			return static_cast<value_type>(this->value() | std::underlying_type_t<E2>(r));
		}

		template <core::meta::CompatibleEnumeration<E> E2>
		type constexpr 
		operator&(E2 const& r) const noexcept {
			return static_cast<value_type>(this->value() & std::underlying_type_t<E2>(r));
		}
	
		template <core::meta::CompatibleEnumeration<E> E2>
		type constexpr 
		operator^(E2 const& r) const noexcept {
			return static_cast<value_type>(this->value() ^ std::underlying_type_t<E2>(r));
		}
	
		type constexpr 
		operator~() const noexcept {
			return static_cast<value_type>(~this->value());
		}
		
		template <core::meta::CompatibleEnumeration<E> E2>
		bool constexpr
		operator==(E2 const& rhs) noexcept {
			return this->value() == std::underlying_type_t<E2>(rhs);
		}

		template <core::meta::CompatibleEnumeration<E> E2>
		bool constexpr
		operator!=(E2 const& rhs) noexcept {
			return this->value() != std::underlying_type_t<E2>(rhs);
		}

	public:
		template <core::meta::CompatibleEnumeration<E> E2>
		reference constexpr 
		operator|=(E2 const& r) noexcept {
			this->Value = static_cast<value_type>(this->value() | std::underlying_type_t<E2>(r));
			return *this;
		}
		
		template <core::meta::CompatibleEnumeration<E> E2>
		reference constexpr 
		operator&=(E2 const& r) noexcept {
			this->Value = static_cast<value_type>(this->value() & std::underlying_type_t<E2>(r));
			return *this;
		}
			
		template <core::meta::CompatibleEnumeration<E> E2>
		reference constexpr 
		operator^=(E2 const& r) noexcept {
			this->Value = static_cast<value_type>(this->value() ^ std::underlying_type_t<E2>(r));
			return *this;
		}
	};
}

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
