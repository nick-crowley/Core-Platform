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
#include "nstd/experimental/metafunc.h"
#include "nstd/sequence/type_sequence.h"
#include "nstd/sequence/value_tuple.h"
#include "nstd/sequence/value_sequence.h"
#include "../../../src/StdLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	//! @brief	Query whether @p Sequence is any sequence type
	template <typename Sequence>
	metafunc is_sequence : std::false_type {};

	// Specialization for @c std::integer_sequence
	template <typename Value, Value... Rs>
	metafunc is_sequence<std::integer_sequence<Value,Rs...>> : std::true_type {};
	
	// Specialization for @c nstd::type_sequence
	template <typename... R>
	metafunc is_sequence<type_sequence<R...>> : std::true_type {};

	// Specialization for @c nstd::value_sequence
	template <typename Value, Value... Rs>
	metafunc is_sequence<value_sequence<Value,Rs...>> : std::true_type {};

	// Specialization for @c nstd::value_tuple
	template <auto... Values>
	metafunc is_sequence<value_tuple<Values...>> : std::true_type {};


	//! @brief	Ensure @p Sequence is any sequence of elements
	template <typename Sequence>
	concept AnySequence = is_sequence<Sequence>::value;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
	//! @test  Verify @c nstd::AnySequence rejects non-sequence types
	static_assert(!AnySequence<int>);
	

	//! @test  Verify @c nstd::AnySequence recognises empty @c std::integer_sequence
	static_assert(AnySequence<std::integer_sequence<int>>);
	
	//! @test  Verify @c nstd::AnySequence recognises empty @c nstd::value_sequence 
	static_assert(AnySequence<nstd::value_sequence<float>>);
	
	//! @test  Verify @c nstd::AnySequence recognises empty @c nstd::type_sequence
	static_assert(AnySequence<nstd::type_sequence<>>);

	//! @test  Verify @c nstd::AnySequence recognises empty @c nstd::value_tuple
	static_assert(AnySequence<nstd::value_tuple<>>);

	
	//! @test  Verify @c nstd::AnySequence recognises non-empty @c std::integer_sequence
	static_assert(AnySequence<std::integer_sequence<int,1,2,3>>);
	
	//! @test  Verify @c nstd::AnySequence recognises non-empty @c nstd::value_sequence 
	static_assert(AnySequence<nstd::value_sequence<float,3.14159f>>);
	
	//! @test  Verify @c nstd::AnySequence recognises non-empty @c nstd::type_sequence
	static_assert(AnySequence<nstd::type_sequence<bool>>);

	//! @test  Verify @c nstd::AnySequence recognises non-empty @c nstd::value_tuple
	static_assert(AnySequence<nstd::value_tuple<1,true,'c'>>);

}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o