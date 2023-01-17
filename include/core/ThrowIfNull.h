#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core
{
	template <std::equality_comparable_with<std::nullptr_t> T> 
	decltype(auto) 
	inline ThrowIfNullImpl(T&& value, char const* argName, std::source_location loc = std::source_location::current())
	{
		if (value == nullptr)
			throw invalid_argument{"{}(..) Null '{}' argument", loc.function_name(), argName};

		return std::forward<T>(value);
	}
}
#define ThrowIfNull(arg)  ThrowIfNullImpl(arg, #arg)
