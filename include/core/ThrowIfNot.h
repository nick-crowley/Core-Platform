#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../src/StdLibrary.h"

namespace core
{
	void
	inline ThrowIfImpl(bool expr, char const* exprName, std::source_location loc = std::source_location::current())
	{
		if (expr)
			throw std::runtime_error{std::format("{}(..) '{}' invariant violated", loc.function_name(), exprName)};
	}
}
#define ThrowIf(expr)     ThrowIfImpl(expr, #expr)
#define ThrowIfNot(expr)  ThrowIfImpl(!(expr), "!(" #expr ")")
