/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2024, Nick Crowley. All rights reserved.
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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	struct ErrorCodeName { 
		std::string_view Name; 
		long             Code;
	};

	std::array<ErrorCodeName, 2887> constexpr
	inline static ErrorCodeNames
	{
#define _MakeErrorCodeName(value)  ErrorCodeName{#value, value}

		_MakeErrorCodeName(ERROR_SUCCESS),  //! The operation completed successfully.
#pragma region Error code definitions
		_MakeErrorCodeName(ERROR_INVALID_FUNCTION),  //! Incorrect function.
		_MakeErrorCodeName(ERROR_FILE_NOT_FOUND),  //! The system cannot find the file specified.
		_MakeErrorCodeName(ERROR_PATH_NOT_FOUND),  //! The system cannot find the path specified.
		_MakeErrorCodeName(ERROR_TOO_MANY_OPEN_FILES),  //! The system cannot open the file.
		_MakeErrorCodeName(ERROR_ACCESS_DENIED),  //! Access is denied.
		_MakeErrorCodeName(ERROR_INVALID_HANDLE),  //! The handle is invalid.
		_MakeErrorCodeName(ERROR_ARENA_TRASHED),  //! The storage control blocks were destroyed.
		_MakeErrorCodeName(ERROR_NOT_ENOUGH_MEMORY),  //! Not enough memory resources are available to process this command.
		_MakeErrorCodeName(ERROR_INVALID_BLOCK),  //! The storage control block address is invalid.
		_MakeErrorCodeName(ERROR_BAD_ENVIRONMENT),  //! The environment is incorrect.
		_MakeErrorCodeName(ERROR_BAD_FORMAT),  //! An attempt was made to load a program with an incorrect format.
		_MakeErrorCodeName(ERROR_INVALID_ACCESS),  //! The access code is invalid.
		_MakeErrorCodeName(ERROR_INVALID_DATA),  //! The data is invalid.
		_MakeErrorCodeName(ERROR_OUTOFMEMORY),  //! Not enough storage is available to complete this operation.
		_MakeErrorCodeName(ERROR_INVALID_DRIVE),  //! The system cannot find the drive specified.
		_MakeErrorCodeName(ERROR_CURRENT_DIRECTORY),  //! The directory cannot be removed.
		_MakeErrorCodeName(ERROR_NOT_SAME_DEVICE),  //! The system cannot move the file to a different disk drive.
		_MakeErrorCodeName(ERROR_NO_MORE_FILES),  //! There are no more files.
		_MakeErrorCodeName(ERROR_WRITE_PROTECT),  //! The media is write protected.
		_MakeErrorCodeName(ERROR_BAD_UNIT),  //! The system cannot find the device specified.
		_MakeErrorCodeName(ERROR_NOT_READY),  //! The device is not ready.
		_MakeErrorCodeName(ERROR_BAD_COMMAND),  //! The device does not recognize the command.
		_MakeErrorCodeName(ERROR_CRC),  //! Data error (cyclic redundancy check).
		_MakeErrorCodeName(ERROR_BAD_LENGTH),  //! The program issued a command but the command length is incorrect.
		_MakeErrorCodeName(ERROR_SEEK),  //! The drive cannot locate a specific area or track on the disk.
		_MakeErrorCodeName(ERROR_NOT_DOS_DISK),  //! The specified disk or diskette cannot be accessed.
		_MakeErrorCodeName(ERROR_SECTOR_NOT_FOUND),  //! The drive cannot find the sector requested.
		_MakeErrorCodeName(ERROR_OUT_OF_PAPER),  //! The printer is out of paper.
		_MakeErrorCodeName(ERROR_WRITE_FAULT),  //! The system cannot write to the specified device.
		_MakeErrorCodeName(ERROR_READ_FAULT),  //! The system cannot read from the specified device.
		_MakeErrorCodeName(ERROR_GEN_FAILURE),  //! A device attached to the system is not functioning.
		_MakeErrorCodeName(ERROR_SHARING_VIOLATION),  //! The process cannot access the file because it is being used by another process.
		_MakeErrorCodeName(ERROR_LOCK_VIOLATION),  //! The process cannot access the file because another process has locked a portion of the file.
		_MakeErrorCodeName(ERROR_WRONG_DISK),  //! The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into drive %1.
		_MakeErrorCodeName(ERROR_SHARING_BUFFER_EXCEEDED),  //! Too many files opened for sharing.
		_MakeErrorCodeName(ERROR_HANDLE_EOF),  //! Reached the end of the file.
		_MakeErrorCodeName(ERROR_HANDLE_DISK_FULL),  //! The disk is full.
		_MakeErrorCodeName(ERROR_NOT_SUPPORTED),  //! The request is not supported.
		_MakeErrorCodeName(ERROR_REM_NOT_LIST),  //! Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.
		_MakeErrorCodeName(ERROR_DUP_NAME),  //! You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again. If joining a workgroup, choose another workgroup name.
		_MakeErrorCodeName(ERROR_BAD_NETPATH),  //! The network path was not found.
		_MakeErrorCodeName(ERROR_NETWORK_BUSY),  //! The network is busy.
		_MakeErrorCodeName(ERROR_DEV_NOT_EXIST),  //! The specified network resource or device is no longer available.
		_MakeErrorCodeName(ERROR_TOO_MANY_CMDS),  //! The network BIOS command limit has been reached.
		_MakeErrorCodeName(ERROR_ADAP_HDW_ERR),  //! A network adapter hardware error occurred.
		_MakeErrorCodeName(ERROR_BAD_NET_RESP),  //! The specified server cannot perform the requested operation.
		_MakeErrorCodeName(ERROR_UNEXP_NET_ERR),  //! An unexpected network error occurred.
		_MakeErrorCodeName(ERROR_BAD_REM_ADAP),  //! The remote adapter is not compatible.
		_MakeErrorCodeName(ERROR_PRINTQ_FULL),  //! The printer queue is full.
		_MakeErrorCodeName(ERROR_NO_SPOOL_SPACE),  //! Space to store the file waiting to be printed is not available on the server.
		_MakeErrorCodeName(ERROR_PRINT_CANCELLED),  //! Your file waiting to be printed was deleted.
		_MakeErrorCodeName(ERROR_NETNAME_DELETED),  //! The specified network name is no longer available.
		_MakeErrorCodeName(ERROR_NETWORK_ACCESS_DENIED),  //! Network access is denied.
		_MakeErrorCodeName(ERROR_BAD_DEV_TYPE),  //! The network resource type is not correct.
		_MakeErrorCodeName(ERROR_BAD_NET_NAME),  //! The network name cannot be found.
		_MakeErrorCodeName(ERROR_TOO_MANY_NAMES),  //! The name limit for the local computer network adapter card was exceeded.
		_MakeErrorCodeName(ERROR_TOO_MANY_SESS),  //! The network BIOS session limit was exceeded.
		_MakeErrorCodeName(ERROR_SHARING_PAUSED),  //! The remote server has been paused or is in the process of being started.
		_MakeErrorCodeName(ERROR_REQ_NOT_ACCEP),  //! No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
		_MakeErrorCodeName(ERROR_REDIR_PAUSED),  //! The specified printer or disk device has been paused.
		_MakeErrorCodeName(ERROR_FILE_EXISTS),  //! The file exists.
		_MakeErrorCodeName(ERROR_CANNOT_MAKE),  //! The directory or file cannot be created.
		_MakeErrorCodeName(ERROR_FAIL_I24),  //! Fail on INT 24.
		_MakeErrorCodeName(ERROR_OUT_OF_STRUCTURES),  //! Storage to process this request is not available.
		_MakeErrorCodeName(ERROR_ALREADY_ASSIGNED),  //! The local device name is already in use.
		_MakeErrorCodeName(ERROR_INVALID_PASSWORD),  //! The specified network password is not correct.
		_MakeErrorCodeName(ERROR_INVALID_PARAMETER),  //! The parameter is incorrect.
		_MakeErrorCodeName(ERROR_NET_WRITE_FAULT),  //! A write fault occurred on the network.
		_MakeErrorCodeName(ERROR_NO_PROC_SLOTS),  //! The system cannot start another process at this time.
		_MakeErrorCodeName(ERROR_TOO_MANY_SEMAPHORES),  //! Cannot create another system semaphore.
		_MakeErrorCodeName(ERROR_EXCL_SEM_ALREADY_OWNED),  //! The exclusive semaphore is owned by another process.
		_MakeErrorCodeName(ERROR_SEM_IS_SET),  //! The semaphore is set and cannot be closed.
		_MakeErrorCodeName(ERROR_TOO_MANY_SEM_REQUESTS),  //! The semaphore cannot be set again.
		_MakeErrorCodeName(ERROR_INVALID_AT_INTERRUPT_TIME),  //! Cannot request exclusive semaphores at interrupt time.
		_MakeErrorCodeName(ERROR_SEM_OWNER_DIED),  //! The previous ownership of this semaphore has ended.
		_MakeErrorCodeName(ERROR_SEM_USER_LIMIT),  //! Insert the diskette for drive %1.
		_MakeErrorCodeName(ERROR_DISK_CHANGE),  //! The program stopped because an alternate diskette was not inserted.
		_MakeErrorCodeName(ERROR_DRIVE_LOCKED),  //! The disk is in use or locked by another process.
		_MakeErrorCodeName(ERROR_BROKEN_PIPE),  //! The pipe has been ended.
		_MakeErrorCodeName(ERROR_OPEN_FAILED),  //! The system cannot open the device or file specified.
		_MakeErrorCodeName(ERROR_BUFFER_OVERFLOW),  //! The file name is too long.
		_MakeErrorCodeName(ERROR_DISK_FULL),  //! There is not enough space on the disk.
		_MakeErrorCodeName(ERROR_NO_MORE_SEARCH_HANDLES),  //! No more internal file identifiers available.
		_MakeErrorCodeName(ERROR_INVALID_TARGET_HANDLE),  //! The target internal file identifier is incorrect.
		_MakeErrorCodeName(ERROR_INVALID_CATEGORY),  //! The IOCTL call made by the application program is not correct.
		_MakeErrorCodeName(ERROR_INVALID_VERIFY_SWITCH),  //! The verify-on-write switch parameter value is not correct.
		_MakeErrorCodeName(ERROR_BAD_DRIVER_LEVEL),  //! The system does not support the command requested.
		_MakeErrorCodeName(ERROR_CALL_NOT_IMPLEMENTED),  //! This function is not supported on this system.
		_MakeErrorCodeName(ERROR_SEM_TIMEOUT),  //! The semaphore timeout period has expired.
		_MakeErrorCodeName(ERROR_INSUFFICIENT_BUFFER),  //! The data area passed to a system call is too small.
		_MakeErrorCodeName(ERROR_INVALID_NAME),  //! The filename, directory name, or volume label syntax is incorrect.
		_MakeErrorCodeName(ERROR_INVALID_LEVEL),  //! The system call level is not correct.
		_MakeErrorCodeName(ERROR_NO_VOLUME_LABEL),  //! The disk has no volume label.
		_MakeErrorCodeName(ERROR_MOD_NOT_FOUND),  //! The specified module could not be found.
		_MakeErrorCodeName(ERROR_PROC_NOT_FOUND),  //! The specified procedure could not be found.
		_MakeErrorCodeName(ERROR_WAIT_NO_CHILDREN),  //! There are no child processes to wait for.
		_MakeErrorCodeName(ERROR_CHILD_NOT_COMPLETE),  //! The %1 application cannot be run in Win32 mode.
		_MakeErrorCodeName(ERROR_DIRECT_ACCESS_HANDLE),  //! Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.
		_MakeErrorCodeName(ERROR_NEGATIVE_SEEK),  //! An attempt was made to move the file pointer before the beginning of the file.
		_MakeErrorCodeName(ERROR_SEEK_ON_DEVICE),  //! The file pointer cannot be set on the specified device or file.
		_MakeErrorCodeName(ERROR_IS_JOIN_TARGET),  //! A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.
		_MakeErrorCodeName(ERROR_IS_JOINED),  //! An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.
		_MakeErrorCodeName(ERROR_IS_SUBSTED),  //! An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.
		_MakeErrorCodeName(ERROR_NOT_JOINED),  //! The system tried to delete the JOIN of a drive that is not joined.
		_MakeErrorCodeName(ERROR_NOT_SUBSTED),  //! The system tried to delete the substitution of a drive that is not substituted.
		_MakeErrorCodeName(ERROR_JOIN_TO_JOIN),  //! The system tried to join a drive to a directory on a joined drive.
		_MakeErrorCodeName(ERROR_SUBST_TO_SUBST),  //! The system tried to substitute a drive to a directory on a substituted drive.
		_MakeErrorCodeName(ERROR_JOIN_TO_SUBST),  //! The system tried to join a drive to a directory on a substituted drive.
		_MakeErrorCodeName(ERROR_SUBST_TO_JOIN),  //! The system tried to SUBST a drive to a directory on a joined drive.
		_MakeErrorCodeName(ERROR_BUSY_DRIVE),  //! The system cannot perform a JOIN or SUBST at this time.
		_MakeErrorCodeName(ERROR_SAME_DRIVE),  //! The system cannot join or substitute a drive to or for a directory on the same drive.
		_MakeErrorCodeName(ERROR_DIR_NOT_ROOT),  //! The directory is not a subdirectory of the root directory.
		_MakeErrorCodeName(ERROR_DIR_NOT_EMPTY),  //! The directory is not empty.
		_MakeErrorCodeName(ERROR_IS_SUBST_PATH),  //! The path specified is being used in a substitute.
		_MakeErrorCodeName(ERROR_IS_JOIN_PATH),  //! Not enough resources are available to process this command.
		_MakeErrorCodeName(ERROR_PATH_BUSY),  //! The path specified cannot be used at this time.
		_MakeErrorCodeName(ERROR_IS_SUBST_TARGET),  //! An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.
		_MakeErrorCodeName(ERROR_SYSTEM_TRACE),  //! System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.
		_MakeErrorCodeName(ERROR_INVALID_EVENT_COUNT),  //! The number of specified semaphore events for DosMuxSemWait is not correct.
		_MakeErrorCodeName(ERROR_TOO_MANY_MUXWAITERS),  //! DosMuxSemWait did not execute; too many semaphores are already set.
		_MakeErrorCodeName(ERROR_INVALID_LIST_FORMAT),  //! The DosMuxSemWait list is not correct.
		_MakeErrorCodeName(ERROR_LABEL_TOO_LONG),  //! The volume label you entered exceeds the label character limit of the target file system.
		_MakeErrorCodeName(ERROR_TOO_MANY_TCBS),  //! Cannot create another thread.
		_MakeErrorCodeName(ERROR_SIGNAL_REFUSED),  //! The recipient process has refused the signal.
		_MakeErrorCodeName(ERROR_DISCARDED),  //! The segment is already discarded and cannot be locked.
		_MakeErrorCodeName(ERROR_NOT_LOCKED),  //! The segment is already unlocked.
		_MakeErrorCodeName(ERROR_BAD_THREADID_ADDR),  //! The address for the thread ID is not correct.
		_MakeErrorCodeName(ERROR_BAD_ARGUMENTS),  //! One or more arguments are not correct.
		_MakeErrorCodeName(ERROR_BAD_PATHNAME),  //! The specified path is invalid.
		_MakeErrorCodeName(ERROR_SIGNAL_PENDING),  //! A signal is already pending.
		_MakeErrorCodeName(ERROR_MAX_THRDS_REACHED),  //! No more threads can be created in the system.
		_MakeErrorCodeName(ERROR_LOCK_FAILED),  //! Unable to lock a region of a file.
		_MakeErrorCodeName(ERROR_BUSY),  //! The requested resource is in use.
		_MakeErrorCodeName(ERROR_DEVICE_SUPPORT_IN_PROGRESS),  //! Device's command support detection is in progress.
		_MakeErrorCodeName(ERROR_CANCEL_VIOLATION),  //! A lock request was not outstanding for the supplied cancel region.
		_MakeErrorCodeName(ERROR_ATOMIC_LOCKS_NOT_SUPPORTED),  //! The file system does not support atomic changes to the lock type.
		_MakeErrorCodeName(ERROR_INVALID_SEGMENT_NUMBER),  //! The system detected a segment number that was not correct.
		_MakeErrorCodeName(ERROR_INVALID_ORDINAL),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_ALREADY_EXISTS),  //! Cannot create a file when that file already exists.
		_MakeErrorCodeName(ERROR_INVALID_FLAG_NUMBER),  //! The flag passed is not correct.
		_MakeErrorCodeName(ERROR_SEM_NOT_FOUND),  //! The specified system semaphore name was not found.
		_MakeErrorCodeName(ERROR_INVALID_STARTING_CODESEG),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_INVALID_STACKSEG),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_INVALID_MODULETYPE),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_INVALID_EXE_SIGNATURE),  //! Cannot run %1 in Win32 mode.
		_MakeErrorCodeName(ERROR_EXE_MARKED_INVALID),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_BAD_EXE_FORMAT),  //! %1 is not a valid Win32 application.
		_MakeErrorCodeName(ERROR_ITERATED_DATA_EXCEEDS_64k),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_INVALID_MINALLOCSIZE),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_DYNLINK_FROM_INVALID_RING),  //! The operating system cannot run this application program.
		_MakeErrorCodeName(ERROR_IOPL_NOT_ENABLED),  //! The operating system is not presently configured to run this application.
		_MakeErrorCodeName(ERROR_INVALID_SEGDPL),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_AUTODATASEG_EXCEEDS_64k),  //! The operating system cannot run this application program.
		_MakeErrorCodeName(ERROR_RING2SEG_MUST_BE_MOVABLE),  //! The code segment cannot be greater than or equal to 64K.
		_MakeErrorCodeName(ERROR_RELOC_CHAIN_XEEDS_SEGLIM),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_INFLOOP_IN_RELOC_CHAIN),  //! The operating system cannot run %1.
		_MakeErrorCodeName(ERROR_ENVVAR_NOT_FOUND),  //! The system could not find the environment option that was entered.
		_MakeErrorCodeName(ERROR_NO_SIGNAL_SENT),  //! No process in the command subtree has a signal handler.
		_MakeErrorCodeName(ERROR_FILENAME_EXCED_RANGE),  //! The filename or extension is too long.
		_MakeErrorCodeName(ERROR_RING2_STACK_IN_USE),  //! The ring 2 stack is in use.
		_MakeErrorCodeName(ERROR_META_EXPANSION_TOO_LONG),  //! The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.
		_MakeErrorCodeName(ERROR_INVALID_SIGNAL_NUMBER),  //! The signal being posted is not correct.
		_MakeErrorCodeName(ERROR_THREAD_1_INACTIVE),  //! The signal handler cannot be set.
		_MakeErrorCodeName(ERROR_LOCKED),  //! The segment is locked and cannot be reallocated.
		_MakeErrorCodeName(ERROR_TOO_MANY_MODULES),  //! Too many dynamic-link modules are attached to this program or dynamic-link module.
		_MakeErrorCodeName(ERROR_NESTING_NOT_ALLOWED),  //! Cannot nest calls to LoadModule.
		_MakeErrorCodeName(ERROR_EXE_MACHINE_TYPE_MISMATCH),  //! This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information and then contact the software publisher.
		_MakeErrorCodeName(ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY),  //! The image file %1 is signed, unable to modify.
		_MakeErrorCodeName(ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY),  //! The image file %1 is strong signed, unable to modify.
		_MakeErrorCodeName(ERROR_FILE_CHECKED_OUT),  //! This file is checked out or locked for editing by another user.
		_MakeErrorCodeName(ERROR_CHECKOUT_REQUIRED),  //! The file must be checked out before saving changes.
		_MakeErrorCodeName(ERROR_BAD_FILE_TYPE),  //! The file type being saved or retrieved has been blocked.
		_MakeErrorCodeName(ERROR_FILE_TOO_LARGE),  //! The file size exceeds the limit allowed and cannot be saved.
		_MakeErrorCodeName(ERROR_FORMS_AUTH_REQUIRED),  //! Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.
		_MakeErrorCodeName(ERROR_VIRUS_INFECTED),  //! Operation did not complete successfully because the file contains a virus or potentially unwanted software.
		_MakeErrorCodeName(ERROR_VIRUS_DELETED),  //! This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.
		_MakeErrorCodeName(ERROR_PIPE_LOCAL),  //! The pipe is local.
		_MakeErrorCodeName(ERROR_BAD_PIPE),  //! The pipe state is invalid.
		_MakeErrorCodeName(ERROR_PIPE_BUSY),  //! All pipe instances are busy.
		_MakeErrorCodeName(ERROR_NO_DATA),  //! The pipe is being closed.
		_MakeErrorCodeName(ERROR_PIPE_NOT_CONNECTED),  //! No process is on the other end of the pipe.
		_MakeErrorCodeName(ERROR_MORE_DATA),  //! More data is available.
		_MakeErrorCodeName(ERROR_VC_DISCONNECTED),  //! The session was canceled.
		_MakeErrorCodeName(ERROR_INVALID_EA_NAME),  //! The specified extended attribute name was invalid.
		_MakeErrorCodeName(ERROR_EA_LIST_INCONSISTENT),  //! The extended attributes are inconsistent.
		_MakeErrorCodeName(WAIT_TIMEOUT),  //! The wait operation timed out.
		_MakeErrorCodeName(ERROR_NO_MORE_ITEMS),  //! No more data is available.
		_MakeErrorCodeName(ERROR_CANNOT_COPY),  //! The copy functions cannot be used.
		_MakeErrorCodeName(ERROR_DIRECTORY),  //! The directory name is invalid.
		_MakeErrorCodeName(ERROR_EAS_DIDNT_FIT),  //! The extended attributes did not fit in the buffer.
		_MakeErrorCodeName(ERROR_EA_FILE_CORRUPT),  //! The extended attribute file on the mounted file system is corrupt.
		_MakeErrorCodeName(ERROR_EA_TABLE_FULL),  //! The extended attribute table file is full.
		_MakeErrorCodeName(ERROR_INVALID_EA_HANDLE),  //! The specified extended attribute handle is invalid.
		_MakeErrorCodeName(ERROR_EAS_NOT_SUPPORTED),  //! The mounted file system does not support extended attributes.
		_MakeErrorCodeName(ERROR_NOT_OWNER),  //! Attempt to release mutex not owned by caller.
		_MakeErrorCodeName(ERROR_TOO_MANY_POSTS),  //! Too many posts were made to a semaphore.
		_MakeErrorCodeName(ERROR_PARTIAL_COPY),  //! Only part of a ReadProcessMemory or WriteProcessMemory request was completed.
		_MakeErrorCodeName(ERROR_OPLOCK_NOT_GRANTED),  //! The oplock request is denied.
		_MakeErrorCodeName(ERROR_INVALID_OPLOCK_PROTOCOL),  //! An invalid oplock acknowledgment was received by the system.
		_MakeErrorCodeName(ERROR_DISK_TOO_FRAGMENTED),  //! The volume is too fragmented to complete this operation.
		_MakeErrorCodeName(ERROR_DELETE_PENDING),  //! The file cannot be opened because it is in the process of being deleted.
		_MakeErrorCodeName(ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING),  //! Short name settings may not be changed on this volume due to the global registry setting.
		_MakeErrorCodeName(ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME),  //! Short names are not enabled on this volume.
		_MakeErrorCodeName(ERROR_SECURITY_STREAM_IS_INCONSISTENT),  //! The security stream for the given volume is in an inconsistent state. Please run CHKDSK on the volume.
		_MakeErrorCodeName(ERROR_INVALID_LOCK_RANGE),  //! A requested file lock operation cannot be processed due to an invalid byte range.
		_MakeErrorCodeName(ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT),  //! The subsystem needed to support the image type is not present.
		_MakeErrorCodeName(ERROR_NOTIFICATION_GUID_ALREADY_DEFINED),  //! The specified file already has a notification GUID associated with it.
		_MakeErrorCodeName(ERROR_INVALID_EXCEPTION_HANDLER),  //! An invalid exception handler routine has been detected.
		_MakeErrorCodeName(ERROR_DUPLICATE_PRIVILEGES),  //! Duplicate privileges were specified for the token.
		_MakeErrorCodeName(ERROR_NO_RANGES_PROCESSED),  //! No ranges for the specified operation were able to be processed.
		_MakeErrorCodeName(ERROR_NOT_ALLOWED_ON_SYSTEM_FILE),  //! Operation is not allowed on a file system internal file.
		_MakeErrorCodeName(ERROR_DISK_RESOURCES_EXHAUSTED),  //! The physical resources of this disk have been exhausted.
		_MakeErrorCodeName(ERROR_INVALID_TOKEN),  //! The token representing the data is invalid.
		_MakeErrorCodeName(ERROR_DEVICE_FEATURE_NOT_SUPPORTED),  //! The device does not support the command feature.
		_MakeErrorCodeName(ERROR_MR_MID_NOT_FOUND),  //! The system cannot find message text for message number 0x%1 in the message file for %2.
		_MakeErrorCodeName(ERROR_SCOPE_NOT_FOUND),  //! The scope specified was not found.
		_MakeErrorCodeName(ERROR_UNDEFINED_SCOPE),  //! The Central Access Policy specified is not defined on the target machine.
		_MakeErrorCodeName(ERROR_INVALID_CAP),  //! The Central Access Policy obtained from Active Directory is invalid.
		_MakeErrorCodeName(ERROR_DEVICE_UNREACHABLE),  //! The device is unreachable.
		_MakeErrorCodeName(ERROR_DEVICE_NO_RESOURCES),  //! The target device has insufficient resources to complete the operation.
		_MakeErrorCodeName(ERROR_DATA_CHECKSUM_ERROR),  //! A data integrity checksum error occurred. Data in the file stream is corrupt.
		_MakeErrorCodeName(ERROR_INTERMIXED_KERNEL_EA_OPERATION),  //! An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.
		_MakeErrorCodeName(ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED),  //! Device does not support file-level TRIM.
		_MakeErrorCodeName(ERROR_OFFSET_ALIGNMENT_VIOLATION),  //! The command specified a data offset that does not align to the device's granularity/alignment.
		_MakeErrorCodeName(ERROR_INVALID_FIELD_IN_PARAMETER_LIST),  //! The command specified an invalid field in its parameter list.
		_MakeErrorCodeName(ERROR_OPERATION_IN_PROGRESS),  //! An operation is currently in progress with the device.
		_MakeErrorCodeName(ERROR_BAD_DEVICE_PATH),  //! An attempt was made to send down the command via an invalid path to the target device.
		_MakeErrorCodeName(ERROR_TOO_MANY_DESCRIPTORS),  //! The command specified a number of descriptors that exceeded the maximum supported by the device.
		_MakeErrorCodeName(ERROR_SCRUB_DATA_DISABLED),  //! Scrub is disabled on the specified file.
		_MakeErrorCodeName(ERROR_NOT_REDUNDANT_STORAGE),  //! The storage device does not provide redundancy.
		_MakeErrorCodeName(ERROR_RESIDENT_FILE_NOT_SUPPORTED),  //! An operation is not supported on a resident file.
		_MakeErrorCodeName(ERROR_COMPRESSED_FILE_NOT_SUPPORTED),  //! An operation is not supported on a compressed file.
		_MakeErrorCodeName(ERROR_DIRECTORY_NOT_SUPPORTED),  //! An operation is not supported on a directory.
		_MakeErrorCodeName(ERROR_NOT_READ_FROM_COPY),  //! The specified copy of the requested data could not be read.
		_MakeErrorCodeName(ERROR_FAIL_NOACTION_REBOOT),  //! No action was taken as a system reboot is required.
		_MakeErrorCodeName(ERROR_FAIL_SHUTDOWN),  //! The shutdown operation failed.
		_MakeErrorCodeName(ERROR_FAIL_RESTART),  //! The restart operation failed.
		_MakeErrorCodeName(ERROR_MAX_SESSIONS_REACHED),  //! The maximum number of sessions has been reached.
		_MakeErrorCodeName(ERROR_THREAD_MODE_ALREADY_BACKGROUND),  //! The thread is already in background processing mode.
		_MakeErrorCodeName(ERROR_THREAD_MODE_NOT_BACKGROUND),  //! The thread is not in background processing mode.
		_MakeErrorCodeName(ERROR_PROCESS_MODE_ALREADY_BACKGROUND),  //! The process is already in background processing mode.
		_MakeErrorCodeName(ERROR_PROCESS_MODE_NOT_BACKGROUND),  //! The process is not in background processing mode.
		_MakeErrorCodeName(ERROR_INVALID_ADDRESS),  //! Attempt to access invalid address.
		_MakeErrorCodeName(ERROR_USER_PROFILE_LOAD),  //! User profile cannot be loaded.
		_MakeErrorCodeName(ERROR_ARITHMETIC_OVERFLOW),  //! Arithmetic result exceeded 32 bits.
		_MakeErrorCodeName(ERROR_PIPE_CONNECTED),  //! There is a process on other end of the pipe.
		_MakeErrorCodeName(ERROR_PIPE_LISTENING),  //! Waiting for a process to open the other end of the pipe.
		_MakeErrorCodeName(ERROR_VERIFIER_STOP),  //! Application verifier has found an error in the current process.
		_MakeErrorCodeName(ERROR_ABIOS_ERROR),  //! An error occurred in the ABIOS subsystem.
		_MakeErrorCodeName(ERROR_WX86_WARNING),  //! A warning occurred in the WX86 subsystem.
		_MakeErrorCodeName(ERROR_WX86_ERROR),  //! An error occurred in the WX86 subsystem.
		_MakeErrorCodeName(ERROR_TIMER_NOT_CANCELED),  //! An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
		_MakeErrorCodeName(ERROR_UNWIND),  //! Unwind exception code.
		_MakeErrorCodeName(ERROR_BAD_STACK),  //! An invalid or unaligned stack was encountered during an unwind operation.
		_MakeErrorCodeName(ERROR_INVALID_UNWIND_TARGET),  //! An invalid unwind target was encountered during an unwind operation.
		_MakeErrorCodeName(ERROR_INVALID_PORT_ATTRIBUTES),  //! Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
		_MakeErrorCodeName(ERROR_PORT_MESSAGE_TOO_LONG),  //! Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
		_MakeErrorCodeName(ERROR_INVALID_QUOTA_LOWER),  //! An attempt was made to lower a quota limit below the current usage.
		_MakeErrorCodeName(ERROR_DEVICE_ALREADY_ATTACHED),  //! An attempt was made to attach to a device that was already attached to another device.
		_MakeErrorCodeName(ERROR_INSTRUCTION_MISALIGNMENT),  //! An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
		_MakeErrorCodeName(ERROR_PROFILING_NOT_STARTED),  //! Profiling not started.
		_MakeErrorCodeName(ERROR_PROFILING_NOT_STOPPED),  //! Profiling not stopped.
		_MakeErrorCodeName(ERROR_COULD_NOT_INTERPRET),  //! The passed ACL did not contain the minimum required information.
		_MakeErrorCodeName(ERROR_PROFILING_AT_LIMIT),  //! The number of active profiling objects is at the maximum and no more may be started.
		_MakeErrorCodeName(ERROR_CANT_WAIT),  //! Used to indicate that an operation cannot continue without blocking for I/O.
		_MakeErrorCodeName(ERROR_CANT_TERMINATE_SELF),  //! Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.
		_MakeErrorCodeName(ERROR_UNEXPECTED_MM_CREATE_ERR),  //! If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
		_MakeErrorCodeName(ERROR_UNEXPECTED_MM_MAP_ERROR),  //! If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
		_MakeErrorCodeName(ERROR_UNEXPECTED_MM_EXTEND_ERR),  //! If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
		_MakeErrorCodeName(ERROR_BAD_FUNCTION_TABLE),  //! A malformed function table was encountered during an unwind operation.
		_MakeErrorCodeName(ERROR_NO_GUID_TRANSLATION),  //! Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system. This causes the protection attempt to fail, which may cause a file creation attempt to fail.
		_MakeErrorCodeName(ERROR_INVALID_LDT_SIZE),  //! Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
		_MakeErrorCodeName(ERROR_INVALID_LDT_OFFSET),  //! Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
		_MakeErrorCodeName(ERROR_INVALID_LDT_DESCRIPTOR),  //! Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
		_MakeErrorCodeName(ERROR_TOO_MANY_THREADS),  //! Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.
		_MakeErrorCodeName(ERROR_THREAD_NOT_IN_PROCESS),  //! An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
		_MakeErrorCodeName(ERROR_PAGEFILE_QUOTA_EXCEEDED),  //! Page file quota was exceeded.
		_MakeErrorCodeName(ERROR_LOGON_SERVER_CONFLICT),  //! The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
		_MakeErrorCodeName(ERROR_SYNCHRONIZATION_REQUIRED),  //! The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
		_MakeErrorCodeName(ERROR_NET_OPEN_FAILED),  //! The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
		_MakeErrorCodeName(ERROR_IO_PRIVILEGE_FAILED),  //! {Privilege Failed} The I/O permissions for the process could not be changed.
		_MakeErrorCodeName(ERROR_CONTROL_C_EXIT),  //! {Application Exit by CTRL+C} The application terminated as a result of a CTRL+C.
		_MakeErrorCodeName(ERROR_MISSING_SYSTEMFILE),  //! {Missing System File} The required system file %hs is bad or missing.
		_MakeErrorCodeName(ERROR_UNHANDLED_EXCEPTION),  //! {Application Error} The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
		_MakeErrorCodeName(ERROR_APP_INIT_FAILURE),  //! {Application Error} The application was unable to start correctly (0x%lx). Click OK to close the application.
		_MakeErrorCodeName(ERROR_PAGEFILE_CREATE_FAILED),  //! {Unable to Create Paging File} The creation of the paging file %hs failed (%lx). The requested size was %ld.
		_MakeErrorCodeName(ERROR_INVALID_IMAGE_HASH),  //! Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.
		_MakeErrorCodeName(ERROR_NO_PAGEFILE),  //! {No Paging File Specified} No paging file was specified in the system configuration.
		_MakeErrorCodeName(ERROR_ILLEGAL_FLOAT_CONTEXT),  //! {EXCEPTION} A real-mode application issued a floating-point instruction and floating-point hardware is not present.
		_MakeErrorCodeName(ERROR_NO_EVENT_PAIR),  //! An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
		_MakeErrorCodeName(ERROR_DOMAIN_CTRLR_CONFIG_ERROR),  //! A Windows Server has an incorrect configuration.
		_MakeErrorCodeName(ERROR_ILLEGAL_CHARACTER),  //! An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
		_MakeErrorCodeName(ERROR_UNDEFINED_CHARACTER),  //! The Unicode character is not defined in the Unicode character set installed on the system.
		_MakeErrorCodeName(ERROR_FLOPPY_VOLUME),  //! The paging file cannot be created on a floppy diskette.
		_MakeErrorCodeName(ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT),  //! The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.
		_MakeErrorCodeName(ERROR_BACKUP_CONTROLLER),  //! This operation is only allowed for the Primary Domain Controller of the domain.
		_MakeErrorCodeName(ERROR_MUTANT_LIMIT_EXCEEDED),  //! An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
		_MakeErrorCodeName(ERROR_FS_DRIVER_REQUIRED),  //! A volume has been accessed for which a file system driver is required that has not yet been loaded.
		_MakeErrorCodeName(ERROR_CANNOT_LOAD_REGISTRY_FILE),  //! {Registry File Failure} The registry cannot load the hive (file): %hs or its log or alternate. It is corrupt, absent, or not writable.
		_MakeErrorCodeName(ERROR_DEBUG_ATTACH_FAILED),  //! {Unexpected Failure in DebugActiveProcess} An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.
		_MakeErrorCodeName(ERROR_SYSTEM_PROCESS_TERMINATED),  //! {Fatal System Error} The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x). The system has been shut down.
		_MakeErrorCodeName(ERROR_DATA_NOT_ACCEPTED),  //! {Data Not Accepted} The TDI client could not handle the data received during an indication.
		_MakeErrorCodeName(ERROR_VDM_HARD_ERROR),  //! NTVDM encountered a hard error.
		_MakeErrorCodeName(ERROR_DRIVER_CANCEL_TIMEOUT),  //! {Cancel Timeout} The driver %hs failed to complete a cancelled I/O request in the allotted time.
		_MakeErrorCodeName(ERROR_REPLY_MESSAGE_MISMATCH),  //! {Reply Message Mismatch} An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
		_MakeErrorCodeName(ERROR_LOST_WRITEBEHIND_DATA),  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs. The data has been lost. This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
		_MakeErrorCodeName(ERROR_CLIENT_SERVER_PARAMETERS_INVALID),  //! The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.
		_MakeErrorCodeName(ERROR_NOT_TINY_STREAM),  //! The stream is not a tiny stream.
		_MakeErrorCodeName(ERROR_STACK_OVERFLOW_READ),  //! The request must be handled by the stack overflow code.
		_MakeErrorCodeName(ERROR_CONVERT_TO_LARGE),  //! Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
		_MakeErrorCodeName(ERROR_FOUND_OUT_OF_SCOPE),  //! The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
		_MakeErrorCodeName(ERROR_ALLOCATE_BUCKET),  //! The bucket array must be grown. Retry transaction after doing so.
		_MakeErrorCodeName(ERROR_MARSHALL_OVERFLOW),  //! The user/kernel marshalling buffer has overflowed.
		_MakeErrorCodeName(ERROR_INVALID_VARIANT),  //! The supplied variant structure contains invalid data.
		_MakeErrorCodeName(ERROR_BAD_COMPRESSION_BUFFER),  //! The specified buffer contains ill-formed data.
		_MakeErrorCodeName(ERROR_AUDIT_FAILED),  //! {Audit Failed} An attempt to generate a security audit failed.
		_MakeErrorCodeName(ERROR_TIMER_RESOLUTION_NOT_SET),  //! The timer resolution was not previously set by the current process.
		_MakeErrorCodeName(ERROR_INSUFFICIENT_LOGON_INFO),  //! There is insufficient account information to log you on.
		_MakeErrorCodeName(ERROR_BAD_DLL_ENTRYPOINT),  //! {Invalid DLL Entrypoint} The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state. The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.
		_MakeErrorCodeName(ERROR_BAD_SERVICE_ENTRYPOINT),  //! {Invalid Service Callback Entrypoint} The %hs service is not written correctly. The stack pointer has been left in an inconsistent state. The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.
		_MakeErrorCodeName(ERROR_IP_ADDRESS_CONFLICT1),  //! There is an IP address conflict with another system on the network.
		_MakeErrorCodeName(ERROR_IP_ADDRESS_CONFLICT2),  //! There is an IP address conflict with another system on the network.
		_MakeErrorCodeName(ERROR_REGISTRY_QUOTA_LIMIT),  //! {Low On Registry Space} The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
		_MakeErrorCodeName(ERROR_NO_CALLBACK_ACTIVE),  //! A callback return system service cannot be executed when no callback is active.
		_MakeErrorCodeName(ERROR_PWD_TOO_SHORT),  //! The password provided is too short to meet the policy of your user account. Please choose a longer password.
		_MakeErrorCodeName(ERROR_PWD_TOO_RECENT),  //! The policy of your user account does not allow you to change passwords too frequently. This is done to prevent users from changing back to a familiar, but potentially discovered, password. If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
		_MakeErrorCodeName(ERROR_PWD_HISTORY_CONFLICT),  //! You have attempted to change your password to one that you have used in the past. The policy of your user account does not allow this. Please select a password that you have not previously used.
		_MakeErrorCodeName(ERROR_UNSUPPORTED_COMPRESSION),  //! The specified compression format is unsupported.
		_MakeErrorCodeName(ERROR_INVALID_HW_PROFILE),  //! The specified hardware profile configuration is invalid.
		_MakeErrorCodeName(ERROR_INVALID_PLUGPLAY_DEVICE_PATH),  //! The specified Plug and Play registry device path is invalid.
		_MakeErrorCodeName(ERROR_QUOTA_LIST_INCONSISTENT),  //! The specified quota list is internally inconsistent with its descriptor.
		_MakeErrorCodeName(ERROR_EVALUATION_EXPIRATION),  //! {Windows Evaluation Notification} The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
		_MakeErrorCodeName(ERROR_ILLEGAL_DLL_RELOCATION),  //! {Illegal System DLL Relocation} The system DLL %hs was relocated in memory. The application will not run properly. The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.
		_MakeErrorCodeName(ERROR_DLL_INIT_FAILED_LOGOFF),  //! {DLL Initialization Failed} The application failed to initialize because the window station is shutting down.
		_MakeErrorCodeName(ERROR_VALIDATE_CONTINUE),  //! The validation process needs to continue on to the next step.
		_MakeErrorCodeName(ERROR_NO_MORE_MATCHES),  //! There are no more matches for the current index enumeration.
		_MakeErrorCodeName(ERROR_RANGE_LIST_CONFLICT),  //! The range could not be added to the range list because of a conflict.
		_MakeErrorCodeName(ERROR_SERVER_SID_MISMATCH),  //! The server process is running under a SID different than that required by client.
		_MakeErrorCodeName(ERROR_CANT_ENABLE_DENY_ONLY),  //! A group marked use for deny only cannot be enabled.
		_MakeErrorCodeName(ERROR_FLOAT_MULTIPLE_FAULTS),  //! {EXCEPTION} Multiple floating point faults.
		_MakeErrorCodeName(ERROR_FLOAT_MULTIPLE_TRAPS),  //! {EXCEPTION} Multiple floating point traps.
		_MakeErrorCodeName(ERROR_NOINTERFACE),  //! The requested interface is not supported.
		_MakeErrorCodeName(ERROR_DRIVER_FAILED_SLEEP),  //! {System Standby Failed} The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.
		_MakeErrorCodeName(ERROR_CORRUPT_SYSTEM_FILE),  //! The system file %1 has become corrupt and has been replaced.
		_MakeErrorCodeName(ERROR_COMMITMENT_MINIMUM),  //! {Virtual Memory Minimum Too Low} Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file. During this process, memory requests for some applications may be denied. For more information, see Help.
		_MakeErrorCodeName(ERROR_PNP_RESTART_ENUMERATION),  //! A device was removed so enumeration must be restarted.
		_MakeErrorCodeName(ERROR_SYSTEM_IMAGE_BAD_SIGNATURE),  //! {Fatal System Error} The system image %s is not properly signed. The file has been replaced with the signed file. The system has been shut down.
		_MakeErrorCodeName(ERROR_PNP_REBOOT_REQUIRED),  //! Device will not start without a reboot.
		_MakeErrorCodeName(ERROR_INSUFFICIENT_POWER),  //! There is not enough power to complete the requested operation.
		_MakeErrorCodeName(ERROR_MULTIPLE_FAULT_VIOLATION),  //! ERROR_MULTIPLE_FAULT_VIOLATION
		_MakeErrorCodeName(ERROR_SYSTEM_SHUTDOWN),  //! The system is in the process of shutting down.
		_MakeErrorCodeName(ERROR_PORT_NOT_SET),  //! An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.
		_MakeErrorCodeName(ERROR_DS_VERSION_CHECK_FAILURE),  //! This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.
		_MakeErrorCodeName(ERROR_RANGE_NOT_FOUND),  //! The specified range could not be found in the range list.
		_MakeErrorCodeName(ERROR_NOT_SAFE_MODE_DRIVER),  //! The driver was not loaded because the system is booting into safe mode.
		_MakeErrorCodeName(ERROR_FAILED_DRIVER_ENTRY),  //! The driver was not loaded because it failed its initialization call.
		_MakeErrorCodeName(ERROR_DEVICE_ENUMERATION_ERROR),  //! The "%hs" encountered an error while applying power or reading the device configuration. This may be caused by a failure of your hardware or by a poor connection.
		_MakeErrorCodeName(ERROR_MOUNT_POINT_NOT_RESOLVED),  //! The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
		_MakeErrorCodeName(ERROR_INVALID_DEVICE_OBJECT_PARAMETER),  //! The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
		_MakeErrorCodeName(ERROR_MCA_OCCURED),  //! A Machine Check Error has occurred. Please check the system eventlog for additional information.
		_MakeErrorCodeName(ERROR_DRIVER_DATABASE_ERROR),  //! There was error [%2] processing the driver database.
		_MakeErrorCodeName(ERROR_SYSTEM_HIVE_TOO_LARGE),  //! System hive size has exceeded its limit.
		_MakeErrorCodeName(ERROR_DRIVER_FAILED_PRIOR_UNLOAD),  //! The driver could not be loaded because a previous version of the driver is still in memory.
		_MakeErrorCodeName(ERROR_VOLSNAP_PREPARE_HIBERNATE),  //! {Volume Shadow Copy Service} Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
		_MakeErrorCodeName(ERROR_HIBERNATION_FAILURE),  //! The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.
		_MakeErrorCodeName(ERROR_PWD_TOO_LONG),  //! The password provided is too long to meet the policy of your user account. Please choose a shorter password.
		_MakeErrorCodeName(ERROR_FILE_SYSTEM_LIMITATION),  //! The requested operation could not be completed due to a file system limitation.
		_MakeErrorCodeName(ERROR_ASSERTION_FAILURE),  //! An assertion failure has occurred.
		_MakeErrorCodeName(ERROR_ACPI_ERROR),  //! An error occurred in the ACPI subsystem.
		_MakeErrorCodeName(ERROR_WOW_ASSERTION),  //! WOW Assertion Error.
		_MakeErrorCodeName(ERROR_PNP_BAD_MPS_TABLE),  //! A device is missing in the system BIOS MPS table. This device will not be used. Please contact your system vendor for system BIOS update.
		_MakeErrorCodeName(ERROR_PNP_TRANSLATION_FAILED),  //! A translator failed to translate resources.
		_MakeErrorCodeName(ERROR_PNP_IRQ_TRANSLATION_FAILED),  //! A IRQ translator failed to translate resources.
		_MakeErrorCodeName(ERROR_PNP_INVALID_ID),  //! Driver %2 returned invalid ID for a child device (%3).
		_MakeErrorCodeName(ERROR_WAKE_SYSTEM_DEBUGGER),  //! {Kernel Debugger Awakened} the system debugger was awakened by an interrupt.
		_MakeErrorCodeName(ERROR_HANDLES_CLOSED),  //! {Handles Closed} Handles to objects have been automatically closed as a result of the requested operation.
		_MakeErrorCodeName(ERROR_EXTRANEOUS_INFORMATION),  //! {Too Much Information} The specified access control list (ACL) contained more information than was expected.
		_MakeErrorCodeName(ERROR_RXACT_COMMIT_NECESSARY),  //! This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
		_MakeErrorCodeName(ERROR_MEDIA_CHECK),  //! {Media Changed} The media may have changed.
		_MakeErrorCodeName(ERROR_GUID_SUBSTITUTION_MADE),  //! {GUID Substitution} During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found. A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.
		_MakeErrorCodeName(ERROR_STOPPED_ON_SYMLINK),  //! The create operation stopped after reaching a symbolic link.
		_MakeErrorCodeName(ERROR_LONGJUMP),  //! A long jump has been executed.
		_MakeErrorCodeName(ERROR_PLUGPLAY_QUERY_VETOED),  //! The Plug and Play query operation was not successful.
		_MakeErrorCodeName(ERROR_UNWIND_CONSOLIDATE),  //! A frame consolidation has been executed.
		_MakeErrorCodeName(ERROR_REGISTRY_HIVE_RECOVERED),  //! {Registry Hive Recovered} Registry hive (file): %hs was corrupted and it has been recovered. Some data might have been lost.
		_MakeErrorCodeName(ERROR_DLL_MIGHT_BE_INSECURE),  //! The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?
		_MakeErrorCodeName(ERROR_DLL_MIGHT_BE_INCOMPATIBLE),  //! The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?
		_MakeErrorCodeName(ERROR_DBG_EXCEPTION_NOT_HANDLED),  //! Debugger did not handle the exception.
		_MakeErrorCodeName(ERROR_DBG_REPLY_LATER),  //! Debugger will reply later.
		_MakeErrorCodeName(ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE),  //! Debugger cannot provide handle.
		_MakeErrorCodeName(ERROR_DBG_TERMINATE_THREAD),  //! Debugger terminated thread.
		_MakeErrorCodeName(ERROR_DBG_TERMINATE_PROCESS),  //! Debugger terminated process.
		_MakeErrorCodeName(ERROR_DBG_CONTROL_C),  //! Debugger got control C.
		_MakeErrorCodeName(ERROR_DBG_PRINTEXCEPTION_C),  //! Debugger printed exception on control C.
		_MakeErrorCodeName(ERROR_DBG_RIPEXCEPTION),  //! Debugger received RIP exception.
		_MakeErrorCodeName(ERROR_DBG_CONTROL_BREAK),  //! Debugger received control break.
		_MakeErrorCodeName(ERROR_DBG_COMMAND_EXCEPTION),  //! Debugger command communication exception.
		_MakeErrorCodeName(ERROR_OBJECT_NAME_EXISTS),  //! {Object Exists} An attempt was made to create an object and the object name already existed.
		_MakeErrorCodeName(ERROR_THREAD_WAS_SUSPENDED),  //! {Thread Suspended} A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.
		_MakeErrorCodeName(ERROR_IMAGE_NOT_AT_BASE),  //! {Image Relocated} An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
		_MakeErrorCodeName(ERROR_RXACT_STATE_CREATED),  //! This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
		_MakeErrorCodeName(ERROR_SEGMENT_NOTIFICATION),  //! {Segment Load} A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image. An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
		_MakeErrorCodeName(ERROR_BAD_CURRENT_DIRECTORY),  //! {Invalid Current Directory} The process cannot switch to the startup current directory %hs. Select OK to set current directory to %hs, or select CANCEL to exit.
		_MakeErrorCodeName(ERROR_FT_READ_RECOVERY_FROM_BACKUP),  //! {Redundant Read} To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
		_MakeErrorCodeName(ERROR_FT_WRITE_RECOVERY),  //! {Redundant Write} To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
		_MakeErrorCodeName(ERROR_IMAGE_MACHINE_TYPE_MISMATCH),  //! {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.
		_MakeErrorCodeName(ERROR_RECEIVE_PARTIAL),  //! {Partial Data Received} The network transport returned partial data to its client. The remaining data will be sent later.
		_MakeErrorCodeName(ERROR_RECEIVE_EXPEDITED),  //! {Expedited Data Received} The network transport returned data to its client that was marked as expedited by the remote system.
		_MakeErrorCodeName(ERROR_RECEIVE_PARTIAL_EXPEDITED),  //! {Partial Expedited Data Received} The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
		_MakeErrorCodeName(ERROR_EVENT_DONE),  //! {TDI Event Done} The TDI indication has completed successfully.
		_MakeErrorCodeName(ERROR_EVENT_PENDING),  //! {TDI Event Pending} The TDI indication has entered the pending state.
		_MakeErrorCodeName(ERROR_CHECKING_FILE_SYSTEM),  //! Checking file system on %wZ.
		_MakeErrorCodeName(ERROR_FATAL_APP_EXIT),  //! {Fatal Application Exit} %hs.
		_MakeErrorCodeName(ERROR_PREDEFINED_HANDLE),  //! The specified registry key is referenced by a predefined handle.
		_MakeErrorCodeName(ERROR_WAS_UNLOCKED),  //! {Page Unlocked} The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
		_MakeErrorCodeName(ERROR_SERVICE_NOTIFICATION),  //! %hs
		_MakeErrorCodeName(ERROR_WAS_LOCKED),  //! {Page Locked} One of the pages to lock was already locked.
		_MakeErrorCodeName(ERROR_LOG_HARD_ERROR),  //! Application popup: %1 : %2
		_MakeErrorCodeName(ERROR_ALREADY_WIN32),  //! ERROR_ALREADY_WIN32
		_MakeErrorCodeName(ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE),  //! {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine.
		_MakeErrorCodeName(ERROR_NO_YIELD_PERFORMED),  //! A yield execution was performed and no thread was available to run.
		_MakeErrorCodeName(ERROR_TIMER_RESUME_IGNORED),  //! The resumable flag to a timer API was ignored.
		_MakeErrorCodeName(ERROR_ARBITRATION_UNHANDLED),  //! The arbiter has deferred arbitration of these resources to its parent.
		_MakeErrorCodeName(ERROR_CARDBUS_NOT_SUPPORTED),  //! The inserted CardBus device cannot be started because of a configuration error on "%hs".
		_MakeErrorCodeName(ERROR_MP_PROCESSOR_MISMATCH),  //! The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
		_MakeErrorCodeName(ERROR_HIBERNATED),  //! The system was put into hibernation.
		_MakeErrorCodeName(ERROR_RESUME_HIBERNATION),  //! The system was resumed from hibernation.
		_MakeErrorCodeName(ERROR_FIRMWARE_UPDATED),  //! Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
		_MakeErrorCodeName(ERROR_DRIVERS_LEAKING_LOCKED_PAGES),  //! A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.
		_MakeErrorCodeName(ERROR_WAKE_SYSTEM),  //! The system has awoken.
		_MakeErrorCodeName(ERROR_WAIT_1),  //! ERROR_WAIT_1
		_MakeErrorCodeName(ERROR_WAIT_2),  //! ERROR_WAIT_2
		_MakeErrorCodeName(ERROR_WAIT_3),  //! ERROR_WAIT_3
		_MakeErrorCodeName(ERROR_WAIT_63),  //! ERROR_WAIT_63
		_MakeErrorCodeName(ERROR_ABANDONED_WAIT_0),  //! ERROR_ABANDONED_WAIT_0
		_MakeErrorCodeName(ERROR_ABANDONED_WAIT_63),  //! ERROR_ABANDONED_WAIT_63
		_MakeErrorCodeName(ERROR_USER_APC),  //! ERROR_USER_APC
		_MakeErrorCodeName(ERROR_KERNEL_APC),  //! ERROR_KERNEL_APC
		_MakeErrorCodeName(ERROR_ALERTED),  //! ERROR_ALERTED
		_MakeErrorCodeName(ERROR_ELEVATION_REQUIRED),  //! The requested operation requires elevation.
		_MakeErrorCodeName(ERROR_REPARSE),  //! A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
		_MakeErrorCodeName(ERROR_OPLOCK_BREAK_IN_PROGRESS),  //! An open/create operation completed while an oplock break is underway.
		_MakeErrorCodeName(ERROR_VOLUME_MOUNTED),  //! A new volume has been mounted by a file system.
		_MakeErrorCodeName(ERROR_RXACT_COMMITTED),  //! This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has now been completed.
		_MakeErrorCodeName(ERROR_NOTIFY_CLEANUP),  //! This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
		_MakeErrorCodeName(ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED),  //! {Connect Failure on Primary Transport} An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed. The computer WAS able to connect on a secondary transport.
		_MakeErrorCodeName(ERROR_PAGE_FAULT_TRANSITION),  //! Page fault was a transition fault.
		_MakeErrorCodeName(ERROR_PAGE_FAULT_DEMAND_ZERO),  //! Page fault was a demand zero fault.
		_MakeErrorCodeName(ERROR_PAGE_FAULT_COPY_ON_WRITE),  //! Page fault was a demand zero fault.
		_MakeErrorCodeName(ERROR_PAGE_FAULT_GUARD_PAGE),  //! Page fault was a demand zero fault.
		_MakeErrorCodeName(ERROR_PAGE_FAULT_PAGING_FILE),  //! Page fault was satisfied by reading from a secondary storage device.
		_MakeErrorCodeName(ERROR_CACHE_PAGE_LOCKED),  //! Cached page was locked during operation.
		_MakeErrorCodeName(ERROR_CRASH_DUMP),  //! Crash dump exists in paging file.
		_MakeErrorCodeName(ERROR_BUFFER_ALL_ZEROS),  //! Specified buffer contains all zeros.
		_MakeErrorCodeName(ERROR_REPARSE_OBJECT),  //! A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
		_MakeErrorCodeName(ERROR_RESOURCE_REQUIREMENTS_CHANGED),  //! The device has succeeded a query-stop and its resource requirements have changed.
		_MakeErrorCodeName(ERROR_TRANSLATION_COMPLETE),  //! The translator has translated these resources into the global space and no further translations should be performed.
		_MakeErrorCodeName(ERROR_NOTHING_TO_TERMINATE),  //! A process being terminated has no threads to terminate.
		_MakeErrorCodeName(ERROR_PROCESS_NOT_IN_JOB),  //! The specified process is not part of a job.
		_MakeErrorCodeName(ERROR_PROCESS_IN_JOB),  //! The specified process is part of a job.
		_MakeErrorCodeName(ERROR_VOLSNAP_HIBERNATE_READY),  //! {Volume Shadow Copy Service} The system is now ready for hibernation.
		_MakeErrorCodeName(ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY),  //! A file system or file system filter driver has successfully completed an FsFilter operation.
		_MakeErrorCodeName(ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED),  //! The specified interrupt vector was already connected.
		_MakeErrorCodeName(ERROR_INTERRUPT_STILL_CONNECTED),  //! The specified interrupt vector is still connected.
		_MakeErrorCodeName(ERROR_WAIT_FOR_OPLOCK),  //! An operation is blocked waiting for an oplock.
		_MakeErrorCodeName(ERROR_DBG_EXCEPTION_HANDLED),  //! Debugger handled exception.
		_MakeErrorCodeName(ERROR_DBG_CONTINUE),  //! Debugger continued.
		_MakeErrorCodeName(ERROR_CALLBACK_POP_STACK),  //! An exception occurred in a user mode callback and the kernel callback frame should be removed.
		_MakeErrorCodeName(ERROR_COMPRESSION_DISABLED),  //! Compression is disabled for this volume.
		_MakeErrorCodeName(ERROR_CANTFETCHBACKWARDS),  //! The data provider cannot fetch backwards through a result set.
		_MakeErrorCodeName(ERROR_CANTSCROLLBACKWARDS),  //! The data provider cannot scroll backwards through a result set.
		_MakeErrorCodeName(ERROR_ROWSNOTRELEASED),  //! The data provider requires that previously fetched data is released before asking for more data.
		_MakeErrorCodeName(ERROR_BAD_ACCESSOR_FLAGS),  //! The data provider was not able to interpret the flags set for a column binding in an accessor.
		_MakeErrorCodeName(ERROR_ERRORS_ENCOUNTERED),  //! One or more errors occurred while processing the request.
		_MakeErrorCodeName(ERROR_NOT_CAPABLE),  //! The implementation is not capable of performing the request.
		_MakeErrorCodeName(ERROR_REQUEST_OUT_OF_SEQUENCE),  //! The client of a component requested an operation which is not valid given the state of the component instance.
		_MakeErrorCodeName(ERROR_VERSION_PARSE_ERROR),  //! A version number could not be parsed.
		_MakeErrorCodeName(ERROR_BADSTARTPOSITION),  //! The iterator's start position is invalid.
		_MakeErrorCodeName(ERROR_MEMORY_HARDWARE),  //! The hardware has reported an uncorrectable memory error.
		_MakeErrorCodeName(ERROR_DISK_REPAIR_DISABLED),  //! The attempted operation required self healing to be enabled.
		_MakeErrorCodeName(ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE),  //! The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.
		_MakeErrorCodeName(ERROR_SYSTEM_POWERSTATE_TRANSITION),  //! The system power state is transitioning from %2 to %3.
		_MakeErrorCodeName(ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION),  //! The system power state is transitioning from %2 to %3 but could enter %4.
		_MakeErrorCodeName(ERROR_MCA_EXCEPTION),  //! A thread is getting dispatched with MCA EXCEPTION because of MCA.
		_MakeErrorCodeName(ERROR_ACCESS_AUDIT_BY_POLICY),  //! Access to %1 is monitored by policy rule %2.
		_MakeErrorCodeName(ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY),  //! Access to %1 has been restricted by your Administrator by policy rule %2.
		_MakeErrorCodeName(ERROR_ABANDON_HIBERFILE),  //! A valid hibernation file has been invalidated and should be abandoned.
		_MakeErrorCodeName(ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED),  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error may be caused by network connectivity issues. Please try to save this file elsewhere.
		_MakeErrorCodeName(ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR),  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error was returned by the server on which the file exists. Please try to save this file elsewhere.
		_MakeErrorCodeName(ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR),  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error may be caused if the device has been removed or the media is write-protected.
		_MakeErrorCodeName(ERROR_BAD_MCFG_TABLE),  //! The resources required for this device conflict with the MCFG table.
		_MakeErrorCodeName(ERROR_DISK_REPAIR_REDIRECTED),  //! The volume repair could not be performed while it is online. Please schedule to take the volume offline so that it can be repaired.
		_MakeErrorCodeName(ERROR_DISK_REPAIR_UNSUCCESSFUL),  //! The volume repair was not successful.
		_MakeErrorCodeName(ERROR_CORRUPT_LOG_OVERFULL),  //! One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.
		_MakeErrorCodeName(ERROR_CORRUPT_LOG_CORRUPTED),  //! One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.
		_MakeErrorCodeName(ERROR_CORRUPT_LOG_UNAVAILABLE),  //! One of the volume corruption logs is unavailable for being operated on.
		_MakeErrorCodeName(ERROR_CORRUPT_LOG_DELETED_FULL),  //! One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.
		_MakeErrorCodeName(ERROR_CORRUPT_LOG_CLEARED),  //! One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.
		_MakeErrorCodeName(ERROR_ORPHAN_NAME_EXHAUSTED),  //! Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.
		_MakeErrorCodeName(ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE),  //! The oplock that was associated with this handle is now associated with a different handle.
		_MakeErrorCodeName(ERROR_CANNOT_GRANT_REQUESTED_OPLOCK),  //! An oplock of the requested level cannot be granted. An oplock of a lower level may be available.
		_MakeErrorCodeName(ERROR_CANNOT_BREAK_OPLOCK),  //! The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.
		_MakeErrorCodeName(ERROR_OPLOCK_HANDLE_CLOSED),  //! The handle with which this oplock was associated has been closed. The oplock is now broken.
		_MakeErrorCodeName(ERROR_NO_ACE_CONDITION),  //! The specified access control entry (ACE) does not contain a condition.
		_MakeErrorCodeName(ERROR_INVALID_ACE_CONDITION),  //! The specified access control entry (ACE) contains an invalid condition.
		_MakeErrorCodeName(ERROR_FILE_HANDLE_REVOKED),  //! Access to the specified file handle has been revoked.
		_MakeErrorCodeName(ERROR_IMAGE_AT_DIFFERENT_BASE),  //! An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.
		_MakeErrorCodeName(ERROR_EA_ACCESS_DENIED),  //! Access to the extended attribute was denied.
		_MakeErrorCodeName(ERROR_OPERATION_ABORTED),  //! The I/O operation has been aborted because of either a thread exit or an application request.
		_MakeErrorCodeName(ERROR_IO_INCOMPLETE),  //! Overlapped I/O event is not in a signaled state.
		_MakeErrorCodeName(ERROR_IO_PENDING),  //! Overlapped I/O operation is in progress.
		_MakeErrorCodeName(ERROR_NOACCESS),  //! Invalid access to memory location.
		_MakeErrorCodeName(ERROR_SWAPERROR),  //! Error performing inpage operation.
		_MakeErrorCodeName(ERROR_STACK_OVERFLOW),  //! Recursion too deep; the stack overflowed.
		_MakeErrorCodeName(ERROR_INVALID_MESSAGE),  //! The window cannot act on the sent message.
		_MakeErrorCodeName(ERROR_CAN_NOT_COMPLETE),  //! Cannot complete this function.
		_MakeErrorCodeName(ERROR_INVALID_FLAGS),  //! Invalid flags.
		_MakeErrorCodeName(ERROR_UNRECOGNIZED_VOLUME),  //! The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
		_MakeErrorCodeName(ERROR_FILE_INVALID),  //! The volume for a file has been externally altered so that the opened file is no longer valid.
		_MakeErrorCodeName(ERROR_FULLSCREEN_MODE),  //! The requested operation cannot be performed in full-screen mode.
		_MakeErrorCodeName(ERROR_NO_TOKEN),  //! An attempt was made to reference a token that does not exist.
		_MakeErrorCodeName(ERROR_BADDB),  //! The configuration registry database is corrupt.
		_MakeErrorCodeName(ERROR_BADKEY),  //! The configuration registry key is invalid.
		_MakeErrorCodeName(ERROR_CANTOPEN),  //! The configuration registry key could not be opened.
		_MakeErrorCodeName(ERROR_CANTREAD),  //! The configuration registry key could not be read.
		_MakeErrorCodeName(ERROR_CANTWRITE),  //! The configuration registry key could not be written.
		_MakeErrorCodeName(ERROR_REGISTRY_RECOVERED),  //! One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.
		_MakeErrorCodeName(ERROR_REGISTRY_CORRUPT),  //! The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.
		_MakeErrorCodeName(ERROR_REGISTRY_IO_FAILED),  //! An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.
		_MakeErrorCodeName(ERROR_NOT_REGISTRY_FILE),  //! The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.
		_MakeErrorCodeName(ERROR_KEY_DELETED),  //! Illegal operation attempted on a registry key that has been marked for deletion.
		_MakeErrorCodeName(ERROR_NO_LOG_SPACE),  //! System could not allocate the required space in a registry log.
		_MakeErrorCodeName(ERROR_KEY_HAS_CHILDREN),  //! Cannot create a symbolic link in a registry key that already has subkeys or values.
		_MakeErrorCodeName(ERROR_CHILD_MUST_BE_VOLATILE),  //! Cannot create a stable subkey under a volatile parent key.
		_MakeErrorCodeName(ERROR_NOTIFY_ENUM_DIR),  //! A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.
		_MakeErrorCodeName(ERROR_DEPENDENT_SERVICES_RUNNING),  //! A stop control has been sent to a service that other running services are dependent on.
		_MakeErrorCodeName(ERROR_INVALID_SERVICE_CONTROL),  //! The requested control is not valid for this service.
		_MakeErrorCodeName(ERROR_SERVICE_REQUEST_TIMEOUT),  //! The service did not respond to the start or control request in a timely fashion.
		_MakeErrorCodeName(ERROR_SERVICE_NO_THREAD),  //! A thread could not be created for the service.
		_MakeErrorCodeName(ERROR_SERVICE_DATABASE_LOCKED),  //! The service database is locked.
		_MakeErrorCodeName(ERROR_SERVICE_ALREADY_RUNNING),  //! An instance of the service is already running.
		_MakeErrorCodeName(ERROR_INVALID_SERVICE_ACCOUNT),  //! The account name is invalid or does not exist, or the password is invalid for the account name specified.
		_MakeErrorCodeName(ERROR_SERVICE_DISABLED),  //! The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.
		_MakeErrorCodeName(ERROR_CIRCULAR_DEPENDENCY),  //! Circular service dependency was specified.
		_MakeErrorCodeName(ERROR_SERVICE_DOES_NOT_EXIST),  //! The specified service does not exist as an installed service.
		_MakeErrorCodeName(ERROR_SERVICE_CANNOT_ACCEPT_CTRL),  //! The service cannot accept control messages at this time.
		_MakeErrorCodeName(ERROR_SERVICE_NOT_ACTIVE),  //! The service has not been started.
		_MakeErrorCodeName(ERROR_FAILED_SERVICE_CONTROLLER_CONNECT),  //! The service process could not connect to the service controller.
		_MakeErrorCodeName(ERROR_EXCEPTION_IN_SERVICE),  //! An exception occurred in the service when handling the control request.
		_MakeErrorCodeName(ERROR_DATABASE_DOES_NOT_EXIST),  //! The database specified does not exist.
		_MakeErrorCodeName(ERROR_SERVICE_SPECIFIC_ERROR),  //! The service has returned a service-specific error code.
		_MakeErrorCodeName(ERROR_PROCESS_ABORTED),  //! The process terminated unexpectedly.
		_MakeErrorCodeName(ERROR_SERVICE_DEPENDENCY_FAIL),  //! The dependency service or group failed to start.
		_MakeErrorCodeName(ERROR_SERVICE_LOGON_FAILED),  //! The service did not start due to a logon failure.
		_MakeErrorCodeName(ERROR_SERVICE_START_HANG),  //! After starting, the service hung in a start-pending state.
		_MakeErrorCodeName(ERROR_INVALID_SERVICE_LOCK),  //! The specified service database lock is invalid.
		_MakeErrorCodeName(ERROR_SERVICE_MARKED_FOR_DELETE),  //! The specified service has been marked for deletion.
		_MakeErrorCodeName(ERROR_SERVICE_EXISTS),  //! The specified service already exists.
		_MakeErrorCodeName(ERROR_ALREADY_RUNNING_LKG),  //! The system is currently running with the last-known-good configuration.
		_MakeErrorCodeName(ERROR_SERVICE_DEPENDENCY_DELETED),  //! The dependency service does not exist or has been marked for deletion.
		_MakeErrorCodeName(ERROR_BOOT_ALREADY_ACCEPTED),  //! The current boot has already been accepted for use as the last-known-good control set.
		_MakeErrorCodeName(ERROR_SERVICE_NEVER_STARTED),  //! No attempts to start the service have been made since the last boot.
		_MakeErrorCodeName(ERROR_DUPLICATE_SERVICE_NAME),  //! The name is already in use as either a service name or a service display name.
		_MakeErrorCodeName(ERROR_DIFFERENT_SERVICE_ACCOUNT),  //! The account specified for this service is different from the account specified for other services running in the same process.
		_MakeErrorCodeName(ERROR_CANNOT_DETECT_DRIVER_FAILURE),  //! Failure actions can only be set for Win32 services, not for drivers.
		_MakeErrorCodeName(ERROR_CANNOT_DETECT_PROCESS_ABORT),  //! This service runs in the same process as the service control manager. Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.
		_MakeErrorCodeName(ERROR_NO_RECOVERY_PROGRAM),  //! No recovery program has been configured for this service.
		_MakeErrorCodeName(ERROR_SERVICE_NOT_IN_EXE),  //! The executable program that this service is configured to run in does not implement the service.
		_MakeErrorCodeName(ERROR_NOT_SAFEBOOT_SERVICE),  //! This service cannot be started in Safe Mode.
		_MakeErrorCodeName(ERROR_END_OF_MEDIA),  //! The physical end of the tape has been reached.
		_MakeErrorCodeName(ERROR_FILEMARK_DETECTED),  //! A tape access reached a filemark.
		_MakeErrorCodeName(ERROR_BEGINNING_OF_MEDIA),  //! The beginning of the tape or a partition was encountered.
		_MakeErrorCodeName(ERROR_SETMARK_DETECTED),  //! A tape access reached the end of a set of files.
		_MakeErrorCodeName(ERROR_NO_DATA_DETECTED),  //! No more data is on the tape.
		_MakeErrorCodeName(ERROR_PARTITION_FAILURE),  //! Tape could not be partitioned.
		_MakeErrorCodeName(ERROR_INVALID_BLOCK_LENGTH),  //! When accessing a new tape of a multivolume partition, the current block size is incorrect.
		_MakeErrorCodeName(ERROR_DEVICE_NOT_PARTITIONED),  //! Tape partition information could not be found when loading a tape.
		_MakeErrorCodeName(ERROR_UNABLE_TO_LOCK_MEDIA),  //! Unable to lock the media eject mechanism.
		_MakeErrorCodeName(ERROR_UNABLE_TO_UNLOAD_MEDIA),  //! Unable to unload the media.
		_MakeErrorCodeName(ERROR_MEDIA_CHANGED),  //! The media in the drive may have changed.
		_MakeErrorCodeName(ERROR_BUS_RESET),  //! The I/O bus was reset.
		_MakeErrorCodeName(ERROR_NO_MEDIA_IN_DRIVE),  //! No media in drive.
		_MakeErrorCodeName(ERROR_NO_UNICODE_TRANSLATION),  //! No mapping for the Unicode character exists in the target multi-byte code page.
		_MakeErrorCodeName(ERROR_DLL_INIT_FAILED),  //! A dynamic link library (DLL) initialization routine failed.
		_MakeErrorCodeName(ERROR_SHUTDOWN_IN_PROGRESS),  //! A system shutdown is in progress.
		_MakeErrorCodeName(ERROR_NO_SHUTDOWN_IN_PROGRESS),  //! Unable to abort the system shutdown because no shutdown was in progress.
		_MakeErrorCodeName(ERROR_IO_DEVICE),  //! The request could not be performed because of an I/O device error.
		_MakeErrorCodeName(ERROR_SERIAL_NO_DEVICE),  //! No serial device was successfully initialized. The serial driver will unload.
		_MakeErrorCodeName(ERROR_IRQ_BUSY),  //! Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.
		_MakeErrorCodeName(ERROR_MORE_WRITES),  //! A serial I/O operation was completed by another write to the serial port. The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
		_MakeErrorCodeName(ERROR_COUNTER_TIMEOUT),  //! A serial I/O operation completed because the timeout period expired. The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
		_MakeErrorCodeName(ERROR_FLOPPY_ID_MARK_NOT_FOUND),  //! No ID address mark was found on the floppy disk.
		_MakeErrorCodeName(ERROR_FLOPPY_WRONG_CYLINDER),  //! Mismatch between the floppy disk sector ID field and the floppy disk controller track address.
		_MakeErrorCodeName(ERROR_FLOPPY_UNKNOWN_ERROR),  //! The floppy disk controller reported an error that is not recognized by the floppy disk driver.
		_MakeErrorCodeName(ERROR_FLOPPY_BAD_REGISTERS),  //! The floppy disk controller returned inconsistent results in its registers.
		_MakeErrorCodeName(ERROR_DISK_RECALIBRATE_FAILED),  //! While accessing the hard disk, a recalibrate operation failed, even after retries.
		_MakeErrorCodeName(ERROR_DISK_OPERATION_FAILED),  //! While accessing the hard disk, a disk operation failed even after retries.
		_MakeErrorCodeName(ERROR_DISK_RESET_FAILED),  //! While accessing the hard disk, a disk controller reset was needed, but even that failed.
		_MakeErrorCodeName(ERROR_EOM_OVERFLOW),  //! Physical end of tape encountered.
		_MakeErrorCodeName(ERROR_NOT_ENOUGH_SERVER_MEMORY),  //! Not enough server storage is available to process this command.
		_MakeErrorCodeName(ERROR_POSSIBLE_DEADLOCK),  //! A potential deadlock condition has been detected.
		_MakeErrorCodeName(ERROR_MAPPED_ALIGNMENT),  //! The base address or the file offset specified does not have the proper alignment.
		_MakeErrorCodeName(ERROR_SET_POWER_STATE_VETOED),  //! An attempt to change the system power state was vetoed by another application or driver.
		_MakeErrorCodeName(ERROR_SET_POWER_STATE_FAILED),  //! The system BIOS failed an attempt to change the system power state.
		_MakeErrorCodeName(ERROR_TOO_MANY_LINKS),  //! An attempt was made to create more links on a file than the file system supports.
		_MakeErrorCodeName(ERROR_OLD_WIN_VERSION),  //! The specified program requires a newer version of Windows.
		_MakeErrorCodeName(ERROR_APP_WRONG_OS),  //! The specified program is not a Windows or MS-DOS program.
		_MakeErrorCodeName(ERROR_SINGLE_INSTANCE_APP),  //! Cannot start more than one instance of the specified program.
		_MakeErrorCodeName(ERROR_RMODE_APP),  //! The specified program was written for an earlier version of Windows.
		_MakeErrorCodeName(ERROR_INVALID_DLL),  //! One of the library files needed to run this application is damaged.
		_MakeErrorCodeName(ERROR_NO_ASSOCIATION),  //! No application is associated with the specified file for this operation.
		_MakeErrorCodeName(ERROR_DDE_FAIL),  //! An error occurred in sending the command to the application.
		_MakeErrorCodeName(ERROR_DLL_NOT_FOUND),  //! One of the library files needed to run this application cannot be found.
		_MakeErrorCodeName(ERROR_NO_MORE_USER_HANDLES),  //! The current process has used all of its system allowance of handles for Window Manager objects.
		_MakeErrorCodeName(ERROR_MESSAGE_SYNC_ONLY),  //! The message can be used only with synchronous operations.
		_MakeErrorCodeName(ERROR_SOURCE_ELEMENT_EMPTY),  //! The indicated source element has no media.
		_MakeErrorCodeName(ERROR_DESTINATION_ELEMENT_FULL),  //! The indicated destination element already contains media.
		_MakeErrorCodeName(ERROR_ILLEGAL_ELEMENT_ADDRESS),  //! The indicated element does not exist.
		_MakeErrorCodeName(ERROR_MAGAZINE_NOT_PRESENT),  //! The indicated element is part of a magazine that is not present.
		_MakeErrorCodeName(ERROR_DEVICE_REINITIALIZATION_NEEDED),  //! The indicated device requires reinitialization due to hardware errors.
		_MakeErrorCodeName(ERROR_DEVICE_REQUIRES_CLEANING),  //! The device has indicated that cleaning is required before further operations are attempted.
		_MakeErrorCodeName(ERROR_DEVICE_DOOR_OPEN),  //! The device has indicated that its door is open.
		_MakeErrorCodeName(ERROR_DEVICE_NOT_CONNECTED),  //! The device is not connected.
		_MakeErrorCodeName(ERROR_NOT_FOUND),  //! Element not found.
		_MakeErrorCodeName(ERROR_NO_MATCH),  //! There was no match for the specified key in the index.
		_MakeErrorCodeName(ERROR_SET_NOT_FOUND),  //! The property set specified does not exist on the object.
		_MakeErrorCodeName(ERROR_POINT_NOT_FOUND),  //! The point passed to GetMouseMovePoints is not in the buffer.
		_MakeErrorCodeName(ERROR_NO_TRACKING_SERVICE),  //! The tracking (workstation) service is not running.
		_MakeErrorCodeName(ERROR_NO_VOLUME_ID),  //! The Volume ID could not be found.
		_MakeErrorCodeName(ERROR_UNABLE_TO_REMOVE_REPLACED),  //! Unable to remove the file to be replaced.
		_MakeErrorCodeName(ERROR_UNABLE_TO_MOVE_REPLACEMENT),  //! Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.
		_MakeErrorCodeName(ERROR_UNABLE_TO_MOVE_REPLACEMENT_2),  //! Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.
		_MakeErrorCodeName(ERROR_JOURNAL_DELETE_IN_PROGRESS),  //! The volume change journal is being deleted.
		_MakeErrorCodeName(ERROR_JOURNAL_NOT_ACTIVE),  //! The volume change journal is not active.
		_MakeErrorCodeName(ERROR_POTENTIAL_FILE_FOUND),  //! A file was found, but it may not be the correct file.
		_MakeErrorCodeName(ERROR_JOURNAL_ENTRY_DELETED),  //! The journal entry has been deleted from the journal.
		_MakeErrorCodeName(ERROR_SHUTDOWN_IS_SCHEDULED),  //! A system shutdown has already been scheduled.
		_MakeErrorCodeName(ERROR_SHUTDOWN_USERS_LOGGED_ON),  //! The system shutdown cannot be initiated because there are other users logged on to the computer.
		_MakeErrorCodeName(ERROR_BAD_DEVICE),  //! The specified device name is invalid.
		_MakeErrorCodeName(ERROR_CONNECTION_UNAVAIL),  //! The device is not currently connected but it is a remembered connection.
		_MakeErrorCodeName(ERROR_DEVICE_ALREADY_REMEMBERED),  //! The local device name has a remembered connection to another network resource.
		_MakeErrorCodeName(ERROR_NO_NET_OR_BAD_PATH),  //! The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.
		_MakeErrorCodeName(ERROR_BAD_PROVIDER),  //! The specified network provider name is invalid.
		_MakeErrorCodeName(ERROR_CANNOT_OPEN_PROFILE),  //! Unable to open the network connection profile.
		_MakeErrorCodeName(ERROR_BAD_PROFILE),  //! The network connection profile is corrupted.
		_MakeErrorCodeName(ERROR_NOT_CONTAINER),  //! Cannot enumerate a noncontainer.
		_MakeErrorCodeName(ERROR_EXTENDED_ERROR),  //! An extended error has occurred.
		_MakeErrorCodeName(ERROR_INVALID_GROUPNAME),  //! The format of the specified group name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_COMPUTERNAME),  //! The format of the specified computer name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_EVENTNAME),  //! The format of the specified event name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_DOMAINNAME),  //! The format of the specified domain name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_SERVICENAME),  //! The format of the specified service name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_NETNAME),  //! The format of the specified network name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_SHARENAME),  //! The format of the specified share name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_PASSWORDNAME),  //! The format of the specified password is invalid.
		_MakeErrorCodeName(ERROR_INVALID_MESSAGENAME),  //! The format of the specified message name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_MESSAGEDEST),  //! The format of the specified message destination is invalid.
		_MakeErrorCodeName(ERROR_SESSION_CREDENTIAL_CONFLICT),  //! Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.
		_MakeErrorCodeName(ERROR_REMOTE_SESSION_LIMIT_EXCEEDED),  //! An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.
		_MakeErrorCodeName(ERROR_DUP_DOMAINNAME),  //! The workgroup or domain name is already in use by another computer on the network.
		_MakeErrorCodeName(ERROR_NO_NETWORK),  //! The network is not present or not started.
		_MakeErrorCodeName(ERROR_CANCELLED),  //! The operation was canceled by the user.
		_MakeErrorCodeName(ERROR_USER_MAPPED_FILE),  //! The requested operation cannot be performed on a file with a user-mapped section open.
		_MakeErrorCodeName(ERROR_CONNECTION_REFUSED),  //! The remote computer refused the network connection.
		_MakeErrorCodeName(ERROR_GRACEFUL_DISCONNECT),  //! The network connection was gracefully closed.
		_MakeErrorCodeName(ERROR_ADDRESS_ALREADY_ASSOCIATED),  //! The network transport endpoint already has an address associated with it.
		_MakeErrorCodeName(ERROR_ADDRESS_NOT_ASSOCIATED),  //! An address has not yet been associated with the network endpoint.
		_MakeErrorCodeName(ERROR_CONNECTION_INVALID),  //! An operation was attempted on a nonexistent network connection.
		_MakeErrorCodeName(ERROR_CONNECTION_ACTIVE),  //! An invalid operation was attempted on an active network connection.
		_MakeErrorCodeName(ERROR_NETWORK_UNREACHABLE),  //! The network location cannot be reached. For information about network troubleshooting, see Windows Help.
		_MakeErrorCodeName(ERROR_HOST_UNREACHABLE),  //! The network location cannot be reached. For information about network troubleshooting, see Windows Help.
		_MakeErrorCodeName(ERROR_PROTOCOL_UNREACHABLE),  //! The network location cannot be reached. For information about network troubleshooting, see Windows Help.
		_MakeErrorCodeName(ERROR_PORT_UNREACHABLE),  //! No service is operating at the destination network endpoint on the remote system.
		_MakeErrorCodeName(ERROR_REQUEST_ABORTED),  //! The request was aborted.
		_MakeErrorCodeName(ERROR_CONNECTION_ABORTED),  //! The network connection was aborted by the local system.
		_MakeErrorCodeName(ERROR_RETRY),  //! The operation could not be completed. A retry should be performed.
		_MakeErrorCodeName(ERROR_CONNECTION_COUNT_LIMIT),  //! A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.
		_MakeErrorCodeName(ERROR_LOGIN_TIME_RESTRICTION),  //! Attempting to log in during an unauthorized time of day for this account.
		_MakeErrorCodeName(ERROR_LOGIN_WKSTA_RESTRICTION),  //! The account is not authorized to log in from this station.
		_MakeErrorCodeName(ERROR_INCORRECT_ADDRESS),  //! The network address could not be used for the operation requested.
		_MakeErrorCodeName(ERROR_ALREADY_REGISTERED),  //! The service is already registered.
		_MakeErrorCodeName(ERROR_SERVICE_NOT_FOUND),  //! The specified service does not exist.
		_MakeErrorCodeName(ERROR_NOT_AUTHENTICATED),  //! The operation being requested was not performed because the user has not been authenticated.
		_MakeErrorCodeName(ERROR_NOT_LOGGED_ON),  //! The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.
		_MakeErrorCodeName(ERROR_CONTINUE),  //! Continue with work in progress.
		_MakeErrorCodeName(ERROR_ALREADY_INITIALIZED),  //! An attempt was made to perform an initialization operation when initialization has already been completed.
		_MakeErrorCodeName(ERROR_NO_MORE_DEVICES),  //! No more local devices.
		_MakeErrorCodeName(ERROR_NO_SUCH_SITE),  //! The specified site does not exist.
		_MakeErrorCodeName(ERROR_DOMAIN_CONTROLLER_EXISTS),  //! A domain controller with the specified name already exists.
		_MakeErrorCodeName(ERROR_ONLY_IF_CONNECTED),  //! This operation is supported only when you are connected to the server.
		_MakeErrorCodeName(ERROR_OVERRIDE_NOCHANGES),  //! The group policy framework should call the extension even if there are no changes.
		_MakeErrorCodeName(ERROR_BAD_USER_PROFILE),  //! The specified user does not have a valid profile.
		_MakeErrorCodeName(ERROR_NOT_SUPPORTED_ON_SBS),  //! This operation is not supported on a computer running Windows Server 2003 for Small Business Server.
		_MakeErrorCodeName(ERROR_SERVER_SHUTDOWN_IN_PROGRESS),  //! The server machine is shutting down.
		_MakeErrorCodeName(ERROR_HOST_DOWN),  //! The remote system is not available. For information about network troubleshooting, see Windows Help.
		_MakeErrorCodeName(ERROR_NON_ACCOUNT_SID),  //! The security identifier provided is not from an account domain.
		_MakeErrorCodeName(ERROR_NON_DOMAIN_SID),  //! The security identifier provided does not have a domain component.
		_MakeErrorCodeName(ERROR_APPHELP_BLOCK),  //! AppHelp dialog canceled thus preventing the application from starting.
		_MakeErrorCodeName(ERROR_ACCESS_DISABLED_BY_POLICY),  //! This program is blocked by group policy. For more information, contact your system administrator.
		_MakeErrorCodeName(ERROR_REG_NAT_CONSUMPTION),  //! A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.
		_MakeErrorCodeName(ERROR_CSCSHARE_OFFLINE),  //! The share is currently offline or does not exist.
		_MakeErrorCodeName(ERROR_PKINIT_FAILURE),  //! The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.
		_MakeErrorCodeName(ERROR_SMARTCARD_SUBSYSTEM_FAILURE),  //! The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.
		_MakeErrorCodeName(ERROR_DOWNGRADE_DETECTED),  //! The system cannot contact a domain controller to service the authentication request. Please try again later.
		_MakeErrorCodeName(ERROR_MACHINE_LOCKED),  //! The machine is locked and cannot be shut down without the force option.
		_MakeErrorCodeName(ERROR_CALLBACK_SUPPLIED_INVALID_DATA),  //! An application-defined callback gave invalid data when called.
		_MakeErrorCodeName(ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED),  //! The group policy framework should call the extension in the synchronous foreground policy refresh.
		_MakeErrorCodeName(ERROR_DRIVER_BLOCKED),  //! This driver has been blocked from loading.
		_MakeErrorCodeName(ERROR_INVALID_IMPORT_OF_NON_DLL),  //! A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.
		_MakeErrorCodeName(ERROR_ACCESS_DISABLED_WEBBLADE),  //! Windows cannot open this program since it has been disabled.
		_MakeErrorCodeName(ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER),  //! Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.
		_MakeErrorCodeName(ERROR_RECOVERY_FAILURE),  //! A transaction recover failed.
		_MakeErrorCodeName(ERROR_ALREADY_FIBER),  //! The current thread has already been converted to a fiber.
		_MakeErrorCodeName(ERROR_ALREADY_THREAD),  //! The current thread has already been converted from a fiber.
		_MakeErrorCodeName(ERROR_STACK_BUFFER_OVERRUN),  //! The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.
		_MakeErrorCodeName(ERROR_PARAMETER_QUOTA_EXCEEDED),  //! Data present in one of the parameters is more than the function can operate on.
		_MakeErrorCodeName(ERROR_DEBUGGER_INACTIVE),  //! An attempt to do an operation on a debug object failed because the object is in the process of being deleted.
		_MakeErrorCodeName(ERROR_DELAY_LOAD_FAILED),  //! An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.
		_MakeErrorCodeName(ERROR_VDM_DISALLOWED),  //! %1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.
		_MakeErrorCodeName(ERROR_UNIDENTIFIED_ERROR),  //! Insufficient information exists to identify the cause of failure.
		_MakeErrorCodeName(ERROR_INVALID_CRUNTIME_PARAMETER),  //! The parameter passed to a C runtime function is incorrect.
		_MakeErrorCodeName(ERROR_BEYOND_VDL),  //! The operation occurred beyond the valid data length of the file.
		_MakeErrorCodeName(ERROR_INCOMPATIBLE_SERVICE_SID_TYPE),  //! The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.
		_MakeErrorCodeName(ERROR_DRIVER_PROCESS_TERMINATED),  //! The process hosting the driver for this device has been terminated.
		_MakeErrorCodeName(ERROR_IMPLEMENTATION_LIMIT),  //! An operation attempted to exceed an implementation-defined limit.
		_MakeErrorCodeName(ERROR_PROCESS_IS_PROTECTED),  //! Either the target process, or the target thread's containing process, is a protected process.
		_MakeErrorCodeName(ERROR_SERVICE_NOTIFY_CLIENT_LAGGING),  //! The service notification client is lagging too far behind the current state of services in the machine.
		_MakeErrorCodeName(ERROR_DISK_QUOTA_EXCEEDED),  //! The requested file operation failed because the storage quota was exceeded. To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.
		_MakeErrorCodeName(ERROR_CONTENT_BLOCKED),  //! The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.
		_MakeErrorCodeName(ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE),  //! A privilege that the service requires to function properly does not exist in the service account configuration. You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.
		_MakeErrorCodeName(ERROR_APP_HANG),  //! A thread involved in this operation appears to be unresponsive.
		_MakeErrorCodeName(ERROR_INVALID_LABEL),  //! Indicates a particular Security ID may not be assigned as the label of an object.
		_MakeErrorCodeName(ERROR_NOT_ALL_ASSIGNED),  //! Not all privileges or groups referenced are assigned to the caller.
		_MakeErrorCodeName(ERROR_SOME_NOT_MAPPED),  //! Some mapping between account names and security IDs was not done.
		_MakeErrorCodeName(ERROR_NO_QUOTAS_FOR_ACCOUNT),  //! No system quota limits are specifically set for this account.
		_MakeErrorCodeName(ERROR_LOCAL_USER_SESSION_KEY),  //! No encryption key is available. A well-known encryption key was returned.
		_MakeErrorCodeName(ERROR_NULL_LM_PASSWORD),  //! The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.
		_MakeErrorCodeName(ERROR_UNKNOWN_REVISION),  //! The revision level is unknown.
		_MakeErrorCodeName(ERROR_REVISION_MISMATCH),  //! Indicates two revision levels are incompatible.
		_MakeErrorCodeName(ERROR_INVALID_OWNER),  //! This security ID may not be assigned as the owner of this object.
		_MakeErrorCodeName(ERROR_INVALID_PRIMARY_GROUP),  //! This security ID may not be assigned as the primary group of an object.
		_MakeErrorCodeName(ERROR_NO_IMPERSONATION_TOKEN),  //! An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.
		_MakeErrorCodeName(ERROR_CANT_DISABLE_MANDATORY),  //! The group may not be disabled.
		_MakeErrorCodeName(ERROR_NO_LOGON_SERVERS),  //! There are currently no logon servers available to service the logon request.
		_MakeErrorCodeName(ERROR_NO_SUCH_LOGON_SESSION),  //! A specified logon session does not exist. It may already have been terminated.
		_MakeErrorCodeName(ERROR_NO_SUCH_PRIVILEGE),  //! A specified privilege does not exist.
		_MakeErrorCodeName(ERROR_PRIVILEGE_NOT_HELD),  //! A required privilege is not held by the client.
		_MakeErrorCodeName(ERROR_INVALID_ACCOUNT_NAME),  //! The name provided is not a properly formed account name.
		_MakeErrorCodeName(ERROR_USER_EXISTS),  //! The specified account already exists.
		_MakeErrorCodeName(ERROR_NO_SUCH_USER),  //! The specified account does not exist.
		_MakeErrorCodeName(ERROR_GROUP_EXISTS),  //! The specified group already exists.
		_MakeErrorCodeName(ERROR_NO_SUCH_GROUP),  //! The specified group does not exist.
		_MakeErrorCodeName(ERROR_MEMBER_IN_GROUP),  //! Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.
		_MakeErrorCodeName(ERROR_MEMBER_NOT_IN_GROUP),  //! The specified user account is not a member of the specified group account.
		_MakeErrorCodeName(ERROR_LAST_ADMIN),  //! This operation is disallowed as it could result in an administration account being disabled, deleted or unable to log on.
		_MakeErrorCodeName(ERROR_WRONG_PASSWORD),  //! Unable to update the password. The value provided as the current password is incorrect.
		_MakeErrorCodeName(ERROR_ILL_FORMED_PASSWORD),  //! Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.
		_MakeErrorCodeName(ERROR_PASSWORD_RESTRICTION),  //! Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.
		_MakeErrorCodeName(ERROR_LOGON_FAILURE),  //! The user name or password is incorrect.
		_MakeErrorCodeName(ERROR_ACCOUNT_RESTRICTION),  //! Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.
		_MakeErrorCodeName(ERROR_INVALID_LOGON_HOURS),  //! Your account has time restrictions that keep you from signing in right now.
		_MakeErrorCodeName(ERROR_INVALID_WORKSTATION),  //! This user isn't allowed to sign in to this computer.
		_MakeErrorCodeName(ERROR_PASSWORD_EXPIRED),  //! The password for this account has expired.
		_MakeErrorCodeName(ERROR_ACCOUNT_DISABLED),  //! This user can't sign in because this account is currently disabled.
		_MakeErrorCodeName(ERROR_NONE_MAPPED),  //! No mapping between account names and security IDs was done.
		_MakeErrorCodeName(ERROR_TOO_MANY_LUIDS_REQUESTED),  //! Too many local user identifiers (LUIDs) were requested at one time.
		_MakeErrorCodeName(ERROR_LUIDS_EXHAUSTED),  //! No more local user identifiers (LUIDs) are available.
		_MakeErrorCodeName(ERROR_INVALID_SUB_AUTHORITY),  //! The subauthority part of a security ID is invalid for this particular use.
		_MakeErrorCodeName(ERROR_INVALID_ACL),  //! The access control list (ACL) structure is invalid.
		_MakeErrorCodeName(ERROR_INVALID_SID),  //! The security ID structure is invalid.
		_MakeErrorCodeName(ERROR_INVALID_SECURITY_DESCR),  //! The security descriptor structure is invalid.
		_MakeErrorCodeName(ERROR_BAD_INHERITANCE_ACL),  //! The inherited access control list (ACL) or access control entry (ACE) could not be built.
		_MakeErrorCodeName(ERROR_SERVER_DISABLED),  //! The server is currently disabled.
		_MakeErrorCodeName(ERROR_SERVER_NOT_DISABLED),  //! The server is currently enabled.
		_MakeErrorCodeName(ERROR_INVALID_ID_AUTHORITY),  //! The value provided was an invalid value for an identifier authority.
		_MakeErrorCodeName(ERROR_ALLOTTED_SPACE_EXCEEDED),  //! No more memory is available for security information updates.
		_MakeErrorCodeName(ERROR_INVALID_GROUP_ATTRIBUTES),  //! The specified attributes are invalid, or incompatible with the attributes for the group as a whole.
		_MakeErrorCodeName(ERROR_BAD_IMPERSONATION_LEVEL),  //! Either a required impersonation level was not provided, or the provided impersonation level is invalid.
		_MakeErrorCodeName(ERROR_CANT_OPEN_ANONYMOUS),  //! Cannot open an anonymous level security token.
		_MakeErrorCodeName(ERROR_BAD_VALIDATION_CLASS),  //! The validation information class requested was invalid.
		_MakeErrorCodeName(ERROR_BAD_TOKEN_TYPE),  //! The type of the token is inappropriate for its attempted use.
		_MakeErrorCodeName(ERROR_NO_SECURITY_ON_OBJECT),  //! Unable to perform a security operation on an object that has no associated security.
		_MakeErrorCodeName(ERROR_CANT_ACCESS_DOMAIN_INFO),  //! Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.
		_MakeErrorCodeName(ERROR_INVALID_SERVER_STATE),  //! The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.
		_MakeErrorCodeName(ERROR_INVALID_DOMAIN_STATE),  //! The domain was in the wrong state to perform the security operation.
		_MakeErrorCodeName(ERROR_INVALID_DOMAIN_ROLE),  //! This operation is only allowed for the Primary Domain Controller of the domain.
		_MakeErrorCodeName(ERROR_NO_SUCH_DOMAIN),  //! The specified domain either does not exist or could not be contacted.
		_MakeErrorCodeName(ERROR_DOMAIN_EXISTS),  //! The specified domain already exists.
		_MakeErrorCodeName(ERROR_DOMAIN_LIMIT_EXCEEDED),  //! An attempt was made to exceed the limit on the number of domains per server.
		_MakeErrorCodeName(ERROR_INTERNAL_DB_CORRUPTION),  //! Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.
		_MakeErrorCodeName(ERROR_INTERNAL_ERROR),  //! An internal error occurred.
		_MakeErrorCodeName(ERROR_GENERIC_NOT_MAPPED),  //! Generic access types were contained in an access mask which should already be mapped to nongeneric types.
		_MakeErrorCodeName(ERROR_BAD_DESCRIPTOR_FORMAT),  //! A security descriptor is not in the right format (absolute or self-relative).
		_MakeErrorCodeName(ERROR_NOT_LOGON_PROCESS),  //! The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.
		_MakeErrorCodeName(ERROR_LOGON_SESSION_EXISTS),  //! Cannot start a new logon session with an ID that is already in use.
		_MakeErrorCodeName(ERROR_NO_SUCH_PACKAGE),  //! A specified authentication package is unknown.
		_MakeErrorCodeName(ERROR_BAD_LOGON_SESSION_STATE),  //! The logon session is not in a state that is consistent with the requested operation.
		_MakeErrorCodeName(ERROR_LOGON_SESSION_COLLISION),  //! The logon session ID is already in use.
		_MakeErrorCodeName(ERROR_INVALID_LOGON_TYPE),  //! A logon request contained an invalid logon type value.
		_MakeErrorCodeName(ERROR_CANNOT_IMPERSONATE),  //! Unable to impersonate using a named pipe until data has been read from that pipe.
		_MakeErrorCodeName(ERROR_RXACT_INVALID_STATE),  //! The transaction state of a registry subtree is incompatible with the requested operation.
		_MakeErrorCodeName(ERROR_RXACT_COMMIT_FAILURE),  //! An internal security database corruption has been encountered.
		_MakeErrorCodeName(ERROR_SPECIAL_ACCOUNT),  //! Cannot perform this operation on built-in accounts.
		_MakeErrorCodeName(ERROR_SPECIAL_GROUP),  //! Cannot perform this operation on this built-in special group.
		_MakeErrorCodeName(ERROR_SPECIAL_USER),  //! Cannot perform this operation on this built-in special user.
		_MakeErrorCodeName(ERROR_MEMBERS_PRIMARY_GROUP),  //! The user cannot be removed from a group because the group is currently the user's primary group.
		_MakeErrorCodeName(ERROR_TOKEN_ALREADY_IN_USE),  //! The token is already in use as a primary token.
		_MakeErrorCodeName(ERROR_NO_SUCH_ALIAS),  //! The specified local group does not exist.
		_MakeErrorCodeName(ERROR_MEMBER_NOT_IN_ALIAS),  //! The specified account name is not a member of the group.
		_MakeErrorCodeName(ERROR_MEMBER_IN_ALIAS),  //! The specified account name is already a member of the group.
		_MakeErrorCodeName(ERROR_ALIAS_EXISTS),  //! The specified local group already exists.
		_MakeErrorCodeName(ERROR_LOGON_NOT_GRANTED),  //! Logon failure: the user has not been granted the requested logon type at this computer.
		_MakeErrorCodeName(ERROR_TOO_MANY_SECRETS),  //! The maximum number of secrets that may be stored in a single system has been exceeded.
		_MakeErrorCodeName(ERROR_SECRET_TOO_LONG),  //! The length of a secret exceeds the maximum length allowed.
		_MakeErrorCodeName(ERROR_INTERNAL_DB_ERROR),  //! The local security authority database contains an internal inconsistency.
		_MakeErrorCodeName(ERROR_TOO_MANY_CONTEXT_IDS),  //! During a logon attempt, the user's security context accumulated too many security IDs.
		_MakeErrorCodeName(ERROR_LOGON_TYPE_NOT_GRANTED),  //! Logon failure: the user has not been granted the requested logon type at this computer.
		_MakeErrorCodeName(ERROR_NT_CROSS_ENCRYPTION_REQUIRED),  //! A cross-encrypted password is necessary to change a user password.
		_MakeErrorCodeName(ERROR_NO_SUCH_MEMBER),  //! A member could not be added to or removed from the local group because the member does not exist.
		_MakeErrorCodeName(ERROR_INVALID_MEMBER),  //! A new member could not be added to a local group because the member has the wrong account type.
		_MakeErrorCodeName(ERROR_TOO_MANY_SIDS),  //! Too many security IDs have been specified.
		_MakeErrorCodeName(ERROR_LM_CROSS_ENCRYPTION_REQUIRED),  //! A cross-encrypted password is necessary to change this user password.
		_MakeErrorCodeName(ERROR_NO_INHERITANCE),  //! Indicates an ACL contains no inheritable components.
		_MakeErrorCodeName(ERROR_FILE_CORRUPT),  //! The file or directory is corrupted and unreadable.
		_MakeErrorCodeName(ERROR_DISK_CORRUPT),  //! The disk structure is corrupted and unreadable.
		_MakeErrorCodeName(ERROR_NO_USER_SESSION_KEY),  //! There is no user session key for the specified logon session.
		_MakeErrorCodeName(ERROR_LICENSE_QUOTA_EXCEEDED),  //! The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.
		_MakeErrorCodeName(ERROR_WRONG_TARGET_NAME),  //! The target account name is incorrect.
		_MakeErrorCodeName(ERROR_MUTUAL_AUTH_FAILED),  //! Mutual Authentication failed. The server's password is out of date at the domain controller.
		_MakeErrorCodeName(ERROR_TIME_SKEW),  //! There is a time and/or date difference between the client and server.
		_MakeErrorCodeName(ERROR_CURRENT_DOMAIN_NOT_ALLOWED),  //! This operation cannot be performed on the current domain.
		_MakeErrorCodeName(ERROR_INVALID_WINDOW_HANDLE),  //! Invalid window handle.
		_MakeErrorCodeName(ERROR_INVALID_MENU_HANDLE),  //! Invalid menu handle.
		_MakeErrorCodeName(ERROR_INVALID_CURSOR_HANDLE),  //! Invalid cursor handle.
		_MakeErrorCodeName(ERROR_INVALID_ACCEL_HANDLE),  //! Invalid accelerator table handle.
		_MakeErrorCodeName(ERROR_INVALID_HOOK_HANDLE),  //! Invalid hook handle.
		_MakeErrorCodeName(ERROR_INVALID_DWP_HANDLE),  //! Invalid handle to a multiple-window position structure.
		_MakeErrorCodeName(ERROR_TLW_WITH_WSCHILD),  //! Cannot create a top-level child window.
		_MakeErrorCodeName(ERROR_CANNOT_FIND_WND_CLASS),  //! Cannot find window class.
		_MakeErrorCodeName(ERROR_WINDOW_OF_OTHER_THREAD),  //! Invalid window; it belongs to other thread.
		_MakeErrorCodeName(ERROR_HOTKEY_ALREADY_REGISTERED),  //! Hot key is already registered.
		_MakeErrorCodeName(ERROR_CLASS_ALREADY_EXISTS),  //! Class already exists.
		_MakeErrorCodeName(ERROR_CLASS_DOES_NOT_EXIST),  //! Class does not exist.
		_MakeErrorCodeName(ERROR_CLASS_HAS_WINDOWS),  //! Class still has open windows.
		_MakeErrorCodeName(ERROR_INVALID_INDEX),  //! Invalid index.
		_MakeErrorCodeName(ERROR_INVALID_ICON_HANDLE),  //! Invalid icon handle.
		_MakeErrorCodeName(ERROR_PRIVATE_DIALOG_INDEX),  //! Using private DIALOG window words.
		_MakeErrorCodeName(ERROR_LISTBOX_ID_NOT_FOUND),  //! The list box identifier was not found.
		_MakeErrorCodeName(ERROR_NO_WILDCARD_CHARACTERS),  //! No wildcards were found.
		_MakeErrorCodeName(ERROR_CLIPBOARD_NOT_OPEN),  //! Thread does not have a clipboard open.
		_MakeErrorCodeName(ERROR_HOTKEY_NOT_REGISTERED),  //! Hot key is not registered.
		_MakeErrorCodeName(ERROR_WINDOW_NOT_DIALOG),  //! The window is not a valid dialog window.
		_MakeErrorCodeName(ERROR_CONTROL_ID_NOT_FOUND),  //! Control ID not found.
		_MakeErrorCodeName(ERROR_INVALID_COMBOBOX_MESSAGE),  //! Invalid message for a combo box because it does not have an edit control.
		_MakeErrorCodeName(ERROR_WINDOW_NOT_COMBOBOX),  //! The window is not a combo box.
		_MakeErrorCodeName(ERROR_INVALID_EDIT_HEIGHT),  //! Height must be less than 256.
		_MakeErrorCodeName(ERROR_DC_NOT_FOUND),  //! Invalid device context (DC) handle.
		_MakeErrorCodeName(ERROR_INVALID_HOOK_FILTER),  //! Invalid hook procedure type.
		_MakeErrorCodeName(ERROR_INVALID_FILTER_PROC),  //! Invalid hook procedure.
		_MakeErrorCodeName(ERROR_HOOK_NEEDS_HMOD),  //! Cannot set nonlocal hook without a module handle.
		_MakeErrorCodeName(ERROR_GLOBAL_ONLY_HOOK),  //! This hook procedure can only be set globally.
		_MakeErrorCodeName(ERROR_JOURNAL_HOOK_SET),  //! The journal hook procedure is already installed.
		_MakeErrorCodeName(ERROR_HOOK_NOT_INSTALLED),  //! The hook procedure is not installed.
		_MakeErrorCodeName(ERROR_INVALID_LB_MESSAGE),  //! Invalid message for single-selection list box.
		_MakeErrorCodeName(ERROR_SETCOUNT_ON_BAD_LB),  //! LB_SETCOUNT sent to non-lazy list box.
		_MakeErrorCodeName(ERROR_LB_WITHOUT_TABSTOPS),  //! This list box does not support tab stops.
		_MakeErrorCodeName(ERROR_DESTROY_OBJECT_OF_OTHER_THREAD),  //! Cannot destroy object created by another thread.
		_MakeErrorCodeName(ERROR_CHILD_WINDOW_MENU),  //! Child windows cannot have menus.
		_MakeErrorCodeName(ERROR_NO_SYSTEM_MENU),  //! The window does not have a system menu.
		_MakeErrorCodeName(ERROR_INVALID_MSGBOX_STYLE),  //! Invalid message box style.
		_MakeErrorCodeName(ERROR_INVALID_SPI_VALUE),  //! Invalid system-wide (SPI_*) parameter.
		_MakeErrorCodeName(ERROR_SCREEN_ALREADY_LOCKED),  //! Screen already locked.
		_MakeErrorCodeName(ERROR_HWNDS_HAVE_DIFF_PARENT),  //! All handles to windows in a multiple-window position structure must have the same parent.
		_MakeErrorCodeName(ERROR_NOT_CHILD_WINDOW),  //! The window is not a child window.
		_MakeErrorCodeName(ERROR_INVALID_GW_COMMAND),  //! Invalid GW_* command.
		_MakeErrorCodeName(ERROR_INVALID_THREAD_ID),  //! Invalid thread identifier.
		_MakeErrorCodeName(ERROR_NON_MDICHILD_WINDOW),  //! Cannot process a message from a window that is not a multiple document interface (MDI) window.
		_MakeErrorCodeName(ERROR_POPUP_ALREADY_ACTIVE),  //! Popup menu already active.
		_MakeErrorCodeName(ERROR_NO_SCROLLBARS),  //! The window does not have scroll bars.
		_MakeErrorCodeName(ERROR_INVALID_SCROLLBAR_RANGE),  //! Scroll bar range cannot be greater than MAXLONG.
		_MakeErrorCodeName(ERROR_INVALID_SHOWWIN_COMMAND),  //! Cannot show or remove the window in the way specified.
		_MakeErrorCodeName(ERROR_NO_SYSTEM_RESOURCES),  //! Insufficient system resources exist to complete the requested service.
		_MakeErrorCodeName(ERROR_NONPAGED_SYSTEM_RESOURCES),  //! Insufficient system resources exist to complete the requested service.
		_MakeErrorCodeName(ERROR_PAGED_SYSTEM_RESOURCES),  //! Insufficient system resources exist to complete the requested service.
		_MakeErrorCodeName(ERROR_WORKING_SET_QUOTA),  //! Insufficient quota to complete the requested service.
		_MakeErrorCodeName(ERROR_PAGEFILE_QUOTA),  //! Insufficient quota to complete the requested service.
		_MakeErrorCodeName(ERROR_COMMITMENT_LIMIT),  //! The paging file is too small for this operation to complete.
		_MakeErrorCodeName(ERROR_MENU_ITEM_NOT_FOUND),  //! A menu item was not found.
		_MakeErrorCodeName(ERROR_INVALID_KEYBOARD_HANDLE),  //! Invalid keyboard layout handle.
		_MakeErrorCodeName(ERROR_HOOK_TYPE_NOT_ALLOWED),  //! Hook type not allowed.
		_MakeErrorCodeName(ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION),  //! This operation requires an interactive window station.
		_MakeErrorCodeName(ERROR_TIMEOUT),  //! This operation returned because the timeout period expired.
		_MakeErrorCodeName(ERROR_INVALID_MONITOR_HANDLE),  //! Invalid monitor handle.
		_MakeErrorCodeName(ERROR_INCORRECT_SIZE),  //! Incorrect size argument.
		_MakeErrorCodeName(ERROR_SYMLINK_CLASS_DISABLED),  //! The symbolic link cannot be followed because its type is disabled.
		_MakeErrorCodeName(ERROR_SYMLINK_NOT_SUPPORTED),  //! This application does not support the current operation on symbolic links.
		_MakeErrorCodeName(ERROR_XML_PARSE_ERROR),  //! Windows was unable to parse the requested XML data.
		_MakeErrorCodeName(ERROR_XMLDSIG_ERROR),  //! An error was encountered while processing an XML digital signature.
		_MakeErrorCodeName(ERROR_RESTART_APPLICATION),  //! This application must be restarted.
		_MakeErrorCodeName(ERROR_WRONG_COMPARTMENT),  //! The caller made the connection request in the wrong routing compartment.
		_MakeErrorCodeName(ERROR_AUTHIP_FAILURE),  //! There was an AuthIP failure when attempting to connect to the remote host.
		_MakeErrorCodeName(ERROR_NO_NVRAM_RESOURCES),  //! Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.
		_MakeErrorCodeName(ERROR_NOT_GUI_PROCESS),  //! Unable to finish the requested operation because the specified process is not a GUI process.
		_MakeErrorCodeName(ERROR_EVENTLOG_FILE_CORRUPT),  //! The event log file is corrupted.
		_MakeErrorCodeName(ERROR_EVENTLOG_CANT_START),  //! No event log file could be opened, so the event logging service did not start.
		_MakeErrorCodeName(ERROR_LOG_FILE_FULL),  //! The event log file is full.
		_MakeErrorCodeName(ERROR_EVENTLOG_FILE_CHANGED),  //! The event log file has changed between read operations.
		_MakeErrorCodeName(ERROR_INVALID_TASK_NAME),  //! The specified task name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_TASK_INDEX),  //! The specified task index is invalid.
		_MakeErrorCodeName(ERROR_THREAD_ALREADY_IN_TASK),  //! The specified thread is already joining a task.
		_MakeErrorCodeName(ERROR_INSTALL_SERVICE_FAILURE),  //! The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.
		_MakeErrorCodeName(ERROR_INSTALL_USEREXIT),  //! User cancelled installation.
		_MakeErrorCodeName(ERROR_INSTALL_FAILURE),  //! Fatal error during installation.
		_MakeErrorCodeName(ERROR_INSTALL_SUSPEND),  //! Installation suspended, incomplete.
		_MakeErrorCodeName(ERROR_UNKNOWN_PRODUCT),  //! This action is only valid for products that are currently installed.
		_MakeErrorCodeName(ERROR_UNKNOWN_FEATURE),  //! Feature ID not registered.
		_MakeErrorCodeName(ERROR_UNKNOWN_COMPONENT),  //! Component ID not registered.
		_MakeErrorCodeName(ERROR_UNKNOWN_PROPERTY),  //! Unknown property.
		_MakeErrorCodeName(ERROR_INVALID_HANDLE_STATE),  //! Handle is in an invalid state.
		_MakeErrorCodeName(ERROR_BAD_CONFIGURATION),  //! The configuration data for this product is corrupt. Contact your support personnel.
		_MakeErrorCodeName(ERROR_INDEX_ABSENT),  //! Component qualifier not present.
		_MakeErrorCodeName(ERROR_INSTALL_SOURCE_ABSENT),  //! The installation source for this product is not available. Verify that the source exists and that you can access it.
		_MakeErrorCodeName(ERROR_INSTALL_PACKAGE_VERSION),  //! This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.
		_MakeErrorCodeName(ERROR_PRODUCT_UNINSTALLED),  //! Product is uninstalled.
		_MakeErrorCodeName(ERROR_BAD_QUERY_SYNTAX),  //! SQL query syntax invalid or unsupported.
		_MakeErrorCodeName(ERROR_INVALID_FIELD),  //! Record field does not exist.
		_MakeErrorCodeName(ERROR_DEVICE_REMOVED),  //! The device has been removed.
		_MakeErrorCodeName(ERROR_INSTALL_ALREADY_RUNNING),  //! Another installation is already in progress. Complete that installation before proceeding with this install.
		_MakeErrorCodeName(ERROR_INSTALL_PACKAGE_OPEN_FAILED),  //! This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.
		_MakeErrorCodeName(ERROR_INSTALL_PACKAGE_INVALID),  //! This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.
		_MakeErrorCodeName(ERROR_INSTALL_UI_FAILURE),  //! There was an error starting the Windows Installer service user interface. Contact your support personnel.
		_MakeErrorCodeName(ERROR_INSTALL_LOG_FAILURE),  //! Error opening installation log file. Verify that the specified log file location exists and that you can write to it.
		_MakeErrorCodeName(ERROR_INSTALL_LANGUAGE_UNSUPPORTED),  //! The language of this installation package is not supported by your system.
		_MakeErrorCodeName(ERROR_INSTALL_TRANSFORM_FAILURE),  //! Error applying transforms. Verify that the specified transform paths are valid.
		_MakeErrorCodeName(ERROR_INSTALL_PACKAGE_REJECTED),  //! This installation is forbidden by system policy. Contact your system administrator.
		_MakeErrorCodeName(ERROR_FUNCTION_NOT_CALLED),  //! Function could not be executed.
		_MakeErrorCodeName(ERROR_FUNCTION_FAILED),  //! Function failed during execution.
		_MakeErrorCodeName(ERROR_INVALID_TABLE),  //! Invalid or unknown table specified.
		_MakeErrorCodeName(ERROR_DATATYPE_MISMATCH),  //! Data supplied is of wrong type.
		_MakeErrorCodeName(ERROR_UNSUPPORTED_TYPE),  //! Data of this type is not supported.
		_MakeErrorCodeName(ERROR_CREATE_FAILED),  //! The Windows Installer service failed to start. Contact your support personnel.
		_MakeErrorCodeName(ERROR_INSTALL_TEMP_UNWRITABLE),  //! The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.
		_MakeErrorCodeName(ERROR_INSTALL_PLATFORM_UNSUPPORTED),  //! This installation package is not supported by this processor type. Contact your product vendor.
		_MakeErrorCodeName(ERROR_INSTALL_NOTUSED),  //! Component not used on this computer.
		_MakeErrorCodeName(ERROR_PATCH_PACKAGE_OPEN_FAILED),  //! This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.
		_MakeErrorCodeName(ERROR_PATCH_PACKAGE_INVALID),  //! This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.
		_MakeErrorCodeName(ERROR_PATCH_PACKAGE_UNSUPPORTED),  //! This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.
		_MakeErrorCodeName(ERROR_PRODUCT_VERSION),  //! Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
		_MakeErrorCodeName(ERROR_INVALID_COMMAND_LINE),  //! Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.
		_MakeErrorCodeName(ERROR_INSTALL_REMOTE_DISALLOWED),  //! Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.
		_MakeErrorCodeName(ERROR_SUCCESS_REBOOT_INITIATED),  //! The requested operation completed successfully. The system will be restarted so the changes can take effect.
		_MakeErrorCodeName(ERROR_PATCH_TARGET_NOT_FOUND),  //! The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.
		_MakeErrorCodeName(ERROR_PATCH_PACKAGE_REJECTED),  //! The update package is not permitted by software restriction policy.
		_MakeErrorCodeName(ERROR_INSTALL_TRANSFORM_REJECTED),  //! One or more customizations are not permitted by software restriction policy.
		_MakeErrorCodeName(ERROR_INSTALL_REMOTE_PROHIBITED),  //! The Windows Installer does not permit installation from a Remote Desktop Connection.
		_MakeErrorCodeName(ERROR_PATCH_REMOVAL_UNSUPPORTED),  //! Uninstallation of the update package is not supported.
		_MakeErrorCodeName(ERROR_UNKNOWN_PATCH),  //! The update is not applied to this product.
		_MakeErrorCodeName(ERROR_PATCH_NO_SEQUENCE),  //! No valid sequence could be found for the set of updates.
		_MakeErrorCodeName(ERROR_PATCH_REMOVAL_DISALLOWED),  //! Update removal was disallowed by policy.
		_MakeErrorCodeName(ERROR_INVALID_PATCH_XML),  //! The XML update data is invalid.
		_MakeErrorCodeName(ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT),  //! Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.
		_MakeErrorCodeName(ERROR_INSTALL_SERVICE_SAFEBOOT),  //! The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.
		_MakeErrorCodeName(ERROR_FAIL_FAST_EXCEPTION),  //! A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.
		_MakeErrorCodeName(ERROR_INSTALL_REJECTED),  //! The app that you are trying to run is not supported on this version of Windows.
		_MakeErrorCodeName(RPC_S_INVALID_STRING_BINDING),  //! The string binding is invalid.
		_MakeErrorCodeName(RPC_S_WRONG_KIND_OF_BINDING),  //! The binding handle is not the correct type.
		_MakeErrorCodeName(RPC_S_INVALID_BINDING),  //! The binding handle is invalid.
		_MakeErrorCodeName(RPC_S_PROTSEQ_NOT_SUPPORTED),  //! The RPC protocol sequence is not supported.
		_MakeErrorCodeName(RPC_S_INVALID_RPC_PROTSEQ),  //! The RPC protocol sequence is invalid.
		_MakeErrorCodeName(RPC_S_INVALID_STRING_UUID),  //! The string universal unique identifier (UUID) is invalid.
		_MakeErrorCodeName(RPC_S_INVALID_ENDPOINT_FORMAT),  //! The endpoint format is invalid.
		_MakeErrorCodeName(RPC_S_INVALID_NET_ADDR),  //! The network address is invalid.
		_MakeErrorCodeName(RPC_S_NO_ENDPOINT_FOUND),  //! No endpoint was found.
		_MakeErrorCodeName(RPC_S_INVALID_TIMEOUT),  //! The timeout value is invalid.
		_MakeErrorCodeName(RPC_S_OBJECT_NOT_FOUND),  //! The object universal unique identifier (UUID) was not found.
		_MakeErrorCodeName(RPC_S_ALREADY_REGISTERED),  //! The object universal unique identifier (UUID) has already been registered.
		_MakeErrorCodeName(RPC_S_TYPE_ALREADY_REGISTERED),  //! The type universal unique identifier (UUID) has already been registered.
		_MakeErrorCodeName(RPC_S_ALREADY_LISTENING),  //! The RPC server is already listening.
		_MakeErrorCodeName(RPC_S_NO_PROTSEQS_REGISTERED),  //! No protocol sequences have been registered.
		_MakeErrorCodeName(RPC_S_NOT_LISTENING),  //! The RPC server is not listening.
		_MakeErrorCodeName(RPC_S_UNKNOWN_MGR_TYPE),  //! The manager type is unknown.
		_MakeErrorCodeName(RPC_S_UNKNOWN_IF),  //! The interface is unknown.
		_MakeErrorCodeName(RPC_S_NO_BINDINGS),  //! There are no bindings.
		_MakeErrorCodeName(RPC_S_NO_PROTSEQS),  //! There are no protocol sequences.
		_MakeErrorCodeName(RPC_S_CANT_CREATE_ENDPOINT),  //! The endpoint cannot be created.
		_MakeErrorCodeName(RPC_S_OUT_OF_RESOURCES),  //! Not enough resources are available to complete this operation.
		_MakeErrorCodeName(RPC_S_SERVER_UNAVAILABLE),  //! The RPC server is unavailable.
		_MakeErrorCodeName(RPC_S_SERVER_TOO_BUSY),  //! The RPC server is too busy to complete this operation.
		_MakeErrorCodeName(RPC_S_INVALID_NETWORK_OPTIONS),  //! The network options are invalid.
		_MakeErrorCodeName(RPC_S_NO_CALL_ACTIVE),  //! There are no remote procedure calls active on this thread.
		_MakeErrorCodeName(RPC_S_CALL_FAILED),  //! The remote procedure call failed.
		_MakeErrorCodeName(RPC_S_CALL_FAILED_DNE),  //! The remote procedure call failed and did not execute.
		_MakeErrorCodeName(RPC_S_PROTOCOL_ERROR),  //! A remote procedure call (RPC) protocol error occurred.
		_MakeErrorCodeName(RPC_S_PROXY_ACCESS_DENIED),  //! Access to the HTTP proxy is denied.
		_MakeErrorCodeName(RPC_S_UNSUPPORTED_TRANS_SYN),  //! The transfer syntax is not supported by the RPC server.
		_MakeErrorCodeName(RPC_S_UNSUPPORTED_TYPE),  //! The universal unique identifier (UUID) type is not supported.
		_MakeErrorCodeName(RPC_S_INVALID_TAG),  //! The tag is invalid.
		_MakeErrorCodeName(RPC_S_INVALID_BOUND),  //! The array bounds are invalid.
		_MakeErrorCodeName(RPC_S_NO_ENTRY_NAME),  //! The binding does not contain an entry name.
		_MakeErrorCodeName(RPC_S_INVALID_NAME_SYNTAX),  //! The name syntax is invalid.
		_MakeErrorCodeName(RPC_S_UNSUPPORTED_NAME_SYNTAX),  //! The name syntax is not supported.
		_MakeErrorCodeName(RPC_S_UUID_NO_ADDRESS),  //! No network address is available to use to construct a universal unique identifier (UUID).
		_MakeErrorCodeName(RPC_S_DUPLICATE_ENDPOINT),  //! The endpoint is a duplicate.
		_MakeErrorCodeName(RPC_S_UNKNOWN_AUTHN_TYPE),  //! The authentication type is unknown.
		_MakeErrorCodeName(RPC_S_MAX_CALLS_TOO_SMALL),  //! The maximum number of calls is too small.
		_MakeErrorCodeName(RPC_S_STRING_TOO_LONG),  //! The string is too long.
		_MakeErrorCodeName(RPC_S_PROTSEQ_NOT_FOUND),  //! The RPC protocol sequence was not found.
		_MakeErrorCodeName(RPC_S_PROCNUM_OUT_OF_RANGE),  //! The procedure number is out of range.
		_MakeErrorCodeName(RPC_S_BINDING_HAS_NO_AUTH),  //! The binding does not contain any authentication information.
		_MakeErrorCodeName(RPC_S_UNKNOWN_AUTHN_SERVICE),  //! The authentication service is unknown.
		_MakeErrorCodeName(RPC_S_UNKNOWN_AUTHN_LEVEL),  //! The authentication level is unknown.
		_MakeErrorCodeName(RPC_S_INVALID_AUTH_IDENTITY),  //! The security context is invalid.
		_MakeErrorCodeName(RPC_S_UNKNOWN_AUTHZ_SERVICE),  //! The authorization service is unknown.
		_MakeErrorCodeName(EPT_S_INVALID_ENTRY),  //! The entry is invalid.
		_MakeErrorCodeName(EPT_S_CANT_PERFORM_OP),  //! The server endpoint cannot perform the operation.
		_MakeErrorCodeName(EPT_S_NOT_REGISTERED),  //! There are no more endpoints available from the endpoint mapper.
		_MakeErrorCodeName(RPC_S_NOTHING_TO_EXPORT),  //! No interfaces have been exported.
		_MakeErrorCodeName(RPC_S_INCOMPLETE_NAME),  //! The entry name is incomplete.
		_MakeErrorCodeName(RPC_S_INVALID_VERS_OPTION),  //! The version option is invalid.
		_MakeErrorCodeName(RPC_S_NO_MORE_MEMBERS),  //! There are no more members.
		_MakeErrorCodeName(RPC_S_NOT_ALL_OBJS_UNEXPORTED),  //! There is nothing to unexport.
		_MakeErrorCodeName(RPC_S_INTERFACE_NOT_FOUND),  //! The interface was not found.
		_MakeErrorCodeName(RPC_S_ENTRY_ALREADY_EXISTS),  //! The entry already exists.
		_MakeErrorCodeName(RPC_S_ENTRY_NOT_FOUND),  //! The entry is not found.
		_MakeErrorCodeName(RPC_S_NAME_SERVICE_UNAVAILABLE),  //! The name service is unavailable.
		_MakeErrorCodeName(RPC_S_INVALID_NAF_ID),  //! The network address family is invalid.
		_MakeErrorCodeName(RPC_S_CANNOT_SUPPORT),  //! The requested operation is not supported.
		_MakeErrorCodeName(RPC_S_NO_CONTEXT_AVAILABLE),  //! No security context is available to allow impersonation.
		_MakeErrorCodeName(RPC_S_INTERNAL_ERROR),  //! An internal error occurred in a remote procedure call (RPC).
		_MakeErrorCodeName(RPC_S_ZERO_DIVIDE),  //! The RPC server attempted an integer division by zero.
		_MakeErrorCodeName(RPC_S_ADDRESS_ERROR),  //! An addressing error occurred in the RPC server.
		_MakeErrorCodeName(RPC_S_FP_DIV_ZERO),  //! A floating-point operation at the RPC server caused a division by zero.
		_MakeErrorCodeName(RPC_S_FP_UNDERFLOW),  //! A floating-point underflow occurred at the RPC server.
		_MakeErrorCodeName(RPC_S_FP_OVERFLOW),  //! A floating-point overflow occurred at the RPC server.
		_MakeErrorCodeName(RPC_X_NO_MORE_ENTRIES),  //! The list of RPC servers available for the binding of auto handles has been exhausted.
		_MakeErrorCodeName(RPC_X_SS_CHAR_TRANS_OPEN_FAIL),  //! Unable to open the character translation table file.
		_MakeErrorCodeName(RPC_X_SS_CHAR_TRANS_SHORT_FILE),  //! The file containing the character translation table has fewer than 512 bytes.
		_MakeErrorCodeName(RPC_X_SS_IN_NULL_CONTEXT),  //! A null context handle was passed from the client to the host during a remote procedure call.
		_MakeErrorCodeName(RPC_X_SS_CONTEXT_DAMAGED),  //! The context handle changed during a remote procedure call.
		_MakeErrorCodeName(RPC_X_SS_HANDLES_MISMATCH),  //! The binding handles passed to a remote procedure call do not match.
		_MakeErrorCodeName(RPC_X_SS_CANNOT_GET_CALL_HANDLE),  //! The stub is unable to get the remote procedure call handle.
		_MakeErrorCodeName(RPC_X_NULL_REF_POINTER),  //! A null reference pointer was passed to the stub.
		_MakeErrorCodeName(RPC_X_ENUM_VALUE_OUT_OF_RANGE),  //! The enumeration value is out of range.
		_MakeErrorCodeName(RPC_X_BYTE_COUNT_TOO_SMALL),  //! The byte count is too small.
		_MakeErrorCodeName(RPC_X_BAD_STUB_DATA),  //! The stub received bad data.
		_MakeErrorCodeName(ERROR_INVALID_USER_BUFFER),  //! The supplied user buffer is not valid for the requested operation.
		_MakeErrorCodeName(ERROR_UNRECOGNIZED_MEDIA),  //! The disk media is not recognized. It may not be formatted.
		_MakeErrorCodeName(ERROR_NO_TRUST_LSA_SECRET),  //! The workstation does not have a trust secret.
		_MakeErrorCodeName(ERROR_NO_TRUST_SAM_ACCOUNT),  //! The security database on the server does not have a computer account for this workstation trust relationship.
		_MakeErrorCodeName(ERROR_TRUSTED_DOMAIN_FAILURE),  //! The trust relationship between the primary domain and the trusted domain failed.
		_MakeErrorCodeName(ERROR_TRUSTED_RELATIONSHIP_FAILURE),  //! The trust relationship between this workstation and the primary domain failed.
		_MakeErrorCodeName(ERROR_TRUST_FAILURE),  //! The network logon failed.
		_MakeErrorCodeName(RPC_S_CALL_IN_PROGRESS),  //! A remote procedure call is already in progress for this thread.
		_MakeErrorCodeName(ERROR_NETLOGON_NOT_STARTED),  //! An attempt was made to logon, but the network logon service was not started.
		_MakeErrorCodeName(ERROR_ACCOUNT_EXPIRED),  //! The user's account has expired.
		_MakeErrorCodeName(ERROR_REDIRECTOR_HAS_OPEN_HANDLES),  //! The redirector is in use and cannot be unloaded.
		_MakeErrorCodeName(ERROR_PRINTER_DRIVER_ALREADY_INSTALLED),  //! The specified printer driver is already installed.
		_MakeErrorCodeName(ERROR_UNKNOWN_PORT),  //! The specified port is unknown.
		_MakeErrorCodeName(ERROR_UNKNOWN_PRINTER_DRIVER),  //! The printer driver is unknown.
		_MakeErrorCodeName(ERROR_UNKNOWN_PRINTPROCESSOR),  //! The print processor is unknown.
		_MakeErrorCodeName(ERROR_INVALID_SEPARATOR_FILE),  //! The specified separator file is invalid.
		_MakeErrorCodeName(ERROR_INVALID_PRIORITY),  //! The specified priority is invalid.
		_MakeErrorCodeName(ERROR_INVALID_PRINTER_NAME),  //! The printer name is invalid.
		_MakeErrorCodeName(ERROR_PRINTER_ALREADY_EXISTS),  //! The printer already exists.
		_MakeErrorCodeName(ERROR_INVALID_PRINTER_COMMAND),  //! The printer command is invalid.
		_MakeErrorCodeName(ERROR_INVALID_DATATYPE),  //! The specified datatype is invalid.
		_MakeErrorCodeName(ERROR_INVALID_ENVIRONMENT),  //! The environment specified is invalid.
		_MakeErrorCodeName(RPC_S_NO_MORE_BINDINGS),  //! There are no more bindings.
		_MakeErrorCodeName(ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT),  //! The account used is an interdomain trust account. Use your global user account or local user account to access this server.
		_MakeErrorCodeName(ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT),  //! The account used is a computer account. Use your global user account or local user account to access this server.
		_MakeErrorCodeName(ERROR_NOLOGON_SERVER_TRUST_ACCOUNT),  //! The account used is a server trust account. Use your global user account or local user account to access this server.
		_MakeErrorCodeName(ERROR_DOMAIN_TRUST_INCONSISTENT),  //! The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.
		_MakeErrorCodeName(ERROR_SERVER_HAS_OPEN_HANDLES),  //! The server is in use and cannot be unloaded.
		_MakeErrorCodeName(ERROR_RESOURCE_DATA_NOT_FOUND),  //! The specified image file did not contain a resource section.
		_MakeErrorCodeName(ERROR_RESOURCE_TYPE_NOT_FOUND),  //! The specified resource type cannot be found in the image file.
		_MakeErrorCodeName(ERROR_RESOURCE_NAME_NOT_FOUND),  //! The specified resource name cannot be found in the image file.
		_MakeErrorCodeName(ERROR_RESOURCE_LANG_NOT_FOUND),  //! The specified resource language ID cannot be found in the image file.
		_MakeErrorCodeName(ERROR_NOT_ENOUGH_QUOTA),  //! Not enough quota is available to process this command.
		_MakeErrorCodeName(RPC_S_NO_INTERFACES),  //! No interfaces have been registered.
		_MakeErrorCodeName(RPC_S_CALL_CANCELLED),  //! The remote procedure call was cancelled.
		_MakeErrorCodeName(RPC_S_BINDING_INCOMPLETE),  //! The binding handle does not contain all required information.
		_MakeErrorCodeName(RPC_S_COMM_FAILURE),  //! A communications failure occurred during a remote procedure call.
		_MakeErrorCodeName(RPC_S_UNSUPPORTED_AUTHN_LEVEL),  //! The requested authentication level is not supported.
		_MakeErrorCodeName(RPC_S_NO_PRINC_NAME),  //! No principal name registered.
		_MakeErrorCodeName(RPC_S_NOT_RPC_ERROR),  //! The error specified is not a valid Windows RPC error code.
		_MakeErrorCodeName(RPC_S_UUID_LOCAL_ONLY),  //! A UUID that is valid only on this computer has been allocated.
		_MakeErrorCodeName(RPC_S_SEC_PKG_ERROR),  //! A security package specific error occurred.
		_MakeErrorCodeName(RPC_S_NOT_CANCELLED),  //! Thread is not canceled.
		_MakeErrorCodeName(RPC_X_INVALID_ES_ACTION),  //! Invalid operation on the encoding/decoding handle.
		_MakeErrorCodeName(RPC_X_WRONG_ES_VERSION),  //! Incompatible version of the serializing package.
		_MakeErrorCodeName(RPC_X_WRONG_STUB_VERSION),  //! Incompatible version of the RPC stub.
		_MakeErrorCodeName(RPC_X_INVALID_PIPE_OBJECT),  //! The RPC pipe object is invalid or corrupted.
		_MakeErrorCodeName(RPC_X_WRONG_PIPE_ORDER),  //! An invalid operation was attempted on an RPC pipe object.
		_MakeErrorCodeName(RPC_X_WRONG_PIPE_VERSION),  //! Unsupported RPC pipe version.
		_MakeErrorCodeName(RPC_S_COOKIE_AUTH_FAILED),  //! HTTP proxy server rejected the connection because the cookie authentication failed.
		_MakeErrorCodeName(RPC_S_GROUP_MEMBER_NOT_FOUND),  //! The group member was not found.
		_MakeErrorCodeName(EPT_S_CANT_CREATE),  //! The endpoint mapper database entry could not be created.
		_MakeErrorCodeName(RPC_S_INVALID_OBJECT),  //! The object universal unique identifier (UUID) is the nil UUID.
		_MakeErrorCodeName(ERROR_INVALID_TIME),  //! The specified time is invalid.
		_MakeErrorCodeName(ERROR_INVALID_FORM_NAME),  //! The specified form name is invalid.
		_MakeErrorCodeName(ERROR_INVALID_FORM_SIZE),  //! The specified form size is invalid.
		_MakeErrorCodeName(ERROR_ALREADY_WAITING),  //! The specified printer handle is already being waited on.
		_MakeErrorCodeName(ERROR_PRINTER_DELETED),  //! The specified printer has been deleted.
		_MakeErrorCodeName(ERROR_INVALID_PRINTER_STATE),  //! The state of the printer is invalid.
		_MakeErrorCodeName(ERROR_PASSWORD_MUST_CHANGE),  //! The user's password must be changed before signing in.
		_MakeErrorCodeName(ERROR_DOMAIN_CONTROLLER_NOT_FOUND),  //! Could not find the domain controller for this domain.
		_MakeErrorCodeName(ERROR_ACCOUNT_LOCKED_OUT),  //! The referenced account is currently locked out and may not be logged on to.
		_MakeErrorCodeName(OR_INVALID_OXID),  //! The object exporter specified was not found.
		_MakeErrorCodeName(OR_INVALID_OID),  //! The object specified was not found.
		_MakeErrorCodeName(OR_INVALID_SET),  //! The object resolver set specified was not found.
		_MakeErrorCodeName(RPC_S_SEND_INCOMPLETE),  //! Some data remains to be sent in the request buffer.
		_MakeErrorCodeName(RPC_S_INVALID_ASYNC_HANDLE),  //! Invalid asynchronous remote procedure call handle.
		_MakeErrorCodeName(RPC_S_INVALID_ASYNC_CALL),  //! Invalid asynchronous RPC call handle for this operation.
		_MakeErrorCodeName(RPC_X_PIPE_CLOSED),  //! The RPC pipe object has already been closed.
		_MakeErrorCodeName(RPC_X_PIPE_DISCIPLINE_ERROR),  //! The RPC call completed before all pipes were processed.
		_MakeErrorCodeName(RPC_X_PIPE_EMPTY),  //! No more data is available from the RPC pipe.
		_MakeErrorCodeName(ERROR_NO_SITENAME),  //! No site name is available for this machine.
		_MakeErrorCodeName(ERROR_CANT_ACCESS_FILE),  //! The file cannot be accessed by the system.
		_MakeErrorCodeName(ERROR_CANT_RESOLVE_FILENAME),  //! The name of the file cannot be resolved by the system.
		_MakeErrorCodeName(RPC_S_ENTRY_TYPE_MISMATCH),  //! The entry is not of the expected type.
		_MakeErrorCodeName(RPC_S_NOT_ALL_OBJS_EXPORTED),  //! Not all object UUIDs could be exported to the specified entry.
		_MakeErrorCodeName(RPC_S_INTERFACE_NOT_EXPORTED),  //! Interface could not be exported to the specified entry.
		_MakeErrorCodeName(RPC_S_PROFILE_NOT_ADDED),  //! The specified profile entry could not be added.
		_MakeErrorCodeName(RPC_S_PRF_ELT_NOT_ADDED),  //! The specified profile element could not be added.
		_MakeErrorCodeName(RPC_S_PRF_ELT_NOT_REMOVED),  //! The specified profile element could not be removed.
		_MakeErrorCodeName(RPC_S_GRP_ELT_NOT_ADDED),  //! The group element could not be added.
		_MakeErrorCodeName(RPC_S_GRP_ELT_NOT_REMOVED),  //! The group element could not be removed.
		_MakeErrorCodeName(ERROR_KM_DRIVER_BLOCKED),  //! The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.
		_MakeErrorCodeName(ERROR_CONTEXT_EXPIRED),  //! The context has expired and can no longer be used.
		_MakeErrorCodeName(ERROR_PER_USER_TRUST_QUOTA_EXCEEDED),  //! The current user's delegated trust creation quota has been exceeded.
		_MakeErrorCodeName(ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED),  //! The total delegated trust creation quota has been exceeded.
		_MakeErrorCodeName(ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED),  //! The current user's delegated trust deletion quota has been exceeded.
		_MakeErrorCodeName(ERROR_AUTHENTICATION_FIREWALL_FAILED),  //! The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer.
		_MakeErrorCodeName(ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED),  //! Remote connections to the Print Spooler are blocked by a policy set on your machine.
		_MakeErrorCodeName(ERROR_NTLM_BLOCKED),  //! Authentication failed because NTLM authentication has been disabled.
		_MakeErrorCodeName(ERROR_PASSWORD_CHANGE_REQUIRED),  //! Logon Failure: EAS policy requires that the user change their password before this operation can be performed.
		_MakeErrorCodeName(ERROR_INVALID_PIXEL_FORMAT),  //! The pixel format is invalid.
		_MakeErrorCodeName(ERROR_BAD_DRIVER),  //! The specified driver is invalid.
		_MakeErrorCodeName(ERROR_INVALID_WINDOW_STYLE),  //! The window style or class attribute is invalid for this operation.
		_MakeErrorCodeName(ERROR_METAFILE_NOT_SUPPORTED),  //! The requested metafile operation is not supported.
		_MakeErrorCodeName(ERROR_TRANSFORM_NOT_SUPPORTED),  //! The requested transformation operation is not supported.
		_MakeErrorCodeName(ERROR_CLIPPING_NOT_SUPPORTED),  //! The requested clipping operation is not supported.
		_MakeErrorCodeName(ERROR_INVALID_CMM),  //! The specified color management module is invalid.
		_MakeErrorCodeName(ERROR_INVALID_PROFILE),  //! The specified color profile is invalid.
		_MakeErrorCodeName(ERROR_TAG_NOT_FOUND),  //! The specified tag was not found.
		_MakeErrorCodeName(ERROR_TAG_NOT_PRESENT),  //! A required tag is not present.
		_MakeErrorCodeName(ERROR_DUPLICATE_TAG),  //! The specified tag is already present.
		_MakeErrorCodeName(ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE),  //! The specified color profile is not associated with the specified device.
		_MakeErrorCodeName(ERROR_PROFILE_NOT_FOUND),  //! The specified color profile was not found.
		_MakeErrorCodeName(ERROR_INVALID_COLORSPACE),  //! The specified color space is invalid.
		_MakeErrorCodeName(ERROR_ICM_NOT_ENABLED),  //! Image Color Management is not enabled.
		_MakeErrorCodeName(ERROR_DELETING_ICM_XFORM),  //! There was an error while deleting the color transform.
		_MakeErrorCodeName(ERROR_INVALID_TRANSFORM),  //! The specified color transform is invalid.
		_MakeErrorCodeName(ERROR_COLORSPACE_MISMATCH),  //! The specified transform does not match the bitmap's color space.
		_MakeErrorCodeName(ERROR_INVALID_COLORINDEX),  //! The specified named color index is not present in the profile.
		_MakeErrorCodeName(ERROR_PROFILE_DOES_NOT_MATCH_DEVICE),  //! The specified profile is intended for a device of a different type than the specified device.
		_MakeErrorCodeName(ERROR_CONNECTED_OTHER_PASSWORD),  //! The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.
		_MakeErrorCodeName(ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT),  //! The network connection was made successfully using default credentials.
		_MakeErrorCodeName(ERROR_BAD_USERNAME),  //! The specified username is invalid.
		_MakeErrorCodeName(ERROR_NOT_CONNECTED),  //! This network connection does not exist.
		_MakeErrorCodeName(ERROR_OPEN_FILES),  //! This network connection has files open or requests pending.
		_MakeErrorCodeName(ERROR_ACTIVE_CONNECTIONS),  //! Active connections still exist.
		_MakeErrorCodeName(ERROR_DEVICE_IN_USE),  //! The device is in use by an active process and cannot be disconnected.
		_MakeErrorCodeName(ERROR_UNKNOWN_PRINT_MONITOR),  //! The specified print monitor is unknown.
		_MakeErrorCodeName(ERROR_PRINTER_DRIVER_IN_USE),  //! The specified printer driver is currently in use.
		_MakeErrorCodeName(ERROR_SPOOL_FILE_NOT_FOUND),  //! The spool file was not found.
		_MakeErrorCodeName(ERROR_SPL_NO_STARTDOC),  //! A StartDocPrinter call was not issued.
		_MakeErrorCodeName(ERROR_SPL_NO_ADDJOB),  //! An AddJob call was not issued.
		_MakeErrorCodeName(ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED),  //! The specified print processor has already been installed.
		_MakeErrorCodeName(ERROR_PRINT_MONITOR_ALREADY_INSTALLED),  //! The specified print monitor has already been installed.
		_MakeErrorCodeName(ERROR_INVALID_PRINT_MONITOR),  //! The specified print monitor does not have the required functions.
		_MakeErrorCodeName(ERROR_PRINT_MONITOR_IN_USE),  //! The specified print monitor is currently in use.
		_MakeErrorCodeName(ERROR_PRINTER_HAS_JOBS_QUEUED),  //! The requested operation is not allowed when there are jobs queued to the printer.
		_MakeErrorCodeName(ERROR_SUCCESS_REBOOT_REQUIRED),  //! The requested operation is successful. Changes will not be effective until the system is rebooted.
		_MakeErrorCodeName(ERROR_SUCCESS_RESTART_REQUIRED),  //! The requested operation is successful. Changes will not be effective until the service is restarted.
		_MakeErrorCodeName(ERROR_PRINTER_NOT_FOUND),  //! No printers were found.
		_MakeErrorCodeName(ERROR_PRINTER_DRIVER_WARNED),  //! The printer driver is known to be unreliable.
		_MakeErrorCodeName(ERROR_PRINTER_DRIVER_BLOCKED),  //! The printer driver is known to harm the system.
		_MakeErrorCodeName(ERROR_PRINTER_DRIVER_PACKAGE_IN_USE),  //! The specified printer driver package is currently in use.
		_MakeErrorCodeName(ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND),  //! Unable to find a core driver package that is required by the printer driver package.
		_MakeErrorCodeName(ERROR_FAIL_REBOOT_REQUIRED),  //! The requested operation failed. A system reboot is required to roll back changes made.
		_MakeErrorCodeName(ERROR_FAIL_REBOOT_INITIATED),  //! The requested operation failed. A system reboot has been initiated to roll back changes made.
		_MakeErrorCodeName(ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED),  //! The specified printer driver was not found on the system and needs to be downloaded.
		_MakeErrorCodeName(ERROR_PRINT_JOB_RESTART_REQUIRED),  //! The requested print job has failed to print. A print system update requires the job to be resubmitted.
		_MakeErrorCodeName(ERROR_INVALID_PRINTER_DRIVER_MANIFEST),  //! The printer driver does not contain a valid manifest, or contains too many manifests.
		_MakeErrorCodeName(ERROR_PRINTER_NOT_SHAREABLE),  //! The specified printer cannot be shared.
		_MakeErrorCodeName(ERROR_REQUEST_PAUSED),  //! The operation was paused.
		_MakeErrorCodeName(ERROR_IO_REISSUE_AS_CACHED),  //! Reissue the given operation as a cached IO operation.
		_MakeErrorCodeName(ERROR_WINS_INTERNAL),  //! WINS encountered an error while processing the command.
		_MakeErrorCodeName(ERROR_CAN_NOT_DEL_LOCAL_WINS),  //! The local WINS cannot be deleted.
		_MakeErrorCodeName(ERROR_STATIC_INIT),  //! The importation from the file failed.
		_MakeErrorCodeName(ERROR_INC_BACKUP),  //! The backup failed. Was a full backup done before?
		_MakeErrorCodeName(ERROR_FULL_BACKUP),  //! The backup failed. Check the directory to which you are backing the database.
		_MakeErrorCodeName(ERROR_REC_NON_EXISTENT),  //! The name does not exist in the WINS database.
		_MakeErrorCodeName(ERROR_RPL_NOT_ALLOWED),  //! Replication with a nonconfigured partner is not allowed.
		_MakeErrorCodeName(PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED),  //! The version of the supplied content information is not supported.
		_MakeErrorCodeName(PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO),  //! The supplied content information is malformed.
		_MakeErrorCodeName(PEERDIST_ERROR_MISSING_DATA),  //! The requested data cannot be found in local or peer caches.
		_MakeErrorCodeName(PEERDIST_ERROR_NO_MORE),  //! No more data is available or required.
		_MakeErrorCodeName(PEERDIST_ERROR_NOT_INITIALIZED),  //! The supplied object has not been initialized.
		_MakeErrorCodeName(PEERDIST_ERROR_ALREADY_INITIALIZED),  //! The supplied object has already been initialized.
		_MakeErrorCodeName(PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS),  //! A shutdown operation is already in progress.
		_MakeErrorCodeName(PEERDIST_ERROR_INVALIDATED),  //! The supplied object has already been invalidated.
		_MakeErrorCodeName(PEERDIST_ERROR_ALREADY_EXISTS),  //! An element already exists and was not replaced.
		_MakeErrorCodeName(PEERDIST_ERROR_OPERATION_NOTFOUND),  //! Cannot cancel the requested operation as it has already been completed.
		_MakeErrorCodeName(PEERDIST_ERROR_ALREADY_COMPLETED),  //! Can not perform the reqested operation because it has already been carried out.
		_MakeErrorCodeName(PEERDIST_ERROR_OUT_OF_BOUNDS),  //! An operation accessed data beyond the bounds of valid data.
		_MakeErrorCodeName(PEERDIST_ERROR_VERSION_UNSUPPORTED),  //! The requested version is not supported.
		_MakeErrorCodeName(PEERDIST_ERROR_INVALID_CONFIGURATION),  //! A configuration value is invalid.
		_MakeErrorCodeName(PEERDIST_ERROR_NOT_LICENSED),  //! The SKU is not licensed.
		_MakeErrorCodeName(PEERDIST_ERROR_SERVICE_UNAVAILABLE),  //! PeerDist Service is still initializing and will be available shortly.
		_MakeErrorCodeName(PEERDIST_ERROR_TRUST_FAILURE),  //! Communication with one or more computers will be temporarily blocked due to recent errors.
		_MakeErrorCodeName(ERROR_DHCP_ADDRESS_CONFLICT),  //! The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.
		_MakeErrorCodeName(ERROR_WMI_GUID_NOT_FOUND),  //! The GUID passed was not recognized as valid by a WMI data provider.
		_MakeErrorCodeName(ERROR_WMI_INSTANCE_NOT_FOUND),  //! The instance name passed was not recognized as valid by a WMI data provider.
		_MakeErrorCodeName(ERROR_WMI_ITEMID_NOT_FOUND),  //! The data item ID passed was not recognized as valid by a WMI data provider.
		_MakeErrorCodeName(ERROR_WMI_TRY_AGAIN),  //! The WMI request could not be completed and should be retried.
		_MakeErrorCodeName(ERROR_WMI_DP_NOT_FOUND),  //! The WMI data provider could not be located.
		_MakeErrorCodeName(ERROR_WMI_UNRESOLVED_INSTANCE_REF),  //! The WMI data provider references an instance set that has not been registered.
		_MakeErrorCodeName(ERROR_WMI_ALREADY_ENABLED),  //! The WMI data block or event notification has already been enabled.
		_MakeErrorCodeName(ERROR_WMI_GUID_DISCONNECTED),  //! The WMI data block is no longer available.
		_MakeErrorCodeName(ERROR_WMI_SERVER_UNAVAILABLE),  //! The WMI data service is not available.
		_MakeErrorCodeName(ERROR_WMI_DP_FAILED),  //! The WMI data provider failed to carry out the request.
		_MakeErrorCodeName(ERROR_WMI_INVALID_MOF),  //! The WMI MOF information is not valid.
		_MakeErrorCodeName(ERROR_WMI_INVALID_REGINFO),  //! The WMI registration information is not valid.
		_MakeErrorCodeName(ERROR_WMI_ALREADY_DISABLED),  //! The WMI data block or event notification has already been disabled.
		_MakeErrorCodeName(ERROR_WMI_READ_ONLY),  //! The WMI data item or data block is read only.
		_MakeErrorCodeName(ERROR_WMI_SET_FAILURE),  //! The WMI data item or data block could not be changed.
		_MakeErrorCodeName(ERROR_NOT_APPCONTAINER),  //! This operation is only valid in the context of an app container.
		_MakeErrorCodeName(ERROR_APPCONTAINER_REQUIRED),  //! This application can only run in the context of an app container.
		_MakeErrorCodeName(ERROR_NOT_SUPPORTED_IN_APPCONTAINER),  //! This functionality is not supported in the context of an app container.
		_MakeErrorCodeName(ERROR_INVALID_PACKAGE_SID_LENGTH),  //! The length of the SID supplied is not a valid length for app container SIDs.
		_MakeErrorCodeName(ERROR_INVALID_MEDIA),  //! The media identifier does not represent a valid medium.
		_MakeErrorCodeName(ERROR_INVALID_LIBRARY),  //! The library identifier does not represent a valid library.
		_MakeErrorCodeName(ERROR_INVALID_MEDIA_POOL),  //! The media pool identifier does not represent a valid media pool.
		_MakeErrorCodeName(ERROR_DRIVE_MEDIA_MISMATCH),  //! The drive and medium are not compatible or exist in different libraries.
		_MakeErrorCodeName(ERROR_MEDIA_OFFLINE),  //! The medium currently exists in an offline library and must be online to perform this operation.
		_MakeErrorCodeName(ERROR_LIBRARY_OFFLINE),  //! The operation cannot be performed on an offline library.
		_MakeErrorCodeName(ERROR_EMPTY),  //! The library, drive, or media pool is empty.
		_MakeErrorCodeName(ERROR_NOT_EMPTY),  //! The library, drive, or media pool must be empty to perform this operation.
		_MakeErrorCodeName(ERROR_MEDIA_UNAVAILABLE),  //! No media is currently available in this media pool or library.
		_MakeErrorCodeName(ERROR_RESOURCE_DISABLED),  //! A resource required for this operation is disabled.
		_MakeErrorCodeName(ERROR_INVALID_CLEANER),  //! The media identifier does not represent a valid cleaner.
		_MakeErrorCodeName(ERROR_UNABLE_TO_CLEAN),  //! The drive cannot be cleaned or does not support cleaning.
		_MakeErrorCodeName(ERROR_OBJECT_NOT_FOUND),  //! The object identifier does not represent a valid object.
		_MakeErrorCodeName(ERROR_DATABASE_FAILURE),  //! Unable to read from or write to the database.
		_MakeErrorCodeName(ERROR_DATABASE_FULL),  //! The database is full.
		_MakeErrorCodeName(ERROR_MEDIA_INCOMPATIBLE),  //! The medium is not compatible with the device or media pool.
		_MakeErrorCodeName(ERROR_RESOURCE_NOT_PRESENT),  //! The resource required for this operation does not exist.
		_MakeErrorCodeName(ERROR_INVALID_OPERATION),  //! The operation identifier is not valid.
		_MakeErrorCodeName(ERROR_MEDIA_NOT_AVAILABLE),  //! The media is not mounted or ready for use.
		_MakeErrorCodeName(ERROR_DEVICE_NOT_AVAILABLE),  //! The device is not ready for use.
		_MakeErrorCodeName(ERROR_REQUEST_REFUSED),  //! The operator or administrator has refused the request.
		_MakeErrorCodeName(ERROR_INVALID_DRIVE_OBJECT),  //! The drive identifier does not represent a valid drive.
		_MakeErrorCodeName(ERROR_LIBRARY_FULL),  //! Library is full. No slot is available for use.
		_MakeErrorCodeName(ERROR_MEDIUM_NOT_ACCESSIBLE),  //! The transport cannot access the medium.
		_MakeErrorCodeName(ERROR_UNABLE_TO_LOAD_MEDIUM),  //! Unable to load the medium into the drive.
		_MakeErrorCodeName(ERROR_UNABLE_TO_INVENTORY_DRIVE),  //! Unable to retrieve the drive status.
		_MakeErrorCodeName(ERROR_UNABLE_TO_INVENTORY_SLOT),  //! Unable to retrieve the slot status.
		_MakeErrorCodeName(ERROR_UNABLE_TO_INVENTORY_TRANSPORT),  //! Unable to retrieve status about the transport.
		_MakeErrorCodeName(ERROR_TRANSPORT_FULL),  //! Cannot use the transport because it is already in use.
		_MakeErrorCodeName(ERROR_CONTROLLING_IEPORT),  //! Unable to open or close the inject/eject port.
		_MakeErrorCodeName(ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA),  //! Unable to eject the medium because it is in a drive.
		_MakeErrorCodeName(ERROR_CLEANER_SLOT_SET),  //! A cleaner slot is already reserved.
		_MakeErrorCodeName(ERROR_CLEANER_SLOT_NOT_SET),  //! A cleaner slot is not reserved.
		_MakeErrorCodeName(ERROR_CLEANER_CARTRIDGE_SPENT),  //! The cleaner cartridge has performed the maximum number of drive cleanings.
		_MakeErrorCodeName(ERROR_UNEXPECTED_OMID),  //! Unexpected on-medium identifier.
		_MakeErrorCodeName(ERROR_CANT_DELETE_LAST_ITEM),  //! The last remaining item in this group or resource cannot be deleted.
		_MakeErrorCodeName(ERROR_MESSAGE_EXCEEDS_MAX_SIZE),  //! The message provided exceeds the maximum size allowed for this parameter.
		_MakeErrorCodeName(ERROR_VOLUME_CONTAINS_SYS_FILES),  //! The volume contains system or paging files.
		_MakeErrorCodeName(ERROR_INDIGENOUS_TYPE),  //! The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.
		_MakeErrorCodeName(ERROR_NO_SUPPORTING_DRIVES),  //! This offline media cannot be mounted on this system since no enabled drives are present which can be used.
		_MakeErrorCodeName(ERROR_CLEANER_CARTRIDGE_INSTALLED),  //! A cleaner cartridge is present in the tape library.
		_MakeErrorCodeName(ERROR_IEPORT_FULL),  //! Cannot use the inject/eject port because it is not empty.
		_MakeErrorCodeName(ERROR_FILE_OFFLINE),  //! This file is currently not available for use on this computer.
		_MakeErrorCodeName(ERROR_REMOTE_STORAGE_NOT_ACTIVE),  //! The remote storage service is not operational at this time.
		_MakeErrorCodeName(ERROR_REMOTE_STORAGE_MEDIA_ERROR),  //! The remote storage service encountered a media error.
		_MakeErrorCodeName(ERROR_NOT_A_REPARSE_POINT),  //! The file or directory is not a reparse point.
		_MakeErrorCodeName(ERROR_REPARSE_ATTRIBUTE_CONFLICT),  //! The reparse point attribute cannot be set because it conflicts with an existing attribute.
		_MakeErrorCodeName(ERROR_INVALID_REPARSE_DATA),  //! The data present in the reparse point buffer is invalid.
		_MakeErrorCodeName(ERROR_REPARSE_TAG_INVALID),  //! The tag present in the reparse point buffer is invalid.
		_MakeErrorCodeName(ERROR_REPARSE_TAG_MISMATCH),  //! There is a mismatch between the tag specified in the request and the tag present in the reparse point.
		_MakeErrorCodeName(ERROR_APP_DATA_NOT_FOUND),  //! Fast Cache data not found.
		_MakeErrorCodeName(ERROR_APP_DATA_EXPIRED),  //! Fast Cache data expired.
		_MakeErrorCodeName(ERROR_APP_DATA_CORRUPT),  //! Fast Cache data corrupt.
		_MakeErrorCodeName(ERROR_APP_DATA_LIMIT_EXCEEDED),  //! Fast Cache data has exceeded its max size and cannot be updated.
		_MakeErrorCodeName(ERROR_APP_DATA_REBOOT_REQUIRED),  //! Fast Cache has been ReArmed and requires a reboot until it can be updated.
		_MakeErrorCodeName(ERROR_SECUREBOOT_ROLLBACK_DETECTED),  //! Secure Boot detected that rollback of protected data has been attempted.
		_MakeErrorCodeName(ERROR_SECUREBOOT_POLICY_VIOLATION),  //! The value is protected by Secure Boot policy and cannot be modified or deleted.
		_MakeErrorCodeName(ERROR_SECUREBOOT_INVALID_POLICY),  //! The Secure Boot policy is invalid.
		_MakeErrorCodeName(ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND),  //! A new Secure Boot policy did not contain the current publisher on its update list.
		_MakeErrorCodeName(ERROR_SECUREBOOT_POLICY_NOT_SIGNED),  //! The Secure Boot policy is either not signed or is signed by a non-trusted signer.
		_MakeErrorCodeName(ERROR_SECUREBOOT_NOT_ENABLED),  //! Secure Boot is not enabled on this machine.
		_MakeErrorCodeName(ERROR_SECUREBOOT_FILE_REPLACED),  //! Secure Boot requires that certain files and drivers are not replaced by other files or drivers.
		_MakeErrorCodeName(ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED),  //! The copy offload read operation is not supported by a filter.
		_MakeErrorCodeName(ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED),  //! The copy offload write operation is not supported by a filter.
		_MakeErrorCodeName(ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED),  //! The copy offload read operation is not supported for the file.
		_MakeErrorCodeName(ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED),  //! The copy offload write operation is not supported for the file.
		_MakeErrorCodeName(ERROR_VOLUME_NOT_SIS_ENABLED),  //! Single Instance Storage is not available on this volume.
		_MakeErrorCodeName(ERROR_DEPENDENT_RESOURCE_EXISTS),  //! The operation cannot be completed because other resources are dependent on this resource.
		_MakeErrorCodeName(ERROR_DEPENDENCY_NOT_FOUND),  //! The cluster resource dependency cannot be found.
		_MakeErrorCodeName(ERROR_DEPENDENCY_ALREADY_EXISTS),  //! The cluster resource cannot be made dependent on the specified resource because it is already dependent.
		_MakeErrorCodeName(ERROR_RESOURCE_NOT_ONLINE),  //! The cluster resource is not online.
		_MakeErrorCodeName(ERROR_HOST_NODE_NOT_AVAILABLE),  //! A cluster node is not available for this operation.
		_MakeErrorCodeName(ERROR_RESOURCE_NOT_AVAILABLE),  //! The cluster resource is not available.
		_MakeErrorCodeName(ERROR_RESOURCE_NOT_FOUND),  //! The cluster resource could not be found.
		_MakeErrorCodeName(ERROR_SHUTDOWN_CLUSTER),  //! The cluster is being shut down.
		_MakeErrorCodeName(ERROR_CANT_EVICT_ACTIVE_NODE),  //! A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.
		_MakeErrorCodeName(ERROR_OBJECT_ALREADY_EXISTS),  //! The object already exists.
		_MakeErrorCodeName(ERROR_OBJECT_IN_LIST),  //! The object is already in the list.
		_MakeErrorCodeName(ERROR_GROUP_NOT_AVAILABLE),  //! The cluster group is not available for any new requests.
		_MakeErrorCodeName(ERROR_GROUP_NOT_FOUND),  //! The cluster group could not be found.
		_MakeErrorCodeName(ERROR_GROUP_NOT_ONLINE),  //! The operation could not be completed because the cluster group is not online.
		_MakeErrorCodeName(ERROR_HOST_NODE_NOT_RESOURCE_OWNER),  //! The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource.
		_MakeErrorCodeName(ERROR_HOST_NODE_NOT_GROUP_OWNER),  //! The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group.
		_MakeErrorCodeName(ERROR_RESMON_CREATE_FAILED),  //! The cluster resource could not be created in the specified resource monitor.
		_MakeErrorCodeName(ERROR_RESMON_ONLINE_FAILED),  //! The cluster resource could not be brought online by the resource monitor.
		_MakeErrorCodeName(ERROR_RESOURCE_ONLINE),  //! The operation could not be completed because the cluster resource is online.
		_MakeErrorCodeName(ERROR_QUORUM_RESOURCE),  //! The cluster resource could not be deleted or brought offline because it is the quorum resource.
		_MakeErrorCodeName(ERROR_NOT_QUORUM_CAPABLE),  //! The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.
		_MakeErrorCodeName(ERROR_CLUSTER_SHUTTING_DOWN),  //! The cluster software is shutting down.
		_MakeErrorCodeName(ERROR_INVALID_STATE),  //! The group or resource is not in the correct state to perform the requested operation.
		_MakeErrorCodeName(ERROR_RESOURCE_PROPERTIES_STORED),  //! The properties were stored but not all changes will take effect until the next time the resource is brought online.
		_MakeErrorCodeName(ERROR_NOT_QUORUM_CLASS),  //! The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.
		_MakeErrorCodeName(ERROR_CORE_RESOURCE),  //! The cluster resource could not be deleted since it is a core resource.
		_MakeErrorCodeName(ERROR_QUORUM_RESOURCE_ONLINE_FAILED),  //! The quorum resource failed to come online.
		_MakeErrorCodeName(ERROR_QUORUMLOG_OPEN_FAILED),  //! The quorum log could not be created or mounted successfully.
		_MakeErrorCodeName(ERROR_CLUSTERLOG_CORRUPT),  //! The cluster log is corrupt.
		_MakeErrorCodeName(ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE),  //! The record could not be written to the cluster log since it exceeds the maximum size.
		_MakeErrorCodeName(ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE),  //! The cluster log exceeds its maximum size.
		_MakeErrorCodeName(ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND),  //! No checkpoint record was found in the cluster log.
		_MakeErrorCodeName(ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE),  //! The minimum required disk space needed for logging is not available.
		_MakeErrorCodeName(ERROR_QUORUM_OWNER_ALIVE),  //! The cluster node failed to take control of the quorum resource because the resource is owned by another active node.
		_MakeErrorCodeName(ERROR_NETWORK_NOT_AVAILABLE),  //! A cluster network is not available for this operation.
		_MakeErrorCodeName(ERROR_NODE_NOT_AVAILABLE),  //! A cluster node is not available for this operation.
		_MakeErrorCodeName(ERROR_ALL_NODES_NOT_AVAILABLE),  //! All cluster nodes must be running to perform this operation.
		_MakeErrorCodeName(ERROR_RESOURCE_FAILED),  //! A cluster resource failed.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_NODE),  //! The cluster node is not valid.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_EXISTS),  //! The cluster node already exists.
		_MakeErrorCodeName(ERROR_CLUSTER_JOIN_IN_PROGRESS),  //! A node is in the process of joining the cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_NOT_FOUND),  //! The cluster node was not found.
		_MakeErrorCodeName(ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND),  //! The cluster local node information was not found.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_EXISTS),  //! The cluster network already exists.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_NOT_FOUND),  //! The cluster network was not found.
		_MakeErrorCodeName(ERROR_CLUSTER_NETINTERFACE_EXISTS),  //! The cluster network interface already exists.
		_MakeErrorCodeName(ERROR_CLUSTER_NETINTERFACE_NOT_FOUND),  //! The cluster network interface was not found.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_REQUEST),  //! The cluster request is not valid for this object.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_NETWORK_PROVIDER),  //! The cluster network provider is not valid.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_DOWN),  //! The cluster node is down.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_UNREACHABLE),  //! The cluster node is not reachable.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_NOT_MEMBER),  //! The cluster node is not a member of the cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS),  //! A cluster join operation is not in progress.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_NETWORK),  //! The cluster network is not valid.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_UP),  //! The cluster node is up.
		_MakeErrorCodeName(ERROR_CLUSTER_IPADDR_IN_USE),  //! The cluster IP address is already in use.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_NOT_PAUSED),  //! The cluster node is not paused.
		_MakeErrorCodeName(ERROR_CLUSTER_NO_SECURITY_CONTEXT),  //! No cluster security context is available.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_NOT_INTERNAL),  //! The cluster network is not configured for internal cluster communication.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_ALREADY_UP),  //! The cluster node is already up.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_ALREADY_DOWN),  //! The cluster node is already down.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_ALREADY_ONLINE),  //! The cluster network is already online.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE),  //! The cluster network is already offline.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_ALREADY_MEMBER),  //! The cluster node is already a member of the cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_LAST_INTERNAL_NETWORK),  //! The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS),  //! One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.
		_MakeErrorCodeName(ERROR_INVALID_OPERATION_ON_QUORUM),  //! This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list.
		_MakeErrorCodeName(ERROR_DEPENDENCY_NOT_ALLOWED),  //! The cluster quorum resource is not allowed to have any dependencies.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_PAUSED),  //! The cluster node is paused.
		_MakeErrorCodeName(ERROR_NODE_CANT_HOST_RESOURCE),  //! The cluster resource cannot be brought online. The owner node cannot run this resource.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_NOT_READY),  //! The cluster node is not ready to perform the requested operation.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_SHUTTING_DOWN),  //! The cluster node is shutting down.
		_MakeErrorCodeName(ERROR_CLUSTER_JOIN_ABORTED),  //! The cluster join operation was aborted.
		_MakeErrorCodeName(ERROR_CLUSTER_INCOMPATIBLE_VERSIONS),  //! The cluster join operation failed due to incompatible software versions between the joining node and its sponsor.
		_MakeErrorCodeName(ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED),  //! This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.
		_MakeErrorCodeName(ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED),  //! The system configuration changed during the cluster join or form operation. The join or form operation was aborted.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND),  //! The specified resource type was not found.
		_MakeErrorCodeName(ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED),  //! The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.
		_MakeErrorCodeName(ERROR_CLUSTER_RESNAME_NOT_FOUND),  //! The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.
		_MakeErrorCodeName(ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED),  //! No authentication package could be registered with the RPC server.
		_MakeErrorCodeName(ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST),  //! You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.
		_MakeErrorCodeName(ERROR_CLUSTER_DATABASE_SEQMISMATCH),  //! The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.
		_MakeErrorCodeName(ERROR_RESMON_INVALID_STATE),  //! The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.
		_MakeErrorCodeName(ERROR_CLUSTER_GUM_NOT_LOCKER),  //! A non locker code got a request to reserve the lock for making global updates.
		_MakeErrorCodeName(ERROR_QUORUM_DISK_NOT_FOUND),  //! The quorum disk could not be located by the cluster service.
		_MakeErrorCodeName(ERROR_DATABASE_BACKUP_CORRUPT),  //! The backed up cluster database is possibly corrupt.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT),  //! A DFS root already exists in this cluster node.
		_MakeErrorCodeName(ERROR_RESOURCE_PROPERTY_UNCHANGEABLE),  //! An attempt to modify a resource property failed because it conflicts with another existing property.
		_MakeErrorCodeName(ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE),  //! An operation was attempted that is incompatible with the current membership state of the node.
		_MakeErrorCodeName(ERROR_CLUSTER_QUORUMLOG_NOT_FOUND),  //! The quorum resource does not contain the quorum log.
		_MakeErrorCodeName(ERROR_CLUSTER_MEMBERSHIP_HALT),  //! The membership engine requested shutdown of the cluster service on this node.
		_MakeErrorCodeName(ERROR_CLUSTER_INSTANCE_ID_MISMATCH),  //! The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.
		_MakeErrorCodeName(ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP),  //! A matching cluster network for the specified IP address could not be found.
		_MakeErrorCodeName(ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH),  //! The actual data type of the property did not match the expected data type of the property.
		_MakeErrorCodeName(ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP),  //! The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.
		_MakeErrorCodeName(ERROR_CLUSTER_PARAMETER_MISMATCH),  //! Two or more parameter values specified for a resource's properties are in conflict.
		_MakeErrorCodeName(ERROR_NODE_CANNOT_BE_CLUSTERED),  //! This computer cannot be made a member of a cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_WRONG_OS_VERSION),  //! This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.
		_MakeErrorCodeName(ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME),  //! A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.
		_MakeErrorCodeName(ERROR_CLUSCFG_ALREADY_COMMITTED),  //! The cluster configuration action has already been committed.
		_MakeErrorCodeName(ERROR_CLUSCFG_ROLLBACK_FAILED),  //! The cluster configuration action could not be rolled back.
		_MakeErrorCodeName(ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT),  //! The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.
		_MakeErrorCodeName(ERROR_CLUSTER_OLD_VERSION),  //! One or more nodes in the cluster are running a version of Windows that does not support this operation.
		_MakeErrorCodeName(ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME),  //! The name of the corresponding computer account doesn't match the Network Name for this resource.
		_MakeErrorCodeName(ERROR_CLUSTER_NO_NET_ADAPTERS),  //! No network adapters are available.
		_MakeErrorCodeName(ERROR_CLUSTER_POISONED),  //! The cluster node has been poisoned.
		_MakeErrorCodeName(ERROR_CLUSTER_GROUP_MOVING),  //! The group is unable to accept the request since it is moving to another node.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_TYPE_BUSY),  //! The resource type cannot accept the request since is too busy performing another operation.
		_MakeErrorCodeName(ERROR_RESOURCE_CALL_TIMED_OUT),  //! The call to the cluster resource DLL timed out.
		_MakeErrorCodeName(ERROR_INVALID_CLUSTER_IPV6_ADDRESS),  //! The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.
		_MakeErrorCodeName(ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION),  //! An internal cluster error occurred. A call to an invalid function was attempted.
		_MakeErrorCodeName(ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS),  //! A parameter value is out of acceptable range.
		_MakeErrorCodeName(ERROR_CLUSTER_PARTIAL_SEND),  //! A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.
		_MakeErrorCodeName(ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION),  //! An invalid cluster registry operation was attempted.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_STRING_TERMINATION),  //! An input string of characters is not properly terminated.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_STRING_FORMAT),  //! An input string of characters is not in a valid format for the data it represents.
		_MakeErrorCodeName(ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS),  //! An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.
		_MakeErrorCodeName(ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS),  //! An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.
		_MakeErrorCodeName(ERROR_CLUSTER_NULL_DATA),  //! An internal cluster error occurred. Data was not properly initialized.
		_MakeErrorCodeName(ERROR_CLUSTER_PARTIAL_READ),  //! An error occurred while reading from a stream of data. An unexpected number of bytes was returned.
		_MakeErrorCodeName(ERROR_CLUSTER_PARTIAL_WRITE),  //! An error occurred while writing to a stream of data. The required number of bytes could not be written.
		_MakeErrorCodeName(ERROR_CLUSTER_CANT_DESERIALIZE_DATA),  //! An error occurred while deserializing a stream of cluster data.
		_MakeErrorCodeName(ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT),  //! One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).
		_MakeErrorCodeName(ERROR_CLUSTER_NO_QUORUM),  //! A quorum of cluster nodes was not present to form a cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_IPV6_NETWORK),  //! The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK),  //! The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.
		_MakeErrorCodeName(ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP),  //! Quorum resource cannot reside in the Available Storage group.
		_MakeErrorCodeName(ERROR_DEPENDENCY_TREE_TOO_COMPLEX),  //! The dependencies for this resource are nested too deeply.
		_MakeErrorCodeName(ERROR_EXCEPTION_IN_RESOURCE_CALL),  //! The call into the resource DLL raised an unhandled exception.
		_MakeErrorCodeName(ERROR_CLUSTER_RHS_FAILED_INITIALIZATION),  //! The RHS process failed to initialize.
		_MakeErrorCodeName(ERROR_CLUSTER_NOT_INSTALLED),  //! The Failover Clustering feature is not installed on this node.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE),  //! The resources must be online on the same node for this operation.
		_MakeErrorCodeName(ERROR_CLUSTER_MAX_NODES_IN_CLUSTER),  //! A new node can not be added since this cluster is already at its maximum number of nodes.
		_MakeErrorCodeName(ERROR_CLUSTER_TOO_MANY_NODES),  //! This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.
		_MakeErrorCodeName(ERROR_CLUSTER_OBJECT_ALREADY_USED),  //! An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain.
		_MakeErrorCodeName(ERROR_NONCORE_GROUPS_FOUND),  //! This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.
		_MakeErrorCodeName(ERROR_FILE_SHARE_RESOURCE_CONFLICT),  //! File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.
		_MakeErrorCodeName(ERROR_CLUSTER_EVICT_INVALID_REQUEST),  //! Eviction of this node is invalid at this time. Due to quorum requirements node eviction will result in cluster shutdown. If it is the last node in the cluster, destroy cluster command should be used.
		_MakeErrorCodeName(ERROR_CLUSTER_SINGLETON_RESOURCE),  //! Only one instance of this resource type is allowed in the cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE),  //! Only one instance of this resource type is allowed per resource group.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED),  //! The resource failed to come online due to the failure of one or more provider resources.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR),  //! The resource has indicated that it cannot come online on any node.
		_MakeErrorCodeName(ERROR_CLUSTER_GROUP_BUSY),  //! The current operation cannot be performed on this group at this time.
		_MakeErrorCodeName(ERROR_CLUSTER_NOT_SHARED_VOLUME),  //! The directory or file is not located on a cluster shared volume.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR),  //! The Security Descriptor does not meet the requirements for a cluster.
		_MakeErrorCodeName(ERROR_CLUSTER_SHARED_VOLUMES_IN_USE),  //! There is one or more shared volumes resources configured in the cluster. Those resources must be moved to available storage in order for operation to succeed.
		_MakeErrorCodeName(ERROR_CLUSTER_USE_SHARED_VOLUMES_API),  //! This group or resource cannot be directly manipulated. Use shared volume APIs to perform desired operation.
		_MakeErrorCodeName(ERROR_CLUSTER_BACKUP_IN_PROGRESS),  //! Back up is in progress. Please wait for backup completion before trying this operation again.
		_MakeErrorCodeName(ERROR_NON_CSV_PATH),  //! The path does not belong to a cluster shared volume.
		_MakeErrorCodeName(ERROR_CSV_VOLUME_NOT_LOCAL),  //! The cluster shared volume is not locally mounted on this node.
		_MakeErrorCodeName(ERROR_CLUSTER_WATCHDOG_TERMINATING),  //! The cluster watchdog is terminating.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES),  //! A resource vetoed a move between two nodes because they are incompatible.
		_MakeErrorCodeName(ERROR_CLUSTER_INVALID_NODE_WEIGHT),  //! The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_VETOED_CALL),  //! The resource vetoed the call.
		_MakeErrorCodeName(ERROR_RESMON_SYSTEM_RESOURCES_LACKING),  //! Resource could not start or run because it could not reserve sufficient system resources.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION),  //! A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE),  //! A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation.
		_MakeErrorCodeName(ERROR_CLUSTER_GROUP_QUEUED),  //! The requested operation can not be completed because the group is queued for an operation.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_LOCKED_STATUS),  //! The requested operation can not be completed because a resource has locked status.
		_MakeErrorCodeName(ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED),  //! The resource cannot move to another node because a cluster shared volume vetoed the operation.
		_MakeErrorCodeName(ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS),  //! A node drain is already in progress.
		_MakeErrorCodeName(ERROR_CLUSTER_DISK_NOT_CONNECTED),  //! Clustered storage is not connected to the node.
		_MakeErrorCodeName(ERROR_DISK_NOT_CSV_CAPABLE),  //! The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS.
		_MakeErrorCodeName(ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE),  //! The resource must be part of the Available Storage group to complete this action.
		_MakeErrorCodeName(ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED),  //! CSVFS failed operation as volume is in redirected mode.
		_MakeErrorCodeName(ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED),  //! CSVFS failed operation as volume is not in redirected mode.
		_MakeErrorCodeName(ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES),  //! Cluster properties cannot be returned at this time.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES),  //! The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE),  //! The operation cannot be completed because the resource is in maintenance mode.
		_MakeErrorCodeName(ERROR_CLUSTER_AFFINITY_CONFLICT),  //! The operation cannot be completed because of cluster affinity conflicts.
		_MakeErrorCodeName(ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE),  //! The operation cannot be completed because the resource is a replica virtual machine.
		_MakeErrorCodeName(ERROR_ENCRYPTION_FAILED),  //! The specified file could not be encrypted.
		_MakeErrorCodeName(ERROR_DECRYPTION_FAILED),  //! The specified file could not be decrypted.
		_MakeErrorCodeName(ERROR_FILE_ENCRYPTED),  //! The specified file is encrypted and the user does not have the ability to decrypt it.
		_MakeErrorCodeName(ERROR_NO_RECOVERY_POLICY),  //! There is no valid encryption recovery policy configured for this system.
		_MakeErrorCodeName(ERROR_NO_EFS),  //! The required encryption driver is not loaded for this system.
		_MakeErrorCodeName(ERROR_WRONG_EFS),  //! The file was encrypted with a different encryption driver than is currently loaded.
		_MakeErrorCodeName(ERROR_NO_USER_KEYS),  //! There are no EFS keys defined for the user.
		_MakeErrorCodeName(ERROR_FILE_NOT_ENCRYPTED),  //! The specified file is not encrypted.
		_MakeErrorCodeName(ERROR_NOT_EXPORT_FORMAT),  //! The specified file is not in the defined EFS export format.
		_MakeErrorCodeName(ERROR_FILE_READ_ONLY),  //! The specified file is read only.
		_MakeErrorCodeName(ERROR_DIR_EFS_DISALLOWED),  //! The directory has been disabled for encryption.
		_MakeErrorCodeName(ERROR_EFS_SERVER_NOT_TRUSTED),  //! The server is not trusted for remote encryption operation.
		_MakeErrorCodeName(ERROR_BAD_RECOVERY_POLICY),  //! Recovery policy configured for this system contains invalid recovery certificate.
		_MakeErrorCodeName(ERROR_EFS_ALG_BLOB_TOO_BIG),  //! The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.
		_MakeErrorCodeName(ERROR_VOLUME_NOT_SUPPORT_EFS),  //! The disk partition does not support file encryption.
		_MakeErrorCodeName(ERROR_EFS_DISABLED),  //! This machine is disabled for file encryption.
		_MakeErrorCodeName(ERROR_EFS_VERSION_NOT_SUPPORT),  //! A newer system is required to decrypt this encrypted file.
		_MakeErrorCodeName(ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE),  //! The remote server sent an invalid response for a file being opened with Client Side Encryption.
		_MakeErrorCodeName(ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER),  //! Client Side Encryption is not supported by the remote server even though it claims to support it.
		_MakeErrorCodeName(ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE),  //! File is encrypted and should be opened in Client Side Encryption mode.
		_MakeErrorCodeName(ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE),  //! A new encrypted file is being created and a $EFS needs to be provided.
		_MakeErrorCodeName(ERROR_CS_ENCRYPTION_FILE_NOT_CSE),  //! The SMB client requested a CSE FSCTL on a non-CSE file.
		_MakeErrorCodeName(ERROR_ENCRYPTION_POLICY_DENIES_OPERATION),  //! The requested operation was blocked by policy. For more information, contact your system administrator.
		_MakeErrorCodeName(ERROR_NO_BROWSER_SERVERS_FOUND),  //! The list of servers for this workgroup is not currently available.
		_MakeErrorCodeName(SCHED_E_SERVICE_NOT_LOCALSYSTEM),  //! The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.
		_MakeErrorCodeName(ERROR_LOG_SECTOR_INVALID),  //! Log service encountered an invalid log sector.
		_MakeErrorCodeName(ERROR_LOG_SECTOR_PARITY_INVALID),  //! Log service encountered a log sector with invalid block parity.
		_MakeErrorCodeName(ERROR_LOG_SECTOR_REMAPPED),  //! Log service encountered a remapped log sector.
		_MakeErrorCodeName(ERROR_LOG_BLOCK_INCOMPLETE),  //! Log service encountered a partial or incomplete log block.
		_MakeErrorCodeName(ERROR_LOG_INVALID_RANGE),  //! Log service encountered an attempt access data outside the active log range.
		_MakeErrorCodeName(ERROR_LOG_BLOCKS_EXHAUSTED),  //! Log service user marshalling buffers are exhausted.
		_MakeErrorCodeName(ERROR_LOG_READ_CONTEXT_INVALID),  //! Log service encountered an attempt read from a marshalling area with an invalid read context.
		_MakeErrorCodeName(ERROR_LOG_RESTART_INVALID),  //! Log service encountered an invalid log restart area.
		_MakeErrorCodeName(ERROR_LOG_BLOCK_VERSION),  //! Log service encountered an invalid log block version.
		_MakeErrorCodeName(ERROR_LOG_BLOCK_INVALID),  //! Log service encountered an invalid log block.
		_MakeErrorCodeName(ERROR_LOG_READ_MODE_INVALID),  //! Log service encountered an attempt to read the log with an invalid read mode.
		_MakeErrorCodeName(ERROR_LOG_NO_RESTART),  //! Log service encountered a log stream with no restart area.
		_MakeErrorCodeName(ERROR_LOG_METADATA_CORRUPT),  //! Log service encountered a corrupted metadata file.
		_MakeErrorCodeName(ERROR_LOG_METADATA_INVALID),  //! Log service encountered a metadata file that could not be created by the log file system.
		_MakeErrorCodeName(ERROR_LOG_METADATA_INCONSISTENT),  //! Log service encountered a metadata file with inconsistent data.
		_MakeErrorCodeName(ERROR_LOG_RESERVATION_INVALID),  //! Log service encountered an attempt to erroneous allocate or dispose reservation space.
		_MakeErrorCodeName(ERROR_LOG_CANT_DELETE),  //! Log service cannot delete log file or file system container.
		_MakeErrorCodeName(ERROR_LOG_CONTAINER_LIMIT_EXCEEDED),  //! Log service has reached the maximum allowable containers allocated to a log file.
		_MakeErrorCodeName(ERROR_LOG_START_OF_LOG),  //! Log service has attempted to read or write backward past the start of the log.
		_MakeErrorCodeName(ERROR_LOG_POLICY_ALREADY_INSTALLED),  //! Log policy could not be installed because a policy of the same type is already present.
		_MakeErrorCodeName(ERROR_LOG_POLICY_NOT_INSTALLED),  //! Log policy in question was not installed at the time of the request.
		_MakeErrorCodeName(ERROR_LOG_POLICY_INVALID),  //! The installed set of policies on the log is invalid.
		_MakeErrorCodeName(ERROR_LOG_POLICY_CONFLICT),  //! A policy on the log in question prevented the operation from completing.
		_MakeErrorCodeName(ERROR_LOG_PINNED_ARCHIVE_TAIL),  //! Log space cannot be reclaimed because the log is pinned by the archive tail.
		_MakeErrorCodeName(ERROR_LOG_RECORD_NONEXISTENT),  //! Log record is not a record in the log file.
		_MakeErrorCodeName(ERROR_LOG_RECORDS_RESERVED_INVALID),  //! Number of reserved log records or the adjustment of the number of reserved log records is invalid.
		_MakeErrorCodeName(ERROR_LOG_SPACE_RESERVED_INVALID),  //! Reserved log space or the adjustment of the log space is invalid.
		_MakeErrorCodeName(ERROR_LOG_TAIL_INVALID),  //! An new or existing archive tail or base of the active log is invalid.
		_MakeErrorCodeName(ERROR_LOG_FULL),  //! Log space is exhausted.
		_MakeErrorCodeName(ERROR_COULD_NOT_RESIZE_LOG),  //! The log could not be set to the requested size.
		_MakeErrorCodeName(ERROR_LOG_MULTIPLEXED),  //! Log is multiplexed, no direct writes to the physical log is allowed.
		_MakeErrorCodeName(ERROR_LOG_DEDICATED),  //! The operation failed because the log is a dedicated log.
		_MakeErrorCodeName(ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS),  //! The operation requires an archive context.
		_MakeErrorCodeName(ERROR_LOG_ARCHIVE_IN_PROGRESS),  //! Log archival is in progress.
		_MakeErrorCodeName(ERROR_LOG_EPHEMERAL),  //! The operation requires a non-ephemeral log, but the log is ephemeral.
		_MakeErrorCodeName(ERROR_LOG_NOT_ENOUGH_CONTAINERS),  //! The log must have at least two containers before it can be read from or written to.
		_MakeErrorCodeName(ERROR_LOG_CLIENT_ALREADY_REGISTERED),  //! A log client has already registered on the stream.
		_MakeErrorCodeName(ERROR_LOG_CLIENT_NOT_REGISTERED),  //! A log client has not been registered on the stream.
		_MakeErrorCodeName(ERROR_LOG_FULL_HANDLER_IN_PROGRESS),  //! A request has already been made to handle the log full condition.
		_MakeErrorCodeName(ERROR_LOG_CONTAINER_READ_FAILED),  //! Log service encountered an error when attempting to read from a log container.
		_MakeErrorCodeName(ERROR_LOG_CONTAINER_WRITE_FAILED),  //! Log service encountered an error when attempting to write to a log container.
		_MakeErrorCodeName(ERROR_LOG_CONTAINER_OPEN_FAILED),  //! Log service encountered an error when attempting open a log container.
		_MakeErrorCodeName(ERROR_LOG_CONTAINER_STATE_INVALID),  //! Log service encountered an invalid container state when attempting a requested action.
		_MakeErrorCodeName(ERROR_LOG_STATE_INVALID),  //! Log service is not in the correct state to perform a requested action.
		_MakeErrorCodeName(ERROR_LOG_PINNED),  //! Log space cannot be reclaimed because the log is pinned.
		_MakeErrorCodeName(ERROR_LOG_METADATA_FLUSH_FAILED),  //! Log metadata flush failed.
		_MakeErrorCodeName(ERROR_LOG_INCONSISTENT_SECURITY),  //! Security on the log and its containers is inconsistent.
		_MakeErrorCodeName(ERROR_LOG_APPENDED_FLUSH_FAILED),  //! Records were appended to the log or reservation changes were made, but the log could not be flushed.
		_MakeErrorCodeName(ERROR_LOG_PINNED_RESERVATION),  //! The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.
		_MakeErrorCodeName(ERROR_INVALID_TRANSACTION),  //! The transaction handle associated with this operation is not valid.
		_MakeErrorCodeName(ERROR_TRANSACTION_NOT_ACTIVE),  //! The requested operation was made in the context of a transaction that is no longer active.
		_MakeErrorCodeName(ERROR_TRANSACTION_REQUEST_NOT_VALID),  //! The requested operation is not valid on the Transaction object in its current state.
		_MakeErrorCodeName(ERROR_TRANSACTION_NOT_REQUESTED),  //! The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.
		_MakeErrorCodeName(ERROR_TRANSACTION_ALREADY_ABORTED),  //! It is too late to perform the requested operation, since the Transaction has already been aborted.
		_MakeErrorCodeName(ERROR_TRANSACTION_ALREADY_COMMITTED),  //! It is too late to perform the requested operation, since the Transaction has already been committed.
		_MakeErrorCodeName(ERROR_TM_INITIALIZATION_FAILED),  //! The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.
		_MakeErrorCodeName(ERROR_RESOURCEMANAGER_READ_ONLY),  //! The specified ResourceManager made no changes or updates to the resource under this transaction.
		_MakeErrorCodeName(ERROR_TRANSACTION_NOT_JOINED),  //! The resource manager has attempted to prepare a transaction that it has not successfully joined.
		_MakeErrorCodeName(ERROR_TRANSACTION_SUPERIOR_EXISTS),  //! The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.
		_MakeErrorCodeName(ERROR_CRM_PROTOCOL_ALREADY_EXISTS),  //! The RM tried to register a protocol that already exists.
		_MakeErrorCodeName(ERROR_TRANSACTION_PROPAGATION_FAILED),  //! The attempt to propagate the Transaction failed.
		_MakeErrorCodeName(ERROR_CRM_PROTOCOL_NOT_FOUND),  //! The requested propagation protocol was not registered as a CRM.
		_MakeErrorCodeName(ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER),  //! The buffer passed in to PushTransaction or PullTransaction is not in a valid format.
		_MakeErrorCodeName(ERROR_CURRENT_TRANSACTION_NOT_VALID),  //! The current transaction context associated with the thread is not a valid handle to a transaction object.
		_MakeErrorCodeName(ERROR_TRANSACTION_NOT_FOUND),  //! The specified Transaction object could not be opened, because it was not found.
		_MakeErrorCodeName(ERROR_RESOURCEMANAGER_NOT_FOUND),  //! The specified ResourceManager object could not be opened, because it was not found.
		_MakeErrorCodeName(ERROR_ENLISTMENT_NOT_FOUND),  //! The specified Enlistment object could not be opened, because it was not found.
		_MakeErrorCodeName(ERROR_TRANSACTIONMANAGER_NOT_FOUND),  //! The specified TransactionManager object could not be opened, because it was not found.
		_MakeErrorCodeName(ERROR_TRANSACTIONMANAGER_NOT_ONLINE),  //! The object specified could not be created or opened, because its associated TransactionManager is not online. The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened. In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.
		_MakeErrorCodeName(ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION),  //! The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.
		_MakeErrorCodeName(ERROR_TRANSACTION_NOT_ROOT),  //! The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.
		_MakeErrorCodeName(ERROR_TRANSACTION_OBJECT_EXPIRED),  //! Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.
		_MakeErrorCodeName(ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED),  //! The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.
		_MakeErrorCodeName(ERROR_TRANSACTION_RECORD_TOO_LONG),  //! The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions: either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.
		_MakeErrorCodeName(ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED),  //! Implicit transaction are not supported.
		_MakeErrorCodeName(ERROR_TRANSACTION_INTEGRITY_VIOLATED),  //! The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.
		_MakeErrorCodeName(ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH),  //! The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.
		_MakeErrorCodeName(ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT),  //! This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state. Please try again.
		_MakeErrorCodeName(ERROR_TRANSACTION_MUST_WRITETHROUGH),  //! The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase. In order to ensure correctness, the ResourceManager must switch to a write- through mode and cease caching data within this transaction. Enlisting for only subsequent transaction phases may still succeed.
		_MakeErrorCodeName(ERROR_TRANSACTION_NO_SUPERIOR),  //! The transaction does not have a superior enlistment.
		_MakeErrorCodeName(ERROR_HEURISTIC_DAMAGE_POSSIBLE),  //! The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics. Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency. If possible, check the consistency of the associated data.
		_MakeErrorCodeName(ERROR_TRANSACTIONAL_CONFLICT),  //! The function attempted to use a name that is reserved for use by another transaction.
		_MakeErrorCodeName(ERROR_RM_NOT_ACTIVE),  //! Transaction support within the specified resource manager is not started or was shut down due to an error.
		_MakeErrorCodeName(ERROR_RM_METADATA_CORRUPT),  //! The metadata of the RM has been corrupted. The RM will not function.
		_MakeErrorCodeName(ERROR_DIRECTORY_NOT_RM),  //! The specified directory does not contain a resource manager.
		_MakeErrorCodeName(ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE),  //! The remote server or share does not support transacted file operations.
		_MakeErrorCodeName(ERROR_LOG_RESIZE_INVALID_SIZE),  //! The requested log size is invalid.
		_MakeErrorCodeName(ERROR_OBJECT_NO_LONGER_EXISTS),  //! The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.
		_MakeErrorCodeName(ERROR_STREAM_MINIVERSION_NOT_FOUND),  //! The specified file miniversion was not found for this transacted file open.
		_MakeErrorCodeName(ERROR_STREAM_MINIVERSION_NOT_VALID),  //! The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.
		_MakeErrorCodeName(ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION),  //! A miniversion may only be opened in the context of the transaction that created it.
		_MakeErrorCodeName(ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT),  //! It is not possible to open a miniversion with modify access.
		_MakeErrorCodeName(ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS),  //! It is not possible to create any more miniversions for this stream.
		_MakeErrorCodeName(ERROR_REMOTE_FILE_VERSION_MISMATCH),  //! The remote server sent mismatching version number or Fid for a file opened with transactions.
		_MakeErrorCodeName(ERROR_HANDLE_NO_LONGER_VALID),  //! The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.
		_MakeErrorCodeName(ERROR_NO_TXF_METADATA),  //! There is no transaction metadata on the file.
		_MakeErrorCodeName(ERROR_LOG_CORRUPTION_DETECTED),  //! The log data is corrupt.
		_MakeErrorCodeName(ERROR_CANT_RECOVER_WITH_HANDLE_OPEN),  //! The file can't be recovered because there is a handle still open on it.
		_MakeErrorCodeName(ERROR_RM_DISCONNECTED),  //! The transaction outcome is unavailable because the resource manager responsible for it has disconnected.
		_MakeErrorCodeName(ERROR_ENLISTMENT_NOT_SUPERIOR),  //! The request was rejected because the enlistment in question is not a superior enlistment.
		_MakeErrorCodeName(ERROR_RECOVERY_NOT_NEEDED),  //! The transactional resource manager is already consistent. Recovery is not needed.
		_MakeErrorCodeName(ERROR_RM_ALREADY_STARTED),  //! The transactional resource manager has already been started.
		_MakeErrorCodeName(ERROR_FILE_IDENTITY_NOT_PERSISTENT),  //! The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.
		_MakeErrorCodeName(ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY),  //! The operation cannot be performed because another transaction is depending on the fact that this property will not change.
		_MakeErrorCodeName(ERROR_CANT_CROSS_RM_BOUNDARY),  //! The operation would involve a single file with two transactional resource managers and is therefore not allowed.
		_MakeErrorCodeName(ERROR_TXF_DIR_NOT_EMPTY),  //! The $Txf directory must be empty for this operation to succeed.
		_MakeErrorCodeName(ERROR_INDOUBT_TRANSACTIONS_EXIST),  //! The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.
		_MakeErrorCodeName(ERROR_TM_VOLATILE),  //! The operation could not be completed because the transaction manager does not have a log.
		_MakeErrorCodeName(ERROR_ROLLBACK_TIMER_EXPIRED),  //! A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.
		_MakeErrorCodeName(ERROR_TXF_ATTRIBUTE_CORRUPT),  //! The transactional metadata attribute on the file or directory is corrupt and unreadable.
		_MakeErrorCodeName(ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION),  //! The encryption operation could not be completed because a transaction is active.
		_MakeErrorCodeName(ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED),  //! This object is not allowed to be opened in a transaction.
		_MakeErrorCodeName(ERROR_LOG_GROWTH_FAILED),  //! An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.
		_MakeErrorCodeName(ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE),  //! Memory mapping (creating a mapped section) a remote file under a transaction is not supported.
		_MakeErrorCodeName(ERROR_TXF_METADATA_ALREADY_PRESENT),  //! Transaction metadata is already present on this file and cannot be superseded.
		_MakeErrorCodeName(ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET),  //! A transaction scope could not be entered because the scope handler has not been initialized.
		_MakeErrorCodeName(ERROR_TRANSACTION_REQUIRED_PROMOTION),  //! Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.
		_MakeErrorCodeName(ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION),  //! This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.
		_MakeErrorCodeName(ERROR_TRANSACTIONS_NOT_FROZEN),  //! The request to thaw frozen transactions was ignored because transactions had not previously been frozen.
		_MakeErrorCodeName(ERROR_TRANSACTION_FREEZE_IN_PROGRESS),  //! Transactions cannot be frozen because a freeze is already in progress.
		_MakeErrorCodeName(ERROR_NOT_SNAPSHOT_VOLUME),  //! The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.
		_MakeErrorCodeName(ERROR_NO_SAVEPOINT_WITH_OPEN_FILES),  //! The savepoint operation failed because files are open on the transaction. This is not permitted.
		_MakeErrorCodeName(ERROR_DATA_LOST_REPAIR),  //! Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.
		_MakeErrorCodeName(ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION),  //! The sparse operation could not be completed because a transaction is active on the file.
		_MakeErrorCodeName(ERROR_TM_IDENTITY_MISMATCH),  //! The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.
		_MakeErrorCodeName(ERROR_FLOATED_SECTION),  //! I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.
		_MakeErrorCodeName(ERROR_CANNOT_ACCEPT_TRANSACTED_WORK),  //! The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.
		_MakeErrorCodeName(ERROR_CANNOT_ABORT_TRANSACTIONS),  //! The transactional resource manager had too many tranactions outstanding that could not be aborted. The transactional resource manger has been shut down.
		_MakeErrorCodeName(ERROR_BAD_CLUSTERS),  //! The operation could not be completed due to bad clusters on disk.
		_MakeErrorCodeName(ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION),  //! The compression operation could not be completed because a transaction is active on the file.
		_MakeErrorCodeName(ERROR_VOLUME_DIRTY),  //! The operation could not be completed because the volume is dirty. Please run chkdsk and try again.
		_MakeErrorCodeName(ERROR_NO_LINK_TRACKING_IN_TRANSACTION),  //! The link tracking operation could not be completed because a transaction is active.
		_MakeErrorCodeName(ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION),  //! This operation cannot be performed in a transaction.
		_MakeErrorCodeName(ERROR_EXPIRED_HANDLE),  //! The handle is no longer properly associated with its transaction. It may have been opened in a transactional resource manager that was subsequently forced to restart. Please close the handle and open a new one.
		_MakeErrorCodeName(ERROR_TRANSACTION_NOT_ENLISTED),  //! The specified operation could not be performed because the resource manager is not enlisted in the transaction.
		_MakeErrorCodeName(ERROR_CTX_WINSTATION_NAME_INVALID),  //! The specified session name is invalid.
		_MakeErrorCodeName(ERROR_CTX_INVALID_PD),  //! The specified protocol driver is invalid.
		_MakeErrorCodeName(ERROR_CTX_PD_NOT_FOUND),  //! The specified protocol driver was not found in the system path.
		_MakeErrorCodeName(ERROR_CTX_WD_NOT_FOUND),  //! The specified terminal connection driver was not found in the system path.
		_MakeErrorCodeName(ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY),  //! A registry key for event logging could not be created for this session.
		_MakeErrorCodeName(ERROR_CTX_SERVICE_NAME_COLLISION),  //! A service with the same name already exists on the system.
		_MakeErrorCodeName(ERROR_CTX_CLOSE_PENDING),  //! A close operation is pending on the session.
		_MakeErrorCodeName(ERROR_CTX_NO_OUTBUF),  //! There are no free output buffers available.
		_MakeErrorCodeName(ERROR_CTX_MODEM_INF_NOT_FOUND),  //! The MODEM.INF file was not found.
		_MakeErrorCodeName(ERROR_CTX_INVALID_MODEMNAME),  //! The modem name was not found in MODEM.INF.
		_MakeErrorCodeName(ERROR_CTX_MODEM_RESPONSE_ERROR),  //! The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.
		_MakeErrorCodeName(ERROR_CTX_MODEM_RESPONSE_TIMEOUT),  //! The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.
		_MakeErrorCodeName(ERROR_CTX_MODEM_RESPONSE_NO_CARRIER),  //! Carrier detect has failed or carrier has been dropped due to disconnect.
		_MakeErrorCodeName(ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE),  //! Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.
		_MakeErrorCodeName(ERROR_CTX_MODEM_RESPONSE_BUSY),  //! Busy signal detected at remote site on callback.
		_MakeErrorCodeName(ERROR_CTX_MODEM_RESPONSE_VOICE),  //! Voice detected at remote site on callback.
		_MakeErrorCodeName(ERROR_CTX_TD_ERROR),  //! Transport driver error.
		_MakeErrorCodeName(ERROR_CTX_WINSTATION_NOT_FOUND),  //! The specified session cannot be found.
		_MakeErrorCodeName(ERROR_CTX_WINSTATION_ALREADY_EXISTS),  //! The specified session name is already in use.
		_MakeErrorCodeName(ERROR_CTX_WINSTATION_BUSY),  //! The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.
		_MakeErrorCodeName(ERROR_CTX_BAD_VIDEO_MODE),  //! An attempt has been made to connect to a session whose video mode is not supported by the current client.
		_MakeErrorCodeName(ERROR_CTX_GRAPHICS_INVALID),  //! The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.
		_MakeErrorCodeName(ERROR_CTX_LOGON_DISABLED),  //! Your interactive logon privilege has been disabled. Please contact your administrator.
		_MakeErrorCodeName(ERROR_CTX_NOT_CONSOLE),  //! The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.
		_MakeErrorCodeName(ERROR_CTX_CLIENT_QUERY_TIMEOUT),  //! The client failed to respond to the server connect message.
		_MakeErrorCodeName(ERROR_CTX_CONSOLE_DISCONNECT),  //! Disconnecting the console session is not supported.
		_MakeErrorCodeName(ERROR_CTX_CONSOLE_CONNECT),  //! Reconnecting a disconnected session to the console is not supported.
		_MakeErrorCodeName(ERROR_CTX_SHADOW_DENIED),  //! The request to control another session remotely was denied.
		_MakeErrorCodeName(ERROR_CTX_WINSTATION_ACCESS_DENIED),  //! The requested session access is denied.
		_MakeErrorCodeName(ERROR_CTX_INVALID_WD),  //! The specified terminal connection driver is invalid.
		_MakeErrorCodeName(ERROR_CTX_SHADOW_INVALID),  //! The requested session cannot be controlled remotely. This may be because the session is disconnected or does not currently have a user logged on.
		_MakeErrorCodeName(ERROR_CTX_SHADOW_DISABLED),  //! The requested session is not configured to allow remote control.
		_MakeErrorCodeName(ERROR_CTX_CLIENT_LICENSE_IN_USE),  //! Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.
		_MakeErrorCodeName(ERROR_CTX_CLIENT_LICENSE_NOT_SET),  //! Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.
		_MakeErrorCodeName(ERROR_CTX_LICENSE_NOT_AVAILABLE),  //! The number of connections to this computer is limited and all connections are in use right now. Try connecting later or contact your system administrator.
		_MakeErrorCodeName(ERROR_CTX_LICENSE_CLIENT_INVALID),  //! The client you are using is not licensed to use this system. Your logon request is denied.
		_MakeErrorCodeName(ERROR_CTX_LICENSE_EXPIRED),  //! The system license has expired. Your logon request is denied.
		_MakeErrorCodeName(ERROR_CTX_SHADOW_NOT_RUNNING),  //! Remote control could not be terminated because the specified session is not currently being remotely controlled.
		_MakeErrorCodeName(ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE),  //! The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.
		_MakeErrorCodeName(ERROR_ACTIVATION_COUNT_EXCEEDED),  //! Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.
		_MakeErrorCodeName(ERROR_CTX_WINSTATIONS_DISABLED),  //! Remote logins are currently disabled.
		_MakeErrorCodeName(ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED),  //! You do not have the proper encryption level to access this Session.
		_MakeErrorCodeName(ERROR_CTX_SESSION_IN_USE),  //! The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.
		_MakeErrorCodeName(ERROR_CTX_NO_FORCE_LOGOFF),  //! The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.
		_MakeErrorCodeName(ERROR_CTX_ACCOUNT_RESTRICTION),  //! Unable to log you on because of an account restriction.
		_MakeErrorCodeName(ERROR_RDP_PROTOCOL_ERROR),  //! The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.
		_MakeErrorCodeName(ERROR_CTX_CDM_CONNECT),  //! The Client Drive Mapping Service Has Connected on Terminal Connection.
		_MakeErrorCodeName(ERROR_CTX_CDM_DISCONNECT),  //! The Client Drive Mapping Service Has Disconnected on Terminal Connection.
		_MakeErrorCodeName(ERROR_CTX_SECURITY_LAYER_ERROR),  //! The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.
		_MakeErrorCodeName(ERROR_TS_INCOMPATIBLE_SESSIONS),  //! The target session is incompatible with the current session.
		_MakeErrorCodeName(ERROR_TS_VIDEO_SUBSYSTEM_ERROR),  //! Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.
		_MakeErrorCodeName(FRS_ERR_INVALID_API_SEQUENCE),  //! The file replication service API was called incorrectly.
		_MakeErrorCodeName(FRS_ERR_STARTING_SERVICE),  //! The file replication service cannot be started.
		_MakeErrorCodeName(FRS_ERR_STOPPING_SERVICE),  //! The file replication service cannot be stopped.
		_MakeErrorCodeName(FRS_ERR_INTERNAL_API),  //! The file replication service API terminated the request. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_INTERNAL),  //! The file replication service terminated the request. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_SERVICE_COMM),  //! The file replication service cannot be contacted. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_INSUFFICIENT_PRIV),  //! The file replication service cannot satisfy the request because the user has insufficient privileges. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_AUTHENTICATION),  //! The file replication service cannot satisfy the request because authenticated RPC is not available. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_PARENT_INSUFFICIENT_PRIV),  //! The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_PARENT_AUTHENTICATION),  //! The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_CHILD_TO_PARENT_COMM),  //! The file replication service cannot communicate with the file replication service on the domain controller. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_PARENT_TO_CHILD_COMM),  //! The file replication service on the domain controller cannot communicate with the file replication service on this computer. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_SYSVOL_POPULATE),  //! The file replication service cannot populate the system volume because of an internal error. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_SYSVOL_POPULATE_TIMEOUT),  //! The file replication service cannot populate the system volume because of an internal timeout. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_SYSVOL_IS_BUSY),  //! The file replication service cannot process the request. The system volume is busy with a previous request.
		_MakeErrorCodeName(FRS_ERR_SYSVOL_DEMOTE),  //! The file replication service cannot stop replicating the system volume because of an internal error. The event log may have more information.
		_MakeErrorCodeName(FRS_ERR_INVALID_SERVICE_PARAMETER),  //! The file replication service detected an invalid parameter.
		_MakeErrorCodeName(ERROR_DS_NOT_INSTALLED),  //! An error occurred while installing the directory service. For more information, see the event log.
		_MakeErrorCodeName(ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY),  //! The directory service evaluated group memberships locally.
		_MakeErrorCodeName(ERROR_DS_NO_ATTRIBUTE_OR_VALUE),  //! The specified directory service attribute or value does not exist.
		_MakeErrorCodeName(ERROR_DS_INVALID_ATTRIBUTE_SYNTAX),  //! The attribute syntax specified to the directory service is invalid.
		_MakeErrorCodeName(ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED),  //! The attribute type specified to the directory service is not defined.
		_MakeErrorCodeName(ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS),  //! The specified directory service attribute or value already exists.
		_MakeErrorCodeName(ERROR_DS_BUSY),  //! The directory service is busy.
		_MakeErrorCodeName(ERROR_DS_UNAVAILABLE),  //! The directory service is unavailable.
		_MakeErrorCodeName(ERROR_DS_NO_RIDS_ALLOCATED),  //! The directory service was unable to allocate a relative identifier.
		_MakeErrorCodeName(ERROR_DS_NO_MORE_RIDS),  //! The directory service has exhausted the pool of relative identifiers.
		_MakeErrorCodeName(ERROR_DS_INCORRECT_ROLE_OWNER),  //! The requested operation could not be performed because the directory service is not the master for that type of operation.
		_MakeErrorCodeName(ERROR_DS_RIDMGR_INIT_ERROR),  //! The directory service was unable to initialize the subsystem that allocates relative identifiers.
		_MakeErrorCodeName(ERROR_DS_OBJ_CLASS_VIOLATION),  //! The requested operation did not satisfy one or more constraints associated with the class of the object.
		_MakeErrorCodeName(ERROR_DS_CANT_ON_NON_LEAF),  //! The directory service can perform the requested operation only on a leaf object.
		_MakeErrorCodeName(ERROR_DS_CANT_ON_RDN),  //! The directory service cannot perform the requested operation on the RDN attribute of an object.
		_MakeErrorCodeName(ERROR_DS_CANT_MOD_OBJ_CLASS),  //! The directory service detected an attempt to modify the object class of an object.
		_MakeErrorCodeName(ERROR_DS_CROSS_DOM_MOVE_ERROR),  //! The requested cross-domain move operation could not be performed.
		_MakeErrorCodeName(ERROR_DS_GC_NOT_AVAILABLE),  //! Unable to contact the global catalog server.
		_MakeErrorCodeName(ERROR_SHARED_POLICY),  //! The policy object is shared and can only be modified at the root.
		_MakeErrorCodeName(ERROR_POLICY_OBJECT_NOT_FOUND),  //! The policy object does not exist.
		_MakeErrorCodeName(ERROR_POLICY_ONLY_IN_DS),  //! The requested policy information is only in the directory service.
		_MakeErrorCodeName(ERROR_PROMOTION_ACTIVE),  //! A domain controller promotion is currently active.
		_MakeErrorCodeName(ERROR_NO_PROMOTION_ACTIVE),  //! A domain controller promotion is not currently active.
		_MakeErrorCodeName(ERROR_DS_OPERATIONS_ERROR),  //! An operations error occurred.
		_MakeErrorCodeName(ERROR_DS_PROTOCOL_ERROR),  //! A protocol error occurred.
		_MakeErrorCodeName(ERROR_DS_TIMELIMIT_EXCEEDED),  //! The time limit for this request was exceeded.
		_MakeErrorCodeName(ERROR_DS_SIZELIMIT_EXCEEDED),  //! The size limit for this request was exceeded.
		_MakeErrorCodeName(ERROR_DS_ADMIN_LIMIT_EXCEEDED),  //! The administrative limit for this request was exceeded.
		_MakeErrorCodeName(ERROR_DS_COMPARE_FALSE),  //! The compare response was false.
		_MakeErrorCodeName(ERROR_DS_COMPARE_TRUE),  //! The compare response was true.
		_MakeErrorCodeName(ERROR_DS_AUTH_METHOD_NOT_SUPPORTED),  //! The requested authentication method is not supported by the server.
		_MakeErrorCodeName(ERROR_DS_STRONG_AUTH_REQUIRED),  //! A more secure authentication method is required for this server.
		_MakeErrorCodeName(ERROR_DS_INAPPROPRIATE_AUTH),  //! Inappropriate authentication.
		_MakeErrorCodeName(ERROR_DS_AUTH_UNKNOWN),  //! The authentication mechanism is unknown.
		_MakeErrorCodeName(ERROR_DS_REFERRAL),  //! A referral was returned from the server.
		_MakeErrorCodeName(ERROR_DS_UNAVAILABLE_CRIT_EXTENSION),  //! The server does not support the requested critical extension.
		_MakeErrorCodeName(ERROR_DS_CONFIDENTIALITY_REQUIRED),  //! This request requires a secure connection.
		_MakeErrorCodeName(ERROR_DS_INAPPROPRIATE_MATCHING),  //! Inappropriate matching.
		_MakeErrorCodeName(ERROR_DS_CONSTRAINT_VIOLATION),  //! A constraint violation occurred.
		_MakeErrorCodeName(ERROR_DS_NO_SUCH_OBJECT),  //! There is no such object on the server.
		_MakeErrorCodeName(ERROR_DS_ALIAS_PROBLEM),  //! There is an alias problem.
		_MakeErrorCodeName(ERROR_DS_INVALID_DN_SYNTAX),  //! An invalid dn syntax has been specified.
		_MakeErrorCodeName(ERROR_DS_IS_LEAF),  //! The object is a leaf object.
		_MakeErrorCodeName(ERROR_DS_ALIAS_DEREF_PROBLEM),  //! There is an alias dereferencing problem.
		_MakeErrorCodeName(ERROR_DS_UNWILLING_TO_PERFORM),  //! The server is unwilling to process the request.
		_MakeErrorCodeName(ERROR_DS_LOOP_DETECT),  //! A loop has been detected.
		_MakeErrorCodeName(ERROR_DS_NAMING_VIOLATION),  //! There is a naming violation.
		_MakeErrorCodeName(ERROR_DS_OBJECT_RESULTS_TOO_LARGE),  //! The result set is too large.
		_MakeErrorCodeName(ERROR_DS_AFFECTS_MULTIPLE_DSAS),  //! The operation affects multiple DSAs.
		_MakeErrorCodeName(ERROR_DS_SERVER_DOWN),  //! The server is not operational.
		_MakeErrorCodeName(ERROR_DS_LOCAL_ERROR),  //! A local error has occurred.
		_MakeErrorCodeName(ERROR_DS_ENCODING_ERROR),  //! An encoding error has occurred.
		_MakeErrorCodeName(ERROR_DS_DECODING_ERROR),  //! A decoding error has occurred.
		_MakeErrorCodeName(ERROR_DS_FILTER_UNKNOWN),  //! The search filter cannot be recognized.
		_MakeErrorCodeName(ERROR_DS_PARAM_ERROR),  //! One or more parameters are illegal.
		_MakeErrorCodeName(ERROR_DS_NOT_SUPPORTED),  //! The specified method is not supported.
		_MakeErrorCodeName(ERROR_DS_NO_RESULTS_RETURNED),  //! No results were returned.
		_MakeErrorCodeName(ERROR_DS_CONTROL_NOT_FOUND),  //! The specified control is not supported by the server.
		_MakeErrorCodeName(ERROR_DS_CLIENT_LOOP),  //! A referral loop was detected by the client.
		_MakeErrorCodeName(ERROR_DS_REFERRAL_LIMIT_EXCEEDED),  //! The preset referral limit was exceeded.
		_MakeErrorCodeName(ERROR_DS_SORT_CONTROL_MISSING),  //! The search requires a SORT control.
		_MakeErrorCodeName(ERROR_DS_OFFSET_RANGE_ERROR),  //! The search results exceed the offset range specified.
		_MakeErrorCodeName(ERROR_DS_RIDMGR_DISABLED),  //! The directory service detected the subsystem that allocates relative identifiers is disabled. This can occur as a protective mechanism when the system determines a significant portion of relative identifiers (RIDs) have been exhausted. Please see https://go.microsoft.com/fwlink/p/?linkid=228610 for recommended diagnostic steps and the procedure to re-enable account creation.
		_MakeErrorCodeName(ERROR_DS_ROOT_MUST_BE_NC),  //! The root object must be the head of a naming context. The root object cannot have an instantiated parent.
		_MakeErrorCodeName(ERROR_DS_ADD_REPLICA_INHIBITED),  //! The add replica operation cannot be performed. The naming context must be writeable in order to create the replica.
		_MakeErrorCodeName(ERROR_DS_ATT_NOT_DEF_IN_SCHEMA),  //! A reference to an attribute that is not defined in the schema occurred.
		_MakeErrorCodeName(ERROR_DS_MAX_OBJ_SIZE_EXCEEDED),  //! The maximum size of an object has been exceeded.
		_MakeErrorCodeName(ERROR_DS_OBJ_STRING_NAME_EXISTS),  //! An attempt was made to add an object to the directory with a name that is already in use.
		_MakeErrorCodeName(ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA),  //! An attempt was made to add an object of a class that does not have an RDN defined in the schema.
		_MakeErrorCodeName(ERROR_DS_RDN_DOESNT_MATCH_SCHEMA),  //! An attempt was made to add an object using an RDN that is not the RDN defined in the schema.
		_MakeErrorCodeName(ERROR_DS_NO_REQUESTED_ATTS_FOUND),  //! None of the requested attributes were found on the objects.
		_MakeErrorCodeName(ERROR_DS_USER_BUFFER_TO_SMALL),  //! The user buffer is too small.
		_MakeErrorCodeName(ERROR_DS_ATT_IS_NOT_ON_OBJ),  //! The attribute specified in the operation is not present on the object.
		_MakeErrorCodeName(ERROR_DS_ILLEGAL_MOD_OPERATION),  //! Illegal modify operation. Some aspect of the modification is not permitted.
		_MakeErrorCodeName(ERROR_DS_OBJ_TOO_LARGE),  //! The specified object is too large.
		_MakeErrorCodeName(ERROR_DS_BAD_INSTANCE_TYPE),  //! The specified instance type is not valid.
		_MakeErrorCodeName(ERROR_DS_MASTERDSA_REQUIRED),  //! The operation must be performed at a master DSA.
		_MakeErrorCodeName(ERROR_DS_OBJECT_CLASS_REQUIRED),  //! The object class attribute must be specified.
		_MakeErrorCodeName(ERROR_DS_MISSING_REQUIRED_ATT),  //! A required attribute is missing.
		_MakeErrorCodeName(ERROR_DS_ATT_NOT_DEF_FOR_CLASS),  //! An attempt was made to modify an object to include an attribute that is not legal for its class.
		_MakeErrorCodeName(ERROR_DS_ATT_ALREADY_EXISTS),  //! The specified attribute is already present on the object.
		_MakeErrorCodeName(ERROR_DS_CANT_ADD_ATT_VALUES),  //! The specified attribute is not present, or has no values.
		_MakeErrorCodeName(ERROR_DS_SINGLE_VALUE_CONSTRAINT),  //! Multiple values were specified for an attribute that can have only one value.
		_MakeErrorCodeName(ERROR_DS_RANGE_CONSTRAINT),  //! A value for the attribute was not in the acceptable range of values.
		_MakeErrorCodeName(ERROR_DS_ATT_VAL_ALREADY_EXISTS),  //! The specified value already exists.
		_MakeErrorCodeName(ERROR_DS_CANT_REM_MISSING_ATT),  //! The attribute cannot be removed because it is not present on the object.
		_MakeErrorCodeName(ERROR_DS_CANT_REM_MISSING_ATT_VAL),  //! The attribute value cannot be removed because it is not present on the object.
		_MakeErrorCodeName(ERROR_DS_ROOT_CANT_BE_SUBREF),  //! The specified root object cannot be a subref.
		_MakeErrorCodeName(ERROR_DS_NO_CHAINING),  //! Chaining is not permitted.
		_MakeErrorCodeName(ERROR_DS_NO_CHAINED_EVAL),  //! Chained evaluation is not permitted.
		_MakeErrorCodeName(ERROR_DS_NO_PARENT_OBJECT),  //! The operation could not be performed because the object's parent is either uninstantiated or deleted.
		_MakeErrorCodeName(ERROR_DS_PARENT_IS_AN_ALIAS),  //! Having a parent that is an alias is not permitted. Aliases are leaf objects.
		_MakeErrorCodeName(ERROR_DS_CANT_MIX_MASTER_AND_REPS),  //! The object and parent must be of the same type, either both masters or both replicas.
		_MakeErrorCodeName(ERROR_DS_CHILDREN_EXIST),  //! The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.
		_MakeErrorCodeName(ERROR_DS_OBJ_NOT_FOUND),  //! Directory object not found.
		_MakeErrorCodeName(ERROR_DS_ALIASED_OBJ_MISSING),  //! The aliased object is missing.
		_MakeErrorCodeName(ERROR_DS_BAD_NAME_SYNTAX),  //! The object name has bad syntax.
		_MakeErrorCodeName(ERROR_DS_ALIAS_POINTS_TO_ALIAS),  //! It is not permitted for an alias to refer to another alias.
		_MakeErrorCodeName(ERROR_DS_CANT_DEREF_ALIAS),  //! The alias cannot be dereferenced.
		_MakeErrorCodeName(ERROR_DS_OUT_OF_SCOPE),  //! The operation is out of scope.
		_MakeErrorCodeName(ERROR_DS_OBJECT_BEING_REMOVED),  //! The operation cannot continue because the object is in the process of being removed.
		_MakeErrorCodeName(ERROR_DS_CANT_DELETE_DSA_OBJ),  //! The DSA object cannot be deleted.
		_MakeErrorCodeName(ERROR_DS_GENERIC_ERROR),  //! A directory service error has occurred.
		_MakeErrorCodeName(ERROR_DS_DSA_MUST_BE_INT_MASTER),  //! The operation can only be performed on an internal master DSA object.
		_MakeErrorCodeName(ERROR_DS_CLASS_NOT_DSA),  //! The object must be of class DSA.
		_MakeErrorCodeName(ERROR_DS_INSUFF_ACCESS_RIGHTS),  //! Insufficient access rights to perform the operation.
		_MakeErrorCodeName(ERROR_DS_ILLEGAL_SUPERIOR),  //! The object cannot be added because the parent is not on the list of possible superiors.
		_MakeErrorCodeName(ERROR_DS_ATTRIBUTE_OWNED_BY_SAM),  //! Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM).
		_MakeErrorCodeName(ERROR_DS_NAME_TOO_MANY_PARTS),  //! The name has too many parts.
		_MakeErrorCodeName(ERROR_DS_NAME_TOO_LONG),  //! The name is too long.
		_MakeErrorCodeName(ERROR_DS_NAME_VALUE_TOO_LONG),  //! The name value is too long.
		_MakeErrorCodeName(ERROR_DS_NAME_UNPARSEABLE),  //! The directory service encountered an error parsing a name.
		_MakeErrorCodeName(ERROR_DS_NAME_TYPE_UNKNOWN),  //! The directory service cannot get the attribute type for a name.
		_MakeErrorCodeName(ERROR_DS_NOT_AN_OBJECT),  //! The name does not identify an object; the name identifies a phantom.
		_MakeErrorCodeName(ERROR_DS_SEC_DESC_TOO_SHORT),  //! The security descriptor is too short.
		_MakeErrorCodeName(ERROR_DS_SEC_DESC_INVALID),  //! The security descriptor is invalid.
		_MakeErrorCodeName(ERROR_DS_NO_DELETED_NAME),  //! Failed to create name for deleted object.
		_MakeErrorCodeName(ERROR_DS_SUBREF_MUST_HAVE_PARENT),  //! The parent of a new subref must exist.
		_MakeErrorCodeName(ERROR_DS_NCNAME_MUST_BE_NC),  //! The object must be a naming context.
		_MakeErrorCodeName(ERROR_DS_CANT_ADD_SYSTEM_ONLY),  //! It is not permitted to add an attribute which is owned by the system.
		_MakeErrorCodeName(ERROR_DS_CLASS_MUST_BE_CONCRETE),  //! The class of the object must be structural; you cannot instantiate an abstract class.
		_MakeErrorCodeName(ERROR_DS_INVALID_DMD),  //! The schema object could not be found.
		_MakeErrorCodeName(ERROR_DS_OBJ_GUID_EXISTS),  //! A local object with this GUID (dead or alive) already exists.
		_MakeErrorCodeName(ERROR_DS_NOT_ON_BACKLINK),  //! The operation cannot be performed on a back link.
		_MakeErrorCodeName(ERROR_DS_NO_CROSSREF_FOR_NC),  //! The cross reference for the specified naming context could not be found.
		_MakeErrorCodeName(ERROR_DS_SHUTTING_DOWN),  //! The operation could not be performed because the directory service is shutting down.
		_MakeErrorCodeName(ERROR_DS_UNKNOWN_OPERATION),  //! The directory service request is invalid.
		_MakeErrorCodeName(ERROR_DS_INVALID_ROLE_OWNER),  //! The role owner attribute could not be read.
		_MakeErrorCodeName(ERROR_DS_COULDNT_CONTACT_FSMO),  //! The requested FSMO operation failed. The current FSMO holder could not be contacted.
		_MakeErrorCodeName(ERROR_DS_CROSS_NC_DN_RENAME),  //! Modification of a DN across a naming context is not permitted.
		_MakeErrorCodeName(ERROR_DS_CANT_MOD_SYSTEM_ONLY),  //! The attribute cannot be modified because it is owned by the system.
		_MakeErrorCodeName(ERROR_DS_REPLICATOR_ONLY),  //! Only the replicator can perform this function.
		_MakeErrorCodeName(ERROR_DS_OBJ_CLASS_NOT_DEFINED),  //! The specified class is not defined.
		_MakeErrorCodeName(ERROR_DS_OBJ_CLASS_NOT_SUBCLASS),  //! The specified class is not a subclass.
		_MakeErrorCodeName(ERROR_DS_NAME_REFERENCE_INVALID),  //! The name reference is invalid.
		_MakeErrorCodeName(ERROR_DS_CROSS_REF_EXISTS),  //! A cross reference already exists.
		_MakeErrorCodeName(ERROR_DS_CANT_DEL_MASTER_CROSSREF),  //! It is not permitted to delete a master cross reference.
		_MakeErrorCodeName(ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD),  //! Subtree notifications are only supported on NC heads.
		_MakeErrorCodeName(ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX),  //! Notification filter is too complex.
		_MakeErrorCodeName(ERROR_DS_DUP_RDN),  //! Schema update failed: duplicate RDN.
		_MakeErrorCodeName(ERROR_DS_DUP_OID),  //! Schema update failed: duplicate OID.
		_MakeErrorCodeName(ERROR_DS_DUP_MAPI_ID),  //! Schema update failed: duplicate MAPI identifier.
		_MakeErrorCodeName(ERROR_DS_DUP_SCHEMA_ID_GUID),  //! Schema update failed: duplicate schema-id GUID.
		_MakeErrorCodeName(ERROR_DS_DUP_LDAP_DISPLAY_NAME),  //! Schema update failed: duplicate LDAP display name.
		_MakeErrorCodeName(ERROR_DS_SEMANTIC_ATT_TEST),  //! Schema update failed: range-lower less than range upper.
		_MakeErrorCodeName(ERROR_DS_SYNTAX_MISMATCH),  //! Schema update failed: syntax mismatch.
		_MakeErrorCodeName(ERROR_DS_EXISTS_IN_MUST_HAVE),  //! Schema deletion failed: attribute is used in must-contain.
		_MakeErrorCodeName(ERROR_DS_EXISTS_IN_MAY_HAVE),  //! Schema deletion failed: attribute is used in may-contain.
		_MakeErrorCodeName(ERROR_DS_NONEXISTENT_MAY_HAVE),  //! Schema update failed: attribute in may-contain does not exist.
		_MakeErrorCodeName(ERROR_DS_NONEXISTENT_MUST_HAVE),  //! Schema update failed: attribute in must-contain does not exist.
		_MakeErrorCodeName(ERROR_DS_AUX_CLS_TEST_FAIL),  //! Schema update failed: class in aux-class list does not exist or is not an auxiliary class.
		_MakeErrorCodeName(ERROR_DS_NONEXISTENT_POSS_SUP),  //! Schema update failed: class in poss-superiors does not exist.
		_MakeErrorCodeName(ERROR_DS_SUB_CLS_TEST_FAIL),  //! Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules.
		_MakeErrorCodeName(ERROR_DS_BAD_RDN_ATT_ID_SYNTAX),  //! Schema update failed: Rdn-Att-Id has wrong syntax.
		_MakeErrorCodeName(ERROR_DS_EXISTS_IN_AUX_CLS),  //! Schema deletion failed: class is used as auxiliary class.
		_MakeErrorCodeName(ERROR_DS_EXISTS_IN_SUB_CLS),  //! Schema deletion failed: class is used as sub class.
		_MakeErrorCodeName(ERROR_DS_EXISTS_IN_POSS_SUP),  //! Schema deletion failed: class is used as poss superior.
		_MakeErrorCodeName(ERROR_DS_RECALCSCHEMA_FAILED),  //! Schema update failed in recalculating validation cache.
		_MakeErrorCodeName(ERROR_DS_TREE_DELETE_NOT_FINISHED),  //! The tree deletion is not finished. The request must be made again to continue deleting the tree.
		_MakeErrorCodeName(ERROR_DS_CANT_DELETE),  //! The requested delete operation could not be performed.
		_MakeErrorCodeName(ERROR_DS_ATT_SCHEMA_REQ_ID),  //! Cannot read the governs class identifier for the schema record.
		_MakeErrorCodeName(ERROR_DS_BAD_ATT_SCHEMA_SYNTAX),  //! The attribute schema has bad syntax.
		_MakeErrorCodeName(ERROR_DS_CANT_CACHE_ATT),  //! The attribute could not be cached.
		_MakeErrorCodeName(ERROR_DS_CANT_CACHE_CLASS),  //! The class could not be cached.
		_MakeErrorCodeName(ERROR_DS_CANT_REMOVE_ATT_CACHE),  //! The attribute could not be removed from the cache.
		_MakeErrorCodeName(ERROR_DS_CANT_REMOVE_CLASS_CACHE),  //! The class could not be removed from the cache.
		_MakeErrorCodeName(ERROR_DS_CANT_RETRIEVE_DN),  //! The distinguished name attribute could not be read.
		_MakeErrorCodeName(ERROR_DS_MISSING_SUPREF),  //! No superior reference has been configured for the directory service. The directory service is therefore unable to issue referrals to objects outside this forest.
		_MakeErrorCodeName(ERROR_DS_CANT_RETRIEVE_INSTANCE),  //! The instance type attribute could not be retrieved.
		_MakeErrorCodeName(ERROR_DS_CODE_INCONSISTENCY),  //! An internal error has occurred.
		_MakeErrorCodeName(ERROR_DS_DATABASE_ERROR),  //! A database error has occurred.
		_MakeErrorCodeName(ERROR_DS_GOVERNSID_MISSING),  //! The attribute GOVERNSID is missing.
		_MakeErrorCodeName(ERROR_DS_MISSING_EXPECTED_ATT),  //! An expected attribute is missing.
		_MakeErrorCodeName(ERROR_DS_NCNAME_MISSING_CR_REF),  //! The specified naming context is missing a cross reference.
		_MakeErrorCodeName(ERROR_DS_SECURITY_CHECKING_ERROR),  //! A security checking error has occurred.
		_MakeErrorCodeName(ERROR_DS_SCHEMA_NOT_LOADED),  //! The schema is not loaded.
		_MakeErrorCodeName(ERROR_DS_SCHEMA_ALLOC_FAILED),  //! Schema allocation failed. Please check if the machine is running low on memory.
		_MakeErrorCodeName(ERROR_DS_ATT_SCHEMA_REQ_SYNTAX),  //! Failed to obtain the required syntax for the attribute schema.
		_MakeErrorCodeName(ERROR_DS_GCVERIFY_ERROR),  //! The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.
		_MakeErrorCodeName(ERROR_DS_DRA_SCHEMA_MISMATCH),  //! The replication operation failed because of a schema mismatch between the servers involved.
		_MakeErrorCodeName(ERROR_DS_CANT_FIND_DSA_OBJ),  //! The DSA object could not be found.
		_MakeErrorCodeName(ERROR_DS_CANT_FIND_EXPECTED_NC),  //! The naming context could not be found.
		_MakeErrorCodeName(ERROR_DS_CANT_FIND_NC_IN_CACHE),  //! The naming context could not be found in the cache.
		_MakeErrorCodeName(ERROR_DS_CANT_RETRIEVE_CHILD),  //! The child object could not be retrieved.
		_MakeErrorCodeName(ERROR_DS_SECURITY_ILLEGAL_MODIFY),  //! The modification was not permitted for security reasons.
		_MakeErrorCodeName(ERROR_DS_CANT_REPLACE_HIDDEN_REC),  //! The operation cannot replace the hidden record.
		_MakeErrorCodeName(ERROR_DS_BAD_HIERARCHY_FILE),  //! The hierarchy file is invalid.
		_MakeErrorCodeName(ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED),  //! The attempt to build the hierarchy table failed.
		_MakeErrorCodeName(ERROR_DS_CONFIG_PARAM_MISSING),  //! The directory configuration parameter is missing from the registry.
		_MakeErrorCodeName(ERROR_DS_COUNTING_AB_INDICES_FAILED),  //! The attempt to count the address book indices failed.
		_MakeErrorCodeName(ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED),  //! The allocation of the hierarchy table failed.
		_MakeErrorCodeName(ERROR_DS_INTERNAL_FAILURE),  //! The directory service encountered an internal failure.
		_MakeErrorCodeName(ERROR_DS_UNKNOWN_ERROR),  //! The directory service encountered an unknown failure.
		_MakeErrorCodeName(ERROR_DS_ROOT_REQUIRES_CLASS_TOP),  //! A root object requires a class of 'top'.
		_MakeErrorCodeName(ERROR_DS_REFUSING_FSMO_ROLES),  //! This directory server is shutting down, and cannot take ownership of new floating single-master operation roles.
		_MakeErrorCodeName(ERROR_DS_MISSING_FSMO_SETTINGS),  //! The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles.
		_MakeErrorCodeName(ERROR_DS_UNABLE_TO_SURRENDER_ROLES),  //! The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers.
		_MakeErrorCodeName(ERROR_DS_DRA_GENERIC),  //! The replication operation failed.
		_MakeErrorCodeName(ERROR_DS_DRA_INVALID_PARAMETER),  //! An invalid parameter was specified for this replication operation.
		_MakeErrorCodeName(ERROR_DS_DRA_BUSY),  //! The directory service is too busy to complete the replication operation at this time.
		_MakeErrorCodeName(ERROR_DS_DRA_BAD_DN),  //! The distinguished name specified for this replication operation is invalid.
		_MakeErrorCodeName(ERROR_DS_DRA_BAD_NC),  //! The naming context specified for this replication operation is invalid.
		_MakeErrorCodeName(ERROR_DS_DRA_DN_EXISTS),  //! The distinguished name specified for this replication operation already exists.
		_MakeErrorCodeName(ERROR_DS_DRA_INTERNAL_ERROR),  //! The replication system encountered an internal error.
		_MakeErrorCodeName(ERROR_DS_DRA_INCONSISTENT_DIT),  //! The replication operation encountered a database inconsistency.
		_MakeErrorCodeName(ERROR_DS_DRA_CONNECTION_FAILED),  //! The server specified for this replication operation could not be contacted.
		_MakeErrorCodeName(ERROR_DS_DRA_BAD_INSTANCE_TYPE),  //! The replication operation encountered an object with an invalid instance type.
		_MakeErrorCodeName(ERROR_DS_DRA_OUT_OF_MEM),  //! The replication operation failed to allocate memory.
		_MakeErrorCodeName(ERROR_DS_DRA_MAIL_PROBLEM),  //! The replication operation encountered an error with the mail system.
		_MakeErrorCodeName(ERROR_DS_DRA_REF_ALREADY_EXISTS),  //! The replication reference information for the target server already exists.
		_MakeErrorCodeName(ERROR_DS_DRA_REF_NOT_FOUND),  //! The replication reference information for the target server does not exist.
		_MakeErrorCodeName(ERROR_DS_DRA_OBJ_IS_REP_SOURCE),  //! The naming context cannot be removed because it is replicated to another server.
		_MakeErrorCodeName(ERROR_DS_DRA_DB_ERROR),  //! The replication operation encountered a database error.
		_MakeErrorCodeName(ERROR_DS_DRA_NO_REPLICA),  //! The naming context is in the process of being removed or is not replicated from the specified server.
		_MakeErrorCodeName(ERROR_DS_DRA_ACCESS_DENIED),  //! Replication access was denied.
		_MakeErrorCodeName(ERROR_DS_DRA_NOT_SUPPORTED),  //! The requested operation is not supported by this version of the directory service.
		_MakeErrorCodeName(ERROR_DS_DRA_RPC_CANCELLED),  //! The replication remote procedure call was cancelled.
		_MakeErrorCodeName(ERROR_DS_DRA_SOURCE_DISABLED),  //! The source server is currently rejecting replication requests.
		_MakeErrorCodeName(ERROR_DS_DRA_SINK_DISABLED),  //! The destination server is currently rejecting replication requests.
		_MakeErrorCodeName(ERROR_DS_DRA_NAME_COLLISION),  //! The replication operation failed due to a collision of object names.
		_MakeErrorCodeName(ERROR_DS_DRA_SOURCE_REINSTALLED),  //! The replication source has been reinstalled.
		_MakeErrorCodeName(ERROR_DS_DRA_MISSING_PARENT),  //! The replication operation failed because a required parent object is missing.
		_MakeErrorCodeName(ERROR_DS_DRA_PREEMPTED),  //! The replication operation was preempted.
		_MakeErrorCodeName(ERROR_DS_DRA_ABANDON_SYNC),  //! The replication synchronization attempt was abandoned because of a lack of updates.
		_MakeErrorCodeName(ERROR_DS_DRA_SHUTDOWN),  //! The replication operation was terminated because the system is shutting down.
		_MakeErrorCodeName(ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET),  //! Synchronization attempt failed because the destination DC is currently waiting to synchronize new partial attributes from source. This condition is normal if a recent schema change modified the partial attribute set. The destination partial attribute set is not a subset of source partial attribute set.
		_MakeErrorCodeName(ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA),  //! The replication synchronization attempt failed because a master replica attempted to sync from a partial replica.
		_MakeErrorCodeName(ERROR_DS_DRA_EXTN_CONNECTION_FAILED),  //! The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation.
		_MakeErrorCodeName(ERROR_DS_INSTALL_SCHEMA_MISMATCH),  //! The version of the directory service schema of the source forest is not compatible with the version of directory service on this computer.
		_MakeErrorCodeName(ERROR_DS_DUP_LINK_ID),  //! Schema update failed: An attribute with the same link identifier already exists.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_RESOLVING),  //! Name translation: Generic processing error.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_NOT_FOUND),  //! Name translation: Could not find the name or insufficient right to see name.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_NOT_UNIQUE),  //! Name translation: Input name mapped to more than one output name.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_NO_MAPPING),  //! Name translation: Input name found, but not the associated output format.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_DOMAIN_ONLY),  //! Name translation: Unable to resolve completely, only the domain was found.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING),  //! Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire.
		_MakeErrorCodeName(ERROR_DS_CONSTRUCTED_ATT_MOD),  //! Modification of a constructed attribute is not allowed.
		_MakeErrorCodeName(ERROR_DS_WRONG_OM_OBJ_CLASS),  //! The OM-Object-Class specified is incorrect for an attribute with the specified syntax.
		_MakeErrorCodeName(ERROR_DS_DRA_REPL_PENDING),  //! The replication request has been posted; waiting for reply.
		_MakeErrorCodeName(ERROR_DS_DS_REQUIRED),  //! The requested operation requires a directory service, and none was available.
		_MakeErrorCodeName(ERROR_DS_INVALID_LDAP_DISPLAY_NAME),  //! The LDAP display name of the class or attribute contains non-ASCII characters.
		_MakeErrorCodeName(ERROR_DS_NON_BASE_SEARCH),  //! The requested search operation is only supported for base searches.
		_MakeErrorCodeName(ERROR_DS_CANT_RETRIEVE_ATTS),  //! The search failed to retrieve attributes from the database.
		_MakeErrorCodeName(ERROR_DS_BACKLINK_WITHOUT_LINK),  //! The schema update operation tried to add a backward link attribute that has no corresponding forward link.
		_MakeErrorCodeName(ERROR_DS_EPOCH_MISMATCH),  //! Source and destination of a cross-domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.
		_MakeErrorCodeName(ERROR_DS_SRC_NAME_MISMATCH),  //! Source and destination of a cross-domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.
		_MakeErrorCodeName(ERROR_DS_SRC_AND_DST_NC_IDENTICAL),  //! Source and destination for the cross-domain move operation are identical. Caller should use local move operation instead of cross-domain move operation.
		_MakeErrorCodeName(ERROR_DS_DST_NC_MISMATCH),  //! Source and destination for a cross-domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.
		_MakeErrorCodeName(ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC),  //! Destination of a cross-domain move is not authoritative for the destination naming context.
		_MakeErrorCodeName(ERROR_DS_SRC_GUID_MISMATCH),  //! Source and destination of a cross-domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.
		_MakeErrorCodeName(ERROR_DS_CANT_MOVE_DELETED_OBJECT),  //! Object being moved across-domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.
		_MakeErrorCodeName(ERROR_DS_PDC_OPERATION_IN_PROGRESS),  //! Another operation which requires exclusive access to the PDC FSMO is already in progress.
		_MakeErrorCodeName(ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD),  //! A cross-domain move operation failed such that two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.
		_MakeErrorCodeName(ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION),  //! This object may not be moved across domain boundaries either because cross-domain moves for this class are disallowed, or the object has some special characteristics, e.g.: trust account or restricted RID, which prevent its move.
		_MakeErrorCodeName(ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS),  //! Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.
		_MakeErrorCodeName(ERROR_DS_NC_MUST_HAVE_NC_PARENT),  //! A naming context head must be the immediate child of another naming context head, not of an interior node.
		_MakeErrorCodeName(ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE),  //! The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners. (Applies only to Windows 2000 Domain Naming masters.)
		_MakeErrorCodeName(ERROR_DS_DST_DOMAIN_NOT_NATIVE),  //! Destination domain must be in native mode.
		_MakeErrorCodeName(ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER),  //! The operation cannot be performed because the server does not have an infrastructure container in the domain of interest.
		_MakeErrorCodeName(ERROR_DS_CANT_MOVE_ACCOUNT_GROUP),  //! Cross-domain move of non-empty account groups is not allowed.
		_MakeErrorCodeName(ERROR_DS_CANT_MOVE_RESOURCE_GROUP),  //! Cross-domain move of non-empty resource groups is not allowed.
		_MakeErrorCodeName(ERROR_DS_INVALID_SEARCH_FLAG),  //! The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.
		_MakeErrorCodeName(ERROR_DS_NO_TREE_DELETE_ABOVE_NC),  //! Tree deletions starting at an object which has an NC head as a descendant are not allowed.
		_MakeErrorCodeName(ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE),  //! The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.
		_MakeErrorCodeName(ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE),  //! The directory service failed to identify the list of objects to delete while attempting a tree deletion.
		_MakeErrorCodeName(ERROR_DS_SAM_INIT_FAILURE),  //! Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Please shutdown this system and reboot into Directory Services Restore Mode, check the event log for more detailed information.
		_MakeErrorCodeName(ERROR_DS_SENSITIVE_GROUP_VIOLATION),  //! Only an administrator can modify the membership list of an administrative group.
		_MakeErrorCodeName(ERROR_DS_CANT_MOD_PRIMARYGROUPID),  //! Cannot change the primary group ID of a domain controller account.
		_MakeErrorCodeName(ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD),  //! An attempt is made to modify the base schema.
		_MakeErrorCodeName(ERROR_DS_NONSAFE_SCHEMA_CHANGE),  //! Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.
		_MakeErrorCodeName(ERROR_DS_SCHEMA_UPDATE_DISALLOWED),  //! Schema update is not allowed on this DC because the DC is not the schema FSMO Role Owner.
		_MakeErrorCodeName(ERROR_DS_CANT_CREATE_UNDER_SCHEMA),  //! An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.
		_MakeErrorCodeName(ERROR_DS_INSTALL_NO_SRC_SCH_VERSION),  //! The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.
		_MakeErrorCodeName(ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE),  //! The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.
		_MakeErrorCodeName(ERROR_DS_INVALID_GROUP_TYPE),  //! The specified group type is invalid.
		_MakeErrorCodeName(ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN),  //! You cannot nest global groups in a mixed domain if the group is security-enabled.
		_MakeErrorCodeName(ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN),  //! You cannot nest local groups in a mixed domain if the group is security-enabled.
		_MakeErrorCodeName(ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER),  //! A global group cannot have a local group as a member.
		_MakeErrorCodeName(ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER),  //! A global group cannot have a universal group as a member.
		_MakeErrorCodeName(ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER),  //! A universal group cannot have a local group as a member.
		_MakeErrorCodeName(ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER),  //! A global group cannot have a cross-domain member.
		_MakeErrorCodeName(ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER),  //! A local group cannot have another cross domain local group as a member.
		_MakeErrorCodeName(ERROR_DS_HAVE_PRIMARY_MEMBERS),  //! A group with primary members cannot change to a security-disabled group.
		_MakeErrorCodeName(ERROR_DS_STRING_SD_CONVERSION_FAILED),  //! The schema cache load failed to convert the string default SD on a class-schema object.
		_MakeErrorCodeName(ERROR_DS_NAMING_MASTER_GC),  //! Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers.)
		_MakeErrorCodeName(ERROR_DS_DNS_LOOKUP_FAILURE),  //! The DSA operation is unable to proceed because of a DNS lookup failure.
		_MakeErrorCodeName(ERROR_DS_COULDNT_UPDATE_SPNS),  //! While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync.
		_MakeErrorCodeName(ERROR_DS_CANT_RETRIEVE_SD),  //! The Security Descriptor attribute could not be read.
		_MakeErrorCodeName(ERROR_DS_KEY_NOT_UNIQUE),  //! The object requested was not found, but an object with that key was found.
		_MakeErrorCodeName(ERROR_DS_WRONG_LINKED_ATT_SYNTAX),  //! The syntax of the linked attribute being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1.
		_MakeErrorCodeName(ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD),  //! Security Account Manager needs to get the boot password.
		_MakeErrorCodeName(ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY),  //! Security Account Manager needs to get the boot key from floppy disk.
		_MakeErrorCodeName(ERROR_DS_CANT_START),  //! Directory Service cannot start.
		_MakeErrorCodeName(ERROR_DS_INIT_FAILURE),  //! Directory Services could not start.
		_MakeErrorCodeName(ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION),  //! The connection between client and server requires packet privacy or better.
		_MakeErrorCodeName(ERROR_DS_SOURCE_DOMAIN_IN_FOREST),  //! The source domain may not be in the same forest as destination.
		_MakeErrorCodeName(ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST),  //! The destination domain must be in the forest.
		_MakeErrorCodeName(ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED),  //! The operation requires that destination domain auditing be enabled.
		_MakeErrorCodeName(ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN),  //! The operation couldn't locate a DC for the source domain.
		_MakeErrorCodeName(ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER),  //! The source object must be a group or user.
		_MakeErrorCodeName(ERROR_DS_SRC_SID_EXISTS_IN_FOREST),  //! The source object's SID already exists in destination forest.
		_MakeErrorCodeName(ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH),  //! The source and destination object must be of the same type.
		_MakeErrorCodeName(ERROR_SAM_INIT_FAILURE),  //! Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information.
		_MakeErrorCodeName(ERROR_DS_DRA_SCHEMA_INFO_SHIP),  //! Schema information could not be included in the replication request.
		_MakeErrorCodeName(ERROR_DS_DRA_SCHEMA_CONFLICT),  //! The replication operation could not be completed due to a schema incompatibility.
		_MakeErrorCodeName(ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT),  //! The replication operation could not be completed due to a previous schema incompatibility.
		_MakeErrorCodeName(ERROR_DS_DRA_OBJ_NC_MISMATCH),  //! The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.
		_MakeErrorCodeName(ERROR_DS_NC_STILL_HAS_DSAS),  //! The requested domain could not be deleted because there exist domain controllers that still host this domain.
		_MakeErrorCodeName(ERROR_DS_GC_REQUIRED),  //! The requested operation can be performed only on a global catalog server.
		_MakeErrorCodeName(ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY),  //! A local group can only be a member of other local groups in the same domain.
		_MakeErrorCodeName(ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS),  //! Foreign security principals cannot be members of universal groups.
		_MakeErrorCodeName(ERROR_DS_CANT_ADD_TO_GC),  //! The attribute is not allowed to be replicated to the GC because of security reasons.
		_MakeErrorCodeName(ERROR_DS_NO_CHECKPOINT_WITH_PDC),  //! The checkpoint with the PDC could not be taken because there too many modifications being processed currently.
		_MakeErrorCodeName(ERROR_DS_SOURCE_AUDITING_NOT_ENABLED),  //! The operation requires that source domain auditing be enabled.
		_MakeErrorCodeName(ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC),  //! Security principal objects can only be created inside domain naming contexts.
		_MakeErrorCodeName(ERROR_DS_INVALID_NAME_FOR_SPN),  //! A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.
		_MakeErrorCodeName(ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS),  //! A Filter was passed that uses constructed attributes.
		_MakeErrorCodeName(ERROR_DS_UNICODEPWD_NOT_IN_QUOTES),  //! The unicodePwd attribute value must be enclosed in double quotes.
		_MakeErrorCodeName(ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED),  //! Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.
		_MakeErrorCodeName(ERROR_DS_MUST_BE_RUN_ON_DST_DC),  //! For security reasons, the operation must be run on the destination DC.
		_MakeErrorCodeName(ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER),  //! For security reasons, the source DC must be NT4SP4 or greater.
		_MakeErrorCodeName(ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ),  //! Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.
		_MakeErrorCodeName(ERROR_DS_INIT_FAILURE_CONSOLE),  //! Directory Services could not start because of the following error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
		_MakeErrorCodeName(ERROR_DS_SAM_INIT_FAILURE_CONSOLE),  //! Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
		_MakeErrorCodeName(ERROR_DS_FOREST_VERSION_TOO_HIGH),  //! The version of the operating system is incompatible with the current AD DS forest functional level or AD LDS Configuration Set functional level. You must upgrade to a new version of the operating system before this server can become an AD DS Domain Controller or add an AD LDS Instance in this AD DS Forest or AD LDS Configuration Set.
		_MakeErrorCodeName(ERROR_DS_DOMAIN_VERSION_TOO_HIGH),  //! The version of the operating system installed is incompatible with the current domain functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this domain.
		_MakeErrorCodeName(ERROR_DS_FOREST_VERSION_TOO_LOW),  //! The version of the operating system installed on this server no longer supports the current AD DS Forest functional level or AD LDS Configuration Set functional level. You must raise the AD DS Forest functional level or AD LDS Configuration Set functional level before this server can become an AD DS Domain Controller or an AD LDS Instance in this Forest or Configuration Set.
		_MakeErrorCodeName(ERROR_DS_DOMAIN_VERSION_TOO_LOW),  //! The version of the operating system installed on this server no longer supports the current domain functional level. You must raise the domain functional level before this server can become a domain controller in this domain.
		_MakeErrorCodeName(ERROR_DS_INCOMPATIBLE_VERSION),  //! The version of the operating system installed on this server is incompatible with the functional level of the domain or forest.
		_MakeErrorCodeName(ERROR_DS_LOW_DSA_VERSION),  //! The functional level of the domain (or forest) cannot be raised to the requested value, because there exist one or more domain controllers in the domain (or forest) that are at a lower incompatible functional level.
		_MakeErrorCodeName(ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN),  //! The forest functional level cannot be raised to the requested value since one or more domains are still in mixed domain mode. All domains in the forest must be in native mode, for you to raise the forest functional level.
		_MakeErrorCodeName(ERROR_DS_NOT_SUPPORTED_SORT_ORDER),  //! The sort order requested is not supported.
		_MakeErrorCodeName(ERROR_DS_NAME_NOT_UNIQUE),  //! The requested name already exists as a unique identifier.
		_MakeErrorCodeName(ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4),  //! The machine account was created pre-NT4. The account needs to be recreated.
		_MakeErrorCodeName(ERROR_DS_OUT_OF_VERSION_STORE),  //! The database is out of version store.
		_MakeErrorCodeName(ERROR_DS_INCOMPATIBLE_CONTROLS_USED),  //! Unable to continue operation because multiple conflicting controls were used.
		_MakeErrorCodeName(ERROR_DS_NO_REF_DOMAIN),  //! Unable to find a valid security descriptor reference domain for this partition.
		_MakeErrorCodeName(ERROR_DS_RESERVED_LINK_ID),  //! Schema update failed: The link identifier is reserved.
		_MakeErrorCodeName(ERROR_DS_LINK_ID_NOT_AVAILABLE),  //! Schema update failed: There are no link identifiers available.
		_MakeErrorCodeName(ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER),  //! An account group cannot have a universal group as a member.
		_MakeErrorCodeName(ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE),  //! Rename or move operations on naming context heads or read-only objects are not allowed.
		_MakeErrorCodeName(ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC),  //! Move operations on objects in the schema naming context are not allowed.
		_MakeErrorCodeName(ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG),  //! A system flag has been set on the object and does not allow the object to be moved or renamed.
		_MakeErrorCodeName(ERROR_DS_MODIFYDN_WRONG_GRANDPARENT),  //! This object is not allowed to change its grandparent container. Moves are not forbidden on this object, but are restricted to sibling containers.
		_MakeErrorCodeName(ERROR_DS_NAME_ERROR_TRUST_REFERRAL),  //! Unable to resolve completely, a referral to another forest is generated.
		_MakeErrorCodeName(ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER),  //! The requested action is not supported on standard server.
		_MakeErrorCodeName(ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD),  //! Could not access a partition of the directory service located on a remote server. Make sure at least one server is running for the partition in question.
		_MakeErrorCodeName(ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2),  //! The directory cannot validate the proposed naming context (or partition) name because it does not hold a replica nor can it contact a replica of the naming context above the proposed naming context. Please ensure that the parent naming context is properly registered in DNS, and at least one replica of this naming context is reachable by the Domain Naming master.
		_MakeErrorCodeName(ERROR_DS_THREAD_LIMIT_EXCEEDED),  //! The thread limit for this request was exceeded.
		_MakeErrorCodeName(ERROR_DS_NOT_CLOSEST),  //! The Global catalog server is not in the closest site.
		_MakeErrorCodeName(ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF),  //! The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the corresponding server object in the local DS database has no serverReference attribute.
		_MakeErrorCodeName(ERROR_DS_SINGLE_USER_MODE_FAILED),  //! The Directory Service failed to enter single user mode.
		_MakeErrorCodeName(ERROR_DS_NTDSCRIPT_SYNTAX_ERROR),  //! The Directory Service cannot parse the script because of a syntax error.
		_MakeErrorCodeName(ERROR_DS_NTDSCRIPT_PROCESS_ERROR),  //! The Directory Service cannot process the script because of an error.
		_MakeErrorCodeName(ERROR_DS_DIFFERENT_REPL_EPOCHS),  //! The directory service cannot perform the requested operation because the servers involved are of different replication epochs (which is usually related to a domain rename that is in progress).
		_MakeErrorCodeName(ERROR_DS_DRS_EXTENSIONS_CHANGED),  //! The directory service binding must be renegotiated due to a change in the server extensions information.
		_MakeErrorCodeName(ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR),  //! Operation not allowed on a disabled cross ref.
		_MakeErrorCodeName(ERROR_DS_NO_MSDS_INTID),  //! Schema update failed: No values for msDS-IntId are available.
		_MakeErrorCodeName(ERROR_DS_DUP_MSDS_INTID),  //! Schema update failed: Duplicate msDS-INtId. Retry the operation.
		_MakeErrorCodeName(ERROR_DS_EXISTS_IN_RDNATTID),  //! Schema deletion failed: attribute is used in rDNAttID.
		_MakeErrorCodeName(ERROR_DS_AUTHORIZATION_FAILED),  //! The directory service failed to authorize the request.
		_MakeErrorCodeName(ERROR_DS_INVALID_SCRIPT),  //! The Directory Service cannot process the script because it is invalid.
		_MakeErrorCodeName(ERROR_DS_REMOTE_CROSSREF_OP_FAILED),  //! The remote create cross reference operation failed on the Domain Naming Master FSMO. The operation's error is in the extended data.
		_MakeErrorCodeName(ERROR_DS_CROSS_REF_BUSY),  //! A cross reference is in use locally with the same name.
		_MakeErrorCodeName(ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN),  //! The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the server's domain has been deleted from the forest.
		_MakeErrorCodeName(ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC),  //! Writeable NCs prevent this DC from demoting.
		_MakeErrorCodeName(ERROR_DS_DUPLICATE_ID_FOUND),  //! The requested object has a non-unique identifier and cannot be retrieved.
		_MakeErrorCodeName(ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT),  //! Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected.
		_MakeErrorCodeName(ERROR_DS_GROUP_CONVERSION_ERROR),  //! The group cannot be converted due to attribute restrictions on the requested group type.
		_MakeErrorCodeName(ERROR_DS_CANT_MOVE_APP_BASIC_GROUP),  //! Cross-domain move of non-empty basic application groups is not allowed.
		_MakeErrorCodeName(ERROR_DS_CANT_MOVE_APP_QUERY_GROUP),  //! Cross-domain move of non-empty query based application groups is not allowed.
		_MakeErrorCodeName(ERROR_DS_ROLE_NOT_VERIFIED),  //! The FSMO role ownership could not be verified because its directory partition has not replicated successfully with at least one replication partner.
		_MakeErrorCodeName(ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL),  //! The target container for a redirection of a well known object container cannot already be a special container.
		_MakeErrorCodeName(ERROR_DS_DOMAIN_RENAME_IN_PROGRESS),  //! The Directory Service cannot perform the requested operation because a domain rename operation is in progress.
		_MakeErrorCodeName(ERROR_DS_EXISTING_AD_CHILD_NC),  //! The directory service detected a child partition below the requested partition name. The partition hierarchy must be created in a top down method.
		_MakeErrorCodeName(ERROR_DS_REPL_LIFETIME_EXCEEDED),  //! The directory service cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime.
		_MakeErrorCodeName(ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER),  //! The requested operation is not allowed on an object under the system container.
		_MakeErrorCodeName(ERROR_DS_LDAP_SEND_QUEUE_FULL),  //! The LDAP servers network send queue has filled up because the client is not processing the results of its requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected.
		_MakeErrorCodeName(ERROR_DS_DRA_OUT_SCHEDULE_WINDOW),  //! The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency.
		_MakeErrorCodeName(ERROR_DS_POLICY_NOT_KNOWN),  //! At this time, it cannot be determined if the branch replication policy is available on the hub domain controller. Please retry at a later time to account for replication latencies.
		_MakeErrorCodeName(ERROR_NO_SITE_SETTINGS_OBJECT),  //! The site settings object for the specified site does not exist.
		_MakeErrorCodeName(ERROR_NO_SECRETS),  //! The local account store does not contain secret material for the specified account.
		_MakeErrorCodeName(ERROR_NO_WRITABLE_DC_FOUND),  //! Could not find a writable domain controller in the domain.
		_MakeErrorCodeName(ERROR_DS_NO_SERVER_OBJECT),  //! The server object for the domain controller does not exist.
		_MakeErrorCodeName(ERROR_DS_NO_NTDSA_OBJECT),  //! The NTDS Settings object for the domain controller does not exist.
		_MakeErrorCodeName(ERROR_DS_NON_ASQ_SEARCH),  //! The requested search operation is not supported for ASQ searches.
		_MakeErrorCodeName(ERROR_DS_AUDIT_FAILURE),  //! A required audit event could not be generated for the operation.
		_MakeErrorCodeName(ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE),  //! The search flags for the attribute are invalid. The subtree index bit is valid only on single valued attributes.
		_MakeErrorCodeName(ERROR_DS_INVALID_SEARCH_FLAG_TUPLE),  //! The search flags for the attribute are invalid. The tuple index bit is valid only on attributes of Unicode strings.
		_MakeErrorCodeName(ERROR_DS_HIERARCHY_TABLE_TOO_DEEP),  //! The address books are nested too deeply. Failed to build the hierarchy table.
		_MakeErrorCodeName(ERROR_DS_DRA_CORRUPT_UTD_VECTOR),  //! The specified up-to-date-ness vector is corrupt.
		_MakeErrorCodeName(ERROR_DS_DRA_SECRETS_DENIED),  //! The request to replicate secrets is denied.
		_MakeErrorCodeName(ERROR_DS_RESERVED_MAPI_ID),  //! Schema update failed: The MAPI identifier is reserved.
		_MakeErrorCodeName(ERROR_DS_MAPI_ID_NOT_AVAILABLE),  //! Schema update failed: There are no MAPI identifiers available.
		_MakeErrorCodeName(ERROR_DS_DRA_MISSING_KRBTGT_SECRET),  //! The replication operation failed because the required attributes of the local krbtgt object are missing.
		_MakeErrorCodeName(ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST),  //! The domain name of the trusted domain already exists in the forest.
		_MakeErrorCodeName(ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST),  //! The flat name of the trusted domain already exists in the forest.
		_MakeErrorCodeName(ERROR_INVALID_USER_PRINCIPAL_NAME),  //! The User Principal Name (UPN) is invalid.
		_MakeErrorCodeName(ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS),  //! OID mapped groups cannot have members.
		_MakeErrorCodeName(ERROR_DS_OID_NOT_FOUND),  //! The specified OID cannot be found.
		_MakeErrorCodeName(ERROR_DS_DRA_RECYCLED_TARGET),  //! The replication operation failed because the target object referred by a link value is recycled.
		_MakeErrorCodeName(ERROR_DS_DISALLOWED_NC_REDIRECT),  //! The redirect operation failed because the target object is in a NC different from the domain NC of the current domain controller.
		_MakeErrorCodeName(ERROR_DS_HIGH_ADLDS_FFL),  //! The functional level of the AD LDS configuration set cannot be lowered to the requested value.
		_MakeErrorCodeName(ERROR_DS_HIGH_DSA_VERSION),  //! The functional level of the domain (or forest) cannot be lowered to the requested value.
		_MakeErrorCodeName(ERROR_DS_LOW_ADLDS_FFL),  //! The functional level of the AD LDS configuration set cannot be raised to the requested value, because there exist one or more ADLDS instances that are at a lower incompatible functional level.
		_MakeErrorCodeName(ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION),  //! The domain join cannot be completed because the SID of the domain you attempted to join was identical to the SID of this machine. This is a symptom of an improperly cloned operating system install. You should run sysprep on this machine in order to generate a new machine SID. Please see https://go.microsoft.com/fwlink/p/?linkid=168895 for more information.
		_MakeErrorCodeName(ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED),  //! The undelete operation failed because the Sam Account Name or Additional Sam Account Name of the object being undeleted conflicts with an existing live object.
		_MakeErrorCodeName(ERROR_INCORRECT_ACCOUNT_TYPE),  //! The system is not authoritative for the specified account and therefore cannot complete the operation. Please retry the operation using the provider associated with this account. If this is an online provider please use the provider's online site.
		_MakeErrorCodeName(DNS_ERROR_RCODE_FORMAT_ERROR),  //! DNS server unable to interpret format.
		_MakeErrorCodeName(DNS_ERROR_RCODE_SERVER_FAILURE),  //! DNS server failure.
		_MakeErrorCodeName(DNS_ERROR_RCODE_NAME_ERROR),  //! DNS name does not exist.
		_MakeErrorCodeName(DNS_ERROR_RCODE_NOT_IMPLEMENTED),  //! DNS request not supported by name server.
		_MakeErrorCodeName(DNS_ERROR_RCODE_REFUSED),  //! DNS operation refused.
		_MakeErrorCodeName(DNS_ERROR_RCODE_YXDOMAIN),  //! DNS name that ought not exist, does exist.
		_MakeErrorCodeName(DNS_ERROR_RCODE_YXRRSET),  //! DNS RR set that ought not exist, does exist.
		_MakeErrorCodeName(DNS_ERROR_RCODE_NXRRSET),  //! DNS RR set that ought to exist, does not exist.
		_MakeErrorCodeName(DNS_ERROR_RCODE_NOTAUTH),  //! DNS server not authoritative for zone.
		_MakeErrorCodeName(DNS_ERROR_RCODE_NOTZONE),  //! DNS name in update or prereq is not in zone.
		_MakeErrorCodeName(DNS_ERROR_RCODE_BADSIG),  //! DNS signature failed to verify.
		_MakeErrorCodeName(DNS_ERROR_RCODE_BADKEY),  //! DNS bad key.
		_MakeErrorCodeName(DNS_ERROR_RCODE_BADTIME),  //! DNS signature validity expired.
		_MakeErrorCodeName(DNS_ERROR_KEYMASTER_REQUIRED),  //! Only the DNS server acting as the key master for the zone may perform this operation.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE),  //! This operation is not allowed on a zone that is signed or has signing keys.
		_MakeErrorCodeName(DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1),  //! NSEC3 is not compatible with the RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC.
		_MakeErrorCodeName(DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS),  //! The zone does not have enough signing keys. There must be at least one key signing key (KSK) and at least one zone signing key (ZSK).
		_MakeErrorCodeName(DNS_ERROR_UNSUPPORTED_ALGORITHM),  //! The specified algorithm is not supported.
		_MakeErrorCodeName(DNS_ERROR_INVALID_KEY_SIZE),  //! The specified key size is not supported.
		_MakeErrorCodeName(DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE),  //! One or more of the signing keys for a zone are not accessible to the DNS server. Zone signing will not be operational until this error is resolved.
		_MakeErrorCodeName(DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION),  //! The specified key storage provider does not support DPAPI++ data protection. Zone signing will not be operational until this error is resolved.
		_MakeErrorCodeName(DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR),  //! An unexpected DPAPI++ error was encountered. Zone signing will not be operational until this error is resolved.
		_MakeErrorCodeName(DNS_ERROR_UNEXPECTED_CNG_ERROR),  //! An unexpected crypto error was encountered. Zone signing may not be operational until this error is resolved.
		_MakeErrorCodeName(DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION),  //! The DNS server encountered a signing key with an unknown version. Zone signing will not be operational until this error is resolved.
		_MakeErrorCodeName(DNS_ERROR_KSP_NOT_ACCESSIBLE),  //! The specified key service provider cannot be opened by the DNS server.
		_MakeErrorCodeName(DNS_ERROR_TOO_MANY_SKDS),  //! The DNS server cannot accept any more signing keys with the specified algorithm and KSK flag value for this zone.
		_MakeErrorCodeName(DNS_ERROR_INVALID_ROLLOVER_PERIOD),  //! The specified rollover period is invalid.
		_MakeErrorCodeName(DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET),  //! The specified initial rollover offset is invalid.
		_MakeErrorCodeName(DNS_ERROR_ROLLOVER_IN_PROGRESS),  //! The specified signing key is already in process of rolling over keys.
		_MakeErrorCodeName(DNS_ERROR_STANDBY_KEY_NOT_PRESENT),  //! The specified signing key does not have a standby key to revoke.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_ON_ZSK),  //! This operation is not allowed on a zone signing key (ZSK).
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD),  //! This operation is not allowed on an active signing key.
		_MakeErrorCodeName(DNS_ERROR_ROLLOVER_ALREADY_QUEUED),  //! The specified signing key is already queued for rollover.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE),  //! This operation is not allowed on an unsigned zone.
		_MakeErrorCodeName(DNS_ERROR_BAD_KEYMASTER),  //! This operation could not be completed because the DNS server listed as the current key master for this zone is down or misconfigured. Resolve the problem on the current key master for this zone or use another DNS server to seize the key master role.
		_MakeErrorCodeName(DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD),  //! The specified signature validity period is invalid.
		_MakeErrorCodeName(DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT),  //! The specified NSEC3 iteration count is higher than allowed by the minimum key length used in the zone.
		_MakeErrorCodeName(DNS_ERROR_DNSSEC_IS_DISABLED),  //! This operation could not be completed because the DNS server has been configured with DNSSEC features disabled. Enable DNSSEC on the DNS server.
		_MakeErrorCodeName(DNS_ERROR_INVALID_XML),  //! This operation could not be completed because the XML stream received is empty or syntactically invalid.
		_MakeErrorCodeName(DNS_ERROR_NO_VALID_TRUST_ANCHORS),  //! This operation completed, but no trust anchors were added because all of the trust anchors received were either invalid, unsupported, expired, or would not become valid in less than 30 days.
		_MakeErrorCodeName(DNS_ERROR_ROLLOVER_NOT_POKEABLE),  //! The specified signing key is not waiting for parental DS update.
		_MakeErrorCodeName(DNS_ERROR_NSEC3_NAME_COLLISION),  //! Hash collision detected during NSEC3 signing. Specify a different user-provided salt, or use a randomly generated salt, and attempt to sign the zone again.
		_MakeErrorCodeName(DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1),  //! NSEC is not compatible with the NSEC3-RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC3.
		_MakeErrorCodeName(DNS_INFO_NO_RECORDS),  //! No records found for given DNS query.
		_MakeErrorCodeName(DNS_ERROR_BAD_PACKET),  //! Bad DNS packet.
		_MakeErrorCodeName(DNS_ERROR_NO_PACKET),  //! No DNS packet.
		_MakeErrorCodeName(DNS_ERROR_RCODE),  //! DNS error, check rcode.
		_MakeErrorCodeName(DNS_ERROR_UNSECURE_PACKET),  //! Unsecured DNS packet.
		_MakeErrorCodeName(DNS_REQUEST_PENDING),  //! DNS query request is pending.
		_MakeErrorCodeName(DNS_ERROR_INVALID_TYPE),  //! Invalid DNS type.
		_MakeErrorCodeName(DNS_ERROR_INVALID_IP_ADDRESS),  //! Invalid IP address.
		_MakeErrorCodeName(DNS_ERROR_INVALID_PROPERTY),  //! Invalid property.
		_MakeErrorCodeName(DNS_ERROR_TRY_AGAIN_LATER),  //! Try DNS operation again later.
		_MakeErrorCodeName(DNS_ERROR_NOT_UNIQUE),  //! Record for given name and type is not unique.
		_MakeErrorCodeName(DNS_ERROR_NON_RFC_NAME),  //! DNS name does not comply with RFC specifications.
		_MakeErrorCodeName(DNS_STATUS_FQDN),  //! DNS name is a fully-qualified DNS name.
		_MakeErrorCodeName(DNS_STATUS_DOTTED_NAME),  //! DNS name is dotted (multi-label).
		_MakeErrorCodeName(DNS_STATUS_SINGLE_PART_NAME),  //! DNS name is a single-part name.
		_MakeErrorCodeName(DNS_ERROR_INVALID_NAME_CHAR),  //! DNS name contains an invalid character.
		_MakeErrorCodeName(DNS_ERROR_NUMERIC_NAME),  //! DNS name is entirely numeric.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER),  //! The operation requested is not permitted on a DNS root server.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION),  //! The record could not be created because this part of the DNS namespace has been delegated to another server.
		_MakeErrorCodeName(DNS_ERROR_CANNOT_FIND_ROOT_HINTS),  //! The DNS server could not find a set of root hints.
		_MakeErrorCodeName(DNS_ERROR_INCONSISTENT_ROOT_HINTS),  //! The DNS server found root hints but they were not consistent across all adapters.
		_MakeErrorCodeName(DNS_ERROR_DWORD_VALUE_TOO_SMALL),  //! The specified value is too small for this parameter.
		_MakeErrorCodeName(DNS_ERROR_DWORD_VALUE_TOO_LARGE),  //! The specified value is too large for this parameter.
		_MakeErrorCodeName(DNS_ERROR_BACKGROUND_LOADING),  //! This operation is not allowed while the DNS server is loading zones in the background. Please try again later.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_ON_RODC),  //! The operation requested is not permitted on against a DNS server running on a read-only DC.
		_MakeErrorCodeName(DNS_ERROR_NOT_ALLOWED_UNDER_DNAME),  //! No data is allowed to exist underneath a DNAME record.
		_MakeErrorCodeName(DNS_ERROR_DELEGATION_REQUIRED),  //! This operation requires credentials delegation.
		_MakeErrorCodeName(DNS_ERROR_INVALID_POLICY_TABLE),  //! Name resolution policy table has been corrupted. DNS resolution will fail until it is fixed. Contact your network administrator.
		_MakeErrorCodeName(DNS_ERROR_ZONE_DOES_NOT_EXIST),  //! DNS zone does not exist.
		_MakeErrorCodeName(DNS_ERROR_NO_ZONE_INFO),  //! DNS zone information not available.
		_MakeErrorCodeName(DNS_ERROR_INVALID_ZONE_OPERATION),  //! Invalid operation for DNS zone.
		_MakeErrorCodeName(DNS_ERROR_ZONE_CONFIGURATION_ERROR),  //! Invalid DNS zone configuration.
		_MakeErrorCodeName(DNS_ERROR_ZONE_HAS_NO_SOA_RECORD),  //! DNS zone has no start of authority (SOA) record.
		_MakeErrorCodeName(DNS_ERROR_ZONE_HAS_NO_NS_RECORDS),  //! DNS zone has no Name Server (NS) record.
		_MakeErrorCodeName(DNS_ERROR_ZONE_LOCKED),  //! DNS zone is locked.
		_MakeErrorCodeName(DNS_ERROR_ZONE_CREATION_FAILED),  //! DNS zone creation failed.
		_MakeErrorCodeName(DNS_ERROR_ZONE_ALREADY_EXISTS),  //! DNS zone already exists.
		_MakeErrorCodeName(DNS_ERROR_AUTOZONE_ALREADY_EXISTS),  //! DNS automatic zone already exists.
		_MakeErrorCodeName(DNS_ERROR_INVALID_ZONE_TYPE),  //! Invalid DNS zone type.
		_MakeErrorCodeName(DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP),  //! Secondary DNS zone requires master IP address.
		_MakeErrorCodeName(DNS_ERROR_ZONE_NOT_SECONDARY),  //! DNS zone not secondary.
		_MakeErrorCodeName(DNS_ERROR_NEED_SECONDARY_ADDRESSES),  //! Need secondary IP address.
		_MakeErrorCodeName(DNS_ERROR_WINS_INIT_FAILED),  //! WINS initialization failed.
		_MakeErrorCodeName(DNS_ERROR_NEED_WINS_SERVERS),  //! Need WINS servers.
		_MakeErrorCodeName(DNS_ERROR_NBSTAT_INIT_FAILED),  //! NBTSTAT initialization call failed.
		_MakeErrorCodeName(DNS_ERROR_SOA_DELETE_INVALID),  //! Invalid delete of start of authority (SOA).
		_MakeErrorCodeName(DNS_ERROR_FORWARDER_ALREADY_EXISTS),  //! A conditional forwarding zone already exists for that name.
		_MakeErrorCodeName(DNS_ERROR_ZONE_REQUIRES_MASTER_IP),  //! This zone must be configured with one or more master DNS server IP addresses.
		_MakeErrorCodeName(DNS_ERROR_ZONE_IS_SHUTDOWN),  //! The operation cannot be performed because this zone is shut down.
		_MakeErrorCodeName(DNS_ERROR_ZONE_LOCKED_FOR_SIGNING),  //! This operation cannot be performed because the zone is currently being signed. Please try again later.
		_MakeErrorCodeName(DNS_ERROR_PRIMARY_REQUIRES_DATAFILE),  //! Primary DNS zone requires datafile.
		_MakeErrorCodeName(DNS_ERROR_INVALID_DATAFILE_NAME),  //! Invalid datafile name for DNS zone.
		_MakeErrorCodeName(DNS_ERROR_DATAFILE_OPEN_FAILURE),  //! Failed to open datafile for DNS zone.
		_MakeErrorCodeName(DNS_ERROR_FILE_WRITEBACK_FAILED),  //! Failed to write datafile for DNS zone.
		_MakeErrorCodeName(DNS_ERROR_DATAFILE_PARSING),  //! Failure while reading datafile for DNS zone.
		_MakeErrorCodeName(DNS_ERROR_RECORD_DOES_NOT_EXIST),  //! DNS record does not exist.
		_MakeErrorCodeName(DNS_ERROR_RECORD_FORMAT),  //! DNS record format error.
		_MakeErrorCodeName(DNS_ERROR_NODE_CREATION_FAILED),  //! Node creation failure in DNS.
		_MakeErrorCodeName(DNS_ERROR_UNKNOWN_RECORD_TYPE),  //! Unknown DNS record type.
		_MakeErrorCodeName(DNS_ERROR_RECORD_TIMED_OUT),  //! DNS record timed out.
		_MakeErrorCodeName(DNS_ERROR_NAME_NOT_IN_ZONE),  //! Name not in DNS zone.
		_MakeErrorCodeName(DNS_ERROR_CNAME_LOOP),  //! CNAME loop detected.
		_MakeErrorCodeName(DNS_ERROR_NODE_IS_CNAME),  //! Node is a CNAME DNS record.
		_MakeErrorCodeName(DNS_ERROR_CNAME_COLLISION),  //! A CNAME record already exists for given name.
		_MakeErrorCodeName(DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT),  //! Record only at DNS zone root.
		_MakeErrorCodeName(DNS_ERROR_RECORD_ALREADY_EXISTS),  //! DNS record already exists.
		_MakeErrorCodeName(DNS_ERROR_SECONDARY_DATA),  //! Secondary DNS zone data error.
		_MakeErrorCodeName(DNS_ERROR_NO_CREATE_CACHE_DATA),  //! Could not create DNS cache data.
		_MakeErrorCodeName(DNS_ERROR_NAME_DOES_NOT_EXIST),  //! DNS name does not exist.
		_MakeErrorCodeName(DNS_WARNING_PTR_CREATE_FAILED),  //! Could not create pointer (PTR) record.
		_MakeErrorCodeName(DNS_WARNING_DOMAIN_UNDELETED),  //! DNS domain was undeleted.
		_MakeErrorCodeName(DNS_ERROR_DS_UNAVAILABLE),  //! The directory service is unavailable.
		_MakeErrorCodeName(DNS_ERROR_DS_ZONE_ALREADY_EXISTS),  //! DNS zone already exists in the directory service.
		_MakeErrorCodeName(DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE),  //! DNS server not creating or reading the boot file for the directory service integrated DNS zone.
		_MakeErrorCodeName(DNS_ERROR_NODE_IS_DNAME),  //! Node is a DNAME DNS record.
		_MakeErrorCodeName(DNS_ERROR_DNAME_COLLISION),  //! A DNAME record already exists for given name.
		_MakeErrorCodeName(DNS_ERROR_ALIAS_LOOP),  //! An alias loop has been detected with either CNAME or DNAME records.
		_MakeErrorCodeName(DNS_INFO_AXFR_COMPLETE),  //! DNS AXFR (zone transfer) complete.
		_MakeErrorCodeName(DNS_ERROR_AXFR),  //! DNS zone transfer failed.
		_MakeErrorCodeName(DNS_INFO_ADDED_LOCAL_WINS),  //! Added local WINS server.
		_MakeErrorCodeName(DNS_STATUS_CONTINUE_NEEDED),  //! Secure update call needs to continue update request.
		_MakeErrorCodeName(DNS_ERROR_NO_TCPIP),  //! TCP/IP network protocol not installed.
		_MakeErrorCodeName(DNS_ERROR_NO_DNS_SERVERS),  //! No DNS servers configured for local system.
		_MakeErrorCodeName(DNS_ERROR_DP_DOES_NOT_EXIST),  //! The specified directory partition does not exist.
		_MakeErrorCodeName(DNS_ERROR_DP_ALREADY_EXISTS),  //! The specified directory partition already exists.
		_MakeErrorCodeName(DNS_ERROR_DP_NOT_ENLISTED),  //! This DNS server is not enlisted in the specified directory partition.
		_MakeErrorCodeName(DNS_ERROR_DP_ALREADY_ENLISTED),  //! This DNS server is already enlisted in the specified directory partition.
		_MakeErrorCodeName(DNS_ERROR_DP_NOT_AVAILABLE),  //! The directory partition is not available at this time. Please wait a few minutes and try again.
		_MakeErrorCodeName(DNS_ERROR_DP_FSMO_ERROR),  //! The operation failed because the domain naming master FSMO role could not be reached. The domain controller holding the domain naming master FSMO role is down or unable to service the request or is not running Windows Server 2003 or later.
		_MakeErrorCodeName(WSAEINTR),  //! A blocking operation was interrupted by a call to WSACancelBlockingCall.
		_MakeErrorCodeName(WSAEBADF),  //! The file handle supplied is not valid.
		_MakeErrorCodeName(WSAEACCES),  //! An attempt was made to access a socket in a way forbidden by its access permissions.
		_MakeErrorCodeName(WSAEFAULT),  //! The system detected an invalid pointer address in attempting to use a pointer argument in a call.
		_MakeErrorCodeName(WSAEINVAL),  //! An invalid argument was supplied.
		_MakeErrorCodeName(WSAEMFILE),  //! Too many open sockets.
		_MakeErrorCodeName(WSAEWOULDBLOCK),  //! A non-blocking socket operation could not be completed immediately.
		_MakeErrorCodeName(WSAEINPROGRESS),  //! A blocking operation is currently executing.
		_MakeErrorCodeName(WSAEALREADY),  //! An operation was attempted on a non-blocking socket that already had an operation in progress.
		_MakeErrorCodeName(WSAENOTSOCK),  //! An operation was attempted on something that is not a socket.
		_MakeErrorCodeName(WSAEDESTADDRREQ),  //! A required address was omitted from an operation on a socket.
		_MakeErrorCodeName(WSAEMSGSIZE),  //! A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.
		_MakeErrorCodeName(WSAEPROTOTYPE),  //! A protocol was specified in the socket function call that does not support the semantics of the socket type requested.
		_MakeErrorCodeName(WSAENOPROTOOPT),  //! An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.
		_MakeErrorCodeName(WSAEPROTONOSUPPORT),  //! The requested protocol has not been configured into the system, or no implementation for it exists.
		_MakeErrorCodeName(WSAESOCKTNOSUPPORT),  //! The support for the specified socket type does not exist in this address family.
		_MakeErrorCodeName(WSAEOPNOTSUPP),  //! The attempted operation is not supported for the type of object referenced.
		_MakeErrorCodeName(WSAEPFNOSUPPORT),  //! The protocol family has not been configured into the system or no implementation for it exists.
		_MakeErrorCodeName(WSAEAFNOSUPPORT),  //! An address incompatible with the requested protocol was used.
		_MakeErrorCodeName(WSAEADDRINUSE),  //! Only one usage of each socket address (protocol/network address/port) is normally permitted.
		_MakeErrorCodeName(WSAEADDRNOTAVAIL),  //! The requested address is not valid in its context.
		_MakeErrorCodeName(WSAENETDOWN),  //! A socket operation encountered a dead network.
		_MakeErrorCodeName(WSAENETUNREACH),  //! A socket operation was attempted to an unreachable network.
		_MakeErrorCodeName(WSAENETRESET),  //! The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.
		_MakeErrorCodeName(WSAECONNABORTED),  //! An established connection was aborted by the software in your host machine.
		_MakeErrorCodeName(WSAECONNRESET),  //! An existing connection was forcibly closed by the remote host.
		_MakeErrorCodeName(WSAENOBUFS),  //! An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
		_MakeErrorCodeName(WSAEISCONN),  //! A connect request was made on an already connected socket.
		_MakeErrorCodeName(WSAENOTCONN),  //! A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.
		_MakeErrorCodeName(WSAESHUTDOWN),  //! A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.
		_MakeErrorCodeName(WSAETOOMANYREFS),  //! Too many references to some kernel object.
		_MakeErrorCodeName(WSAETIMEDOUT),  //! A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
		_MakeErrorCodeName(WSAECONNREFUSED),  //! No connection could be made because the target machine actively refused it.
		_MakeErrorCodeName(WSAELOOP),  //! Cannot translate name.
		_MakeErrorCodeName(WSAENAMETOOLONG),  //! Name component or name was too long.
		_MakeErrorCodeName(WSAEHOSTDOWN),  //! A socket operation failed because the destination host was down.
		_MakeErrorCodeName(WSAEHOSTUNREACH),  //! A socket operation was attempted to an unreachable host.
		_MakeErrorCodeName(WSAENOTEMPTY),  //! Cannot remove a directory that is not empty.
		_MakeErrorCodeName(WSAEPROCLIM),  //! A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.
		_MakeErrorCodeName(WSAEUSERS),  //! Ran out of quota.
		_MakeErrorCodeName(WSAEDQUOT),  //! Ran out of disk quota.
		_MakeErrorCodeName(WSAESTALE),  //! File handle reference is no longer available.
		_MakeErrorCodeName(WSAEREMOTE),  //! Item is not available locally.
		_MakeErrorCodeName(WSASYSNOTREADY),  //! WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.
		_MakeErrorCodeName(WSAVERNOTSUPPORTED),  //! The Windows Sockets version requested is not supported.
		_MakeErrorCodeName(WSANOTINITIALISED),  //! Either the application has not called WSAStartup, or WSAStartup failed.
		_MakeErrorCodeName(WSAEDISCON),  //! Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.
		_MakeErrorCodeName(WSAENOMORE),  //! No more results can be returned by WSALookupServiceNext.
		_MakeErrorCodeName(WSAECANCELLED),  //! A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
		_MakeErrorCodeName(WSAEINVALIDPROCTABLE),  //! The procedure call table is invalid.
		_MakeErrorCodeName(WSAEINVALIDPROVIDER),  //! The requested service provider is invalid.
		_MakeErrorCodeName(WSAEPROVIDERFAILEDINIT),  //! The requested service provider could not be loaded or initialized.
		_MakeErrorCodeName(WSASYSCALLFAILURE),  //! A system call has failed.
		_MakeErrorCodeName(WSASERVICE_NOT_FOUND),  //! No such service is known. The service cannot be found in the specified name space.
		_MakeErrorCodeName(WSATYPE_NOT_FOUND),  //! The specified class was not found.
		_MakeErrorCodeName(WSA_E_NO_MORE),  //! No more results can be returned by WSALookupServiceNext.
		_MakeErrorCodeName(WSA_E_CANCELLED),  //! A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
		_MakeErrorCodeName(WSAEREFUSED),  //! A database query failed because it was actively refused.
		_MakeErrorCodeName(WSAHOST_NOT_FOUND),  //! No such host is known.
		_MakeErrorCodeName(WSATRY_AGAIN),  //! This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.
		_MakeErrorCodeName(WSANO_RECOVERY),  //! A non-recoverable error occurred during a database lookup.
		_MakeErrorCodeName(WSANO_DATA),  //! The requested name is valid, but no data of the requested type was found.
		_MakeErrorCodeName(WSA_QOS_RECEIVERS),  //! At least one reserve has arrived.
		_MakeErrorCodeName(WSA_QOS_SENDERS),  //! At least one path has arrived.
		_MakeErrorCodeName(WSA_QOS_NO_SENDERS),  //! There are no senders.
		_MakeErrorCodeName(WSA_QOS_NO_RECEIVERS),  //! There are no receivers.
		_MakeErrorCodeName(WSA_QOS_REQUEST_CONFIRMED),  //! Reserve has been confirmed.
		_MakeErrorCodeName(WSA_QOS_ADMISSION_FAILURE),  //! Error due to lack of resources.
		_MakeErrorCodeName(WSA_QOS_POLICY_FAILURE),  //! Rejected for administrative reasons - bad credentials.
		_MakeErrorCodeName(WSA_QOS_BAD_STYLE),  //! Unknown or conflicting style.
		_MakeErrorCodeName(WSA_QOS_BAD_OBJECT),  //! Problem with some part of the filterspec or providerspecific buffer in general.
		_MakeErrorCodeName(WSA_QOS_TRAFFIC_CTRL_ERROR),  //! Problem with some part of the flowspec.
		_MakeErrorCodeName(WSA_QOS_GENERIC_ERROR),  //! General QOS error.
		_MakeErrorCodeName(WSA_QOS_ESERVICETYPE),  //! An invalid or unrecognized service type was found in the flowspec.
		_MakeErrorCodeName(WSA_QOS_EFLOWSPEC),  //! An invalid or inconsistent flowspec was found in the QOS structure.
		_MakeErrorCodeName(WSA_QOS_EPROVSPECBUF),  //! Invalid QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_QOS_EFILTERSTYLE),  //! An invalid QOS filter style was used.
		_MakeErrorCodeName(WSA_QOS_EFILTERTYPE),  //! An invalid QOS filter type was used.
		_MakeErrorCodeName(WSA_QOS_EFILTERCOUNT),  //! An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
		_MakeErrorCodeName(WSA_QOS_EOBJLENGTH),  //! An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_QOS_EFLOWCOUNT),  //! An incorrect number of flow descriptors was specified in the QOS structure.
		_MakeErrorCodeName(WSA_QOS_EUNKOWNPSOBJ),  //! An unrecognized object was found in the QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_QOS_EPOLICYOBJ),  //! An invalid policy object was found in the QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_QOS_EFLOWDESC),  //! An invalid QOS flow descriptor was found in the flow descriptor list.
		_MakeErrorCodeName(WSA_QOS_EPSFLOWSPEC),  //! An invalid or inconsistent flowspec was found in the QOS provider specific buffer.
		_MakeErrorCodeName(WSA_QOS_EPSFILTERSPEC),  //! An invalid FILTERSPEC was found in the QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_QOS_ESDMODEOBJ),  //! An invalid shape discard mode object was found in the QOS provider specific buffer.
		_MakeErrorCodeName(WSA_QOS_ESHAPERATEOBJ),  //! An invalid shaping rate object was found in the QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_QOS_RESERVED_PETYPE),  //! A reserved policy element was found in the QOS provider-specific buffer.
		_MakeErrorCodeName(WSA_SECURE_HOST_NOT_FOUND),  //! No such host is known securely.
		_MakeErrorCodeName(WSA_IPSEC_NAME_POLICY_ERROR),  //! Name based IPSEC policy could not be added.

#pragma region ERROR_INTERNET
		/*ERROR_INTERNET_*
		12000 - 12175 (0x2EE0)
		See Internet Error Codes and WinInet.h.*/
		_MakeErrorCodeName(ERROR_FTP_DROPPED),  //! The FTP operation was not completed because the session was aborted.
		_MakeErrorCodeName(ERROR_FTP_NO_PASSIVE_MODE),  //! Passive mode is not available on the server.
		_MakeErrorCodeName(ERROR_FTP_TRANSFER_IN_PROGRESS),  //! The requested operation cannot be made on the FTP session handle because an operation is already in progress.
		_MakeErrorCodeName(ERROR_GOPHER_ATTRIBUTE_NOT_FOUND),  //! The requested attribute could not be located.
		_MakeErrorCodeName(ERROR_GOPHER_DATA_ERROR),  //! An error was detected while receiving data from the Gopher server.
		_MakeErrorCodeName(ERROR_GOPHER_END_OF_DATA),  //! The end of the data has been reached.
		_MakeErrorCodeName(ERROR_GOPHER_INCORRECT_LOCATOR_TYPE),  //! The type of the locator is not correct for this operation.
		_MakeErrorCodeName(ERROR_GOPHER_INVALID_LOCATOR),  //! The supplied locator is not valid.
		_MakeErrorCodeName(ERROR_GOPHER_NOT_FILE),  //! The request must be made for a file locator.
		_MakeErrorCodeName(ERROR_GOPHER_NOT_GOPHER_PLUS),  //! The requested operation can be made only against a Gopher+ server, or with a locator that specifies a Gopher+ operation.
		_MakeErrorCodeName(ERROR_GOPHER_PROTOCOL_ERROR),  //! An error was detected while parsing data returned from the Gopher server.
		_MakeErrorCodeName(ERROR_GOPHER_UNKNOWN_LOCATOR),  //! The locator type is unknown.
		_MakeErrorCodeName(ERROR_HTTP_COOKIE_DECLINED),  //! The HTTP cookie was declined by the server.
		_MakeErrorCodeName(ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION),  //! The HTTP cookie requires confirmation.
		_MakeErrorCodeName(ERROR_HTTP_DOWNLEVEL_SERVER),  //! The server did not return any headers.
		_MakeErrorCodeName(ERROR_HTTP_HEADER_ALREADY_EXISTS),  //! The header could not be added because it already exists.
		_MakeErrorCodeName(ERROR_HTTP_HEADER_NOT_FOUND),  //! The requested header could not be located.
		_MakeErrorCodeName(ERROR_HTTP_INVALID_HEADER),  //! The supplied header is invalid.
		_MakeErrorCodeName(ERROR_HTTP_INVALID_QUERY_REQUEST),  //! The request made to HttpQueryInfo is invalid.
		_MakeErrorCodeName(ERROR_HTTP_INVALID_SERVER_RESPONSE),  //! The server response could not be parsed.
		_MakeErrorCodeName(ERROR_HTTP_NOT_REDIRECTED),  //! The HTTP request was not redirected.
		_MakeErrorCodeName(ERROR_HTTP_REDIRECT_FAILED),  //! The redirection failed because either the scheme changed (for example, HTTP to FTP) or all attempts made to redirect failed (default is five attempts).
		_MakeErrorCodeName(ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION),  //! The redirection requires user confirmation.
		_MakeErrorCodeName(ERROR_INTERNET_ASYNC_THREAD_FAILED),  //! The application could not start an asynchronous thread.
		_MakeErrorCodeName(ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT),  //! There was an error in the automatic proxy configuration script.
		_MakeErrorCodeName(ERROR_INTERNET_BAD_OPTION_LENGTH),  //! The length of an option supplied to InternetQueryOption or InternetSetOption is incorrect for the type of option specified.
		_MakeErrorCodeName(ERROR_INTERNET_BAD_REGISTRY_PARAMETER),  //! A required registry value was located but is an incorrect type or has an invalid value.
		_MakeErrorCodeName(ERROR_INTERNET_CANNOT_CONNECT),  //! The attempt to connect to the server failed.
		_MakeErrorCodeName(ERROR_INTERNET_CHG_POST_IS_NON_SECURE),  //! The application is posting and attempting to change multiple lines of text on a server that is not secure.
		_MakeErrorCodeName(ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED),  //! The server is requesting client authentication.
		_MakeErrorCodeName(ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP),  //! Client authorization is not set up on this computer.
		_MakeErrorCodeName(ERROR_INTERNET_CONNECTION_ABORTED),  //! The connection with the server has been terminated.
		_MakeErrorCodeName(ERROR_INTERNET_CONNECTION_RESET),  //! The connection with the server has been reset.
		_MakeErrorCodeName(ERROR_INTERNET_DECODING_FAILED),  //! WinINet failed to perform content decoding on the response. For more information, see the Content Encoding topic.
		_MakeErrorCodeName(ERROR_INTERNET_DIALOG_PENDING),  //! Another thread has a password dialog box in progress.
		_MakeErrorCodeName(ERROR_INTERNET_DISCONNECTED),  //! The Internet connection has been lost.
		_MakeErrorCodeName(ERROR_INTERNET_EXTENDED_ERROR),  //! An extended error was returned from the server. This is typically a string or buffer containing a verbose error message. Call InternetGetLastResponseInfo to retrieve the error text.
		_MakeErrorCodeName(ERROR_INTERNET_FAILED_DUETOSECURITYCHECK),  //! The function failed due to a security check.
		_MakeErrorCodeName(ERROR_INTERNET_FORCE_RETRY),  //! The function needs to redo the request.
		_MakeErrorCodeName(ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED),  //! The requested resource requires Fortezza authentication.
		_MakeErrorCodeName(ERROR_INTERNET_HANDLE_EXISTS),  //! The request failed because the handle already exists.
		_MakeErrorCodeName(ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR),  //! The application is moving from a non-SSL to an SSL connection because of a redirect.
		_MakeErrorCodeName(ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR),  //! The data being submitted to an SSL connection is being redirected to a non-SSL connection.
		_MakeErrorCodeName(ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR),  //! The application is moving from an SSL to an non-SSL connection because of a redirect.
		_MakeErrorCodeName(ERROR_INTERNET_INCORRECT_FORMAT),  //! The format of the request is invalid.
		_MakeErrorCodeName(ERROR_INTERNET_INCORRECT_HANDLE_STATE),  //! The requested operation cannot be carried out because the handle supplied is not in the correct state.
		_MakeErrorCodeName(ERROR_INTERNET_INCORRECT_HANDLE_TYPE),  //! The type of handle supplied is incorrect for this operation.
		_MakeErrorCodeName(ERROR_INTERNET_INCORRECT_PASSWORD),  //! The request to connect and log on to an FTP server could not be completed because the supplied password is incorrect.
		_MakeErrorCodeName(ERROR_INTERNET_INCORRECT_USER_NAME),  //! The request to connect and log on to an FTP server could not be completed because the supplied user name is incorrect.
		_MakeErrorCodeName(ERROR_INTERNET_INSERT_CDROM),  //! The request requires a CD-ROM to be inserted in the CD-ROM drive to locate the resource requested.
		_MakeErrorCodeName(ERROR_INTERNET_INTERNAL_ERROR),  //! An internal error has occurred.
		_MakeErrorCodeName(ERROR_INTERNET_INVALID_CA),  //! The function is unfamiliar with the Certificate Authority that generated the server's certificate.
		_MakeErrorCodeName(ERROR_INTERNET_INVALID_OPERATION),  //! The requested operation is invalid.
		_MakeErrorCodeName(ERROR_INTERNET_INVALID_OPTION),  //! A request to InternetQueryOption or InternetSetOption specified an invalid option value.
		_MakeErrorCodeName(ERROR_INTERNET_INVALID_PROXY_REQUEST),  //! The request to the proxy was invalid.
		_MakeErrorCodeName(ERROR_INTERNET_INVALID_URL),  //! The URL is invalid.
		_MakeErrorCodeName(ERROR_INTERNET_ITEM_NOT_FOUND),  //! The requested item could not be located.
		_MakeErrorCodeName(ERROR_INTERNET_LOGIN_FAILURE),  //! The request to connect and log on to an FTP server failed.
		_MakeErrorCodeName(ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY),  //! The MS-Logoff digest header has been returned from the website. This header specifically instructs the digest package to purge credentials for the associated realm. This error will only be returned if INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY option has been set; otherwise, ERROR_INTERNET_LOGIN_FAILURE is returned.
		_MakeErrorCodeName(ERROR_INTERNET_MIXED_SECURITY),  //! The content is not entirely secure. Some of the content being viewed may have come from unsecured servers.
		_MakeErrorCodeName(ERROR_INTERNET_NAME_NOT_RESOLVED),  //! The server name could not be resolved.
		_MakeErrorCodeName(ERROR_INTERNET_NEED_MSN_SSPI_PKG),  //! Not currently implemented.
		_MakeErrorCodeName(ERROR_INTERNET_NEED_UI),  //! A user interface or other blocking operation has been requested.
		_MakeErrorCodeName(ERROR_INTERNET_NO_CALLBACK),  //! An asynchronous request could not be made because a callback function has not been set.
		_MakeErrorCodeName(ERROR_INTERNET_NO_CONTEXT),  //! An asynchronous request could not be made because a zero context value was supplied.
		_MakeErrorCodeName(ERROR_INTERNET_NO_DIRECT_ACCESS),  //! Direct network access cannot be made at this time.
		_MakeErrorCodeName(ERROR_INTERNET_NOT_INITIALIZED),  //! Initialization of the WinINet API has not occurred. Indicates that a higher-level function, such as InternetOpen, has not been called yet.
		_MakeErrorCodeName(ERROR_INTERNET_NOT_PROXY_REQUEST),  //! The request cannot be made via a proxy.
		_MakeErrorCodeName(ERROR_INTERNET_OPERATION_CANCELLED),  //! The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed.
		_MakeErrorCodeName(ERROR_INTERNET_OPTION_NOT_SETTABLE),  //! The requested option cannot be set, only queried.
		_MakeErrorCodeName(ERROR_INTERNET_OUT_OF_HANDLES),  //! No more handles could be generated at this time.
		_MakeErrorCodeName(ERROR_INTERNET_POST_IS_NON_SECURE),  //! The application is posting data to a server that is not secure.
		_MakeErrorCodeName(ERROR_INTERNET_PROTOCOL_NOT_FOUND),  //! The requested protocol could not be located.
		_MakeErrorCodeName(ERROR_INTERNET_PROXY_SERVER_UNREACHABLE),  //! The designated proxy server cannot be reached.
		_MakeErrorCodeName(ERROR_INTERNET_REDIRECT_SCHEME_CHANGE),  //! The function could not handle the redirection, because the scheme changed (for example, HTTP to FTP).
		_MakeErrorCodeName(ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND),  //! A required registry value could not be located.
		_MakeErrorCodeName(ERROR_INTERNET_REQUEST_PENDING),  //! The required operation could not be completed because one or more requests are pending.
		_MakeErrorCodeName(ERROR_INTERNET_RETRY_DIALOG),  //! The dialog box should be retried.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_CERT_CN_INVALID),  //! SSL certificate common name (host name field) is incorrect for example, if you entered www.server.com and the common name on the certificate says www.different.com.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_CERT_DATE_INVALID),  //! SSL certificate date that was received from the server is bad. The certificate is expired.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_CERT_ERRORS),  //! The SSL certificate contains errors.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_CERT_NO_REV),  //! The SSL certificate was not revoked.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_CERT_REV_FAILED),  //! Revocation of the SSL certificate failed.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_CERT_REVOKED),  //! The SSL certificate was revoked.
		_MakeErrorCodeName(ERROR_INTERNET_SEC_INVALID_CERT),  //! The SSL certificate is invalid.
		_MakeErrorCodeName(ERROR_INTERNET_SECURITY_CHANNEL_ERROR),  //! The application experienced an internal error loading the SSL libraries.
		_MakeErrorCodeName(ERROR_INTERNET_SERVER_UNREACHABLE),  //! The website or server indicated is unreachable.
		_MakeErrorCodeName(ERROR_INTERNET_SHUTDOWN),  //! WinINet support is being shut down or unloaded.
		_MakeErrorCodeName(ERROR_INTERNET_TCPIP_NOT_INSTALLED),  //! The required protocol stack is not loaded and the application cannot start WinSock.
		_MakeErrorCodeName(ERROR_INTERNET_TIMEOUT),  //! The request has timed out.
		_MakeErrorCodeName(ERROR_INTERNET_UNABLE_TO_CACHE_FILE),  //! The function was unable to cache the file.
		_MakeErrorCodeName(ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT),  //! The automatic proxy configuration script could not be downloaded. The INTERNET_FLAG_MUST_CACHE_REQUEST flag was set.
		_MakeErrorCodeName(ERROR_INTERNET_UNRECOGNIZED_SCHEME),  //! The URL scheme could not be recognized, or is not supported.

#pragma endregion

#pragma region ERROR_WINHTTP
		/*ERROR_WINHTTP_*
		12001 - 12184 (0x2EE1)
		See WinHTTP Error Codes and Winhttp.h.*/

		_MakeErrorCodeName(ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR),  //! Returned by WinHttpGetProxyForUrl when a proxy for the specified URL cannot be located.
		_MakeErrorCodeName(ERROR_WINHTTP_AUTODETECTION_FAILED),  //! Returned by WinHttpDetectAutoProxyConfigUrl if WinHTTP was unable to discover the URL of the Proxy Auto-Configuration (PAC) file.
		_MakeErrorCodeName(ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT),  //! An error occurred executing the script code in the Proxy Auto-Configuration (PAC) file.
		_MakeErrorCodeName(ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN),  //! Returned by the HttpRequest object if a specified option cannot be requested after the Open method has been called.
		_MakeErrorCodeName(ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND),  //! Returned by the HttpRequest object if a requested operation cannot be performed after calling the Send method.
		_MakeErrorCodeName(ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN),  //! Returned by the HttpRequest object if a requested operation cannot be performed before calling the Open method.
		_MakeErrorCodeName(ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND),  //! Returned by the HttpRequest object if a requested operation cannot be performed before calling the Send method.
		_MakeErrorCodeName(ERROR_WINHTTP_CANNOT_CONNECT),  //! Returned if connection to the server failed.
		_MakeErrorCodeName(ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED),  //! The server requires SSL client Authentication. 
		_MakeErrorCodeName(ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY),  //! The application does not have the required privileges to access the private key associated with the client certificate.
		_MakeErrorCodeName(ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY),  //! The context for the SSL client certificate does not have a private key associated with it. The client certificate may have been imported to the computer without the private key.
		_MakeErrorCodeName(ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW),  //! Returned by WinHttpReceiveResponse when an overflow condition is encountered in the course of parsing chunked encoding.
		_MakeErrorCodeName(ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED),  //! Returned by WinHttpReceiveResponse when the server requests client authentication.
		_MakeErrorCodeName(ERROR_WINHTTP_CONNECTION_ERROR),  //! The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it.
		_MakeErrorCodeName(ERROR_WINHTTP_HEADER_ALREADY_EXISTS),  //! Obsolete; no longer used.
		_MakeErrorCodeName(ERROR_WINHTTP_HEADER_COUNT_EXCEEDED),  //! Returned by WinHttpReceiveResponse when a larger number of headers were present in a response than WinHTTP could receive.
		_MakeErrorCodeName(ERROR_WINHTTP_HEADER_NOT_FOUND),  //! The requested header cannot be located.
		_MakeErrorCodeName(ERROR_WINHTTP_HEADER_SIZE_OVERFLOW),  //! Returned by WinHttpReceiveResponse when the size of headers received exceeds the limit for the request handle.
		_MakeErrorCodeName(ERROR_WINHTTP_INCORRECT_HANDLE_STATE),  //! The requested operation cannot be carried out because the handle supplied is not in the correct state.
		_MakeErrorCodeName(ERROR_WINHTTP_INCORRECT_HANDLE_TYPE),  //! The type of handle supplied is incorrect for this operation.
		_MakeErrorCodeName(ERROR_WINHTTP_INTERNAL_ERROR),  //! An internal error has occurred.
		_MakeErrorCodeName(ERROR_WINHTTP_INVALID_OPTION),  //! A request to WinHttpQueryOption or WinHttpSetOption specified an invalid option value.
		_MakeErrorCodeName(ERROR_WINHTTP_INVALID_QUERY_REQUEST),  //! Obsolete; no longer used.
		_MakeErrorCodeName(ERROR_WINHTTP_INVALID_SERVER_RESPONSE),  //! The server response cannot be parsed.
		_MakeErrorCodeName(ERROR_WINHTTP_INVALID_URL),  //! The URL is not valid.
		_MakeErrorCodeName(ERROR_WINHTTP_LOGIN_FAILURE),  //! The login attempt failed. When this error is encountered, the request handle should be closed with WinHttpCloseHandle. A new request handle must be created before retrying the function that originally produced this error.
		_MakeErrorCodeName(ERROR_WINHTTP_NAME_NOT_RESOLVED),  //! The server name cannot be resolved.
		_MakeErrorCodeName(ERROR_WINHTTP_NOT_INITIALIZED),  //! Obsolete; no longer used.
		_MakeErrorCodeName(ERROR_WINHTTP_OPERATION_CANCELLED),  //! The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed.
		_MakeErrorCodeName(ERROR_WINHTTP_OPTION_NOT_SETTABLE),  //! The requested option cannot be set, only queried.
		_MakeErrorCodeName(ERROR_WINHTTP_OUT_OF_HANDLES),  //! Obsolete; no longer used.
		_MakeErrorCodeName(ERROR_WINHTTP_REDIRECT_FAILED),  //! The redirection failed because either the scheme changed or all attempts made to redirect failed (default is five attempts).
		_MakeErrorCodeName(ERROR_WINHTTP_RESEND_REQUEST),  //! The WinHTTP function failed. The desired function can be retried on the same request handle.
		_MakeErrorCodeName(ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW),  //! Returned when an incoming response exceeds an internal WinHTTP size limit.
		_MakeErrorCodeName(ERROR_WINHTTP_SCRIPT_EXECUTION_ERROR),  //! An error was encountered while executing a script.
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_CERT_CN_INVALID),  //! Returned when a certificate CN name does not match the passed value (equivalent to a CERT_E_CN_NO_MATCH error).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_CERT_DATE_INVALID),  //! Indicates that a required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file, or that the validity periods of the certification chain do not nest correctly (equivalent to a CERT_E_EXPIRED or a CERT_E_VALIDITYPERIODNESTING error).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_CERT_REV_FAILED),  //! Indicates that revocation cannot be checked because the revocation server was offline (equivalent to CRYPT_E_REVOCATION_OFFLINE).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_CERT_REVOKED),  //! Indicates that a certificate has been revoked (equivalent to CRYPT_E_REVOKED).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE),  //! Indicates that a certificate is not valid for the requested usage (equivalent to CERT_E_WRONG_USAGE).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_CHANNEL_ERROR),  //! Indicates that an error occurred having to do with a secure channel (equivalent to error codes that begin with "SEC_E_" and "SEC_I_" listed in the "winerror.h" header file).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_FAILURE),  //! One or more errors were found in the Secure Sockets Layer (SSL) certificate sent by the server. To determine what type of error was encountered, check for a WINHTTP_CALLBACK_STATUS_SECURE_FAILURE notification in a status callback function. For more information, see WINHTTP_STATUS_CALLBACK.
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_INVALID_CA),  //! Indicates that a certificate chain was processed, but terminated in a root certificate that is not trusted by the trust provider (equivalent to CERT_E_UNTRUSTEDROOT).
		_MakeErrorCodeName(ERROR_WINHTTP_SECURE_INVALID_CERT),  //! Indicates that a certificate is invalid (equivalent to errors such as CERT_E_ROLE, CERT_E_PATHLENCONST, CERT_E_CRITICAL, CERT_E_PURPOSE, CERT_E_ISSUERCHAINING, CERT_E_MALFORMED and CERT_E_CHAINING).
		_MakeErrorCodeName(ERROR_WINHTTP_SHUTDOWN),  //! The WinHTTP function support is being shut down or unloaded.
		_MakeErrorCodeName(ERROR_WINHTTP_TIMEOUT),  //! The request has timed out.
		_MakeErrorCodeName(ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT),  //! The PAC file cannot be downloaded. For example, the server referenced by the PAC URL may not have been reachable, or the server returned a 404 NOT FOUND response.
		_MakeErrorCodeName(ERROR_WINHTTP_UNHANDLED_SCRIPT_TYPE),  //! The script type is not supported.
		_MakeErrorCodeName(ERROR_WINHTTP_UNRECOGNIZED_SCHEME),  //! The URL specified a scheme other than "http:" or "https:".
#pragma endregion

		_MakeErrorCodeName(ERROR_IPSEC_QM_POLICY_EXISTS),  //! The specified quick mode policy already exists.
		_MakeErrorCodeName(ERROR_IPSEC_QM_POLICY_NOT_FOUND),  //! The specified quick mode policy was not found.
		_MakeErrorCodeName(ERROR_IPSEC_QM_POLICY_IN_USE),  //! The specified quick mode policy is being used.
		_MakeErrorCodeName(ERROR_IPSEC_MM_POLICY_EXISTS),  //! The specified main mode policy already exists.
		_MakeErrorCodeName(ERROR_IPSEC_MM_POLICY_NOT_FOUND),  //! The specified main mode policy was not found.
		_MakeErrorCodeName(ERROR_IPSEC_MM_POLICY_IN_USE),  //! The specified main mode policy is being used.
		_MakeErrorCodeName(ERROR_IPSEC_MM_FILTER_EXISTS),  //! The specified main mode filter already exists.
		_MakeErrorCodeName(ERROR_IPSEC_MM_FILTER_NOT_FOUND),  //! The specified main mode filter was not found.
		_MakeErrorCodeName(ERROR_IPSEC_TRANSPORT_FILTER_EXISTS),  //! The specified transport mode filter already exists.
		_MakeErrorCodeName(ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND),  //! The specified transport mode filter does not exist.
		_MakeErrorCodeName(ERROR_IPSEC_MM_AUTH_EXISTS),  //! The specified main mode authentication list exists.
		_MakeErrorCodeName(ERROR_IPSEC_MM_AUTH_NOT_FOUND),  //! The specified main mode authentication list was not found.
		_MakeErrorCodeName(ERROR_IPSEC_MM_AUTH_IN_USE),  //! The specified main mode authentication list is being used.
		_MakeErrorCodeName(ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND),  //! The specified default main mode policy was not found.
		_MakeErrorCodeName(ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND),  //! The specified default main mode authentication list was not found.
		_MakeErrorCodeName(ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND),  //! The specified default quick mode policy was not found.
		_MakeErrorCodeName(ERROR_IPSEC_TUNNEL_FILTER_EXISTS),  //! The specified tunnel mode filter exists.
		_MakeErrorCodeName(ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND),  //! The specified tunnel mode filter was not found.
		_MakeErrorCodeName(ERROR_IPSEC_MM_FILTER_PENDING_DELETION),  //! The Main Mode filter is pending deletion.
		_MakeErrorCodeName(ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION),  //! The transport filter is pending deletion.
		_MakeErrorCodeName(ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION),  //! The tunnel filter is pending deletion.
		_MakeErrorCodeName(ERROR_IPSEC_MM_POLICY_PENDING_DELETION),  //! The Main Mode policy is pending deletion.
		_MakeErrorCodeName(ERROR_IPSEC_MM_AUTH_PENDING_DELETION),  //! The Main Mode authentication bundle is pending deletion.
		_MakeErrorCodeName(ERROR_IPSEC_QM_POLICY_PENDING_DELETION),  //! The Quick Mode policy is pending deletion.
		_MakeErrorCodeName(WARNING_IPSEC_MM_POLICY_PRUNED),  //! The Main Mode policy was successfully added, but some of the requested offers are not supported.
		_MakeErrorCodeName(WARNING_IPSEC_QM_POLICY_PRUNED),  //! The Quick Mode policy was successfully added, but some of the requested offers are not supported.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NEG_STATUS_BEGIN),  //! ERROR_IPSEC_IKE_NEG_STATUS_BEGIN
		_MakeErrorCodeName(ERROR_IPSEC_IKE_AUTH_FAIL),  //! IKE authentication credentials are unacceptable.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_ATTRIB_FAIL),  //! IKE security attributes are unacceptable.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NEGOTIATION_PENDING),  //! IKE Negotiation in progress.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR),  //! General processing error.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_TIMED_OUT),  //! Negotiation timed out.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NO_CERT),  //! IKE failed to find valid machine certificate. Contact your Network Security Administrator about installing a valid certificate in the appropriate Certificate Store.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SA_DELETED),  //! IKE SA deleted by peer before establishment completed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SA_REAPED),  //! IKE SA deleted before establishment completed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_MM_ACQUIRE_DROP),  //! Negotiation request sat in Queue too long.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_QM_ACQUIRE_DROP),  //! Negotiation request sat in Queue too long.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_QUEUE_DROP_MM),  //! Negotiation request sat in Queue too long.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM),  //! Negotiation request sat in Queue too long.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_DROP_NO_RESPONSE),  //! No response from peer.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_MM_DELAY_DROP),  //! Negotiation took too long.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_QM_DELAY_DROP),  //! Negotiation took too long.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_ERROR),  //! Unknown error occurred.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_CRL_FAILED),  //! Certificate Revocation Check failed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_KEY_USAGE),  //! Invalid certificate key usage.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_CERT_TYPE),  //! Invalid certificate type.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NO_PRIVATE_KEY),  //! IKE negotiation failed because the machine certificate used does not have a private key. IPsec certificates require a private key. Contact your Network Security administrator about replacing with a certificate that has a private key.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY),  //! Simultaneous rekeys were detected.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_DH_FAIL),  //! Failure in Diffie-Hellman computation.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED),  //! Don't know how to process critical payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_HEADER),  //! Invalid header.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NO_POLICY),  //! No policy configured.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_SIGNATURE),  //! Failed to verify signature.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_KERBEROS_ERROR),  //! Failed to authenticate using Kerberos.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NO_PUBLIC_KEY),  //! Peer's certificate did not have a public key.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR),  //! Error processing error payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_SA),  //! Error processing SA payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_PROP),  //! Error processing Proposal payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_TRANS),  //! Error processing Transform payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_KE),  //! Error processing KE payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_ID),  //! Error processing ID payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_CERT),  //! Error processing Cert payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ),  //! Error processing Certificate Request payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_HASH),  //! Error processing Hash payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_SIG),  //! Error processing Signature payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_NONCE),  //! Error processing Nonce payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY),  //! Error processing Notify payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_DELETE),  //! Error processing Delete Payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR),  //! Error processing VendorId payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_PAYLOAD),  //! Invalid payload received.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_LOAD_SOFT_SA),  //! Soft SA loaded.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN),  //! Soft SA torn down.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_COOKIE),  //! Invalid cookie received.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NO_PEER_CERT),  //! Peer failed to send valid machine certificate.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PEER_CRL_FAILED),  //! Certification Revocation check of peer's certificate failed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_POLICY_CHANGE),  //! New policy invalidated SAs formed with old policy.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NO_MM_POLICY),  //! There is no available Main Mode IKE policy.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NOTCBPRIV),  //! Failed to enabled TCB privilege.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SECLOADFAIL),  //! Failed to load SECURITY.DLL.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_FAILSSPINIT),  //! Failed to obtain security function table dispatch address from SSPI.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_FAILQUERYSSP),  //! Failed to query Kerberos package to obtain max token size.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SRVACQFAIL),  //! Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE service. Kerberos authentication will not function. The most likely reason for this is lack of domain membership. This is normal if your computer is a member of a workgroup.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SRVQUERYCRED),  //! Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service (QueryCredentialsAttributes).
		_MakeErrorCodeName(ERROR_IPSEC_IKE_GETSPIFAIL),  //! Failed to obtain new SPI for the inbound SA from IPsec driver. The most common cause for this is that the driver does not have the correct filter. Check your policy to verify the filters.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_FILTER),  //! Given filter is invalid.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_OUT_OF_MEMORY),  //! Memory allocation failed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED),  //! Failed to add Security Association to IPsec Driver. The most common cause for this is if the IKE negotiation took too long to complete. If the problem persists, reduce the load on the faulting machine.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_POLICY),  //! Invalid policy.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_UNKNOWN_DOI),  //! Invalid DOI.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_SITUATION),  //! Invalid situation.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_DH_FAILURE),  //! Diffie-Hellman failure.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_GROUP),  //! Invalid Diffie-Hellman group.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_ENCRYPT),  //! Error encrypting payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_DECRYPT),  //! Error decrypting payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_POLICY_MATCH),  //! Policy match error.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_UNSUPPORTED_ID),  //! Unsupported ID.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_HASH),  //! Hash verification failed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_HASH_ALG),  //! Invalid hash algorithm.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_HASH_SIZE),  //! Invalid hash size.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG),  //! Invalid encryption algorithm.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_AUTH_ALG),  //! Invalid authentication algorithm.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_SIG),  //! Invalid certificate signature.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_LOAD_FAILED),  //! Load failed.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_RPC_DELETE),  //! Deleted via RPC call.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_BENIGN_REINIT),  //! Temporary state created to perform reinitialization. This is not a real failure.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY),  //! The lifetime value received in the Responder Lifetime Notify is below the Windows 2000 configured minimum value. Please fix the policy on the peer machine.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION),  //! The recipient cannot handle version of IKE specified in the header.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN),  //! Key length in certificate is too small for configured security requirements.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_MM_LIMIT),  //! Max number of established MM SAs to peer exceeded.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NEGOTIATION_DISABLED),  //! IKE received a policy that disables negotiation.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_QM_LIMIT),  //! Reached maximum quick mode limit for the main mode. New main mode will be started.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_MM_EXPIRED),  //! Main mode SA lifetime expired or peer sent a main mode delete.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID),  //! Main mode SA assumed to be invalid because peer stopped responding.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH),  //! Certificate doesn't chain to a trusted root in IPsec policy.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID),  //! Received unexpected message ID.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD),  //! Received invalid authentication offers.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_DOS_COOKIE_SENT),  //! Sent DoS cookie notify to initiator.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_SHUTTING_DOWN),  //! IKE service is shutting down.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_CGA_AUTH_FAILED),  //! Could not verify binding between CGA address and certificate.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PROCESS_ERR_NATOA),  //! Error processing NatOA payload.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INVALID_MM_FOR_QM),  //! Parameters of the main mode are invalid for this quick mode.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_QM_EXPIRED),  //! Quick mode SA was expired by IPsec driver.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_TOO_MANY_FILTERS),  //! Too many dynamically added IKEEXT filters were detected.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NEG_STATUS_END),  //! ERROR_IPSEC_IKE_NEG_STATUS_END
		_MakeErrorCodeName(ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL),  //! NAP reauth succeeded and must delete the dummy NAP IKEv2 tunnel.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE),  //! Error in assigning inner IP address to initiator in tunnel mode.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING),  //! Require configuration payload missing.
		_MakeErrorCodeName(ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING),  //! A negotiation running as the security principle who issued the connection is in progress.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS),  //! SA was deleted due to IKEv1/AuthIP co-existence suppress check.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_RATELIMIT_DROP),  //! Incoming SA request was dropped due to peer IP address rate limiting.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE),  //! Peer does not support MOBIKE.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE),  //! SA establishment is not authorized.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE),  //! SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY),  //! SA establishment is not authorized. You may need to enter updated or different credentials such as a smartcard.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE),  //! SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential. This might be related to certificate-to-account mapping failure for the SA.
		_MakeErrorCodeName(ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END),  //! ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END
		_MakeErrorCodeName(ERROR_IPSEC_BAD_SPI),  //! The SPI in the packet does not match a valid IPsec SA.
		_MakeErrorCodeName(ERROR_IPSEC_SA_LIFETIME_EXPIRED),  //! Packet was received on an IPsec SA whose lifetime has expired.
		_MakeErrorCodeName(ERROR_IPSEC_WRONG_SA),  //! Packet was received on an IPsec SA that does not match the packet characteristics.
		_MakeErrorCodeName(ERROR_IPSEC_REPLAY_CHECK_FAILED),  //! Packet sequence number replay check failed.
		_MakeErrorCodeName(ERROR_IPSEC_INVALID_PACKET),  //! IPsec header and/or trailer in the packet is invalid.
		_MakeErrorCodeName(ERROR_IPSEC_INTEGRITY_CHECK_FAILED),  //! IPsec integrity check failed.
		_MakeErrorCodeName(ERROR_IPSEC_CLEAR_TEXT_DROP),  //! IPsec dropped a clear text packet.
		_MakeErrorCodeName(ERROR_IPSEC_AUTH_FIREWALL_DROP),  //! IPsec dropped an incoming ESP packet in authenticated firewall mode. This drop is benign.
		_MakeErrorCodeName(ERROR_IPSEC_THROTTLE_DROP),  //! IPsec dropped a packet due to DoS throttling.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_BLOCK),  //! IPsec DoS Protection matched an explicit block rule.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_RECEIVED_MULTICAST),  //! IPsec DoS Protection received an IPsec specific multicast packet which is not allowed.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_INVALID_PACKET),  //! IPsec DoS Protection received an incorrectly formatted packet.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED),  //! IPsec DoS Protection failed to look up state.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_MAX_ENTRIES),  //! IPsec DoS Protection failed to create state because the maximum number of entries allowed by policy has been reached.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED),  //! IPsec DoS Protection received an IPsec negotiation packet for a keying module which is not allowed by policy.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_NOT_INSTALLED),  //! IPsec DoS Protection has not been enabled.
		_MakeErrorCodeName(ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES),  //! IPsec DoS Protection failed to create a per internal IP rate limit queue because the maximum number of queues allowed by policy has been reached.
		_MakeErrorCodeName(ERROR_SXS_SECTION_NOT_FOUND),  //! The requested section was not present in the activation context.
		_MakeErrorCodeName(ERROR_SXS_CANT_GEN_ACTCTX),  //! The application has failed to start because its side-by-side configuration is incorrect. Please see the application event log or use the command-line sxstrace.exe tool for more detail.
		_MakeErrorCodeName(ERROR_SXS_INVALID_ACTCTXDATA_FORMAT),  //! The application binding data format is invalid.
		_MakeErrorCodeName(ERROR_SXS_ASSEMBLY_NOT_FOUND),  //! The referenced assembly is not installed on your system.
		_MakeErrorCodeName(ERROR_SXS_MANIFEST_FORMAT_ERROR),  //! The manifest file does not begin with the required tag and format information.
		_MakeErrorCodeName(ERROR_SXS_MANIFEST_PARSE_ERROR),  //! The manifest file contains one or more syntax errors.
		_MakeErrorCodeName(ERROR_SXS_ACTIVATION_CONTEXT_DISABLED),  //! The application attempted to activate a disabled activation context.
		_MakeErrorCodeName(ERROR_SXS_KEY_NOT_FOUND),  //! The requested lookup key was not found in any active activation context.
		_MakeErrorCodeName(ERROR_SXS_VERSION_CONFLICT),  //! A component version required by the application conflicts with another component version already active.
		_MakeErrorCodeName(ERROR_SXS_WRONG_SECTION_TYPE),  //! The type requested activation context section does not match the query API used.
		_MakeErrorCodeName(ERROR_SXS_THREAD_QUERIES_DISABLED),  //! Lack of system resources has required isolated activation to be disabled for the current thread of execution.
		_MakeErrorCodeName(ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET),  //! An attempt to set the process default activation context failed because the process default activation context was already set.
		_MakeErrorCodeName(ERROR_SXS_UNKNOWN_ENCODING_GROUP),  //! The encoding group identifier specified is not recognized.
		_MakeErrorCodeName(ERROR_SXS_UNKNOWN_ENCODING),  //! The encoding requested is not recognized.
		_MakeErrorCodeName(ERROR_SXS_INVALID_XML_NAMESPACE_URI),  //! The manifest contains a reference to an invalid URI.
		_MakeErrorCodeName(ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED),  //! The application manifest contains a reference to a dependent assembly which is not installed.
		_MakeErrorCodeName(ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED),  //! The manifest for an assembly used by the application has a reference to a dependent assembly which is not installed.
		_MakeErrorCodeName(ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE),  //! The manifest contains an attribute for the assembly identity which is not valid.
		_MakeErrorCodeName(ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE),  //! The manifest is missing the required default namespace specification on the assembly element.
		_MakeErrorCodeName(ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE),  //! The manifest has a default namespace specified on the assembly element but its value is not "urn:schemas-microsoft-com:asm.v1".
		_MakeErrorCodeName(ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT),  //! The private manifest probed has crossed a path with an unsupported reparse point.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_DLL_NAME),  //! Two or more components referenced directly or indirectly by the application manifest have files by the same name.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME),  //! Two or more components referenced directly or indirectly by the application manifest have window classes with the same name.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_CLSID),  //! Two or more components referenced directly or indirectly by the application manifest have the same COM server CLSIDs.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_IID),  //! Two or more components referenced directly or indirectly by the application manifest have proxies for the same COM interface IIDs.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_TLBID),  //! Two or more components referenced directly or indirectly by the application manifest have the same COM type library TLBIDs.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_PROGID),  //! Two or more components referenced directly or indirectly by the application manifest have the same COM ProgIDs.
		_MakeErrorCodeName(ERROR_SXS_DUPLICATE_ASSEMBLY_NAME),  //! Two or more components referenced directly or indirectly by the application manifest are different versions of the same component which is not permitted.
		_MakeErrorCodeName(ERROR_SXS_FILE_HASH_MISMATCH),  //! A component's file does not match the verification information present in the component manifest.
		_MakeErrorCodeName(ERROR_SXS_POLICY_PARSE_ERROR),  //! The policy manifest contains one or more syntax errors.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MISSINGQUOTE),  //! Manifest Parse Error : A string literal was expected, but no opening quote character was found.
		_MakeErrorCodeName(ERROR_SXS_XML_E_COMMENTSYNTAX),  //! Manifest Parse Error : Incorrect syntax was used in a comment.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADSTARTNAMECHAR),  //! Manifest Parse Error : A name was started with an invalid character.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADNAMECHAR),  //! Manifest Parse Error : A name contained an invalid character.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADCHARINSTRING),  //! Manifest Parse Error : A string literal contained an invalid character.
		_MakeErrorCodeName(ERROR_SXS_XML_E_XMLDECLSYNTAX),  //! Manifest Parse Error : Invalid syntax for an xml declaration.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADCHARDATA),  //! Manifest Parse Error : An Invalid character was found in text content.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MISSINGWHITESPACE),  //! Manifest Parse Error : Required white space was missing.
		_MakeErrorCodeName(ERROR_SXS_XML_E_EXPECTINGTAGEND),  //! Manifest Parse Error : The character '>' was expected.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MISSINGSEMICOLON),  //! Manifest Parse Error : A semi colon character was expected.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNBALANCEDPAREN),  //! Manifest Parse Error : Unbalanced parentheses.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INTERNALERROR),  //! Manifest Parse Error : Internal error.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE),  //! Manifest Parse Error : Whitespace is not allowed at this location.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INCOMPLETE_ENCODING),  //! Manifest Parse Error : End of file reached in invalid state for current encoding.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MISSING_PAREN),  //! Manifest Parse Error : Missing parenthesis.
		_MakeErrorCodeName(ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE),  //! Manifest Parse Error : A single or double closing quote character (\' or \") is missing.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MULTIPLE_COLONS),  //! Manifest Parse Error : Multiple colons are not allowed in a name.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALID_DECIMAL),  //! Manifest Parse Error : Invalid character for decimal digit.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALID_HEXIDECIMAL),  //! Manifest Parse Error : Invalid character for hexadecimal digit.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALID_UNICODE),  //! Manifest Parse Error : Invalid unicode character value for this platform.
		_MakeErrorCodeName(ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK),  //! Manifest Parse Error : Expecting whitespace or '?'.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNEXPECTEDENDTAG),  //! Manifest Parse Error : End tag was not expected at this location.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDTAG),  //! Manifest Parse Error : The following tags were not closed: %1.
		_MakeErrorCodeName(ERROR_SXS_XML_E_DUPLICATEATTRIBUTE),  //! Manifest Parse Error : Duplicate attribute.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MULTIPLEROOTS),  //! Manifest Parse Error : Only one top level element is allowed in an XML document.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALIDATROOTLEVEL),  //! Manifest Parse Error : Invalid at the top level of the document.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADXMLDECL),  //! Manifest Parse Error : Invalid xml declaration.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MISSINGROOT),  //! Manifest Parse Error : XML document must have a top level element.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNEXPECTEDEOF),  //! Manifest Parse Error : Unexpected end of file.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADPEREFINSUBSET),  //! Manifest Parse Error : Parameter entities cannot be used inside markup declarations in an internal subset.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDSTARTTAG),  //! Manifest Parse Error : Element was not closed.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDENDTAG),  //! Manifest Parse Error : End element was missing the character '>'.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDSTRING),  //! Manifest Parse Error : A string literal was not closed.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDCOMMENT),  //! Manifest Parse Error : A comment was not closed.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDDECL),  //! Manifest Parse Error : A declaration was not closed.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNCLOSEDCDATA),  //! Manifest Parse Error : A CDATA section was not closed.
		_MakeErrorCodeName(ERROR_SXS_XML_E_RESERVEDNAMESPACE),  //! Manifest Parse Error : The namespace prefix is not allowed to start with the reserved string "xml".
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALIDENCODING),  //! Manifest Parse Error : System does not support the specified encoding.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALIDSWITCH),  //! Manifest Parse Error : Switch from current encoding to specified encoding not supported.
		_MakeErrorCodeName(ERROR_SXS_XML_E_BADXMLCASE),  //! Manifest Parse Error : The name 'xml' is reserved and must be lower case.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALID_STANDALONE),  //! Manifest Parse Error : The standalone attribute must have the value 'yes' or 'no'.
		_MakeErrorCodeName(ERROR_SXS_XML_E_UNEXPECTED_STANDALONE),  //! Manifest Parse Error : The standalone attribute cannot be used in external entities.
		_MakeErrorCodeName(ERROR_SXS_XML_E_INVALID_VERSION),  //! Manifest Parse Error : Invalid version number.
		_MakeErrorCodeName(ERROR_SXS_XML_E_MISSINGEQUALS),  //! Manifest Parse Error : Missing equals sign between attribute and attribute value.
		_MakeErrorCodeName(ERROR_SXS_PROTECTION_RECOVERY_FAILED),  //! Assembly Protection Error : Unable to recover the specified assembly.
		_MakeErrorCodeName(ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT),  //! Assembly Protection Error : The public key for an assembly was too short to be allowed.
		_MakeErrorCodeName(ERROR_SXS_PROTECTION_CATALOG_NOT_VALID),  //! Assembly Protection Error : The catalog for an assembly is not valid, or does not match the assembly's manifest.
		_MakeErrorCodeName(ERROR_SXS_UNTRANSLATABLE_HRESULT),  //! An HRESULT could not be translated to a corresponding Win32 error code.
		_MakeErrorCodeName(ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING),  //! Assembly Protection Error : The catalog for an assembly is missing.
		_MakeErrorCodeName(ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE),  //! The supplied assembly identity is missing one or more attributes which must be present in this context.
		_MakeErrorCodeName(ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME),  //! The supplied assembly identity has one or more attribute names that contain characters not permitted in XML names.
		_MakeErrorCodeName(ERROR_SXS_ASSEMBLY_MISSING),  //! The referenced assembly could not be found.
		_MakeErrorCodeName(ERROR_SXS_CORRUPT_ACTIVATION_STACK),  //! The activation context activation stack for the running thread of execution is corrupt.
		_MakeErrorCodeName(ERROR_SXS_CORRUPTION),  //! The application isolation metadata for this process or thread has become corrupt.
		_MakeErrorCodeName(ERROR_SXS_EARLY_DEACTIVATION),  //! The activation context being deactivated is not the most recently activated one.
		_MakeErrorCodeName(ERROR_SXS_INVALID_DEACTIVATION),  //! The activation context being deactivated is not active for the current thread of execution.
		_MakeErrorCodeName(ERROR_SXS_MULTIPLE_DEACTIVATION),  //! The activation context being deactivated has already been deactivated.
		_MakeErrorCodeName(ERROR_SXS_PROCESS_TERMINATION_REQUESTED),  //! A component used by the isolation facility has requested to terminate the process.
		_MakeErrorCodeName(ERROR_SXS_RELEASE_ACTIVATION_CONTEXT),  //! A kernel mode component is releasing a reference on an activation context.
		_MakeErrorCodeName(ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY),  //! The activation context of system default assembly could not be generated.
		_MakeErrorCodeName(ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE),  //! The value of an attribute in an identity is not within the legal range.
		_MakeErrorCodeName(ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME),  //! The name of an attribute in an identity is not within the legal range.
		_MakeErrorCodeName(ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE),  //! An identity contains two definitions for the same attribute.
		_MakeErrorCodeName(ERROR_SXS_IDENTITY_PARSE_ERROR),  //! The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.
		_MakeErrorCodeName(ERROR_MALFORMED_SUBSTITUTION_STRING),  //! A string containing localized substitutable content was malformed. Either a dollar sign ($) was followed by something other than a left parenthesis or another dollar sign or an substitution's right parenthesis was not found.
		_MakeErrorCodeName(ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN),  //! The public key token does not correspond to the public key specified.
		_MakeErrorCodeName(ERROR_UNMAPPED_SUBSTITUTION_STRING),  //! A substitution string had no mapping.
		_MakeErrorCodeName(ERROR_SXS_ASSEMBLY_NOT_LOCKED),  //! The component must be locked before making the request.
		_MakeErrorCodeName(ERROR_SXS_COMPONENT_STORE_CORRUPT),  //! The component store has been corrupted.
		_MakeErrorCodeName(ERROR_ADVANCED_INSTALLER_FAILED),  //! An advanced installer failed during setup or servicing.
		_MakeErrorCodeName(ERROR_XML_ENCODING_MISMATCH),  //! The character encoding in the XML declaration did not match the encoding used in the document.
		_MakeErrorCodeName(ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT),  //! The identities of the manifests are identical but their contents are different.
		_MakeErrorCodeName(ERROR_SXS_IDENTITIES_DIFFERENT),  //! The component identities are different.
		_MakeErrorCodeName(ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT),  //! The assembly is not a deployment.
		_MakeErrorCodeName(ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY),  //! The file is not a part of the assembly.
		_MakeErrorCodeName(ERROR_SXS_MANIFEST_TOO_BIG),  //! The size of the manifest exceeds the maximum allowed.
		_MakeErrorCodeName(ERROR_SXS_SETTING_NOT_REGISTERED),  //! The setting is not registered.
		_MakeErrorCodeName(ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE),  //! One or more required members of the transaction are not present.
		_MakeErrorCodeName(ERROR_SMI_PRIMITIVE_INSTALLER_FAILED),  //! The SMI primitive installer failed during setup or servicing.
		_MakeErrorCodeName(ERROR_GENERIC_COMMAND_FAILED),  //! A generic command executable returned a result that indicates failure.
		_MakeErrorCodeName(ERROR_SXS_FILE_HASH_MISSING),  //! A component is missing file verification information in its manifest.
		_MakeErrorCodeName(ERROR_EVT_INVALID_CHANNEL_PATH),  //! The specified channel path is invalid.
		_MakeErrorCodeName(ERROR_EVT_INVALID_QUERY),  //! The specified query is invalid.
		_MakeErrorCodeName(ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND),  //! The publisher metadata cannot be found in the resource.
		_MakeErrorCodeName(ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND),  //! The template for an event definition cannot be found in the resource (error = %1).
		_MakeErrorCodeName(ERROR_EVT_INVALID_PUBLISHER_NAME),  //! The specified publisher name is invalid.
		_MakeErrorCodeName(ERROR_EVT_INVALID_EVENT_DATA),  //! The event data raised by the publisher is not compatible with the event template definition in the publisher's manifest.
		_MakeErrorCodeName(ERROR_EVT_CHANNEL_NOT_FOUND),  //! The specified channel could not be found. Check channel configuration.
		_MakeErrorCodeName(ERROR_EVT_MALFORMED_XML_TEXT),  //! The specified xml text was not well-formed. See Extended Error for more details.
		_MakeErrorCodeName(ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL),  //! The caller is trying to subscribe to a direct channel which is not allowed. The events for a direct channel go directly to a logfile and cannot be subscribed to.
		_MakeErrorCodeName(ERROR_EVT_CONFIGURATION_ERROR),  //! Configuration error.
		_MakeErrorCodeName(ERROR_EVT_QUERY_RESULT_STALE),  //! The query result is stale / invalid. This may be due to the log being cleared or rolling over after the query result was created. Users should handle this code by releasing the query result object and reissuing the query.
		_MakeErrorCodeName(ERROR_EVT_QUERY_RESULT_INVALID_POSITION),  //! Query result is currently at an invalid position.
		_MakeErrorCodeName(ERROR_EVT_NON_VALIDATING_MSXML),  //! Registered MSXML doesn't support validation.
		_MakeErrorCodeName(ERROR_EVT_FILTER_ALREADYSCOPED),  //! An expression can only be followed by a change of scope operation if it itself evaluates to a node set and is not already part of some other change of scope operation.
		_MakeErrorCodeName(ERROR_EVT_FILTER_NOTELTSET),  //! Can't perform a step operation from a term that does not represent an element set.
		_MakeErrorCodeName(ERROR_EVT_FILTER_INVARG),  //! Left hand side arguments to binary operators must be either attributes, nodes or variables and right hand side arguments must be constants.
		_MakeErrorCodeName(ERROR_EVT_FILTER_INVTEST),  //! A step operation must involve either a node test or, in the case of a predicate, an algebraic expression against which to test each node in the node set identified by the preceding node set can be evaluated.
		_MakeErrorCodeName(ERROR_EVT_FILTER_INVTYPE),  //! This data type is currently unsupported.
		_MakeErrorCodeName(ERROR_EVT_FILTER_PARSEERR),  //! A syntax error occurred at position %1!d!.
		_MakeErrorCodeName(ERROR_EVT_FILTER_UNSUPPORTEDOP),  //! This operator is unsupported by this implementation of the filter.
		_MakeErrorCodeName(ERROR_EVT_FILTER_UNEXPECTEDTOKEN),  //! The token encountered was unexpected.
		_MakeErrorCodeName(ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL),  //! The requested operation cannot be performed over an enabled direct channel. The channel must first be disabled before performing the requested operation.
		_MakeErrorCodeName(ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE),  //! Channel property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of channel.
		_MakeErrorCodeName(ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE),  //! Publisher property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of publisher.
		_MakeErrorCodeName(ERROR_EVT_CHANNEL_CANNOT_ACTIVATE),  //! The channel fails to activate.
		_MakeErrorCodeName(ERROR_EVT_FILTER_TOO_COMPLEX),  //! The xpath expression exceeded supported complexity. Please symplify it or split it into two or more simple expressions.
		_MakeErrorCodeName(ERROR_EVT_MESSAGE_NOT_FOUND),  //! the message resource is present but the message is not found in the string/message table.
		_MakeErrorCodeName(ERROR_EVT_MESSAGE_ID_NOT_FOUND),  //! The message id for the desired message could not be found.
		_MakeErrorCodeName(ERROR_EVT_UNRESOLVED_VALUE_INSERT),  //! The substitution string for insert index (%1) could not be found.
		_MakeErrorCodeName(ERROR_EVT_UNRESOLVED_PARAMETER_INSERT),  //! The description string for parameter reference (%1) could not be found.
		_MakeErrorCodeName(ERROR_EVT_MAX_INSERTS_REACHED),  //! The maximum number of replacements has been reached.
		_MakeErrorCodeName(ERROR_EVT_EVENT_DEFINITION_NOT_FOUND),  //! The event definition could not be found for event id (%1).
		_MakeErrorCodeName(ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND),  //! The locale specific resource for the desired message is not present.
		_MakeErrorCodeName(ERROR_EVT_VERSION_TOO_OLD),  //! The resource is too old to be compatible.
		_MakeErrorCodeName(ERROR_EVT_VERSION_TOO_NEW),  //! The resource is too new to be compatible.
		_MakeErrorCodeName(ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY),  //! The channel at index %1!d! of the query can't be opened.
		_MakeErrorCodeName(ERROR_EVT_PUBLISHER_DISABLED),  //! The publisher has been disabled and its resource is not available. This usually occurs when the publisher is in the process of being uninstalled or upgraded.
		_MakeErrorCodeName(ERROR_EVT_FILTER_OUT_OF_RANGE),  //! Attempted to create a numeric type that is outside of its valid range.
		_MakeErrorCodeName(ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE),  //! The subscription fails to activate.
		_MakeErrorCodeName(ERROR_EC_LOG_DISABLED),  //! The log of the subscription is in disabled state, and cannot be used to forward events to. The log must first be enabled before the subscription can be activated.
		_MakeErrorCodeName(ERROR_EC_CIRCULAR_FORWARDING),  //! When forwarding events from local machine to itself, the query of the subscription can't contain target log of the subscription.
		_MakeErrorCodeName(ERROR_EC_CREDSTORE_FULL),  //! The credential store that is used to save credentials is full.
		_MakeErrorCodeName(ERROR_EC_CRED_NOT_FOUND),  //! The credential used by this subscription can't be found in credential store.
		_MakeErrorCodeName(ERROR_EC_NO_ACTIVE_CHANNEL),  //! No active channel is found for the query.
		_MakeErrorCodeName(ERROR_MUI_FILE_NOT_FOUND),  //! The resource loader failed to find MUI file.
		_MakeErrorCodeName(ERROR_MUI_INVALID_FILE),  //! The resource loader failed to load MUI file because the file fail to pass validation.
		_MakeErrorCodeName(ERROR_MUI_INVALID_RC_CONFIG),  //! The RC Manifest is corrupted with garbage data or unsupported version or missing required item.
		_MakeErrorCodeName(ERROR_MUI_INVALID_LOCALE_NAME),  //! The RC Manifest has invalid culture name.
		_MakeErrorCodeName(ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME),  //! The RC Manifest has invalid ultimatefallback name.
		_MakeErrorCodeName(ERROR_MUI_FILE_NOT_LOADED),  //! The resource loader cache doesn't have loaded MUI entry.
		_MakeErrorCodeName(ERROR_RESOURCE_ENUM_USER_STOP),  //! User stopped resource enumeration.
		_MakeErrorCodeName(ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED),  //! UI language installation failed.
		_MakeErrorCodeName(ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME),  //! Locale installation failed.
		_MakeErrorCodeName(ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE),  //! A resource does not have default or neutral value.
		_MakeErrorCodeName(ERROR_MRM_INVALID_PRICONFIG),  //! Invalid PRI config file.
		_MakeErrorCodeName(ERROR_MRM_INVALID_FILE_TYPE),  //! Invalid file type.
		_MakeErrorCodeName(ERROR_MRM_UNKNOWN_QUALIFIER),  //! Unknown qualifier.
		_MakeErrorCodeName(ERROR_MRM_INVALID_QUALIFIER_VALUE),  //! Invalid qualifier value.
		_MakeErrorCodeName(ERROR_MRM_NO_CANDIDATE),  //! No Candidate found.
		_MakeErrorCodeName(ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE),  //! The ResourceMap or NamedResource has an item that does not have default or neutral resource..
		_MakeErrorCodeName(ERROR_MRM_RESOURCE_TYPE_MISMATCH),  //! Invalid ResourceCandidate type.
		_MakeErrorCodeName(ERROR_MRM_DUPLICATE_MAP_NAME),  //! Duplicate Resource Map.
		_MakeErrorCodeName(ERROR_MRM_DUPLICATE_ENTRY),  //! Duplicate Entry.
		_MakeErrorCodeName(ERROR_MRM_INVALID_RESOURCE_IDENTIFIER),  //! Invalid Resource Identifier.
		_MakeErrorCodeName(ERROR_MRM_FILEPATH_TOO_LONG),  //! Filepath too long.
		_MakeErrorCodeName(ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE),  //! Unsupported directory type.
		_MakeErrorCodeName(ERROR_MRM_INVALID_PRI_FILE),  //! Invalid PRI File.
		_MakeErrorCodeName(ERROR_MRM_NAMED_RESOURCE_NOT_FOUND),  //! NamedResource Not Found.
		_MakeErrorCodeName(ERROR_MRM_MAP_NOT_FOUND),  //! ResourceMap Not Found.
		_MakeErrorCodeName(ERROR_MRM_UNSUPPORTED_PROFILE_TYPE),  //! Unsupported MRT profile type.
		_MakeErrorCodeName(ERROR_MRM_INVALID_QUALIFIER_OPERATOR),  //! Invalid qualifier operator.
		_MakeErrorCodeName(ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE),  //! Unable to determine qualifier value or qualifier value has not been set.
		_MakeErrorCodeName(ERROR_MRM_AUTOMERGE_ENABLED),  //! Automerge is enabled in the PRI file.
		_MakeErrorCodeName(ERROR_MRM_TOO_MANY_RESOURCES),  //! Too many resources defined for package.
		_MakeErrorCodeName(ERROR_MCA_INVALID_CAPABILITIES_STRING),  //! The monitor returned a DDC/CI capabilities string that did not comply with the ACCESS.bus 3.0, DDC/CI 1.1 or MCCS 2 Revision 1 specification.
		_MakeErrorCodeName(ERROR_MCA_INVALID_VCP_VERSION),  //! The monitor's VCP Version (0xDF) VCP code returned an invalid version value.
		_MakeErrorCodeName(ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION),  //! The monitor does not comply with the MCCS specification it claims to support.
		_MakeErrorCodeName(ERROR_MCA_MCCS_VERSION_MISMATCH),  //! The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.
		_MakeErrorCodeName(ERROR_MCA_UNSUPPORTED_MCCS_VERSION),  //! The Monitor Configuration API only works with monitors that support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.
		_MakeErrorCodeName(ERROR_MCA_INTERNAL_ERROR),  //! An internal Monitor Configuration API error occurred.
		_MakeErrorCodeName(ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED),  //! The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
		_MakeErrorCodeName(ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE),  //! The caller of SetMonitorColorTemperature specified a color temperature that the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
		_MakeErrorCodeName(ERROR_AMBIGUOUS_SYSTEM_DEVICE),  //! The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria.
		_MakeErrorCodeName(ERROR_SYSTEM_DEVICE_NOT_FOUND),  //! The requested system device cannot be found.
		_MakeErrorCodeName(ERROR_HASH_NOT_SUPPORTED),  //! Hash generation for the specified hash version and hash type is not enabled on the server.
		_MakeErrorCodeName(ERROR_HASH_NOT_PRESENT),  //! The hash requested from the server is not available or no longer valid.
		_MakeErrorCodeName(ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED),  //! The secondary interrupt controller instance that manages the specified interrupt is not registered.
		_MakeErrorCodeName(ERROR_GPIO_CLIENT_INFORMATION_INVALID),  //! The information supplied by the GPIO client driver is invalid.
		_MakeErrorCodeName(ERROR_GPIO_VERSION_NOT_SUPPORTED),  //! The version specified by the GPIO client driver is not supported.
		_MakeErrorCodeName(ERROR_GPIO_INVALID_REGISTRATION_PACKET),  //! The registration packet supplied by the GPIO client driver is not valid.
		_MakeErrorCodeName(ERROR_GPIO_OPERATION_DENIED),  //! The requested operation is not supported for the specified handle.
		_MakeErrorCodeName(ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE),  //! The requested connect mode conflicts with an existing mode on one or more of the specified pins.
		_MakeErrorCodeName(ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED),  //! The interrupt requested to be unmasked is not masked.
		_MakeErrorCodeName(ERROR_CANNOT_SWITCH_RUNLEVEL),  //! The requested run level switch cannot be completed successfully.
		_MakeErrorCodeName(ERROR_INVALID_RUNLEVEL_SETTING),  //! The service has an invalid run level setting. The run level for a service must not be higher than the run level of its dependent services.
		_MakeErrorCodeName(ERROR_RUNLEVEL_SWITCH_TIMEOUT),  //! The requested run level switch cannot be completed successfully since one or more services will not stop or restart within the specified timeout.
		_MakeErrorCodeName(ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT),  //! A run level switch agent did not respond within the specified timeout.
		_MakeErrorCodeName(ERROR_RUNLEVEL_SWITCH_IN_PROGRESS),  //! A run level switch is currently in progress.
		_MakeErrorCodeName(ERROR_SERVICES_FAILED_AUTOSTART),  //! One or more services failed to start during the service startup phase of a run level switch.
		_MakeErrorCodeName(ERROR_COM_TASK_STOP_PENDING),  //! The task stop request cannot be completed immediately since task needs more time to shutdown.
		_MakeErrorCodeName(ERROR_INSTALL_OPEN_PACKAGE_FAILED),  //! Package could not be opened.
		_MakeErrorCodeName(ERROR_INSTALL_PACKAGE_NOT_FOUND),  //! Package was not found.
		_MakeErrorCodeName(ERROR_INSTALL_INVALID_PACKAGE),  //! Package data is invalid.
		_MakeErrorCodeName(ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED),  //! Package failed updates, dependency or conflict validation.
		_MakeErrorCodeName(ERROR_INSTALL_OUT_OF_DISK_SPACE),  //! There is not enough disk space on your computer. Please free up some space and try again.
		_MakeErrorCodeName(ERROR_INSTALL_NETWORK_FAILURE),  //! There was a problem downloading your product.
		_MakeErrorCodeName(ERROR_INSTALL_REGISTRATION_FAILURE),  //! Package could not be registered.
		_MakeErrorCodeName(ERROR_INSTALL_DEREGISTRATION_FAILURE),  //! Package could not be unregistered.
		_MakeErrorCodeName(ERROR_INSTALL_CANCEL),  //! User cancelled the install request.
		_MakeErrorCodeName(ERROR_INSTALL_FAILED),  //! Install failed. Please contact your software vendor.
		_MakeErrorCodeName(ERROR_REMOVE_FAILED),  //! Removal failed. Please contact your software vendor.
		_MakeErrorCodeName(ERROR_PACKAGE_ALREADY_EXISTS),  //! The provided package is already installed, and reinstallation of the package was blocked. Check the AppXDeployment-Server event log for details.
		_MakeErrorCodeName(ERROR_NEEDS_REMEDIATION),  //! The application cannot be started. Try reinstalling the application to fix the problem.
		_MakeErrorCodeName(ERROR_INSTALL_PREREQUISITE_FAILED),  //! A Prerequisite for an install could not be satisfied.
		_MakeErrorCodeName(ERROR_PACKAGE_REPOSITORY_CORRUPTED),  //! The package repository is corrupted.
		_MakeErrorCodeName(ERROR_INSTALL_POLICY_FAILURE),  //! To install this application you need either a Windows developer license or a sideloading-enabled system.
		_MakeErrorCodeName(ERROR_PACKAGE_UPDATING),  //! The application cannot be started because it is currently updating.
		_MakeErrorCodeName(ERROR_DEPLOYMENT_BLOCKED_BY_POLICY),  //! The package deployment operation is blocked by policy. Please contact your system administrator.
		_MakeErrorCodeName(ERROR_PACKAGES_IN_USE),  //! The package could not be installed because resources it modifies are currently in use.
		_MakeErrorCodeName(ERROR_RECOVERY_FILE_CORRUPT),  //! The package could not be recovered because necessary data for recovery have been corrupted.
		_MakeErrorCodeName(ERROR_INVALID_STAGED_SIGNATURE),  //! The signature is invalid. To register in developer mode, AppxSignature.p7x and AppxBlockMap.xml must be valid or should not be present.
		_MakeErrorCodeName(ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED),  //! An error occurred while deleting the package's previously existing application data.
		_MakeErrorCodeName(ERROR_INSTALL_PACKAGE_DOWNGRADE),  //! The package could not be installed because a higher version of this package is already installed.
		_MakeErrorCodeName(ERROR_SYSTEM_NEEDS_REMEDIATION),  //! An error in a system binary was detected. Try refreshing the PC to fix the problem.
		_MakeErrorCodeName(ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN),  //! A corrupted CLR NGEN binary was detected on the system.
		_MakeErrorCodeName(ERROR_RESILIENCY_FILE_CORRUPT),  //! The operation could not be resumed because necessary data for recovery have been corrupted.
		_MakeErrorCodeName(ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING),  //! The package could not be installed because the Windows Firewall service is not running. Enable the Windows Firewall service and try again.
		_MakeErrorCodeName(APPMODEL_ERROR_NO_PACKAGE),  //! The process has no package identity.
		_MakeErrorCodeName(APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT),  //! The package runtime information is corrupted.
		_MakeErrorCodeName(APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT),  //! The package identity is corrupted.
		_MakeErrorCodeName(APPMODEL_ERROR_NO_APPLICATION),  //! The process has no application identity.
		_MakeErrorCodeName(ERROR_STATE_LOAD_STORE_FAILED),  //! Loading the state store failed.
		_MakeErrorCodeName(ERROR_STATE_GET_VERSION_FAILED),  //! Retrieving the state version for the application failed.
		_MakeErrorCodeName(ERROR_STATE_SET_VERSION_FAILED),  //! Setting the state version for the application failed.
		_MakeErrorCodeName(ERROR_STATE_STRUCTURED_RESET_FAILED),  //! Resetting the structured state of the application failed.
		_MakeErrorCodeName(ERROR_STATE_OPEN_CONTAINER_FAILED),  //! State Manager failed to open the container.
		_MakeErrorCodeName(ERROR_STATE_CREATE_CONTAINER_FAILED),  //! State Manager failed to create the container.
		_MakeErrorCodeName(ERROR_STATE_DELETE_CONTAINER_FAILED),  //! State Manager failed to delete the container.
		_MakeErrorCodeName(ERROR_STATE_READ_SETTING_FAILED),  //! State Manager failed to read the setting.
		_MakeErrorCodeName(ERROR_STATE_WRITE_SETTING_FAILED),  //! State Manager failed to write the setting.
		_MakeErrorCodeName(ERROR_STATE_DELETE_SETTING_FAILED),  //! State Manager failed to delete the setting.
		_MakeErrorCodeName(ERROR_STATE_QUERY_SETTING_FAILED),  //! State Manager failed to query the setting.
		_MakeErrorCodeName(ERROR_STATE_READ_COMPOSITE_SETTING_FAILED),  //! State Manager failed to read the composite setting.
		_MakeErrorCodeName(ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED),  //! State Manager failed to write the composite setting.
		_MakeErrorCodeName(ERROR_STATE_ENUMERATE_CONTAINER_FAILED),  //! State Manager failed to enumerate the containers.
		_MakeErrorCodeName(ERROR_STATE_ENUMERATE_SETTINGS_FAILED),  //! State Manager failed to enumerate the settings.
		_MakeErrorCodeName(ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED),  //! The size of the state manager composite setting value has exceeded the limit.
		_MakeErrorCodeName(ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED),  //! The size of the state manager setting value has exceeded the limit.
		_MakeErrorCodeName(ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED),  //! The length of the state manager setting name has exceeded the limit.
		_MakeErrorCodeName(ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED),  //! The length of the state manager container name has exceeded the limit.
#pragma endregion
		_MakeErrorCodeName(ERROR_API_UNAVAILABLE),  //! This API cannot be used in the context of the caller's application type.

#undef _MakeErrorCodeName
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o