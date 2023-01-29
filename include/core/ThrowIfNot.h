#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core
{
	void
	inline ThrowIfImpl(bool cond, gsl::czstring argName, gsl::czstring invariant, std::source_location loc = std::source_location::current())
	{
		if (cond)
			throw runtime_error{"{}(..) Invalid '{}' argument: {}", loc.function_name(), argName, invariant};
	}

#	define ThrowIf(arg,expr)     ThrowIfImpl(expr, #arg, #expr)
#	define ThrowIfNot(arg,expr)  ThrowIfImpl(!(expr), #arg, "!(" #expr ")")
}
