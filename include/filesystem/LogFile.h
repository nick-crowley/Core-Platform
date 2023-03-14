#pragma once
#include "library/core.Platform.h"

namespace core::filesystem
{
	namespace detail {	
		path
		processPath() {
			wchar_t buffer[MAX_PATH] {};
			::GetModuleFileNameW(nullptr, buffer, MAX_PATH);
			return path{buffer};
		}
	}

	class LogFile : public std::ofstream 
	{
		using base = std::ofstream;

	public:
		LogFile(std::string_view fileName) 
		  : base{detail::processPath().parent_path() / ThrowIfEmpty(fileName), std::ios::out|std::ios::app}
		{
			this->imbue(std::locale(this->getloc(), new std::codecvt_utf8<char16_t, 0x10ffff, std::generate_header>));
		}
	};
}