#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/TypeTraits.h"

namespace nstd
{
	template <typename T, typename... Types>
	concept AnyOf = is_any_of_v<T,Types...>;

	template <typename T>
	concept Character = AnyOf<T,char,wchar_t,char8_t,char16_t,char32_t>;

	template <typename T>
	concept Clock = std::chrono::is_clock_v<T>;
	
	template <typename Range, typename U>
	concept ContiguousRangeOf = std::ranges::contiguous_range<Range> 
	                         && std::is_same_v<std::ranges::range_value_t<Range>,U>;
	
	template <typename T, typename... Types>
	concept ConvertibleToAnyOf = (std::convertible_to<T,Types> || ...);

	template <typename T>
	concept Enumeration = std::is_enum_v<T>;

	template <typename From, typename To>
	concept ExplicitlyConvertible = requires(From&& f)
	{
		static_cast<To>(f);
	};
	
	//! @brief	Verify type is non-bool, non-character, integral type (signed or unsigned)
	template <typename T>
	concept Integer = std::integral<T> && !AnyOf<std::make_signed_t<std::remove_cv_t<T>>, bool,char,wchar_t,char8_t,char16_t,char32_t>;

	template <typename T>
	concept IntegralOrEnum = std::is_integral_v<T> || Enumeration<T>;
	
	template <typename Range, typename U>
	concept InputRangeOf = std::ranges::input_range<Range> 
	                    && std::is_same_v<std::ranges::range_value_t<Range>,U>;

	template <typename T, typename Return, typename... Params>
	concept Invocable_r = std::is_invocable_r_v<Return,T,Params...>;

	//! @brief	Ensure type is a function-object/lambda (of any signature)
	template <typename T>
	concept FunctionObject = std::is_class_v<T> && !std::is_abstract_v<T> && requires {
		T::operator();
		// BUG: nstd::FunctionObject can't support templated lambdas or overloaded function-call operators
	};
	
	//! @brief	Ensure type is callable target (of any signature)
	template <typename T>
	concept CallableTarget = FunctionObject<T>
		|| std::is_member_function_pointer_v<T>
		|| std::is_function_v<T>
		|| is_function_pointer_v<T>;
	
	template <typename T>
	concept RealNumber = std::is_arithmetic_v<T> && !Character<T>;
}

namespace nstd::testing {
	struct TestClass {};
	static_assert(FunctionObject<decltype([](){})>);
	static_assert(FunctionObject<decltype([](){ return 42; })>);
	static_assert(FunctionObject<decltype([](int){})>);
	static_assert(!FunctionObject<void()>);
	static_assert(!FunctionObject<void(int)>);
	static_assert(!FunctionObject<void(*)()>);
	static_assert(!FunctionObject<void(TestClass::*)()>);
	static_assert(!FunctionObject<void(TestClass::*)(int)>);
	static_assert(!FunctionObject<void(TestClass::*)(int) const>);
	static_assert(CallableTarget<void()>);
	static_assert(CallableTarget<void(int)>);
	static_assert(CallableTarget<void(*)()>);
	static_assert(CallableTarget<void(TestClass::*)()>);
	static_assert(CallableTarget<void(TestClass::*)(int)>);
	static_assert(CallableTarget<void(TestClass::*)(int) const>);
	static_assert(CallableTarget<decltype([](){})>);
	static_assert(CallableTarget<decltype([](){ return 42; })>);
	static_assert(CallableTarget<decltype([](int){})>);
	static_assert(!CallableTarget<TestClass>);
	static_assert(!CallableTarget<int>);
}
