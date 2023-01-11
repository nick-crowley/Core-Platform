#pragma once
#include "corePlatform.h"

namespace win
{
	class Boolean
	{
		bool value;
		
	public:
		constexpr 
		explicit 
		Boolean(bool expr) : value{expr}
		{
		}
		
		satisfies(Boolean,
			NotDefaultConstructible,
            constexpr IsCopyable noexcept,
            constexpr IsMovable noexcept,
			constexpr IsEqualityComparable noexcept,
			constexpr IsSortable noexcept
		);

	public:
		implicit operator 
		BOOL() const 
		{
			return this->value ? TRUE : FALSE;
		}
	};
}
