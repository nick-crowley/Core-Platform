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
			constexpr_IsCopyable_noexcept,
			constexpr_IsMovable_noexcept,
			constexpr IsEqualityComparable,
			constexpr IsSortable
		);

	public:
		implicit operator 
		BOOL() const 
		{
			return this->value ? TRUE : FALSE;
		}
	};
}
