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
#ifndef security_StandardRight_h_included
#define security_StandardRight_h_included

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"      //
#include "security/AccessRight.h"

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win 
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Common access rights for securable objects
	*/
	enum class CommonRight : access_mask_t {
		Delete = DELETE,						//!< Delete the object
		Synchronize = SYNCHRONIZE,				//!< Wait upon the oject
		ReadDac = READ_CONTROL,					//!< Read the discretionary ACL
		WriteDac = WRITE_DAC,					//!< Modify the discretionary ACL
		WriteOwner = WRITE_OWNER,				//!< Change object's owner
	};

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Generic access-rights for securable objects
	*
	* @details	Defines generic access-rights which each type of securable object maps to a combination
	*			of standard- and object-specific access-rights
	*/
	enum class GenericRight : access_mask_t {
		All = GENERIC_ALL,						//!< All possible rights
		Execute = GENERIC_EXECUTE,				//!< Execute access
		Read = GENERIC_READ,					//!< Read access
		Write = GENERIC_WRITE,					//!< Write access
	};

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Standard access-rights for securable objects
	*
	* @details	Defines standard access-rights which correspond to operations common to most securable 
	*			object types
	*/
	enum class StandardRight : access_mask_t {
		All = STANDARD_RIGHTS_ALL,				//!< Delete, Wait, Read/modify DACL, Modify Owner
		Execute = STANDARD_RIGHTS_EXECUTE,		//!< Read the discretionary ACL
		Read = STANDARD_RIGHTS_READ,			//!< Read the discretionary ACL
		Required = STANDARD_RIGHTS_REQUIRED,	//!< Delete, Read/modify DACL, Modify Owner
		Write = STANDARD_RIGHTS_WRITE,			//!< Read the discretionary ACL (NB: Not a mistake)
		Synchronize = SYNCHRONIZE,              //!< Wait on object
	};

}      // namespace core::win
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta 
{
	//! @brief	@c core::win::CommonRight is a bitflag
	metadata bool Settings<bitwise_enum, win::CommonRight> = true;
	
	//! @brief	@c core::win::GenericRight is a bitflag
	metadata bool Settings<bitwise_enum, win::GenericRight> = true;
	
	//! @brief	@c core::win::StandardRight is a bitflag
	metadata bool Settings<bitwise_enum, win::StandardRight> = true;
	
	//! @brief	@c core::win::StandardRight can be combined with core::win::CommonRight
	metadata bool Settings<compatible_enum, win::StandardRight, win::CommonRight> = true;

	//! @brief	@c core::win::StandardRight can be combined with core::win::GenericRight
	metadata bool Settings<compatible_enum, win::StandardRight, win::GenericRight> = true;

	//! @brief	@c core::win::GenericRight can be combined with core::win::CommonRight
	metadata bool Settings<compatible_enum, win::GenericRight, win::CommonRight> = true;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif      // security_StandardRight_h_included
