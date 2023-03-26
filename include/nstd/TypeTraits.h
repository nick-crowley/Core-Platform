#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/Metafunc.h"
#include "../src/StdLibrary.h"

// clang-format off
namespace nstd
{
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

}
// clang-format on
