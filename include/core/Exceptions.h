#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/FormatString.h"
#include "nstd/SourceLocation.h"

namespace core
{
	struct invalid_argument : public std::invalid_argument
	{
		using base = std::invalid_argument;

		template <typename... Params>
		invalid_argument(std::string_view msg, Params&&... args)
			: base{std::vformat(msg,std::make_format_args(args...))}
		{}
	};

	struct runtime_error : public std::runtime_error
	{
		using base = std::runtime_error;
		
		template <typename... Params>
		runtime_error(std::string_view msg, Params&&... args)
			: base{std::vformat(msg,std::make_format_args(args...))}
		{}
	};
}
