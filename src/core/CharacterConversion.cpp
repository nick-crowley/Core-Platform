/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2023, Nick Crowley. All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions
*    and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of
*    conditions and the following disclaimer in the documentation and/or other materials provided
*    with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
* FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
* WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* The views and conclusions contained in the software and documentation are those of the author 
* and should not be interpreted as representing official policies, either expressed or implied, of
* the projects which contain it.
*/
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
	