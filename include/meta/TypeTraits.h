#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../src/StdLibrary.h"

namespace core::meta 
{
    template <typename F>
	struct add_function_pointer : std::type_identity<F> {};
	
#if defined _M_IX86
	template <typename R, typename... P>
	struct add_function_pointer<R __cdecl(P...)> : std::type_identity<R(__cdecl*)(P...)> {};
	
	template <typename R, typename... P>
	struct add_function_pointer<R __fastcall(P...)> : std::type_identity<R(__fastcall*)(P...)> {};
	
	template <typename R, typename... P>
	struct add_function_pointer<R __stdcall(P...)> : std::type_identity<R(__stdcall*)(P...)> {};
	
	template <typename R, typename... P>
	struct add_function_pointer<R __vectorcall(P...)> : std::type_identity<R(__vectorcall*)(P...)> {};
#elif defined _M_X64
	template <typename R, typename... P>
	struct add_function_pointer<R (P...)> : std::type_identity<R(*)(P...)> {};
#endif

	template <typename F>
	using add_function_pointer_t = typename add_function_pointer<F>::type;
	

    template <typename T, typename... U>
    constexpr bool is_any_of_v = (std::is_same_v<T,U> || ...);


	template <typename F>
	struct remove_function_pointer : std::type_identity<F> {};
	
#if defined _M_IX86
	template <typename R, typename... P>
	struct remove_function_pointer<R(__cdecl*)(P...)> : std::type_identity<R __cdecl(P...)> {};
	
	template <typename R, typename... P>
	struct remove_function_pointer<R(__fastcall*)(P...)> : std::type_identity<R __fastcall(P...)> {};

	template <typename R, typename... P>
	struct remove_function_pointer<R(__stdcall*)(P...)> : std::type_identity<R __stdcall(P...)> {};

	template <typename R, typename... P>
	struct remove_function_pointer<R(__vectorcall*)(P...)> : std::type_identity<R __vectorcall(P...)> {};
#elif defined _M_X64
	template <typename R, typename... P>
	struct remove_function_pointer<R(*)(P...)> : std::type_identity<R (P...)> {};
#endif

	template <typename F>
	using remove_function_pointer_t = typename remove_function_pointer<F>::type;    

	
	//! @brief	Aliases the type with the opposite const-qualitification to 'T'
	template <typename T>
	using toggle_const_t = std::conditional_t<std::is_const_v<T>, std::remove_cv_t<T>, std::add_const_t<T>>;

}
