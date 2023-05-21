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
#pragma push_macro("CreateSymbolicLink")
#undef CreateSymbolicLink
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security
{
	enum class PrivilegeName : uint32_t {
		AssignPrimaryToken,		//!< Required to assign the primary token of a process.
		Audit,					//!< Required to generate audit-log entries
		Backup,					//!< Required to perform backup operations (causes the system to grant all read access control to any file, regardless of the access control list)
		ChangeNotify,			//!< Required to receive notifications of changes to files or directories. This privilege also causes the system to skip all traversal access checks. It is enabled by default for all users.
		CreateGlobal,			//!< Required to create named file mapping objects in the global namespace during Terminal Services sessions. This privilege is enabled by default for administrators, services, and the local system account.
		CreatePagefile,			//!< Required to create a paging file.
		CreatePermanent,		//!< Required to create a permanent object.
		CreateSymbolicLink,		//!< Required to create a symbolic link.
		CreateToken,			//!< Required to create a primary token.
		Debug,					//!< Required to debug and adjust the memory of a process owned by another account.
		DelegateSessionUserImpersonate,	//!< Required to obtain an impersonation token for another user in the same session.
		EnableDelegation,		//!< Required to mark user and computer accounts as trusted for delegation.
		Impersonate,			//!< Required to impersonate.
		IncreaseBasePriority,	//!< Required to increase the base priority of a process.
		IncreaseQuota,			//!< Required to increase the quota assigned to a process.
		IncreaseWorkingSet,		//!< Required to allocate more memory for applications that run in the context of users.
		LoadDriver,				//!< Required to load or unload a device driver.
		LockMemory,				//!< Required to lock physical pages in memory.
		MachineAccount,			//!< Required to create a computer account.
		ManageVolume,			//!< Required to enable volume management privileges.
		ProfileSingleProcess,	//!< Required to gather profiling information for a single process.
		Relabel,				//!< Required to modify the mandatory integrity level of an object
		RemoteShutdown,			//!< Required to shut down a system using a network request.
		Restore,				//!< Required to perform restore operations (causes system to grant all write access control to any file)
		Security,				//!< Required to perform a number of security-related functions, such as controlling and viewing audit messages.
		Shutdown,				//!< Required to shut down a local system.
		SyncAgent,				//!< Required for a domain controller to use LDAP directory synchronization services (allows holder to read all objects and properties regardless of their DACL)
		SystemEnvironment,		//!< Required to modify the nonvolatile RAM configuration information.
		SystemProfile,			//!< Required to gather profiling information for the entire system.
		Systemtime,				//!< Required to modify the system time.
		TakeOwnership,			//!< Required to take ownership of an object without being granted discretionary access.
		Tcb,					//!< Identifies holder as part of the trusted computer base
		TimeZone,				//!< Required to adjust the time zone associated with the computer's internal clock.
		TrustedCredManAccess,	//!< Required to access Credential Manager as a trusted caller.
		Undock,					//!< Required to undock a laptop.
		UnsolicitedInput,		//!< Required to read unsolicited input from a terminal device.
	};
}
#pragma pop_macro("CreateSymbolicLink")
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o