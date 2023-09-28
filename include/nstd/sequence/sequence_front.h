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
#include "meta/TagTypes.h"
#include "nstd/experimental/metafunc.h"
#include "nstd/sequence/type_sequence.h"
#include "nstd/sequence/value_sequence.h"
#include "../../../src/StdLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	//! @brief  First element of any sequence [type or value]
	template <typename Sequence>
	metafunc sequence_front : core::meta::undefined_t {};
	
	// Specialization for @c std::integer_sequence
	template <typename T, T F, T... R>
	metafunc sequence_front<std::integer_sequence<T,F,R...>> : std::integral_constant<T, F> {};
	
	// Specialization for @c nstd::type_sequence
	template <typename T, typename... R>
	metafunc sequence_front<type_sequence<T,R...>> : std::type_identity<T> {};

	// Specialization for @c nstd::value_sequence
	template <auto F, auto... R>
	metafunc sequence_front<value_sequence<F,R...>> : std::integral_constant<decltype(F), F> {};
	


	//! @brief  First value of any sequence
	template <typename Sequence>
	auto constexpr
	inline sequence_front_v = core::undefined;
	
	// Specialization for @c std::integer_sequence
	template <typename T, T F, T... R>
	auto constexpr
	inline sequence_front_v<std::integer_sequence<T,F,R...>> = F;
	
	// Specialization for @c nstd::value_sequence
	template <auto F, auto... R>
	auto constexpr
	inline sequence_front_v<value_sequence<F,R...>> = F;



	namespace detail {
		//! @brief  Type of the front element of any sequence
		template <typename Sequence>
		metafunc sequence_front_type : std::type_identity<core::meta::undefined_t> {};
		
		// Specialization for @c std::integer_sequence
		template <typename T, T... R>
		metafunc sequence_front_type<std::integer_sequence<T,R...>> : std::type_identity<T> {};

		// Specialization for @c nstd::type_sequence
		template <typename T, typename... R>
		metafunc sequence_front_type<type_sequence<T,R...>> : std::type_identity<T> {};
		
		// Specialization for @c nstd::value_sequence
		template <auto F, auto... R>
		metafunc sequence_front_type<value_sequence<F,R...>> : std::type_identity<decltype(F)> {};
	}

	//! @brief  Type of the first element of any sequence
	template <typename Sequence>
	using sequence_front_t = typename detail::sequence_front_type<Sequence>::type;


}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd::testing {
	//! @test  Verify @c nstd::sequence_front is @c undefined for non-sequence types
	static_assert(std::convertible_to<sequence_front<void>, core::meta::undefined_t>);

	//! @test  Verify @c nstd::sequence_front is @c undefined for non-sequence types
	static_assert(std::convertible_to<sequence_front<int>, core::meta::undefined_t>);

	//! @test  Verify @c nstd::sequence_front_v returns first value of @c std::integer_sequence
	static_assert(sequence_front_v<std::integer_sequence<int,1,2,3>> == 1);

	//! @test  Verify @c nstd::sequence_front_v returns first value of @c nstd::value_sequence
	static_assert(sequence_front_v<nstd::value_sequence<3,2,1>> == 3);

	//! @test  Verify @c nstd::sequence_front_v returns first type of @c nstd::type_sequence
	static_assert(sequence_front_v<nstd::type_sequence<float,bool>> == core::undefined);

	//! @test  Verify @c nstd::sequence_front_v is undefined for non-sequence types
	static_assert(sequence_front_v<int> == core::undefined);
	
	//! @test  Verify @c nstd::sequence_front_t returns type of @c std::integer_sequence values
	static_assert(std::same_as<int, sequence_front_t<std::integer_sequence<int,1,2,3>>>);

	//! @test  Verify @c nstd::sequence_front_t returns first @c nstd::type_sequence element
	static_assert(std::same_as<int, sequence_front_t<nstd::type_sequence<int,float,char>>>);

	//! @test  Verify @c nstd::sequence_front_t returns type of first @c nstd::value_sequence element
	static_assert(std::same_as<int, sequence_front_t<nstd::value_sequence<3,2,1>>>);

	//! @test  Verify @c nstd::sequence_front_t is undefined for non-sequence types
	static_assert(std::same_as<core::meta::undefined_t, sequence_front_t<int>>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o