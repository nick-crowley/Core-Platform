#pragma once
#include "library/core.Platform.h"
#include "core/CallAdapter.h"
#include "nt/NtStatus.h"

namespace core::nt
{
	template <unsigned NumResults = 0, typename... Parameters>
	auto constexpr 
	function(::NTSTATUS (__stdcall *fx)(Parameters...)) noexcept
	{
		auto const callable = [fx](Parameters... args) -> NTSTATUS 
		{
			if (NtStatus r = (*fx)(std::forward<Parameters>(args)...); !r)
				r.throw_always();
			else
				return r;
		};

		return ::detail::makeCallAdapter<
			NumResults, sizeof...(Parameters), decltype(callable), Parameters...
		>(
			std::move(callable)
		);
	}
}  // namespace core::nt
