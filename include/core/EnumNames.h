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
		// Appends a sequence with a value iff its a valid enumerator; otherwise no-op
		template <nstd::EnumSequence Sequence, auto Value, auto _E = static_cast<nstd::sequence_element_t<Sequence>>(Value)>
		using push_back_if_valid_enum_t = std::conditional_t<
			is_valid_enumerator_v<_E>, 
		    nstd::sequence_push_back_t<Sequence,_E>, 
		    Sequence
		>;

		// Blind search (through a contiguous range) for valid enumerators
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
			requires (Start <= Finish)
		metafunc LinearSearch 
		  : std::conditional_t<
				Start == Finish,
				std::type_identity<push_back_if_valid_enum_t<Result,Finish>>,
				LinearSearch<E, (Start+1 <= Finish ? Start+1 : Finish), Finish, push_back_if_valid_enum_t<Result,Start>>
			> 
		{};

		// Type accessor
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
		using LinearSearch_t = typename LinearSearch<E,Start,Finish,Result>::type;
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
	using BlindLinearSearch = detail::LinearSearch_t<E,Start,Finish>;
	

	namespace detail 
	{
		// Common implementation
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
		metafunc GeometricSearchImpl
			: std::conditional_t<
				Start == Finish,
				std::type_identity<push_back_if_valid_enum_t<Result,Finish>>,
				GeometricSearchImpl<E, (Start<<1 != Finish && Start<<1 != 0 ? Start<<1 : Finish), Finish, push_back_if_valid_enum_t<Result,Start>>
			> 
		{};

		// Blind search through powers-of-2 (within a given range) for valid enumerators
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
		metafunc GeometricSearch;

		// Specialization for unsigned underlying types
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result>
			requires std::unsigned_integral<std::underlying_type_t<E>> 
			      && (Start <= Finish)
			      && (nstd::is_pow2(Start))
			      && (nstd::is_pow2(Finish))
		metafunc GeometricSearch<E,Start,Finish,Result> : GeometricSearchImpl<E,Start,Finish,Result>
		{};

		// Specialization for signed underlying types
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result>
			requires std::signed_integral<std::underlying_type_t<E>> 
			      && (Start <= Finish && Start > 0 && Finish > 0)
			      && (nstd::is_pow2(Start))
			      && (nstd::is_pow2(Finish))
			      && (Finish != std::numeric_limits<std::underlying_type_t<E>>::min())
		metafunc GeometricSearch<E,Start,Finish,Result> : GeometricSearchImpl<E,Start,Finish,Result>
		{};

		// Type accessor
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
		using GeometricSearch_t = typename GeometricSearch<E,Start,Finish,Result>::type;

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
	using BlindLinearSearchThenPowersOf2 = detail::GeometricSearch_t<
		E,
		std::bit_ceil<std::make_unsigned_t<std::underlying_type_t<E>>>(Finish),
		nstd::max_pow2<std::underlying_type_t<E>>::value,
		detail::LinearSearch_t<E,Start,Finish>
	>;

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Sequence of user-provided enumerators
	*
	* @tparam	Values...	Sequence of valid enumerators (of the same type)
	*/
	template <auto... Values>
		requires nstd::NonEmptyPack<Values...>
		      && nstd::HomogenousValues<Values...>
		      && ValidEnumerators<Values...>
	using SuppliedValues = nstd::enum_sequence<nstd::sequence_element_t<nstd::value_tuple<Values...>>, Values...>;


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
	* @tparam	...	[optional] User-provided valid enumerators
	*/
	template <nstd::Enumeration E, nstd::EnumSequence = BlindLinearSearchThenPowersOf2<E,0,32> /*std::remove_cv_t<decltype(enumerator_values_v<E>)>*/ >
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
		return ranges::any_of(enumerator_dictionary_v<E> | views::values, lambda(=, e, e == value));
	}

	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief  Identifies any enumerator from its string-representation
	*
	* @param  name   String-representation of any enumerator
	* 
	* @returns  Matching enumerator, if any, otherwise @c std::nullopt
	*/
	template <nstd::Enumeration E>
	std::optional<E> constexpr
	from_string(std::nothrow_t, std::string_view name) {
		for (auto const [n, v] : enumerator_dictionary_v<E>) 
            if (name == n)
                return v;

		return {};
	}
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief  Identifies any enumerator from its string-representation
	*
	* @param  name   String-representation of any enumerator
	* 
	* @throws  std::invalid_argument  
	*/
	template <nstd::Enumeration E>
	E 
	from_string(std::string_view name) {
		if (auto const e = core::from_string<E>(std::nothrow, name); e.has_value())
			return *e;

		ThrowInvalidArg(name, "{} is not a valid {} enumerator", name, enumeration_name_v<E>);
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::testing
{
	//! @test	Verify @c core::enumerator_name() correctly stringifies enumerators (of enumerations who underlying type is unsigned)
	static_assert(enumerator_name(E2::Twenty) == "Twenty");

	//! @test	Verify @c core::is_valid_enumerator() correctly identifies valid enumerators (of enumerations who underlying type is unsigned)
	static_assert(is_valid_enumerator(E2::Twenty));

	//! @test	Verify @c core::is_valid_enumerator() correctly identifies invalid enumerators (of enumerations who underlying type is unsigned)
	static_assert(!is_valid_enumerator(E2{21}));

	//! @Test	Verify @c core::from_string() correctly identifies enumerators from string-representation
	static_assert(from_string<E2>(std::nothrow, "Twenty") == E2::Twenty);
	
	//! @Test	Verify @c core::from_string() correctly rejects unrecognised string-representation
	static_assert(from_string<E2>(std::nothrow, "Sixty") == nullopt);

	//! @test	Verify @c core::enumerator_dictionary_v returns @c std::array containing all enumerators
	static_assert(enumerator_dictionary_v<N1::E1> == std::array<EnumName<N1::E1>,1>{ 
		EnumName<N1::E1>{"Zero",N1::E1::Zero} 
	});
		
	//! @test	Verify @c core::SuppliedValues produces correct @c nstd::enum_sequence when enumeration is nested type
	static_assert(std::same_as<
		SuppliedValues<N1::E1::Zero>,
		nstd::enum_sequence<N1::E1, N1::E1::Zero>
	>);

	//! @test	Verify @c core::SuppliedValues produces correct @c nstd::enum_sequence when enumeration isn't a nested type
	static_assert(std::same_as<
		SuppliedValues<E2::Zero>,
		nstd::enum_sequence<E2, E2::Zero>
	>);
	
	//! @test	Verify @c core::BlindLinearSearch correctly finds all enumerators between zero and twenty
	static_assert(std::same_as<
		BlindLinearSearch<E2,0,20>,
		nstd::enum_sequence<E2,E2::Zero,E2::One,E2::Two,E2::Six,E2::Twenty>
	>);
	
	//! @test	Verify @c core::BlindLinearSearchThenPowersOf2 correctly finds all remaining enumerators not found by earlier test
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

	//! @test	Verify @c core::enumerator_name() correctly stringifies enumerators (of enumerations who underlying type is signed)
	static_assert(enumerator_name(SignedEnum::Two) == "Two");

	//! @test	Verify @c core::is_valid_enumerator() correctly identifies valid enumerators (of enumerations who underlying type is signed)
	static_assert(is_valid_enumerator(SignedEnum::Two));

	//! @test	Verify @c core::is_valid_enumerator() correctly identifies invalid enumerators (of enumerations who underlying type is signed)
	static_assert(!is_valid_enumerator(SignedEnum{3}));
	
	//! @test	Verify @c core::BlindLinearSearchThenPowersOf2 operates correctly on enumerations whose underlying type is signed
	static_assert(std::same_as<
		BlindLinearSearchThenPowersOf2<SignedEnum,0,3>,
		nstd::enum_sequence<SignedEnum,SignedEnum::Zero,SignedEnum::One,SignedEnum::Two,SignedEnum::v2_29,SignedEnum::v2_30>
	>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o