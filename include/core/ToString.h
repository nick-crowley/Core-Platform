#pragma once
#include "library/core.Platform.h"
#include "nstd/Functional.h"

namespace core
{
    std::string 
    inline to_string(gsl::czstring s) { 
        return {s, s+strlen(s)}; 
    }
    
    std::string 
    inline to_string(gsl::cwzstring ws) { 
        return {
			boost::make_transform_iterator(ws, nstd::convert_to<char>),
			boost::make_transform_iterator(ws + wcslen(ws), nstd::convert_to<char>)
        };
    }
    
	std::string 
	inline to_string(std::string_view sv) {
		return std::string{sv}; 
	}

	std::string 
	inline to_string(std::wstring_view wsv) {
        return {
			boost::make_transform_iterator(wsv.begin(), nstd::convert_to<char>),
			boost::make_transform_iterator(wsv.end(), nstd::convert_to<char>)
        };
	}

    std::string 
    inline to_string(std::wstring const& ws) { 
        return {
			boost::make_transform_iterator(ws.begin(), nstd::convert_to<char>),
			boost::make_transform_iterator(ws.end(), nstd::convert_to<char>)
        };
    }

    std::add_lvalue_reference_t<std::string const>
    inline to_string(std::string const& s) { 
        return s; 
    }

#ifdef HAS_ATL_STRING
    std::string 
    inline to_string(ATL::CString const& s) { 
        return s.GetString(); 
}
#endif

    template <meta::Enumeration Enum> 
    std::string 
    inline to_string(Enum&& e) { 
        return "todo"; 
    }
}

namespace core::meta
{
    template <typename T> 
    concept ToWStringCompatible = requires(T&& value) 
    { 
	    to_string(value); 
    };
}

template <typename T>
std::string 
to_string(T** value)
{
    using ::to_string;
    using std::to_string;
    using core::to_string;

    if constexpr (core::meta::is_any_of_v<std::remove_const_t<T>,char,wchar_t>)
        return !value ? "nullptr" : '\'' + to_string(*value) + '\'';
    else if constexpr (core::meta::ToWStringCompatible<T*> || core::meta::ToWStringCompatible<T>)
        return !value ? "nullptr" : '*' + to_string(*value);
    else
        return !value ? "nullptr" : "0x" + std::to_string(reinterpret_cast<uintptr_t>(value));
}

template <typename T>
std::string 
to_string(T* value) requires (!std::is_integral_v<T>)
{
    using ::to_string;
    using std::to_string;
    using core::to_string;

    if constexpr (core::meta::ToWStringCompatible<T>)
        return !value ? "nullptr" : '*' + to_string(*value);
    else
        return !value ? "nullptr" : "0x" + std::to_string(reinterpret_cast<uintptr_t>(value));
}

std::string 
inline to_string(BOOL const* value)
{
    return !value ? "nullptr" 
        : (*value ? "TRUE" : "FALSE");
}

std::string 
inline to_string(DWORD const* value)
{
    return !value ? "nullptr" 
        : ((LONG)*value < 0 ? std::to_string((LONG)*value) : std::to_string(*value));
}
