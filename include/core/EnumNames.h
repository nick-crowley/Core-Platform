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
#pragma push_macro("nameof")
#undef nameof
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
		template <nstd::Enumeration E>
		auto constexpr
		nameof() noexcept 
		{
			//__FUNCSIG__: auto __cdecl nameof<enum E1>(void) noexcept
			//           : auto __cdecl nameof<enum N1::E1>(void) noexcept
			std::string_view constexpr ParamList{
				__FUNCSIG__+sizeof("auto __cdecl core::detail::nameof<enum ")-1,
				__FUNCSIG__+(sizeof(__FUNCSIG__)-1)-(sizeof(">(void) noexcept")-1)
			};
			return ParamList;
		}
	}

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve name of any enumeration type
	*/
	template <nstd::Enumeration E>
	std::string_view constexpr
	enumeration_name_v = detail::nameof<E>();


	namespace detail
	{
		template <nstd::Enumeration E, E Enumerator>
		auto constexpr
		__cdecl nameof() noexcept 
		{
			//__FUNCSIG__: auto __cdecl core::detail::nameof<enum E1,E1::None>(void) noexcept
			//             auto __cdecl core::detail::nameof<enum N1::E1,N1::E1::None>(void) noexcept
			//             auto __cdecl core::detail::nameof<enum N1::E1,(enum N1::E1)0x16>(void) noexcept
			
			std::string_view constexpr ParamList{
				__FUNCSIG__+sizeof("auto __cdecl core::detail::nameof<enum ")-1,
				__FUNCSIG__+(sizeof(__FUNCSIG__)-1)-(sizeof(">(void) noexcept")-1)
			};

			//ParamList: E1,E1::None
			//           N1::E1,N1::E1::None
			//           N1::E1,(enum N1::E1)0x16
			std::string_view name = ParamList;
			name.remove_prefix(name.find(',')+1);	// BUG: What happens if E1 is within a template T1 with >1 arguments?
			if (name.starts_with('('))
				return std::string_view{};

			name.remove_prefix(name.find_last_of("::")+1);
			return name;
		}
	}

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve string-representation of any enumerator value
	*
	* @returns	Non-empty string if enumerator is valid, otherwise empty string
	*/
	template <nstd::Enumeration E, E Enumerator>
	std::string_view constexpr
	enumerator_name_v = detail::nameof<E, Enumerator>();
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Query whether a value represents a valid enumerator of enumeration @c E
	*/
	template <nstd::Enumeration E, auto Enumerator>
	bool constexpr
	is_valid_enumerator_v = enumerator_name_v<E, static_cast<E>(Enumerator)>.size() != 0;


	namespace detail 
	{
		template <nstd::Enumeration E, nstd::EnumSequenceOf<E> Sequence, auto Value>
		using push_back_if_valid_t = std::conditional_t<is_valid_enumerator_v<E,Value>, 
		                                                nstd::sequence_push_back_t<Sequence,static_cast<E>(Value)>, 
		                                                Sequence>;

		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
			requires (Start <= Finish)
		metafunc linear_search_impl : std::conditional_t<
			Start == Finish,
			std::type_identity<push_back_if_valid_t<E, Result, Finish>>,
			linear_search_impl<E, (Start+1 <= Finish ? Start+1 : Finish), Finish, push_back_if_valid_t<E,Result,Start>>
		> 
		{};
		
		template <nstd::Enumeration         E,
		          std::underlying_type_t<E> Start,
		          std::underlying_type_t<E> Finish,
		          nstd::EnumSequenceOf<E>   Result = nstd::enum_sequence<E>>
			requires std::unsigned_integral<std::underlying_type_t<E>> 
			      && (Start <= Finish)
			      && (nstd::is_pow2(Start))
			      && (nstd::is_pow2(Finish))
		metafunc geometric_search_impl : std::conditional_t<
			Start == Finish,
			std::type_identity<push_back_if_valid_t<E, Result, Finish>>,
			geometric_search_impl<E, (Start<<1 != Finish && Start<<1 != 0 ? Start<<1 : Finish), Finish, push_back_if_valid_t<E,Result,Start>>
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

	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Compile-time search algorithm which extends blind linear search with a scan of remaining power-of-2 values
	*
	* @tparam	E	Enumeration whos enumerators are to be searched
	* @tparam	Start	Inclusive minimum of search range for initial blind linear search
	* @tparam	Finish	Inclusive maximum of search range for initial blind linear search
	*/
	template <nstd::Enumeration E, std::underlying_type_t<E> Start, std::underlying_type_t<E> Finish>
		requires (Start < Finish) 
		      && std::unsigned_integral<std::underlying_type_t<E>>
		      && (nstd::is_pow2(Finish))
	using BlindLinearSearchThenPowersOf2 = typename detail::geometric_search_impl<
		E,
		Finish,
		~std::numeric_limits<std::make_signed_t<std::underlying_type_t<E>>>::max(),
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
		      && (is_valid_enumerator_v<E,Values> && ...)
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
		EnumName<E>{enumerator_name_v<E,Values>, Values}...
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
	namespace N1 {
		enum class E1 : unsigned {Zero};
	}

	enum class E2 : uint32_t { 
		Zero,
		One,
		Two,
		Six = 6,
		Twenty = 20,
		v2_6  = 1u << 6,
		v2_7  = 1u << 7,
		v2_8  = 1u << 8,
		v2_9  = 1u << 9,
		v2_10 = 1u << 10,
		v2_28 = 1u << 28,
		v2_29 = 1u << 29,
		v2_30 = 1u << 30,
		v2_31 = 1u << 31
	};

	static_assert(enumeration_name_v<E2> == "core::testing::E2");
	static_assert(enumerator_name_v<E2, E2::Twenty> == "Twenty");
	static_assert(enumerator_name(E2::Twenty) == "Twenty");
	static_assert(!is_valid_enumerator_v<E2,5>);
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
		BlindLinearSearchThenPowersOf2<E2,0,32>,
		nstd::enum_sequence<E2,E2::Zero,E2::One,E2::Two,E2::Six,E2::Twenty,
			E2::v2_6,E2::v2_7,E2::v2_8,E2::v2_9,E2::v2_10,E2::v2_28,E2::v2_29,E2::v2_30,E2::v2_31>
	>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma pop_macro("nameof")