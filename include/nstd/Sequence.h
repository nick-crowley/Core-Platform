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
	concept AnyIndexSequence = is_index_sequence<T>::value;


	//! @brief	Query whether type is @c std::integer_sequence<> (of any type and length)
	template <typename Seq>
	metafunc is_integer_sequence : std::false_type {};

	template <typename Value, Value...Vals>
	metafunc is_integer_sequence<std::integer_sequence<Value,Vals...>> : std::true_type {};
	
	template <typename Seq>
	bool constexpr is_integer_sequence_v = is_integer_sequence<Seq>::value;

	//! @brief	Ensure type is @c std::integer_sequence<> (of any type and length)
	template <typename T>
	concept AnyIntegerSequence = is_integer_sequence_v<T>;
	
	static_assert(AnyIntegerSequence<std::integer_sequence<int>>);
	static_assert(AnyIntegerSequence<std::integer_sequence<int,1>>);
	static_assert(AnyIntegerSequence<std::integer_sequence<double,2.0>>);
	static_assert(!AnyIntegerSequence<float>);

	
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

	
} // namespace nstd
