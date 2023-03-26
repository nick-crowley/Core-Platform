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
#include "nstd/tuple/tuple_first_n.h"
#include "nstd/tuple/tuple_reverse.h"

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve type of tuple representing subset of final @c N types of existing tuple
	*
	* @tparam	N		Length of subset
	* @tparam	Tuple	Source tuple
	*/
	template <size_t N, typename Tuple>
	using tuple_last_n = tuple_reverse<tuple_first_n_t<N,tuple_reverse_t<Tuple>>>;


	template <size_t N, typename Tuple>
	using tuple_last_n_t = typename tuple_last_n<N,Tuple>::type;
}

namespace nstd::testing 
{
	// static_assert(std::is_same_v<std::tuple<>, tuple_last_n_t<n,std::tuple<>>>);
#define tuple_last_n_t__returns_empty_tuple_for_n_zero(dummy, n, unused)                          \
	static_assert(std::is_same_v<std::tuple<>, tuple_last_n_t<0,std::tuple<BOOST_PP_ENUM_PARAMS(n,UT)>>>);
	// Test operations for 1 <= N <= 15
	// eg. static_assert(std::is_same_v<std::tuple<>, tuple_last_n_t<n,std::tuple<>>>);
	BOOST_PP_REPEAT(16, tuple_last_n_t__returns_empty_tuple_for_n_zero, ~);
#undef tuple_last_n_t__returns_empty_tuple_for_n_zero
	
	// static_assert(std::is_same_v<invalid_argument, tuple_last_n_t<n,std::tuple<>>>);
#define tuple_last_n_t__returns_invalid_argument_for_empty_tuple(dummy, n, unused)                \
	static_assert(std::is_same_v<tuple_reverse_invalid_argument, tuple_last_n_t<n,std::tuple<>>>);
	
	// Test operations for 1 <= N <= 15
	// eg. static_assert(std::is_same_v<invalid_argument, tuple_last_n_t<n,std::tuple<>>>);
	BOOST_PP_REPEAT_FROM_TO(1,16, tuple_last_n_t__returns_invalid_argument_for_empty_tuple, ~);
#undef tuple_last_n_t__returns_invalid_argument_for_empty_tuple
	
	// static_assert(std::is_same_v<std::tuple<T1,..,Tn,Tn+1>, tuple_last_n_t<1..N,std::tuple<T0,..,Tn,Tn+1>>>);
#define tuple_last_n_t__returns_last_n_types(dummy, n, unused)                                    \
	static_assert(std::is_same_v<std::tuple<BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_INC(n),UT)>,    \
		tuple_last_n_t<n,std::tuple<BOOST_PP_ENUM_PARAMS(n,UT), BOOST_PP_CAT(UT,n)>>>);
	// Test operations for 1 <= N <= 15
	// eg. static_assert(std::is_same_v<std::tuple<UT1>, tuple_last_n_t<1,std::tuple<UT0, UT1>>>);
	BOOST_PP_REPEAT_FROM_TO(1, 15, tuple_last_n_t__returns_last_n_types, ~);
#undef tuple_last_n_t__returns_last_n_types
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Separator o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o