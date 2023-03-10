#pragma once
#include "library/core.Platform.h"
#include "core/CallAdapter.h"
#include "win/LResult.h"

namespace core::win
{
	template <unsigned NumResults = 0, typename ReturnType, typename... Parameters>
	auto constexpr 
	function(ReturnType (__stdcall *fx)(Parameters...)) noexcept requires std::_Is_any_of_v<ReturnType,LONG,LONG_PTR>
	{	
		auto const callable = [fx](Parameters... args) -> ReturnType
		{
			ThrowingLResult r = (*fx)(std::forward<Parameters>(args)...);
			return static_cast<ReturnType>(r);
		};

		return core::detail::makeCallAdapter<NumResults, 
		                                     sizeof...(Parameters), 
		                                     decltype(callable), 
		                                     Parameters...>(std::move(callable));
	}
	
	template <unsigned NumResults = 0, typename... Parameters>
	auto constexpr 
	function(::BOOL (__stdcall *fx)(Parameters...)) noexcept
	{	
		auto const callable = [fx](Parameters... args) -> BOOL
		{
			if (BOOL r = (*fx)(std::forward<Parameters>(args)...); r == FALSE)
				LastError{}.throwAlways();
			else
				return r;
		};

		return core::detail::makeCallAdapter<NumResults, 
		                                     sizeof...(Parameters), 
		                                     decltype(callable), 
		                                     Parameters...>(std::move(callable));
	}
}  // namespace core::win
