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
#ifdef __clang__
#	error Clang doesn't support compiling EnumNames.h yet
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "core/Reflection.h"
#include "nstd/Sequence.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
	namespace detail 
	{
		template <nstd::EnumSequence Sequence, auto Value>
		using push_back_if_valid_enum_t = std::conditional_t<is_valid_enumerator_v<static_cast<nstd::sequence_element_t<Sequence>>(Value)>, 
		                                                nstd::sequence_push_back_t<Sequence,static_cast<nstd::sequence_element_t<Sequence>>(Value)>, 
		                                                Sequence>;

		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
			requires (Start <= Finish)
		metafunc linear_search_impl : std::conditional_t<
			Start == Finish,
			std::type_identity<push_back_if_valid_enum_t<Result,Finish>>,
			linear_search_impl<E, (Start+1 <= Finish ? Start+1 : Finish), Finish, push_back_if_valid_enum_t<Result,Start>>
		> 
		{};
	}
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Compile-time search algorithm which locates enumerators using a blind linear search
	*
	* @tparam	E	Enumeration whos enumerators are to be searched
	* @tparam	Start	Inclusive minimum of search range
	* @tparam	Finish	Inclusive maximum of search range
	*/
	template <nstd::Enumeration E, std::underlying_type_t<E> Start, std::underlying_type_t<E> Finish>
		requires (Start < Finish)
	using BlindLinearSearch = typename detail::linear_search_impl<E,Start,Finish>::type;
	

	namespace detail 
	{
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
		metafunc geometric_search_impl;

		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result>
			requires std::unsigned_integral<std::underlying_type_t<E>> 
			      && (Start <= Finish)
			      && (nstd::is_pow2(Start))
			      && (nstd::is_pow2(Finish))
		metafunc geometric_search_impl<E,Start,Finish,Result> : std::conditional_t<
			Start == Finish,
			std::type_identity<push_back_if_valid_enum_t<Result,Finish>>,
			geometric_search_impl<E, (Start<<1 != Finish && Start<<1 != 0 ? Start<<1 : Finish), Finish, push_back_if_valid_enum_t<Result,Start>>
		> 
		{};

		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result>
			requires std::signed_integral<std::underlying_type_t<E>> 
			      && (Start > 0)
			      && (Finish > 0)
			      && (Start <= Finish)
			      && (nstd::is_pow2(Start))
			      && (nstd::is_pow2(Finish))
			      && (Finish != std::numeric_limits<std::underlying_type_t<E>>::min())
		metafunc geometric_search_impl<E,Start,Finish,Result> : std::conditional_t<
			Start == Finish,
			std::type_identity<push_back_if_valid_enum_t<Result,Finish>>,
			geometric_search_impl<E, (Start<<1 != Finish && Start<<1 != 0 ? Start<<1 : Finish), Finish, push_back_if_valid_enum_t<Result,Start>>
		> 
		{};

		template <nstd::Integer>
		metafunc max_pow2;

		template <std::signed_integral N>
		metafunc max_pow2<N> : std::integral_constant<N, 1 << (-2 + sizeof(N)*8)>
		{};

		template <std::unsigned_integral N>
		metafunc max_pow2<N> : std::integral_constant<N, 1 << (-1 + sizeof(N)*8)>
		{};
	}
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Compile-time search algorithm which extends blind linear search with a scan of remaining power-of-2 values
	*
	* @tparam	E	Enumeration whos enumerators are to be searched
	* @tparam	Start	Inclusive minimum of search range for initial blind linear search
	* @tparam	Finish	Inclusive maximum of search range for initial blind linear search
	* 
	* @remarks	Scan of remaining power-of-2 values begins at the next power-of-2 following @p Finish
	*/
	template <nstd::Enumeration E, std::underlying_type_t<E> Start, std::underlying_type_t<E> Finish>
		requires (Start < Finish) 
	using BlindLinearSearchThenPowersOf2 = typename detail::geometric_search_impl<
		E,
		std::bit_ceil<std::make_unsigned_t<std::underlying_type_t<E>>>(Finish),
		detail::max_pow2<std::underlying_type_t<E>>::value,
		typename detail::linear_search_impl<E,Start,Finish>::type
	>::type;

	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Compile-time search algorithm which defines enumerators via user-provided values
	*
	* @tparam	E	Enumeration whos enumerators are to be searched
	* @tparam	Values...	Sequence of valid enumerators
	*/
	template <nstd::Enumeration E, E... Values>
		requires (sizeof...(Values) >= 1)
		      && (is_valid_enumerator_v<Values> && ...)
	using SuppliedValues = nstd::enum_sequence<E,Values...>;


	//! @brief	Name-value pair containing string-representation of one enumerator
	template <nstd::Enumeration E>
	using EnumName = std::pair<std::string_view,E>;
	

	/* @todo	Retrieve enumerator search algorithm from nstd::Settings

	template <nstd::Enumeration E>
	BlindLinearSearchThenPowersOf2<E,0,32> constexpr
	enumerator_values_v {};
	*/

	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Array of name-value pairs representing every valid enumerator for type @c E
	*
	* @tparam	E	Any enumeration type
	* @tparam	Values...	[optional] User-provided valid enumerators
	*/
	template <nstd::Enumeration E, nstd::EnumSequence Values = BlindLinearSearchThenPowersOf2<E,0,32> /*std::remove_cv_t<decltype(enumerator_values_v<E>)>*/ >
	meta::undefined_t constexpr
	enumerator_dictionary_v;

	template <nstd::Enumeration E, E... Values>
	std::array<EnumName<E>,sizeof...(Values)> constexpr
	enumerator_dictionary_v<E, nstd::enum_sequence<E,Values...>> {
		EnumName<E>{enumerator_name_v<Values>, Values}...
	};	
	
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve enumerator string-representation at run-time
	*
	* @param	value	Enumerator of any enumeration type
	* 
	* @returns	Empty string if @p value is invalid, otherwise its string-representation
	*/
	template <nstd::Enumeration E>
	std::string_view constexpr
	enumerator_name(E value) {
		for (auto const& def : enumerator_dictionary_v<E>) {
            if (def.second == value)
                return def.first;
		}

		return {};
	}

	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Query whether a value is a valid enumerator at run-time
	*
	* @param	value	Enumerator of any enumeration type
	*/
	template <nstd::Enumeration E>
	bool constexpr
	is_valid_enumerator(E value) {
		return ranges::any_of(enumerator_dictionary_v<E> | views::values, [=](auto e){ 
			return e == value; 
		});
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::testing
{
	static_assert(enumerator_name(E2::Twenty) == "Twenty");
	static_assert(is_valid_enumerator(E2::Twenty));
	static_assert(!is_valid_enumerator(E2{21}));

	static_assert(enumerator_dictionary_v<N1::E1> == std::array<EnumName<N1::E1>,1>{ 
		EnumName<N1::E1>{"Zero",N1::E1::Zero} 
	});
		
	static_assert(std::same_as<
		SuppliedValues<N1::E1, N1::E1::Zero>,
		nstd::enum_sequence<N1::E1, N1::E1::Zero>
	>);

	static_assert(std::same_as<
		SuppliedValues<E2, E2::Zero>,
		nstd::enum_sequence<E2, E2::Zero>
	>);
	
	static_assert(std::same_as<
		BlindLinearSearch<E2,0,20>,
		nstd::enum_sequence<E2,E2::Zero,E2::One,E2::Two,E2::Six,E2::Twenty>
	>);
	
	static_assert(std::same_as<
		BlindLinearSearchThenPowersOf2<E2,0,21>,
		nstd::enum_sequence<E2,E2::Zero,E2::One,E2::Two,E2::Six,E2::Twenty,
			E2::v2_6,E2::v2_7,E2::v2_8,E2::v2_9,E2::v2_10,E2::v2_28,E2::v2_29,E2::v2_30,E2::v2_31>
	>);

	
	enum class SignedEnum : int32_t { 
		Zero,
		One,
		Two,
		v2_29 = 1u << 29,
		v2_30 = 1u << 30
	};
	static_assert(enumerator_name(SignedEnum::Two) == "Two");
	static_assert(is_valid_enumerator(SignedEnum::Two));
	static_assert(!is_valid_enumerator(SignedEnum{3}));
	
	static_assert(std::same_as<
		BlindLinearSearchThenPowersOf2<SignedEnum,0,3>,
		nstd::enum_sequence<SignedEnum,SignedEnum::Zero,SignedEnum::One,SignedEnum::Two,SignedEnum::v2_29,SignedEnum::v2_30>
	>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o