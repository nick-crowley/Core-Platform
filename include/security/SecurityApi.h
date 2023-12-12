/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2018, Nick Crowley. All rights reserved.
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
#ifndef interface_SecurityApi_h_included
#define interface_SecurityApi_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "win/SharedHandle.h"
#include "security/TokenProperty.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security 
{
	struct Account {
		std::wstring            Domain;
		std::wstring            Name;
		std::vector<std::byte>  Sid;
	};

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Implements the high-level Security API
	* 
	* @details	This class wraps the production API and takes responsibility for performing boilerplate
	*			tasks such as argument verification, buffer allocation, and converting error-codes into 
	*           exceptions, for example.
	*/
	class PlatformExport SecurityApi 
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	private:
		//using HandleOrPath = std::variant<filesystem::FilePath, filesystem::FileHandle, registry::RegistryHandle>;
		using ConstByteSpan = std::span<std::byte const>;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		satisfies(SecurityApi, 
			IsDefaultConstructible,
			IsCopyable, 
			IsMovable
		);

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	public:
		[[nodiscard]]
		bool
		checkMembership(win::SharedToken token, std::span<std::byte const> sid) const;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Compares (all sub-authorities) of two security identifiers for equality
		*
		* @param[in]	lhs		Binary representation of one SID
		* @param[in]	rhs		Binary representation of another SID
		*
		* @returns		True iff all sub-authorities compare equal; false otherwise
		*
		* @throws		std::invalid_argument	Missing argument
		*/
		[[nodiscard]]
		bool
		compareSid(std::span<std::byte const> lhs, std::span<std::byte const> rhs) const;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Compares all but final sub-authority of two security identifiers for equality
		*
		* @param[in]	lhs		Binary representation of one SID
		* @param[in]	rhs		Binary representation of another SID
		*
		* @returns		True iff all but final sub-authorities compare equal; false otherwise
		*
		* @remarks		Enables a server application in one domain to verify an attempt by a user to 
		*				log on to another domain
		*
		* @throws		std::invalid_argument	Missing argument
		*/
		[[nodiscard]]
		bool
		compareSidPrefix(std::span<std::byte const> lhs, std::span<std::byte const> rhs) const;
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Converts a security descriptor into security descriptor definition language formatted string
		*
		* @param[in]	descriptor		Binary representation of SID to be converted
		*
		* @returns		Resultant string in SDDL format (O: G: D: S:)
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		[[nodiscard]]
		std::wstring
		descriptorToString(std::span<std::byte const> descriptor) const;
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Converts a string-format security descriptor into a valid, functional descriptor
		*
		* @param[in]	descriptor		String in security descriptor definition language (SDDL) (eg. O: G: D: S:)
		*
		* @returns		Binary representation of security descriptor
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		[[nodiscard]]
		std::vector<std::byte>
		descriptorFromString(std::wstring_view descriptor) const;
#if 0	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Implements ISecurityApi::get_access_rights()
		*
		* @see		core::security::ISecurityApi::get_access_rights()
		*/
		AccessRight
		get_access_rights(registry::RegistryHandle handle) const;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Implements ISecurityApi::get_file_security()
		*/
		[[nodiscard]]
		std::vector<std::byte>
		get_file_security(filesystem::FileHandle handle, Information components) const;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Implements ISecurityApi::get_key_security()
		*/
		[[nodiscard]]
		std::vector<std::byte>
		get_key_security(registry::RegistryHandle handle, Information components) const;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Implements ISecurityApi::get_path_security()
		*/
		[[nodiscard]]
		std::vector<std::byte>
		get_path_security(filesystem::FilePath file, Information components) const;
#endif
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Retrieves an account from its account name
		*
		* @param[in]	account		Account name
		* @param[in]	system		[optional] Hostname of system upon which search should begin
		*
		* @returns		[optional] Account, if exists
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		std::optional<Account>
		lookupAccount(std::wstring_view                account,
		              std::optional<std::wstring_view> system) const;
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Retrieves an account from its security identifier
		*
		* @param[in]	account		Account security identifier
		* @param[in]	system		[optional] Hostname of system upon which search should begin
		*
		* @returns		[optional] Account, if exists
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		std::optional<Account>
		lookupAccount(ConstByteSpan                    account,
		              std::optional<std::wstring_view> system) const;
#if 0	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Implements ISecurityApi::make_descriptor()
		*/
		[[nodiscard]]
		std::vector<std::byte>
		make_descriptor() const;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Implements ISecurityApi::set_key_security()
		*/
		[[nodiscard]]
		void 
		set_key_security(registry::RegistryHandle key, std::span<std::byte const> bytes, Information components) const;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Implements ISecurityApi::set_path_security()
		*/
		[[nodiscard]]
		void 
		set_path_security(filesystem::FilePath path, std::span<std::byte const> bytes, Information components) const;
#endif	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Converts a security identifier into a hexadecimal string format
		*
		* @param[in]	sid		Binary representation of SID to be converted
		*
		* @returns		Resultant string is in the standard S-R-I-S-S… format.
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		[[nodiscard]]
		std::wstring
		sidToString(std::span<std::byte const> sid) const;
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Converts a string-format security identifier into a valid, functional SID
		*
		* @param[in]	sid		String in the standard S-R-I-S-S… format
		*
		* @returns		Binary representation of SID
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		[[nodiscard]]
		std::vector<std::byte>
		stringToSid(std::wstring_view sid) const;
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Retrieve a property of an access token
		*
		* @param[in]	token	Handle to an access token
		* @param[in]	info	Token property
		*
		* @returns		Byte-representation of property-specific data-structure
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		[[nodiscard]]
		std::unique_ptr<std::byte[]>
		tokenInformation(win::SharedToken token, TokenProperty info) const;
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief		Modify a property of an access token
		*
		* @param[in]	token	Handle to an access token
		* @param[in]	info	Token property
		* @param[in]	data	New value
		*
		* @throws		std::invalid_argument	Missing argument
		* @throws		std::system_error		Operation failed
		*/
		void
		tokenInformation(win::SharedToken token, TokenProperty info, std::span<std::byte const> value) const;

#if 0
	private:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief	Retrieve security descriptor
		*/
		std::vector<std::byte>
		_get_descriptor(HandleOrPath ident, ::SE_OBJECT_TYPE type, Information components) const;
#endif
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
	};

	//! @brief	High-level security API pointer
	using SharedSecurityApi = std::shared_ptr<SecurityApi>;

}	// namespace core::security
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security 
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve implementation of high-level security API
	*
	* @return	Non-null instance (possibly mocked)
	*
	* @related	core::security::ISecurityApi
	*/
	SharedSecurityApi
	PlatformExport security_api();
}   // namespace core::security
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // interface_SecurityApi_h_included
