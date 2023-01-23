#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace nstd
{
	struct invariant_violated : ::core::runtime_error {
		invariant_violated(std::string_view expression)
			: core::runtime_error{"'{}' is false", expression}
		{}
	};

	//! @brief	Throws immediately if expression is untrue
	//! 
	//! @param	invarExpr	Boolean expression
#	define Invariant(invarExpr)		if (!(invarExpr)) throw ::nstd::invariant_violated{#invarExpr};
}
