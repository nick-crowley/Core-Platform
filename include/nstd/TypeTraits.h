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
#include "nstd/experimental/Metafunc.h"
#include "../src/StdLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	// clang-format off

    template <typename F>
	metafunc add_function_pointer : std::type_identity<F> {};
	
#if defined _M_IX86
	template <typename R, typename... P>
	metafunc add_function_pointer<R __cdecl(P...)> : std::type_identity<R(__cdecl*)(P...)> {};
	
	template <typename R, typename... P>
	metafunc add_function_pointer<R __fastcall(P...)> : std::type_identity<R(__fastcall*)(P...)> {};
	
	template <typename R, typename... P>
	metafunc add_function_pointer<R __stdcall(P...)> : std::type_identity<R(__stdcall*)(P...)> {};
	
	template <typename R, typename... P>
	metafunc add_function_pointer<R __vectorcall(P...)> : std::type_identity<R(__vectorcall*)(P...)> {};
#elif defined _M_X64
	template <typename R, typename... P>
	metafunc add_function_pointer<R (P...)> : std::type_identity<R(*)(P...)> {};
#endif

	template <typename F>
	using add_function_pointer_t = typename add_function_pointer<F>::type;
	

    template <typename T, typename... U>
    constexpr bool is_any_of_v = (std::is_same_v<T,U> || ...);

	
	//! @brief	Query whether type is function-pointer
	template <typename T>
	metafunc is_function_pointer : std::false_type {};

	template <typename R, typename... Params>
	metafunc is_function_pointer<R(*)(Params...)> : std::true_type {};
	
	template <typename T>
	bool constexpr is_function_pointer_v = is_function_pointer<T>::value;


	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Type-trait which clones the CV-qualification of another type
	* @details	Produces the type @e [cv-qual] @c To from the type @e [cv-qual] @c From
	* @typedef	mirror_cv
	*
	* @tparam	From	Type whose cv-qualification should be cloned
	* @tparam	To		Any type
	*/
	template <typename From, typename To>
	metafunc mirror_cv : std::type_identity<To> {};

	// const From => const To
	template <typename From, typename To>
	metafunc mirror_cv<const From,To> : std::type_identity<const To> {};

	// volatile From => volatile To
	template <typename From, typename To>
	metafunc mirror_cv<volatile From,To> : std::type_identity<volatile To> {};

	// const-volatile From => const-volatile To
	template <typename From, typename To>
	metafunc mirror_cv<const volatile From,To> : std::type_identity<const volatile To> {};

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @typedef	mirror_cv_t 
	* 
	* @tparam	From	Type whose cv-qualification should be cloned
	* @tparam	To		Any type
	*/
	template <typename From, typename To>
	using mirror_cv_t = typename mirror_cv<From,To>::type;


	template <typename F>
	metafunc remove_function_pointer : std::type_identity<F> {};
	
#if defined _M_IX86
	template <typename R, typename... P>
	metafunc remove_function_pointer<R(__cdecl*)(P...)> : std::type_identity<R __cdecl(P...)> {};
	
	template <typename R, typename... P>
	metafunc remove_function_pointer<R(__fastcall*)(P...)> : std::type_identity<R __fastcall(P...)> {};

	template <typename R, typename... P>
	metafunc remove_function_pointer<R(__stdcall*)(P...)> : std::type_identity<R __stdcall(P...)> {};

	template <typename R, typename... P>
	metafunc remove_function_pointer<R(__vectorcall*)(P...)> : std::type_identity<R __vectorcall(P...)> {};
#elif defined _M_X64
	template <typename R, typename... P>
	metafunc remove_function_pointer<R(*)(P...)> : std::type_identity<R (P...)> {};
#endif

	template <typename F>
	using remove_function_pointer_t = typename remove_function_pointer<F>::type;    

	
	//! @brief	Aliases the type with the opposite const-qualitification to 'T'
	template <typename T>
	using toggle_const_t = std::conditional_t<std::is_const_v<T>, std::remove_cv_t<T>, std::add_const_t<T>>;
	
	// clang-format on
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Separator o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o