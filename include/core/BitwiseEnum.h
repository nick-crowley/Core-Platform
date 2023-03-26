#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/Concepts.h"
#include "meta/Settings.h"

namespace core::meta 
{	
	template <>
	struct DataType<bitwise_enum> : std::type_identity<bool> {};

	template <typename E>
	concept BitwiseEnumeration = nstd::Enumeration<E> && Settings<bitwise_enum,E>;
}

template <core::meta::BitwiseEnumeration E>
E constexpr
operator&(E lhs, E rhs) { 
	return static_cast<E>(
		std::to_underlying<E>(lhs) & std::to_underlying<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator|(E lhs, E rhs) { 
	return static_cast<E>(
		std::to_underlying<E>(lhs) | std::to_underlying<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator^(E lhs, E rhs) { 
	return static_cast<E>(
		std::to_underlying<E>(lhs) ^ std::to_underlying<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator~(E lhs) { 
	return static_cast<E>(
		~std::to_underlying<E>(lhs)
	);
};

namespace core::meta 
{
	template <>
	struct DataType<compatible_enum> : std::type_identity<bool> {};

	template <typename E1, typename E2>
	concept CompatibleEnumeration = nstd::Enumeration<E1> 
	                             && nstd::Enumeration<E2> 
	                             && Settings<compatible_enum,E1,E2>;

	template <nstd::Enumeration E>
	bool constexpr inline Settings<compatible_enum, E, E> = true;
}

template <core::meta::BitwiseEnumeration E1, core::meta::CompatibleEnumeration<E1> E2>
E1 constexpr
operator&(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) & std::underlying_type_t<E2>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E1, core::meta::CompatibleEnumeration<E1> E2>
E1 constexpr
operator|(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) | std::underlying_type_t<E2>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E1, core::meta::CompatibleEnumeration<E1> E2>
E1 constexpr
operator^(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) ^ std::underlying_type_t<E2>(rhs)
	);
};
