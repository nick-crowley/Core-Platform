#pragma once
#include "corePlatform.h"

template <meta::Character Character, size_t Capacity>
class LiteralString
{
	static_assert(Capacity != 0, "'Capacity' cannot be zero");

	template <meta::Character, size_t>
	friend class LiteralString;

private:
	using type = LiteralString<Character,Capacity>;
	using char_t = Character;

	Character m_text[Capacity];

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
	
	constexpr 
	LiteralString() noexcept = delete;
	
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

	constexpr
	~LiteralString() noexcept = default;

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

	void constexpr
	swap(type& r) noexcept
	{
		std::swap(this->m_text, r.m_text);
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
	std::wstring_view() const noexcept
	{
		return {this->begin(), this->end()};
	}

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
	  : m_text{str[Idx]..., L'\0'}
	{
	}
	
	template <size_type... Idx>
	constexpr
	LiteralString(Character const *str, Character const c, std::index_sequence<Idx...>) noexcept 
	  : m_text{str[Idx]..., c, L'\0'}
	{
	}
	
	template <size_type... Idx1, size_type... Idx2>
	constexpr
	LiteralString(Character const *lhs, std::index_sequence<Idx1...>, Character const *rhs, std::index_sequence<Idx2...>) noexcept 
	  : m_text{lhs[Idx1]..., rhs[Idx2]..., L'\0'}
	{
	}
};

template <meta::Character Character, size_t N>
LiteralString(Character const (&)[N]) -> LiteralString<Character,N>;

namespace detail 
{
	struct StringHolder 
	{
		wchar_t const* m_text;
		size_t         m_length;

		constexpr 
		StringHolder(wchar_t const *str)
			: m_text{str}, m_length{StringHolder::measure(str)}
		{}

		constexpr size_t
		measure(wchar_t const *str) {
			size_t len = 0;
			for (; str[len]; ++str)
			{}
			return len;
		}
	};
}
 
inline namespace literals
{
	inline namespace string_literals
	{
		template <detail::StringHolder S>
		auto constexpr
		operator ""_str()
		{
			return LiteralString<wchar_t,S.m_length+1>{S.m_text};
		}
	}
}
