/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2019, Nick Crowley. All rights reserved.
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
#ifndef utility_VarLengthStruct_h_included
#define utility_VarLengthStruct_h_included

#if defined(__clang__) && (!defined(__cpp_explicit_this_parameter) || (__cpp_explicit_this_parameter < 202110L)) 
#	error Clang doesn't support compiling VarLengthStructure.h yet
#	error VarLengthStructure.h requires explicit 'this' support

#elif !defined(__clang__) && defined(_MSC_VER) && (_MSC_VER < 1932)
#	error VarLengthStructure.h requires explicit 'this' support
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"      //
#include "nstd/experimental/PropagateConst.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Dependency Management o=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail 
{
	//! @brief	Const-propagating wrapper for any field type
	//!
	//! @details	Returns @c std::experimental::propagate_const<T> for pointer-types and @c T& for
	//!				all other types; where @p T has the same cv-qualification as @p value_type
	template <typename ValueType, typename Field>
	using propagate_const_t = std::conditional_t<
		std::is_pointer_v<Field>, 
		nstd::propagate_const<nstd::mirror_cv_t<ValueType, std::remove_pointer_t<Field>>*>,
		std::add_lvalue_reference_t<nstd::mirror_cv_t<ValueType, Field>>
	>;
}

namespace core
{
	//! @brief	Base class for wrappers of variable-length types
	template <typename ValueType>
	class VarLengthStructure
	{
		static_assert(std::is_aggregate_v<ValueType>);
	
		template <typename>
		friend class VarLengthStructure;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Variable-length type being wrapped
		using value_type = ValueType;
	
		//! @brief	Non-const value-type
		using mutable_value_type = std::remove_const_t<value_type>;
	
		//! @brief	Equally CV-qualified std::byte
		using MaybeConstByte = nstd::mirror_cv_t<value_type, std::byte>;

		//! @brief	Const-propagating wrapper mutable field of any type
		template <typename Field>
		using propagate_const_t = detail::propagate_const_t<ValueType,Field>;
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		value_type* m_object;
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	protected:
		implicit
		VarLengthStructure(value_type* instance) 
			: m_object{ThrowIfNull(instance)}
		{}

		implicit
		VarLengthStructure(std::span<std::byte> bytes)
			: m_object{reinterpret_cast<value_type*>(ThrowIfEmpty(bytes).data())}
		{}
	
		// Block construction from const values
		VarLengthStructure(value_type const*) = delete;
		VarLengthStructure(std::span<std::byte const>) = delete;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(VarLengthStructure, 
			NotDefaultConstructible,
			constexpr IsCopyable noexcept,
			constexpr IsMovable noexcept,
			NotEqualityComparable,
			NotSortable
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:	
		//! @brief	Retrieve byte-representation of object
		template <typename Self>
		std::span<MaybeConstByte>
		bytes(this Self&& derived) {
			return { reinterpret_cast<MaybeConstByte*>(derived.m_object), derived.size() };
		}

#if BUGGED
		//! @brief	Implicit conversion to pointer-to-mutable
		template <typename Self, nstd::AnyOf<value_type,void> Output>
		implicit 
		operator nstd::mirror_cv_t<std::remove_reference_t<Self>,Output>*(this Self&& derived) {
			return derived.m_object;
		}
#endif

		implicit 
		operator value_type const*() const {
			return this->m_object;
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		implicit
		operator value_type*() {
			return this->m_object;
		}
	};

	//! @brief	Specialization for const types
	template <typename ValueType>
	class VarLengthStructure<ValueType const>
	{
		static_assert(std::is_aggregate_v<ValueType>);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Variable-length type being wrapped
		using value_type = ValueType const;
	
		//! @brief	Non-const value-type
		using mutable_value_type = ValueType;

		//! @brief	Equally CV-qualified std::byte
		using MaybeConstByte = std::byte const;

		//! @brief	Const-propagating wrapper for const-fields of any type
		template <typename Field>
		using propagate_const_t = detail::propagate_const_t<value_type,Field>;
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		value_type* m_object;
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	protected:
		implicit
		VarLengthStructure(value_type* instance)
			: m_object{ThrowIfNull(instance)}
		{}
	
		implicit
		VarLengthStructure(std::span<std::byte const> bytes)
			: m_object{reinterpret_cast<value_type*>(ThrowIfEmpty(bytes).data())}
		{}
	
		// Block construction from non-const values
		VarLengthStructure(mutable_value_type*) = delete;
		VarLengthStructure(std::span<std::byte>) = delete;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(VarLengthStructure, 
			NotDefaultConstructible,
			constexpr IsCopyable noexcept,
			constexpr IsMovable noexcept,
			NotEqualityComparable,
			NotSortable
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:	
		//! @brief	Retrieve mutable wrapper to the same object
		template <typename Self>
		auto
		as_mutable(this Self&& derived) requires
			requires { typename Self::mutable_type; }
		{
			using MutableSelf = typename std::remove_reference_t<Self>::mutable_type;
			return MutableSelf{ const_cast<mutable_value_type*>(derived.m_object) };
		}

		//! @brief	Retrieve byte-representation of object
		template <typename Self>
		std::span<std::byte const>
		bytes(this Self&& derived) {
			return { reinterpret_cast<std::byte const*>(derived.m_object), derived.size() };
		}

		//! @brief	Implicit conversion to pointer-to-const
		implicit
		operator value_type*() const {
			return this->m_object;
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}      // namespace core
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // utility_VarLengthStruct_h_included
