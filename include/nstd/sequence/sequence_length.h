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
#include "nstd/sequence/type_sequence.h"
#include "nstd/sequence/value_sequence.h"
#include "nstd/sequence/value_tuple.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	//! @brief	Calculate number of elements in any sequence
	template <typename Sequence>
	metafunc sequence_length : core::meta::undefined_t {};

	// Specialization for @c std::integer_sequence
	template <typename T, T... Values>
	metafunc sequence_length<std::integer_sequence<T,Values...>> : std::integral_constant<size_t,sizeof...(Values)> {};
	
	// Specialization for @c nstd::type_sequence
	template <typename... Types>
	metafunc sequence_length<type_sequence<Types...>> : std::integral_constant<size_t,sizeof...(Types)> {};

	// Specialization for @c nstd::value_sequence
	template <typename T, T... Values>
	metafunc sequence_length<value_sequence<T,Values...>> : std::integral_constant<size_t,sizeof...(Values)> {};

	// Specialization for @c nstd::value_tuple
	template <auto... Values>
	metafunc sequence_length<value_tuple<Values...>> : std::integral_constant<size_t,sizeof...(Values)> {};


	//! @brief	Number of elements in any sequence
	template <typename Sequence>
	size_t constexpr
	sequence_length_v = sequence_length<Sequence>::value;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
	//! @test  Verify @c nstd::sequence_length_v is @c 0 for empty @c std::integer_sequence
	static_assert(sequence_length_v<std::integer_sequence<int>> == 0);

	//! @test  Verify @c nstd::sequence_length_v is @c 0 for empty @c nstd::type_sequence
	static_assert(sequence_length_v<type_sequence<>> == 0);

	//! @test  Verify @c nstd::sequence_length_v is @c 0 for empty @c nstd::value_sequence
	static_assert(sequence_length_v<value_sequence<float>> == 0);

	//! @test  Verify @c nstd::sequence_length_v is @c 0 for empty @c nstd::value_tuple
	static_assert(sequence_length_v<value_tuple<>> == 0);

	//! @test  Verify @c nstd::sequence_length_v is @c 1 for @c std::integer_sequence with a single element
	static_assert(sequence_length_v<std::integer_sequence<int,1>> == 1);

	//! @test  Verify @c nstd::sequence_length_v is @c 1 for @c nstd::type_sequence with a single element
	static_assert(sequence_length_v<type_sequence<bool>> == 1);

	//! @test  Verify @c nstd::sequence_length_v is @c 1 for @c nstd::value_sequence with a single element
	static_assert(sequence_length_v<value_sequence<float, 3.14159f>> == 1);

	//! @test  Verify @c nstd::sequence_length_v is @c 1 for @c nstd::value_tuple with a single element
	static_assert(sequence_length_v<value_tuple<42>> == 1);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o