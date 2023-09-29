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
#include "nstd/sequence/is_value_sequence.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	//! @brief	Append value to any value-sequence
	template <AnyValueSequence Sequence, auto Element>
	metafunc sequence_push_back : std::type_identity<core::meta::undefined_t> {};
	
	// Specialization for @c std::integer_sequence
	template <typename T, T... V, T E>
	metafunc sequence_push_back<std::integer_sequence<T,V...>, E> : std::type_identity<
		std::integer_sequence<T,V..., E>
	>{};
	
	// Specialization for @c nstd::value_sequence
	template <typename T, T... V, T E>
	metafunc sequence_push_back<value_sequence<T,V...>, E> : std::type_identity<
		value_sequence<T,V..., E>
	>{};
	
	// Specialization for @c nstd::value_tuple
	template <auto... V, auto E>
	metafunc sequence_push_back<value_tuple<V...>, E> : std::type_identity<
		value_tuple<V..., E>
	>{};
	
	//! @brief	Append value to any value-sequence
	template <AnyValueSequence Sequence, auto Element>
	using sequence_push_back_t = typename sequence_push_back<Sequence,Element>::type;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
	//! @test  Verify @c nstd::sequence_push_back_t appends element to empty @c std::integer_sequence
	static_assert(std::same_as<sequence_push_back_t<std::integer_sequence<int>, 1>, std::integer_sequence<int,1>>);
	
	//! @test  Verify @c nstd::sequence_push_back_t appends element to empty @c nstd::value_sequence
	static_assert(std::same_as<sequence_push_back_t<value_sequence<int>, 1>, value_sequence<int,1>>);

	//! @test  Verify @c nstd::sequence_push_back_t appends element to empty @c nstd::value_tuple
	static_assert(std::same_as<sequence_push_back_t<value_tuple<>, 1>, value_tuple<1>>);

	
	//! @test  Verify @c nstd::sequence_push_back_t appends element to non-empty @c std::integer_sequence
	static_assert(std::same_as<sequence_push_back_t<std::integer_sequence<int,1>, 2>, std::integer_sequence<int,1,2>>);
	
	//! @test  Verify @c nstd::sequence_push_back_t appends element to non-empty @c nstd::value_sequence
	static_assert(std::same_as<sequence_push_back_t<value_sequence<int,1>, 2>, value_sequence<int,1,2>>);

	//! @test  Verify @c nstd::sequence_push_back_t appends element to non-empty @c nstd::value_tuple
	static_assert(std::same_as<sequence_push_back_t<value_tuple<1>, 2>, value_tuple<1,2>>);

	
	//! @test  Verify @c nstd::sequence_push_back_t cannot append heterogenous value to homogenous std::integer_sequence
	static_assert(std::same_as<sequence_push_back_t<std::integer_sequence<int>,42.0f>, core::meta::undefined_t>);

	//! @test  Verify @c nstd::sequence_push_back_t cannot append heterogenous value to homogenous nstd::value_sequence
	static_assert(std::same_as<sequence_push_back_t<value_sequence<float>,42>, core::meta::undefined_t>);
	
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o