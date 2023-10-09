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
	
	private:
		Character m_text[Capacity];

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

		satisfies(LiteralString,
			constexpr NotDefaultConstructible,
			constexpr IsMovable noexcept,
			constexpr IsDestructible noexcept,
			constexpr IsEqualityComparable noexcept
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

	inline namespace literals
	{
		inline namespace string_literals
		{
			//! @brief	Produce literal string
			template <ZString<wchar_t> Buffer>
			auto constexpr
			operator ""_str()
			{
				return LiteralString<wchar_t,Buffer.Length+1>{Buffer.Text};
			}
		}
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::testing {
	//! @test  Verify @c core::LiteralString addition and equality operators are correct
	static_assert(LiteralString{"abc"} + LiteralString{"def"} == LiteralString{"abcdef"});
	
	//! @test  Verify @c core::LiteralString::size() returns length in characters
	static_assert(LiteralString{"abc"}.size() == 3);

	//! @test  Verify @c core::LiteralString::size() returns length in characters for wide-character strings
	static_assert(LiteralString{L"abc"}.size() == 3);
	
	//! @test  Verify @c core::LiteralString converts to @c std::basic_string_view
	using namespace std::string_view_literals;
	static_assert(LiteralString{"abc"} == "abc"sv);
	
	//! @test  Verify @c core::operator""_str() produces a valid @c core::LiteralString
	using namespace core::string_literals;
	static_assert(LiteralString{L"abc"} == L"abc"_str);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o