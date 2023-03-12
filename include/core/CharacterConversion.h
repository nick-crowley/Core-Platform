#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../../src/StdLibrary.h"
#include "../../src/PlatformSdk.h"
#include "../../src/library/PlatformExport.h"

namespace core
{
	enum class CodePage : uint32_t {
		Latin1 = 1252,		// ANSI Latin 1; Western European (Windows)
		Utf8 = CP_UTF8,
	};

	std::string
	PlatformExport narrow(std::wstring_view wstr, CodePage destination);

	std::wstring
	PlatformExport widen(std::string_view str, CodePage source);
	
	std::string
	inline to_utf8(std::wstring_view wstr) {
		return core::narrow(wstr, CodePage::Utf8);
	}
}