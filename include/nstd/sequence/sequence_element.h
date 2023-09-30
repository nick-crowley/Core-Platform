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
#include "nstd/sequence/is_sequence.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	//! @brief	Query the element type of any homogenous sequence
	template <AnySequence  Sequence>
	metafunc sequence_element : std::type_identity<core::meta::undefined_t> {};
	
	// Specialization for @c std::integer_sequence
	template <typename Value, Value... Values>
	metafunc sequence_element<std::integer_sequence<Value,Values...>> : std::type_identity<Value> {};
	
	// Specialization for @c nstd::type_sequence
	template <typename T, typename... R>
		requires (std::same_as<T,R> && ...)
	metafunc sequence_element<type_sequence<T,R...>> : std::type_identity<T> {};
	
	// Specialization for @c nstd::value_sequence
	template <typename Value, Value... Values>
	metafunc sequence_element<value_sequence<Value,Values...>> : std::type_identity<Value> {};
	
	// Specialization for @c nstd::value_tuple
	template <auto V, auto... R>
		requires (std::same_as<decltype(V),decltype(R)> && ...)
	metafunc sequence_element<value_tuple<V,R...>> : std::type_identity<decltype(V)> {};


	//! @brief  Element type of any homogenous sequence
	template <AnySequence Sequence>
	using sequence_element_t = typename sequence_element<Sequence>::type;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
	//! @test  Verify @c nstd::sequence_element_t returns element type of empty @c std::integer_sequence
	static_assert(std::same_as<sequence_element_t<std::integer_sequence<int>>, int>);

	//! @test  Verify @c nstd::sequence_element_t returns element type of empty @c nstd::value_sequence
	static_assert(std::same_as<sequence_element_t<value_sequence<char>>, char>);
	
	//! @test  Verify @c nstd::sequence_element_t is @c undefined for empty @c nstd::value_tuple
	static_assert(std::same_as<sequence_element_t<value_tuple<>>, core::meta::undefined_t>);

	//! @test  Verify @c nstd::sequence_element_t is @c undefined for empty @c nstd::type_sequence
	static_assert(std::same_as<sequence_element_t<type_sequence<>>, core::meta::undefined_t>);
	
	
	//! @test  Verify @c nstd::sequence_element_t returns element type of non-empty @c std::integer_sequence
	static_assert(std::same_as<sequence_element_t<std::integer_sequence<long,2,3,4>>, long>);

	//! @test  Verify @c nstd::sequence_element_t returns element type of non-empty @c nstd::value_sequence
	static_assert(std::same_as<sequence_element_t<value_sequence<bool,true,false>>, bool>);
	
	//! @test  Verify @c nstd::sequence_element_t returns element type of homogenous non-empty @c nstd::value_tuple
	static_assert(std::same_as<sequence_element_t<value_tuple<1,2,3>>, int>);

	//! @test  Verify @c nstd::sequence_element_t returns element type of homogenous non-empty @c nstd::type_sequence
	static_assert(std::same_as<sequence_element_t<type_sequence<bool,bool,bool>>, bool>);
	

	//! @test  Verify @c nstd::sequence_element_t is @c undefined for heterogenous non-empty @c nstd::value_tuple
	static_assert(std::same_as<sequence_element_t<value_tuple<1,true,2.0f>>, core::meta::undefined_t>);

	//! @test  Verify @c nstd::sequence_element_t is @c undefined for heterogenous non-empty @c nstd::type_sequence
	static_assert(std::same_as<sequence_element_t<type_sequence<bool,char,bool>>, core::meta::undefined_t>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o