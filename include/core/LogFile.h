#pragma once
#include "library/core.Platform.h"

#ifndef _SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING
#	error _SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING must be defined to build <LogFile.h>
#endif

namespace core::filesystem
{
	path
	processPath() {
		wchar_t buffer[MAX_PATH] {};
		::GetModuleFileNameW(nullptr, buffer, MAX_PATH);
		return path{buffer};
	}
}

namespace core
{
	class LogFile : public std::ofstream 
	{
		using base = std::ofstream;

	public:
		LogFile(std::string_view fileName) 
		  : base{filesystem::processPath().parent_path() / ThrowIfEmpty(fileName), std::ios::out|std::ios::app}
		{
			this->imbue(std::locale(this->getloc(), new std::codecvt_utf8<char16_t, 0x10ffff, std::generate_header>));
		}
	};
}