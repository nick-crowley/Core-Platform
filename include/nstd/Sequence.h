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
	
} // namespace nstd
