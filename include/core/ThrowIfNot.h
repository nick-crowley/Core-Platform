#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core
{
	void
	inline ThrowIfImpl(bool expr, char const* exprName, std::source_location loc = std::source_location::current())
	{
		if (expr)
			throw runtime_error{"{}(..) '{}' invariant violated", loc.function_name(), exprName};
	}
}
#define ThrowIf(expr)     ThrowIfImpl(expr, #expr)				//FIXME: Change ThrowIf() and ThrowIfNot() into argument-validation routines; add separate ones for invariants
#define ThrowIfNot(expr)  ThrowIfImpl(!(expr), "!(" #expr ")")
