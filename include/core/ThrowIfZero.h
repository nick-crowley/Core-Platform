#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core::detail
{
	template <std::equality_comparable_with<decltype(0)> T> 
	decltype(auto) 
	inline ThrowIfNullImpl(T&& value, char const* argName, std::source_location loc = std::source_location::current())
	{
		if (value == 0)
			throw invalid_argument{"{}(..) '{}' argument is zero", loc.function_name(), argName};

		return std::forward<T>(value);
	}
}

//! @brief	Throws if expression <tt>arg == 0</tt> evaluates to @c true
//! 
//! @param	arg		Argument
#define ThrowIfZero(arg)  ::core::detail::ThrowIfZeroImpl(arg, #arg)
