#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "meta/Concepts.h"
#include "meta/Settings.h"

namespace core::meta 
{	
	struct bitwise_enum_t {} constexpr 
	inline bitwise_enum;

	template <>
	struct DataType<bitwise_enum_t> : std::type_identity<bool> {};

	template <typename E>
	concept BitwiseEnumeration = Enumeration<E> && Settings<bitwise_enum_t,E>;
}

template <core::meta::BitwiseEnumeration E>
E constexpr
operator&(E lhs, E rhs) { 
	return static_cast<E>(
		std::underlying_type_t<E>(lhs) & std::underlying_type_t<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator|(E lhs, E rhs) { 
	return static_cast<E>(
		std::underlying_type_t<E>(lhs) | std::underlying_type_t<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator^(E lhs, E rhs) { 
	return static_cast<E>(
		std::underlying_type_t<E>(lhs) ^ std::underlying_type_t<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator~(E lhs) { 
	return static_cast<E>(
		~std::underlying_type_t<E>(lhs)
	);
};

namespace core::meta 
{
	struct compatible_enum_t {} constexpr 
	inline compatible_enum;

	template <>
	struct DataType<compatible_enum_t> : std::type_identity<bool> {};

	template <typename E1, typename E2>
	concept CompatibleEnumeration = Enumeration<E1> 
	                             && Enumeration<E2> 
	                             && Settings<compatible_enum_t,E1,E2>;

	template <typename E>
	bool constexpr inline Settings<compatible_enum_t, E, E> = true;
}

template <core::meta::BitwiseEnumeration E1, core::meta::BitwiseEnumeration E2>
	requires core::meta::CompatibleEnumeration<E1,E2> //(!std::same_as<std::remove_cvref_t<E1>,std::remove_cvref_t<E2>>)
E1 constexpr
operator&(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) & std::underlying_type_t<E2>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E1, core::meta::BitwiseEnumeration E2>
	requires core::meta::CompatibleEnumeration<E1,E2>
E1 constexpr
operator|(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) | std::underlying_type_t<E2>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E1, core::meta::BitwiseEnumeration E2>
	requires core::meta::CompatibleEnumeration<E1,E2>
E1 constexpr
operator^(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) ^ std::underlying_type_t<E2>(rhs)
	);
};
