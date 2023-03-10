#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "meta/TagTypes.h"

namespace core::meta
{
	template <auto Name>
	struct DataType : std::type_identity_t<undefined_t> {};
	
	template <auto Name>
	using DataType_t = typename DataType<Name>::type;

	//! @brief	Storage for arbitrary compile-time data
	template <auto Name, typename... Params>
	DataType_t<Name> constexpr
	inline Settings = {};
	
	//! @brief	Initializer for compile-time meta-data (non-standard)
#	define constdata	template <> constexpr inline
}
