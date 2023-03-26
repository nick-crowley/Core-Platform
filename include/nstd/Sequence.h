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

	
} // namespace nstd
