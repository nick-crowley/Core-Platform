#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/Concepts.h"
#include "core/CharacterConversion.h"
#include "core/EnumNames.h"
#include "core/ToHexString.h"
#include "../../src/library/PlatformExport.h"

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
PlatformExport to_string(gsl::cwzstring ws, core::meta::noconversion_t);
    
std::string 
PlatformExport to_string(std::wstring_view ws, core::meta::noconversion_t);
    
std::string 
PlatformExport to_string(void const* value); 

#ifdef HAS_ATL_STRING
namespace ATL
{
    std::string 
    inline to_string(CString const& s) { 
        return s.GetString(); 
    }
}
using ATL::to_string;
#endif

template <nstd::Enumeration Enum> 
std::string 
to_string(Enum e) { 
    std::string_view const name = enumerator_name(e);
    return !name.empty() ? std::string{name} : to_hexString(e);
}

template <typename T>
std::string 
as_string(T&& v);

using std::to_string;

template <typename T>
std::string 
to_string(T** value)
{
    if constexpr (nstd::AnyOf<std::remove_const_t<T>,char,wchar_t>)
        return !value ? "nullptr" : '\'' + as_string(*value) + '\'';
    else if constexpr (requires { to_string(value); })
        return !value ? "nullptr" : '*' + as_string(*value);
    else
        return !value ? "nullptr" : core::to_hexString(reinterpret_cast<uintptr_t>(value));
}

template <typename T>
    requires (!std::same_as<void,std::remove_cvref_t<T>>)
std::string 
to_string(T* value) 
{
    if constexpr (requires { to_string(*value); })
        return !value ? "nullptr" : '*' + as_string(*value);
    else
        return !value ? "nullptr" : core::to_hexString(reinterpret_cast<uintptr_t>(value));
}

namespace core::meta
{
    template <typename T>
    bool constexpr
    is_stringable_v = !nstd::Enumeration<T> && requires(T&& value) {
        ::to_string(value);
    };

    template <typename T>
    concept Stringable = is_stringable_v<T>; 
}

template <typename T>
std::string 
as_string(T&& v) {
    using ::to_string;
    using std::to_string;

    return to_string(std::forward<T>(v));
}

namespace core::testing
{
    enum class E1 {Zero};
    struct S1 {};
    static_assert(meta::Stringable<char[]>);
    static_assert(meta::Stringable<wchar_t[]>);
    static_assert(meta::Stringable<gsl::zstring>);
    static_assert(meta::Stringable<gsl::czstring>);
    static_assert(meta::Stringable<gsl::wzstring>);
    static_assert(meta::Stringable<gsl::cwzstring>);
    static_assert(meta::Stringable<void*>);
    static_assert(meta::Stringable<void const*>);
    static_assert(meta::Stringable<S1*>);
    static_assert(meta::Stringable<S1 const*>);
    static_assert(meta::Stringable<int>);
    static_assert(meta::Stringable<long>);
    static_assert(meta::Stringable<long long>);
    static_assert(!meta::Stringable<E1>);
    static_assert(meta::Stringable<float>);
    static_assert(meta::Stringable<double>);
    static_assert(meta::Stringable<float*>);
    static_assert(meta::Stringable<double*>);
    static_assert(meta::Stringable<float**>);
    static_assert(meta::Stringable<double**>);
    static_assert(meta::Stringable<bool>);
    static_assert(meta::Stringable<char>);
    static_assert(meta::Stringable<wchar_t>);
    static_assert(meta::Stringable<char8_t>);
    static_assert(meta::Stringable<char16_t>);
    static_assert(meta::Stringable<char32_t>);
    static_assert(meta::Stringable<unsigned>);
    static_assert(meta::Stringable<signed>);
    static_assert(meta::Stringable<long>);
    static_assert(meta::Stringable<unsigned*>);
    static_assert(meta::Stringable<signed*>);
    static_assert(meta::Stringable<long*>);
    static_assert(meta::Stringable<unsigned**>);
    static_assert(meta::Stringable<signed**>);
    static_assert(meta::Stringable<long**>);
    static_assert(meta::Stringable<std::string>);
    static_assert(meta::Stringable<std::wstring>);
    static_assert(meta::Stringable<std::string_view>);
    static_assert(meta::Stringable<std::wstring_view>);
    static_assert(meta::Stringable<void**>);
    static_assert(meta::Stringable<gsl::czstring*>);
    static_assert(meta::Stringable<gsl::cwzstring*>);
}