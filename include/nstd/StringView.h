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
#include "../src/StdLibrary.h"
#include "nstd/Concepts.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
    template <AnyOf<char,wchar_t> Char>
    class case_insensitive_char_traits : public std::char_traits<Char>
    {
        using type = case_insensitive_char_traits<Char>;
	    using char_t = Char;

        char
	    static to_lower(char ch) {
            return static_cast<char>(
                std::tolower(static_cast<unsigned char>(ch))
            );
        }

	    wchar_t 
	    static to_lower(wchar_t ch) {
            return static_cast<wchar_t>(
                ::towlower(ch)
            );
        }
 
    public:
        bool 
        static eq(char_t c1, char_t c2) {
            return type::to_lower(c1) == type::to_lower(c2);
        }
 
        bool 
        static lt(char_t c1, char_t c2) {
             return type::to_lower(c1) < type::to_lower(c2);
        }
        
        int 
        static compare(char_t const* s1, char_t const* s2, std::size_t n)
        {
            while (n-- != 0)
            {
                if (type::lt(*s1, *s2))
                    return -1;
                if (type::to_lower(*s1) > type::to_lower(*s2))
                    return 1;
                ++s1;
                ++s2;
            }
            return 0;
        }
 
        return_t<char_t const*>
        static find(char_t const* s, std::size_t n, char_t a)
        {
            char_t const ua{type::to_lower(a)};
            while (n-- != 0) 
            {
                if (type::to_lower(*s) == ua)
                    return s;
                s++;
            }
		
            return nullptr;
        }
    };

    using istring_view  = std::basic_string_view<char, case_insensitive_char_traits<char>>;
    using wistring_view = std::basic_string_view<wchar_t, case_insensitive_char_traits<wchar_t>>;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
    template <AnyOf<char,wchar_t> Char>
    bool 
    operator==(std::basic_string_view<Char, std::char_traits<Char>> const& lhs, 
               std::basic_string_view<Char, case_insensitive_char_traits<Char>> const& rhs) {
	    return rhs.compare(std::remove_reference_t<decltype(rhs)>{lhs.begin(), lhs.end()}) == 0;
    }

    template <AnyOf<char,wchar_t> Char>
    bool 
    operator==(std::basic_string_view<Char, case_insensitive_char_traits<Char>> const& lhs,
               std::basic_string_view<Char, std::char_traits<Char>> const& rhs) {
	    return lhs.compare(std::remove_reference_t<decltype(lhs)>{rhs.begin(), rhs.end()}) == 0;
    }

    namespace literals 
    {
        inline namespace string_view_literals 
        {
            istring_view constexpr
            operator ""_isv(char const* str, std::size_t len) noexcept {
	            return istring_view{str, len};
            }

            wistring_view constexpr
            operator ""_isv(wchar_t const* str, std::size_t len) noexcept {
	            return wistring_view{str, len};
            }
        }
    }
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o