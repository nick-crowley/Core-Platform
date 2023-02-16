#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core::detail
{
	[[noreturn]]
	void
	inline ThrowInvalidArgImpl(gsl::czstring argName, gsl::czstring reason, std::source_location loc = std::source_location::current())
	{
		throw invalid_argument{"{}(..) Invalid '{}' argument: {}", loc.function_name(), argName, reason};
	}
}

//! @brief	Throws an argument exception (unconditionally)
//! 
//! @param	arg		Argument
//! @param	reason	Reason why argument is invalid
#define ThrowInvalidArg(arg,reason)     ::core::detail::ThrowInvalidArgImpl(#arg, reason)
