#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../../src/StdLibrary.h"

namespace nstd
{
	template <typename... Args>
	using format_string = std::_Fmt_string<Args...>;
	
	template <typename... Args>
	using format_wstring = std::_Fmt_wstring<Args...>;
}
