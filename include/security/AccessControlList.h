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
#ifndef security_AccessControlList_h_included
#define security_AccessControlList_h_included

#if defined(__clang__) && (!defined(__cpp_explicit_this_parameter) || (__cpp_explicit_this_parameter < 202110L)) 
#	error Clang doesn't support compiling AccessControlList.h yet
#	error AccessControlList.h requires explicit 'this' support

#elif !defined(__clang__) && defined(_MSC_VER) && (_MSC_VER < 1932)
#	error AccessControlList.h requires explicit 'this' support
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
#include "security/AccessControlListIterator.h"
#include "security/SecurityApi.h"
#include "core/VarLengthStructure.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security 
{
	namespace detail
	{
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @internal
		* 
		* @begincode
		*			struct ACL {
		*				BYTE  AclRevision;
		*				BYTE  Sbz1;
		*				WORD  AclSize;
		*				WORD  AceCount;
		*				WORD  Sbz2;
		*			};
		* @endcode
		*/

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Variable-length wrapper for access control lists
		*/
		template <nstd::AnyOf<::ACL,::ACL const> MaybeConstAcl>
		class AclWrapper : public VarLengthStructure<MaybeConstAcl>
		{
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			//! @brief	Aliases our type
			using type = AclWrapper<MaybeConstAcl>;

			//! @brief	Aliases base type
			using base = VarLengthStructure<MaybeConstAcl>;
	
			//! @brief	Const-propagating field-wrapper
			template <typename Field> 
			using propagate_const_t = typename base::template propagate_const_t<Field>;
	
		public:
			//! @brief	Non-const wrapper type
			using mutable_type = AclWrapper<::ACL>;
			
			//! @brief	Const/non-const access control entry
			using MaybeConstAce = nstd::mirror_cv_t<MaybeConstAcl, ::ACE_HEADER>;
	
			//! @brief	Const/non-const iterator for access control entries
			using MaybeConstAclIterator = AccessControlListIterator<MaybeConstAce>;
	
			//! @brief	Equally CV-qualified std::byte
			using MaybeConstByte = nstd::mirror_cv_t<MaybeConstAce,std::byte>;

		private:
			//! @brief	Const/non-const pair delimiting the entries
			using MaybeConstAcePair = std::pair<MaybeConstAce*,MaybeConstAce*>;
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			propagate_const_t<::BYTE>  AclRevision;     //!< Layout version
			propagate_const_t<::WORD>  AclSize;         //!< Size, in bytes
			propagate_const_t<::WORD>  AceCount;        //!< Length, in elements

		private:
			MaybeConstAcePair          HeadTail;        //!< Begin/end entries	
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] access control list
			* 
			* @parm[in]		list	(const/mutable) ACL to be wrapped
			*
			* @throws	std::invalid_argument	Missing argument
			*/
			explicit
			AclWrapper(MaybeConstAcl* list)
			  : base{ThrowIfNull(list)},
				AclRevision(list->AclRevision),
				AclSize(list->AclSize),
				AceCount(list->AceCount),
				HeadTail(AclWrapper::findHeadAndTail(list))
			{}
	
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] binary representation
			* 
			* @throws	std::invalid_argument		Missing argument
			*/
			explicit
			AclWrapper(std::span<MaybeConstByte> bytes)
				: AclWrapper{reinterpret_cast<MaybeConstAcl*>(bytes.data())}
			{}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(AclWrapper,
				NotDefaultConstructible,
				IsCopyable,
				NotSortable,
				NotArithmetic
			);

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve iterator positioned at first access-control-entry
			*/
			template <typename Self>
			auto
			begin(this Self&& self) {
				if constexpr (std::is_const_v<Self> || std::is_const_v<MaybeConstAcl>)
					return security::ConstAclIterator{self.HeadTail.first};
				else
					return security::AclIterator{self.HeadTail.first};
			}
	
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve iterator positioned after last access-control-entry
			*/
			template <typename Self>
			auto
			end(this Self&& self) {
				if constexpr (std::is_const_v<Self> || std::is_const_v<MaybeConstAcl>)
					return security::ConstAclIterator{self.HeadTail.second};
				else
					return security::AclIterator{self.HeadTail.second};
			}

		private:
			//! @brief	Calculate positions of list head and tail
			MaybeConstAcePair
			static findHeadAndTail(MaybeConstAcl* list) {
				// First ACE is located immediately following the ACL
				auto* const begin = reinterpret_cast<MaybeConstAce*>(ThrowIfNull(list)+1);
				
				// Find position immediately beyond final ACE
				auto* end = begin;
				for (unsigned idx = 0; idx < list->AceCount; ++idx) {
					end = MaybeConstAclIterator::next(end);
				}
				return {begin, end};
			}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve size of structure, in bytes
			*/
			std::size_t
			size() const
			{
				return this->AclSize;
			}
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		
		};
	}
	
	//! @brief	Wrapper for mutable access control lists
	using AclWrapper = detail::AclWrapper<::ACL>;

	//! @brief	Wrapper for const access control lists
	using ConstAclWrapper = detail::AclWrapper<::ACL const>;

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Provides list operations upon elements of an access control list
	*/
	class AccessControlList
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Types & Constants o=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		//! @brief 	Our type
		using type = AccessControlList;

		//! @brief	Provides storage for binary access control list data
		using ByteBuffer = std::vector<std::byte>;

	public:
		using iterator = AclIterator;
		using const_iterator = ConstAclIterator;
		using value_type = std::iter_value_t<iterator>;
		using reference = std::iter_reference_t<iterator>;
		using const_reference = std::iter_reference_t<const_iterator>;
		using size_type = size_t;
		using difference_type = std::iter_difference_t<iterator>;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		ByteBuffer        listStorage;      //!< Storage for var-length access control list structure
		SharedSecurityApi securityApi;      //!< Security API implementation

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct by copying binary representation
		*
		* @param[in]	bytes	Binary representation of access control list
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		AccessControlList(gsl::span<std::byte const> bytes, SharedSecurityApi api = security_api())
		  : listStorage{ThrowIfEmpty(bytes).begin(), bytes.end()}, 
			securityApi{std::move(ThrowIfEmpty(api))}
		{}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct and take ownership of binary representation
		*
		* @param[in]	bytes	Binary representation of access control list
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument		Missing argument
		*/
		explicit
		AccessControlList(std::vector<std::byte>&& bytes, SharedSecurityApi api = security_api())
		  : listStorage{std::move(ThrowIfEmpty(bytes))}, 
			securityApi{std::move(ThrowIfEmpty(api))}
		{}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(AccessControlList,
			NotDefaultConstructible,
			IsCopyable,
			IsMovable,
			NotSortable,
			NotEqualityComparable,
			NotArithmetic
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Retrieve iterator positioned at first access-control-entry
		*/
		template <typename Self>
		auto
		begin(this Self&& self) {
			if constexpr (std::is_const_v<std::remove_reference_t<Self>>)
				return ConstAclWrapper{self.listStorage}.begin();
			else
				return AclWrapper{self.listStorage}.begin();
		}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Retrieve iterator positioned beyond last access-control-entry
		*/
		template <typename Self>
		auto
		end(this Self&& self) {
			if constexpr (std::is_const_v<std::remove_reference_t<Self>>)
				return ConstAclWrapper{self.listStorage}.end();
			else
				return AclWrapper{self.listStorage}.end();
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Retrieve binary representation
		gsl::span<std::byte const>
		bytes() const {
			return this->listStorage;
		}
		
#if REQUIRES_EQUALITY_COMPARABLE_ELEMENTS
		bool
		contains(const_reference value) const
		{	
			static_assert(std::equality_comparable<value_type>);
			auto const npos = this->end();
			return std::find(this->begin(), npos, value) != npos;
		}
#endif

		bool
		empty() const {
			return this->size() == 0;
		}
	
		//! @brief	Retrieve number of entries
		size_type
		size() const {
			return ConstAclWrapper{this->listStorage}.AceCount;
		}

		size_type
		max_size() const {
			return std::numeric_limits<::WORD>::max();
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		clear() {
			AclWrapper{this->listStorage}.AceCount = 0;
		}
	};

}      // namespace core::security
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_AccessControlList_h_included
