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
#	error Clang doesn't support compiling Reflection.h yet
#endif
#pragma push_macro("nameof")
#undef nameof
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

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
			using namespace std::string_view_literals;
			//__FUNCSIG__: auto __cdecl nameof<enum E1>(void) noexcept
			//           : auto __cdecl nameof<enum N1::E1>(void) noexcept
			std::string_view constexpr ParamList{
				__FUNCSIG__ + "auto __cdecl core::detail::nameof<enum "sv.length(),
				__FUNCSIG__ + std::string_view{__FUNCSIG__}.length() - ">(void) noexcept"sv.length()
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
			using namespace std::string_view_literals;
			//__FUNCSIG__: auto __cdecl core::detail::nameof<enum E1,E1::None>(void) noexcept
			//             auto __cdecl core::detail::nameof<enum N1::E1,N1::E1::None>(void) noexcept
			//             auto __cdecl core::detail::nameof<enum N1::E1,(enum N1::E1)0x16>(void) noexcept
			
			std::string_view constexpr ParamList{
				__FUNCSIG__ + "auto __cdecl core::detail::nameof<enum "sv.length(),
				__FUNCSIG__ + std::string_view{__FUNCSIG__}.length() - ">(void) noexcept"sv.length()
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
	static_assert(!is_valid_enumerator_v<E2,5>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma pop_macro("nameof")