/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2023, Nick Crowley. All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions
*    and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of
*    conditions and the following disclaimer in the documentation and/or other materials provided
*    with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
* FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
* WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* The views and conclusions contained in the software and documentation are those of the author 
* and should not be interpreted as representing official policies, either expressed or implied, of
* the projects which contain it.
*/
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Preprocessor Directives o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "nstd/TypeTraits.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
		&T::operator();
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
	
	//! @brief	Ensure type is either built-in string or string-like class (of any character type)
	template <typename T>
    concept Stringish = AnyOf<std::decay_t<T>,
                              gsl::zstring,gsl::wzstring,
                              gsl::czstring,gsl::cwzstring,
#ifdef HAS_ATL_STRING
                              ATL::CString,
#endif
                              std::string_view,std::wstring_view,
                              std::string,std::wstring>;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o