#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../../src/StdLibrary.h"

namespace core::nstd
{
	//! @brief	Clone of @c std::source_location which satisfies C++20 non-type template argument requirements
	struct SourceLocation
	{
		char const* const    File {""};
		char const* const    Function {""};
		uint_least32_t const Line {};

		consteval
		SourceLocation(std::source_location loc) 
		  : Line{loc.line()},
			File{loc.file_name()},
			Function{loc.function_name()}
		{}
	};
}
