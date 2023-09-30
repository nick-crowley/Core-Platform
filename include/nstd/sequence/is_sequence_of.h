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
	//! @brief	Query whether @p Sequence is a sequence of elements of type @p T
	template <AnySequence Sequence, typename T>
	metafunc is_sequence_of : std::false_type {};

	// Specialization for @c std::integer_sequence
	template <typename Value, Value... Rs>
	metafunc is_sequence_of<std::integer_sequence<Value,Rs...>, Value> : std::true_type {};
	
	// Specialization for @c nstd::type_sequence
	template <typename T, typename... R>
	metafunc is_sequence_of<type_sequence<R...>, T> : std::bool_constant<
		(sizeof...(R)) && (std::same_as<T,R> && ...)
	> {};

	// Specialization for @c nstd::value_sequence
	template <typename Value, Value... Rs>
	metafunc is_sequence_of<value_sequence<Value,Rs...>, Value> : std::true_type {};

	// Specialization for @c nstd::value_tuple
	template <typename T, auto... Values>
	metafunc is_sequence_of<value_tuple<Values...>, T> : std::bool_constant<
		(sizeof...(Values) > 0) && (std::same_as<T,decltype(Values)> && ...)
	> {};


	//! @brief	Ensure @p T is any sequence of elements of type @p Element
	template <typename T, typename Element>
	concept SequenceOf = is_sequence_of<T,Element>::value;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
	//! @test  Verify @c nstd::SequenceOf recognises empty @c std::integer_sequence element type
	static_assert(SequenceOf<std::integer_sequence<int>, int>);
	
	//! @test  Verify @c nstd::SequenceOf recognises empty @c nstd::value_sequence element type
	static_assert(SequenceOf<nstd::value_sequence<float>, float>);
	
	//! @test  Verify @c nstd::SequenceOf rejects empty @c nstd::type_sequence
	static_assert(!SequenceOf<nstd::type_sequence<>, int>);

	//! @test  Verify @c nstd::SequenceOf rejects empty @c nstd::value_tuple
	static_assert(!SequenceOf<nstd::value_tuple<>, bool>);


	//! @test  Verify @c nstd::SequenceOf recognises non-empty @c std::integer_sequence element type
	static_assert(SequenceOf<std::integer_sequence<int,1,3,5>, int>);
	
	//! @test  Verify @c nstd::SequenceOf recognises non-empty @c nstd::value_sequence element type
	static_assert(SequenceOf<nstd::value_sequence<float,3.14159f,2.34f>, float>);
	
	//! @test  Verify @c nstd::SequenceOf recognises non-empty @c nstd::value_tuple element type
	static_assert(SequenceOf<nstd::value_tuple<true,false,true>, bool>);

	//! @test  Verify @c nstd::SequenceOf rejects heterogenous non-empty @c nstd::value_tuple 
	static_assert(!SequenceOf<nstd::value_tuple<true, 42, false>, bool>);

	//! @test  Verify @c nstd::SequenceOf recognises non-empty @c nstd::type_sequence element type
	static_assert(SequenceOf<nstd::type_sequence<long,long>, long>);

	//! @test  Verify @c nstd::SequenceOf rejects heterogenous non-empty @c nstd::type_sequence 
	static_assert(!SequenceOf<nstd::type_sequence<long,int,long>, long>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o