#include "library/core.Platform.h"
#include "core/CharacterConversion.h"
using namespace core;

std::string
core::narrow(std::wstring_view wstr, CodePage destination) 
{
	auto constexpr flags = WC_NO_BEST_FIT_CHARS|WC_ERR_INVALID_CHARS;
		
	char const* NoDefaultChar = nullptr;
	BOOL* UsedDefaultChar = nullptr;

	if (wstr.empty())
		return {};

	else if (size_t capacity = ::WideCharToMultiByte(std::to_underlying(destination), 
		                                        flags, 
		                                        wstr.data(), wstr.size(), 
		                                        nullptr, 0, 
		                                        NoDefaultChar, UsedDefaultChar); !capacity) 
		ThrowInvalidArg(wstr, win::LastError{}.str());
	else {
		std::string result(capacity, L'\0');
		if (!::WideCharToMultiByte(std::to_underlying(destination), 
			                        flags, 
			                        wstr.data(), wstr.size(), 
			                        result.data(), capacity,
			                        NoDefaultChar, UsedDefaultChar))
			ThrowInvalidArg(wstr, win::LastError{}.str());
		
		return result;
	}
}

std::wstring
core::widen(std::string_view str, CodePage source) 
{
	auto constexpr flags = MB_PRECOMPOSED|MB_ERR_INVALID_CHARS;
		
	if (str.empty())
		return {};

	else if (size_t capacity = ::MultiByteToWideChar(std::to_underlying(source), 
		                                        flags, 
		                                        str.data(), str.size(), 
		                                        nullptr, 0); !capacity) 
		ThrowInvalidArg(str, win::LastError{}.str());
	else {
		std::wstring result(capacity, L'\0');
		if (!::MultiByteToWideChar(std::to_underlying(source), 
			                        flags, 
			                        str.data(), str.size(), 
			                        result.data(), capacity))
			ThrowInvalidArg(str, win::LastError{}.str());
		
		return result;
	}
}
	