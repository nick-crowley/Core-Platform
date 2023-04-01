#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/Concepts.h"
#include "core/CharacterConversion.h"
#include "core/EnumNames.h"
#include "core/ToHexString.h"
#include "../../src/library/PlatformExport.h"

namespace core
{
    std::string 
    PlatformExport to_string(gsl::czstring s);
    
	std::string 
	PlatformExport to_string(std::string_view s);
    
    std::type_identity_t<std::string const&>
    PlatformExport to_string(std::string const& s);
    
    std::string 
    PlatformExport to_string(gsl::cwzstring ws);
    
    std::string 
	PlatformExport to_string(std::wstring_view ws); 

    std::string 
    PlatformExport to_string(std::wstring const& ws);

    std::string 
    PlatformExport to_string(gsl::cwzstring ws, meta::noconversion_t);
    
	std::string 
	PlatformExport to_string(std::wstring_view ws, meta::noconversion_t);

#ifdef HAS_ATL_STRING
    std::string 
    inline to_string(ATL::CString const& s) { 
        return s.GetString(); 
}
#endif

    template <nstd::Enumeration Enum> 
    std::string 
    to_string(Enum&& e) { 
        std::string_view const name = enumerator_name(e);
        return !name.empty() ? name : to_hexString(e);
    }
}

namespace core::meta
{
    template <typename T> 
    concept Stringable = requires(T&& value) 
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

    if constexpr (nstd::AnyOf<std::remove_const_t<T>,char,wchar_t>)
        return !value ? "nullptr" : '\'' + to_string(*value) + '\'';
    else if constexpr (core::meta::Stringable<T*> || core::meta::Stringable<T>)
        return !value ? "nullptr" : '*' + to_string(*value);
    else
        return !value ? "nullptr" : core::to_hexString(reinterpret_cast<uintptr_t>(value));
}

template <typename T>
std::string 
to_string(T* value) requires (!std::is_integral_v<T>)
{
    using ::to_string;
    using std::to_string;
    using core::to_string;

    if constexpr (core::meta::Stringable<T>)
        return !value ? "nullptr" : '*' + to_string(*value);
    else
        return !value ? "nullptr" : core::to_hexString(reinterpret_cast<uintptr_t>(value));
}

std::string 
PlatformExport to_string(BOOL const* value);

std::string 
PlatformExport to_string(DWORD const* value);
