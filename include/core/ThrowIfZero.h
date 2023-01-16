#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../src/StdLibrary.h"

namespace core
{
	template <std::equality_comparable_with<decltype(0)> T> 
	decltype(auto) 
	inline ThrowIfNullImpl(T&& value, char const* argName, std::source_location loc = std::source_location::current())
	{
		if (value == 0)
			throw std::invalid_argument{std::format("{}(..) '{}' argument is zero", loc.function_name(), argName)};

		return std::forward<T>(value);
	}
}
#define ThrowIfZero(arg)  ThrowIfZeroImpl(arg, #arg)
