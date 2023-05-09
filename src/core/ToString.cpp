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
#include "core/ToString.h"
#include "core/CharacterConversion.h"
#include "nstd/Functional.h"
using namespace core;

std::string 
core::to_string(gsl::czstring s) { 
    if (!s)
        return "nullptr";
    return std::string{s, s + ::strlen(s)}; 
}

std::string 
core::to_string(std::string_view s) {
	return std::string{s}; 
}

nstd::return_t<std::string const&>
core::to_string(std::string const& s) { 
    return s; 
}

std::string 
core::to_string(gsl::cwzstring ws) { 
    if (!ws)
        return "nullptr";
    
    return to_utf8(ws);
}

std::string 
core::to_string(std::wstring_view ws) {
    return to_utf8(ws);
}

std::string 
core::to_string(std::wstring const& ws) { 
    return to_utf8(ws);
}

std::string 
core::to_string(gsl::cwzstring ws, meta::noconversion_t) { 
    if (!ws)
        return "nullptr";
    else 
        return {
            boost::make_transform_iterator(ws, nstd::convert_to<char>),
            boost::make_transform_iterator(ws + wcslen(ws), nstd::convert_to<char>)
        };
}

std::string 
core::to_string(std::wstring_view ws, meta::noconversion_t) {
    return {
        boost::make_transform_iterator(ws.begin(), nstd::convert_to<char>),
        boost::make_transform_iterator(ws.end(), nstd::convert_to<char>)
    };
}

std::string 
core::to_string(void const* value) 
{
    return !value ? "nullptr" : to_hexString(reinterpret_cast<uintptr_t>(value));
}

#ifdef SUPPORT_ATL_STRING
std::string 
ATL::to_string(CString const& s) { 
    return s.GetString(); 
}
#endif
