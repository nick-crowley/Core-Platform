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
#include "nstd/StringView.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	using istring  = std::basic_string<char, case_insensitive_char_traits<char>>;
	using wistring = std::basic_string<wchar_t, case_insensitive_char_traits<wchar_t>>;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	template <AnyOf<char,wchar_t> Char, typename Alloc>
	bool constexpr
	operator==(std::basic_string<Char,std::char_traits<Char>,Alloc> const& lhs, 
	           std::basic_string<Char,case_insensitive_char_traits<Char>,Alloc> const& rhs) {
		return std::basic_string_view<Char>{lhs} == std::basic_string_view<Char,case_insensitive_char_traits<Char>>{rhs};
	}

	template <AnyOf<char,wchar_t> Char, typename Alloc>
	bool constexpr
	operator==(std::basic_string<Char,case_insensitive_char_traits<Char>,Alloc> const& lhs, 
	           std::basic_string<Char,std::char_traits<Char>,Alloc> const& rhs) {
		return std::basic_string_view<Char,case_insensitive_char_traits<Char>>{lhs} == std::basic_string_view<Char>{rhs};
	}
 
	template <AnyOf<char,wchar_t> Char, typename Alloc>
	bool constexpr
	operator==(Char const* lhs, 
	           std::basic_string<Char,case_insensitive_char_traits<Char>,Alloc> const& rhs) {
		return rhs.compare(lhs) == 0;
	}
	
	template <AnyOf<char,wchar_t> Char, typename Alloc>
	bool constexpr
	operator==(std::basic_string<Char,case_insensitive_char_traits<Char>,Alloc> const& lhs, 
	           Char const* rhs) {
		return lhs.compare(rhs) == 0;
	}
	
	inline namespace literals 
    {
        inline namespace string_literals 
        {
			istring constexpr
			operator ""_is(char const* str, std::size_t len) noexcept {
				return istring{str, len};
			}

			wistring constexpr
			operator ""_is(wchar_t const* str, std::size_t len) noexcept {
				return wistring{str, len};
			}
		}
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
    //! @test  Verify equality between @c nstd::istring and @c std::string is case-insensitive
	static_assert(std::string{"HELLO"} == istring{"hello"});

    //! @test  Verify equality between @c std::string and @c nstd::istring is case-insensitive
	static_assert(istring{"HELLO"} == std::string{"hello"});
    
    //! @test  Verify inequality between @c nstd::istring and @c std::string detects differences
	static_assert(std::string{"HELLO"} != istring{"world"});

    //! @test  Verify inequality between @c std::string and @c nstd::istring detects differences
	static_assert(istring{"WORLD"} != std::string{"hello"});
    

    //! @test  Verify equality between @c nstd::istring and @c std::string is case-insensitive
	static_assert(std::string{"HELLO"} == istring{"hello"});

    //! @test  Verify equality between @c std::string and @c nstd::istring is case-insensitive
	static_assert(istring{"HELLO"} == std::string{"hello"});
    
    //! @test  Verify inequality between @c nstd::istring and @c std::string detects differences
	static_assert(std::string{"HELLO"} != istring{"world"});

    //! @test  Verify inequality between @c std::string and @c nstd::istring detects differences
	static_assert(istring{"WORLD"} != std::string{"hello"});
    

    using namespace literals::string_literals;
    //! @test  Verify @c _is literal operator creates @c constexpr narrow-character string
	static_assert(std::string{"HELLO"} == "hello"_is);

    //! @test  Verify @c _is literal operator creates @c constexpr wide-character string
    static_assert(std::wstring{L"HELLO"} == L"hello"_is);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o