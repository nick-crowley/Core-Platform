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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "core/SignatureAdapter.h"
#include "win/HResult.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::com
{
	template <typename... Parameters>
	using function_pointer_t = ::HRESULT (COMAPI *)(Parameters...);

	template <meta::ComInterface Interface, typename... Parameters>
	using method_pointer_t = ::HRESULT (COMAPI Interface::*)(Parameters...);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::com 
{
	template <unsigned NumResults = 0, typename... Parameters>
	auto constexpr
	function(function_pointer_t<Parameters...> fx) noexcept
	{
		auto const callable = [fx](Parameters... args) -> ::HRESULT
		{
			win::ThrowingHResult hr = (*fx)(std::forward<Parameters>(args)...);
			return S_OK;
		};

		return core::detail::adaptSignature<NumResults>(callable);
	}

	template <unsigned NumResults = 0, meta::ComInterface Interface, typename... Parameters>
	auto constexpr
	method(method_pointer_t<Interface,Parameters...> mx) noexcept
	{
		auto const callable = [mx](Interface& object, Parameters... args) -> ::HRESULT
		{
			win::ThrowingHResult hr = (object.*mx)(args...);
			return S_OK;
		};
		return core::detail::adaptSignature<NumResults>(callable);
	}

	//! @brief	Type of COM method wrapper (which can be quite complicated to determine)
	template <unsigned NumResults, meta::ComInterface Interface, typename... Parameters>
	using method_t = decltype(method<NumResults>(std::declval<method_pointer_t<Interface,Parameters...>>()));

}  // namespace core::com
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail::testing 
{
	//! @test  Verify @c AdaptedSignature_t<7,decltype(::CoQueryProxyBlanket)) produces expected return types
	static_assert(
		std::is_same_v<
			SignatureReturnTypes_t<AdaptedSignature_t<7,DeduceSignature_t<decltype(::CoQueryProxyBlanket)>>>,
			mpl::vector<DWORD, DWORD, wchar_t*, DWORD, DWORD, RPC_AUTH_IDENTITY_HANDLE, DWORD>
		>
	);

	//! @test  Verify @c com::function<7>(::CoQueryProxyBlanket()) produces expected @c core::detail::FunctionSignature
	static_assert(
		std::is_same_v<
			AdaptedSignature_t<7,DeduceSignature_t<decltype(::CoQueryProxyBlanket)>>,
			FunctionSignature<nstd::make_indexed_tuple_t<DWORD, DWORD, wchar_t*, DWORD, DWORD, RPC_AUTH_IDENTITY_HANDLE, DWORD>, nstd::unary_indexed_tuple_t<IUnknown*>>
		>
	);

	//! @test  Verify @c com::function<7>(::CoQueryProxyBlanket()) produces a type which can be called with an @c IUnknown* argument
	static_assert(
		std::is_invocable_v<decltype(com::function<7>(::CoQueryProxyBlanket)), IUnknown*>
	);

	//! @test  Verify @c com::function<7>(::CoQueryProxyBlanket()) produces a type which returns the expected 7-tuple when invoked with an @c IUnknown* argument
	static_assert(
		std::is_same_v<
			std::invoke_result_t<decltype(com::function<7>(::CoQueryProxyBlanket)), IUnknown*>,
			std::tuple<DWORD,DWORD,wchar_t*,DWORD,DWORD,RPC_AUTH_IDENTITY_HANDLE,DWORD>
		>
	);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o