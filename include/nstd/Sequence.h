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
#include "../../src/StdLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{	
	//! @brief	Query whether type is @c std::index_sequence<> (of any length)
	template <typename T>
	metafunc is_index_sequence : std::false_type {};

	template <size_t... N>
	metafunc is_index_sequence<std::index_sequence<N...>> : std::true_type {};
	
	template <typename T>
	bool constexpr is_index_sequence_v = is_index_sequence<T>::value;


	//! @brief	Ensure type is @c std::index_sequence<> (of any length)
	template <typename T>
	concept IndexSequence = is_index_sequence<T>::value;


	//! @brief	Query whether type is @c std::integer_sequence<> (of any type and length)
	template <typename Seq>
	metafunc is_integer_sequence : std::false_type {};

	template <typename Value, Value...Vals>
	metafunc is_integer_sequence<std::integer_sequence<Value,Vals...>> : std::true_type {};
	
	template <typename Seq>
	bool constexpr is_integer_sequence_v = is_integer_sequence<Seq>::value;

	//! @brief	Ensure type is @c std::integer_sequence<> (of any type and length)
	template <typename T>
	concept IntegerSequence = is_integer_sequence_v<T>;
	
	static_assert(IntegerSequence<std::integer_sequence<int>>);
	static_assert(IntegerSequence<std::integer_sequence<int,1>>);
	static_assert(IntegerSequence<std::integer_sequence<double,2.0>>);
	static_assert(!IntegerSequence<float>);

	
	//! @brief	Query whether type is an @c std::integer_sequence<> of a particular type
	template <typename Sequence, typename T>
	metafunc is_sequence_of : std::false_type {};

	template <typename Value, Value... Values>
	metafunc is_sequence_of<std::integer_sequence<Value,Values...>, Value> : std::true_type {};
	
	//! @brief	Ensure type is an @c std::integer_sequence<> of a particular type
	template <typename T, typename Element>
	concept SequenceOf = is_sequence_of<T,Element>::value;
	
	static_assert(SequenceOf<std::integer_sequence<int>,int>);
	static_assert(SequenceOf<std::integer_sequence<int,1>,int>);
	static_assert(!SequenceOf<std::integer_sequence<float>,int>);

	
	//! @brief	Query the element type of a @c std::integer_sequence<>
	template <IntegerSequence Sequence>
	metafunc sequence_element;

	template <typename Value, Value... Values>
	metafunc sequence_element<std::integer_sequence<Value,Values...>> {
		using type = Value;
	};

	template <IntegerSequence Sequence>
	using sequence_element_t = typename sequence_element<Sequence>::type;
	
	
	//! @brief	Calculate number of elements in @c std::integer_sequence<> (of any type)
	template <IntegerSequence Sequence>
	metafunc sequence_length;

	template <typename T, T... Values>
	metafunc sequence_length<std::integer_sequence<T,Values...>> : std::integral_constant<size_t,sizeof...(Values)> {};
	
	template <IntegerSequence Sequence>
	size_t constexpr
	sequence_length_v = sequence_length<Sequence>::value;
	
	static_assert(sequence_length_v<std::integer_sequence<int>> == 0);
	static_assert(sequence_length_v<std::integer_sequence<int,1>> == 1);

	
	//! @brief	Append an item to an integer sequence
	template <IntegerSequence Sequence, sequence_element_t<Sequence> Element>
	metafunc push_back;

	template <typename Element, Element... Values, Element NewValue>
	metafunc push_back<std::integer_sequence<Element,Values...>, NewValue> 
		: std::type_identity<std::integer_sequence<Element,Values...,NewValue>> 
	{};

	template <IntegerSequence Sequence, sequence_element_t<Sequence> Element>
	using push_back_t = typename push_back<Sequence,Element>::type;
	
	static_assert(std::same_as<push_back_t<std::integer_sequence<int>, 1>, std::integer_sequence<int,1>>);
	static_assert(std::same_as<push_back_t<std::integer_sequence<int,1>, 2>, std::integer_sequence<int,1,2>>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Separator o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o