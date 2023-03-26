#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/metafunc.h"
#include "../../src/StdLibrary.h"

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

	
} // namespace nstd
