#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/FormatString.h"
#include "nstd/SourceLocation.h"
#include "../../src/PlatformSdk.h"

namespace core::win::detail
{
	std::string 
	PlatformExport formatMessage(::LRESULT err);
}

namespace core::win
{
	struct system_error : public std::system_error
	{
		using base = std::system_error;
		
		explicit
		system_error(::LRESULT code)
			: base{static_cast<int>(code), std::system_category(), detail::formatMessage(code)}
		{
		}

		template <typename... Params>
		system_error(::LRESULT code, std::string_view msg, Params&&... args)
		  : base{static_cast<int>(code), 
		         std::system_category(), 
		         std::vformat(msg,std::make_format_args(args...)) + " (" + detail::formatMessage(code) + ")"}
		{
		}
	};
}