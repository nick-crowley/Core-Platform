#include "core/ToString.h"
#include "core/CharacterConversion.h"
#include "nstd/Functional.h"
using namespace core;

std::string 
to_string(gsl::czstring s) { 
    if (!s)
        return "nullptr";
    return std::string{s, s + ::strlen(s)}; 
}

std::string 
to_string(std::string_view s) {
	return std::string{s}; 
}

std::type_identity_t<std::string const&>
to_string(std::string const& s) { 
    return s; 
}

std::string 
to_string(gsl::cwzstring ws) { 
    if (!ws)
        return "nullptr";
    
    return core::to_utf8(ws);
}

std::string 
to_string(std::wstring_view ws) {
    return core::to_utf8(ws);
}

std::string 
to_string(std::wstring const& ws) { 
    return core::to_utf8(ws);
}

std::string 
to_string(gsl::cwzstring ws, core::meta::noconversion_t) { 
    if (!ws)
        return "nullptr";
    else 
        return {
            boost::make_transform_iterator(ws, nstd::convert_to<char>),
            boost::make_transform_iterator(ws + wcslen(ws), nstd::convert_to<char>)
        };
}

std::string 
to_string(std::wstring_view ws, core::meta::noconversion_t) {
    return {
        boost::make_transform_iterator(ws.begin(), nstd::convert_to<char>),
        boost::make_transform_iterator(ws.end(), nstd::convert_to<char>)
    };
}

std::string 
to_string(void const* value) 
{
    return !value ? "nullptr" : core::to_hexString(reinterpret_cast<uintptr_t>(value));
}

#ifdef HAS_ATL_STRING
std::string 
ATL::to_string(CString const& s) { 
    return s.GetString(); 
}
#endif
