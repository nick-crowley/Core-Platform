#pragma once
#include "library/core.Platform.h"

namespace core
{
	template <nstd::Character Character>
	class ZString
	{
		using basic_zstring = gsl::basic_zstring<Character>;
		using basic_czstring = gsl::basic_zstring<Character const>;

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
		static measure(basic_czstring str) {
			if (!str)
				return 0;

			size_t len = 0;
			while (str[len]) 
				++len;
			return len;
		}

	public:
		constexpr
		implicit operator
		std::basic_string_view<Character>() const {
			return {this->Text, this->Text+this->Length};
		}
	};
}
