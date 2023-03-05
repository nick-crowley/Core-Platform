#pragma once
#include "library/core.Platform.h"
#include "core/ZString.h"

namespace core
{
	template <meta::Character Character, size_t Capacity>
	class LiteralString
	{
		static_assert(Capacity != 0, "'Capacity' cannot be zero");

		template <meta::Character, size_t>
		friend class LiteralString;

		using type = LiteralString<Character,Capacity>;
		using char_t = Character;

	public:
		using const_reference = Character const&;
		using const_pointer = Character const*;
		using const_iterator = const_pointer;
		using reference = const_reference;
		using pointer = const_pointer;
		using iterator = const_iterator;
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

		constexpr
		type& operator=(type const& r) noexcept 
		{
			type{r}.swap(*this);
			return *this;
		}

		satisfies(LiteralString,
			constexpr NotDefaultConstructible,
			constexpr NotMovable,
			constexpr IsDestructible,
			constexpr IsEqualityComparable
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

		constexpr
		implicit operator 
		std::basic_string_view<Character>() const noexcept
		{
			return {this->begin(), this->end()};
		}
	
	public:
		void constexpr
		swap(type& r) noexcept
		{
			std::swap(this->m_text, r.m_text);
		}
	};

	template <meta::Character Character, size_t N>
	LiteralString(Character const (&)[N]) -> LiteralString<Character,N>;

	inline namespace literals
	{
		inline namespace string_literals
		{
			template <ZString<wchar_t> Buffer>
			auto constexpr
			operator ""_str()
			{
				return LiteralString<wchar_t,Buffer.Length+1>{Buffer.Text};
			}
		}
	}
}