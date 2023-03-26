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
#include "nstd/tuple/tuple_back.h"
#include "nstd/tuple/tuple_first_n.h"
#include "nstd/tuple/tuple_front.h"
#include "nstd/tuple/tuple_last_n.h"
#include "nstd/tuple/tuple_push_front.h"
#include "nstd/tuple/tuple_reverse.h"
#include "nstd/tuple/tuple_transform.h"
#include "nstd/Sequence.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
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
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Separator o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o