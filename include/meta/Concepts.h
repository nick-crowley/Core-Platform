#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "meta/TypeTraits.h"

namespace meta
{
	template <typename T>
	concept Character = is_any_of_v<T,char,wchar_t,char8_t,char16_t,char32_t>;

	template <typename T>
	concept Clock = std::chrono::is_clock_v<T>;

	template <typename T>
	concept Enumeration = std::is_enum_v<T>;

	template <typename From, typename To>
	concept ExplicitlyConvertible = requires(From&& f)
	{
		static_cast<To>(f);
	};

	template <typename T>
	concept IntegralOrEnum = std::is_integral_v<T> || Enumeration<T>;
	
	template <typename Range, typename U>
	concept InputRangeOf = std::ranges::input_range<Range> 
	                    && std::is_same_v<std::ranges::range_value_t<Range>,U>;

	template <typename T>
	concept RealNumber = std::is_arithmetic_v<T> && !Character<T>;
}
