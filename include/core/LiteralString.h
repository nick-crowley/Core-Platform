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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "core/ZString.h"

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	String of literal type whose characters are part of its representation
	*/
	template <nstd::Character Character, size_t Capacity>
	class LiteralString
	{
		static_assert(Capacity != 0, "'Capacity' cannot be zero");

		template <nstd::Character, size_t>
		friend class LiteralString;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = LiteralString<Character,Capacity>;
		using char_t = Character;
		using other_char_t = std::conditional_t<std::is_same_v<char_t,char>, wchar_t, char>;

	public:
		using const_reference = Character const&;
		using const_pointer = Character const*;
		using const_iterator = const_pointer;
		using reference = Character&;
		using pointer = Character*;
		using iterator = pointer;
		using difference_type = ptrdiff_t;
		using size_type = size_t;
		using value_type = Character;
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		Character m_text[Capacity];
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		constexpr
		LiteralString(Character const *str) noexcept 
		  : LiteralString{str, std::make_index_sequence<Capacity-1>{}}
		{
		}
	
		constexpr
		LiteralString(type const& r) noexcept 
		  : LiteralString{r.m_text, std::make_index_sequence<Capacity-1>{}}
		{
		}

		constexpr type& 
		operator=(type const& r) noexcept 
		{
			type{r}.swap(*this);
			return *this;
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(LiteralString,
			constexpr NotDefaultConstructible,
			constexpr IsMovable noexcept,
			constexpr IsDestructible noexcept
		);
	
	private:
		template <size_type N>
		constexpr
		LiteralString(Character const (&str)[N], Character const c) noexcept 
		  : LiteralString{str, c, std::make_index_sequence<N-1>{}}
		{
		}
	
		template <size_type L, size_type R>
		constexpr
		LiteralString(Character const (&lhs)[L], Character const (&rhs)[R]) noexcept 
		  : LiteralString{lhs, std::make_index_sequence<L-1>{}, rhs, std::make_index_sequence<R-1>{}}
		{
		}
	
		template <size_type... Idx>
		constexpr
		LiteralString(Character const *str, std::index_sequence<Idx...>) noexcept 
		  : m_text{str[Idx]..., '\0'}
		{
		}
	
		template <size_type... Idx>
		constexpr
		LiteralString(Character const *str, Character const c, std::index_sequence<Idx...>) noexcept 
		  : m_text{str[Idx]..., c, '\0'}
		{
		}
	
		template <size_type... Idx1, size_type... Idx2>
		constexpr
		LiteralString(Character const *lhs, std::index_sequence<Idx1...>, Character const *rhs, std::index_sequence<Idx2...>) noexcept 
		  : m_text{lhs[Idx1]..., rhs[Idx2]..., '\0'}
		{
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		const_iterator constexpr 
		begin() const noexcept
		{
			return std::begin(this->m_text);
		}

		const_iterator constexpr 
		end() const noexcept
		{
			return std::prev(std::end(this->m_text));
		}

		const_pointer constexpr 
		c_str() const noexcept
		{
			return std::begin(this->m_text);
		}

		const_pointer constexpr 
		data() const noexcept
		{
			return std::begin(this->m_text);
		}

		LiteralString<wchar_t,Capacity> constexpr
		wstr() const noexcept
		{
			std::wstring ws{this->begin(), this->end()};
			return LiteralString<wchar_t,Capacity>{ws.c_str()};
		}

		size_type constexpr
		size() const noexcept
		{
			return Capacity-1;
		}

		template <size_t N>
		auto constexpr
		operator+(LiteralString<Character,N> const& r) const noexcept
		{
			return LiteralString<Character,Capacity+N-1>{this->m_text, r.m_text};
		}
	
		auto constexpr
		operator+(Character const& c) const noexcept
		{
			return LiteralString<Character,Capacity+1>{this->m_text, c};
		}

		constexpr implicit
		operator std::basic_string_view<Character>() const noexcept
		{
			return {this->begin(), this->end()};
		}
	
		constexpr implicit
		operator std::basic_string_view<other_char_t>() const noexcept = delete;
		
		template <size_t N>
		bool constexpr
		operator==(LiteralString<Character,N> const& r) const noexcept {
			return std::equal(this->begin(), this->end(), r.begin(), r.end());
		}
		
		bool constexpr
		operator==(std::basic_string_view<Character> sv) const noexcept {
			return std::equal(this->begin(), this->end(), sv.begin(), sv.end());
		}
		
		bool constexpr
		operator==(gsl::basic_zstring<Character const> zs) const noexcept {
			return *this == std::basic_string_view<Character>{zs};
		}

		template <size_t N>
		bool constexpr
		operator==(LiteralString<other_char_t,N> const& r) const noexcept = delete;
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void constexpr
		swap(type& r) noexcept
		{
			std::swap(this->m_text, r.m_text);
		}
	};

	//! @brief	Deduce from character-array if possible but permit construction from char-pointer
	template <nstd::Character Character, size_t N>
	LiteralString(Character const (&)[N]) -> LiteralString<Character,N>;
}

namespace std 
{
	template <size_t N, nstd::AnyOf<char,wchar_t> Char>
	struct formatter<core::LiteralString<Char,N>, Char> {

		auto constexpr
		parse(basic_format_parse_context<Char>& ctx) {
            return ranges::find(ctx, '}');
        }

		auto 
		format(core::LiteralString<Char,N> const& value, format_context& ctx) const 
			requires std::same_as<Char,char>
		{
			return format_to(ctx.out(), "{}", static_cast<string_view>(value));
		}
        
		auto 
		format(core::LiteralString<Char,N> const& value, wformat_context& ctx) const 
			requires std::same_as<Char,wchar_t>
		{
			return format_to(ctx.out(), L"{}", static_cast<wstring_view>(value));
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
	inline namespace literals
	{
		inline namespace string_literals
		{
			//! @brief	Produce literal string
			template <ZString Buffer>
			auto constexpr
			operator ""_str()
			{
				return LiteralString<decltype(Buffer)::char_t, Buffer.Length+1>{Buffer.Text};
			}
		}
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::testing {
	//! @test  Verify equality between @c core::LiteralString of same character type and equal length
	static_assert(LiteralString{"abc"} == LiteralString{"abc"});
	static_assert(!(LiteralString{"abc"} == LiteralString{"cba"}));
	static_assert(LiteralString{"abc"} != LiteralString{"cba"});
	static_assert(!(LiteralString{"abc"} != LiteralString{"abc"}));

	//! @test  Verify equality between @c core::LiteralString of same character type and different length
	static_assert(!(LiteralString{"abc"} == LiteralString{""}));
	static_assert(!(LiteralString{""} == LiteralString{"abc"}));
	static_assert(LiteralString{""} != LiteralString{"cba"});
	static_assert(LiteralString{"abc"} != LiteralString{""});

	//! @test  Verify equality between @c core::LiteralString and @c std::basic_string_view
	static_assert(LiteralString{"abc"} == std::string_view{"abc"});
	static_assert(LiteralString{"abc"} != std::string_view{"cba"});
	static_assert(std::string_view{"abc"} == LiteralString{"abc"});
	static_assert(std::string_view{"cba"} != LiteralString{"abc"});

	//! @test  Verify equality between @c core::LiteralString and @c gsl::zstring
	static_assert(LiteralString{"abc"} == "abc");
	static_assert(LiteralString{"abc"} != "cba");
	static_assert("abc" == LiteralString{"abc"});
	static_assert("cba" != LiteralString{"abc"});

	//! @test  Verify two empty @c core::LiteralString compare equal
	static_assert(LiteralString{""} == LiteralString{""});

	//! @test  Verify @c core::LiteralString equality is case sensitive
	static_assert(LiteralString{"abc"} != LiteralString{"ABC"});

	//! @test  Verify @c core::LiteralString string-concatentation
	static_assert(LiteralString{"abc"} + LiteralString{"def"} == LiteralString{"abcdef"});
	
	//! @test  Verify @c core::LiteralString character-concatentation
	static_assert(LiteralString{"abc"} + 'd' == LiteralString{"abcd"});
	
	//! @test  Verify @c core::LiteralString wide-character conversion
	static_assert(LiteralString{"abc"}.wstr() == L"abc");
	
	//! @test  Verify @c core::LiteralString::size() returns 0 for empty strings
	static_assert(LiteralString{""}.size() == 0);

	//! @test  Verify @c core::LiteralString::size() returns length in characters
	static_assert(LiteralString{"abc"}.size() == 3);

	//! @test  Verify @c core::LiteralString::size() returns length in characters for wide-character strings
	static_assert(LiteralString{L"abc"}.size() == 3);
	
	//! @test  Verify @c core::LiteralString converts to @c std::basic_string_view
	static_assert(LiteralString{"abc"} == "abc"sv);
	
	//! @test  Verify @c core::operator""_str() produces a valid @c core::LiteralString
	using namespace core::string_literals;
	static_assert(LiteralString{"def"} == "def"_str);
	static_assert(LiteralString{L"abc"} == L"abc"_str);
	
	//! @test  Verify @c std::format() supports @c core::LiteralString
	static_assert(requires { std::format("{}", LiteralString{"abc"}); });
	static_assert(requires { std::format(L"{}", LiteralString{L"abc"}); });
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o