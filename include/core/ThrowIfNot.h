#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core::detail
{
	void
	inline ThrowIfImpl(bool cond, gsl::czstring argName, gsl::czstring invariant, std::source_location loc = std::source_location::current())
	{
		if (cond)
			throw runtime_error{"{}(..) Invalid '{}' argument: {}", loc.function_name(), argName, invariant};
	}
}

//! @brief	Throws if expression @c expr evaluates to @c true
//! 
//! @param	arg		Argument
//! @param	expr	Boolean expression
#define ThrowIf(arg,expr)     ::core::detail::ThrowIfImpl(expr, #arg, #expr)

//! @brief	Throws if expression @c expr evaluates to @c false
//! 
//! @param	arg		Argument
//! @param	expr	Boolean expression
#define ThrowIfNot(arg,expr)  ::core::detail::ThrowIfImpl(!(expr), #arg, "!(" #expr ")")
