#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/metafunc.h"
#include "nstd/Sequence.h"
#include "../../src/StdLibrary.h"

namespace core::meta
{	
	//! @brief	Query whether type is @c std::tuple<> (of any length)
	template <typename T>
	metafunc is_tuple : std::false_type {};

	template <typename... R>
	metafunc is_tuple<std::tuple<R...>> : std::true_type {};

	template <typename T>
	bool constexpr is_tuple_v = is_tuple<T>::value;


	//! @brief	Ensure type is @c std::tuple<> (of any length)
	template <typename T>
	concept AnyTuple = is_tuple<T>::value;

	
	//! @brief	Tuple with its matching index sequence
	template <AnyTuple Types, nstd::AnyIndexSequence Indicies>
	struct IndexedTuple {};

	//! @brief	An @c IndexedTuple containing an empty tuple and empty indicies sequence
	using EmptyIndexedTuple = IndexedTuple<std::tuple<>, std::index_sequence<>>;
	

	//! @brief	An @c IndexedTuple containing a single element
	template <typename T>
	using UnaryIndexedTuple = IndexedTuple<std::tuple<T>, std::index_sequence<0>>;


	//! @brief	Generate an @c IndexedTuple of arbitrary length
	template <typename... Types>
	using MakeIndexedTuple = IndexedTuple<std::tuple<Types...>, std::index_sequence_for<Types...>>;

	
	//! @brief	Query whether type is @c IndexedTuple (of any length)
	template <typename T>
	metafunc is_indexed_tuple : std::false_type {};

	template <AnyTuple T, nstd::AnyIndexSequence I>
	metafunc is_indexed_tuple<IndexedTuple<T,I>> : std::true_type {};
	
	template <typename T>
	bool constexpr is_indexed_tuple_v = is_indexed_tuple<T>::value;

	
	//! @brief	Ensure type is @c IndexedTuple (of any length)
	template <typename T>
	concept AnyIndexedTuple = is_indexed_tuple<T>::value;
	
} // namespace nstd
