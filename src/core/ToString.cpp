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

std::type_identity_t<std::string const&>
core::to_string(std::string const& s) { 
    return s; 
}

std::string 
core::to_string(gsl::cwzstring ws) { 
    if (!ws)
        return "nullptr";
    
    return core::to_utf8(ws);
}

std::string 
core::to_string(std::wstring_view ws) {
    return core::to_utf8(ws);
}

std::string 
core::to_string(std::wstring const& ws) { 
    return core::to_utf8(ws);
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
to_string(::BOOL const* value)
{
    return !value ? "nullptr" 
         : *value ? "TRUE" 
                  : "FALSE";
}

std::string 
to_string(::DWORD const* value)
{
    return !value                          ? "nullptr" 
         : static_cast<::LONG>(*value) < 0 ? std::to_string(static_cast<::LONG>(*value)) 
                                           : std::to_string(*value);
}
