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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Preprocessor Directives o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "nstd/Concepts.h"
#include "core/CharacterConversion.h"
#include "core/EnumNames.h"
#include "core/ToHexString.h"
#include "../../src/library/PlatformExport.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o