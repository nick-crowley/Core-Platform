#pragma once
#include "library/core.Platform.h"

namespace core
{
	template <meta::Character Character>
	class ZString
	{
		using basic_zstring = gsl::basic_zstring<Character>;

	public:
		basic_zstring const  Text;
		size_t const         Length;

	public:
		constexpr 
		ZString(basic_zstring const str)
		  : Text{str}, 
		    Length{ZString::measure(str)}
		{}

	public:
		constexpr size_t
		static measure(basic_zstring str) {
			size_t len = 0;
			for (; str[len]; ++len)
			{}
			return len;
		}
	};
}
