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

#ifdef HAS_ATL_STRING
std::string 
ATL::to_string(CString const& s) { 
    return s.GetString(); 
}
#endif
