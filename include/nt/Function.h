#pragma once
#include "library/core.Platform.h"
#include "core/SignatureAdapter.h"
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
				r.throwAlways();
			else
				return r;
		};
		
		return core::detail::adaptSignature<NumResults>(std::move(callable));
	}
}  // namespace core::nt
