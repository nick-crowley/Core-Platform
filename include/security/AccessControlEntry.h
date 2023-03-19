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
#ifndef security_AceControlEntry_h_included
#define security_AceControlEntry_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security 
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @internal
	* @begincode
	*	struct ACL {
	*		BYTE  AclRevision;
	*		BYTE  Sbz1;
	*		WORD   AclSize;
	*		WORD   AceCount;
	*		WORD   Sbz2;
	*	};
	*	
	*	struct ACE_HEADER {
	*		BYTE  AceType;
	*		BYTE  AceFlags;
	*		WORD   AceSize;
	*	};
	* @endcode
	*/

	enum class AceType 
	{
		AccessAllowed                = ACCESS_ALLOWED_ACE_TYPE,                 //!< 0x0
		AccessDenied                 = ACCESS_DENIED_ACE_TYPE,                  //!< 0x1
		SystemAudit                  = SYSTEM_AUDIT_ACE_TYPE,                   //!< 0x2
		SystemAlarm                  = SYSTEM_ALARM_ACE_TYPE,                   //!< 0x3

		AccessAllowedCompound        = ACCESS_ALLOWED_COMPOUND_ACE_TYPE,        //!< 0x4

		AccessAllowedObject          = ACCESS_ALLOWED_OBJECT_ACE_TYPE,          //!< 0x5
		AccessDeniedObject           = ACCESS_DENIED_OBJECT_ACE_TYPE,           //!< 0x6
		SystemAuditObject            = SYSTEM_AUDIT_OBJECT_ACE_TYPE,            //!< 0x7
		SystemAlarmObject            = SYSTEM_ALARM_OBJECT_ACE_TYPE,            //!< 0x8

		AccessAllowedCallback        = ACCESS_ALLOWED_CALLBACK_ACE_TYPE,        //!< 0x9
		AccessDeniedCallback         = ACCESS_DENIED_CALLBACK_ACE_TYPE,         //!< 0xA
		AccessAllowedCallbackObject  = ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE, //!< 0xB
		AccessDeniedCallbackObject   = ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE,  //!< 0xC
		SystemAuditCallback          = SYSTEM_AUDIT_CALLBACK_ACE_TYPE,          //!< 0xD
		SystemAlarmCallback          = SYSTEM_ALARM_CALLBACK_ACE_TYPE,          //!< 0xE
		SystemAuditCallbackObject    = SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE,   //!< 0xF
		SystemAlarmCallbackObject    = SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE,   //!< 0x10

		SystemMandatoryLabel         = SYSTEM_MANDATORY_LABEL_ACE_TYPE,         //!< 0x11
		SystemResourceAttribute      = SYSTEM_RESOURCE_ATTRIBUTE_ACE_TYPE,      //!< 0x12
		SystemScopedPolicyId         = SYSTEM_SCOPED_POLICY_ID_ACE_TYPE,        //!< 0x13
		SystemProcessTrustLabel      = SYSTEM_PROCESS_TRUST_LABEL_ACE_TYPE,     //!< 0x14
		SystemAccessFilter           = SYSTEM_ACCESS_FILTER_ACE_TYPE,           //!< 0x15
	};

	union AccessControlEntry {
		::ACE_HEADER         Header;
		::ACCESS_ALLOWED_ACE Allow;
		::ACCESS_DENIED_ACE  Deny;
		::SYSTEM_AUDIT_ACE   Audit;
		::SYSTEM_ALARM_ACE   Alarm;
	};

	namespace detail
	{
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Variable-length wrapper for access control entries
		*/
		template <meta::AnyOf<::ACE_HEADER,::ACE_HEADER const> MaybeConstAce>
		class AceWrapper : public VarLengthStructure<MaybeConstAce>
		{
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			//! @brief	Aliases our type
			using type = AceWrapper<MaybeConstAce>;

			//! @brief	Aliases base type
			using base = VarLengthStructure<MaybeConstAce>;

			//! @brief	Const-propagating field-wrapper
			template <typename Field> 
			using propagate_const_t = typename base::template propagate_const_t<Field>;

		public:
			//! @brief	Non-const wrapper type
			using mutable_type = AceWrapper<::ACE_HEADER>;

			//! @brief	Equally CV-qualified std::byte
			using MaybeConstByte = meta::mirror_cv_t<MaybeConstAce,std::byte>;

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			propagate_const_t<::BYTE>  AceType;          //!< Entry type
			propagate_const_t<::BYTE>  AceFlags;         //!< 
			propagate_const_t<::WORD>  AceSize;          //!< Size, in bytes

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] access control entry
			* 
			* @parm[in]		entry	(const/mutable) ACE to be wrapped
			*
			* @throws	std::invalid_argument	Missing argument
			*/
			explicit
			AceWrapper(MaybeConstAce* entry)
			  : base{ThrowIfNull(entry)},
				AceType(entry->AceType),
				AceFlags(entry->AceFlags),
				AceSize(entry->AceSize)
			{}

			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] binary representation
			* 
			* @throws	std::invalid_argument		Missing argument
			*/
			explicit
			AceWrapper(std::span<MaybeConstByte> bytes)
				: AceWrapper{reinterpret_cast<MaybeConstAce*>(bytes.data())}
			{}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(AceWrapper,
				NotDefaultConstructible,
				IsCopyable,
				NotEqualityComparable,
				NotSortable,
				NotArithmetic
			);

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			security::AceType
			kind() const {
				return static_cast<security::AceType>(this->AceType);
			}

			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve size of structure, in bytes
			*/
			std::size_t
			size() const
			{
				return this->AceSize;
			}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		
		};
	}
	
	//! @brief	Wrapper for mutable access control entries
	using AceWrapper = detail::AceWrapper<::ACE_HEADER>;

	//! @brief	Wrapper for const access control entries
	using ConstAceWrapper = detail::AceWrapper<::ACE_HEADER const>;
	
} // namespace core::security 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_AceControlEntry_h_included
