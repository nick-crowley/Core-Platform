/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2020, Nick Crowley. All rights reserved.
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
#ifndef security_AccessControlListIterator_h_included
#define security_AccessControlListIterator_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
#include "security/AccessControlEntry.h"

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security 
{
	namespace detail 
	{
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Navigates over the entries of an access control list
		*
		* @tparam	MaybeConstAce	Optionally const-qualified access-control-entry
		*/
		template <nstd::AnyOf<::ACE_HEADER,::ACE_HEADER const> MaybeConstAce>
		class AccessControlListIterator : public boost::iterator_facade<AccessControlListIterator<MaybeConstAce>, MaybeConstAce, boost::forward_traversal_tag>
		{
			//! @brief	Enable boost::iterator_facade to operate by granting friendship to it's core logic
			friend class boost::iterator_core_access;

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			//! @brief	Aliases base type
			using base = boost::iterator_facade<AccessControlListIterator<MaybeConstAce>, MaybeConstAce, boost::forward_traversal_tag>;

			//! @brief	Aliases our type
			using type = AccessControlListIterator<MaybeConstAce>;
	
			//! @brief	Equally cv-qualified std::byte
			using MaybeConstByte = nstd::mirror_cv_t<MaybeConstAce,std::byte>;

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			MaybeConstAce*	Position;
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from (possibly-const) access control entry
			* 
			* @parm[in] pos   (const/mutable) Access control entry
			*
			* @throws	std::invalid_argument	Missing argument
			*/
			explicit
			AccessControlListIterator(MaybeConstAce* pos) : Position(ThrowIfNull(pos))
			{}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(AccessControlListIterator,
				NotDefaultConstructible,
				IsCopyable
			);

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Calculate position of successor entry in a list
			* 
			* @parm[in] pos   Position of list element
			*
			* @throws	std::invalid_argument	Missing argument
			*/
			nstd::return_t<MaybeConstAce*>
			static next(MaybeConstAce* ace) {
				return reinterpret_cast<MaybeConstAce*>(
					reinterpret_cast<MaybeConstByte*>(ace) + ThrowIfNull(ace)->AceSize
				);
			}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve the value associated with this position
			*/
			MaybeConstAce&
			dereference() const {
				return *this->Position;
			}

			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Query whether iterator occupies the same position
			*
			* @return	True iff iterators are positioned at the same entry
			*/
			bool
			equal(const type& r) const noexcept {
				return this->Position == r.Position;
			}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Advance to the next position
			*/
			void
			increment() {
				this->Position = AccessControlListIterator::next(this->Position);
			}
		};
	}

	//! @brief	Non-const iterator for ACL entries
	using AclIterator = detail::AccessControlListIterator<::ACE_HEADER>;

	//! @brief	Const iterator for ACL entries
	using ConstAclIterator = detail::AccessControlListIterator<::ACE_HEADER const>;

} // namespace core::security 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace std {

	//! @brief	Define traits of ACL iterators
	template <> 
	struct iterator_traits<core::security::AclIterator>
		: nstd::make_iterator_traits_t<::ACE_HEADER, std::forward_iterator_tag> 
	{};

	//! @brief	Define traits of ACL const-iterators
	template <> 
	struct iterator_traits<core::security::ConstAclIterator>
		: nstd::make_iterator_traits_t<::ACE_HEADER const, std::forward_iterator_tag> 
	{};

}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_AccessControlListIterator_h_included
