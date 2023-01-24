#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "meta/TypeTraits.h"

namespace core::meta
{
	template <typename T, typename... Types>
	concept AnyOf = is_any_of_v<T,Types...>;

	template <typename T>
	concept Character = AnyOf<T,char,wchar_t,char8_t,char16_t,char32_t>;

	template <typename T>
	concept Clock = chrono::is_clock_v<T>;
	
	template <typename Range, typename U>
	concept ContiguousRangeOf = ranges::contiguous_range<Range> 
	                         && std::is_same_v<ranges::range_value_t<Range>,U>;

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
	concept InputRangeOf = ranges::input_range<Range> 
	                    && std::is_same_v<ranges::range_value_t<Range>,U>;

	template <typename T, typename Return, typename... Params>
	concept Invocable_r = std::is_invocable_r_v<Return,T,Params...>;

	template <typename T>
	concept RealNumber = std::is_arithmetic_v<T> && !Character<T>;
}
