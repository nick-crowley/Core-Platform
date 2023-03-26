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
#include "nstd/tuple/is_tuple.h"
#include "../src/libBoost.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	struct tuple_first_n_invalid_argument;

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve type of tuple representing subset of first @c N types of existing tuple
	*
	* @tparam	N	Length of subset
	* @tparam	T	Source tuple
	*/
	template <size_t N, Tuple T>
		requires (N <= std::tuple_size_v<T>)
	struct tuple_first_n : std::type_identity<tuple_first_n_invalid_argument> {};

	template <typename...R>
	struct tuple_first_n<0,std::tuple<R...>>
		: std::type_identity<std::tuple<>> {};

	// template <typename T0, ..., typename Tn, typename... Rest> 
	// struct tuple_first_n<1..N, std::tuple<T0,..,Tn,Rest...>> : std::type_identity<std::tuple<T0,..,Tn>> {};
#define tuple_first_n__definition(obj, n, unused)                                                 \
	template <BOOST_PP_ENUM_PARAMS(n,typename T), typename... Rest>                               \
	struct tuple_first_n<n,std::tuple<BOOST_PP_ENUM_PARAMS(n,T),Rest...>>                         \
		: std::type_identity<std::tuple<BOOST_PP_ENUM_PARAMS(n,T)>> {};
	// Define operations for 1 <= N <= 15
	// template <typename T0, typename T1, typename... Rest> struct tuple_first_n<2,std::tuple<T0, T1, Rest...>> : std::type_identity<std::tuple<T0, T1>> {};
	BOOST_PP_REPEAT_FROM_TO(1, 16, tuple_first_n__definition, ~);
#undef tuple_first_n__definition
	
	template <size_t N, Tuple T>
		requires (N <= std::tuple_size_v<T>)
	using tuple_first_n_t = typename tuple_first_n<N,T>::type;
}

namespace nstd::testing 
{
	// struct UT0 {}, ..., struct UTn {};
#define make_tuple_test_fakes(dummy, n, unused)                                                   \
	struct BOOST_PP_CAT(UT,n) {};
	// Generate 15 fake types
	BOOST_PP_REPEAT(16, make_tuple_test_fakes, ~);
#undef make_tuple_test_fakes

	// tuple_first_n_t
	
	// static_assert(std::is_same_v<std::tuple<>, tuple_first_n_t<0,std::tuple<T0,...,TN>>>);
#define tuple_first_n_t__returns_empty_tuple_for_n_zero(dummy, n, unused)                         \
	static_assert(std::is_same_v<std::tuple<>, tuple_first_n_t<0,std::tuple<BOOST_PP_ENUM_PARAMS(n,UT)>>>);
	// Test operations for 1 <= N <= 15
	// eg. static_assert(std::is_same_v<std::tuple<>, tuple_first_n_t<n,std::tuple<>>>);
	BOOST_PP_REPEAT(16, tuple_first_n_t__returns_empty_tuple_for_n_zero, ~);
#undef tuple_first_n_t__returns_empty_tuple_for_zero

	// static_assert(std::is_same_v<invalid_argument, tuple_first_n_t<n,std::tuple<>>>);
#define tuple_first_n_t__returns_invalid_argument_for_empty_tuple(dummy, n, unused)               \
	static_assert(std::is_same_v<tuple_first_n_invalid_argument, tuple_first_n_t<n,std::tuple<>>>);
	// Test operations for 1 <= N <= 15
	// eg. static_assert(std::is_same_v<invalid_argument, tuple_first_n_t<n,std::tuple<>>>);
	BOOST_PP_REPEAT_FROM_TO(1, 16, tuple_first_n_t__returns_invalid_argument_for_empty_tuple, ~);
#undef tuple_first_n_t__returns_invalid_argument_for_empty_tuple
	
	// static_assert(std::is_same_v<std::tuple<T0,..,Tn>, tuple_first_n_t<1..N,std::tuple<T0,..,Tn,Tn+1>>>);
#define tuple_first_n_t__returns_first_n_types(dummy, n, unused)                                  \
	static_assert(std::is_same_v<std::tuple<BOOST_PP_ENUM_PARAMS(n,UT)>,                          \
		tuple_first_n_t<n,std::tuple<BOOST_PP_ENUM_PARAMS(n,UT), BOOST_PP_CAT(UT,n)>>>);
	// Test operations for 1 <= N <= 15
	// eg. static_assert(std::is_same_v<std::tuple<UT0>, tuple_first_n_t<1,std::tuple<UT0, UT1>>>);
	BOOST_PP_REPEAT_FROM_TO(1, 16, tuple_first_n_t__returns_first_n_types, ~);
#undef tuple_first_n_t__returns_first_n_types
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Separator o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o