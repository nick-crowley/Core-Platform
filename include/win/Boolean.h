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
			//FIXME: constexpr IsCopyable noexcept,
            constexpr IsCopyAssignable noexcept,
            constexpr IsCopyConstructible noexcept,
            //FIXME: constexpr IsMovable noexcept,
            constexpr IsMoveAssignable noexcept,
            constexpr IsMoveConstructible noexcept,
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
