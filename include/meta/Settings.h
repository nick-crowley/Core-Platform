#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "meta/TagTypes.h"

namespace core::meta
{
	//! @brief	Arbitrary compile-time meta-data
	template <typename Name, typename... Params>
	undefined_t constexpr
	inline Settings;
	
	//! @brief	Initializer for compile-time meta-data (non-standard)
#	define constdata	template <> constexpr inline	
}
