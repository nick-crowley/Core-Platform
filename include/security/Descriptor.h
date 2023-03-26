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
#ifndef security_Descriptor_h_included
#define security_Descriptor_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
#include "security/Identifier.h"
#include "security/AccessControlList.h"
#include "security/SecurityApi.h" 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security {
	
	//! @brief	Security descriptor binary layout format
	enum class DescriptorFormat {
		Absolute,
		SelfRelative
	};

	namespace detail {
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @internal
		* 
		* @begincode
		*			struct SECURITY_DESCRIPTOR {
		*			   BYTE  Revision;
		*			   BYTE  Sbz1;
		*			   SECURITY_DESCRIPTOR_CONTROL Control;
		*			   PSID Owner;
		*			   PSID Group;
		*			   PACL Sacl;
		*			   PACL Dacl;
		*			}
		* @endcode
		*/

		//#define SE_OWNER_DEFAULTED               (0x0001)
		//#define SE_GROUP_DEFAULTED               (0x0002)
		//#define SE_DACL_PRESENT                  (0x0004)
		//#define SE_DACL_DEFAULTED                (0x0008)
		//#define SE_SACL_PRESENT                  (0x0010)
		//#define SE_SACL_DEFAULTED                (0x0020)
		//#define SE_DACL_AUTO_INHERIT_REQ         (0x0100)
		//#define SE_SACL_AUTO_INHERIT_REQ         (0x0200)
		//#define SE_DACL_AUTO_INHERITED           (0x0400)
		//#define SE_SACL_AUTO_INHERITED           (0x0800)
		//#define SE_DACL_PROTECTED                (0x1000)
		//#define SE_SACL_PROTECTED                (0x2000)
		//#define SE_RM_CONTROL_VALID              (0x4000)
		//#define SE_SELF_RELATIVE                 (0x8000)

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Implementation of a wrapper for a variable-length security descriptor structure
		*/
		template <meta::AnyOf<::SECURITY_DESCRIPTOR,::SECURITY_DESCRIPTOR const> MaybeConstDescriptor>
		class DescriptorWrapper : public VarLengthStructure<MaybeConstDescriptor>
		{
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			//! @brief	Aliases our type
			using type = DescriptorWrapper<MaybeConstDescriptor>;
	
			//! @brief	Aliases base type
			using base = VarLengthStructure<MaybeConstDescriptor>;
	
			//! @brief	Import const-propagating field-wrapper
			template <typename Field> 
			using propagate_const_t = typename base::template propagate_const_t<Field>;
	
		public:
			//! @brief	Non-const wrapper type
			using mutable_type = DescriptorWrapper<::SECURITY_DESCRIPTOR>;

			//! @brief	Aliases a const or mutable access-control-list type
			using MaybeConstAcl = meta::mirror_cv_t<MaybeConstDescriptor,::ACL>;
	
			//! @brief	Equally cv-qualified std::byte
			using MaybeConstByte = meta::mirror_cv_t<MaybeConstDescriptor,std::byte>;

			//! @brief	Aliases a const or mutable security-identifier type
			using MaybeConstSid = meta::mirror_cv_t<MaybeConstDescriptor,::SID>;

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			propagate_const_t<::BYTE>                        Revision;
			propagate_const_t<::SECURITY_DESCRIPTOR_CONTROL> Control;
			propagate_const_t<::SID*>                        Owner;
			propagate_const_t<::SID*>                        Group;
			propagate_const_t<::ACL*>                        Sacl;
			propagate_const_t<::ACL*>                        Dacl;
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] binary representation
			* 
			* @throws	std::invalid_argument	Missing argument
			*/
			explicit
			DescriptorWrapper(std::span<MaybeConstByte> bytes)
			  : DescriptorWrapper{reinterpret_cast<MaybeConstDescriptor*>(bytes.data())}
			{}

			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Construct from [possibly-const] absolute security descriptor
			* 
			* @parm[in]		sd	(const/mutable) Absolute security descriptor to be wrapped
			*
			* @throws	std::invalid_argument	Missing argument
			*/
			explicit
			DescriptorWrapper(MaybeConstDescriptor* sd)
			  : base{ThrowIfNull(sd)},
				Revision{sd->Revision},
				Control{sd->Control},
				Owner{nullptr},
				Group{nullptr},
				Sacl{nullptr},
				Dacl{nullptr}
			{
				// [ABSOLUTE] Components linked by aggregation
				if (this->format() == DescriptorFormat::Absolute) {
					this->Owner = static_cast<MaybeConstSid*>(sd->Owner);
					this->Group = static_cast<MaybeConstSid*>(sd->Group);
					this->Sacl = static_cast<MaybeConstAcl*>(sd->Sacl);
					this->Dacl = static_cast<MaybeConstAcl*>(sd->Dacl);
				}
				// [SELF-RELATIVE] Calculate position of each field using offsets
				else {
					using MaybeConstRelativeDescriptor = meta::mirror_cv_t<MaybeConstDescriptor, ::SECURITY_DESCRIPTOR_RELATIVE>;
					// Reinterpret pointers
					auto* const self = reinterpret_cast<MaybeConstRelativeDescriptor*>(sd);
					auto* const start = reinterpret_cast<MaybeConstByte*>(self); 
					if (self->Owner) 
						this->Owner = reinterpret_cast<MaybeConstSid*>(start + self->Owner);
					if (self->Group) 
						this->Group = reinterpret_cast<MaybeConstSid*>(start + self->Group);
					if (self->Sacl) 
						this->Sacl = reinterpret_cast<MaybeConstAcl*>(start + self->Sacl);
					if (self->Dacl) 
						this->Dacl = reinterpret_cast<MaybeConstAcl*>(start + self->Dacl);
				}
			}
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(DescriptorWrapper,
				NotDefaultConstructible,
				IsCopyable,
				IsMovable,
				NotEqualityComparable,
				NotSortable,
				NotArithmetic
			);
	
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve structure format
			*/
			DescriptorFormat
			format() const {
				return (this->Control & SE_SELF_RELATIVE) ? DescriptorFormat::SelfRelative 
				                                          : DescriptorFormat::Absolute;
			}
	
			/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
			* @brief	Retrieve size of structure, in bytes
			*/
			std::size_t
			size() const
			{
				// [ABSOLUTE] Size is fixed
				if (this->format() == DescriptorFormat::Absolute) {
					return nstd::sizeof_v<::SECURITY_DESCRIPTOR>;
				}
				// [SELF-RELATIVE] Calculate dynamically
				else {
					using acl_wrapper_t = detail::AclWrapper<MaybeConstAcl>;
					using sid_wrapper_t = detail::SidWrapper<MaybeConstSid>;

					//! @todo	Verify alignment of these sub-objects
					auto n = nstd::sizeof_v<::SECURITY_DESCRIPTOR_RELATIVE>;
					if (this->Owner)
						n += sid_wrapper_t{meta::const_pointer_cast<MaybeConstSid*>(this->Owner)}.size();
					if (this->Group)
						n += sid_wrapper_t{meta::const_pointer_cast<MaybeConstSid*>(this->Group)}.size();
					if (this->Dacl)
						n += acl_wrapper_t{meta::const_pointer_cast<MaybeConstAcl*>(this->Dacl)}.size();
					if (this->Sacl)
						n += acl_wrapper_t{meta::const_pointer_cast<MaybeConstAcl*>(this->Sacl)}.size();
					return n;
				}
			}

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};
	} // namespace detail

	//! @brief	Wrapper for mutable security descriptors
	using DescriptorWrapper = detail::DescriptorWrapper<::SECURITY_DESCRIPTOR>;

	//! @brief	Wrapper for const security descriptors
	using ConstDescriptorWrapper = detail::DescriptorWrapper<::SECURITY_DESCRIPTOR const>;

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Security descriptor
	*/
	class Descriptor
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		//! @brief 	Aliases our own type
		using type = Descriptor;

		//! @brief	Provides storage for binary security descriptor data
		using ByteBuffer = std::vector<std::byte>;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		ByteBuffer        storage;       //!< Storage for var-length security descriptor structure
		SharedSecurityApi securityApi;   //!< Security API implementation

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct copy of existing security descriptor
		*
		* @param[in]	sd		Security descriptor
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument	Missing argument
		*/
		explicit
		Descriptor(::SECURITY_DESCRIPTOR const* sd, SharedSecurityApi api = security_api()) 
		  : Descriptor{ConstDescriptorWrapper{sd}.bytes(), api}
		{
		}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct copy of binary representation 
		*
		* @param[in]	bytes	Binary representation of security descriptor
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument	Missing argument
		*/
		explicit
		Descriptor(gsl::span<std::byte const> bytes, SharedSecurityApi api = security_api()) 
		  : storage{ThrowIfEmpty(bytes).begin(),bytes.end()}, 
			securityApi{std::move(ThrowIfEmpty(api))}
		{
		}
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct and take ownership of binary representation
		*
		* @param[in]	bytes	Binary representation of security descriptor
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument	Missing argument
		*/
		explicit
		Descriptor(std::vector<std::byte>&& bytes, SharedSecurityApi api = security_api())
		  : storage{ThrowIfEmpty(std::move(bytes))}, 
			securityApi{std::move(ThrowIfEmpty(api))}
		{}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(Descriptor,
			NotDefaultConstructible,
			IsCopyable,
			IsMovable,
			NotPolymorphic,
			NotEqualityComparable,
			NotSortable,
			NotArithmetic
		);
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Construct from string representation
		*
		* @param[in]    str		Security descriptor string in SDDL (security descriptor definition language)
		* @param[in]	api		[optional] Implementation/mock of high-level security API
		*
		* @throws	std::invalid_argument	Missing argument
		* @throws	std::system_error		Operation failed
		*/
		Descriptor
		static fromString(std::wstring_view str, SharedSecurityApi api = security_api()) {
			return Descriptor{api->descriptorFromString(str), api};
		}
		 
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Retrieve binary representation
		gsl::span<std::byte const>
		bytes() const {
			return this->storage;
		}
	
		//! @brief	Retrieve discretionary access-control-list
		AccessControlList
		dacl() const {
			return AccessControlList{
				ConstAclWrapper{ConstDescriptorWrapper{this->storage}.Dacl}.bytes(),
				this->securityApi
			};
		}

		//! @brief	Retrieve primary group
		Identifier
		group() const {
			return Identifier{
				ConstSidWrapper{ConstDescriptorWrapper{this->storage}.Group}.bytes(),
				this->securityApi
			};
		}

		//! @brief	Retrieve owner
		Identifier
		owner() const {
			return Identifier{
				ConstSidWrapper{ConstDescriptorWrapper{this->storage}.Owner}.bytes(),
				this->securityApi
			};
		}
	
		//! @brief	Retrieve system/auditing access-control-list
		AccessControlList
		sacl() const {
			return AccessControlList{
				ConstAclWrapper{ConstDescriptorWrapper{this->storage}.Sacl}.bytes(),
				this->securityApi
			};
		}

		//! @brief	Generate string representation
		//! 
		//! @throws	std::system_error		Operation failed
		std::wstring
		str() const {
			return this->securityApi->descriptorToString(this->storage);
		}
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};

}      // namespace core::security
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_Descriptor_h_included
