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
		ErrorCodeName{"ERROR_SUCCESS", ERROR_SUCCESS},  //! The operation completed successfully.
#pragma region Error code definitions
		ErrorCodeName{"ERROR_INVALID_FUNCTION", ERROR_INVALID_FUNCTION},  //! Incorrect function.
		ErrorCodeName{"ERROR_FILE_NOT_FOUND", ERROR_FILE_NOT_FOUND},  //! The system cannot find the file specified.
		ErrorCodeName{"ERROR_PATH_NOT_FOUND", ERROR_PATH_NOT_FOUND},  //! The system cannot find the path specified.
		ErrorCodeName{"ERROR_TOO_MANY_OPEN_FILES", ERROR_TOO_MANY_OPEN_FILES},  //! The system cannot open the file.
		ErrorCodeName{"ERROR_ACCESS_DENIED", ERROR_ACCESS_DENIED},  //! Access is denied.
		ErrorCodeName{"ERROR_INVALID_HANDLE", ERROR_INVALID_HANDLE},  //! The handle is invalid.
		ErrorCodeName{"ERROR_ARENA_TRASHED", ERROR_ARENA_TRASHED},  //! The storage control blocks were destroyed.
		ErrorCodeName{"ERROR_NOT_ENOUGH_MEMORY", ERROR_NOT_ENOUGH_MEMORY},  //! Not enough memory resources are available to process this command.
		ErrorCodeName{"ERROR_INVALID_BLOCK", ERROR_INVALID_BLOCK},  //! The storage control block address is invalid.
		ErrorCodeName{"ERROR_BAD_ENVIRONMENT", ERROR_BAD_ENVIRONMENT},  //! The environment is incorrect.
		ErrorCodeName{"ERROR_BAD_FORMAT", ERROR_BAD_FORMAT},  //! An attempt was made to load a program with an incorrect format.
		ErrorCodeName{"ERROR_INVALID_ACCESS", ERROR_INVALID_ACCESS},  //! The access code is invalid.
		ErrorCodeName{"ERROR_INVALID_DATA", ERROR_INVALID_DATA},  //! The data is invalid.
		ErrorCodeName{"ERROR_OUTOFMEMORY", ERROR_OUTOFMEMORY},  //! Not enough storage is available to complete this operation.
		ErrorCodeName{"ERROR_INVALID_DRIVE", ERROR_INVALID_DRIVE},  //! The system cannot find the drive specified.
		ErrorCodeName{"ERROR_CURRENT_DIRECTORY", ERROR_CURRENT_DIRECTORY},  //! The directory cannot be removed.
		ErrorCodeName{"ERROR_NOT_SAME_DEVICE", ERROR_NOT_SAME_DEVICE},  //! The system cannot move the file to a different disk drive.
		ErrorCodeName{"ERROR_NO_MORE_FILES", ERROR_NO_MORE_FILES},  //! There are no more files.
		ErrorCodeName{"ERROR_WRITE_PROTECT", ERROR_WRITE_PROTECT},  //! The media is write protected.
		ErrorCodeName{"ERROR_BAD_UNIT", ERROR_BAD_UNIT},  //! The system cannot find the device specified.
		ErrorCodeName{"ERROR_NOT_READY", ERROR_NOT_READY},  //! The device is not ready.
		ErrorCodeName{"ERROR_BAD_COMMAND", ERROR_BAD_COMMAND},  //! The device does not recognize the command.
		ErrorCodeName{"ERROR_CRC", ERROR_CRC},  //! Data error (cyclic redundancy check).
		ErrorCodeName{"ERROR_BAD_LENGTH", ERROR_BAD_LENGTH},  //! The program issued a command but the command length is incorrect.
		ErrorCodeName{"ERROR_SEEK", ERROR_SEEK},  //! The drive cannot locate a specific area or track on the disk.
		ErrorCodeName{"ERROR_NOT_DOS_DISK", ERROR_NOT_DOS_DISK},  //! The specified disk or diskette cannot be accessed.
		ErrorCodeName{"ERROR_SECTOR_NOT_FOUND", ERROR_SECTOR_NOT_FOUND},  //! The drive cannot find the sector requested.
		ErrorCodeName{"ERROR_OUT_OF_PAPER", ERROR_OUT_OF_PAPER},  //! The printer is out of paper.
		ErrorCodeName{"ERROR_WRITE_FAULT", ERROR_WRITE_FAULT},  //! The system cannot write to the specified device.
		ErrorCodeName{"ERROR_READ_FAULT", ERROR_READ_FAULT},  //! The system cannot read from the specified device.
		ErrorCodeName{"ERROR_GEN_FAILURE", ERROR_GEN_FAILURE},  //! A device attached to the system is not functioning.
		ErrorCodeName{"ERROR_SHARING_VIOLATION", ERROR_SHARING_VIOLATION},  //! The process cannot access the file because it is being used by another process.
		ErrorCodeName{"ERROR_LOCK_VIOLATION", ERROR_LOCK_VIOLATION},  //! The process cannot access the file because another process has locked a portion of the file.
		ErrorCodeName{"ERROR_WRONG_DISK", ERROR_WRONG_DISK},  //! The wrong diskette is in the drive. Insert %2 (Volume Serial Number: %3) into drive %1.
		ErrorCodeName{"ERROR_SHARING_BUFFER_EXCEEDED", ERROR_SHARING_BUFFER_EXCEEDED},  //! Too many files opened for sharing.
		ErrorCodeName{"ERROR_HANDLE_EOF", ERROR_HANDLE_EOF},  //! Reached the end of the file.
		ErrorCodeName{"ERROR_HANDLE_DISK_FULL", ERROR_HANDLE_DISK_FULL},  //! The disk is full.
		ErrorCodeName{"ERROR_NOT_SUPPORTED", ERROR_NOT_SUPPORTED},  //! The request is not supported.
		ErrorCodeName{"ERROR_REM_NOT_LIST", ERROR_REM_NOT_LIST},  //! Windows cannot find the network path. Verify that the network path is correct and the destination computer is not busy or turned off. If Windows still cannot find the network path, contact your network administrator.
		ErrorCodeName{"ERROR_DUP_NAME", ERROR_DUP_NAME},  //! You were not connected because a duplicate name exists on the network. If joining a domain, go to System in Control Panel to change the computer name and try again. If joining a workgroup, choose another workgroup name.
		ErrorCodeName{"ERROR_BAD_NETPATH", ERROR_BAD_NETPATH},  //! The network path was not found.
		ErrorCodeName{"ERROR_NETWORK_BUSY", ERROR_NETWORK_BUSY},  //! The network is busy.
		ErrorCodeName{"ERROR_DEV_NOT_EXIST", ERROR_DEV_NOT_EXIST},  //! The specified network resource or device is no longer available.
		ErrorCodeName{"ERROR_TOO_MANY_CMDS", ERROR_TOO_MANY_CMDS},  //! The network BIOS command limit has been reached.
		ErrorCodeName{"ERROR_ADAP_HDW_ERR", ERROR_ADAP_HDW_ERR},  //! A network adapter hardware error occurred.
		ErrorCodeName{"ERROR_BAD_NET_RESP", ERROR_BAD_NET_RESP},  //! The specified server cannot perform the requested operation.
		ErrorCodeName{"ERROR_UNEXP_NET_ERR", ERROR_UNEXP_NET_ERR},  //! An unexpected network error occurred.
		ErrorCodeName{"ERROR_BAD_REM_ADAP", ERROR_BAD_REM_ADAP},  //! The remote adapter is not compatible.
		ErrorCodeName{"ERROR_PRINTQ_FULL", ERROR_PRINTQ_FULL},  //! The printer queue is full.
		ErrorCodeName{"ERROR_NO_SPOOL_SPACE", ERROR_NO_SPOOL_SPACE},  //! Space to store the file waiting to be printed is not available on the server.
		ErrorCodeName{"ERROR_PRINT_CANCELLED", ERROR_PRINT_CANCELLED},  //! Your file waiting to be printed was deleted.
		ErrorCodeName{"ERROR_NETNAME_DELETED", ERROR_NETNAME_DELETED},  //! The specified network name is no longer available.
		ErrorCodeName{"ERROR_NETWORK_ACCESS_DENIED", ERROR_NETWORK_ACCESS_DENIED},  //! Network access is denied.
		ErrorCodeName{"ERROR_BAD_DEV_TYPE", ERROR_BAD_DEV_TYPE},  //! The network resource type is not correct.
		ErrorCodeName{"ERROR_BAD_NET_NAME", ERROR_BAD_NET_NAME},  //! The network name cannot be found.
		ErrorCodeName{"ERROR_TOO_MANY_NAMES", ERROR_TOO_MANY_NAMES},  //! The name limit for the local computer network adapter card was exceeded.
		ErrorCodeName{"ERROR_TOO_MANY_SESS", ERROR_TOO_MANY_SESS},  //! The network BIOS session limit was exceeded.
		ErrorCodeName{"ERROR_SHARING_PAUSED", ERROR_SHARING_PAUSED},  //! The remote server has been paused or is in the process of being started.
		ErrorCodeName{"ERROR_REQ_NOT_ACCEP", ERROR_REQ_NOT_ACCEP},  //! No more connections can be made to this remote computer at this time because there are already as many connections as the computer can accept.
		ErrorCodeName{"ERROR_REDIR_PAUSED", ERROR_REDIR_PAUSED},  //! The specified printer or disk device has been paused.
		ErrorCodeName{"ERROR_FILE_EXISTS", ERROR_FILE_EXISTS},  //! The file exists.
		ErrorCodeName{"ERROR_CANNOT_MAKE", ERROR_CANNOT_MAKE},  //! The directory or file cannot be created.
		ErrorCodeName{"ERROR_FAIL_I24", ERROR_FAIL_I24},  //! Fail on INT 24.
		ErrorCodeName{"ERROR_OUT_OF_STRUCTURES", ERROR_OUT_OF_STRUCTURES},  //! Storage to process this request is not available.
		ErrorCodeName{"ERROR_ALREADY_ASSIGNED", ERROR_ALREADY_ASSIGNED},  //! The local device name is already in use.
		ErrorCodeName{"ERROR_INVALID_PASSWORD", ERROR_INVALID_PASSWORD},  //! The specified network password is not correct.
		ErrorCodeName{"ERROR_INVALID_PARAMETER", ERROR_INVALID_PARAMETER},  //! The parameter is incorrect.
		ErrorCodeName{"ERROR_NET_WRITE_FAULT", ERROR_NET_WRITE_FAULT},  //! A write fault occurred on the network.
		ErrorCodeName{"ERROR_NO_PROC_SLOTS", ERROR_NO_PROC_SLOTS},  //! The system cannot start another process at this time.
		ErrorCodeName{"ERROR_TOO_MANY_SEMAPHORES", ERROR_TOO_MANY_SEMAPHORES},  //! Cannot create another system semaphore.
		ErrorCodeName{"ERROR_EXCL_SEM_ALREADY_OWNED", ERROR_EXCL_SEM_ALREADY_OWNED},  //! The exclusive semaphore is owned by another process.
		ErrorCodeName{"ERROR_SEM_IS_SET", ERROR_SEM_IS_SET},  //! The semaphore is set and cannot be closed.
		ErrorCodeName{"ERROR_TOO_MANY_SEM_REQUESTS", ERROR_TOO_MANY_SEM_REQUESTS},  //! The semaphore cannot be set again.
		ErrorCodeName{"ERROR_INVALID_AT_INTERRUPT_TIME", ERROR_INVALID_AT_INTERRUPT_TIME},  //! Cannot request exclusive semaphores at interrupt time.
		ErrorCodeName{"ERROR_SEM_OWNER_DIED", ERROR_SEM_OWNER_DIED},  //! The previous ownership of this semaphore has ended.
		ErrorCodeName{"ERROR_SEM_USER_LIMIT", ERROR_SEM_USER_LIMIT},  //! Insert the diskette for drive %1.
		ErrorCodeName{"ERROR_DISK_CHANGE", ERROR_DISK_CHANGE},  //! The program stopped because an alternate diskette was not inserted.
		ErrorCodeName{"ERROR_DRIVE_LOCKED", ERROR_DRIVE_LOCKED},  //! The disk is in use or locked by another process.
		ErrorCodeName{"ERROR_BROKEN_PIPE", ERROR_BROKEN_PIPE},  //! The pipe has been ended.
		ErrorCodeName{"ERROR_OPEN_FAILED", ERROR_OPEN_FAILED},  //! The system cannot open the device or file specified.
		ErrorCodeName{"ERROR_BUFFER_OVERFLOW", ERROR_BUFFER_OVERFLOW},  //! The file name is too long.
		ErrorCodeName{"ERROR_DISK_FULL", ERROR_DISK_FULL},  //! There is not enough space on the disk.
		ErrorCodeName{"ERROR_NO_MORE_SEARCH_HANDLES", ERROR_NO_MORE_SEARCH_HANDLES},  //! No more internal file identifiers available.
		ErrorCodeName{"ERROR_INVALID_TARGET_HANDLE", ERROR_INVALID_TARGET_HANDLE},  //! The target internal file identifier is incorrect.
		ErrorCodeName{"ERROR_INVALID_CATEGORY", ERROR_INVALID_CATEGORY},  //! The IOCTL call made by the application program is not correct.
		ErrorCodeName{"ERROR_INVALID_VERIFY_SWITCH", ERROR_INVALID_VERIFY_SWITCH},  //! The verify-on-write switch parameter value is not correct.
		ErrorCodeName{"ERROR_BAD_DRIVER_LEVEL", ERROR_BAD_DRIVER_LEVEL},  //! The system does not support the command requested.
		ErrorCodeName{"ERROR_CALL_NOT_IMPLEMENTED", ERROR_CALL_NOT_IMPLEMENTED},  //! This function is not supported on this system.
		ErrorCodeName{"ERROR_SEM_TIMEOUT", ERROR_SEM_TIMEOUT},  //! The semaphore timeout period has expired.
		ErrorCodeName{"ERROR_INSUFFICIENT_BUFFER", ERROR_INSUFFICIENT_BUFFER},  //! The data area passed to a system call is too small.
		ErrorCodeName{"ERROR_INVALID_NAME", ERROR_INVALID_NAME},  //! The filename, directory name, or volume label syntax is incorrect.
		ErrorCodeName{"ERROR_INVALID_LEVEL", ERROR_INVALID_LEVEL},  //! The system call level is not correct.
		ErrorCodeName{"ERROR_NO_VOLUME_LABEL", ERROR_NO_VOLUME_LABEL},  //! The disk has no volume label.
		ErrorCodeName{"ERROR_MOD_NOT_FOUND", ERROR_MOD_NOT_FOUND},  //! The specified module could not be found.
		ErrorCodeName{"ERROR_PROC_NOT_FOUND", ERROR_PROC_NOT_FOUND},  //! The specified procedure could not be found.
		ErrorCodeName{"ERROR_WAIT_NO_CHILDREN", ERROR_WAIT_NO_CHILDREN},  //! There are no child processes to wait for.
		ErrorCodeName{"ERROR_CHILD_NOT_COMPLETE", ERROR_CHILD_NOT_COMPLETE},  //! The %1 application cannot be run in Win32 mode.
		ErrorCodeName{"ERROR_DIRECT_ACCESS_HANDLE", ERROR_DIRECT_ACCESS_HANDLE},  //! Attempt to use a file handle to an open disk partition for an operation other than raw disk I/O.
		ErrorCodeName{"ERROR_NEGATIVE_SEEK", ERROR_NEGATIVE_SEEK},  //! An attempt was made to move the file pointer before the beginning of the file.
		ErrorCodeName{"ERROR_SEEK_ON_DEVICE", ERROR_SEEK_ON_DEVICE},  //! The file pointer cannot be set on the specified device or file.
		ErrorCodeName{"ERROR_IS_JOIN_TARGET", ERROR_IS_JOIN_TARGET},  //! A JOIN or SUBST command cannot be used for a drive that contains previously joined drives.
		ErrorCodeName{"ERROR_IS_JOINED", ERROR_IS_JOINED},  //! An attempt was made to use a JOIN or SUBST command on a drive that has already been joined.
		ErrorCodeName{"ERROR_IS_SUBSTED", ERROR_IS_SUBSTED},  //! An attempt was made to use a JOIN or SUBST command on a drive that has already been substituted.
		ErrorCodeName{"ERROR_NOT_JOINED", ERROR_NOT_JOINED},  //! The system tried to delete the JOIN of a drive that is not joined.
		ErrorCodeName{"ERROR_NOT_SUBSTED", ERROR_NOT_SUBSTED},  //! The system tried to delete the substitution of a drive that is not substituted.
		ErrorCodeName{"ERROR_JOIN_TO_JOIN", ERROR_JOIN_TO_JOIN},  //! The system tried to join a drive to a directory on a joined drive.
		ErrorCodeName{"ERROR_SUBST_TO_SUBST", ERROR_SUBST_TO_SUBST},  //! The system tried to substitute a drive to a directory on a substituted drive.
		ErrorCodeName{"ERROR_JOIN_TO_SUBST", ERROR_JOIN_TO_SUBST},  //! The system tried to join a drive to a directory on a substituted drive.
		ErrorCodeName{"ERROR_SUBST_TO_JOIN", ERROR_SUBST_TO_JOIN},  //! The system tried to SUBST a drive to a directory on a joined drive.
		ErrorCodeName{"ERROR_BUSY_DRIVE", ERROR_BUSY_DRIVE},  //! The system cannot perform a JOIN or SUBST at this time.
		ErrorCodeName{"ERROR_SAME_DRIVE", ERROR_SAME_DRIVE},  //! The system cannot join or substitute a drive to or for a directory on the same drive.
		ErrorCodeName{"ERROR_DIR_NOT_ROOT", ERROR_DIR_NOT_ROOT},  //! The directory is not a subdirectory of the root directory.
		ErrorCodeName{"ERROR_DIR_NOT_EMPTY", ERROR_DIR_NOT_EMPTY},  //! The directory is not empty.
		ErrorCodeName{"ERROR_IS_SUBST_PATH", ERROR_IS_SUBST_PATH},  //! The path specified is being used in a substitute.
		ErrorCodeName{"ERROR_IS_JOIN_PATH", ERROR_IS_JOIN_PATH},  //! Not enough resources are available to process this command.
		ErrorCodeName{"ERROR_PATH_BUSY", ERROR_PATH_BUSY},  //! The path specified cannot be used at this time.
		ErrorCodeName{"ERROR_IS_SUBST_TARGET", ERROR_IS_SUBST_TARGET},  //! An attempt was made to join or substitute a drive for which a directory on the drive is the target of a previous substitute.
		ErrorCodeName{"ERROR_SYSTEM_TRACE", ERROR_SYSTEM_TRACE},  //! System trace information was not specified in your CONFIG.SYS file, or tracing is disallowed.
		ErrorCodeName{"ERROR_INVALID_EVENT_COUNT", ERROR_INVALID_EVENT_COUNT},  //! The number of specified semaphore events for DosMuxSemWait is not correct.
		ErrorCodeName{"ERROR_TOO_MANY_MUXWAITERS", ERROR_TOO_MANY_MUXWAITERS},  //! DosMuxSemWait did not execute; too many semaphores are already set.
		ErrorCodeName{"ERROR_INVALID_LIST_FORMAT", ERROR_INVALID_LIST_FORMAT},  //! The DosMuxSemWait list is not correct.
		ErrorCodeName{"ERROR_LABEL_TOO_LONG", ERROR_LABEL_TOO_LONG},  //! The volume label you entered exceeds the label character limit of the target file system.
		ErrorCodeName{"ERROR_TOO_MANY_TCBS", ERROR_TOO_MANY_TCBS},  //! Cannot create another thread.
		ErrorCodeName{"ERROR_SIGNAL_REFUSED", ERROR_SIGNAL_REFUSED},  //! The recipient process has refused the signal.
		ErrorCodeName{"ERROR_DISCARDED", ERROR_DISCARDED},  //! The segment is already discarded and cannot be locked.
		ErrorCodeName{"ERROR_NOT_LOCKED", ERROR_NOT_LOCKED},  //! The segment is already unlocked.
		ErrorCodeName{"ERROR_BAD_THREADID_ADDR", ERROR_BAD_THREADID_ADDR},  //! The address for the thread ID is not correct.
		ErrorCodeName{"ERROR_BAD_ARGUMENTS", ERROR_BAD_ARGUMENTS},  //! One or more arguments are not correct.
		ErrorCodeName{"ERROR_BAD_PATHNAME", ERROR_BAD_PATHNAME},  //! The specified path is invalid.
		ErrorCodeName{"ERROR_SIGNAL_PENDING", ERROR_SIGNAL_PENDING},  //! A signal is already pending.
		ErrorCodeName{"ERROR_MAX_THRDS_REACHED", ERROR_MAX_THRDS_REACHED},  //! No more threads can be created in the system.
		ErrorCodeName{"ERROR_LOCK_FAILED", ERROR_LOCK_FAILED},  //! Unable to lock a region of a file.
		ErrorCodeName{"ERROR_BUSY", ERROR_BUSY},  //! The requested resource is in use.
		ErrorCodeName{"ERROR_DEVICE_SUPPORT_IN_PROGRESS", ERROR_DEVICE_SUPPORT_IN_PROGRESS},  //! Device's command support detection is in progress.
		ErrorCodeName{"ERROR_CANCEL_VIOLATION", ERROR_CANCEL_VIOLATION},  //! A lock request was not outstanding for the supplied cancel region.
		ErrorCodeName{"ERROR_ATOMIC_LOCKS_NOT_SUPPORTED", ERROR_ATOMIC_LOCKS_NOT_SUPPORTED},  //! The file system does not support atomic changes to the lock type.
		ErrorCodeName{"ERROR_INVALID_SEGMENT_NUMBER", ERROR_INVALID_SEGMENT_NUMBER},  //! The system detected a segment number that was not correct.
		ErrorCodeName{"ERROR_INVALID_ORDINAL", ERROR_INVALID_ORDINAL},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_ALREADY_EXISTS", ERROR_ALREADY_EXISTS},  //! Cannot create a file when that file already exists.
		ErrorCodeName{"ERROR_INVALID_FLAG_NUMBER", ERROR_INVALID_FLAG_NUMBER},  //! The flag passed is not correct.
		ErrorCodeName{"ERROR_SEM_NOT_FOUND", ERROR_SEM_NOT_FOUND},  //! The specified system semaphore name was not found.
		ErrorCodeName{"ERROR_INVALID_STARTING_CODESEG", ERROR_INVALID_STARTING_CODESEG},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_INVALID_STACKSEG", ERROR_INVALID_STACKSEG},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_INVALID_MODULETYPE", ERROR_INVALID_MODULETYPE},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_INVALID_EXE_SIGNATURE", ERROR_INVALID_EXE_SIGNATURE},  //! Cannot run %1 in Win32 mode.
		ErrorCodeName{"ERROR_EXE_MARKED_INVALID", ERROR_EXE_MARKED_INVALID},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_BAD_EXE_FORMAT", ERROR_BAD_EXE_FORMAT},  //! %1 is not a valid Win32 application.
		ErrorCodeName{"ERROR_ITERATED_DATA_EXCEEDS_64k", ERROR_ITERATED_DATA_EXCEEDS_64k},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_INVALID_MINALLOCSIZE", ERROR_INVALID_MINALLOCSIZE},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_DYNLINK_FROM_INVALID_RING", ERROR_DYNLINK_FROM_INVALID_RING},  //! The operating system cannot run this application program.
		ErrorCodeName{"ERROR_IOPL_NOT_ENABLED", ERROR_IOPL_NOT_ENABLED},  //! The operating system is not presently configured to run this application.
		ErrorCodeName{"ERROR_INVALID_SEGDPL", ERROR_INVALID_SEGDPL},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_AUTODATASEG_EXCEEDS_64k", ERROR_AUTODATASEG_EXCEEDS_64k},  //! The operating system cannot run this application program.
		ErrorCodeName{"ERROR_RING2SEG_MUST_BE_MOVABLE", ERROR_RING2SEG_MUST_BE_MOVABLE},  //! The code segment cannot be greater than or equal to 64K.
		ErrorCodeName{"ERROR_RELOC_CHAIN_XEEDS_SEGLIM", ERROR_RELOC_CHAIN_XEEDS_SEGLIM},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_INFLOOP_IN_RELOC_CHAIN", ERROR_INFLOOP_IN_RELOC_CHAIN},  //! The operating system cannot run %1.
		ErrorCodeName{"ERROR_ENVVAR_NOT_FOUND", ERROR_ENVVAR_NOT_FOUND},  //! The system could not find the environment option that was entered.
		ErrorCodeName{"ERROR_NO_SIGNAL_SENT", ERROR_NO_SIGNAL_SENT},  //! No process in the command subtree has a signal handler.
		ErrorCodeName{"ERROR_FILENAME_EXCED_RANGE", ERROR_FILENAME_EXCED_RANGE},  //! The filename or extension is too long.
		ErrorCodeName{"ERROR_RING2_STACK_IN_USE", ERROR_RING2_STACK_IN_USE},  //! The ring 2 stack is in use.
		ErrorCodeName{"ERROR_META_EXPANSION_TOO_LONG", ERROR_META_EXPANSION_TOO_LONG},  //! The global filename characters, * or ?, are entered incorrectly or too many global filename characters are specified.
		ErrorCodeName{"ERROR_INVALID_SIGNAL_NUMBER", ERROR_INVALID_SIGNAL_NUMBER},  //! The signal being posted is not correct.
		ErrorCodeName{"ERROR_THREAD_1_INACTIVE", ERROR_THREAD_1_INACTIVE},  //! The signal handler cannot be set.
		ErrorCodeName{"ERROR_LOCKED", ERROR_LOCKED},  //! The segment is locked and cannot be reallocated.
		ErrorCodeName{"ERROR_TOO_MANY_MODULES", ERROR_TOO_MANY_MODULES},  //! Too many dynamic-link modules are attached to this program or dynamic-link module.
		ErrorCodeName{"ERROR_NESTING_NOT_ALLOWED", ERROR_NESTING_NOT_ALLOWED},  //! Cannot nest calls to LoadModule.
		ErrorCodeName{"ERROR_EXE_MACHINE_TYPE_MISMATCH", ERROR_EXE_MACHINE_TYPE_MISMATCH},  //! This version of %1 is not compatible with the version of Windows you're running. Check your computer's system information and then contact the software publisher.
		ErrorCodeName{"ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY", ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY},  //! The image file %1 is signed, unable to modify.
		ErrorCodeName{"ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY", ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY},  //! The image file %1 is strong signed, unable to modify.
		ErrorCodeName{"ERROR_FILE_CHECKED_OUT", ERROR_FILE_CHECKED_OUT},  //! This file is checked out or locked for editing by another user.
		ErrorCodeName{"ERROR_CHECKOUT_REQUIRED", ERROR_CHECKOUT_REQUIRED},  //! The file must be checked out before saving changes.
		ErrorCodeName{"ERROR_BAD_FILE_TYPE", ERROR_BAD_FILE_TYPE},  //! The file type being saved or retrieved has been blocked.
		ErrorCodeName{"ERROR_FILE_TOO_LARGE", ERROR_FILE_TOO_LARGE},  //! The file size exceeds the limit allowed and cannot be saved.
		ErrorCodeName{"ERROR_FORMS_AUTH_REQUIRED", ERROR_FORMS_AUTH_REQUIRED},  //! Access Denied. Before opening files in this location, you must first add the web site to your trusted sites list, browse to the web site, and select the option to login automatically.
		ErrorCodeName{"ERROR_VIRUS_INFECTED", ERROR_VIRUS_INFECTED},  //! Operation did not complete successfully because the file contains a virus or potentially unwanted software.
		ErrorCodeName{"ERROR_VIRUS_DELETED", ERROR_VIRUS_DELETED},  //! This file contains a virus or potentially unwanted software and cannot be opened. Due to the nature of this virus or potentially unwanted software, the file has been removed from this location.
		ErrorCodeName{"ERROR_PIPE_LOCAL", ERROR_PIPE_LOCAL},  //! The pipe is local.
		ErrorCodeName{"ERROR_BAD_PIPE", ERROR_BAD_PIPE},  //! The pipe state is invalid.
		ErrorCodeName{"ERROR_PIPE_BUSY", ERROR_PIPE_BUSY},  //! All pipe instances are busy.
		ErrorCodeName{"ERROR_NO_DATA", ERROR_NO_DATA},  //! The pipe is being closed.
		ErrorCodeName{"ERROR_PIPE_NOT_CONNECTED", ERROR_PIPE_NOT_CONNECTED},  //! No process is on the other end of the pipe.
		ErrorCodeName{"ERROR_MORE_DATA", ERROR_MORE_DATA},  //! More data is available.
		ErrorCodeName{"ERROR_VC_DISCONNECTED", ERROR_VC_DISCONNECTED},  //! The session was canceled.
		ErrorCodeName{"ERROR_INVALID_EA_NAME", ERROR_INVALID_EA_NAME},  //! The specified extended attribute name was invalid.
		ErrorCodeName{"ERROR_EA_LIST_INCONSISTENT", ERROR_EA_LIST_INCONSISTENT},  //! The extended attributes are inconsistent.
		ErrorCodeName{"WAIT_TIMEOUT", WAIT_TIMEOUT},  //! The wait operation timed out.
		ErrorCodeName{"ERROR_NO_MORE_ITEMS", ERROR_NO_MORE_ITEMS},  //! No more data is available.
		ErrorCodeName{"ERROR_CANNOT_COPY", ERROR_CANNOT_COPY},  //! The copy functions cannot be used.
		ErrorCodeName{"ERROR_DIRECTORY", ERROR_DIRECTORY},  //! The directory name is invalid.
		ErrorCodeName{"ERROR_EAS_DIDNT_FIT", ERROR_EAS_DIDNT_FIT},  //! The extended attributes did not fit in the buffer.
		ErrorCodeName{"ERROR_EA_FILE_CORRUPT", ERROR_EA_FILE_CORRUPT},  //! The extended attribute file on the mounted file system is corrupt.
		ErrorCodeName{"ERROR_EA_TABLE_FULL", ERROR_EA_TABLE_FULL},  //! The extended attribute table file is full.
		ErrorCodeName{"ERROR_INVALID_EA_HANDLE", ERROR_INVALID_EA_HANDLE},  //! The specified extended attribute handle is invalid.
		ErrorCodeName{"ERROR_EAS_NOT_SUPPORTED", ERROR_EAS_NOT_SUPPORTED},  //! The mounted file system does not support extended attributes.
		ErrorCodeName{"ERROR_NOT_OWNER", ERROR_NOT_OWNER},  //! Attempt to release mutex not owned by caller.
		ErrorCodeName{"ERROR_TOO_MANY_POSTS", ERROR_TOO_MANY_POSTS},  //! Too many posts were made to a semaphore.
		ErrorCodeName{"ERROR_PARTIAL_COPY", ERROR_PARTIAL_COPY},  //! Only part of a ReadProcessMemory or WriteProcessMemory request was completed.
		ErrorCodeName{"ERROR_OPLOCK_NOT_GRANTED", ERROR_OPLOCK_NOT_GRANTED},  //! The oplock request is denied.
		ErrorCodeName{"ERROR_INVALID_OPLOCK_PROTOCOL", ERROR_INVALID_OPLOCK_PROTOCOL},  //! An invalid oplock acknowledgment was received by the system.
		ErrorCodeName{"ERROR_DISK_TOO_FRAGMENTED", ERROR_DISK_TOO_FRAGMENTED},  //! The volume is too fragmented to complete this operation.
		ErrorCodeName{"ERROR_DELETE_PENDING", ERROR_DELETE_PENDING},  //! The file cannot be opened because it is in the process of being deleted.
		ErrorCodeName{"ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING", ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING},  //! Short name settings may not be changed on this volume due to the global registry setting.
		ErrorCodeName{"ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME", ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME},  //! Short names are not enabled on this volume.
		ErrorCodeName{"ERROR_SECURITY_STREAM_IS_INCONSISTENT", ERROR_SECURITY_STREAM_IS_INCONSISTENT},  //! The security stream for the given volume is in an inconsistent state. Please run CHKDSK on the volume.
		ErrorCodeName{"ERROR_INVALID_LOCK_RANGE", ERROR_INVALID_LOCK_RANGE},  //! A requested file lock operation cannot be processed due to an invalid byte range.
		ErrorCodeName{"ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT", ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT},  //! The subsystem needed to support the image type is not present.
		ErrorCodeName{"ERROR_NOTIFICATION_GUID_ALREADY_DEFINED", ERROR_NOTIFICATION_GUID_ALREADY_DEFINED},  //! The specified file already has a notification GUID associated with it.
		ErrorCodeName{"ERROR_INVALID_EXCEPTION_HANDLER", ERROR_INVALID_EXCEPTION_HANDLER},  //! An invalid exception handler routine has been detected.
		ErrorCodeName{"ERROR_DUPLICATE_PRIVILEGES", ERROR_DUPLICATE_PRIVILEGES},  //! Duplicate privileges were specified for the token.
		ErrorCodeName{"ERROR_NO_RANGES_PROCESSED", ERROR_NO_RANGES_PROCESSED},  //! No ranges for the specified operation were able to be processed.
		ErrorCodeName{"ERROR_NOT_ALLOWED_ON_SYSTEM_FILE", ERROR_NOT_ALLOWED_ON_SYSTEM_FILE},  //! Operation is not allowed on a file system internal file.
		ErrorCodeName{"ERROR_DISK_RESOURCES_EXHAUSTED", ERROR_DISK_RESOURCES_EXHAUSTED},  //! The physical resources of this disk have been exhausted.
		ErrorCodeName{"ERROR_INVALID_TOKEN", ERROR_INVALID_TOKEN},  //! The token representing the data is invalid.
		ErrorCodeName{"ERROR_DEVICE_FEATURE_NOT_SUPPORTED", ERROR_DEVICE_FEATURE_NOT_SUPPORTED},  //! The device does not support the command feature.
		ErrorCodeName{"ERROR_MR_MID_NOT_FOUND", ERROR_MR_MID_NOT_FOUND},  //! The system cannot find message text for message number 0x%1 in the message file for %2.
		ErrorCodeName{"ERROR_SCOPE_NOT_FOUND", ERROR_SCOPE_NOT_FOUND},  //! The scope specified was not found.
		ErrorCodeName{"ERROR_UNDEFINED_SCOPE", ERROR_UNDEFINED_SCOPE},  //! The Central Access Policy specified is not defined on the target machine.
		ErrorCodeName{"ERROR_INVALID_CAP", ERROR_INVALID_CAP},  //! The Central Access Policy obtained from Active Directory is invalid.
		ErrorCodeName{"ERROR_DEVICE_UNREACHABLE", ERROR_DEVICE_UNREACHABLE},  //! The device is unreachable.
		ErrorCodeName{"ERROR_DEVICE_NO_RESOURCES", ERROR_DEVICE_NO_RESOURCES},  //! The target device has insufficient resources to complete the operation.
		ErrorCodeName{"ERROR_DATA_CHECKSUM_ERROR", ERROR_DATA_CHECKSUM_ERROR},  //! A data integrity checksum error occurred. Data in the file stream is corrupt.
		ErrorCodeName{"ERROR_INTERMIXED_KERNEL_EA_OPERATION", ERROR_INTERMIXED_KERNEL_EA_OPERATION},  //! An attempt was made to modify both a KERNEL and normal Extended Attribute (EA) in the same operation.
		ErrorCodeName{"ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED", ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED},  //! Device does not support file-level TRIM.
		ErrorCodeName{"ERROR_OFFSET_ALIGNMENT_VIOLATION", ERROR_OFFSET_ALIGNMENT_VIOLATION},  //! The command specified a data offset that does not align to the device's granularity/alignment.
		ErrorCodeName{"ERROR_INVALID_FIELD_IN_PARAMETER_LIST", ERROR_INVALID_FIELD_IN_PARAMETER_LIST},  //! The command specified an invalid field in its parameter list.
		ErrorCodeName{"ERROR_OPERATION_IN_PROGRESS", ERROR_OPERATION_IN_PROGRESS},  //! An operation is currently in progress with the device.
		ErrorCodeName{"ERROR_BAD_DEVICE_PATH", ERROR_BAD_DEVICE_PATH},  //! An attempt was made to send down the command via an invalid path to the target device.
		ErrorCodeName{"ERROR_TOO_MANY_DESCRIPTORS", ERROR_TOO_MANY_DESCRIPTORS},  //! The command specified a number of descriptors that exceeded the maximum supported by the device.
		ErrorCodeName{"ERROR_SCRUB_DATA_DISABLED", ERROR_SCRUB_DATA_DISABLED},  //! Scrub is disabled on the specified file.
		ErrorCodeName{"ERROR_NOT_REDUNDANT_STORAGE", ERROR_NOT_REDUNDANT_STORAGE},  //! The storage device does not provide redundancy.
		ErrorCodeName{"ERROR_RESIDENT_FILE_NOT_SUPPORTED", ERROR_RESIDENT_FILE_NOT_SUPPORTED},  //! An operation is not supported on a resident file.
		ErrorCodeName{"ERROR_COMPRESSED_FILE_NOT_SUPPORTED", ERROR_COMPRESSED_FILE_NOT_SUPPORTED},  //! An operation is not supported on a compressed file.
		ErrorCodeName{"ERROR_DIRECTORY_NOT_SUPPORTED", ERROR_DIRECTORY_NOT_SUPPORTED},  //! An operation is not supported on a directory.
		ErrorCodeName{"ERROR_NOT_READ_FROM_COPY", ERROR_NOT_READ_FROM_COPY},  //! The specified copy of the requested data could not be read.
		ErrorCodeName{"ERROR_FAIL_NOACTION_REBOOT", ERROR_FAIL_NOACTION_REBOOT},  //! No action was taken as a system reboot is required.
		ErrorCodeName{"ERROR_FAIL_SHUTDOWN", ERROR_FAIL_SHUTDOWN},  //! The shutdown operation failed.
		ErrorCodeName{"ERROR_FAIL_RESTART", ERROR_FAIL_RESTART},  //! The restart operation failed.
		ErrorCodeName{"ERROR_MAX_SESSIONS_REACHED", ERROR_MAX_SESSIONS_REACHED},  //! The maximum number of sessions has been reached.
		ErrorCodeName{"ERROR_THREAD_MODE_ALREADY_BACKGROUND", ERROR_THREAD_MODE_ALREADY_BACKGROUND},  //! The thread is already in background processing mode.
		ErrorCodeName{"ERROR_THREAD_MODE_NOT_BACKGROUND", ERROR_THREAD_MODE_NOT_BACKGROUND},  //! The thread is not in background processing mode.
		ErrorCodeName{"ERROR_PROCESS_MODE_ALREADY_BACKGROUND", ERROR_PROCESS_MODE_ALREADY_BACKGROUND},  //! The process is already in background processing mode.
		ErrorCodeName{"ERROR_PROCESS_MODE_NOT_BACKGROUND", ERROR_PROCESS_MODE_NOT_BACKGROUND},  //! The process is not in background processing mode.
		ErrorCodeName{"ERROR_INVALID_ADDRESS", ERROR_INVALID_ADDRESS},  //! Attempt to access invalid address.
		ErrorCodeName{"ERROR_USER_PROFILE_LOAD", ERROR_USER_PROFILE_LOAD},  //! User profile cannot be loaded.
		ErrorCodeName{"ERROR_ARITHMETIC_OVERFLOW", ERROR_ARITHMETIC_OVERFLOW},  //! Arithmetic result exceeded 32 bits.
		ErrorCodeName{"ERROR_PIPE_CONNECTED", ERROR_PIPE_CONNECTED},  //! There is a process on other end of the pipe.
		ErrorCodeName{"ERROR_PIPE_LISTENING", ERROR_PIPE_LISTENING},  //! Waiting for a process to open the other end of the pipe.
		ErrorCodeName{"ERROR_VERIFIER_STOP", ERROR_VERIFIER_STOP},  //! Application verifier has found an error in the current process.
		ErrorCodeName{"ERROR_ABIOS_ERROR", ERROR_ABIOS_ERROR},  //! An error occurred in the ABIOS subsystem.
		ErrorCodeName{"ERROR_WX86_WARNING", ERROR_WX86_WARNING},  //! A warning occurred in the WX86 subsystem.
		ErrorCodeName{"ERROR_WX86_ERROR", ERROR_WX86_ERROR},  //! An error occurred in the WX86 subsystem.
		ErrorCodeName{"ERROR_TIMER_NOT_CANCELED", ERROR_TIMER_NOT_CANCELED},  //! An attempt was made to cancel or set a timer that has an associated APC and the subject thread is not the thread that originally set the timer with an associated APC routine.
		ErrorCodeName{"ERROR_UNWIND", ERROR_UNWIND},  //! Unwind exception code.
		ErrorCodeName{"ERROR_BAD_STACK", ERROR_BAD_STACK},  //! An invalid or unaligned stack was encountered during an unwind operation.
		ErrorCodeName{"ERROR_INVALID_UNWIND_TARGET", ERROR_INVALID_UNWIND_TARGET},  //! An invalid unwind target was encountered during an unwind operation.
		ErrorCodeName{"ERROR_INVALID_PORT_ATTRIBUTES", ERROR_INVALID_PORT_ATTRIBUTES},  //! Invalid Object Attributes specified to NtCreatePort or invalid Port Attributes specified to NtConnectPort
		ErrorCodeName{"ERROR_PORT_MESSAGE_TOO_LONG", ERROR_PORT_MESSAGE_TOO_LONG},  //! Length of message passed to NtRequestPort or NtRequestWaitReplyPort was longer than the maximum message allowed by the port.
		ErrorCodeName{"ERROR_INVALID_QUOTA_LOWER", ERROR_INVALID_QUOTA_LOWER},  //! An attempt was made to lower a quota limit below the current usage.
		ErrorCodeName{"ERROR_DEVICE_ALREADY_ATTACHED", ERROR_DEVICE_ALREADY_ATTACHED},  //! An attempt was made to attach to a device that was already attached to another device.
		ErrorCodeName{"ERROR_INSTRUCTION_MISALIGNMENT", ERROR_INSTRUCTION_MISALIGNMENT},  //! An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references.
		ErrorCodeName{"ERROR_PROFILING_NOT_STARTED", ERROR_PROFILING_NOT_STARTED},  //! Profiling not started.
		ErrorCodeName{"ERROR_PROFILING_NOT_STOPPED", ERROR_PROFILING_NOT_STOPPED},  //! Profiling not stopped.
		ErrorCodeName{"ERROR_COULD_NOT_INTERPRET", ERROR_COULD_NOT_INTERPRET},  //! The passed ACL did not contain the minimum required information.
		ErrorCodeName{"ERROR_PROFILING_AT_LIMIT", ERROR_PROFILING_AT_LIMIT},  //! The number of active profiling objects is at the maximum and no more may be started.
		ErrorCodeName{"ERROR_CANT_WAIT", ERROR_CANT_WAIT},  //! Used to indicate that an operation cannot continue without blocking for I/O.
		ErrorCodeName{"ERROR_CANT_TERMINATE_SELF", ERROR_CANT_TERMINATE_SELF},  //! Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process.
		ErrorCodeName{"ERROR_UNEXPECTED_MM_CREATE_ERR", ERROR_UNEXPECTED_MM_CREATE_ERR},  //! If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
		ErrorCodeName{"ERROR_UNEXPECTED_MM_MAP_ERROR", ERROR_UNEXPECTED_MM_MAP_ERROR},  //! If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
		ErrorCodeName{"ERROR_UNEXPECTED_MM_EXTEND_ERR", ERROR_UNEXPECTED_MM_EXTEND_ERR},  //! If an MM error is returned which is not defined in the standard FsRtl filter, it is converted to one of the following errors which is guaranteed to be in the filter. In this case information is lost, however, the filter correctly handles the exception.
		ErrorCodeName{"ERROR_BAD_FUNCTION_TABLE", ERROR_BAD_FUNCTION_TABLE},  //! A malformed function table was encountered during an unwind operation.
		ErrorCodeName{"ERROR_NO_GUID_TRANSLATION", ERROR_NO_GUID_TRANSLATION},  //! Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system. This causes the protection attempt to fail, which may cause a file creation attempt to fail.
		ErrorCodeName{"ERROR_INVALID_LDT_SIZE", ERROR_INVALID_LDT_SIZE},  //! Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors.
		ErrorCodeName{"ERROR_INVALID_LDT_OFFSET", ERROR_INVALID_LDT_OFFSET},  //! Indicates that the starting value for the LDT information was not an integral multiple of the selector size.
		ErrorCodeName{"ERROR_INVALID_LDT_DESCRIPTOR", ERROR_INVALID_LDT_DESCRIPTOR},  //! Indicates that the user supplied an invalid descriptor when trying to set up Ldt descriptors.
		ErrorCodeName{"ERROR_TOO_MANY_THREADS", ERROR_TOO_MANY_THREADS},  //! Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token may only be performed when a process has zero or one threads.
		ErrorCodeName{"ERROR_THREAD_NOT_IN_PROCESS", ERROR_THREAD_NOT_IN_PROCESS},  //! An attempt was made to operate on a thread within a specific process, but the thread specified is not in the process specified.
		ErrorCodeName{"ERROR_PAGEFILE_QUOTA_EXCEEDED", ERROR_PAGEFILE_QUOTA_EXCEEDED},  //! Page file quota was exceeded.
		ErrorCodeName{"ERROR_LOGON_SERVER_CONFLICT", ERROR_LOGON_SERVER_CONFLICT},  //! The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role.
		ErrorCodeName{"ERROR_SYNCHRONIZATION_REQUIRED", ERROR_SYNCHRONIZATION_REQUIRED},  //! The SAM database on a Windows Server is significantly out of synchronization with the copy on the Domain Controller. A complete synchronization is required.
		ErrorCodeName{"ERROR_NET_OPEN_FAILED", ERROR_NET_OPEN_FAILED},  //! The NtCreateFile API failed. This error should never be returned to an application, it is a place holder for the Windows Lan Manager Redirector to use in its internal error mapping routines.
		ErrorCodeName{"ERROR_IO_PRIVILEGE_FAILED", ERROR_IO_PRIVILEGE_FAILED},  //! {Privilege Failed} The I/O permissions for the process could not be changed.
		ErrorCodeName{"ERROR_CONTROL_C_EXIT", ERROR_CONTROL_C_EXIT},  //! {Application Exit by CTRL+C} The application terminated as a result of a CTRL+C.
		ErrorCodeName{"ERROR_MISSING_SYSTEMFILE", ERROR_MISSING_SYSTEMFILE},  //! {Missing System File} The required system file %hs is bad or missing.
		ErrorCodeName{"ERROR_UNHANDLED_EXCEPTION", ERROR_UNHANDLED_EXCEPTION},  //! {Application Error} The exception %s (0x%08lx) occurred in the application at location 0x%08lx.
		ErrorCodeName{"ERROR_APP_INIT_FAILURE", ERROR_APP_INIT_FAILURE},  //! {Application Error} The application was unable to start correctly (0x%lx). Click OK to close the application.
		ErrorCodeName{"ERROR_PAGEFILE_CREATE_FAILED", ERROR_PAGEFILE_CREATE_FAILED},  //! {Unable to Create Paging File} The creation of the paging file %hs failed (%lx). The requested size was %ld.
		ErrorCodeName{"ERROR_INVALID_IMAGE_HASH", ERROR_INVALID_IMAGE_HASH},  //! Windows cannot verify the digital signature for this file. A recent hardware or software change might have installed a file that is signed incorrectly or damaged, or that might be malicious software from an unknown source.
		ErrorCodeName{"ERROR_NO_PAGEFILE", ERROR_NO_PAGEFILE},  //! {No Paging File Specified} No paging file was specified in the system configuration.
		ErrorCodeName{"ERROR_ILLEGAL_FLOAT_CONTEXT", ERROR_ILLEGAL_FLOAT_CONTEXT},  //! {EXCEPTION} A real-mode application issued a floating-point instruction and floating-point hardware is not present.
		ErrorCodeName{"ERROR_NO_EVENT_PAIR", ERROR_NO_EVENT_PAIR},  //! An event pair synchronization operation was performed using the thread specific client/server event pair object, but no event pair object was associated with the thread.
		ErrorCodeName{"ERROR_DOMAIN_CTRLR_CONFIG_ERROR", ERROR_DOMAIN_CTRLR_CONFIG_ERROR},  //! A Windows Server has an incorrect configuration.
		ErrorCodeName{"ERROR_ILLEGAL_CHARACTER", ERROR_ILLEGAL_CHARACTER},  //! An illegal character was encountered. For a multi-byte character set this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE.
		ErrorCodeName{"ERROR_UNDEFINED_CHARACTER", ERROR_UNDEFINED_CHARACTER},  //! The Unicode character is not defined in the Unicode character set installed on the system.
		ErrorCodeName{"ERROR_FLOPPY_VOLUME", ERROR_FLOPPY_VOLUME},  //! The paging file cannot be created on a floppy diskette.
		ErrorCodeName{"ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT", ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT},  //! The system BIOS failed to connect a system interrupt to the device or bus for which the device is connected.
		ErrorCodeName{"ERROR_BACKUP_CONTROLLER", ERROR_BACKUP_CONTROLLER},  //! This operation is only allowed for the Primary Domain Controller of the domain.
		ErrorCodeName{"ERROR_MUTANT_LIMIT_EXCEEDED", ERROR_MUTANT_LIMIT_EXCEEDED},  //! An attempt was made to acquire a mutant such that its maximum count would have been exceeded.
		ErrorCodeName{"ERROR_FS_DRIVER_REQUIRED", ERROR_FS_DRIVER_REQUIRED},  //! A volume has been accessed for which a file system driver is required that has not yet been loaded.
		ErrorCodeName{"ERROR_CANNOT_LOAD_REGISTRY_FILE", ERROR_CANNOT_LOAD_REGISTRY_FILE},  //! {Registry File Failure} The registry cannot load the hive (file): %hs or its log or alternate. It is corrupt, absent, or not writable.
		ErrorCodeName{"ERROR_DEBUG_ATTACH_FAILED", ERROR_DEBUG_ATTACH_FAILED},  //! {Unexpected Failure in DebugActiveProcess} An unexpected failure occurred while processing a DebugActiveProcess API request. You may choose OK to terminate the process, or Cancel to ignore the error.
		ErrorCodeName{"ERROR_SYSTEM_PROCESS_TERMINATED", ERROR_SYSTEM_PROCESS_TERMINATED},  //! {Fatal System Error} The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x). The system has been shut down.
		ErrorCodeName{"ERROR_DATA_NOT_ACCEPTED", ERROR_DATA_NOT_ACCEPTED},  //! {Data Not Accepted} The TDI client could not handle the data received during an indication.
		ErrorCodeName{"ERROR_VDM_HARD_ERROR", ERROR_VDM_HARD_ERROR},  //! NTVDM encountered a hard error.
		ErrorCodeName{"ERROR_DRIVER_CANCEL_TIMEOUT", ERROR_DRIVER_CANCEL_TIMEOUT},  //! {Cancel Timeout} The driver %hs failed to complete a cancelled I/O request in the allotted time.
		ErrorCodeName{"ERROR_REPLY_MESSAGE_MISMATCH", ERROR_REPLY_MESSAGE_MISMATCH},  //! {Reply Message Mismatch} An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message.
		ErrorCodeName{"ERROR_LOST_WRITEBEHIND_DATA", ERROR_LOST_WRITEBEHIND_DATA},  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs. The data has been lost. This error may be caused by a failure of your computer hardware or network connection. Please try to save this file elsewhere.
		ErrorCodeName{"ERROR_CLIENT_SERVER_PARAMETERS_INVALID", ERROR_CLIENT_SERVER_PARAMETERS_INVALID},  //! The parameter(s) passed to the server in the client/server shared memory window were invalid. Too much data may have been put in the shared memory window.
		ErrorCodeName{"ERROR_NOT_TINY_STREAM", ERROR_NOT_TINY_STREAM},  //! The stream is not a tiny stream.
		ErrorCodeName{"ERROR_STACK_OVERFLOW_READ", ERROR_STACK_OVERFLOW_READ},  //! The request must be handled by the stack overflow code.
		ErrorCodeName{"ERROR_CONVERT_TO_LARGE", ERROR_CONVERT_TO_LARGE},  //! Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing onode is moved or the extent stream is converted to a large stream.
		ErrorCodeName{"ERROR_FOUND_OUT_OF_SCOPE", ERROR_FOUND_OUT_OF_SCOPE},  //! The attempt to find the object found an object matching by ID on the volume but it is out of the scope of the handle used for the operation.
		ErrorCodeName{"ERROR_ALLOCATE_BUCKET", ERROR_ALLOCATE_BUCKET},  //! The bucket array must be grown. Retry transaction after doing so.
		ErrorCodeName{"ERROR_MARSHALL_OVERFLOW", ERROR_MARSHALL_OVERFLOW},  //! The user/kernel marshalling buffer has overflowed.
		ErrorCodeName{"ERROR_INVALID_VARIANT", ERROR_INVALID_VARIANT},  //! The supplied variant structure contains invalid data.
		ErrorCodeName{"ERROR_BAD_COMPRESSION_BUFFER", ERROR_BAD_COMPRESSION_BUFFER},  //! The specified buffer contains ill-formed data.
		ErrorCodeName{"ERROR_AUDIT_FAILED", ERROR_AUDIT_FAILED},  //! {Audit Failed} An attempt to generate a security audit failed.
		ErrorCodeName{"ERROR_TIMER_RESOLUTION_NOT_SET", ERROR_TIMER_RESOLUTION_NOT_SET},  //! The timer resolution was not previously set by the current process.
		ErrorCodeName{"ERROR_INSUFFICIENT_LOGON_INFO", ERROR_INSUFFICIENT_LOGON_INFO},  //! There is insufficient account information to log you on.
		ErrorCodeName{"ERROR_BAD_DLL_ENTRYPOINT", ERROR_BAD_DLL_ENTRYPOINT},  //! {Invalid DLL Entrypoint} The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state. The entrypoint should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO may cause the application to operate incorrectly.
		ErrorCodeName{"ERROR_BAD_SERVICE_ENTRYPOINT", ERROR_BAD_SERVICE_ENTRYPOINT},  //! {Invalid Service Callback Entrypoint} The %hs service is not written correctly. The stack pointer has been left in an inconsistent state. The callback entrypoint should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process may operate incorrectly.
		ErrorCodeName{"ERROR_IP_ADDRESS_CONFLICT1", ERROR_IP_ADDRESS_CONFLICT1},  //! There is an IP address conflict with another system on the network.
		ErrorCodeName{"ERROR_IP_ADDRESS_CONFLICT2", ERROR_IP_ADDRESS_CONFLICT2},  //! There is an IP address conflict with another system on the network.
		ErrorCodeName{"ERROR_REGISTRY_QUOTA_LIMIT", ERROR_REGISTRY_QUOTA_LIMIT},  //! {Low On Registry Space} The system has reached the maximum size allowed for the system part of the registry. Additional storage requests will be ignored.
		ErrorCodeName{"ERROR_NO_CALLBACK_ACTIVE", ERROR_NO_CALLBACK_ACTIVE},  //! A callback return system service cannot be executed when no callback is active.
		ErrorCodeName{"ERROR_PWD_TOO_SHORT", ERROR_PWD_TOO_SHORT},  //! The password provided is too short to meet the policy of your user account. Please choose a longer password.
		ErrorCodeName{"ERROR_PWD_TOO_RECENT", ERROR_PWD_TOO_RECENT},  //! The policy of your user account does not allow you to change passwords too frequently. This is done to prevent users from changing back to a familiar, but potentially discovered, password. If you feel your password has been compromised then please contact your administrator immediately to have a new one assigned.
		ErrorCodeName{"ERROR_PWD_HISTORY_CONFLICT", ERROR_PWD_HISTORY_CONFLICT},  //! You have attempted to change your password to one that you have used in the past. The policy of your user account does not allow this. Please select a password that you have not previously used.
		ErrorCodeName{"ERROR_UNSUPPORTED_COMPRESSION", ERROR_UNSUPPORTED_COMPRESSION},  //! The specified compression format is unsupported.
		ErrorCodeName{"ERROR_INVALID_HW_PROFILE", ERROR_INVALID_HW_PROFILE},  //! The specified hardware profile configuration is invalid.
		ErrorCodeName{"ERROR_INVALID_PLUGPLAY_DEVICE_PATH", ERROR_INVALID_PLUGPLAY_DEVICE_PATH},  //! The specified Plug and Play registry device path is invalid.
		ErrorCodeName{"ERROR_QUOTA_LIST_INCONSISTENT", ERROR_QUOTA_LIST_INCONSISTENT},  //! The specified quota list is internally inconsistent with its descriptor.
		ErrorCodeName{"ERROR_EVALUATION_EXPIRATION", ERROR_EVALUATION_EXPIRATION},  //! {Windows Evaluation Notification} The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, please upgrade this installation using a licensed distribution of this product.
		ErrorCodeName{"ERROR_ILLEGAL_DLL_RELOCATION", ERROR_ILLEGAL_DLL_RELOCATION},  //! {Illegal System DLL Relocation} The system DLL %hs was relocated in memory. The application will not run properly. The relocation occurred because the DLL %hs occupied an address range reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL.
		ErrorCodeName{"ERROR_DLL_INIT_FAILED_LOGOFF", ERROR_DLL_INIT_FAILED_LOGOFF},  //! {DLL Initialization Failed} The application failed to initialize because the window station is shutting down.
		ErrorCodeName{"ERROR_VALIDATE_CONTINUE", ERROR_VALIDATE_CONTINUE},  //! The validation process needs to continue on to the next step.
		ErrorCodeName{"ERROR_NO_MORE_MATCHES", ERROR_NO_MORE_MATCHES},  //! There are no more matches for the current index enumeration.
		ErrorCodeName{"ERROR_RANGE_LIST_CONFLICT", ERROR_RANGE_LIST_CONFLICT},  //! The range could not be added to the range list because of a conflict.
		ErrorCodeName{"ERROR_SERVER_SID_MISMATCH", ERROR_SERVER_SID_MISMATCH},  //! The server process is running under a SID different than that required by client.
		ErrorCodeName{"ERROR_CANT_ENABLE_DENY_ONLY", ERROR_CANT_ENABLE_DENY_ONLY},  //! A group marked use for deny only cannot be enabled.
		ErrorCodeName{"ERROR_FLOAT_MULTIPLE_FAULTS", ERROR_FLOAT_MULTIPLE_FAULTS},  //! {EXCEPTION} Multiple floating point faults.
		ErrorCodeName{"ERROR_FLOAT_MULTIPLE_TRAPS", ERROR_FLOAT_MULTIPLE_TRAPS},  //! {EXCEPTION} Multiple floating point traps.
		ErrorCodeName{"ERROR_NOINTERFACE", ERROR_NOINTERFACE},  //! The requested interface is not supported.
		ErrorCodeName{"ERROR_DRIVER_FAILED_SLEEP", ERROR_DRIVER_FAILED_SLEEP},  //! {System Standby Failed} The driver %hs does not support standby mode. Updating this driver may allow the system to go to standby mode.
		ErrorCodeName{"ERROR_CORRUPT_SYSTEM_FILE", ERROR_CORRUPT_SYSTEM_FILE},  //! The system file %1 has become corrupt and has been replaced.
		ErrorCodeName{"ERROR_COMMITMENT_MINIMUM", ERROR_COMMITMENT_MINIMUM},  //! {Virtual Memory Minimum Too Low} Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file. During this process, memory requests for some applications may be denied. For more information, see Help.
		ErrorCodeName{"ERROR_PNP_RESTART_ENUMERATION", ERROR_PNP_RESTART_ENUMERATION},  //! A device was removed so enumeration must be restarted.
		ErrorCodeName{"ERROR_SYSTEM_IMAGE_BAD_SIGNATURE", ERROR_SYSTEM_IMAGE_BAD_SIGNATURE},  //! {Fatal System Error} The system image %s is not properly signed. The file has been replaced with the signed file. The system has been shut down.
		ErrorCodeName{"ERROR_PNP_REBOOT_REQUIRED", ERROR_PNP_REBOOT_REQUIRED},  //! Device will not start without a reboot.
		ErrorCodeName{"ERROR_INSUFFICIENT_POWER", ERROR_INSUFFICIENT_POWER},  //! There is not enough power to complete the requested operation.
		ErrorCodeName{"ERROR_MULTIPLE_FAULT_VIOLATION", ERROR_MULTIPLE_FAULT_VIOLATION},  //! ERROR_MULTIPLE_FAULT_VIOLATION
		ErrorCodeName{"ERROR_SYSTEM_SHUTDOWN", ERROR_SYSTEM_SHUTDOWN},  //! The system is in the process of shutting down.
		ErrorCodeName{"ERROR_PORT_NOT_SET", ERROR_PORT_NOT_SET},  //! An attempt to remove a processes DebugPort was made, but a port was not already associated with the process.
		ErrorCodeName{"ERROR_DS_VERSION_CHECK_FAILURE", ERROR_DS_VERSION_CHECK_FAILURE},  //! This version of Windows is not compatible with the behavior version of directory forest, domain or domain controller.
		ErrorCodeName{"ERROR_RANGE_NOT_FOUND", ERROR_RANGE_NOT_FOUND},  //! The specified range could not be found in the range list.
		ErrorCodeName{"ERROR_NOT_SAFE_MODE_DRIVER", ERROR_NOT_SAFE_MODE_DRIVER},  //! The driver was not loaded because the system is booting into safe mode.
		ErrorCodeName{"ERROR_FAILED_DRIVER_ENTRY", ERROR_FAILED_DRIVER_ENTRY},  //! The driver was not loaded because it failed its initialization call.
		ErrorCodeName{"ERROR_DEVICE_ENUMERATION_ERROR", ERROR_DEVICE_ENUMERATION_ERROR},  //! The "%hs" encountered an error while applying power or reading the device configuration. This may be caused by a failure of your hardware or by a poor connection.
		ErrorCodeName{"ERROR_MOUNT_POINT_NOT_RESOLVED", ERROR_MOUNT_POINT_NOT_RESOLVED},  //! The create operation failed because the name contained at least one mount point which resolves to a volume to which the specified device object is not attached.
		ErrorCodeName{"ERROR_INVALID_DEVICE_OBJECT_PARAMETER", ERROR_INVALID_DEVICE_OBJECT_PARAMETER},  //! The device object parameter is either not a valid device object or is not attached to the volume specified by the file name.
		ErrorCodeName{"ERROR_MCA_OCCURED", ERROR_MCA_OCCURED},  //! A Machine Check Error has occurred. Please check the system eventlog for additional information.
		ErrorCodeName{"ERROR_DRIVER_DATABASE_ERROR", ERROR_DRIVER_DATABASE_ERROR},  //! There was error [%2] processing the driver database.
		ErrorCodeName{"ERROR_SYSTEM_HIVE_TOO_LARGE", ERROR_SYSTEM_HIVE_TOO_LARGE},  //! System hive size has exceeded its limit.
		ErrorCodeName{"ERROR_DRIVER_FAILED_PRIOR_UNLOAD", ERROR_DRIVER_FAILED_PRIOR_UNLOAD},  //! The driver could not be loaded because a previous version of the driver is still in memory.
		ErrorCodeName{"ERROR_VOLSNAP_PREPARE_HIBERNATE", ERROR_VOLSNAP_PREPARE_HIBERNATE},  //! {Volume Shadow Copy Service} Please wait while the Volume Shadow Copy Service prepares volume %hs for hibernation.
		ErrorCodeName{"ERROR_HIBERNATION_FAILURE", ERROR_HIBERNATION_FAILURE},  //! The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted.
		ErrorCodeName{"ERROR_PWD_TOO_LONG", ERROR_PWD_TOO_LONG},  //! The password provided is too long to meet the policy of your user account. Please choose a shorter password.
		ErrorCodeName{"ERROR_FILE_SYSTEM_LIMITATION", ERROR_FILE_SYSTEM_LIMITATION},  //! The requested operation could not be completed due to a file system limitation.
		ErrorCodeName{"ERROR_ASSERTION_FAILURE", ERROR_ASSERTION_FAILURE},  //! An assertion failure has occurred.
		ErrorCodeName{"ERROR_ACPI_ERROR", ERROR_ACPI_ERROR},  //! An error occurred in the ACPI subsystem.
		ErrorCodeName{"ERROR_WOW_ASSERTION", ERROR_WOW_ASSERTION},  //! WOW Assertion Error.
		ErrorCodeName{"ERROR_PNP_BAD_MPS_TABLE", ERROR_PNP_BAD_MPS_TABLE},  //! A device is missing in the system BIOS MPS table. This device will not be used. Please contact your system vendor for system BIOS update.
		ErrorCodeName{"ERROR_PNP_TRANSLATION_FAILED", ERROR_PNP_TRANSLATION_FAILED},  //! A translator failed to translate resources.
		ErrorCodeName{"ERROR_PNP_IRQ_TRANSLATION_FAILED", ERROR_PNP_IRQ_TRANSLATION_FAILED},  //! A IRQ translator failed to translate resources.
		ErrorCodeName{"ERROR_PNP_INVALID_ID", ERROR_PNP_INVALID_ID},  //! Driver %2 returned invalid ID for a child device (%3).
		ErrorCodeName{"ERROR_WAKE_SYSTEM_DEBUGGER", ERROR_WAKE_SYSTEM_DEBUGGER},  //! {Kernel Debugger Awakened} the system debugger was awakened by an interrupt.
		ErrorCodeName{"ERROR_HANDLES_CLOSED", ERROR_HANDLES_CLOSED},  //! {Handles Closed} Handles to objects have been automatically closed as a result of the requested operation.
		ErrorCodeName{"ERROR_EXTRANEOUS_INFORMATION", ERROR_EXTRANEOUS_INFORMATION},  //! {Too Much Information} The specified access control list (ACL) contained more information than was expected.
		ErrorCodeName{"ERROR_RXACT_COMMIT_NECESSARY", ERROR_RXACT_COMMIT_NECESSARY},  //! This warning level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has NOT been completed, but has not been rolled back either (so it may still be committed if desired).
		ErrorCodeName{"ERROR_MEDIA_CHECK", ERROR_MEDIA_CHECK},  //! {Media Changed} The media may have changed.
		ErrorCodeName{"ERROR_GUID_SUBSTITUTION_MADE", ERROR_GUID_SUBSTITUTION_MADE},  //! {GUID Substitution} During the translation of a global identifier (GUID) to a Windows security ID (SID), no administratively-defined GUID prefix was found. A substitute prefix was used, which will not compromise system security. However, this may provide a more restrictive access than intended.
		ErrorCodeName{"ERROR_STOPPED_ON_SYMLINK", ERROR_STOPPED_ON_SYMLINK},  //! The create operation stopped after reaching a symbolic link.
		ErrorCodeName{"ERROR_LONGJUMP", ERROR_LONGJUMP},  //! A long jump has been executed.
		ErrorCodeName{"ERROR_PLUGPLAY_QUERY_VETOED", ERROR_PLUGPLAY_QUERY_VETOED},  //! The Plug and Play query operation was not successful.
		ErrorCodeName{"ERROR_UNWIND_CONSOLIDATE", ERROR_UNWIND_CONSOLIDATE},  //! A frame consolidation has been executed.
		ErrorCodeName{"ERROR_REGISTRY_HIVE_RECOVERED", ERROR_REGISTRY_HIVE_RECOVERED},  //! {Registry Hive Recovered} Registry hive (file): %hs was corrupted and it has been recovered. Some data might have been lost.
		ErrorCodeName{"ERROR_DLL_MIGHT_BE_INSECURE", ERROR_DLL_MIGHT_BE_INSECURE},  //! The application is attempting to run executable code from the module %hs. This may be insecure. An alternative, %hs, is available. Should the application use the secure module %hs?
		ErrorCodeName{"ERROR_DLL_MIGHT_BE_INCOMPATIBLE", ERROR_DLL_MIGHT_BE_INCOMPATIBLE},  //! The application is loading executable code from the module %hs. This is secure, but may be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs?
		ErrorCodeName{"ERROR_DBG_EXCEPTION_NOT_HANDLED", ERROR_DBG_EXCEPTION_NOT_HANDLED},  //! Debugger did not handle the exception.
		ErrorCodeName{"ERROR_DBG_REPLY_LATER", ERROR_DBG_REPLY_LATER},  //! Debugger will reply later.
		ErrorCodeName{"ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE", ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE},  //! Debugger cannot provide handle.
		ErrorCodeName{"ERROR_DBG_TERMINATE_THREAD", ERROR_DBG_TERMINATE_THREAD},  //! Debugger terminated thread.
		ErrorCodeName{"ERROR_DBG_TERMINATE_PROCESS", ERROR_DBG_TERMINATE_PROCESS},  //! Debugger terminated process.
		ErrorCodeName{"ERROR_DBG_CONTROL_C", ERROR_DBG_CONTROL_C},  //! Debugger got control C.
		ErrorCodeName{"ERROR_DBG_PRINTEXCEPTION_C", ERROR_DBG_PRINTEXCEPTION_C},  //! Debugger printed exception on control C.
		ErrorCodeName{"ERROR_DBG_RIPEXCEPTION", ERROR_DBG_RIPEXCEPTION},  //! Debugger received RIP exception.
		ErrorCodeName{"ERROR_DBG_CONTROL_BREAK", ERROR_DBG_CONTROL_BREAK},  //! Debugger received control break.
		ErrorCodeName{"ERROR_DBG_COMMAND_EXCEPTION", ERROR_DBG_COMMAND_EXCEPTION},  //! Debugger command communication exception.
		ErrorCodeName{"ERROR_OBJECT_NAME_EXISTS", ERROR_OBJECT_NAME_EXISTS},  //! {Object Exists} An attempt was made to create an object and the object name already existed.
		ErrorCodeName{"ERROR_THREAD_WAS_SUSPENDED", ERROR_THREAD_WAS_SUSPENDED},  //! {Thread Suspended} A thread termination occurred while the thread was suspended. The thread was resumed, and termination proceeded.
		ErrorCodeName{"ERROR_IMAGE_NOT_AT_BASE", ERROR_IMAGE_NOT_AT_BASE},  //! {Image Relocated} An image file could not be mapped at the address specified in the image file. Local fixups must be performed on this image.
		ErrorCodeName{"ERROR_RXACT_STATE_CREATED", ERROR_RXACT_STATE_CREATED},  //! This informational level status indicates that a specified registry sub-tree transaction state did not yet exist and had to be created.
		ErrorCodeName{"ERROR_SEGMENT_NOTIFICATION", ERROR_SEGMENT_NOTIFICATION},  //! {Segment Load} A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image. An exception is raised so a debugger can load, unload or track symbols and breakpoints within these 16-bit segments.
		ErrorCodeName{"ERROR_BAD_CURRENT_DIRECTORY", ERROR_BAD_CURRENT_DIRECTORY},  //! {Invalid Current Directory} The process cannot switch to the startup current directory %hs. Select OK to set current directory to %hs, or select CANCEL to exit.
		ErrorCodeName{"ERROR_FT_READ_RECOVERY_FROM_BACKUP", ERROR_FT_READ_RECOVERY_FROM_BACKUP},  //! {Redundant Read} To satisfy a read request, the NT fault-tolerant file system successfully read the requested data from a redundant copy. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was unable to reassign the failing area of the device.
		ErrorCodeName{"ERROR_FT_WRITE_RECOVERY", ERROR_FT_WRITE_RECOVERY},  //! {Redundant Write} To satisfy a write request, the NT fault-tolerant file system successfully wrote a redundant copy of the information. This was done because the file system encountered a failure on a member of the fault-tolerant volume, but was not able to reassign the failing area of the device.
		ErrorCodeName{"ERROR_IMAGE_MACHINE_TYPE_MISMATCH", ERROR_IMAGE_MACHINE_TYPE_MISMATCH},  //! {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load.
		ErrorCodeName{"ERROR_RECEIVE_PARTIAL", ERROR_RECEIVE_PARTIAL},  //! {Partial Data Received} The network transport returned partial data to its client. The remaining data will be sent later.
		ErrorCodeName{"ERROR_RECEIVE_EXPEDITED", ERROR_RECEIVE_EXPEDITED},  //! {Expedited Data Received} The network transport returned data to its client that was marked as expedited by the remote system.
		ErrorCodeName{"ERROR_RECEIVE_PARTIAL_EXPEDITED", ERROR_RECEIVE_PARTIAL_EXPEDITED},  //! {Partial Expedited Data Received} The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later.
		ErrorCodeName{"ERROR_EVENT_DONE", ERROR_EVENT_DONE},  //! {TDI Event Done} The TDI indication has completed successfully.
		ErrorCodeName{"ERROR_EVENT_PENDING", ERROR_EVENT_PENDING},  //! {TDI Event Pending} The TDI indication has entered the pending state.
		ErrorCodeName{"ERROR_CHECKING_FILE_SYSTEM", ERROR_CHECKING_FILE_SYSTEM},  //! Checking file system on %wZ.
		ErrorCodeName{"ERROR_FATAL_APP_EXIT", ERROR_FATAL_APP_EXIT},  //! {Fatal Application Exit} %hs.
		ErrorCodeName{"ERROR_PREDEFINED_HANDLE", ERROR_PREDEFINED_HANDLE},  //! The specified registry key is referenced by a predefined handle.
		ErrorCodeName{"ERROR_WAS_UNLOCKED", ERROR_WAS_UNLOCKED},  //! {Page Unlocked} The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process.
		ErrorCodeName{"ERROR_SERVICE_NOTIFICATION", ERROR_SERVICE_NOTIFICATION},  //! %hs
		ErrorCodeName{"ERROR_WAS_LOCKED", ERROR_WAS_LOCKED},  //! {Page Locked} One of the pages to lock was already locked.
		ErrorCodeName{"ERROR_LOG_HARD_ERROR", ERROR_LOG_HARD_ERROR},  //! Application popup: %1 : %2
		ErrorCodeName{"ERROR_ALREADY_WIN32", ERROR_ALREADY_WIN32},  //! ERROR_ALREADY_WIN32
		ErrorCodeName{"ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE", ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE},  //! {Machine Type Mismatch} The image file %hs is valid, but is for a machine type other than the current machine.
		ErrorCodeName{"ERROR_NO_YIELD_PERFORMED", ERROR_NO_YIELD_PERFORMED},  //! A yield execution was performed and no thread was available to run.
		ErrorCodeName{"ERROR_TIMER_RESUME_IGNORED", ERROR_TIMER_RESUME_IGNORED},  //! The resumable flag to a timer API was ignored.
		ErrorCodeName{"ERROR_ARBITRATION_UNHANDLED", ERROR_ARBITRATION_UNHANDLED},  //! The arbiter has deferred arbitration of these resources to its parent.
		ErrorCodeName{"ERROR_CARDBUS_NOT_SUPPORTED", ERROR_CARDBUS_NOT_SUPPORTED},  //! The inserted CardBus device cannot be started because of a configuration error on "%hs".
		ErrorCodeName{"ERROR_MP_PROCESSOR_MISMATCH", ERROR_MP_PROCESSOR_MISMATCH},  //! The CPUs in this multiprocessor system are not all the same revision level. To use all processors the operating system restricts itself to the features of the least capable processor in the system. Should problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported.
		ErrorCodeName{"ERROR_HIBERNATED", ERROR_HIBERNATED},  //! The system was put into hibernation.
		ErrorCodeName{"ERROR_RESUME_HIBERNATION", ERROR_RESUME_HIBERNATION},  //! The system was resumed from hibernation.
		ErrorCodeName{"ERROR_FIRMWARE_UPDATED", ERROR_FIRMWARE_UPDATED},  //! Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3].
		ErrorCodeName{"ERROR_DRIVERS_LEAKING_LOCKED_PAGES", ERROR_DRIVERS_LEAKING_LOCKED_PAGES},  //! A device driver is leaking locked I/O pages causing system degradation. The system has automatically enabled tracking code in order to try and catch the culprit.
		ErrorCodeName{"ERROR_WAKE_SYSTEM", ERROR_WAKE_SYSTEM},  //! The system has awoken.
		ErrorCodeName{"ERROR_WAIT_1", ERROR_WAIT_1},  //! ERROR_WAIT_1
		ErrorCodeName{"ERROR_WAIT_2", ERROR_WAIT_2},  //! ERROR_WAIT_2
		ErrorCodeName{"ERROR_WAIT_3", ERROR_WAIT_3},  //! ERROR_WAIT_3
		ErrorCodeName{"ERROR_WAIT_63", ERROR_WAIT_63},  //! ERROR_WAIT_63
		ErrorCodeName{"ERROR_ABANDONED_WAIT_0", ERROR_ABANDONED_WAIT_0},  //! ERROR_ABANDONED_WAIT_0
		ErrorCodeName{"ERROR_ABANDONED_WAIT_63", ERROR_ABANDONED_WAIT_63},  //! ERROR_ABANDONED_WAIT_63
		ErrorCodeName{"ERROR_USER_APC", ERROR_USER_APC},  //! ERROR_USER_APC
		ErrorCodeName{"ERROR_KERNEL_APC", ERROR_KERNEL_APC},  //! ERROR_KERNEL_APC
		ErrorCodeName{"ERROR_ALERTED", ERROR_ALERTED},  //! ERROR_ALERTED
		ErrorCodeName{"ERROR_ELEVATION_REQUIRED", ERROR_ELEVATION_REQUIRED},  //! The requested operation requires elevation.
		ErrorCodeName{"ERROR_REPARSE", ERROR_REPARSE},  //! A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
		ErrorCodeName{"ERROR_OPLOCK_BREAK_IN_PROGRESS", ERROR_OPLOCK_BREAK_IN_PROGRESS},  //! An open/create operation completed while an oplock break is underway.
		ErrorCodeName{"ERROR_VOLUME_MOUNTED", ERROR_VOLUME_MOUNTED},  //! A new volume has been mounted by a file system.
		ErrorCodeName{"ERROR_RXACT_COMMITTED", ERROR_RXACT_COMMITTED},  //! This success level status indicates that the transaction state already exists for the registry sub-tree, but that a transaction commit was previously aborted. The commit has now been completed.
		ErrorCodeName{"ERROR_NOTIFY_CLEANUP", ERROR_NOTIFY_CLEANUP},  //! This indicates that a notify change request has been completed due to closing the handle which made the notify change request.
		ErrorCodeName{"ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED", ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED},  //! {Connect Failure on Primary Transport} An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed. The computer WAS able to connect on a secondary transport.
		ErrorCodeName{"ERROR_PAGE_FAULT_TRANSITION", ERROR_PAGE_FAULT_TRANSITION},  //! Page fault was a transition fault.
		ErrorCodeName{"ERROR_PAGE_FAULT_DEMAND_ZERO", ERROR_PAGE_FAULT_DEMAND_ZERO},  //! Page fault was a demand zero fault.
		ErrorCodeName{"ERROR_PAGE_FAULT_COPY_ON_WRITE", ERROR_PAGE_FAULT_COPY_ON_WRITE},  //! Page fault was a demand zero fault.
		ErrorCodeName{"ERROR_PAGE_FAULT_GUARD_PAGE", ERROR_PAGE_FAULT_GUARD_PAGE},  //! Page fault was a demand zero fault.
		ErrorCodeName{"ERROR_PAGE_FAULT_PAGING_FILE", ERROR_PAGE_FAULT_PAGING_FILE},  //! Page fault was satisfied by reading from a secondary storage device.
		ErrorCodeName{"ERROR_CACHE_PAGE_LOCKED", ERROR_CACHE_PAGE_LOCKED},  //! Cached page was locked during operation.
		ErrorCodeName{"ERROR_CRASH_DUMP", ERROR_CRASH_DUMP},  //! Crash dump exists in paging file.
		ErrorCodeName{"ERROR_BUFFER_ALL_ZEROS", ERROR_BUFFER_ALL_ZEROS},  //! Specified buffer contains all zeros.
		ErrorCodeName{"ERROR_REPARSE_OBJECT", ERROR_REPARSE_OBJECT},  //! A reparse should be performed by the Object Manager since the name of the file resulted in a symbolic link.
		ErrorCodeName{"ERROR_RESOURCE_REQUIREMENTS_CHANGED", ERROR_RESOURCE_REQUIREMENTS_CHANGED},  //! The device has succeeded a query-stop and its resource requirements have changed.
		ErrorCodeName{"ERROR_TRANSLATION_COMPLETE", ERROR_TRANSLATION_COMPLETE},  //! The translator has translated these resources into the global space and no further translations should be performed.
		ErrorCodeName{"ERROR_NOTHING_TO_TERMINATE", ERROR_NOTHING_TO_TERMINATE},  //! A process being terminated has no threads to terminate.
		ErrorCodeName{"ERROR_PROCESS_NOT_IN_JOB", ERROR_PROCESS_NOT_IN_JOB},  //! The specified process is not part of a job.
		ErrorCodeName{"ERROR_PROCESS_IN_JOB", ERROR_PROCESS_IN_JOB},  //! The specified process is part of a job.
		ErrorCodeName{"ERROR_VOLSNAP_HIBERNATE_READY", ERROR_VOLSNAP_HIBERNATE_READY},  //! {Volume Shadow Copy Service} The system is now ready for hibernation.
		ErrorCodeName{"ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY", ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY},  //! A file system or file system filter driver has successfully completed an FsFilter operation.
		ErrorCodeName{"ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED", ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED},  //! The specified interrupt vector was already connected.
		ErrorCodeName{"ERROR_INTERRUPT_STILL_CONNECTED", ERROR_INTERRUPT_STILL_CONNECTED},  //! The specified interrupt vector is still connected.
		ErrorCodeName{"ERROR_WAIT_FOR_OPLOCK", ERROR_WAIT_FOR_OPLOCK},  //! An operation is blocked waiting for an oplock.
		ErrorCodeName{"ERROR_DBG_EXCEPTION_HANDLED", ERROR_DBG_EXCEPTION_HANDLED},  //! Debugger handled exception.
		ErrorCodeName{"ERROR_DBG_CONTINUE", ERROR_DBG_CONTINUE},  //! Debugger continued.
		ErrorCodeName{"ERROR_CALLBACK_POP_STACK", ERROR_CALLBACK_POP_STACK},  //! An exception occurred in a user mode callback and the kernel callback frame should be removed.
		ErrorCodeName{"ERROR_COMPRESSION_DISABLED", ERROR_COMPRESSION_DISABLED},  //! Compression is disabled for this volume.
		ErrorCodeName{"ERROR_CANTFETCHBACKWARDS", ERROR_CANTFETCHBACKWARDS},  //! The data provider cannot fetch backwards through a result set.
		ErrorCodeName{"ERROR_CANTSCROLLBACKWARDS", ERROR_CANTSCROLLBACKWARDS},  //! The data provider cannot scroll backwards through a result set.
		ErrorCodeName{"ERROR_ROWSNOTRELEASED", ERROR_ROWSNOTRELEASED},  //! The data provider requires that previously fetched data is released before asking for more data.
		ErrorCodeName{"ERROR_BAD_ACCESSOR_FLAGS", ERROR_BAD_ACCESSOR_FLAGS},  //! The data provider was not able to interpret the flags set for a column binding in an accessor.
		ErrorCodeName{"ERROR_ERRORS_ENCOUNTERED", ERROR_ERRORS_ENCOUNTERED},  //! One or more errors occurred while processing the request.
		ErrorCodeName{"ERROR_NOT_CAPABLE", ERROR_NOT_CAPABLE},  //! The implementation is not capable of performing the request.
		ErrorCodeName{"ERROR_REQUEST_OUT_OF_SEQUENCE", ERROR_REQUEST_OUT_OF_SEQUENCE},  //! The client of a component requested an operation which is not valid given the state of the component instance.
		ErrorCodeName{"ERROR_VERSION_PARSE_ERROR", ERROR_VERSION_PARSE_ERROR},  //! A version number could not be parsed.
		ErrorCodeName{"ERROR_BADSTARTPOSITION", ERROR_BADSTARTPOSITION},  //! The iterator's start position is invalid.
		ErrorCodeName{"ERROR_MEMORY_HARDWARE", ERROR_MEMORY_HARDWARE},  //! The hardware has reported an uncorrectable memory error.
		ErrorCodeName{"ERROR_DISK_REPAIR_DISABLED", ERROR_DISK_REPAIR_DISABLED},  //! The attempted operation required self healing to be enabled.
		ErrorCodeName{"ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE", ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE},  //! The Desktop heap encountered an error while allocating session memory. There is more information in the system event log.
		ErrorCodeName{"ERROR_SYSTEM_POWERSTATE_TRANSITION", ERROR_SYSTEM_POWERSTATE_TRANSITION},  //! The system power state is transitioning from %2 to %3.
		ErrorCodeName{"ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION", ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION},  //! The system power state is transitioning from %2 to %3 but could enter %4.
		ErrorCodeName{"ERROR_MCA_EXCEPTION", ERROR_MCA_EXCEPTION},  //! A thread is getting dispatched with MCA EXCEPTION because of MCA.
		ErrorCodeName{"ERROR_ACCESS_AUDIT_BY_POLICY", ERROR_ACCESS_AUDIT_BY_POLICY},  //! Access to %1 is monitored by policy rule %2.
		ErrorCodeName{"ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY", ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY},  //! Access to %1 has been restricted by your Administrator by policy rule %2.
		ErrorCodeName{"ERROR_ABANDON_HIBERFILE", ERROR_ABANDON_HIBERFILE},  //! A valid hibernation file has been invalidated and should be abandoned.
		ErrorCodeName{"ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED", ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED},  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error may be caused by network connectivity issues. Please try to save this file elsewhere.
		ErrorCodeName{"ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR", ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR},  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error was returned by the server on which the file exists. Please try to save this file elsewhere.
		ErrorCodeName{"ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR", ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR},  //! {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error may be caused if the device has been removed or the media is write-protected.
		ErrorCodeName{"ERROR_BAD_MCFG_TABLE", ERROR_BAD_MCFG_TABLE},  //! The resources required for this device conflict with the MCFG table.
		ErrorCodeName{"ERROR_DISK_REPAIR_REDIRECTED", ERROR_DISK_REPAIR_REDIRECTED},  //! The volume repair could not be performed while it is online. Please schedule to take the volume offline so that it can be repaired.
		ErrorCodeName{"ERROR_DISK_REPAIR_UNSUCCESSFUL", ERROR_DISK_REPAIR_UNSUCCESSFUL},  //! The volume repair was not successful.
		ErrorCodeName{"ERROR_CORRUPT_LOG_OVERFULL", ERROR_CORRUPT_LOG_OVERFULL},  //! One of the volume corruption logs is full. Further corruptions that may be detected won't be logged.
		ErrorCodeName{"ERROR_CORRUPT_LOG_CORRUPTED", ERROR_CORRUPT_LOG_CORRUPTED},  //! One of the volume corruption logs is internally corrupted and needs to be recreated. The volume may contain undetected corruptions and must be scanned.
		ErrorCodeName{"ERROR_CORRUPT_LOG_UNAVAILABLE", ERROR_CORRUPT_LOG_UNAVAILABLE},  //! One of the volume corruption logs is unavailable for being operated on.
		ErrorCodeName{"ERROR_CORRUPT_LOG_DELETED_FULL", ERROR_CORRUPT_LOG_DELETED_FULL},  //! One of the volume corruption logs was deleted while still having corruption records in them. The volume contains detected corruptions and must be scanned.
		ErrorCodeName{"ERROR_CORRUPT_LOG_CLEARED", ERROR_CORRUPT_LOG_CLEARED},  //! One of the volume corruption logs was cleared by chkdsk and no longer contains real corruptions.
		ErrorCodeName{"ERROR_ORPHAN_NAME_EXHAUSTED", ERROR_ORPHAN_NAME_EXHAUSTED},  //! Orphaned files exist on the volume but could not be recovered because no more new names could be created in the recovery directory. Files must be moved from the recovery directory.
		ErrorCodeName{"ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE", ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE},  //! The oplock that was associated with this handle is now associated with a different handle.
		ErrorCodeName{"ERROR_CANNOT_GRANT_REQUESTED_OPLOCK", ERROR_CANNOT_GRANT_REQUESTED_OPLOCK},  //! An oplock of the requested level cannot be granted. An oplock of a lower level may be available.
		ErrorCodeName{"ERROR_CANNOT_BREAK_OPLOCK", ERROR_CANNOT_BREAK_OPLOCK},  //! The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken.
		ErrorCodeName{"ERROR_OPLOCK_HANDLE_CLOSED", ERROR_OPLOCK_HANDLE_CLOSED},  //! The handle with which this oplock was associated has been closed. The oplock is now broken.
		ErrorCodeName{"ERROR_NO_ACE_CONDITION", ERROR_NO_ACE_CONDITION},  //! The specified access control entry (ACE) does not contain a condition.
		ErrorCodeName{"ERROR_INVALID_ACE_CONDITION", ERROR_INVALID_ACE_CONDITION},  //! The specified access control entry (ACE) contains an invalid condition.
		ErrorCodeName{"ERROR_FILE_HANDLE_REVOKED", ERROR_FILE_HANDLE_REVOKED},  //! Access to the specified file handle has been revoked.
		ErrorCodeName{"ERROR_IMAGE_AT_DIFFERENT_BASE", ERROR_IMAGE_AT_DIFFERENT_BASE},  //! An image file was mapped at a different address from the one specified in the image file but fixups will still be automatically performed on the image.
		ErrorCodeName{"ERROR_EA_ACCESS_DENIED", ERROR_EA_ACCESS_DENIED},  //! Access to the extended attribute was denied.
		ErrorCodeName{"ERROR_OPERATION_ABORTED", ERROR_OPERATION_ABORTED},  //! The I/O operation has been aborted because of either a thread exit or an application request.
		ErrorCodeName{"ERROR_IO_INCOMPLETE", ERROR_IO_INCOMPLETE},  //! Overlapped I/O event is not in a signaled state.
		ErrorCodeName{"ERROR_IO_PENDING", ERROR_IO_PENDING},  //! Overlapped I/O operation is in progress.
		ErrorCodeName{"ERROR_NOACCESS", ERROR_NOACCESS},  //! Invalid access to memory location.
		ErrorCodeName{"ERROR_SWAPERROR", ERROR_SWAPERROR},  //! Error performing inpage operation.
		ErrorCodeName{"ERROR_STACK_OVERFLOW", ERROR_STACK_OVERFLOW},  //! Recursion too deep; the stack overflowed.
		ErrorCodeName{"ERROR_INVALID_MESSAGE", ERROR_INVALID_MESSAGE},  //! The window cannot act on the sent message.
		ErrorCodeName{"ERROR_CAN_NOT_COMPLETE", ERROR_CAN_NOT_COMPLETE},  //! Cannot complete this function.
		ErrorCodeName{"ERROR_INVALID_FLAGS", ERROR_INVALID_FLAGS},  //! Invalid flags.
		ErrorCodeName{"ERROR_UNRECOGNIZED_VOLUME", ERROR_UNRECOGNIZED_VOLUME},  //! The volume does not contain a recognized file system. Please make sure that all required file system drivers are loaded and that the volume is not corrupted.
		ErrorCodeName{"ERROR_FILE_INVALID", ERROR_FILE_INVALID},  //! The volume for a file has been externally altered so that the opened file is no longer valid.
		ErrorCodeName{"ERROR_FULLSCREEN_MODE", ERROR_FULLSCREEN_MODE},  //! The requested operation cannot be performed in full-screen mode.
		ErrorCodeName{"ERROR_NO_TOKEN", ERROR_NO_TOKEN},  //! An attempt was made to reference a token that does not exist.
		ErrorCodeName{"ERROR_BADDB", ERROR_BADDB},  //! The configuration registry database is corrupt.
		ErrorCodeName{"ERROR_BADKEY", ERROR_BADKEY},  //! The configuration registry key is invalid.
		ErrorCodeName{"ERROR_CANTOPEN", ERROR_CANTOPEN},  //! The configuration registry key could not be opened.
		ErrorCodeName{"ERROR_CANTREAD", ERROR_CANTREAD},  //! The configuration registry key could not be read.
		ErrorCodeName{"ERROR_CANTWRITE", ERROR_CANTWRITE},  //! The configuration registry key could not be written.
		ErrorCodeName{"ERROR_REGISTRY_RECOVERED", ERROR_REGISTRY_RECOVERED},  //! One of the files in the registry database had to be recovered by use of a log or alternate copy. The recovery was successful.
		ErrorCodeName{"ERROR_REGISTRY_CORRUPT", ERROR_REGISTRY_CORRUPT},  //! The registry is corrupted. The structure of one of the files containing registry data is corrupted, or the system's memory image of the file is corrupted, or the file could not be recovered because the alternate copy or log was absent or corrupted.
		ErrorCodeName{"ERROR_REGISTRY_IO_FAILED", ERROR_REGISTRY_IO_FAILED},  //! An I/O operation initiated by the registry failed unrecoverably. The registry could not read in, or write out, or flush, one of the files that contain the system's image of the registry.
		ErrorCodeName{"ERROR_NOT_REGISTRY_FILE", ERROR_NOT_REGISTRY_FILE},  //! The system has attempted to load or restore a file into the registry, but the specified file is not in a registry file format.
		ErrorCodeName{"ERROR_KEY_DELETED", ERROR_KEY_DELETED},  //! Illegal operation attempted on a registry key that has been marked for deletion.
		ErrorCodeName{"ERROR_NO_LOG_SPACE", ERROR_NO_LOG_SPACE},  //! System could not allocate the required space in a registry log.
		ErrorCodeName{"ERROR_KEY_HAS_CHILDREN", ERROR_KEY_HAS_CHILDREN},  //! Cannot create a symbolic link in a registry key that already has subkeys or values.
		ErrorCodeName{"ERROR_CHILD_MUST_BE_VOLATILE", ERROR_CHILD_MUST_BE_VOLATILE},  //! Cannot create a stable subkey under a volatile parent key.
		ErrorCodeName{"ERROR_NOTIFY_ENUM_DIR", ERROR_NOTIFY_ENUM_DIR},  //! A notify change request is being completed and the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes.
		ErrorCodeName{"ERROR_DEPENDENT_SERVICES_RUNNING", ERROR_DEPENDENT_SERVICES_RUNNING},  //! A stop control has been sent to a service that other running services are dependent on.
		ErrorCodeName{"ERROR_INVALID_SERVICE_CONTROL", ERROR_INVALID_SERVICE_CONTROL},  //! The requested control is not valid for this service.
		ErrorCodeName{"ERROR_SERVICE_REQUEST_TIMEOUT", ERROR_SERVICE_REQUEST_TIMEOUT},  //! The service did not respond to the start or control request in a timely fashion.
		ErrorCodeName{"ERROR_SERVICE_NO_THREAD", ERROR_SERVICE_NO_THREAD},  //! A thread could not be created for the service.
		ErrorCodeName{"ERROR_SERVICE_DATABASE_LOCKED", ERROR_SERVICE_DATABASE_LOCKED},  //! The service database is locked.
		ErrorCodeName{"ERROR_SERVICE_ALREADY_RUNNING", ERROR_SERVICE_ALREADY_RUNNING},  //! An instance of the service is already running.
		ErrorCodeName{"ERROR_INVALID_SERVICE_ACCOUNT", ERROR_INVALID_SERVICE_ACCOUNT},  //! The account name is invalid or does not exist, or the password is invalid for the account name specified.
		ErrorCodeName{"ERROR_SERVICE_DISABLED", ERROR_SERVICE_DISABLED},  //! The service cannot be started, either because it is disabled or because it has no enabled devices associated with it.
		ErrorCodeName{"ERROR_CIRCULAR_DEPENDENCY", ERROR_CIRCULAR_DEPENDENCY},  //! Circular service dependency was specified.
		ErrorCodeName{"ERROR_SERVICE_DOES_NOT_EXIST", ERROR_SERVICE_DOES_NOT_EXIST},  //! The specified service does not exist as an installed service.
		ErrorCodeName{"ERROR_SERVICE_CANNOT_ACCEPT_CTRL", ERROR_SERVICE_CANNOT_ACCEPT_CTRL},  //! The service cannot accept control messages at this time.
		ErrorCodeName{"ERROR_SERVICE_NOT_ACTIVE", ERROR_SERVICE_NOT_ACTIVE},  //! The service has not been started.
		ErrorCodeName{"ERROR_FAILED_SERVICE_CONTROLLER_CONNECT", ERROR_FAILED_SERVICE_CONTROLLER_CONNECT},  //! The service process could not connect to the service controller.
		ErrorCodeName{"ERROR_EXCEPTION_IN_SERVICE", ERROR_EXCEPTION_IN_SERVICE},  //! An exception occurred in the service when handling the control request.
		ErrorCodeName{"ERROR_DATABASE_DOES_NOT_EXIST", ERROR_DATABASE_DOES_NOT_EXIST},  //! The database specified does not exist.
		ErrorCodeName{"ERROR_SERVICE_SPECIFIC_ERROR", ERROR_SERVICE_SPECIFIC_ERROR},  //! The service has returned a service-specific error code.
		ErrorCodeName{"ERROR_PROCESS_ABORTED", ERROR_PROCESS_ABORTED},  //! The process terminated unexpectedly.
		ErrorCodeName{"ERROR_SERVICE_DEPENDENCY_FAIL", ERROR_SERVICE_DEPENDENCY_FAIL},  //! The dependency service or group failed to start.
		ErrorCodeName{"ERROR_SERVICE_LOGON_FAILED", ERROR_SERVICE_LOGON_FAILED},  //! The service did not start due to a logon failure.
		ErrorCodeName{"ERROR_SERVICE_START_HANG", ERROR_SERVICE_START_HANG},  //! After starting, the service hung in a start-pending state.
		ErrorCodeName{"ERROR_INVALID_SERVICE_LOCK", ERROR_INVALID_SERVICE_LOCK},  //! The specified service database lock is invalid.
		ErrorCodeName{"ERROR_SERVICE_MARKED_FOR_DELETE", ERROR_SERVICE_MARKED_FOR_DELETE},  //! The specified service has been marked for deletion.
		ErrorCodeName{"ERROR_SERVICE_EXISTS", ERROR_SERVICE_EXISTS},  //! The specified service already exists.
		ErrorCodeName{"ERROR_ALREADY_RUNNING_LKG", ERROR_ALREADY_RUNNING_LKG},  //! The system is currently running with the last-known-good configuration.
		ErrorCodeName{"ERROR_SERVICE_DEPENDENCY_DELETED", ERROR_SERVICE_DEPENDENCY_DELETED},  //! The dependency service does not exist or has been marked for deletion.
		ErrorCodeName{"ERROR_BOOT_ALREADY_ACCEPTED", ERROR_BOOT_ALREADY_ACCEPTED},  //! The current boot has already been accepted for use as the last-known-good control set.
		ErrorCodeName{"ERROR_SERVICE_NEVER_STARTED", ERROR_SERVICE_NEVER_STARTED},  //! No attempts to start the service have been made since the last boot.
		ErrorCodeName{"ERROR_DUPLICATE_SERVICE_NAME", ERROR_DUPLICATE_SERVICE_NAME},  //! The name is already in use as either a service name or a service display name.
		ErrorCodeName{"ERROR_DIFFERENT_SERVICE_ACCOUNT", ERROR_DIFFERENT_SERVICE_ACCOUNT},  //! The account specified for this service is different from the account specified for other services running in the same process.
		ErrorCodeName{"ERROR_CANNOT_DETECT_DRIVER_FAILURE", ERROR_CANNOT_DETECT_DRIVER_FAILURE},  //! Failure actions can only be set for Win32 services, not for drivers.
		ErrorCodeName{"ERROR_CANNOT_DETECT_PROCESS_ABORT", ERROR_CANNOT_DETECT_PROCESS_ABORT},  //! This service runs in the same process as the service control manager. Therefore, the service control manager cannot take action if this service's process terminates unexpectedly.
		ErrorCodeName{"ERROR_NO_RECOVERY_PROGRAM", ERROR_NO_RECOVERY_PROGRAM},  //! No recovery program has been configured for this service.
		ErrorCodeName{"ERROR_SERVICE_NOT_IN_EXE", ERROR_SERVICE_NOT_IN_EXE},  //! The executable program that this service is configured to run in does not implement the service.
		ErrorCodeName{"ERROR_NOT_SAFEBOOT_SERVICE", ERROR_NOT_SAFEBOOT_SERVICE},  //! This service cannot be started in Safe Mode.
		ErrorCodeName{"ERROR_END_OF_MEDIA", ERROR_END_OF_MEDIA},  //! The physical end of the tape has been reached.
		ErrorCodeName{"ERROR_FILEMARK_DETECTED", ERROR_FILEMARK_DETECTED},  //! A tape access reached a filemark.
		ErrorCodeName{"ERROR_BEGINNING_OF_MEDIA", ERROR_BEGINNING_OF_MEDIA},  //! The beginning of the tape or a partition was encountered.
		ErrorCodeName{"ERROR_SETMARK_DETECTED", ERROR_SETMARK_DETECTED},  //! A tape access reached the end of a set of files.
		ErrorCodeName{"ERROR_NO_DATA_DETECTED", ERROR_NO_DATA_DETECTED},  //! No more data is on the tape.
		ErrorCodeName{"ERROR_PARTITION_FAILURE", ERROR_PARTITION_FAILURE},  //! Tape could not be partitioned.
		ErrorCodeName{"ERROR_INVALID_BLOCK_LENGTH", ERROR_INVALID_BLOCK_LENGTH},  //! When accessing a new tape of a multivolume partition, the current block size is incorrect.
		ErrorCodeName{"ERROR_DEVICE_NOT_PARTITIONED", ERROR_DEVICE_NOT_PARTITIONED},  //! Tape partition information could not be found when loading a tape.
		ErrorCodeName{"ERROR_UNABLE_TO_LOCK_MEDIA", ERROR_UNABLE_TO_LOCK_MEDIA},  //! Unable to lock the media eject mechanism.
		ErrorCodeName{"ERROR_UNABLE_TO_UNLOAD_MEDIA", ERROR_UNABLE_TO_UNLOAD_MEDIA},  //! Unable to unload the media.
		ErrorCodeName{"ERROR_MEDIA_CHANGED", ERROR_MEDIA_CHANGED},  //! The media in the drive may have changed.
		ErrorCodeName{"ERROR_BUS_RESET", ERROR_BUS_RESET},  //! The I/O bus was reset.
		ErrorCodeName{"ERROR_NO_MEDIA_IN_DRIVE", ERROR_NO_MEDIA_IN_DRIVE},  //! No media in drive.
		ErrorCodeName{"ERROR_NO_UNICODE_TRANSLATION", ERROR_NO_UNICODE_TRANSLATION},  //! No mapping for the Unicode character exists in the target multi-byte code page.
		ErrorCodeName{"ERROR_DLL_INIT_FAILED", ERROR_DLL_INIT_FAILED},  //! A dynamic link library (DLL) initialization routine failed.
		ErrorCodeName{"ERROR_SHUTDOWN_IN_PROGRESS", ERROR_SHUTDOWN_IN_PROGRESS},  //! A system shutdown is in progress.
		ErrorCodeName{"ERROR_NO_SHUTDOWN_IN_PROGRESS", ERROR_NO_SHUTDOWN_IN_PROGRESS},  //! Unable to abort the system shutdown because no shutdown was in progress.
		ErrorCodeName{"ERROR_IO_DEVICE", ERROR_IO_DEVICE},  //! The request could not be performed because of an I/O device error.
		ErrorCodeName{"ERROR_SERIAL_NO_DEVICE", ERROR_SERIAL_NO_DEVICE},  //! No serial device was successfully initialized. The serial driver will unload.
		ErrorCodeName{"ERROR_IRQ_BUSY", ERROR_IRQ_BUSY},  //! Unable to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened.
		ErrorCodeName{"ERROR_MORE_WRITES", ERROR_MORE_WRITES},  //! A serial I/O operation was completed by another write to the serial port. The IOCTL_SERIAL_XOFF_COUNTER reached zero.)
		ErrorCodeName{"ERROR_COUNTER_TIMEOUT", ERROR_COUNTER_TIMEOUT},  //! A serial I/O operation completed because the timeout period expired. The IOCTL_SERIAL_XOFF_COUNTER did not reach zero.)
		ErrorCodeName{"ERROR_FLOPPY_ID_MARK_NOT_FOUND", ERROR_FLOPPY_ID_MARK_NOT_FOUND},  //! No ID address mark was found on the floppy disk.
		ErrorCodeName{"ERROR_FLOPPY_WRONG_CYLINDER", ERROR_FLOPPY_WRONG_CYLINDER},  //! Mismatch between the floppy disk sector ID field and the floppy disk controller track address.
		ErrorCodeName{"ERROR_FLOPPY_UNKNOWN_ERROR", ERROR_FLOPPY_UNKNOWN_ERROR},  //! The floppy disk controller reported an error that is not recognized by the floppy disk driver.
		ErrorCodeName{"ERROR_FLOPPY_BAD_REGISTERS", ERROR_FLOPPY_BAD_REGISTERS},  //! The floppy disk controller returned inconsistent results in its registers.
		ErrorCodeName{"ERROR_DISK_RECALIBRATE_FAILED", ERROR_DISK_RECALIBRATE_FAILED},  //! While accessing the hard disk, a recalibrate operation failed, even after retries.
		ErrorCodeName{"ERROR_DISK_OPERATION_FAILED", ERROR_DISK_OPERATION_FAILED},  //! While accessing the hard disk, a disk operation failed even after retries.
		ErrorCodeName{"ERROR_DISK_RESET_FAILED", ERROR_DISK_RESET_FAILED},  //! While accessing the hard disk, a disk controller reset was needed, but even that failed.
		ErrorCodeName{"ERROR_EOM_OVERFLOW", ERROR_EOM_OVERFLOW},  //! Physical end of tape encountered.
		ErrorCodeName{"ERROR_NOT_ENOUGH_SERVER_MEMORY", ERROR_NOT_ENOUGH_SERVER_MEMORY},  //! Not enough server storage is available to process this command.
		ErrorCodeName{"ERROR_POSSIBLE_DEADLOCK", ERROR_POSSIBLE_DEADLOCK},  //! A potential deadlock condition has been detected.
		ErrorCodeName{"ERROR_MAPPED_ALIGNMENT", ERROR_MAPPED_ALIGNMENT},  //! The base address or the file offset specified does not have the proper alignment.
		ErrorCodeName{"ERROR_SET_POWER_STATE_VETOED", ERROR_SET_POWER_STATE_VETOED},  //! An attempt to change the system power state was vetoed by another application or driver.
		ErrorCodeName{"ERROR_SET_POWER_STATE_FAILED", ERROR_SET_POWER_STATE_FAILED},  //! The system BIOS failed an attempt to change the system power state.
		ErrorCodeName{"ERROR_TOO_MANY_LINKS", ERROR_TOO_MANY_LINKS},  //! An attempt was made to create more links on a file than the file system supports.
		ErrorCodeName{"ERROR_OLD_WIN_VERSION", ERROR_OLD_WIN_VERSION},  //! The specified program requires a newer version of Windows.
		ErrorCodeName{"ERROR_APP_WRONG_OS", ERROR_APP_WRONG_OS},  //! The specified program is not a Windows or MS-DOS program.
		ErrorCodeName{"ERROR_SINGLE_INSTANCE_APP", ERROR_SINGLE_INSTANCE_APP},  //! Cannot start more than one instance of the specified program.
		ErrorCodeName{"ERROR_RMODE_APP", ERROR_RMODE_APP},  //! The specified program was written for an earlier version of Windows.
		ErrorCodeName{"ERROR_INVALID_DLL", ERROR_INVALID_DLL},  //! One of the library files needed to run this application is damaged.
		ErrorCodeName{"ERROR_NO_ASSOCIATION", ERROR_NO_ASSOCIATION},  //! No application is associated with the specified file for this operation.
		ErrorCodeName{"ERROR_DDE_FAIL", ERROR_DDE_FAIL},  //! An error occurred in sending the command to the application.
		ErrorCodeName{"ERROR_DLL_NOT_FOUND", ERROR_DLL_NOT_FOUND},  //! One of the library files needed to run this application cannot be found.
		ErrorCodeName{"ERROR_NO_MORE_USER_HANDLES", ERROR_NO_MORE_USER_HANDLES},  //! The current process has used all of its system allowance of handles for Window Manager objects.
		ErrorCodeName{"ERROR_MESSAGE_SYNC_ONLY", ERROR_MESSAGE_SYNC_ONLY},  //! The message can be used only with synchronous operations.
		ErrorCodeName{"ERROR_SOURCE_ELEMENT_EMPTY", ERROR_SOURCE_ELEMENT_EMPTY},  //! The indicated source element has no media.
		ErrorCodeName{"ERROR_DESTINATION_ELEMENT_FULL", ERROR_DESTINATION_ELEMENT_FULL},  //! The indicated destination element already contains media.
		ErrorCodeName{"ERROR_ILLEGAL_ELEMENT_ADDRESS", ERROR_ILLEGAL_ELEMENT_ADDRESS},  //! The indicated element does not exist.
		ErrorCodeName{"ERROR_MAGAZINE_NOT_PRESENT", ERROR_MAGAZINE_NOT_PRESENT},  //! The indicated element is part of a magazine that is not present.
		ErrorCodeName{"ERROR_DEVICE_REINITIALIZATION_NEEDED", ERROR_DEVICE_REINITIALIZATION_NEEDED},  //! The indicated device requires reinitialization due to hardware errors.
		ErrorCodeName{"ERROR_DEVICE_REQUIRES_CLEANING", ERROR_DEVICE_REQUIRES_CLEANING},  //! The device has indicated that cleaning is required before further operations are attempted.
		ErrorCodeName{"ERROR_DEVICE_DOOR_OPEN", ERROR_DEVICE_DOOR_OPEN},  //! The device has indicated that its door is open.
		ErrorCodeName{"ERROR_DEVICE_NOT_CONNECTED", ERROR_DEVICE_NOT_CONNECTED},  //! The device is not connected.
		ErrorCodeName{"ERROR_NOT_FOUND", ERROR_NOT_FOUND},  //! Element not found.
		ErrorCodeName{"ERROR_NO_MATCH", ERROR_NO_MATCH},  //! There was no match for the specified key in the index.
		ErrorCodeName{"ERROR_SET_NOT_FOUND", ERROR_SET_NOT_FOUND},  //! The property set specified does not exist on the object.
		ErrorCodeName{"ERROR_POINT_NOT_FOUND", ERROR_POINT_NOT_FOUND},  //! The point passed to GetMouseMovePoints is not in the buffer.
		ErrorCodeName{"ERROR_NO_TRACKING_SERVICE", ERROR_NO_TRACKING_SERVICE},  //! The tracking (workstation) service is not running.
		ErrorCodeName{"ERROR_NO_VOLUME_ID", ERROR_NO_VOLUME_ID},  //! The Volume ID could not be found.
		ErrorCodeName{"ERROR_UNABLE_TO_REMOVE_REPLACED", ERROR_UNABLE_TO_REMOVE_REPLACED},  //! Unable to remove the file to be replaced.
		ErrorCodeName{"ERROR_UNABLE_TO_MOVE_REPLACEMENT", ERROR_UNABLE_TO_MOVE_REPLACEMENT},  //! Unable to move the replacement file to the file to be replaced. The file to be replaced has retained its original name.
		ErrorCodeName{"ERROR_UNABLE_TO_MOVE_REPLACEMENT_2", ERROR_UNABLE_TO_MOVE_REPLACEMENT_2},  //! Unable to move the replacement file to the file to be replaced. The file to be replaced has been renamed using the backup name.
		ErrorCodeName{"ERROR_JOURNAL_DELETE_IN_PROGRESS", ERROR_JOURNAL_DELETE_IN_PROGRESS},  //! The volume change journal is being deleted.
		ErrorCodeName{"ERROR_JOURNAL_NOT_ACTIVE", ERROR_JOURNAL_NOT_ACTIVE},  //! The volume change journal is not active.
		ErrorCodeName{"ERROR_POTENTIAL_FILE_FOUND", ERROR_POTENTIAL_FILE_FOUND},  //! A file was found, but it may not be the correct file.
		ErrorCodeName{"ERROR_JOURNAL_ENTRY_DELETED", ERROR_JOURNAL_ENTRY_DELETED},  //! The journal entry has been deleted from the journal.
		ErrorCodeName{"ERROR_SHUTDOWN_IS_SCHEDULED", ERROR_SHUTDOWN_IS_SCHEDULED},  //! A system shutdown has already been scheduled.
		ErrorCodeName{"ERROR_SHUTDOWN_USERS_LOGGED_ON", ERROR_SHUTDOWN_USERS_LOGGED_ON},  //! The system shutdown cannot be initiated because there are other users logged on to the computer.
		ErrorCodeName{"ERROR_BAD_DEVICE", ERROR_BAD_DEVICE},  //! The specified device name is invalid.
		ErrorCodeName{"ERROR_CONNECTION_UNAVAIL", ERROR_CONNECTION_UNAVAIL},  //! The device is not currently connected but it is a remembered connection.
		ErrorCodeName{"ERROR_DEVICE_ALREADY_REMEMBERED", ERROR_DEVICE_ALREADY_REMEMBERED},  //! The local device name has a remembered connection to another network resource.
		ErrorCodeName{"ERROR_NO_NET_OR_BAD_PATH", ERROR_NO_NET_OR_BAD_PATH},  //! The network path was either typed incorrectly, does not exist, or the network provider is not currently available. Please try retyping the path or contact your network administrator.
		ErrorCodeName{"ERROR_BAD_PROVIDER", ERROR_BAD_PROVIDER},  //! The specified network provider name is invalid.
		ErrorCodeName{"ERROR_CANNOT_OPEN_PROFILE", ERROR_CANNOT_OPEN_PROFILE},  //! Unable to open the network connection profile.
		ErrorCodeName{"ERROR_BAD_PROFILE", ERROR_BAD_PROFILE},  //! The network connection profile is corrupted.
		ErrorCodeName{"ERROR_NOT_CONTAINER", ERROR_NOT_CONTAINER},  //! Cannot enumerate a noncontainer.
		ErrorCodeName{"ERROR_EXTENDED_ERROR", ERROR_EXTENDED_ERROR},  //! An extended error has occurred.
		ErrorCodeName{"ERROR_INVALID_GROUPNAME", ERROR_INVALID_GROUPNAME},  //! The format of the specified group name is invalid.
		ErrorCodeName{"ERROR_INVALID_COMPUTERNAME", ERROR_INVALID_COMPUTERNAME},  //! The format of the specified computer name is invalid.
		ErrorCodeName{"ERROR_INVALID_EVENTNAME", ERROR_INVALID_EVENTNAME},  //! The format of the specified event name is invalid.
		ErrorCodeName{"ERROR_INVALID_DOMAINNAME", ERROR_INVALID_DOMAINNAME},  //! The format of the specified domain name is invalid.
		ErrorCodeName{"ERROR_INVALID_SERVICENAME", ERROR_INVALID_SERVICENAME},  //! The format of the specified service name is invalid.
		ErrorCodeName{"ERROR_INVALID_NETNAME", ERROR_INVALID_NETNAME},  //! The format of the specified network name is invalid.
		ErrorCodeName{"ERROR_INVALID_SHARENAME", ERROR_INVALID_SHARENAME},  //! The format of the specified share name is invalid.
		ErrorCodeName{"ERROR_INVALID_PASSWORDNAME", ERROR_INVALID_PASSWORDNAME},  //! The format of the specified password is invalid.
		ErrorCodeName{"ERROR_INVALID_MESSAGENAME", ERROR_INVALID_MESSAGENAME},  //! The format of the specified message name is invalid.
		ErrorCodeName{"ERROR_INVALID_MESSAGEDEST", ERROR_INVALID_MESSAGEDEST},  //! The format of the specified message destination is invalid.
		ErrorCodeName{"ERROR_SESSION_CREDENTIAL_CONFLICT", ERROR_SESSION_CREDENTIAL_CONFLICT},  //! Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again.
		ErrorCodeName{"ERROR_REMOTE_SESSION_LIMIT_EXCEEDED", ERROR_REMOTE_SESSION_LIMIT_EXCEEDED},  //! An attempt was made to establish a session to a network server, but there are already too many sessions established to that server.
		ErrorCodeName{"ERROR_DUP_DOMAINNAME", ERROR_DUP_DOMAINNAME},  //! The workgroup or domain name is already in use by another computer on the network.
		ErrorCodeName{"ERROR_NO_NETWORK", ERROR_NO_NETWORK},  //! The network is not present or not started.
		ErrorCodeName{"ERROR_CANCELLED", ERROR_CANCELLED},  //! The operation was canceled by the user.
		ErrorCodeName{"ERROR_USER_MAPPED_FILE", ERROR_USER_MAPPED_FILE},  //! The requested operation cannot be performed on a file with a user-mapped section open.
		ErrorCodeName{"ERROR_CONNECTION_REFUSED", ERROR_CONNECTION_REFUSED},  //! The remote computer refused the network connection.
		ErrorCodeName{"ERROR_GRACEFUL_DISCONNECT", ERROR_GRACEFUL_DISCONNECT},  //! The network connection was gracefully closed.
		ErrorCodeName{"ERROR_ADDRESS_ALREADY_ASSOCIATED", ERROR_ADDRESS_ALREADY_ASSOCIATED},  //! The network transport endpoint already has an address associated with it.
		ErrorCodeName{"ERROR_ADDRESS_NOT_ASSOCIATED", ERROR_ADDRESS_NOT_ASSOCIATED},  //! An address has not yet been associated with the network endpoint.
		ErrorCodeName{"ERROR_CONNECTION_INVALID", ERROR_CONNECTION_INVALID},  //! An operation was attempted on a nonexistent network connection.
		ErrorCodeName{"ERROR_CONNECTION_ACTIVE", ERROR_CONNECTION_ACTIVE},  //! An invalid operation was attempted on an active network connection.
		ErrorCodeName{"ERROR_NETWORK_UNREACHABLE", ERROR_NETWORK_UNREACHABLE},  //! The network location cannot be reached. For information about network troubleshooting, see Windows Help.
		ErrorCodeName{"ERROR_HOST_UNREACHABLE", ERROR_HOST_UNREACHABLE},  //! The network location cannot be reached. For information about network troubleshooting, see Windows Help.
		ErrorCodeName{"ERROR_PROTOCOL_UNREACHABLE", ERROR_PROTOCOL_UNREACHABLE},  //! The network location cannot be reached. For information about network troubleshooting, see Windows Help.
		ErrorCodeName{"ERROR_PORT_UNREACHABLE", ERROR_PORT_UNREACHABLE},  //! No service is operating at the destination network endpoint on the remote system.
		ErrorCodeName{"ERROR_REQUEST_ABORTED", ERROR_REQUEST_ABORTED},  //! The request was aborted.
		ErrorCodeName{"ERROR_CONNECTION_ABORTED", ERROR_CONNECTION_ABORTED},  //! The network connection was aborted by the local system.
		ErrorCodeName{"ERROR_RETRY", ERROR_RETRY},  //! The operation could not be completed. A retry should be performed.
		ErrorCodeName{"ERROR_CONNECTION_COUNT_LIMIT", ERROR_CONNECTION_COUNT_LIMIT},  //! A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached.
		ErrorCodeName{"ERROR_LOGIN_TIME_RESTRICTION", ERROR_LOGIN_TIME_RESTRICTION},  //! Attempting to log in during an unauthorized time of day for this account.
		ErrorCodeName{"ERROR_LOGIN_WKSTA_RESTRICTION", ERROR_LOGIN_WKSTA_RESTRICTION},  //! The account is not authorized to log in from this station.
		ErrorCodeName{"ERROR_INCORRECT_ADDRESS", ERROR_INCORRECT_ADDRESS},  //! The network address could not be used for the operation requested.
		ErrorCodeName{"ERROR_ALREADY_REGISTERED", ERROR_ALREADY_REGISTERED},  //! The service is already registered.
		ErrorCodeName{"ERROR_SERVICE_NOT_FOUND", ERROR_SERVICE_NOT_FOUND},  //! The specified service does not exist.
		ErrorCodeName{"ERROR_NOT_AUTHENTICATED", ERROR_NOT_AUTHENTICATED},  //! The operation being requested was not performed because the user has not been authenticated.
		ErrorCodeName{"ERROR_NOT_LOGGED_ON", ERROR_NOT_LOGGED_ON},  //! The operation being requested was not performed because the user has not logged on to the network. The specified service does not exist.
		ErrorCodeName{"ERROR_CONTINUE", ERROR_CONTINUE},  //! Continue with work in progress.
		ErrorCodeName{"ERROR_ALREADY_INITIALIZED", ERROR_ALREADY_INITIALIZED},  //! An attempt was made to perform an initialization operation when initialization has already been completed.
		ErrorCodeName{"ERROR_NO_MORE_DEVICES", ERROR_NO_MORE_DEVICES},  //! No more local devices.
		ErrorCodeName{"ERROR_NO_SUCH_SITE", ERROR_NO_SUCH_SITE},  //! The specified site does not exist.
		ErrorCodeName{"ERROR_DOMAIN_CONTROLLER_EXISTS", ERROR_DOMAIN_CONTROLLER_EXISTS},  //! A domain controller with the specified name already exists.
		ErrorCodeName{"ERROR_ONLY_IF_CONNECTED", ERROR_ONLY_IF_CONNECTED},  //! This operation is supported only when you are connected to the server.
		ErrorCodeName{"ERROR_OVERRIDE_NOCHANGES", ERROR_OVERRIDE_NOCHANGES},  //! The group policy framework should call the extension even if there are no changes.
		ErrorCodeName{"ERROR_BAD_USER_PROFILE", ERROR_BAD_USER_PROFILE},  //! The specified user does not have a valid profile.
		ErrorCodeName{"ERROR_NOT_SUPPORTED_ON_SBS", ERROR_NOT_SUPPORTED_ON_SBS},  //! This operation is not supported on a computer running Windows Server 2003 for Small Business Server.
		ErrorCodeName{"ERROR_SERVER_SHUTDOWN_IN_PROGRESS", ERROR_SERVER_SHUTDOWN_IN_PROGRESS},  //! The server machine is shutting down.
		ErrorCodeName{"ERROR_HOST_DOWN", ERROR_HOST_DOWN},  //! The remote system is not available. For information about network troubleshooting, see Windows Help.
		ErrorCodeName{"ERROR_NON_ACCOUNT_SID", ERROR_NON_ACCOUNT_SID},  //! The security identifier provided is not from an account domain.
		ErrorCodeName{"ERROR_NON_DOMAIN_SID", ERROR_NON_DOMAIN_SID},  //! The security identifier provided does not have a domain component.
		ErrorCodeName{"ERROR_APPHELP_BLOCK", ERROR_APPHELP_BLOCK},  //! AppHelp dialog canceled thus preventing the application from starting.
		ErrorCodeName{"ERROR_ACCESS_DISABLED_BY_POLICY", ERROR_ACCESS_DISABLED_BY_POLICY},  //! This program is blocked by group policy. For more information, contact your system administrator.
		ErrorCodeName{"ERROR_REG_NAT_CONSUMPTION", ERROR_REG_NAT_CONSUMPTION},  //! A program attempt to use an invalid register value. Normally caused by an uninitialized register. This error is Itanium specific.
		ErrorCodeName{"ERROR_CSCSHARE_OFFLINE", ERROR_CSCSHARE_OFFLINE},  //! The share is currently offline or does not exist.
		ErrorCodeName{"ERROR_PKINIT_FAILURE", ERROR_PKINIT_FAILURE},  //! The Kerberos protocol encountered an error while validating the KDC certificate during smartcard logon. There is more information in the system event log.
		ErrorCodeName{"ERROR_SMARTCARD_SUBSYSTEM_FAILURE", ERROR_SMARTCARD_SUBSYSTEM_FAILURE},  //! The Kerberos protocol encountered an error while attempting to utilize the smartcard subsystem.
		ErrorCodeName{"ERROR_DOWNGRADE_DETECTED", ERROR_DOWNGRADE_DETECTED},  //! The system cannot contact a domain controller to service the authentication request. Please try again later.
		ErrorCodeName{"ERROR_MACHINE_LOCKED", ERROR_MACHINE_LOCKED},  //! The machine is locked and cannot be shut down without the force option.
		ErrorCodeName{"ERROR_CALLBACK_SUPPLIED_INVALID_DATA", ERROR_CALLBACK_SUPPLIED_INVALID_DATA},  //! An application-defined callback gave invalid data when called.
		ErrorCodeName{"ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED", ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED},  //! The group policy framework should call the extension in the synchronous foreground policy refresh.
		ErrorCodeName{"ERROR_DRIVER_BLOCKED", ERROR_DRIVER_BLOCKED},  //! This driver has been blocked from loading.
		ErrorCodeName{"ERROR_INVALID_IMPORT_OF_NON_DLL", ERROR_INVALID_IMPORT_OF_NON_DLL},  //! A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image.
		ErrorCodeName{"ERROR_ACCESS_DISABLED_WEBBLADE", ERROR_ACCESS_DISABLED_WEBBLADE},  //! Windows cannot open this program since it has been disabled.
		ErrorCodeName{"ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER", ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER},  //! Windows cannot open this program because the license enforcement system has been tampered with or become corrupted.
		ErrorCodeName{"ERROR_RECOVERY_FAILURE", ERROR_RECOVERY_FAILURE},  //! A transaction recover failed.
		ErrorCodeName{"ERROR_ALREADY_FIBER", ERROR_ALREADY_FIBER},  //! The current thread has already been converted to a fiber.
		ErrorCodeName{"ERROR_ALREADY_THREAD", ERROR_ALREADY_THREAD},  //! The current thread has already been converted from a fiber.
		ErrorCodeName{"ERROR_STACK_BUFFER_OVERRUN", ERROR_STACK_BUFFER_OVERRUN},  //! The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application.
		ErrorCodeName{"ERROR_PARAMETER_QUOTA_EXCEEDED", ERROR_PARAMETER_QUOTA_EXCEEDED},  //! Data present in one of the parameters is more than the function can operate on.
		ErrorCodeName{"ERROR_DEBUGGER_INACTIVE", ERROR_DEBUGGER_INACTIVE},  //! An attempt to do an operation on a debug object failed because the object is in the process of being deleted.
		ErrorCodeName{"ERROR_DELAY_LOAD_FAILED", ERROR_DELAY_LOAD_FAILED},  //! An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed.
		ErrorCodeName{"ERROR_VDM_DISALLOWED", ERROR_VDM_DISALLOWED},  //! %1 is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator.
		ErrorCodeName{"ERROR_UNIDENTIFIED_ERROR", ERROR_UNIDENTIFIED_ERROR},  //! Insufficient information exists to identify the cause of failure.
		ErrorCodeName{"ERROR_INVALID_CRUNTIME_PARAMETER", ERROR_INVALID_CRUNTIME_PARAMETER},  //! The parameter passed to a C runtime function is incorrect.
		ErrorCodeName{"ERROR_BEYOND_VDL", ERROR_BEYOND_VDL},  //! The operation occurred beyond the valid data length of the file.
		ErrorCodeName{"ERROR_INCOMPATIBLE_SERVICE_SID_TYPE", ERROR_INCOMPATIBLE_SERVICE_SID_TYPE},  //! The service start failed since one or more services in the same process have an incompatible service SID type setting. A service with restricted service SID type can only coexist in the same process with other services with a restricted SID type. If the service SID type for this service was just configured, the hosting process must be restarted in order to start this service.
		ErrorCodeName{"ERROR_DRIVER_PROCESS_TERMINATED", ERROR_DRIVER_PROCESS_TERMINATED},  //! The process hosting the driver for this device has been terminated.
		ErrorCodeName{"ERROR_IMPLEMENTATION_LIMIT", ERROR_IMPLEMENTATION_LIMIT},  //! An operation attempted to exceed an implementation-defined limit.
		ErrorCodeName{"ERROR_PROCESS_IS_PROTECTED", ERROR_PROCESS_IS_PROTECTED},  //! Either the target process, or the target thread's containing process, is a protected process.
		ErrorCodeName{"ERROR_SERVICE_NOTIFY_CLIENT_LAGGING", ERROR_SERVICE_NOTIFY_CLIENT_LAGGING},  //! The service notification client is lagging too far behind the current state of services in the machine.
		ErrorCodeName{"ERROR_DISK_QUOTA_EXCEEDED", ERROR_DISK_QUOTA_EXCEEDED},  //! The requested file operation failed because the storage quota was exceeded. To free up disk space, move files to a different location or delete unnecessary files. For more information, contact your system administrator.
		ErrorCodeName{"ERROR_CONTENT_BLOCKED", ERROR_CONTENT_BLOCKED},  //! The requested file operation failed because the storage policy blocks that type of file. For more information, contact your system administrator.
		ErrorCodeName{"ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE", ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE},  //! A privilege that the service requires to function properly does not exist in the service account configuration. You may use the Services Microsoft Management Console (MMC) snap-in (services.msc) and the Local Security Settings MMC snap-in (secpol.msc) to view the service configuration and the account configuration.
		ErrorCodeName{"ERROR_APP_HANG", ERROR_APP_HANG},  //! A thread involved in this operation appears to be unresponsive.
		ErrorCodeName{"ERROR_INVALID_LABEL", ERROR_INVALID_LABEL},  //! Indicates a particular Security ID may not be assigned as the label of an object.
		ErrorCodeName{"ERROR_NOT_ALL_ASSIGNED", ERROR_NOT_ALL_ASSIGNED},  //! Not all privileges or groups referenced are assigned to the caller.
		ErrorCodeName{"ERROR_SOME_NOT_MAPPED", ERROR_SOME_NOT_MAPPED},  //! Some mapping between account names and security IDs was not done.
		ErrorCodeName{"ERROR_NO_QUOTAS_FOR_ACCOUNT", ERROR_NO_QUOTAS_FOR_ACCOUNT},  //! No system quota limits are specifically set for this account.
		ErrorCodeName{"ERROR_LOCAL_USER_SESSION_KEY", ERROR_LOCAL_USER_SESSION_KEY},  //! No encryption key is available. A well-known encryption key was returned.
		ErrorCodeName{"ERROR_NULL_LM_PASSWORD", ERROR_NULL_LM_PASSWORD},  //! The password is too complex to be converted to a LAN Manager password. The LAN Manager password returned is a NULL string.
		ErrorCodeName{"ERROR_UNKNOWN_REVISION", ERROR_UNKNOWN_REVISION},  //! The revision level is unknown.
		ErrorCodeName{"ERROR_REVISION_MISMATCH", ERROR_REVISION_MISMATCH},  //! Indicates two revision levels are incompatible.
		ErrorCodeName{"ERROR_INVALID_OWNER", ERROR_INVALID_OWNER},  //! This security ID may not be assigned as the owner of this object.
		ErrorCodeName{"ERROR_INVALID_PRIMARY_GROUP", ERROR_INVALID_PRIMARY_GROUP},  //! This security ID may not be assigned as the primary group of an object.
		ErrorCodeName{"ERROR_NO_IMPERSONATION_TOKEN", ERROR_NO_IMPERSONATION_TOKEN},  //! An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client.
		ErrorCodeName{"ERROR_CANT_DISABLE_MANDATORY", ERROR_CANT_DISABLE_MANDATORY},  //! The group may not be disabled.
		ErrorCodeName{"ERROR_NO_LOGON_SERVERS", ERROR_NO_LOGON_SERVERS},  //! There are currently no logon servers available to service the logon request.
		ErrorCodeName{"ERROR_NO_SUCH_LOGON_SESSION", ERROR_NO_SUCH_LOGON_SESSION},  //! A specified logon session does not exist. It may already have been terminated.
		ErrorCodeName{"ERROR_NO_SUCH_PRIVILEGE", ERROR_NO_SUCH_PRIVILEGE},  //! A specified privilege does not exist.
		ErrorCodeName{"ERROR_PRIVILEGE_NOT_HELD", ERROR_PRIVILEGE_NOT_HELD},  //! A required privilege is not held by the client.
		ErrorCodeName{"ERROR_INVALID_ACCOUNT_NAME", ERROR_INVALID_ACCOUNT_NAME},  //! The name provided is not a properly formed account name.
		ErrorCodeName{"ERROR_USER_EXISTS", ERROR_USER_EXISTS},  //! The specified account already exists.
		ErrorCodeName{"ERROR_NO_SUCH_USER", ERROR_NO_SUCH_USER},  //! The specified account does not exist.
		ErrorCodeName{"ERROR_GROUP_EXISTS", ERROR_GROUP_EXISTS},  //! The specified group already exists.
		ErrorCodeName{"ERROR_NO_SUCH_GROUP", ERROR_NO_SUCH_GROUP},  //! The specified group does not exist.
		ErrorCodeName{"ERROR_MEMBER_IN_GROUP", ERROR_MEMBER_IN_GROUP},  //! Either the specified user account is already a member of the specified group, or the specified group cannot be deleted because it contains a member.
		ErrorCodeName{"ERROR_MEMBER_NOT_IN_GROUP", ERROR_MEMBER_NOT_IN_GROUP},  //! The specified user account is not a member of the specified group account.
		ErrorCodeName{"ERROR_LAST_ADMIN", ERROR_LAST_ADMIN},  //! This operation is disallowed as it could result in an administration account being disabled, deleted or unable to log on.
		ErrorCodeName{"ERROR_WRONG_PASSWORD", ERROR_WRONG_PASSWORD},  //! Unable to update the password. The value provided as the current password is incorrect.
		ErrorCodeName{"ERROR_ILL_FORMED_PASSWORD", ERROR_ILL_FORMED_PASSWORD},  //! Unable to update the password. The value provided for the new password contains values that are not allowed in passwords.
		ErrorCodeName{"ERROR_PASSWORD_RESTRICTION", ERROR_PASSWORD_RESTRICTION},  //! Unable to update the password. The value provided for the new password does not meet the length, complexity, or history requirements of the domain.
		ErrorCodeName{"ERROR_LOGON_FAILURE", ERROR_LOGON_FAILURE},  //! The user name or password is incorrect.
		ErrorCodeName{"ERROR_ACCOUNT_RESTRICTION", ERROR_ACCOUNT_RESTRICTION},  //! Account restrictions are preventing this user from signing in. For example: blank passwords aren't allowed, sign-in times are limited, or a policy restriction has been enforced.
		ErrorCodeName{"ERROR_INVALID_LOGON_HOURS", ERROR_INVALID_LOGON_HOURS},  //! Your account has time restrictions that keep you from signing in right now.
		ErrorCodeName{"ERROR_INVALID_WORKSTATION", ERROR_INVALID_WORKSTATION},  //! This user isn't allowed to sign in to this computer.
		ErrorCodeName{"ERROR_PASSWORD_EXPIRED", ERROR_PASSWORD_EXPIRED},  //! The password for this account has expired.
		ErrorCodeName{"ERROR_ACCOUNT_DISABLED", ERROR_ACCOUNT_DISABLED},  //! This user can't sign in because this account is currently disabled.
		ErrorCodeName{"ERROR_NONE_MAPPED", ERROR_NONE_MAPPED},  //! No mapping between account names and security IDs was done.
		ErrorCodeName{"ERROR_TOO_MANY_LUIDS_REQUESTED", ERROR_TOO_MANY_LUIDS_REQUESTED},  //! Too many local user identifiers (LUIDs) were requested at one time.
		ErrorCodeName{"ERROR_LUIDS_EXHAUSTED", ERROR_LUIDS_EXHAUSTED},  //! No more local user identifiers (LUIDs) are available.
		ErrorCodeName{"ERROR_INVALID_SUB_AUTHORITY", ERROR_INVALID_SUB_AUTHORITY},  //! The subauthority part of a security ID is invalid for this particular use.
		ErrorCodeName{"ERROR_INVALID_ACL", ERROR_INVALID_ACL},  //! The access control list (ACL) structure is invalid.
		ErrorCodeName{"ERROR_INVALID_SID", ERROR_INVALID_SID},  //! The security ID structure is invalid.
		ErrorCodeName{"ERROR_INVALID_SECURITY_DESCR", ERROR_INVALID_SECURITY_DESCR},  //! The security descriptor structure is invalid.
		ErrorCodeName{"ERROR_BAD_INHERITANCE_ACL", ERROR_BAD_INHERITANCE_ACL},  //! The inherited access control list (ACL) or access control entry (ACE) could not be built.
		ErrorCodeName{"ERROR_SERVER_DISABLED", ERROR_SERVER_DISABLED},  //! The server is currently disabled.
		ErrorCodeName{"ERROR_SERVER_NOT_DISABLED", ERROR_SERVER_NOT_DISABLED},  //! The server is currently enabled.
		ErrorCodeName{"ERROR_INVALID_ID_AUTHORITY", ERROR_INVALID_ID_AUTHORITY},  //! The value provided was an invalid value for an identifier authority.
		ErrorCodeName{"ERROR_ALLOTTED_SPACE_EXCEEDED", ERROR_ALLOTTED_SPACE_EXCEEDED},  //! No more memory is available for security information updates.
		ErrorCodeName{"ERROR_INVALID_GROUP_ATTRIBUTES", ERROR_INVALID_GROUP_ATTRIBUTES},  //! The specified attributes are invalid, or incompatible with the attributes for the group as a whole.
		ErrorCodeName{"ERROR_BAD_IMPERSONATION_LEVEL", ERROR_BAD_IMPERSONATION_LEVEL},  //! Either a required impersonation level was not provided, or the provided impersonation level is invalid.
		ErrorCodeName{"ERROR_CANT_OPEN_ANONYMOUS", ERROR_CANT_OPEN_ANONYMOUS},  //! Cannot open an anonymous level security token.
		ErrorCodeName{"ERROR_BAD_VALIDATION_CLASS", ERROR_BAD_VALIDATION_CLASS},  //! The validation information class requested was invalid.
		ErrorCodeName{"ERROR_BAD_TOKEN_TYPE", ERROR_BAD_TOKEN_TYPE},  //! The type of the token is inappropriate for its attempted use.
		ErrorCodeName{"ERROR_NO_SECURITY_ON_OBJECT", ERROR_NO_SECURITY_ON_OBJECT},  //! Unable to perform a security operation on an object that has no associated security.
		ErrorCodeName{"ERROR_CANT_ACCESS_DOMAIN_INFO", ERROR_CANT_ACCESS_DOMAIN_INFO},  //! Configuration information could not be read from the domain controller, either because the machine is unavailable, or access has been denied.
		ErrorCodeName{"ERROR_INVALID_SERVER_STATE", ERROR_INVALID_SERVER_STATE},  //! The security account manager (SAM) or local security authority (LSA) server was in the wrong state to perform the security operation.
		ErrorCodeName{"ERROR_INVALID_DOMAIN_STATE", ERROR_INVALID_DOMAIN_STATE},  //! The domain was in the wrong state to perform the security operation.
		ErrorCodeName{"ERROR_INVALID_DOMAIN_ROLE", ERROR_INVALID_DOMAIN_ROLE},  //! This operation is only allowed for the Primary Domain Controller of the domain.
		ErrorCodeName{"ERROR_NO_SUCH_DOMAIN", ERROR_NO_SUCH_DOMAIN},  //! The specified domain either does not exist or could not be contacted.
		ErrorCodeName{"ERROR_DOMAIN_EXISTS", ERROR_DOMAIN_EXISTS},  //! The specified domain already exists.
		ErrorCodeName{"ERROR_DOMAIN_LIMIT_EXCEEDED", ERROR_DOMAIN_LIMIT_EXCEEDED},  //! An attempt was made to exceed the limit on the number of domains per server.
		ErrorCodeName{"ERROR_INTERNAL_DB_CORRUPTION", ERROR_INTERNAL_DB_CORRUPTION},  //! Unable to complete the requested operation because of either a catastrophic media failure or a data structure corruption on the disk.
		ErrorCodeName{"ERROR_INTERNAL_ERROR", ERROR_INTERNAL_ERROR},  //! An internal error occurred.
		ErrorCodeName{"ERROR_GENERIC_NOT_MAPPED", ERROR_GENERIC_NOT_MAPPED},  //! Generic access types were contained in an access mask which should already be mapped to nongeneric types.
		ErrorCodeName{"ERROR_BAD_DESCRIPTOR_FORMAT", ERROR_BAD_DESCRIPTOR_FORMAT},  //! A security descriptor is not in the right format (absolute or self-relative).
		ErrorCodeName{"ERROR_NOT_LOGON_PROCESS", ERROR_NOT_LOGON_PROCESS},  //! The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process.
		ErrorCodeName{"ERROR_LOGON_SESSION_EXISTS", ERROR_LOGON_SESSION_EXISTS},  //! Cannot start a new logon session with an ID that is already in use.
		ErrorCodeName{"ERROR_NO_SUCH_PACKAGE", ERROR_NO_SUCH_PACKAGE},  //! A specified authentication package is unknown.
		ErrorCodeName{"ERROR_BAD_LOGON_SESSION_STATE", ERROR_BAD_LOGON_SESSION_STATE},  //! The logon session is not in a state that is consistent with the requested operation.
		ErrorCodeName{"ERROR_LOGON_SESSION_COLLISION", ERROR_LOGON_SESSION_COLLISION},  //! The logon session ID is already in use.
		ErrorCodeName{"ERROR_INVALID_LOGON_TYPE", ERROR_INVALID_LOGON_TYPE},  //! A logon request contained an invalid logon type value.
		ErrorCodeName{"ERROR_CANNOT_IMPERSONATE", ERROR_CANNOT_IMPERSONATE},  //! Unable to impersonate using a named pipe until data has been read from that pipe.
		ErrorCodeName{"ERROR_RXACT_INVALID_STATE", ERROR_RXACT_INVALID_STATE},  //! The transaction state of a registry subtree is incompatible with the requested operation.
		ErrorCodeName{"ERROR_RXACT_COMMIT_FAILURE", ERROR_RXACT_COMMIT_FAILURE},  //! An internal security database corruption has been encountered.
		ErrorCodeName{"ERROR_SPECIAL_ACCOUNT", ERROR_SPECIAL_ACCOUNT},  //! Cannot perform this operation on built-in accounts.
		ErrorCodeName{"ERROR_SPECIAL_GROUP", ERROR_SPECIAL_GROUP},  //! Cannot perform this operation on this built-in special group.
		ErrorCodeName{"ERROR_SPECIAL_USER", ERROR_SPECIAL_USER},  //! Cannot perform this operation on this built-in special user.
		ErrorCodeName{"ERROR_MEMBERS_PRIMARY_GROUP", ERROR_MEMBERS_PRIMARY_GROUP},  //! The user cannot be removed from a group because the group is currently the user's primary group.
		ErrorCodeName{"ERROR_TOKEN_ALREADY_IN_USE", ERROR_TOKEN_ALREADY_IN_USE},  //! The token is already in use as a primary token.
		ErrorCodeName{"ERROR_NO_SUCH_ALIAS", ERROR_NO_SUCH_ALIAS},  //! The specified local group does not exist.
		ErrorCodeName{"ERROR_MEMBER_NOT_IN_ALIAS", ERROR_MEMBER_NOT_IN_ALIAS},  //! The specified account name is not a member of the group.
		ErrorCodeName{"ERROR_MEMBER_IN_ALIAS", ERROR_MEMBER_IN_ALIAS},  //! The specified account name is already a member of the group.
		ErrorCodeName{"ERROR_ALIAS_EXISTS", ERROR_ALIAS_EXISTS},  //! The specified local group already exists.
		ErrorCodeName{"ERROR_LOGON_NOT_GRANTED", ERROR_LOGON_NOT_GRANTED},  //! Logon failure: the user has not been granted the requested logon type at this computer.
		ErrorCodeName{"ERROR_TOO_MANY_SECRETS", ERROR_TOO_MANY_SECRETS},  //! The maximum number of secrets that may be stored in a single system has been exceeded.
		ErrorCodeName{"ERROR_SECRET_TOO_LONG", ERROR_SECRET_TOO_LONG},  //! The length of a secret exceeds the maximum length allowed.
		ErrorCodeName{"ERROR_INTERNAL_DB_ERROR", ERROR_INTERNAL_DB_ERROR},  //! The local security authority database contains an internal inconsistency.
		ErrorCodeName{"ERROR_TOO_MANY_CONTEXT_IDS", ERROR_TOO_MANY_CONTEXT_IDS},  //! During a logon attempt, the user's security context accumulated too many security IDs.
		ErrorCodeName{"ERROR_LOGON_TYPE_NOT_GRANTED", ERROR_LOGON_TYPE_NOT_GRANTED},  //! Logon failure: the user has not been granted the requested logon type at this computer.
		ErrorCodeName{"ERROR_NT_CROSS_ENCRYPTION_REQUIRED", ERROR_NT_CROSS_ENCRYPTION_REQUIRED},  //! A cross-encrypted password is necessary to change a user password.
		ErrorCodeName{"ERROR_NO_SUCH_MEMBER", ERROR_NO_SUCH_MEMBER},  //! A member could not be added to or removed from the local group because the member does not exist.
		ErrorCodeName{"ERROR_INVALID_MEMBER", ERROR_INVALID_MEMBER},  //! A new member could not be added to a local group because the member has the wrong account type.
		ErrorCodeName{"ERROR_TOO_MANY_SIDS", ERROR_TOO_MANY_SIDS},  //! Too many security IDs have been specified.
		ErrorCodeName{"ERROR_LM_CROSS_ENCRYPTION_REQUIRED", ERROR_LM_CROSS_ENCRYPTION_REQUIRED},  //! A cross-encrypted password is necessary to change this user password.
		ErrorCodeName{"ERROR_NO_INHERITANCE", ERROR_NO_INHERITANCE},  //! Indicates an ACL contains no inheritable components.
		ErrorCodeName{"ERROR_FILE_CORRUPT", ERROR_FILE_CORRUPT},  //! The file or directory is corrupted and unreadable.
		ErrorCodeName{"ERROR_DISK_CORRUPT", ERROR_DISK_CORRUPT},  //! The disk structure is corrupted and unreadable.
		ErrorCodeName{"ERROR_NO_USER_SESSION_KEY", ERROR_NO_USER_SESSION_KEY},  //! There is no user session key for the specified logon session.
		ErrorCodeName{"ERROR_LICENSE_QUOTA_EXCEEDED", ERROR_LICENSE_QUOTA_EXCEEDED},  //! The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because there are already as many connections as the service can accept.
		ErrorCodeName{"ERROR_WRONG_TARGET_NAME", ERROR_WRONG_TARGET_NAME},  //! The target account name is incorrect.
		ErrorCodeName{"ERROR_MUTUAL_AUTH_FAILED", ERROR_MUTUAL_AUTH_FAILED},  //! Mutual Authentication failed. The server's password is out of date at the domain controller.
		ErrorCodeName{"ERROR_TIME_SKEW", ERROR_TIME_SKEW},  //! There is a time and/or date difference between the client and server.
		ErrorCodeName{"ERROR_CURRENT_DOMAIN_NOT_ALLOWED", ERROR_CURRENT_DOMAIN_NOT_ALLOWED},  //! This operation cannot be performed on the current domain.
		ErrorCodeName{"ERROR_INVALID_WINDOW_HANDLE", ERROR_INVALID_WINDOW_HANDLE},  //! Invalid window handle.
		ErrorCodeName{"ERROR_INVALID_MENU_HANDLE", ERROR_INVALID_MENU_HANDLE},  //! Invalid menu handle.
		ErrorCodeName{"ERROR_INVALID_CURSOR_HANDLE", ERROR_INVALID_CURSOR_HANDLE},  //! Invalid cursor handle.
		ErrorCodeName{"ERROR_INVALID_ACCEL_HANDLE", ERROR_INVALID_ACCEL_HANDLE},  //! Invalid accelerator table handle.
		ErrorCodeName{"ERROR_INVALID_HOOK_HANDLE", ERROR_INVALID_HOOK_HANDLE},  //! Invalid hook handle.
		ErrorCodeName{"ERROR_INVALID_DWP_HANDLE", ERROR_INVALID_DWP_HANDLE},  //! Invalid handle to a multiple-window position structure.
		ErrorCodeName{"ERROR_TLW_WITH_WSCHILD", ERROR_TLW_WITH_WSCHILD},  //! Cannot create a top-level child window.
		ErrorCodeName{"ERROR_CANNOT_FIND_WND_CLASS", ERROR_CANNOT_FIND_WND_CLASS},  //! Cannot find window class.
		ErrorCodeName{"ERROR_WINDOW_OF_OTHER_THREAD", ERROR_WINDOW_OF_OTHER_THREAD},  //! Invalid window; it belongs to other thread.
		ErrorCodeName{"ERROR_HOTKEY_ALREADY_REGISTERED", ERROR_HOTKEY_ALREADY_REGISTERED},  //! Hot key is already registered.
		ErrorCodeName{"ERROR_CLASS_ALREADY_EXISTS", ERROR_CLASS_ALREADY_EXISTS},  //! Class already exists.
		ErrorCodeName{"ERROR_CLASS_DOES_NOT_EXIST", ERROR_CLASS_DOES_NOT_EXIST},  //! Class does not exist.
		ErrorCodeName{"ERROR_CLASS_HAS_WINDOWS", ERROR_CLASS_HAS_WINDOWS},  //! Class still has open windows.
		ErrorCodeName{"ERROR_INVALID_INDEX", ERROR_INVALID_INDEX},  //! Invalid index.
		ErrorCodeName{"ERROR_INVALID_ICON_HANDLE", ERROR_INVALID_ICON_HANDLE},  //! Invalid icon handle.
		ErrorCodeName{"ERROR_PRIVATE_DIALOG_INDEX", ERROR_PRIVATE_DIALOG_INDEX},  //! Using private DIALOG window words.
		ErrorCodeName{"ERROR_LISTBOX_ID_NOT_FOUND", ERROR_LISTBOX_ID_NOT_FOUND},  //! The list box identifier was not found.
		ErrorCodeName{"ERROR_NO_WILDCARD_CHARACTERS", ERROR_NO_WILDCARD_CHARACTERS},  //! No wildcards were found.
		ErrorCodeName{"ERROR_CLIPBOARD_NOT_OPEN", ERROR_CLIPBOARD_NOT_OPEN},  //! Thread does not have a clipboard open.
		ErrorCodeName{"ERROR_HOTKEY_NOT_REGISTERED", ERROR_HOTKEY_NOT_REGISTERED},  //! Hot key is not registered.
		ErrorCodeName{"ERROR_WINDOW_NOT_DIALOG", ERROR_WINDOW_NOT_DIALOG},  //! The window is not a valid dialog window.
		ErrorCodeName{"ERROR_CONTROL_ID_NOT_FOUND", ERROR_CONTROL_ID_NOT_FOUND},  //! Control ID not found.
		ErrorCodeName{"ERROR_INVALID_COMBOBOX_MESSAGE", ERROR_INVALID_COMBOBOX_MESSAGE},  //! Invalid message for a combo box because it does not have an edit control.
		ErrorCodeName{"ERROR_WINDOW_NOT_COMBOBOX", ERROR_WINDOW_NOT_COMBOBOX},  //! The window is not a combo box.
		ErrorCodeName{"ERROR_INVALID_EDIT_HEIGHT", ERROR_INVALID_EDIT_HEIGHT},  //! Height must be less than 256.
		ErrorCodeName{"ERROR_DC_NOT_FOUND", ERROR_DC_NOT_FOUND},  //! Invalid device context (DC) handle.
		ErrorCodeName{"ERROR_INVALID_HOOK_FILTER", ERROR_INVALID_HOOK_FILTER},  //! Invalid hook procedure type.
		ErrorCodeName{"ERROR_INVALID_FILTER_PROC", ERROR_INVALID_FILTER_PROC},  //! Invalid hook procedure.
		ErrorCodeName{"ERROR_HOOK_NEEDS_HMOD", ERROR_HOOK_NEEDS_HMOD},  //! Cannot set nonlocal hook without a module handle.
		ErrorCodeName{"ERROR_GLOBAL_ONLY_HOOK", ERROR_GLOBAL_ONLY_HOOK},  //! This hook procedure can only be set globally.
		ErrorCodeName{"ERROR_JOURNAL_HOOK_SET", ERROR_JOURNAL_HOOK_SET},  //! The journal hook procedure is already installed.
		ErrorCodeName{"ERROR_HOOK_NOT_INSTALLED", ERROR_HOOK_NOT_INSTALLED},  //! The hook procedure is not installed.
		ErrorCodeName{"ERROR_INVALID_LB_MESSAGE", ERROR_INVALID_LB_MESSAGE},  //! Invalid message for single-selection list box.
		ErrorCodeName{"ERROR_SETCOUNT_ON_BAD_LB", ERROR_SETCOUNT_ON_BAD_LB},  //! LB_SETCOUNT sent to non-lazy list box.
		ErrorCodeName{"ERROR_LB_WITHOUT_TABSTOPS", ERROR_LB_WITHOUT_TABSTOPS},  //! This list box does not support tab stops.
		ErrorCodeName{"ERROR_DESTROY_OBJECT_OF_OTHER_THREAD", ERROR_DESTROY_OBJECT_OF_OTHER_THREAD},  //! Cannot destroy object created by another thread.
		ErrorCodeName{"ERROR_CHILD_WINDOW_MENU", ERROR_CHILD_WINDOW_MENU},  //! Child windows cannot have menus.
		ErrorCodeName{"ERROR_NO_SYSTEM_MENU", ERROR_NO_SYSTEM_MENU},  //! The window does not have a system menu.
		ErrorCodeName{"ERROR_INVALID_MSGBOX_STYLE", ERROR_INVALID_MSGBOX_STYLE},  //! Invalid message box style.
		ErrorCodeName{"ERROR_INVALID_SPI_VALUE", ERROR_INVALID_SPI_VALUE},  //! Invalid system-wide (SPI_*) parameter.
		ErrorCodeName{"ERROR_SCREEN_ALREADY_LOCKED", ERROR_SCREEN_ALREADY_LOCKED},  //! Screen already locked.
		ErrorCodeName{"ERROR_HWNDS_HAVE_DIFF_PARENT", ERROR_HWNDS_HAVE_DIFF_PARENT},  //! All handles to windows in a multiple-window position structure must have the same parent.
		ErrorCodeName{"ERROR_NOT_CHILD_WINDOW", ERROR_NOT_CHILD_WINDOW},  //! The window is not a child window.
		ErrorCodeName{"ERROR_INVALID_GW_COMMAND", ERROR_INVALID_GW_COMMAND},  //! Invalid GW_* command.
		ErrorCodeName{"ERROR_INVALID_THREAD_ID", ERROR_INVALID_THREAD_ID},  //! Invalid thread identifier.
		ErrorCodeName{"ERROR_NON_MDICHILD_WINDOW", ERROR_NON_MDICHILD_WINDOW},  //! Cannot process a message from a window that is not a multiple document interface (MDI) window.
		ErrorCodeName{"ERROR_POPUP_ALREADY_ACTIVE", ERROR_POPUP_ALREADY_ACTIVE},  //! Popup menu already active.
		ErrorCodeName{"ERROR_NO_SCROLLBARS", ERROR_NO_SCROLLBARS},  //! The window does not have scroll bars.
		ErrorCodeName{"ERROR_INVALID_SCROLLBAR_RANGE", ERROR_INVALID_SCROLLBAR_RANGE},  //! Scroll bar range cannot be greater than MAXLONG.
		ErrorCodeName{"ERROR_INVALID_SHOWWIN_COMMAND", ERROR_INVALID_SHOWWIN_COMMAND},  //! Cannot show or remove the window in the way specified.
		ErrorCodeName{"ERROR_NO_SYSTEM_RESOURCES", ERROR_NO_SYSTEM_RESOURCES},  //! Insufficient system resources exist to complete the requested service.
		ErrorCodeName{"ERROR_NONPAGED_SYSTEM_RESOURCES", ERROR_NONPAGED_SYSTEM_RESOURCES},  //! Insufficient system resources exist to complete the requested service.
		ErrorCodeName{"ERROR_PAGED_SYSTEM_RESOURCES", ERROR_PAGED_SYSTEM_RESOURCES},  //! Insufficient system resources exist to complete the requested service.
		ErrorCodeName{"ERROR_WORKING_SET_QUOTA", ERROR_WORKING_SET_QUOTA},  //! Insufficient quota to complete the requested service.
		ErrorCodeName{"ERROR_PAGEFILE_QUOTA", ERROR_PAGEFILE_QUOTA},  //! Insufficient quota to complete the requested service.
		ErrorCodeName{"ERROR_COMMITMENT_LIMIT", ERROR_COMMITMENT_LIMIT},  //! The paging file is too small for this operation to complete.
		ErrorCodeName{"ERROR_MENU_ITEM_NOT_FOUND", ERROR_MENU_ITEM_NOT_FOUND},  //! A menu item was not found.
		ErrorCodeName{"ERROR_INVALID_KEYBOARD_HANDLE", ERROR_INVALID_KEYBOARD_HANDLE},  //! Invalid keyboard layout handle.
		ErrorCodeName{"ERROR_HOOK_TYPE_NOT_ALLOWED", ERROR_HOOK_TYPE_NOT_ALLOWED},  //! Hook type not allowed.
		ErrorCodeName{"ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION", ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION},  //! This operation requires an interactive window station.
		ErrorCodeName{"ERROR_TIMEOUT", ERROR_TIMEOUT},  //! This operation returned because the timeout period expired.
		ErrorCodeName{"ERROR_INVALID_MONITOR_HANDLE", ERROR_INVALID_MONITOR_HANDLE},  //! Invalid monitor handle.
		ErrorCodeName{"ERROR_INCORRECT_SIZE", ERROR_INCORRECT_SIZE},  //! Incorrect size argument.
		ErrorCodeName{"ERROR_SYMLINK_CLASS_DISABLED", ERROR_SYMLINK_CLASS_DISABLED},  //! The symbolic link cannot be followed because its type is disabled.
		ErrorCodeName{"ERROR_SYMLINK_NOT_SUPPORTED", ERROR_SYMLINK_NOT_SUPPORTED},  //! This application does not support the current operation on symbolic links.
		ErrorCodeName{"ERROR_XML_PARSE_ERROR", ERROR_XML_PARSE_ERROR},  //! Windows was unable to parse the requested XML data.
		ErrorCodeName{"ERROR_XMLDSIG_ERROR", ERROR_XMLDSIG_ERROR},  //! An error was encountered while processing an XML digital signature.
		ErrorCodeName{"ERROR_RESTART_APPLICATION", ERROR_RESTART_APPLICATION},  //! This application must be restarted.
		ErrorCodeName{"ERROR_WRONG_COMPARTMENT", ERROR_WRONG_COMPARTMENT},  //! The caller made the connection request in the wrong routing compartment.
		ErrorCodeName{"ERROR_AUTHIP_FAILURE", ERROR_AUTHIP_FAILURE},  //! There was an AuthIP failure when attempting to connect to the remote host.
		ErrorCodeName{"ERROR_NO_NVRAM_RESOURCES", ERROR_NO_NVRAM_RESOURCES},  //! Insufficient NVRAM resources exist to complete the requested service. A reboot might be required.
		ErrorCodeName{"ERROR_NOT_GUI_PROCESS", ERROR_NOT_GUI_PROCESS},  //! Unable to finish the requested operation because the specified process is not a GUI process.
		ErrorCodeName{"ERROR_EVENTLOG_FILE_CORRUPT", ERROR_EVENTLOG_FILE_CORRUPT},  //! The event log file is corrupted.
		ErrorCodeName{"ERROR_EVENTLOG_CANT_START", ERROR_EVENTLOG_CANT_START},  //! No event log file could be opened, so the event logging service did not start.
		ErrorCodeName{"ERROR_LOG_FILE_FULL", ERROR_LOG_FILE_FULL},  //! The event log file is full.
		ErrorCodeName{"ERROR_EVENTLOG_FILE_CHANGED", ERROR_EVENTLOG_FILE_CHANGED},  //! The event log file has changed between read operations.
		ErrorCodeName{"ERROR_INVALID_TASK_NAME", ERROR_INVALID_TASK_NAME},  //! The specified task name is invalid.
		ErrorCodeName{"ERROR_INVALID_TASK_INDEX", ERROR_INVALID_TASK_INDEX},  //! The specified task index is invalid.
		ErrorCodeName{"ERROR_THREAD_ALREADY_IN_TASK", ERROR_THREAD_ALREADY_IN_TASK},  //! The specified thread is already joining a task.
		ErrorCodeName{"ERROR_INSTALL_SERVICE_FAILURE", ERROR_INSTALL_SERVICE_FAILURE},  //! The Windows Installer Service could not be accessed. This can occur if the Windows Installer is not correctly installed. Contact your support personnel for assistance.
		ErrorCodeName{"ERROR_INSTALL_USEREXIT", ERROR_INSTALL_USEREXIT},  //! User cancelled installation.
		ErrorCodeName{"ERROR_INSTALL_FAILURE", ERROR_INSTALL_FAILURE},  //! Fatal error during installation.
		ErrorCodeName{"ERROR_INSTALL_SUSPEND", ERROR_INSTALL_SUSPEND},  //! Installation suspended, incomplete.
		ErrorCodeName{"ERROR_UNKNOWN_PRODUCT", ERROR_UNKNOWN_PRODUCT},  //! This action is only valid for products that are currently installed.
		ErrorCodeName{"ERROR_UNKNOWN_FEATURE", ERROR_UNKNOWN_FEATURE},  //! Feature ID not registered.
		ErrorCodeName{"ERROR_UNKNOWN_COMPONENT", ERROR_UNKNOWN_COMPONENT},  //! Component ID not registered.
		ErrorCodeName{"ERROR_UNKNOWN_PROPERTY", ERROR_UNKNOWN_PROPERTY},  //! Unknown property.
		ErrorCodeName{"ERROR_INVALID_HANDLE_STATE", ERROR_INVALID_HANDLE_STATE},  //! Handle is in an invalid state.
		ErrorCodeName{"ERROR_BAD_CONFIGURATION", ERROR_BAD_CONFIGURATION},  //! The configuration data for this product is corrupt. Contact your support personnel.
		ErrorCodeName{"ERROR_INDEX_ABSENT", ERROR_INDEX_ABSENT},  //! Component qualifier not present.
		ErrorCodeName{"ERROR_INSTALL_SOURCE_ABSENT", ERROR_INSTALL_SOURCE_ABSENT},  //! The installation source for this product is not available. Verify that the source exists and that you can access it.
		ErrorCodeName{"ERROR_INSTALL_PACKAGE_VERSION", ERROR_INSTALL_PACKAGE_VERSION},  //! This installation package cannot be installed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.
		ErrorCodeName{"ERROR_PRODUCT_UNINSTALLED", ERROR_PRODUCT_UNINSTALLED},  //! Product is uninstalled.
		ErrorCodeName{"ERROR_BAD_QUERY_SYNTAX", ERROR_BAD_QUERY_SYNTAX},  //! SQL query syntax invalid or unsupported.
		ErrorCodeName{"ERROR_INVALID_FIELD", ERROR_INVALID_FIELD},  //! Record field does not exist.
		ErrorCodeName{"ERROR_DEVICE_REMOVED", ERROR_DEVICE_REMOVED},  //! The device has been removed.
		ErrorCodeName{"ERROR_INSTALL_ALREADY_RUNNING", ERROR_INSTALL_ALREADY_RUNNING},  //! Another installation is already in progress. Complete that installation before proceeding with this install.
		ErrorCodeName{"ERROR_INSTALL_PACKAGE_OPEN_FAILED", ERROR_INSTALL_PACKAGE_OPEN_FAILED},  //! This installation package could not be opened. Verify that the package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer package.
		ErrorCodeName{"ERROR_INSTALL_PACKAGE_INVALID", ERROR_INSTALL_PACKAGE_INVALID},  //! This installation package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer package.
		ErrorCodeName{"ERROR_INSTALL_UI_FAILURE", ERROR_INSTALL_UI_FAILURE},  //! There was an error starting the Windows Installer service user interface. Contact your support personnel.
		ErrorCodeName{"ERROR_INSTALL_LOG_FAILURE", ERROR_INSTALL_LOG_FAILURE},  //! Error opening installation log file. Verify that the specified log file location exists and that you can write to it.
		ErrorCodeName{"ERROR_INSTALL_LANGUAGE_UNSUPPORTED", ERROR_INSTALL_LANGUAGE_UNSUPPORTED},  //! The language of this installation package is not supported by your system.
		ErrorCodeName{"ERROR_INSTALL_TRANSFORM_FAILURE", ERROR_INSTALL_TRANSFORM_FAILURE},  //! Error applying transforms. Verify that the specified transform paths are valid.
		ErrorCodeName{"ERROR_INSTALL_PACKAGE_REJECTED", ERROR_INSTALL_PACKAGE_REJECTED},  //! This installation is forbidden by system policy. Contact your system administrator.
		ErrorCodeName{"ERROR_FUNCTION_NOT_CALLED", ERROR_FUNCTION_NOT_CALLED},  //! Function could not be executed.
		ErrorCodeName{"ERROR_FUNCTION_FAILED", ERROR_FUNCTION_FAILED},  //! Function failed during execution.
		ErrorCodeName{"ERROR_INVALID_TABLE", ERROR_INVALID_TABLE},  //! Invalid or unknown table specified.
		ErrorCodeName{"ERROR_DATATYPE_MISMATCH", ERROR_DATATYPE_MISMATCH},  //! Data supplied is of wrong type.
		ErrorCodeName{"ERROR_UNSUPPORTED_TYPE", ERROR_UNSUPPORTED_TYPE},  //! Data of this type is not supported.
		ErrorCodeName{"ERROR_CREATE_FAILED", ERROR_CREATE_FAILED},  //! The Windows Installer service failed to start. Contact your support personnel.
		ErrorCodeName{"ERROR_INSTALL_TEMP_UNWRITABLE", ERROR_INSTALL_TEMP_UNWRITABLE},  //! The Temp folder is on a drive that is full or is inaccessible. Free up space on the drive or verify that you have write permission on the Temp folder.
		ErrorCodeName{"ERROR_INSTALL_PLATFORM_UNSUPPORTED", ERROR_INSTALL_PLATFORM_UNSUPPORTED},  //! This installation package is not supported by this processor type. Contact your product vendor.
		ErrorCodeName{"ERROR_INSTALL_NOTUSED", ERROR_INSTALL_NOTUSED},  //! Component not used on this computer.
		ErrorCodeName{"ERROR_PATCH_PACKAGE_OPEN_FAILED", ERROR_PATCH_PACKAGE_OPEN_FAILED},  //! This update package could not be opened. Verify that the update package exists and that you can access it, or contact the application vendor to verify that this is a valid Windows Installer update package.
		ErrorCodeName{"ERROR_PATCH_PACKAGE_INVALID", ERROR_PATCH_PACKAGE_INVALID},  //! This update package could not be opened. Contact the application vendor to verify that this is a valid Windows Installer update package.
		ErrorCodeName{"ERROR_PATCH_PACKAGE_UNSUPPORTED", ERROR_PATCH_PACKAGE_UNSUPPORTED},  //! This update package cannot be processed by the Windows Installer service. You must install a Windows service pack that contains a newer version of the Windows Installer service.
		ErrorCodeName{"ERROR_PRODUCT_VERSION", ERROR_PRODUCT_VERSION},  //! Another version of this product is already installed. Installation of this version cannot continue. To configure or remove the existing version of this product, use Add/Remove Programs on the Control Panel.
		ErrorCodeName{"ERROR_INVALID_COMMAND_LINE", ERROR_INVALID_COMMAND_LINE},  //! Invalid command line argument. Consult the Windows Installer SDK for detailed command line help.
		ErrorCodeName{"ERROR_INSTALL_REMOTE_DISALLOWED", ERROR_INSTALL_REMOTE_DISALLOWED},  //! Only administrators have permission to add, remove, or configure server software during a Terminal services remote session. If you want to install or configure software on the server, contact your network administrator.
		ErrorCodeName{"ERROR_SUCCESS_REBOOT_INITIATED", ERROR_SUCCESS_REBOOT_INITIATED},  //! The requested operation completed successfully. The system will be restarted so the changes can take effect.
		ErrorCodeName{"ERROR_PATCH_TARGET_NOT_FOUND", ERROR_PATCH_TARGET_NOT_FOUND},  //! The upgrade cannot be installed by the Windows Installer service because the program to be upgraded may be missing, or the upgrade may update a different version of the program. Verify that the program to be upgraded exists on your computer and that you have the correct upgrade.
		ErrorCodeName{"ERROR_PATCH_PACKAGE_REJECTED", ERROR_PATCH_PACKAGE_REJECTED},  //! The update package is not permitted by software restriction policy.
		ErrorCodeName{"ERROR_INSTALL_TRANSFORM_REJECTED", ERROR_INSTALL_TRANSFORM_REJECTED},  //! One or more customizations are not permitted by software restriction policy.
		ErrorCodeName{"ERROR_INSTALL_REMOTE_PROHIBITED", ERROR_INSTALL_REMOTE_PROHIBITED},  //! The Windows Installer does not permit installation from a Remote Desktop Connection.
		ErrorCodeName{"ERROR_PATCH_REMOVAL_UNSUPPORTED", ERROR_PATCH_REMOVAL_UNSUPPORTED},  //! Uninstallation of the update package is not supported.
		ErrorCodeName{"ERROR_UNKNOWN_PATCH", ERROR_UNKNOWN_PATCH},  //! The update is not applied to this product.
		ErrorCodeName{"ERROR_PATCH_NO_SEQUENCE", ERROR_PATCH_NO_SEQUENCE},  //! No valid sequence could be found for the set of updates.
		ErrorCodeName{"ERROR_PATCH_REMOVAL_DISALLOWED", ERROR_PATCH_REMOVAL_DISALLOWED},  //! Update removal was disallowed by policy.
		ErrorCodeName{"ERROR_INVALID_PATCH_XML", ERROR_INVALID_PATCH_XML},  //! The XML update data is invalid.
		ErrorCodeName{"ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT", ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT},  //! Windows Installer does not permit updating of managed advertised products. At least one feature of the product must be installed before applying the update.
		ErrorCodeName{"ERROR_INSTALL_SERVICE_SAFEBOOT", ERROR_INSTALL_SERVICE_SAFEBOOT},  //! The Windows Installer service is not accessible in Safe Mode. Please try again when your computer is not in Safe Mode or you can use System Restore to return your machine to a previous good state.
		ErrorCodeName{"ERROR_FAIL_FAST_EXCEPTION", ERROR_FAIL_FAST_EXCEPTION},  //! A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately.
		ErrorCodeName{"ERROR_INSTALL_REJECTED", ERROR_INSTALL_REJECTED},  //! The app that you are trying to run is not supported on this version of Windows.
		ErrorCodeName{"RPC_S_INVALID_STRING_BINDING", RPC_S_INVALID_STRING_BINDING},  //! The string binding is invalid.
		ErrorCodeName{"RPC_S_WRONG_KIND_OF_BINDING", RPC_S_WRONG_KIND_OF_BINDING},  //! The binding handle is not the correct type.
		ErrorCodeName{"RPC_S_INVALID_BINDING", RPC_S_INVALID_BINDING},  //! The binding handle is invalid.
		ErrorCodeName{"RPC_S_PROTSEQ_NOT_SUPPORTED", RPC_S_PROTSEQ_NOT_SUPPORTED},  //! The RPC protocol sequence is not supported.
		ErrorCodeName{"RPC_S_INVALID_RPC_PROTSEQ", RPC_S_INVALID_RPC_PROTSEQ},  //! The RPC protocol sequence is invalid.
		ErrorCodeName{"RPC_S_INVALID_STRING_UUID", RPC_S_INVALID_STRING_UUID},  //! The string universal unique identifier (UUID) is invalid.
		ErrorCodeName{"RPC_S_INVALID_ENDPOINT_FORMAT", RPC_S_INVALID_ENDPOINT_FORMAT},  //! The endpoint format is invalid.
		ErrorCodeName{"RPC_S_INVALID_NET_ADDR", RPC_S_INVALID_NET_ADDR},  //! The network address is invalid.
		ErrorCodeName{"RPC_S_NO_ENDPOINT_FOUND", RPC_S_NO_ENDPOINT_FOUND},  //! No endpoint was found.
		ErrorCodeName{"RPC_S_INVALID_TIMEOUT", RPC_S_INVALID_TIMEOUT},  //! The timeout value is invalid.
		ErrorCodeName{"RPC_S_OBJECT_NOT_FOUND", RPC_S_OBJECT_NOT_FOUND},  //! The object universal unique identifier (UUID) was not found.
		ErrorCodeName{"RPC_S_ALREADY_REGISTERED", RPC_S_ALREADY_REGISTERED},  //! The object universal unique identifier (UUID) has already been registered.
		ErrorCodeName{"RPC_S_TYPE_ALREADY_REGISTERED", RPC_S_TYPE_ALREADY_REGISTERED},  //! The type universal unique identifier (UUID) has already been registered.
		ErrorCodeName{"RPC_S_ALREADY_LISTENING", RPC_S_ALREADY_LISTENING},  //! The RPC server is already listening.
		ErrorCodeName{"RPC_S_NO_PROTSEQS_REGISTERED", RPC_S_NO_PROTSEQS_REGISTERED},  //! No protocol sequences have been registered.
		ErrorCodeName{"RPC_S_NOT_LISTENING", RPC_S_NOT_LISTENING},  //! The RPC server is not listening.
		ErrorCodeName{"RPC_S_UNKNOWN_MGR_TYPE", RPC_S_UNKNOWN_MGR_TYPE},  //! The manager type is unknown.
		ErrorCodeName{"RPC_S_UNKNOWN_IF", RPC_S_UNKNOWN_IF},  //! The interface is unknown.
		ErrorCodeName{"RPC_S_NO_BINDINGS", RPC_S_NO_BINDINGS},  //! There are no bindings.
		ErrorCodeName{"RPC_S_NO_PROTSEQS", RPC_S_NO_PROTSEQS},  //! There are no protocol sequences.
		ErrorCodeName{"RPC_S_CANT_CREATE_ENDPOINT", RPC_S_CANT_CREATE_ENDPOINT},  //! The endpoint cannot be created.
		ErrorCodeName{"RPC_S_OUT_OF_RESOURCES", RPC_S_OUT_OF_RESOURCES},  //! Not enough resources are available to complete this operation.
		ErrorCodeName{"RPC_S_SERVER_UNAVAILABLE", RPC_S_SERVER_UNAVAILABLE},  //! The RPC server is unavailable.
		ErrorCodeName{"RPC_S_SERVER_TOO_BUSY", RPC_S_SERVER_TOO_BUSY},  //! The RPC server is too busy to complete this operation.
		ErrorCodeName{"RPC_S_INVALID_NETWORK_OPTIONS", RPC_S_INVALID_NETWORK_OPTIONS},  //! The network options are invalid.
		ErrorCodeName{"RPC_S_NO_CALL_ACTIVE", RPC_S_NO_CALL_ACTIVE},  //! There are no remote procedure calls active on this thread.
		ErrorCodeName{"RPC_S_CALL_FAILED", RPC_S_CALL_FAILED},  //! The remote procedure call failed.
		ErrorCodeName{"RPC_S_CALL_FAILED_DNE", RPC_S_CALL_FAILED_DNE},  //! The remote procedure call failed and did not execute.
		ErrorCodeName{"RPC_S_PROTOCOL_ERROR", RPC_S_PROTOCOL_ERROR},  //! A remote procedure call (RPC) protocol error occurred.
		ErrorCodeName{"RPC_S_PROXY_ACCESS_DENIED", RPC_S_PROXY_ACCESS_DENIED},  //! Access to the HTTP proxy is denied.
		ErrorCodeName{"RPC_S_UNSUPPORTED_TRANS_SYN", RPC_S_UNSUPPORTED_TRANS_SYN},  //! The transfer syntax is not supported by the RPC server.
		ErrorCodeName{"RPC_S_UNSUPPORTED_TYPE", RPC_S_UNSUPPORTED_TYPE},  //! The universal unique identifier (UUID) type is not supported.
		ErrorCodeName{"RPC_S_INVALID_TAG", RPC_S_INVALID_TAG},  //! The tag is invalid.
		ErrorCodeName{"RPC_S_INVALID_BOUND", RPC_S_INVALID_BOUND},  //! The array bounds are invalid.
		ErrorCodeName{"RPC_S_NO_ENTRY_NAME", RPC_S_NO_ENTRY_NAME},  //! The binding does not contain an entry name.
		ErrorCodeName{"RPC_S_INVALID_NAME_SYNTAX", RPC_S_INVALID_NAME_SYNTAX},  //! The name syntax is invalid.
		ErrorCodeName{"RPC_S_UNSUPPORTED_NAME_SYNTAX", RPC_S_UNSUPPORTED_NAME_SYNTAX},  //! The name syntax is not supported.
		ErrorCodeName{"RPC_S_UUID_NO_ADDRESS", RPC_S_UUID_NO_ADDRESS},  //! No network address is available to use to construct a universal unique identifier (UUID).
		ErrorCodeName{"RPC_S_DUPLICATE_ENDPOINT", RPC_S_DUPLICATE_ENDPOINT},  //! The endpoint is a duplicate.
		ErrorCodeName{"RPC_S_UNKNOWN_AUTHN_TYPE", RPC_S_UNKNOWN_AUTHN_TYPE},  //! The authentication type is unknown.
		ErrorCodeName{"RPC_S_MAX_CALLS_TOO_SMALL", RPC_S_MAX_CALLS_TOO_SMALL},  //! The maximum number of calls is too small.
		ErrorCodeName{"RPC_S_STRING_TOO_LONG", RPC_S_STRING_TOO_LONG},  //! The string is too long.
		ErrorCodeName{"RPC_S_PROTSEQ_NOT_FOUND", RPC_S_PROTSEQ_NOT_FOUND},  //! The RPC protocol sequence was not found.
		ErrorCodeName{"RPC_S_PROCNUM_OUT_OF_RANGE", RPC_S_PROCNUM_OUT_OF_RANGE},  //! The procedure number is out of range.
		ErrorCodeName{"RPC_S_BINDING_HAS_NO_AUTH", RPC_S_BINDING_HAS_NO_AUTH},  //! The binding does not contain any authentication information.
		ErrorCodeName{"RPC_S_UNKNOWN_AUTHN_SERVICE", RPC_S_UNKNOWN_AUTHN_SERVICE},  //! The authentication service is unknown.
		ErrorCodeName{"RPC_S_UNKNOWN_AUTHN_LEVEL", RPC_S_UNKNOWN_AUTHN_LEVEL},  //! The authentication level is unknown.
		ErrorCodeName{"RPC_S_INVALID_AUTH_IDENTITY", RPC_S_INVALID_AUTH_IDENTITY},  //! The security context is invalid.
		ErrorCodeName{"RPC_S_UNKNOWN_AUTHZ_SERVICE", RPC_S_UNKNOWN_AUTHZ_SERVICE},  //! The authorization service is unknown.
		ErrorCodeName{"EPT_S_INVALID_ENTRY", EPT_S_INVALID_ENTRY},  //! The entry is invalid.
		ErrorCodeName{"EPT_S_CANT_PERFORM_OP", EPT_S_CANT_PERFORM_OP},  //! The server endpoint cannot perform the operation.
		ErrorCodeName{"EPT_S_NOT_REGISTERED", EPT_S_NOT_REGISTERED},  //! There are no more endpoints available from the endpoint mapper.
		ErrorCodeName{"RPC_S_NOTHING_TO_EXPORT", RPC_S_NOTHING_TO_EXPORT},  //! No interfaces have been exported.
		ErrorCodeName{"RPC_S_INCOMPLETE_NAME", RPC_S_INCOMPLETE_NAME},  //! The entry name is incomplete.
		ErrorCodeName{"RPC_S_INVALID_VERS_OPTION", RPC_S_INVALID_VERS_OPTION},  //! The version option is invalid.
		ErrorCodeName{"RPC_S_NO_MORE_MEMBERS", RPC_S_NO_MORE_MEMBERS},  //! There are no more members.
		ErrorCodeName{"RPC_S_NOT_ALL_OBJS_UNEXPORTED", RPC_S_NOT_ALL_OBJS_UNEXPORTED},  //! There is nothing to unexport.
		ErrorCodeName{"RPC_S_INTERFACE_NOT_FOUND", RPC_S_INTERFACE_NOT_FOUND},  //! The interface was not found.
		ErrorCodeName{"RPC_S_ENTRY_ALREADY_EXISTS", RPC_S_ENTRY_ALREADY_EXISTS},  //! The entry already exists.
		ErrorCodeName{"RPC_S_ENTRY_NOT_FOUND", RPC_S_ENTRY_NOT_FOUND},  //! The entry is not found.
		ErrorCodeName{"RPC_S_NAME_SERVICE_UNAVAILABLE", RPC_S_NAME_SERVICE_UNAVAILABLE},  //! The name service is unavailable.
		ErrorCodeName{"RPC_S_INVALID_NAF_ID", RPC_S_INVALID_NAF_ID},  //! The network address family is invalid.
		ErrorCodeName{"RPC_S_CANNOT_SUPPORT", RPC_S_CANNOT_SUPPORT},  //! The requested operation is not supported.
		ErrorCodeName{"RPC_S_NO_CONTEXT_AVAILABLE", RPC_S_NO_CONTEXT_AVAILABLE},  //! No security context is available to allow impersonation.
		ErrorCodeName{"RPC_S_INTERNAL_ERROR", RPC_S_INTERNAL_ERROR},  //! An internal error occurred in a remote procedure call (RPC).
		ErrorCodeName{"RPC_S_ZERO_DIVIDE", RPC_S_ZERO_DIVIDE},  //! The RPC server attempted an integer division by zero.
		ErrorCodeName{"RPC_S_ADDRESS_ERROR", RPC_S_ADDRESS_ERROR},  //! An addressing error occurred in the RPC server.
		ErrorCodeName{"RPC_S_FP_DIV_ZERO", RPC_S_FP_DIV_ZERO},  //! A floating-point operation at the RPC server caused a division by zero.
		ErrorCodeName{"RPC_S_FP_UNDERFLOW", RPC_S_FP_UNDERFLOW},  //! A floating-point underflow occurred at the RPC server.
		ErrorCodeName{"RPC_S_FP_OVERFLOW", RPC_S_FP_OVERFLOW},  //! A floating-point overflow occurred at the RPC server.
		ErrorCodeName{"RPC_X_NO_MORE_ENTRIES", RPC_X_NO_MORE_ENTRIES},  //! The list of RPC servers available for the binding of auto handles has been exhausted.
		ErrorCodeName{"RPC_X_SS_CHAR_TRANS_OPEN_FAIL", RPC_X_SS_CHAR_TRANS_OPEN_FAIL},  //! Unable to open the character translation table file.
		ErrorCodeName{"RPC_X_SS_CHAR_TRANS_SHORT_FILE", RPC_X_SS_CHAR_TRANS_SHORT_FILE},  //! The file containing the character translation table has fewer than 512 bytes.
		ErrorCodeName{"RPC_X_SS_IN_NULL_CONTEXT", RPC_X_SS_IN_NULL_CONTEXT},  //! A null context handle was passed from the client to the host during a remote procedure call.
		ErrorCodeName{"RPC_X_SS_CONTEXT_DAMAGED", RPC_X_SS_CONTEXT_DAMAGED},  //! The context handle changed during a remote procedure call.
		ErrorCodeName{"RPC_X_SS_HANDLES_MISMATCH", RPC_X_SS_HANDLES_MISMATCH},  //! The binding handles passed to a remote procedure call do not match.
		ErrorCodeName{"RPC_X_SS_CANNOT_GET_CALL_HANDLE", RPC_X_SS_CANNOT_GET_CALL_HANDLE},  //! The stub is unable to get the remote procedure call handle.
		ErrorCodeName{"RPC_X_NULL_REF_POINTER", RPC_X_NULL_REF_POINTER},  //! A null reference pointer was passed to the stub.
		ErrorCodeName{"RPC_X_ENUM_VALUE_OUT_OF_RANGE", RPC_X_ENUM_VALUE_OUT_OF_RANGE},  //! The enumeration value is out of range.
		ErrorCodeName{"RPC_X_BYTE_COUNT_TOO_SMALL", RPC_X_BYTE_COUNT_TOO_SMALL},  //! The byte count is too small.
		ErrorCodeName{"RPC_X_BAD_STUB_DATA", RPC_X_BAD_STUB_DATA},  //! The stub received bad data.
		ErrorCodeName{"ERROR_INVALID_USER_BUFFER", ERROR_INVALID_USER_BUFFER},  //! The supplied user buffer is not valid for the requested operation.
		ErrorCodeName{"ERROR_UNRECOGNIZED_MEDIA", ERROR_UNRECOGNIZED_MEDIA},  //! The disk media is not recognized. It may not be formatted.
		ErrorCodeName{"ERROR_NO_TRUST_LSA_SECRET", ERROR_NO_TRUST_LSA_SECRET},  //! The workstation does not have a trust secret.
		ErrorCodeName{"ERROR_NO_TRUST_SAM_ACCOUNT", ERROR_NO_TRUST_SAM_ACCOUNT},  //! The security database on the server does not have a computer account for this workstation trust relationship.
		ErrorCodeName{"ERROR_TRUSTED_DOMAIN_FAILURE", ERROR_TRUSTED_DOMAIN_FAILURE},  //! The trust relationship between the primary domain and the trusted domain failed.
		ErrorCodeName{"ERROR_TRUSTED_RELATIONSHIP_FAILURE", ERROR_TRUSTED_RELATIONSHIP_FAILURE},  //! The trust relationship between this workstation and the primary domain failed.
		ErrorCodeName{"ERROR_TRUST_FAILURE", ERROR_TRUST_FAILURE},  //! The network logon failed.
		ErrorCodeName{"RPC_S_CALL_IN_PROGRESS", RPC_S_CALL_IN_PROGRESS},  //! A remote procedure call is already in progress for this thread.
		ErrorCodeName{"ERROR_NETLOGON_NOT_STARTED", ERROR_NETLOGON_NOT_STARTED},  //! An attempt was made to logon, but the network logon service was not started.
		ErrorCodeName{"ERROR_ACCOUNT_EXPIRED", ERROR_ACCOUNT_EXPIRED},  //! The user's account has expired.
		ErrorCodeName{"ERROR_REDIRECTOR_HAS_OPEN_HANDLES", ERROR_REDIRECTOR_HAS_OPEN_HANDLES},  //! The redirector is in use and cannot be unloaded.
		ErrorCodeName{"ERROR_PRINTER_DRIVER_ALREADY_INSTALLED", ERROR_PRINTER_DRIVER_ALREADY_INSTALLED},  //! The specified printer driver is already installed.
		ErrorCodeName{"ERROR_UNKNOWN_PORT", ERROR_UNKNOWN_PORT},  //! The specified port is unknown.
		ErrorCodeName{"ERROR_UNKNOWN_PRINTER_DRIVER", ERROR_UNKNOWN_PRINTER_DRIVER},  //! The printer driver is unknown.
		ErrorCodeName{"ERROR_UNKNOWN_PRINTPROCESSOR", ERROR_UNKNOWN_PRINTPROCESSOR},  //! The print processor is unknown.
		ErrorCodeName{"ERROR_INVALID_SEPARATOR_FILE", ERROR_INVALID_SEPARATOR_FILE},  //! The specified separator file is invalid.
		ErrorCodeName{"ERROR_INVALID_PRIORITY", ERROR_INVALID_PRIORITY},  //! The specified priority is invalid.
		ErrorCodeName{"ERROR_INVALID_PRINTER_NAME", ERROR_INVALID_PRINTER_NAME},  //! The printer name is invalid.
		ErrorCodeName{"ERROR_PRINTER_ALREADY_EXISTS", ERROR_PRINTER_ALREADY_EXISTS},  //! The printer already exists.
		ErrorCodeName{"ERROR_INVALID_PRINTER_COMMAND", ERROR_INVALID_PRINTER_COMMAND},  //! The printer command is invalid.
		ErrorCodeName{"ERROR_INVALID_DATATYPE", ERROR_INVALID_DATATYPE},  //! The specified datatype is invalid.
		ErrorCodeName{"ERROR_INVALID_ENVIRONMENT", ERROR_INVALID_ENVIRONMENT},  //! The environment specified is invalid.
		ErrorCodeName{"RPC_S_NO_MORE_BINDINGS", RPC_S_NO_MORE_BINDINGS},  //! There are no more bindings.
		ErrorCodeName{"ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT", ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT},  //! The account used is an interdomain trust account. Use your global user account or local user account to access this server.
		ErrorCodeName{"ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT", ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT},  //! The account used is a computer account. Use your global user account or local user account to access this server.
		ErrorCodeName{"ERROR_NOLOGON_SERVER_TRUST_ACCOUNT", ERROR_NOLOGON_SERVER_TRUST_ACCOUNT},  //! The account used is a server trust account. Use your global user account or local user account to access this server.
		ErrorCodeName{"ERROR_DOMAIN_TRUST_INCONSISTENT", ERROR_DOMAIN_TRUST_INCONSISTENT},  //! The name or security ID (SID) of the domain specified is inconsistent with the trust information for that domain.
		ErrorCodeName{"ERROR_SERVER_HAS_OPEN_HANDLES", ERROR_SERVER_HAS_OPEN_HANDLES},  //! The server is in use and cannot be unloaded.
		ErrorCodeName{"ERROR_RESOURCE_DATA_NOT_FOUND", ERROR_RESOURCE_DATA_NOT_FOUND},  //! The specified image file did not contain a resource section.
		ErrorCodeName{"ERROR_RESOURCE_TYPE_NOT_FOUND", ERROR_RESOURCE_TYPE_NOT_FOUND},  //! The specified resource type cannot be found in the image file.
		ErrorCodeName{"ERROR_RESOURCE_NAME_NOT_FOUND", ERROR_RESOURCE_NAME_NOT_FOUND},  //! The specified resource name cannot be found in the image file.
		ErrorCodeName{"ERROR_RESOURCE_LANG_NOT_FOUND", ERROR_RESOURCE_LANG_NOT_FOUND},  //! The specified resource language ID cannot be found in the image file.
		ErrorCodeName{"ERROR_NOT_ENOUGH_QUOTA", ERROR_NOT_ENOUGH_QUOTA},  //! Not enough quota is available to process this command.
		ErrorCodeName{"RPC_S_NO_INTERFACES", RPC_S_NO_INTERFACES},  //! No interfaces have been registered.
		ErrorCodeName{"RPC_S_CALL_CANCELLED", RPC_S_CALL_CANCELLED},  //! The remote procedure call was cancelled.
		ErrorCodeName{"RPC_S_BINDING_INCOMPLETE", RPC_S_BINDING_INCOMPLETE},  //! The binding handle does not contain all required information.
		ErrorCodeName{"RPC_S_COMM_FAILURE", RPC_S_COMM_FAILURE},  //! A communications failure occurred during a remote procedure call.
		ErrorCodeName{"RPC_S_UNSUPPORTED_AUTHN_LEVEL", RPC_S_UNSUPPORTED_AUTHN_LEVEL},  //! The requested authentication level is not supported.
		ErrorCodeName{"RPC_S_NO_PRINC_NAME", RPC_S_NO_PRINC_NAME},  //! No principal name registered.
		ErrorCodeName{"RPC_S_NOT_RPC_ERROR", RPC_S_NOT_RPC_ERROR},  //! The error specified is not a valid Windows RPC error code.
		ErrorCodeName{"RPC_S_UUID_LOCAL_ONLY", RPC_S_UUID_LOCAL_ONLY},  //! A UUID that is valid only on this computer has been allocated.
		ErrorCodeName{"RPC_S_SEC_PKG_ERROR", RPC_S_SEC_PKG_ERROR},  //! A security package specific error occurred.
		ErrorCodeName{"RPC_S_NOT_CANCELLED", RPC_S_NOT_CANCELLED},  //! Thread is not canceled.
		ErrorCodeName{"RPC_X_INVALID_ES_ACTION", RPC_X_INVALID_ES_ACTION},  //! Invalid operation on the encoding/decoding handle.
		ErrorCodeName{"RPC_X_WRONG_ES_VERSION", RPC_X_WRONG_ES_VERSION},  //! Incompatible version of the serializing package.
		ErrorCodeName{"RPC_X_WRONG_STUB_VERSION", RPC_X_WRONG_STUB_VERSION},  //! Incompatible version of the RPC stub.
		ErrorCodeName{"RPC_X_INVALID_PIPE_OBJECT", RPC_X_INVALID_PIPE_OBJECT},  //! The RPC pipe object is invalid or corrupted.
		ErrorCodeName{"RPC_X_WRONG_PIPE_ORDER", RPC_X_WRONG_PIPE_ORDER},  //! An invalid operation was attempted on an RPC pipe object.
		ErrorCodeName{"RPC_X_WRONG_PIPE_VERSION", RPC_X_WRONG_PIPE_VERSION},  //! Unsupported RPC pipe version.
		ErrorCodeName{"RPC_S_COOKIE_AUTH_FAILED", RPC_S_COOKIE_AUTH_FAILED},  //! HTTP proxy server rejected the connection because the cookie authentication failed.
		ErrorCodeName{"RPC_S_GROUP_MEMBER_NOT_FOUND", RPC_S_GROUP_MEMBER_NOT_FOUND},  //! The group member was not found.
		ErrorCodeName{"EPT_S_CANT_CREATE", EPT_S_CANT_CREATE},  //! The endpoint mapper database entry could not be created.
		ErrorCodeName{"RPC_S_INVALID_OBJECT", RPC_S_INVALID_OBJECT},  //! The object universal unique identifier (UUID) is the nil UUID.
		ErrorCodeName{"ERROR_INVALID_TIME", ERROR_INVALID_TIME},  //! The specified time is invalid.
		ErrorCodeName{"ERROR_INVALID_FORM_NAME", ERROR_INVALID_FORM_NAME},  //! The specified form name is invalid.
		ErrorCodeName{"ERROR_INVALID_FORM_SIZE", ERROR_INVALID_FORM_SIZE},  //! The specified form size is invalid.
		ErrorCodeName{"ERROR_ALREADY_WAITING", ERROR_ALREADY_WAITING},  //! The specified printer handle is already being waited on.
		ErrorCodeName{"ERROR_PRINTER_DELETED", ERROR_PRINTER_DELETED},  //! The specified printer has been deleted.
		ErrorCodeName{"ERROR_INVALID_PRINTER_STATE", ERROR_INVALID_PRINTER_STATE},  //! The state of the printer is invalid.
		ErrorCodeName{"ERROR_PASSWORD_MUST_CHANGE", ERROR_PASSWORD_MUST_CHANGE},  //! The user's password must be changed before signing in.
		ErrorCodeName{"ERROR_DOMAIN_CONTROLLER_NOT_FOUND", ERROR_DOMAIN_CONTROLLER_NOT_FOUND},  //! Could not find the domain controller for this domain.
		ErrorCodeName{"ERROR_ACCOUNT_LOCKED_OUT", ERROR_ACCOUNT_LOCKED_OUT},  //! The referenced account is currently locked out and may not be logged on to.
		ErrorCodeName{"OR_INVALID_OXID", OR_INVALID_OXID},  //! The object exporter specified was not found.
		ErrorCodeName{"OR_INVALID_OID", OR_INVALID_OID},  //! The object specified was not found.
		ErrorCodeName{"OR_INVALID_SET", OR_INVALID_SET},  //! The object resolver set specified was not found.
		ErrorCodeName{"RPC_S_SEND_INCOMPLETE", RPC_S_SEND_INCOMPLETE},  //! Some data remains to be sent in the request buffer.
		ErrorCodeName{"RPC_S_INVALID_ASYNC_HANDLE", RPC_S_INVALID_ASYNC_HANDLE},  //! Invalid asynchronous remote procedure call handle.
		ErrorCodeName{"RPC_S_INVALID_ASYNC_CALL", RPC_S_INVALID_ASYNC_CALL},  //! Invalid asynchronous RPC call handle for this operation.
		ErrorCodeName{"RPC_X_PIPE_CLOSED", RPC_X_PIPE_CLOSED},  //! The RPC pipe object has already been closed.
		ErrorCodeName{"RPC_X_PIPE_DISCIPLINE_ERROR", RPC_X_PIPE_DISCIPLINE_ERROR},  //! The RPC call completed before all pipes were processed.
		ErrorCodeName{"RPC_X_PIPE_EMPTY", RPC_X_PIPE_EMPTY},  //! No more data is available from the RPC pipe.
		ErrorCodeName{"ERROR_NO_SITENAME", ERROR_NO_SITENAME},  //! No site name is available for this machine.
		ErrorCodeName{"ERROR_CANT_ACCESS_FILE", ERROR_CANT_ACCESS_FILE},  //! The file cannot be accessed by the system.
		ErrorCodeName{"ERROR_CANT_RESOLVE_FILENAME", ERROR_CANT_RESOLVE_FILENAME},  //! The name of the file cannot be resolved by the system.
		ErrorCodeName{"RPC_S_ENTRY_TYPE_MISMATCH", RPC_S_ENTRY_TYPE_MISMATCH},  //! The entry is not of the expected type.
		ErrorCodeName{"RPC_S_NOT_ALL_OBJS_EXPORTED", RPC_S_NOT_ALL_OBJS_EXPORTED},  //! Not all object UUIDs could be exported to the specified entry.
		ErrorCodeName{"RPC_S_INTERFACE_NOT_EXPORTED", RPC_S_INTERFACE_NOT_EXPORTED},  //! Interface could not be exported to the specified entry.
		ErrorCodeName{"RPC_S_PROFILE_NOT_ADDED", RPC_S_PROFILE_NOT_ADDED},  //! The specified profile entry could not be added.
		ErrorCodeName{"RPC_S_PRF_ELT_NOT_ADDED", RPC_S_PRF_ELT_NOT_ADDED},  //! The specified profile element could not be added.
		ErrorCodeName{"RPC_S_PRF_ELT_NOT_REMOVED", RPC_S_PRF_ELT_NOT_REMOVED},  //! The specified profile element could not be removed.
		ErrorCodeName{"RPC_S_GRP_ELT_NOT_ADDED", RPC_S_GRP_ELT_NOT_ADDED},  //! The group element could not be added.
		ErrorCodeName{"RPC_S_GRP_ELT_NOT_REMOVED", RPC_S_GRP_ELT_NOT_REMOVED},  //! The group element could not be removed.
		ErrorCodeName{"ERROR_KM_DRIVER_BLOCKED", ERROR_KM_DRIVER_BLOCKED},  //! The printer driver is not compatible with a policy enabled on your computer that blocks NT 4.0 drivers.
		ErrorCodeName{"ERROR_CONTEXT_EXPIRED", ERROR_CONTEXT_EXPIRED},  //! The context has expired and can no longer be used.
		ErrorCodeName{"ERROR_PER_USER_TRUST_QUOTA_EXCEEDED", ERROR_PER_USER_TRUST_QUOTA_EXCEEDED},  //! The current user's delegated trust creation quota has been exceeded.
		ErrorCodeName{"ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED", ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED},  //! The total delegated trust creation quota has been exceeded.
		ErrorCodeName{"ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED", ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED},  //! The current user's delegated trust deletion quota has been exceeded.
		ErrorCodeName{"ERROR_AUTHENTICATION_FIREWALL_FAILED", ERROR_AUTHENTICATION_FIREWALL_FAILED},  //! The computer you are signing into is protected by an authentication firewall. The specified account is not allowed to authenticate to the computer.
		ErrorCodeName{"ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED", ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED},  //! Remote connections to the Print Spooler are blocked by a policy set on your machine.
		ErrorCodeName{"ERROR_NTLM_BLOCKED", ERROR_NTLM_BLOCKED},  //! Authentication failed because NTLM authentication has been disabled.
		ErrorCodeName{"ERROR_PASSWORD_CHANGE_REQUIRED", ERROR_PASSWORD_CHANGE_REQUIRED},  //! Logon Failure: EAS policy requires that the user change their password before this operation can be performed.
		ErrorCodeName{"ERROR_INVALID_PIXEL_FORMAT", ERROR_INVALID_PIXEL_FORMAT},  //! The pixel format is invalid.
		ErrorCodeName{"ERROR_BAD_DRIVER", ERROR_BAD_DRIVER},  //! The specified driver is invalid.
		ErrorCodeName{"ERROR_INVALID_WINDOW_STYLE", ERROR_INVALID_WINDOW_STYLE},  //! The window style or class attribute is invalid for this operation.
		ErrorCodeName{"ERROR_METAFILE_NOT_SUPPORTED", ERROR_METAFILE_NOT_SUPPORTED},  //! The requested metafile operation is not supported.
		ErrorCodeName{"ERROR_TRANSFORM_NOT_SUPPORTED", ERROR_TRANSFORM_NOT_SUPPORTED},  //! The requested transformation operation is not supported.
		ErrorCodeName{"ERROR_CLIPPING_NOT_SUPPORTED", ERROR_CLIPPING_NOT_SUPPORTED},  //! The requested clipping operation is not supported.
		ErrorCodeName{"ERROR_INVALID_CMM", ERROR_INVALID_CMM},  //! The specified color management module is invalid.
		ErrorCodeName{"ERROR_INVALID_PROFILE", ERROR_INVALID_PROFILE},  //! The specified color profile is invalid.
		ErrorCodeName{"ERROR_TAG_NOT_FOUND", ERROR_TAG_NOT_FOUND},  //! The specified tag was not found.
		ErrorCodeName{"ERROR_TAG_NOT_PRESENT", ERROR_TAG_NOT_PRESENT},  //! A required tag is not present.
		ErrorCodeName{"ERROR_DUPLICATE_TAG", ERROR_DUPLICATE_TAG},  //! The specified tag is already present.
		ErrorCodeName{"ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE", ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE},  //! The specified color profile is not associated with the specified device.
		ErrorCodeName{"ERROR_PROFILE_NOT_FOUND", ERROR_PROFILE_NOT_FOUND},  //! The specified color profile was not found.
		ErrorCodeName{"ERROR_INVALID_COLORSPACE", ERROR_INVALID_COLORSPACE},  //! The specified color space is invalid.
		ErrorCodeName{"ERROR_ICM_NOT_ENABLED", ERROR_ICM_NOT_ENABLED},  //! Image Color Management is not enabled.
		ErrorCodeName{"ERROR_DELETING_ICM_XFORM", ERROR_DELETING_ICM_XFORM},  //! There was an error while deleting the color transform.
		ErrorCodeName{"ERROR_INVALID_TRANSFORM", ERROR_INVALID_TRANSFORM},  //! The specified color transform is invalid.
		ErrorCodeName{"ERROR_COLORSPACE_MISMATCH", ERROR_COLORSPACE_MISMATCH},  //! The specified transform does not match the bitmap's color space.
		ErrorCodeName{"ERROR_INVALID_COLORINDEX", ERROR_INVALID_COLORINDEX},  //! The specified named color index is not present in the profile.
		ErrorCodeName{"ERROR_PROFILE_DOES_NOT_MATCH_DEVICE", ERROR_PROFILE_DOES_NOT_MATCH_DEVICE},  //! The specified profile is intended for a device of a different type than the specified device.
		ErrorCodeName{"ERROR_CONNECTED_OTHER_PASSWORD", ERROR_CONNECTED_OTHER_PASSWORD},  //! The network connection was made successfully, but the user had to be prompted for a password other than the one originally specified.
		ErrorCodeName{"ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT", ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT},  //! The network connection was made successfully using default credentials.
		ErrorCodeName{"ERROR_BAD_USERNAME", ERROR_BAD_USERNAME},  //! The specified username is invalid.
		ErrorCodeName{"ERROR_NOT_CONNECTED", ERROR_NOT_CONNECTED},  //! This network connection does not exist.
		ErrorCodeName{"ERROR_OPEN_FILES", ERROR_OPEN_FILES},  //! This network connection has files open or requests pending.
		ErrorCodeName{"ERROR_ACTIVE_CONNECTIONS", ERROR_ACTIVE_CONNECTIONS},  //! Active connections still exist.
		ErrorCodeName{"ERROR_DEVICE_IN_USE", ERROR_DEVICE_IN_USE},  //! The device is in use by an active process and cannot be disconnected.
		ErrorCodeName{"ERROR_UNKNOWN_PRINT_MONITOR", ERROR_UNKNOWN_PRINT_MONITOR},  //! The specified print monitor is unknown.
		ErrorCodeName{"ERROR_PRINTER_DRIVER_IN_USE", ERROR_PRINTER_DRIVER_IN_USE},  //! The specified printer driver is currently in use.
		ErrorCodeName{"ERROR_SPOOL_FILE_NOT_FOUND", ERROR_SPOOL_FILE_NOT_FOUND},  //! The spool file was not found.
		ErrorCodeName{"ERROR_SPL_NO_STARTDOC", ERROR_SPL_NO_STARTDOC},  //! A StartDocPrinter call was not issued.
		ErrorCodeName{"ERROR_SPL_NO_ADDJOB", ERROR_SPL_NO_ADDJOB},  //! An AddJob call was not issued.
		ErrorCodeName{"ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED", ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED},  //! The specified print processor has already been installed.
		ErrorCodeName{"ERROR_PRINT_MONITOR_ALREADY_INSTALLED", ERROR_PRINT_MONITOR_ALREADY_INSTALLED},  //! The specified print monitor has already been installed.
		ErrorCodeName{"ERROR_INVALID_PRINT_MONITOR", ERROR_INVALID_PRINT_MONITOR},  //! The specified print monitor does not have the required functions.
		ErrorCodeName{"ERROR_PRINT_MONITOR_IN_USE", ERROR_PRINT_MONITOR_IN_USE},  //! The specified print monitor is currently in use.
		ErrorCodeName{"ERROR_PRINTER_HAS_JOBS_QUEUED", ERROR_PRINTER_HAS_JOBS_QUEUED},  //! The requested operation is not allowed when there are jobs queued to the printer.
		ErrorCodeName{"ERROR_SUCCESS_REBOOT_REQUIRED", ERROR_SUCCESS_REBOOT_REQUIRED},  //! The requested operation is successful. Changes will not be effective until the system is rebooted.
		ErrorCodeName{"ERROR_SUCCESS_RESTART_REQUIRED", ERROR_SUCCESS_RESTART_REQUIRED},  //! The requested operation is successful. Changes will not be effective until the service is restarted.
		ErrorCodeName{"ERROR_PRINTER_NOT_FOUND", ERROR_PRINTER_NOT_FOUND},  //! No printers were found.
		ErrorCodeName{"ERROR_PRINTER_DRIVER_WARNED", ERROR_PRINTER_DRIVER_WARNED},  //! The printer driver is known to be unreliable.
		ErrorCodeName{"ERROR_PRINTER_DRIVER_BLOCKED", ERROR_PRINTER_DRIVER_BLOCKED},  //! The printer driver is known to harm the system.
		ErrorCodeName{"ERROR_PRINTER_DRIVER_PACKAGE_IN_USE", ERROR_PRINTER_DRIVER_PACKAGE_IN_USE},  //! The specified printer driver package is currently in use.
		ErrorCodeName{"ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND", ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND},  //! Unable to find a core driver package that is required by the printer driver package.
		ErrorCodeName{"ERROR_FAIL_REBOOT_REQUIRED", ERROR_FAIL_REBOOT_REQUIRED},  //! The requested operation failed. A system reboot is required to roll back changes made.
		ErrorCodeName{"ERROR_FAIL_REBOOT_INITIATED", ERROR_FAIL_REBOOT_INITIATED},  //! The requested operation failed. A system reboot has been initiated to roll back changes made.
		ErrorCodeName{"ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED", ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED},  //! The specified printer driver was not found on the system and needs to be downloaded.
		ErrorCodeName{"ERROR_PRINT_JOB_RESTART_REQUIRED", ERROR_PRINT_JOB_RESTART_REQUIRED},  //! The requested print job has failed to print. A print system update requires the job to be resubmitted.
		ErrorCodeName{"ERROR_INVALID_PRINTER_DRIVER_MANIFEST", ERROR_INVALID_PRINTER_DRIVER_MANIFEST},  //! The printer driver does not contain a valid manifest, or contains too many manifests.
		ErrorCodeName{"ERROR_PRINTER_NOT_SHAREABLE", ERROR_PRINTER_NOT_SHAREABLE},  //! The specified printer cannot be shared.
		ErrorCodeName{"ERROR_REQUEST_PAUSED", ERROR_REQUEST_PAUSED},  //! The operation was paused.
		ErrorCodeName{"ERROR_IO_REISSUE_AS_CACHED", ERROR_IO_REISSUE_AS_CACHED},  //! Reissue the given operation as a cached IO operation.
		ErrorCodeName{"ERROR_WINS_INTERNAL", ERROR_WINS_INTERNAL},  //! WINS encountered an error while processing the command.
		ErrorCodeName{"ERROR_CAN_NOT_DEL_LOCAL_WINS", ERROR_CAN_NOT_DEL_LOCAL_WINS},  //! The local WINS cannot be deleted.
		ErrorCodeName{"ERROR_STATIC_INIT", ERROR_STATIC_INIT},  //! The importation from the file failed.
		ErrorCodeName{"ERROR_INC_BACKUP", ERROR_INC_BACKUP},  //! The backup failed. Was a full backup done before?
		ErrorCodeName{"ERROR_FULL_BACKUP", ERROR_FULL_BACKUP},  //! The backup failed. Check the directory to which you are backing the database.
		ErrorCodeName{"ERROR_REC_NON_EXISTENT", ERROR_REC_NON_EXISTENT},  //! The name does not exist in the WINS database.
		ErrorCodeName{"ERROR_RPL_NOT_ALLOWED", ERROR_RPL_NOT_ALLOWED},  //! Replication with a nonconfigured partner is not allowed.
		ErrorCodeName{"PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED", PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED},  //! The version of the supplied content information is not supported.
		ErrorCodeName{"PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO", PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO},  //! The supplied content information is malformed.
		ErrorCodeName{"PEERDIST_ERROR_MISSING_DATA", PEERDIST_ERROR_MISSING_DATA},  //! The requested data cannot be found in local or peer caches.
		ErrorCodeName{"PEERDIST_ERROR_NO_MORE", PEERDIST_ERROR_NO_MORE},  //! No more data is available or required.
		ErrorCodeName{"PEERDIST_ERROR_NOT_INITIALIZED", PEERDIST_ERROR_NOT_INITIALIZED},  //! The supplied object has not been initialized.
		ErrorCodeName{"PEERDIST_ERROR_ALREADY_INITIALIZED", PEERDIST_ERROR_ALREADY_INITIALIZED},  //! The supplied object has already been initialized.
		ErrorCodeName{"PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS", PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS},  //! A shutdown operation is already in progress.
		ErrorCodeName{"PEERDIST_ERROR_INVALIDATED", PEERDIST_ERROR_INVALIDATED},  //! The supplied object has already been invalidated.
		ErrorCodeName{"PEERDIST_ERROR_ALREADY_EXISTS", PEERDIST_ERROR_ALREADY_EXISTS},  //! An element already exists and was not replaced.
		ErrorCodeName{"PEERDIST_ERROR_OPERATION_NOTFOUND", PEERDIST_ERROR_OPERATION_NOTFOUND},  //! Cannot cancel the requested operation as it has already been completed.
		ErrorCodeName{"PEERDIST_ERROR_ALREADY_COMPLETED", PEERDIST_ERROR_ALREADY_COMPLETED},  //! Can not perform the reqested operation because it has already been carried out.
		ErrorCodeName{"PEERDIST_ERROR_OUT_OF_BOUNDS", PEERDIST_ERROR_OUT_OF_BOUNDS},  //! An operation accessed data beyond the bounds of valid data.
		ErrorCodeName{"PEERDIST_ERROR_VERSION_UNSUPPORTED", PEERDIST_ERROR_VERSION_UNSUPPORTED},  //! The requested version is not supported.
		ErrorCodeName{"PEERDIST_ERROR_INVALID_CONFIGURATION", PEERDIST_ERROR_INVALID_CONFIGURATION},  //! A configuration value is invalid.
		ErrorCodeName{"PEERDIST_ERROR_NOT_LICENSED", PEERDIST_ERROR_NOT_LICENSED},  //! The SKU is not licensed.
		ErrorCodeName{"PEERDIST_ERROR_SERVICE_UNAVAILABLE", PEERDIST_ERROR_SERVICE_UNAVAILABLE},  //! PeerDist Service is still initializing and will be available shortly.
		ErrorCodeName{"PEERDIST_ERROR_TRUST_FAILURE", PEERDIST_ERROR_TRUST_FAILURE},  //! Communication with one or more computers will be temporarily blocked due to recent errors.
		ErrorCodeName{"ERROR_DHCP_ADDRESS_CONFLICT", ERROR_DHCP_ADDRESS_CONFLICT},  //! The DHCP client has obtained an IP address that is already in use on the network. The local interface will be disabled until the DHCP client can obtain a new address.
		ErrorCodeName{"ERROR_WMI_GUID_NOT_FOUND", ERROR_WMI_GUID_NOT_FOUND},  //! The GUID passed was not recognized as valid by a WMI data provider.
		ErrorCodeName{"ERROR_WMI_INSTANCE_NOT_FOUND", ERROR_WMI_INSTANCE_NOT_FOUND},  //! The instance name passed was not recognized as valid by a WMI data provider.
		ErrorCodeName{"ERROR_WMI_ITEMID_NOT_FOUND", ERROR_WMI_ITEMID_NOT_FOUND},  //! The data item ID passed was not recognized as valid by a WMI data provider.
		ErrorCodeName{"ERROR_WMI_TRY_AGAIN", ERROR_WMI_TRY_AGAIN},  //! The WMI request could not be completed and should be retried.
		ErrorCodeName{"ERROR_WMI_DP_NOT_FOUND", ERROR_WMI_DP_NOT_FOUND},  //! The WMI data provider could not be located.
		ErrorCodeName{"ERROR_WMI_UNRESOLVED_INSTANCE_REF", ERROR_WMI_UNRESOLVED_INSTANCE_REF},  //! The WMI data provider references an instance set that has not been registered.
		ErrorCodeName{"ERROR_WMI_ALREADY_ENABLED", ERROR_WMI_ALREADY_ENABLED},  //! The WMI data block or event notification has already been enabled.
		ErrorCodeName{"ERROR_WMI_GUID_DISCONNECTED", ERROR_WMI_GUID_DISCONNECTED},  //! The WMI data block is no longer available.
		ErrorCodeName{"ERROR_WMI_SERVER_UNAVAILABLE", ERROR_WMI_SERVER_UNAVAILABLE},  //! The WMI data service is not available.
		ErrorCodeName{"ERROR_WMI_DP_FAILED", ERROR_WMI_DP_FAILED},  //! The WMI data provider failed to carry out the request.
		ErrorCodeName{"ERROR_WMI_INVALID_MOF", ERROR_WMI_INVALID_MOF},  //! The WMI MOF information is not valid.
		ErrorCodeName{"ERROR_WMI_INVALID_REGINFO", ERROR_WMI_INVALID_REGINFO},  //! The WMI registration information is not valid.
		ErrorCodeName{"ERROR_WMI_ALREADY_DISABLED", ERROR_WMI_ALREADY_DISABLED},  //! The WMI data block or event notification has already been disabled.
		ErrorCodeName{"ERROR_WMI_READ_ONLY", ERROR_WMI_READ_ONLY},  //! The WMI data item or data block is read only.
		ErrorCodeName{"ERROR_WMI_SET_FAILURE", ERROR_WMI_SET_FAILURE},  //! The WMI data item or data block could not be changed.
		ErrorCodeName{"ERROR_NOT_APPCONTAINER", ERROR_NOT_APPCONTAINER},  //! This operation is only valid in the context of an app container.
		ErrorCodeName{"ERROR_APPCONTAINER_REQUIRED", ERROR_APPCONTAINER_REQUIRED},  //! This application can only run in the context of an app container.
		ErrorCodeName{"ERROR_NOT_SUPPORTED_IN_APPCONTAINER", ERROR_NOT_SUPPORTED_IN_APPCONTAINER},  //! This functionality is not supported in the context of an app container.
		ErrorCodeName{"ERROR_INVALID_PACKAGE_SID_LENGTH", ERROR_INVALID_PACKAGE_SID_LENGTH},  //! The length of the SID supplied is not a valid length for app container SIDs.
		ErrorCodeName{"ERROR_INVALID_MEDIA", ERROR_INVALID_MEDIA},  //! The media identifier does not represent a valid medium.
		ErrorCodeName{"ERROR_INVALID_LIBRARY", ERROR_INVALID_LIBRARY},  //! The library identifier does not represent a valid library.
		ErrorCodeName{"ERROR_INVALID_MEDIA_POOL", ERROR_INVALID_MEDIA_POOL},  //! The media pool identifier does not represent a valid media pool.
		ErrorCodeName{"ERROR_DRIVE_MEDIA_MISMATCH", ERROR_DRIVE_MEDIA_MISMATCH},  //! The drive and medium are not compatible or exist in different libraries.
		ErrorCodeName{"ERROR_MEDIA_OFFLINE", ERROR_MEDIA_OFFLINE},  //! The medium currently exists in an offline library and must be online to perform this operation.
		ErrorCodeName{"ERROR_LIBRARY_OFFLINE", ERROR_LIBRARY_OFFLINE},  //! The operation cannot be performed on an offline library.
		ErrorCodeName{"ERROR_EMPTY", ERROR_EMPTY},  //! The library, drive, or media pool is empty.
		ErrorCodeName{"ERROR_NOT_EMPTY", ERROR_NOT_EMPTY},  //! The library, drive, or media pool must be empty to perform this operation.
		ErrorCodeName{"ERROR_MEDIA_UNAVAILABLE", ERROR_MEDIA_UNAVAILABLE},  //! No media is currently available in this media pool or library.
		ErrorCodeName{"ERROR_RESOURCE_DISABLED", ERROR_RESOURCE_DISABLED},  //! A resource required for this operation is disabled.
		ErrorCodeName{"ERROR_INVALID_CLEANER", ERROR_INVALID_CLEANER},  //! The media identifier does not represent a valid cleaner.
		ErrorCodeName{"ERROR_UNABLE_TO_CLEAN", ERROR_UNABLE_TO_CLEAN},  //! The drive cannot be cleaned or does not support cleaning.
		ErrorCodeName{"ERROR_OBJECT_NOT_FOUND", ERROR_OBJECT_NOT_FOUND},  //! The object identifier does not represent a valid object.
		ErrorCodeName{"ERROR_DATABASE_FAILURE", ERROR_DATABASE_FAILURE},  //! Unable to read from or write to the database.
		ErrorCodeName{"ERROR_DATABASE_FULL", ERROR_DATABASE_FULL},  //! The database is full.
		ErrorCodeName{"ERROR_MEDIA_INCOMPATIBLE", ERROR_MEDIA_INCOMPATIBLE},  //! The medium is not compatible with the device or media pool.
		ErrorCodeName{"ERROR_RESOURCE_NOT_PRESENT", ERROR_RESOURCE_NOT_PRESENT},  //! The resource required for this operation does not exist.
		ErrorCodeName{"ERROR_INVALID_OPERATION", ERROR_INVALID_OPERATION},  //! The operation identifier is not valid.
		ErrorCodeName{"ERROR_MEDIA_NOT_AVAILABLE", ERROR_MEDIA_NOT_AVAILABLE},  //! The media is not mounted or ready for use.
		ErrorCodeName{"ERROR_DEVICE_NOT_AVAILABLE", ERROR_DEVICE_NOT_AVAILABLE},  //! The device is not ready for use.
		ErrorCodeName{"ERROR_REQUEST_REFUSED", ERROR_REQUEST_REFUSED},  //! The operator or administrator has refused the request.
		ErrorCodeName{"ERROR_INVALID_DRIVE_OBJECT", ERROR_INVALID_DRIVE_OBJECT},  //! The drive identifier does not represent a valid drive.
		ErrorCodeName{"ERROR_LIBRARY_FULL", ERROR_LIBRARY_FULL},  //! Library is full. No slot is available for use.
		ErrorCodeName{"ERROR_MEDIUM_NOT_ACCESSIBLE", ERROR_MEDIUM_NOT_ACCESSIBLE},  //! The transport cannot access the medium.
		ErrorCodeName{"ERROR_UNABLE_TO_LOAD_MEDIUM", ERROR_UNABLE_TO_LOAD_MEDIUM},  //! Unable to load the medium into the drive.
		ErrorCodeName{"ERROR_UNABLE_TO_INVENTORY_DRIVE", ERROR_UNABLE_TO_INVENTORY_DRIVE},  //! Unable to retrieve the drive status.
		ErrorCodeName{"ERROR_UNABLE_TO_INVENTORY_SLOT", ERROR_UNABLE_TO_INVENTORY_SLOT},  //! Unable to retrieve the slot status.
		ErrorCodeName{"ERROR_UNABLE_TO_INVENTORY_TRANSPORT", ERROR_UNABLE_TO_INVENTORY_TRANSPORT},  //! Unable to retrieve status about the transport.
		ErrorCodeName{"ERROR_TRANSPORT_FULL", ERROR_TRANSPORT_FULL},  //! Cannot use the transport because it is already in use.
		ErrorCodeName{"ERROR_CONTROLLING_IEPORT", ERROR_CONTROLLING_IEPORT},  //! Unable to open or close the inject/eject port.
		ErrorCodeName{"ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA", ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA},  //! Unable to eject the medium because it is in a drive.
		ErrorCodeName{"ERROR_CLEANER_SLOT_SET", ERROR_CLEANER_SLOT_SET},  //! A cleaner slot is already reserved.
		ErrorCodeName{"ERROR_CLEANER_SLOT_NOT_SET", ERROR_CLEANER_SLOT_NOT_SET},  //! A cleaner slot is not reserved.
		ErrorCodeName{"ERROR_CLEANER_CARTRIDGE_SPENT", ERROR_CLEANER_CARTRIDGE_SPENT},  //! The cleaner cartridge has performed the maximum number of drive cleanings.
		ErrorCodeName{"ERROR_UNEXPECTED_OMID", ERROR_UNEXPECTED_OMID},  //! Unexpected on-medium identifier.
		ErrorCodeName{"ERROR_CANT_DELETE_LAST_ITEM", ERROR_CANT_DELETE_LAST_ITEM},  //! The last remaining item in this group or resource cannot be deleted.
		ErrorCodeName{"ERROR_MESSAGE_EXCEEDS_MAX_SIZE", ERROR_MESSAGE_EXCEEDS_MAX_SIZE},  //! The message provided exceeds the maximum size allowed for this parameter.
		ErrorCodeName{"ERROR_VOLUME_CONTAINS_SYS_FILES", ERROR_VOLUME_CONTAINS_SYS_FILES},  //! The volume contains system or paging files.
		ErrorCodeName{"ERROR_INDIGENOUS_TYPE", ERROR_INDIGENOUS_TYPE},  //! The media type cannot be removed from this library since at least one drive in the library reports it can support this media type.
		ErrorCodeName{"ERROR_NO_SUPPORTING_DRIVES", ERROR_NO_SUPPORTING_DRIVES},  //! This offline media cannot be mounted on this system since no enabled drives are present which can be used.
		ErrorCodeName{"ERROR_CLEANER_CARTRIDGE_INSTALLED", ERROR_CLEANER_CARTRIDGE_INSTALLED},  //! A cleaner cartridge is present in the tape library.
		ErrorCodeName{"ERROR_IEPORT_FULL", ERROR_IEPORT_FULL},  //! Cannot use the inject/eject port because it is not empty.
		ErrorCodeName{"ERROR_FILE_OFFLINE", ERROR_FILE_OFFLINE},  //! This file is currently not available for use on this computer.
		ErrorCodeName{"ERROR_REMOTE_STORAGE_NOT_ACTIVE", ERROR_REMOTE_STORAGE_NOT_ACTIVE},  //! The remote storage service is not operational at this time.
		ErrorCodeName{"ERROR_REMOTE_STORAGE_MEDIA_ERROR", ERROR_REMOTE_STORAGE_MEDIA_ERROR},  //! The remote storage service encountered a media error.
		ErrorCodeName{"ERROR_NOT_A_REPARSE_POINT", ERROR_NOT_A_REPARSE_POINT},  //! The file or directory is not a reparse point.
		ErrorCodeName{"ERROR_REPARSE_ATTRIBUTE_CONFLICT", ERROR_REPARSE_ATTRIBUTE_CONFLICT},  //! The reparse point attribute cannot be set because it conflicts with an existing attribute.
		ErrorCodeName{"ERROR_INVALID_REPARSE_DATA", ERROR_INVALID_REPARSE_DATA},  //! The data present in the reparse point buffer is invalid.
		ErrorCodeName{"ERROR_REPARSE_TAG_INVALID", ERROR_REPARSE_TAG_INVALID},  //! The tag present in the reparse point buffer is invalid.
		ErrorCodeName{"ERROR_REPARSE_TAG_MISMATCH", ERROR_REPARSE_TAG_MISMATCH},  //! There is a mismatch between the tag specified in the request and the tag present in the reparse point.
		ErrorCodeName{"ERROR_APP_DATA_NOT_FOUND", ERROR_APP_DATA_NOT_FOUND},  //! Fast Cache data not found.
		ErrorCodeName{"ERROR_APP_DATA_EXPIRED", ERROR_APP_DATA_EXPIRED},  //! Fast Cache data expired.
		ErrorCodeName{"ERROR_APP_DATA_CORRUPT", ERROR_APP_DATA_CORRUPT},  //! Fast Cache data corrupt.
		ErrorCodeName{"ERROR_APP_DATA_LIMIT_EXCEEDED", ERROR_APP_DATA_LIMIT_EXCEEDED},  //! Fast Cache data has exceeded its max size and cannot be updated.
		ErrorCodeName{"ERROR_APP_DATA_REBOOT_REQUIRED", ERROR_APP_DATA_REBOOT_REQUIRED},  //! Fast Cache has been ReArmed and requires a reboot until it can be updated.
		ErrorCodeName{"ERROR_SECUREBOOT_ROLLBACK_DETECTED", ERROR_SECUREBOOT_ROLLBACK_DETECTED},  //! Secure Boot detected that rollback of protected data has been attempted.
		ErrorCodeName{"ERROR_SECUREBOOT_POLICY_VIOLATION", ERROR_SECUREBOOT_POLICY_VIOLATION},  //! The value is protected by Secure Boot policy and cannot be modified or deleted.
		ErrorCodeName{"ERROR_SECUREBOOT_INVALID_POLICY", ERROR_SECUREBOOT_INVALID_POLICY},  //! The Secure Boot policy is invalid.
		ErrorCodeName{"ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND", ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND},  //! A new Secure Boot policy did not contain the current publisher on its update list.
		ErrorCodeName{"ERROR_SECUREBOOT_POLICY_NOT_SIGNED", ERROR_SECUREBOOT_POLICY_NOT_SIGNED},  //! The Secure Boot policy is either not signed or is signed by a non-trusted signer.
		ErrorCodeName{"ERROR_SECUREBOOT_NOT_ENABLED", ERROR_SECUREBOOT_NOT_ENABLED},  //! Secure Boot is not enabled on this machine.
		ErrorCodeName{"ERROR_SECUREBOOT_FILE_REPLACED", ERROR_SECUREBOOT_FILE_REPLACED},  //! Secure Boot requires that certain files and drivers are not replaced by other files or drivers.
		ErrorCodeName{"ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED", ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED},  //! The copy offload read operation is not supported by a filter.
		ErrorCodeName{"ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED", ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED},  //! The copy offload write operation is not supported by a filter.
		ErrorCodeName{"ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED", ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED},  //! The copy offload read operation is not supported for the file.
		ErrorCodeName{"ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED", ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED},  //! The copy offload write operation is not supported for the file.
		ErrorCodeName{"ERROR_VOLUME_NOT_SIS_ENABLED", ERROR_VOLUME_NOT_SIS_ENABLED},  //! Single Instance Storage is not available on this volume.
		ErrorCodeName{"ERROR_DEPENDENT_RESOURCE_EXISTS", ERROR_DEPENDENT_RESOURCE_EXISTS},  //! The operation cannot be completed because other resources are dependent on this resource.
		ErrorCodeName{"ERROR_DEPENDENCY_NOT_FOUND", ERROR_DEPENDENCY_NOT_FOUND},  //! The cluster resource dependency cannot be found.
		ErrorCodeName{"ERROR_DEPENDENCY_ALREADY_EXISTS", ERROR_DEPENDENCY_ALREADY_EXISTS},  //! The cluster resource cannot be made dependent on the specified resource because it is already dependent.
		ErrorCodeName{"ERROR_RESOURCE_NOT_ONLINE", ERROR_RESOURCE_NOT_ONLINE},  //! The cluster resource is not online.
		ErrorCodeName{"ERROR_HOST_NODE_NOT_AVAILABLE", ERROR_HOST_NODE_NOT_AVAILABLE},  //! A cluster node is not available for this operation.
		ErrorCodeName{"ERROR_RESOURCE_NOT_AVAILABLE", ERROR_RESOURCE_NOT_AVAILABLE},  //! The cluster resource is not available.
		ErrorCodeName{"ERROR_RESOURCE_NOT_FOUND", ERROR_RESOURCE_NOT_FOUND},  //! The cluster resource could not be found.
		ErrorCodeName{"ERROR_SHUTDOWN_CLUSTER", ERROR_SHUTDOWN_CLUSTER},  //! The cluster is being shut down.
		ErrorCodeName{"ERROR_CANT_EVICT_ACTIVE_NODE", ERROR_CANT_EVICT_ACTIVE_NODE},  //! A cluster node cannot be evicted from the cluster unless the node is down or it is the last node.
		ErrorCodeName{"ERROR_OBJECT_ALREADY_EXISTS", ERROR_OBJECT_ALREADY_EXISTS},  //! The object already exists.
		ErrorCodeName{"ERROR_OBJECT_IN_LIST", ERROR_OBJECT_IN_LIST},  //! The object is already in the list.
		ErrorCodeName{"ERROR_GROUP_NOT_AVAILABLE", ERROR_GROUP_NOT_AVAILABLE},  //! The cluster group is not available for any new requests.
		ErrorCodeName{"ERROR_GROUP_NOT_FOUND", ERROR_GROUP_NOT_FOUND},  //! The cluster group could not be found.
		ErrorCodeName{"ERROR_GROUP_NOT_ONLINE", ERROR_GROUP_NOT_ONLINE},  //! The operation could not be completed because the cluster group is not online.
		ErrorCodeName{"ERROR_HOST_NODE_NOT_RESOURCE_OWNER", ERROR_HOST_NODE_NOT_RESOURCE_OWNER},  //! The operation failed because either the specified cluster node is not the owner of the resource, or the node is not a possible owner of the resource.
		ErrorCodeName{"ERROR_HOST_NODE_NOT_GROUP_OWNER", ERROR_HOST_NODE_NOT_GROUP_OWNER},  //! The operation failed because either the specified cluster node is not the owner of the group, or the node is not a possible owner of the group.
		ErrorCodeName{"ERROR_RESMON_CREATE_FAILED", ERROR_RESMON_CREATE_FAILED},  //! The cluster resource could not be created in the specified resource monitor.
		ErrorCodeName{"ERROR_RESMON_ONLINE_FAILED", ERROR_RESMON_ONLINE_FAILED},  //! The cluster resource could not be brought online by the resource monitor.
		ErrorCodeName{"ERROR_RESOURCE_ONLINE", ERROR_RESOURCE_ONLINE},  //! The operation could not be completed because the cluster resource is online.
		ErrorCodeName{"ERROR_QUORUM_RESOURCE", ERROR_QUORUM_RESOURCE},  //! The cluster resource could not be deleted or brought offline because it is the quorum resource.
		ErrorCodeName{"ERROR_NOT_QUORUM_CAPABLE", ERROR_NOT_QUORUM_CAPABLE},  //! The cluster could not make the specified resource a quorum resource because it is not capable of being a quorum resource.
		ErrorCodeName{"ERROR_CLUSTER_SHUTTING_DOWN", ERROR_CLUSTER_SHUTTING_DOWN},  //! The cluster software is shutting down.
		ErrorCodeName{"ERROR_INVALID_STATE", ERROR_INVALID_STATE},  //! The group or resource is not in the correct state to perform the requested operation.
		ErrorCodeName{"ERROR_RESOURCE_PROPERTIES_STORED", ERROR_RESOURCE_PROPERTIES_STORED},  //! The properties were stored but not all changes will take effect until the next time the resource is brought online.
		ErrorCodeName{"ERROR_NOT_QUORUM_CLASS", ERROR_NOT_QUORUM_CLASS},  //! The cluster could not make the specified resource a quorum resource because it does not belong to a shared storage class.
		ErrorCodeName{"ERROR_CORE_RESOURCE", ERROR_CORE_RESOURCE},  //! The cluster resource could not be deleted since it is a core resource.
		ErrorCodeName{"ERROR_QUORUM_RESOURCE_ONLINE_FAILED", ERROR_QUORUM_RESOURCE_ONLINE_FAILED},  //! The quorum resource failed to come online.
		ErrorCodeName{"ERROR_QUORUMLOG_OPEN_FAILED", ERROR_QUORUMLOG_OPEN_FAILED},  //! The quorum log could not be created or mounted successfully.
		ErrorCodeName{"ERROR_CLUSTERLOG_CORRUPT", ERROR_CLUSTERLOG_CORRUPT},  //! The cluster log is corrupt.
		ErrorCodeName{"ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE", ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE},  //! The record could not be written to the cluster log since it exceeds the maximum size.
		ErrorCodeName{"ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE", ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE},  //! The cluster log exceeds its maximum size.
		ErrorCodeName{"ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND", ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND},  //! No checkpoint record was found in the cluster log.
		ErrorCodeName{"ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE", ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE},  //! The minimum required disk space needed for logging is not available.
		ErrorCodeName{"ERROR_QUORUM_OWNER_ALIVE", ERROR_QUORUM_OWNER_ALIVE},  //! The cluster node failed to take control of the quorum resource because the resource is owned by another active node.
		ErrorCodeName{"ERROR_NETWORK_NOT_AVAILABLE", ERROR_NETWORK_NOT_AVAILABLE},  //! A cluster network is not available for this operation.
		ErrorCodeName{"ERROR_NODE_NOT_AVAILABLE", ERROR_NODE_NOT_AVAILABLE},  //! A cluster node is not available for this operation.
		ErrorCodeName{"ERROR_ALL_NODES_NOT_AVAILABLE", ERROR_ALL_NODES_NOT_AVAILABLE},  //! All cluster nodes must be running to perform this operation.
		ErrorCodeName{"ERROR_RESOURCE_FAILED", ERROR_RESOURCE_FAILED},  //! A cluster resource failed.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_NODE", ERROR_CLUSTER_INVALID_NODE},  //! The cluster node is not valid.
		ErrorCodeName{"ERROR_CLUSTER_NODE_EXISTS", ERROR_CLUSTER_NODE_EXISTS},  //! The cluster node already exists.
		ErrorCodeName{"ERROR_CLUSTER_JOIN_IN_PROGRESS", ERROR_CLUSTER_JOIN_IN_PROGRESS},  //! A node is in the process of joining the cluster.
		ErrorCodeName{"ERROR_CLUSTER_NODE_NOT_FOUND", ERROR_CLUSTER_NODE_NOT_FOUND},  //! The cluster node was not found.
		ErrorCodeName{"ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND", ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND},  //! The cluster local node information was not found.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_EXISTS", ERROR_CLUSTER_NETWORK_EXISTS},  //! The cluster network already exists.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_NOT_FOUND", ERROR_CLUSTER_NETWORK_NOT_FOUND},  //! The cluster network was not found.
		ErrorCodeName{"ERROR_CLUSTER_NETINTERFACE_EXISTS", ERROR_CLUSTER_NETINTERFACE_EXISTS},  //! The cluster network interface already exists.
		ErrorCodeName{"ERROR_CLUSTER_NETINTERFACE_NOT_FOUND", ERROR_CLUSTER_NETINTERFACE_NOT_FOUND},  //! The cluster network interface was not found.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_REQUEST", ERROR_CLUSTER_INVALID_REQUEST},  //! The cluster request is not valid for this object.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_NETWORK_PROVIDER", ERROR_CLUSTER_INVALID_NETWORK_PROVIDER},  //! The cluster network provider is not valid.
		ErrorCodeName{"ERROR_CLUSTER_NODE_DOWN", ERROR_CLUSTER_NODE_DOWN},  //! The cluster node is down.
		ErrorCodeName{"ERROR_CLUSTER_NODE_UNREACHABLE", ERROR_CLUSTER_NODE_UNREACHABLE},  //! The cluster node is not reachable.
		ErrorCodeName{"ERROR_CLUSTER_NODE_NOT_MEMBER", ERROR_CLUSTER_NODE_NOT_MEMBER},  //! The cluster node is not a member of the cluster.
		ErrorCodeName{"ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS", ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS},  //! A cluster join operation is not in progress.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_NETWORK", ERROR_CLUSTER_INVALID_NETWORK},  //! The cluster network is not valid.
		ErrorCodeName{"ERROR_CLUSTER_NODE_UP", ERROR_CLUSTER_NODE_UP},  //! The cluster node is up.
		ErrorCodeName{"ERROR_CLUSTER_IPADDR_IN_USE", ERROR_CLUSTER_IPADDR_IN_USE},  //! The cluster IP address is already in use.
		ErrorCodeName{"ERROR_CLUSTER_NODE_NOT_PAUSED", ERROR_CLUSTER_NODE_NOT_PAUSED},  //! The cluster node is not paused.
		ErrorCodeName{"ERROR_CLUSTER_NO_SECURITY_CONTEXT", ERROR_CLUSTER_NO_SECURITY_CONTEXT},  //! No cluster security context is available.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_NOT_INTERNAL", ERROR_CLUSTER_NETWORK_NOT_INTERNAL},  //! The cluster network is not configured for internal cluster communication.
		ErrorCodeName{"ERROR_CLUSTER_NODE_ALREADY_UP", ERROR_CLUSTER_NODE_ALREADY_UP},  //! The cluster node is already up.
		ErrorCodeName{"ERROR_CLUSTER_NODE_ALREADY_DOWN", ERROR_CLUSTER_NODE_ALREADY_DOWN},  //! The cluster node is already down.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_ALREADY_ONLINE", ERROR_CLUSTER_NETWORK_ALREADY_ONLINE},  //! The cluster network is already online.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE", ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE},  //! The cluster network is already offline.
		ErrorCodeName{"ERROR_CLUSTER_NODE_ALREADY_MEMBER", ERROR_CLUSTER_NODE_ALREADY_MEMBER},  //! The cluster node is already a member of the cluster.
		ErrorCodeName{"ERROR_CLUSTER_LAST_INTERNAL_NETWORK", ERROR_CLUSTER_LAST_INTERNAL_NETWORK},  //! The cluster network is the only one configured for internal cluster communication between two or more active cluster nodes. The internal communication capability cannot be removed from the network.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS", ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS},  //! One or more cluster resources depend on the network to provide service to clients. The client access capability cannot be removed from the network.
		ErrorCodeName{"ERROR_INVALID_OPERATION_ON_QUORUM", ERROR_INVALID_OPERATION_ON_QUORUM},  //! This operation cannot be performed on the cluster resource as it the quorum resource. You may not bring the quorum resource offline or modify its possible owners list.
		ErrorCodeName{"ERROR_DEPENDENCY_NOT_ALLOWED", ERROR_DEPENDENCY_NOT_ALLOWED},  //! The cluster quorum resource is not allowed to have any dependencies.
		ErrorCodeName{"ERROR_CLUSTER_NODE_PAUSED", ERROR_CLUSTER_NODE_PAUSED},  //! The cluster node is paused.
		ErrorCodeName{"ERROR_NODE_CANT_HOST_RESOURCE", ERROR_NODE_CANT_HOST_RESOURCE},  //! The cluster resource cannot be brought online. The owner node cannot run this resource.
		ErrorCodeName{"ERROR_CLUSTER_NODE_NOT_READY", ERROR_CLUSTER_NODE_NOT_READY},  //! The cluster node is not ready to perform the requested operation.
		ErrorCodeName{"ERROR_CLUSTER_NODE_SHUTTING_DOWN", ERROR_CLUSTER_NODE_SHUTTING_DOWN},  //! The cluster node is shutting down.
		ErrorCodeName{"ERROR_CLUSTER_JOIN_ABORTED", ERROR_CLUSTER_JOIN_ABORTED},  //! The cluster join operation was aborted.
		ErrorCodeName{"ERROR_CLUSTER_INCOMPATIBLE_VERSIONS", ERROR_CLUSTER_INCOMPATIBLE_VERSIONS},  //! The cluster join operation failed due to incompatible software versions between the joining node and its sponsor.
		ErrorCodeName{"ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED", ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED},  //! This resource cannot be created because the cluster has reached the limit on the number of resources it can monitor.
		ErrorCodeName{"ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED", ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED},  //! The system configuration changed during the cluster join or form operation. The join or form operation was aborted.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND", ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND},  //! The specified resource type was not found.
		ErrorCodeName{"ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED", ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED},  //! The specified node does not support a resource of this type. This may be due to version inconsistencies or due to the absence of the resource DLL on this node.
		ErrorCodeName{"ERROR_CLUSTER_RESNAME_NOT_FOUND", ERROR_CLUSTER_RESNAME_NOT_FOUND},  //! The specified resource name is not supported by this resource DLL. This may be due to a bad (or changed) name supplied to the resource DLL.
		ErrorCodeName{"ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED", ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED},  //! No authentication package could be registered with the RPC server.
		ErrorCodeName{"ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST", ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST},  //! You cannot bring the group online because the owner of the group is not in the preferred list for the group. To change the owner node for the group, move the group.
		ErrorCodeName{"ERROR_CLUSTER_DATABASE_SEQMISMATCH", ERROR_CLUSTER_DATABASE_SEQMISMATCH},  //! The join operation failed because the cluster database sequence number has changed or is incompatible with the locker node. This may happen during a join operation if the cluster database was changing during the join.
		ErrorCodeName{"ERROR_RESMON_INVALID_STATE", ERROR_RESMON_INVALID_STATE},  //! The resource monitor will not allow the fail operation to be performed while the resource is in its current state. This may happen if the resource is in a pending state.
		ErrorCodeName{"ERROR_CLUSTER_GUM_NOT_LOCKER", ERROR_CLUSTER_GUM_NOT_LOCKER},  //! A non locker code got a request to reserve the lock for making global updates.
		ErrorCodeName{"ERROR_QUORUM_DISK_NOT_FOUND", ERROR_QUORUM_DISK_NOT_FOUND},  //! The quorum disk could not be located by the cluster service.
		ErrorCodeName{"ERROR_DATABASE_BACKUP_CORRUPT", ERROR_DATABASE_BACKUP_CORRUPT},  //! The backed up cluster database is possibly corrupt.
		ErrorCodeName{"ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT", ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT},  //! A DFS root already exists in this cluster node.
		ErrorCodeName{"ERROR_RESOURCE_PROPERTY_UNCHANGEABLE", ERROR_RESOURCE_PROPERTY_UNCHANGEABLE},  //! An attempt to modify a resource property failed because it conflicts with another existing property.
		ErrorCodeName{"ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE", ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE},  //! An operation was attempted that is incompatible with the current membership state of the node.
		ErrorCodeName{"ERROR_CLUSTER_QUORUMLOG_NOT_FOUND", ERROR_CLUSTER_QUORUMLOG_NOT_FOUND},  //! The quorum resource does not contain the quorum log.
		ErrorCodeName{"ERROR_CLUSTER_MEMBERSHIP_HALT", ERROR_CLUSTER_MEMBERSHIP_HALT},  //! The membership engine requested shutdown of the cluster service on this node.
		ErrorCodeName{"ERROR_CLUSTER_INSTANCE_ID_MISMATCH", ERROR_CLUSTER_INSTANCE_ID_MISMATCH},  //! The join operation failed because the cluster instance ID of the joining node does not match the cluster instance ID of the sponsor node.
		ErrorCodeName{"ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP", ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP},  //! A matching cluster network for the specified IP address could not be found.
		ErrorCodeName{"ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH", ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH},  //! The actual data type of the property did not match the expected data type of the property.
		ErrorCodeName{"ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP", ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP},  //! The cluster node was evicted from the cluster successfully, but the node was not cleaned up. To determine what cleanup steps failed and how to recover, see the Failover Clustering application event log using Event Viewer.
		ErrorCodeName{"ERROR_CLUSTER_PARAMETER_MISMATCH", ERROR_CLUSTER_PARAMETER_MISMATCH},  //! Two or more parameter values specified for a resource's properties are in conflict.
		ErrorCodeName{"ERROR_NODE_CANNOT_BE_CLUSTERED", ERROR_NODE_CANNOT_BE_CLUSTERED},  //! This computer cannot be made a member of a cluster.
		ErrorCodeName{"ERROR_CLUSTER_WRONG_OS_VERSION", ERROR_CLUSTER_WRONG_OS_VERSION},  //! This computer cannot be made a member of a cluster because it does not have the correct version of Windows installed.
		ErrorCodeName{"ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME", ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME},  //! A cluster cannot be created with the specified cluster name because that cluster name is already in use. Specify a different name for the cluster.
		ErrorCodeName{"ERROR_CLUSCFG_ALREADY_COMMITTED", ERROR_CLUSCFG_ALREADY_COMMITTED},  //! The cluster configuration action has already been committed.
		ErrorCodeName{"ERROR_CLUSCFG_ROLLBACK_FAILED", ERROR_CLUSCFG_ROLLBACK_FAILED},  //! The cluster configuration action could not be rolled back.
		ErrorCodeName{"ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT", ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT},  //! The drive letter assigned to a system disk on one node conflicted with the drive letter assigned to a disk on another node.
		ErrorCodeName{"ERROR_CLUSTER_OLD_VERSION", ERROR_CLUSTER_OLD_VERSION},  //! One or more nodes in the cluster are running a version of Windows that does not support this operation.
		ErrorCodeName{"ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME", ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME},  //! The name of the corresponding computer account doesn't match the Network Name for this resource.
		ErrorCodeName{"ERROR_CLUSTER_NO_NET_ADAPTERS", ERROR_CLUSTER_NO_NET_ADAPTERS},  //! No network adapters are available.
		ErrorCodeName{"ERROR_CLUSTER_POISONED", ERROR_CLUSTER_POISONED},  //! The cluster node has been poisoned.
		ErrorCodeName{"ERROR_CLUSTER_GROUP_MOVING", ERROR_CLUSTER_GROUP_MOVING},  //! The group is unable to accept the request since it is moving to another node.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_TYPE_BUSY", ERROR_CLUSTER_RESOURCE_TYPE_BUSY},  //! The resource type cannot accept the request since is too busy performing another operation.
		ErrorCodeName{"ERROR_RESOURCE_CALL_TIMED_OUT", ERROR_RESOURCE_CALL_TIMED_OUT},  //! The call to the cluster resource DLL timed out.
		ErrorCodeName{"ERROR_INVALID_CLUSTER_IPV6_ADDRESS", ERROR_INVALID_CLUSTER_IPV6_ADDRESS},  //! The address is not valid for an IPv6 Address resource. A global IPv6 address is required, and it must match a cluster network. Compatibility addresses are not permitted.
		ErrorCodeName{"ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION", ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION},  //! An internal cluster error occurred. A call to an invalid function was attempted.
		ErrorCodeName{"ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS", ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS},  //! A parameter value is out of acceptable range.
		ErrorCodeName{"ERROR_CLUSTER_PARTIAL_SEND", ERROR_CLUSTER_PARTIAL_SEND},  //! A network error occurred while sending data to another node in the cluster. The number of bytes transmitted was less than required.
		ErrorCodeName{"ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION", ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION},  //! An invalid cluster registry operation was attempted.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_STRING_TERMINATION", ERROR_CLUSTER_INVALID_STRING_TERMINATION},  //! An input string of characters is not properly terminated.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_STRING_FORMAT", ERROR_CLUSTER_INVALID_STRING_FORMAT},  //! An input string of characters is not in a valid format for the data it represents.
		ErrorCodeName{"ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS", ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS},  //! An internal cluster error occurred. A cluster database transaction was attempted while a transaction was already in progress.
		ErrorCodeName{"ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS", ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS},  //! An internal cluster error occurred. There was an attempt to commit a cluster database transaction while no transaction was in progress.
		ErrorCodeName{"ERROR_CLUSTER_NULL_DATA", ERROR_CLUSTER_NULL_DATA},  //! An internal cluster error occurred. Data was not properly initialized.
		ErrorCodeName{"ERROR_CLUSTER_PARTIAL_READ", ERROR_CLUSTER_PARTIAL_READ},  //! An error occurred while reading from a stream of data. An unexpected number of bytes was returned.
		ErrorCodeName{"ERROR_CLUSTER_PARTIAL_WRITE", ERROR_CLUSTER_PARTIAL_WRITE},  //! An error occurred while writing to a stream of data. The required number of bytes could not be written.
		ErrorCodeName{"ERROR_CLUSTER_CANT_DESERIALIZE_DATA", ERROR_CLUSTER_CANT_DESERIALIZE_DATA},  //! An error occurred while deserializing a stream of cluster data.
		ErrorCodeName{"ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT", ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT},  //! One or more property values for this resource are in conflict with one or more property values associated with its dependent resource(s).
		ErrorCodeName{"ERROR_CLUSTER_NO_QUORUM", ERROR_CLUSTER_NO_QUORUM},  //! A quorum of cluster nodes was not present to form a cluster.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_IPV6_NETWORK", ERROR_CLUSTER_INVALID_IPV6_NETWORK},  //! The cluster network is not valid for an IPv6 Address resource, or it does not match the configured address.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK", ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK},  //! The cluster network is not valid for an IPv6 Tunnel resource. Check the configuration of the IP Address resource on which the IPv6 Tunnel resource depends.
		ErrorCodeName{"ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP", ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP},  //! Quorum resource cannot reside in the Available Storage group.
		ErrorCodeName{"ERROR_DEPENDENCY_TREE_TOO_COMPLEX", ERROR_DEPENDENCY_TREE_TOO_COMPLEX},  //! The dependencies for this resource are nested too deeply.
		ErrorCodeName{"ERROR_EXCEPTION_IN_RESOURCE_CALL", ERROR_EXCEPTION_IN_RESOURCE_CALL},  //! The call into the resource DLL raised an unhandled exception.
		ErrorCodeName{"ERROR_CLUSTER_RHS_FAILED_INITIALIZATION", ERROR_CLUSTER_RHS_FAILED_INITIALIZATION},  //! The RHS process failed to initialize.
		ErrorCodeName{"ERROR_CLUSTER_NOT_INSTALLED", ERROR_CLUSTER_NOT_INSTALLED},  //! The Failover Clustering feature is not installed on this node.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE", ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE},  //! The resources must be online on the same node for this operation.
		ErrorCodeName{"ERROR_CLUSTER_MAX_NODES_IN_CLUSTER", ERROR_CLUSTER_MAX_NODES_IN_CLUSTER},  //! A new node can not be added since this cluster is already at its maximum number of nodes.
		ErrorCodeName{"ERROR_CLUSTER_TOO_MANY_NODES", ERROR_CLUSTER_TOO_MANY_NODES},  //! This cluster can not be created since the specified number of nodes exceeds the maximum allowed limit.
		ErrorCodeName{"ERROR_CLUSTER_OBJECT_ALREADY_USED", ERROR_CLUSTER_OBJECT_ALREADY_USED},  //! An attempt to use the specified cluster name failed because an enabled computer object with the given name already exists in the domain.
		ErrorCodeName{"ERROR_NONCORE_GROUPS_FOUND", ERROR_NONCORE_GROUPS_FOUND},  //! This cluster cannot be destroyed. It has non-core application groups which must be deleted before the cluster can be destroyed.
		ErrorCodeName{"ERROR_FILE_SHARE_RESOURCE_CONFLICT", ERROR_FILE_SHARE_RESOURCE_CONFLICT},  //! File share associated with file share witness resource cannot be hosted by this cluster or any of its nodes.
		ErrorCodeName{"ERROR_CLUSTER_EVICT_INVALID_REQUEST", ERROR_CLUSTER_EVICT_INVALID_REQUEST},  //! Eviction of this node is invalid at this time. Due to quorum requirements node eviction will result in cluster shutdown. If it is the last node in the cluster, destroy cluster command should be used.
		ErrorCodeName{"ERROR_CLUSTER_SINGLETON_RESOURCE", ERROR_CLUSTER_SINGLETON_RESOURCE},  //! Only one instance of this resource type is allowed in the cluster.
		ErrorCodeName{"ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE", ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE},  //! Only one instance of this resource type is allowed per resource group.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED", ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED},  //! The resource failed to come online due to the failure of one or more provider resources.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR", ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR},  //! The resource has indicated that it cannot come online on any node.
		ErrorCodeName{"ERROR_CLUSTER_GROUP_BUSY", ERROR_CLUSTER_GROUP_BUSY},  //! The current operation cannot be performed on this group at this time.
		ErrorCodeName{"ERROR_CLUSTER_NOT_SHARED_VOLUME", ERROR_CLUSTER_NOT_SHARED_VOLUME},  //! The directory or file is not located on a cluster shared volume.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR", ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR},  //! The Security Descriptor does not meet the requirements for a cluster.
		ErrorCodeName{"ERROR_CLUSTER_SHARED_VOLUMES_IN_USE", ERROR_CLUSTER_SHARED_VOLUMES_IN_USE},  //! There is one or more shared volumes resources configured in the cluster. Those resources must be moved to available storage in order for operation to succeed.
		ErrorCodeName{"ERROR_CLUSTER_USE_SHARED_VOLUMES_API", ERROR_CLUSTER_USE_SHARED_VOLUMES_API},  //! This group or resource cannot be directly manipulated. Use shared volume APIs to perform desired operation.
		ErrorCodeName{"ERROR_CLUSTER_BACKUP_IN_PROGRESS", ERROR_CLUSTER_BACKUP_IN_PROGRESS},  //! Back up is in progress. Please wait for backup completion before trying this operation again.
		ErrorCodeName{"ERROR_NON_CSV_PATH", ERROR_NON_CSV_PATH},  //! The path does not belong to a cluster shared volume.
		ErrorCodeName{"ERROR_CSV_VOLUME_NOT_LOCAL", ERROR_CSV_VOLUME_NOT_LOCAL},  //! The cluster shared volume is not locally mounted on this node.
		ErrorCodeName{"ERROR_CLUSTER_WATCHDOG_TERMINATING", ERROR_CLUSTER_WATCHDOG_TERMINATING},  //! The cluster watchdog is terminating.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES", ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES},  //! A resource vetoed a move between two nodes because they are incompatible.
		ErrorCodeName{"ERROR_CLUSTER_INVALID_NODE_WEIGHT", ERROR_CLUSTER_INVALID_NODE_WEIGHT},  //! The request is invalid either because node weight cannot be changed while the cluster is in disk-only quorum mode, or because changing the node weight would violate the minimum cluster quorum requirements.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_VETOED_CALL", ERROR_CLUSTER_RESOURCE_VETOED_CALL},  //! The resource vetoed the call.
		ErrorCodeName{"ERROR_RESMON_SYSTEM_RESOURCES_LACKING", ERROR_RESMON_SYSTEM_RESOURCES_LACKING},  //! Resource could not start or run because it could not reserve sufficient system resources.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION", ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION},  //! A resource vetoed a move between two nodes because the destination currently does not have enough resources to complete the operation.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE", ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE},  //! A resource vetoed a move between two nodes because the source currently does not have enough resources to complete the operation.
		ErrorCodeName{"ERROR_CLUSTER_GROUP_QUEUED", ERROR_CLUSTER_GROUP_QUEUED},  //! The requested operation can not be completed because the group is queued for an operation.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_LOCKED_STATUS", ERROR_CLUSTER_RESOURCE_LOCKED_STATUS},  //! The requested operation can not be completed because a resource has locked status.
		ErrorCodeName{"ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED", ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED},  //! The resource cannot move to another node because a cluster shared volume vetoed the operation.
		ErrorCodeName{"ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS", ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS},  //! A node drain is already in progress.
		ErrorCodeName{"ERROR_CLUSTER_DISK_NOT_CONNECTED", ERROR_CLUSTER_DISK_NOT_CONNECTED},  //! Clustered storage is not connected to the node.
		ErrorCodeName{"ERROR_DISK_NOT_CSV_CAPABLE", ERROR_DISK_NOT_CSV_CAPABLE},  //! The disk is not configured in a way to be used with CSV. CSV disks must have at least one partition that is formatted with NTFS.
		ErrorCodeName{"ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE", ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE},  //! The resource must be part of the Available Storage group to complete this action.
		ErrorCodeName{"ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED", ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED},  //! CSVFS failed operation as volume is in redirected mode.
		ErrorCodeName{"ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED", ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED},  //! CSVFS failed operation as volume is not in redirected mode.
		ErrorCodeName{"ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES", ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES},  //! Cluster properties cannot be returned at this time.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES", ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES},  //! The clustered disk resource contains software snapshot diff area that are not supported for Cluster Shared Volumes.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE", ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE},  //! The operation cannot be completed because the resource is in maintenance mode.
		ErrorCodeName{"ERROR_CLUSTER_AFFINITY_CONFLICT", ERROR_CLUSTER_AFFINITY_CONFLICT},  //! The operation cannot be completed because of cluster affinity conflicts.
		ErrorCodeName{"ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE", ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE},  //! The operation cannot be completed because the resource is a replica virtual machine.
		ErrorCodeName{"ERROR_ENCRYPTION_FAILED", ERROR_ENCRYPTION_FAILED},  //! The specified file could not be encrypted.
		ErrorCodeName{"ERROR_DECRYPTION_FAILED", ERROR_DECRYPTION_FAILED},  //! The specified file could not be decrypted.
		ErrorCodeName{"ERROR_FILE_ENCRYPTED", ERROR_FILE_ENCRYPTED},  //! The specified file is encrypted and the user does not have the ability to decrypt it.
		ErrorCodeName{"ERROR_NO_RECOVERY_POLICY", ERROR_NO_RECOVERY_POLICY},  //! There is no valid encryption recovery policy configured for this system.
		ErrorCodeName{"ERROR_NO_EFS", ERROR_NO_EFS},  //! The required encryption driver is not loaded for this system.
		ErrorCodeName{"ERROR_WRONG_EFS", ERROR_WRONG_EFS},  //! The file was encrypted with a different encryption driver than is currently loaded.
		ErrorCodeName{"ERROR_NO_USER_KEYS", ERROR_NO_USER_KEYS},  //! There are no EFS keys defined for the user.
		ErrorCodeName{"ERROR_FILE_NOT_ENCRYPTED", ERROR_FILE_NOT_ENCRYPTED},  //! The specified file is not encrypted.
		ErrorCodeName{"ERROR_NOT_EXPORT_FORMAT", ERROR_NOT_EXPORT_FORMAT},  //! The specified file is not in the defined EFS export format.
		ErrorCodeName{"ERROR_FILE_READ_ONLY", ERROR_FILE_READ_ONLY},  //! The specified file is read only.
		ErrorCodeName{"ERROR_DIR_EFS_DISALLOWED", ERROR_DIR_EFS_DISALLOWED},  //! The directory has been disabled for encryption.
		ErrorCodeName{"ERROR_EFS_SERVER_NOT_TRUSTED", ERROR_EFS_SERVER_NOT_TRUSTED},  //! The server is not trusted for remote encryption operation.
		ErrorCodeName{"ERROR_BAD_RECOVERY_POLICY", ERROR_BAD_RECOVERY_POLICY},  //! Recovery policy configured for this system contains invalid recovery certificate.
		ErrorCodeName{"ERROR_EFS_ALG_BLOB_TOO_BIG", ERROR_EFS_ALG_BLOB_TOO_BIG},  //! The encryption algorithm used on the source file needs a bigger key buffer than the one on the destination file.
		ErrorCodeName{"ERROR_VOLUME_NOT_SUPPORT_EFS", ERROR_VOLUME_NOT_SUPPORT_EFS},  //! The disk partition does not support file encryption.
		ErrorCodeName{"ERROR_EFS_DISABLED", ERROR_EFS_DISABLED},  //! This machine is disabled for file encryption.
		ErrorCodeName{"ERROR_EFS_VERSION_NOT_SUPPORT", ERROR_EFS_VERSION_NOT_SUPPORT},  //! A newer system is required to decrypt this encrypted file.
		ErrorCodeName{"ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE", ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE},  //! The remote server sent an invalid response for a file being opened with Client Side Encryption.
		ErrorCodeName{"ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER", ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER},  //! Client Side Encryption is not supported by the remote server even though it claims to support it.
		ErrorCodeName{"ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE", ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE},  //! File is encrypted and should be opened in Client Side Encryption mode.
		ErrorCodeName{"ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE", ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE},  //! A new encrypted file is being created and a $EFS needs to be provided.
		ErrorCodeName{"ERROR_CS_ENCRYPTION_FILE_NOT_CSE", ERROR_CS_ENCRYPTION_FILE_NOT_CSE},  //! The SMB client requested a CSE FSCTL on a non-CSE file.
		ErrorCodeName{"ERROR_ENCRYPTION_POLICY_DENIES_OPERATION", ERROR_ENCRYPTION_POLICY_DENIES_OPERATION},  //! The requested operation was blocked by policy. For more information, contact your system administrator.
		ErrorCodeName{"ERROR_NO_BROWSER_SERVERS_FOUND", ERROR_NO_BROWSER_SERVERS_FOUND},  //! The list of servers for this workgroup is not currently available.
		ErrorCodeName{"SCHED_E_SERVICE_NOT_LOCALSYSTEM", SCHED_E_SERVICE_NOT_LOCALSYSTEM},  //! The Task Scheduler service must be configured to run in the System account to function properly. Individual tasks may be configured to run in other accounts.
		ErrorCodeName{"ERROR_LOG_SECTOR_INVALID", ERROR_LOG_SECTOR_INVALID},  //! Log service encountered an invalid log sector.
		ErrorCodeName{"ERROR_LOG_SECTOR_PARITY_INVALID", ERROR_LOG_SECTOR_PARITY_INVALID},  //! Log service encountered a log sector with invalid block parity.
		ErrorCodeName{"ERROR_LOG_SECTOR_REMAPPED", ERROR_LOG_SECTOR_REMAPPED},  //! Log service encountered a remapped log sector.
		ErrorCodeName{"ERROR_LOG_BLOCK_INCOMPLETE", ERROR_LOG_BLOCK_INCOMPLETE},  //! Log service encountered a partial or incomplete log block.
		ErrorCodeName{"ERROR_LOG_INVALID_RANGE", ERROR_LOG_INVALID_RANGE},  //! Log service encountered an attempt access data outside the active log range.
		ErrorCodeName{"ERROR_LOG_BLOCKS_EXHAUSTED", ERROR_LOG_BLOCKS_EXHAUSTED},  //! Log service user marshalling buffers are exhausted.
		ErrorCodeName{"ERROR_LOG_READ_CONTEXT_INVALID", ERROR_LOG_READ_CONTEXT_INVALID},  //! Log service encountered an attempt read from a marshalling area with an invalid read context.
		ErrorCodeName{"ERROR_LOG_RESTART_INVALID", ERROR_LOG_RESTART_INVALID},  //! Log service encountered an invalid log restart area.
		ErrorCodeName{"ERROR_LOG_BLOCK_VERSION", ERROR_LOG_BLOCK_VERSION},  //! Log service encountered an invalid log block version.
		ErrorCodeName{"ERROR_LOG_BLOCK_INVALID", ERROR_LOG_BLOCK_INVALID},  //! Log service encountered an invalid log block.
		ErrorCodeName{"ERROR_LOG_READ_MODE_INVALID", ERROR_LOG_READ_MODE_INVALID},  //! Log service encountered an attempt to read the log with an invalid read mode.
		ErrorCodeName{"ERROR_LOG_NO_RESTART", ERROR_LOG_NO_RESTART},  //! Log service encountered a log stream with no restart area.
		ErrorCodeName{"ERROR_LOG_METADATA_CORRUPT", ERROR_LOG_METADATA_CORRUPT},  //! Log service encountered a corrupted metadata file.
		ErrorCodeName{"ERROR_LOG_METADATA_INVALID", ERROR_LOG_METADATA_INVALID},  //! Log service encountered a metadata file that could not be created by the log file system.
		ErrorCodeName{"ERROR_LOG_METADATA_INCONSISTENT", ERROR_LOG_METADATA_INCONSISTENT},  //! Log service encountered a metadata file with inconsistent data.
		ErrorCodeName{"ERROR_LOG_RESERVATION_INVALID", ERROR_LOG_RESERVATION_INVALID},  //! Log service encountered an attempt to erroneous allocate or dispose reservation space.
		ErrorCodeName{"ERROR_LOG_CANT_DELETE", ERROR_LOG_CANT_DELETE},  //! Log service cannot delete log file or file system container.
		ErrorCodeName{"ERROR_LOG_CONTAINER_LIMIT_EXCEEDED", ERROR_LOG_CONTAINER_LIMIT_EXCEEDED},  //! Log service has reached the maximum allowable containers allocated to a log file.
		ErrorCodeName{"ERROR_LOG_START_OF_LOG", ERROR_LOG_START_OF_LOG},  //! Log service has attempted to read or write backward past the start of the log.
		ErrorCodeName{"ERROR_LOG_POLICY_ALREADY_INSTALLED", ERROR_LOG_POLICY_ALREADY_INSTALLED},  //! Log policy could not be installed because a policy of the same type is already present.
		ErrorCodeName{"ERROR_LOG_POLICY_NOT_INSTALLED", ERROR_LOG_POLICY_NOT_INSTALLED},  //! Log policy in question was not installed at the time of the request.
		ErrorCodeName{"ERROR_LOG_POLICY_INVALID", ERROR_LOG_POLICY_INVALID},  //! The installed set of policies on the log is invalid.
		ErrorCodeName{"ERROR_LOG_POLICY_CONFLICT", ERROR_LOG_POLICY_CONFLICT},  //! A policy on the log in question prevented the operation from completing.
		ErrorCodeName{"ERROR_LOG_PINNED_ARCHIVE_TAIL", ERROR_LOG_PINNED_ARCHIVE_TAIL},  //! Log space cannot be reclaimed because the log is pinned by the archive tail.
		ErrorCodeName{"ERROR_LOG_RECORD_NONEXISTENT", ERROR_LOG_RECORD_NONEXISTENT},  //! Log record is not a record in the log file.
		ErrorCodeName{"ERROR_LOG_RECORDS_RESERVED_INVALID", ERROR_LOG_RECORDS_RESERVED_INVALID},  //! Number of reserved log records or the adjustment of the number of reserved log records is invalid.
		ErrorCodeName{"ERROR_LOG_SPACE_RESERVED_INVALID", ERROR_LOG_SPACE_RESERVED_INVALID},  //! Reserved log space or the adjustment of the log space is invalid.
		ErrorCodeName{"ERROR_LOG_TAIL_INVALID", ERROR_LOG_TAIL_INVALID},  //! An new or existing archive tail or base of the active log is invalid.
		ErrorCodeName{"ERROR_LOG_FULL", ERROR_LOG_FULL},  //! Log space is exhausted.
		ErrorCodeName{"ERROR_COULD_NOT_RESIZE_LOG", ERROR_COULD_NOT_RESIZE_LOG},  //! The log could not be set to the requested size.
		ErrorCodeName{"ERROR_LOG_MULTIPLEXED", ERROR_LOG_MULTIPLEXED},  //! Log is multiplexed, no direct writes to the physical log is allowed.
		ErrorCodeName{"ERROR_LOG_DEDICATED", ERROR_LOG_DEDICATED},  //! The operation failed because the log is a dedicated log.
		ErrorCodeName{"ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS", ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS},  //! The operation requires an archive context.
		ErrorCodeName{"ERROR_LOG_ARCHIVE_IN_PROGRESS", ERROR_LOG_ARCHIVE_IN_PROGRESS},  //! Log archival is in progress.
		ErrorCodeName{"ERROR_LOG_EPHEMERAL", ERROR_LOG_EPHEMERAL},  //! The operation requires a non-ephemeral log, but the log is ephemeral.
		ErrorCodeName{"ERROR_LOG_NOT_ENOUGH_CONTAINERS", ERROR_LOG_NOT_ENOUGH_CONTAINERS},  //! The log must have at least two containers before it can be read from or written to.
		ErrorCodeName{"ERROR_LOG_CLIENT_ALREADY_REGISTERED", ERROR_LOG_CLIENT_ALREADY_REGISTERED},  //! A log client has already registered on the stream.
		ErrorCodeName{"ERROR_LOG_CLIENT_NOT_REGISTERED", ERROR_LOG_CLIENT_NOT_REGISTERED},  //! A log client has not been registered on the stream.
		ErrorCodeName{"ERROR_LOG_FULL_HANDLER_IN_PROGRESS", ERROR_LOG_FULL_HANDLER_IN_PROGRESS},  //! A request has already been made to handle the log full condition.
		ErrorCodeName{"ERROR_LOG_CONTAINER_READ_FAILED", ERROR_LOG_CONTAINER_READ_FAILED},  //! Log service encountered an error when attempting to read from a log container.
		ErrorCodeName{"ERROR_LOG_CONTAINER_WRITE_FAILED", ERROR_LOG_CONTAINER_WRITE_FAILED},  //! Log service encountered an error when attempting to write to a log container.
		ErrorCodeName{"ERROR_LOG_CONTAINER_OPEN_FAILED", ERROR_LOG_CONTAINER_OPEN_FAILED},  //! Log service encountered an error when attempting open a log container.
		ErrorCodeName{"ERROR_LOG_CONTAINER_STATE_INVALID", ERROR_LOG_CONTAINER_STATE_INVALID},  //! Log service encountered an invalid container state when attempting a requested action.
		ErrorCodeName{"ERROR_LOG_STATE_INVALID", ERROR_LOG_STATE_INVALID},  //! Log service is not in the correct state to perform a requested action.
		ErrorCodeName{"ERROR_LOG_PINNED", ERROR_LOG_PINNED},  //! Log space cannot be reclaimed because the log is pinned.
		ErrorCodeName{"ERROR_LOG_METADATA_FLUSH_FAILED", ERROR_LOG_METADATA_FLUSH_FAILED},  //! Log metadata flush failed.
		ErrorCodeName{"ERROR_LOG_INCONSISTENT_SECURITY", ERROR_LOG_INCONSISTENT_SECURITY},  //! Security on the log and its containers is inconsistent.
		ErrorCodeName{"ERROR_LOG_APPENDED_FLUSH_FAILED", ERROR_LOG_APPENDED_FLUSH_FAILED},  //! Records were appended to the log or reservation changes were made, but the log could not be flushed.
		ErrorCodeName{"ERROR_LOG_PINNED_RESERVATION", ERROR_LOG_PINNED_RESERVATION},  //! The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available.
		ErrorCodeName{"ERROR_INVALID_TRANSACTION", ERROR_INVALID_TRANSACTION},  //! The transaction handle associated with this operation is not valid.
		ErrorCodeName{"ERROR_TRANSACTION_NOT_ACTIVE", ERROR_TRANSACTION_NOT_ACTIVE},  //! The requested operation was made in the context of a transaction that is no longer active.
		ErrorCodeName{"ERROR_TRANSACTION_REQUEST_NOT_VALID", ERROR_TRANSACTION_REQUEST_NOT_VALID},  //! The requested operation is not valid on the Transaction object in its current state.
		ErrorCodeName{"ERROR_TRANSACTION_NOT_REQUESTED", ERROR_TRANSACTION_NOT_REQUESTED},  //! The caller has called a response API, but the response is not expected because the TM did not issue the corresponding request to the caller.
		ErrorCodeName{"ERROR_TRANSACTION_ALREADY_ABORTED", ERROR_TRANSACTION_ALREADY_ABORTED},  //! It is too late to perform the requested operation, since the Transaction has already been aborted.
		ErrorCodeName{"ERROR_TRANSACTION_ALREADY_COMMITTED", ERROR_TRANSACTION_ALREADY_COMMITTED},  //! It is too late to perform the requested operation, since the Transaction has already been committed.
		ErrorCodeName{"ERROR_TM_INITIALIZATION_FAILED", ERROR_TM_INITIALIZATION_FAILED},  //! The Transaction Manager was unable to be successfully initialized. Transacted operations are not supported.
		ErrorCodeName{"ERROR_RESOURCEMANAGER_READ_ONLY", ERROR_RESOURCEMANAGER_READ_ONLY},  //! The specified ResourceManager made no changes or updates to the resource under this transaction.
		ErrorCodeName{"ERROR_TRANSACTION_NOT_JOINED", ERROR_TRANSACTION_NOT_JOINED},  //! The resource manager has attempted to prepare a transaction that it has not successfully joined.
		ErrorCodeName{"ERROR_TRANSACTION_SUPERIOR_EXISTS", ERROR_TRANSACTION_SUPERIOR_EXISTS},  //! The Transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allow.
		ErrorCodeName{"ERROR_CRM_PROTOCOL_ALREADY_EXISTS", ERROR_CRM_PROTOCOL_ALREADY_EXISTS},  //! The RM tried to register a protocol that already exists.
		ErrorCodeName{"ERROR_TRANSACTION_PROPAGATION_FAILED", ERROR_TRANSACTION_PROPAGATION_FAILED},  //! The attempt to propagate the Transaction failed.
		ErrorCodeName{"ERROR_CRM_PROTOCOL_NOT_FOUND", ERROR_CRM_PROTOCOL_NOT_FOUND},  //! The requested propagation protocol was not registered as a CRM.
		ErrorCodeName{"ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER", ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER},  //! The buffer passed in to PushTransaction or PullTransaction is not in a valid format.
		ErrorCodeName{"ERROR_CURRENT_TRANSACTION_NOT_VALID", ERROR_CURRENT_TRANSACTION_NOT_VALID},  //! The current transaction context associated with the thread is not a valid handle to a transaction object.
		ErrorCodeName{"ERROR_TRANSACTION_NOT_FOUND", ERROR_TRANSACTION_NOT_FOUND},  //! The specified Transaction object could not be opened, because it was not found.
		ErrorCodeName{"ERROR_RESOURCEMANAGER_NOT_FOUND", ERROR_RESOURCEMANAGER_NOT_FOUND},  //! The specified ResourceManager object could not be opened, because it was not found.
		ErrorCodeName{"ERROR_ENLISTMENT_NOT_FOUND", ERROR_ENLISTMENT_NOT_FOUND},  //! The specified Enlistment object could not be opened, because it was not found.
		ErrorCodeName{"ERROR_TRANSACTIONMANAGER_NOT_FOUND", ERROR_TRANSACTIONMANAGER_NOT_FOUND},  //! The specified TransactionManager object could not be opened, because it was not found.
		ErrorCodeName{"ERROR_TRANSACTIONMANAGER_NOT_ONLINE", ERROR_TRANSACTIONMANAGER_NOT_ONLINE},  //! The object specified could not be created or opened, because its associated TransactionManager is not online. The TransactionManager must be brought fully Online by calling RecoverTransactionManager to recover to the end of its LogFile before objects in its Transaction or ResourceManager namespaces can be opened. In addition, errors in writing records to its LogFile can cause a TransactionManager to go offline.
		ErrorCodeName{"ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION", ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION},  //! The specified TransactionManager was unable to create the objects contained in its logfile in the Ob namespace. Therefore, the TransactionManager was unable to recover.
		ErrorCodeName{"ERROR_TRANSACTION_NOT_ROOT", ERROR_TRANSACTION_NOT_ROOT},  //! The call to create a superior Enlistment on this Transaction object could not be completed, because the Transaction object specified for the enlistment is a subordinate branch of the Transaction. Only the root of the Transaction can be enlisted on as a superior.
		ErrorCodeName{"ERROR_TRANSACTION_OBJECT_EXPIRED", ERROR_TRANSACTION_OBJECT_EXPIRED},  //! Because the associated transaction manager or resource manager has been closed, the handle is no longer valid.
		ErrorCodeName{"ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED", ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED},  //! The specified operation could not be performed on this Superior enlistment, because the enlistment was not created with the corresponding completion response in the NotificationMask.
		ErrorCodeName{"ERROR_TRANSACTION_RECORD_TOO_LONG", ERROR_TRANSACTION_RECORD_TOO_LONG},  //! The specified operation could not be performed, because the record that would be logged was too long. This can occur because of two conditions: either there are too many Enlistments on this Transaction, or the combined RecoveryInformation being logged on behalf of those Enlistments is too long.
		ErrorCodeName{"ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED", ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED},  //! Implicit transaction are not supported.
		ErrorCodeName{"ERROR_TRANSACTION_INTEGRITY_VIOLATED", ERROR_TRANSACTION_INTEGRITY_VIOLATED},  //! The kernel transaction manager had to abort or forget the transaction because it blocked forward progress.
		ErrorCodeName{"ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH", ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH},  //! The TransactionManager identity that was supplied did not match the one recorded in the TransactionManager's log file.
		ErrorCodeName{"ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT", ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT},  //! This snapshot operation cannot continue because a transactional resource manager cannot be frozen in its current state. Please try again.
		ErrorCodeName{"ERROR_TRANSACTION_MUST_WRITETHROUGH", ERROR_TRANSACTION_MUST_WRITETHROUGH},  //! The transaction cannot be enlisted on with the specified EnlistmentMask, because the transaction has already completed the PrePrepare phase. In order to ensure correctness, the ResourceManager must switch to a write- through mode and cease caching data within this transaction. Enlisting for only subsequent transaction phases may still succeed.
		ErrorCodeName{"ERROR_TRANSACTION_NO_SUPERIOR", ERROR_TRANSACTION_NO_SUPERIOR},  //! The transaction does not have a superior enlistment.
		ErrorCodeName{"ERROR_HEURISTIC_DAMAGE_POSSIBLE", ERROR_HEURISTIC_DAMAGE_POSSIBLE},  //! The attempt to commit the Transaction completed, but it is possible that some portion of the transaction tree did not commit successfully due to heuristics. Therefore it is possible that some data modified in the transaction may not have committed, resulting in transactional inconsistency. If possible, check the consistency of the associated data.
		ErrorCodeName{"ERROR_TRANSACTIONAL_CONFLICT", ERROR_TRANSACTIONAL_CONFLICT},  //! The function attempted to use a name that is reserved for use by another transaction.
		ErrorCodeName{"ERROR_RM_NOT_ACTIVE", ERROR_RM_NOT_ACTIVE},  //! Transaction support within the specified resource manager is not started or was shut down due to an error.
		ErrorCodeName{"ERROR_RM_METADATA_CORRUPT", ERROR_RM_METADATA_CORRUPT},  //! The metadata of the RM has been corrupted. The RM will not function.
		ErrorCodeName{"ERROR_DIRECTORY_NOT_RM", ERROR_DIRECTORY_NOT_RM},  //! The specified directory does not contain a resource manager.
		ErrorCodeName{"ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE", ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE},  //! The remote server or share does not support transacted file operations.
		ErrorCodeName{"ERROR_LOG_RESIZE_INVALID_SIZE", ERROR_LOG_RESIZE_INVALID_SIZE},  //! The requested log size is invalid.
		ErrorCodeName{"ERROR_OBJECT_NO_LONGER_EXISTS", ERROR_OBJECT_NO_LONGER_EXISTS},  //! The object (file, stream, link) corresponding to the handle has been deleted by a Transaction Savepoint Rollback.
		ErrorCodeName{"ERROR_STREAM_MINIVERSION_NOT_FOUND", ERROR_STREAM_MINIVERSION_NOT_FOUND},  //! The specified file miniversion was not found for this transacted file open.
		ErrorCodeName{"ERROR_STREAM_MINIVERSION_NOT_VALID", ERROR_STREAM_MINIVERSION_NOT_VALID},  //! The specified file miniversion was found but has been invalidated. Most likely cause is a transaction savepoint rollback.
		ErrorCodeName{"ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION", ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION},  //! A miniversion may only be opened in the context of the transaction that created it.
		ErrorCodeName{"ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT", ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT},  //! It is not possible to open a miniversion with modify access.
		ErrorCodeName{"ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS", ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS},  //! It is not possible to create any more miniversions for this stream.
		ErrorCodeName{"ERROR_REMOTE_FILE_VERSION_MISMATCH", ERROR_REMOTE_FILE_VERSION_MISMATCH},  //! The remote server sent mismatching version number or Fid for a file opened with transactions.
		ErrorCodeName{"ERROR_HANDLE_NO_LONGER_VALID", ERROR_HANDLE_NO_LONGER_VALID},  //! The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint.
		ErrorCodeName{"ERROR_NO_TXF_METADATA", ERROR_NO_TXF_METADATA},  //! There is no transaction metadata on the file.
		ErrorCodeName{"ERROR_LOG_CORRUPTION_DETECTED", ERROR_LOG_CORRUPTION_DETECTED},  //! The log data is corrupt.
		ErrorCodeName{"ERROR_CANT_RECOVER_WITH_HANDLE_OPEN", ERROR_CANT_RECOVER_WITH_HANDLE_OPEN},  //! The file can't be recovered because there is a handle still open on it.
		ErrorCodeName{"ERROR_RM_DISCONNECTED", ERROR_RM_DISCONNECTED},  //! The transaction outcome is unavailable because the resource manager responsible for it has disconnected.
		ErrorCodeName{"ERROR_ENLISTMENT_NOT_SUPERIOR", ERROR_ENLISTMENT_NOT_SUPERIOR},  //! The request was rejected because the enlistment in question is not a superior enlistment.
		ErrorCodeName{"ERROR_RECOVERY_NOT_NEEDED", ERROR_RECOVERY_NOT_NEEDED},  //! The transactional resource manager is already consistent. Recovery is not needed.
		ErrorCodeName{"ERROR_RM_ALREADY_STARTED", ERROR_RM_ALREADY_STARTED},  //! The transactional resource manager has already been started.
		ErrorCodeName{"ERROR_FILE_IDENTITY_NOT_PERSISTENT", ERROR_FILE_IDENTITY_NOT_PERSISTENT},  //! The file cannot be opened transactionally, because its identity depends on the outcome of an unresolved transaction.
		ErrorCodeName{"ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY", ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY},  //! The operation cannot be performed because another transaction is depending on the fact that this property will not change.
		ErrorCodeName{"ERROR_CANT_CROSS_RM_BOUNDARY", ERROR_CANT_CROSS_RM_BOUNDARY},  //! The operation would involve a single file with two transactional resource managers and is therefore not allowed.
		ErrorCodeName{"ERROR_TXF_DIR_NOT_EMPTY", ERROR_TXF_DIR_NOT_EMPTY},  //! The $Txf directory must be empty for this operation to succeed.
		ErrorCodeName{"ERROR_INDOUBT_TRANSACTIONS_EXIST", ERROR_INDOUBT_TRANSACTIONS_EXIST},  //! The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed.
		ErrorCodeName{"ERROR_TM_VOLATILE", ERROR_TM_VOLATILE},  //! The operation could not be completed because the transaction manager does not have a log.
		ErrorCodeName{"ERROR_ROLLBACK_TIMER_EXPIRED", ERROR_ROLLBACK_TIMER_EXPIRED},  //! A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution.
		ErrorCodeName{"ERROR_TXF_ATTRIBUTE_CORRUPT", ERROR_TXF_ATTRIBUTE_CORRUPT},  //! The transactional metadata attribute on the file or directory is corrupt and unreadable.
		ErrorCodeName{"ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION", ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION},  //! The encryption operation could not be completed because a transaction is active.
		ErrorCodeName{"ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED", ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED},  //! This object is not allowed to be opened in a transaction.
		ErrorCodeName{"ERROR_LOG_GROWTH_FAILED", ERROR_LOG_GROWTH_FAILED},  //! An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log.
		ErrorCodeName{"ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE", ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE},  //! Memory mapping (creating a mapped section) a remote file under a transaction is not supported.
		ErrorCodeName{"ERROR_TXF_METADATA_ALREADY_PRESENT", ERROR_TXF_METADATA_ALREADY_PRESENT},  //! Transaction metadata is already present on this file and cannot be superseded.
		ErrorCodeName{"ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET", ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET},  //! A transaction scope could not be entered because the scope handler has not been initialized.
		ErrorCodeName{"ERROR_TRANSACTION_REQUIRED_PROMOTION", ERROR_TRANSACTION_REQUIRED_PROMOTION},  //! Promotion was required in order to allow the resource manager to enlist, but the transaction was set to disallow it.
		ErrorCodeName{"ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION", ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION},  //! This file is open for modification in an unresolved transaction and may be opened for execute only by a transacted reader.
		ErrorCodeName{"ERROR_TRANSACTIONS_NOT_FROZEN", ERROR_TRANSACTIONS_NOT_FROZEN},  //! The request to thaw frozen transactions was ignored because transactions had not previously been frozen.
		ErrorCodeName{"ERROR_TRANSACTION_FREEZE_IN_PROGRESS", ERROR_TRANSACTION_FREEZE_IN_PROGRESS},  //! Transactions cannot be frozen because a freeze is already in progress.
		ErrorCodeName{"ERROR_NOT_SNAPSHOT_VOLUME", ERROR_NOT_SNAPSHOT_VOLUME},  //! The target volume is not a snapshot volume. This operation is only valid on a volume mounted as a snapshot.
		ErrorCodeName{"ERROR_NO_SAVEPOINT_WITH_OPEN_FILES", ERROR_NO_SAVEPOINT_WITH_OPEN_FILES},  //! The savepoint operation failed because files are open on the transaction. This is not permitted.
		ErrorCodeName{"ERROR_DATA_LOST_REPAIR", ERROR_DATA_LOST_REPAIR},  //! Windows has discovered corruption in a file, and that file has since been repaired. Data loss may have occurred.
		ErrorCodeName{"ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION", ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION},  //! The sparse operation could not be completed because a transaction is active on the file.
		ErrorCodeName{"ERROR_TM_IDENTITY_MISMATCH", ERROR_TM_IDENTITY_MISMATCH},  //! The call to create a TransactionManager object failed because the Tm Identity stored in the logfile does not match the Tm Identity that was passed in as an argument.
		ErrorCodeName{"ERROR_FLOATED_SECTION", ERROR_FLOATED_SECTION},  //! I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data.
		ErrorCodeName{"ERROR_CANNOT_ACCEPT_TRANSACTED_WORK", ERROR_CANNOT_ACCEPT_TRANSACTED_WORK},  //! The transactional resource manager cannot currently accept transacted work due to a transient condition such as low resources.
		ErrorCodeName{"ERROR_CANNOT_ABORT_TRANSACTIONS", ERROR_CANNOT_ABORT_TRANSACTIONS},  //! The transactional resource manager had too many tranactions outstanding that could not be aborted. The transactional resource manger has been shut down.
		ErrorCodeName{"ERROR_BAD_CLUSTERS", ERROR_BAD_CLUSTERS},  //! The operation could not be completed due to bad clusters on disk.
		ErrorCodeName{"ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION", ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION},  //! The compression operation could not be completed because a transaction is active on the file.
		ErrorCodeName{"ERROR_VOLUME_DIRTY", ERROR_VOLUME_DIRTY},  //! The operation could not be completed because the volume is dirty. Please run chkdsk and try again.
		ErrorCodeName{"ERROR_NO_LINK_TRACKING_IN_TRANSACTION", ERROR_NO_LINK_TRACKING_IN_TRANSACTION},  //! The link tracking operation could not be completed because a transaction is active.
		ErrorCodeName{"ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION", ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION},  //! This operation cannot be performed in a transaction.
		ErrorCodeName{"ERROR_EXPIRED_HANDLE", ERROR_EXPIRED_HANDLE},  //! The handle is no longer properly associated with its transaction. It may have been opened in a transactional resource manager that was subsequently forced to restart. Please close the handle and open a new one.
		ErrorCodeName{"ERROR_TRANSACTION_NOT_ENLISTED", ERROR_TRANSACTION_NOT_ENLISTED},  //! The specified operation could not be performed because the resource manager is not enlisted in the transaction.
		ErrorCodeName{"ERROR_CTX_WINSTATION_NAME_INVALID", ERROR_CTX_WINSTATION_NAME_INVALID},  //! The specified session name is invalid.
		ErrorCodeName{"ERROR_CTX_INVALID_PD", ERROR_CTX_INVALID_PD},  //! The specified protocol driver is invalid.
		ErrorCodeName{"ERROR_CTX_PD_NOT_FOUND", ERROR_CTX_PD_NOT_FOUND},  //! The specified protocol driver was not found in the system path.
		ErrorCodeName{"ERROR_CTX_WD_NOT_FOUND", ERROR_CTX_WD_NOT_FOUND},  //! The specified terminal connection driver was not found in the system path.
		ErrorCodeName{"ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY", ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY},  //! A registry key for event logging could not be created for this session.
		ErrorCodeName{"ERROR_CTX_SERVICE_NAME_COLLISION", ERROR_CTX_SERVICE_NAME_COLLISION},  //! A service with the same name already exists on the system.
		ErrorCodeName{"ERROR_CTX_CLOSE_PENDING", ERROR_CTX_CLOSE_PENDING},  //! A close operation is pending on the session.
		ErrorCodeName{"ERROR_CTX_NO_OUTBUF", ERROR_CTX_NO_OUTBUF},  //! There are no free output buffers available.
		ErrorCodeName{"ERROR_CTX_MODEM_INF_NOT_FOUND", ERROR_CTX_MODEM_INF_NOT_FOUND},  //! The MODEM.INF file was not found.
		ErrorCodeName{"ERROR_CTX_INVALID_MODEMNAME", ERROR_CTX_INVALID_MODEMNAME},  //! The modem name was not found in MODEM.INF.
		ErrorCodeName{"ERROR_CTX_MODEM_RESPONSE_ERROR", ERROR_CTX_MODEM_RESPONSE_ERROR},  //! The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem.
		ErrorCodeName{"ERROR_CTX_MODEM_RESPONSE_TIMEOUT", ERROR_CTX_MODEM_RESPONSE_TIMEOUT},  //! The modem did not respond to the command sent to it. Verify that the modem is properly cabled and powered on.
		ErrorCodeName{"ERROR_CTX_MODEM_RESPONSE_NO_CARRIER", ERROR_CTX_MODEM_RESPONSE_NO_CARRIER},  //! Carrier detect has failed or carrier has been dropped due to disconnect.
		ErrorCodeName{"ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE", ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE},  //! Dial tone not detected within the required time. Verify that the phone cable is properly attached and functional.
		ErrorCodeName{"ERROR_CTX_MODEM_RESPONSE_BUSY", ERROR_CTX_MODEM_RESPONSE_BUSY},  //! Busy signal detected at remote site on callback.
		ErrorCodeName{"ERROR_CTX_MODEM_RESPONSE_VOICE", ERROR_CTX_MODEM_RESPONSE_VOICE},  //! Voice detected at remote site on callback.
		ErrorCodeName{"ERROR_CTX_TD_ERROR", ERROR_CTX_TD_ERROR},  //! Transport driver error.
		ErrorCodeName{"ERROR_CTX_WINSTATION_NOT_FOUND", ERROR_CTX_WINSTATION_NOT_FOUND},  //! The specified session cannot be found.
		ErrorCodeName{"ERROR_CTX_WINSTATION_ALREADY_EXISTS", ERROR_CTX_WINSTATION_ALREADY_EXISTS},  //! The specified session name is already in use.
		ErrorCodeName{"ERROR_CTX_WINSTATION_BUSY", ERROR_CTX_WINSTATION_BUSY},  //! The task you are trying to do can't be completed because Remote Desktop Services is currently busy. Please try again in a few minutes. Other users should still be able to log on.
		ErrorCodeName{"ERROR_CTX_BAD_VIDEO_MODE", ERROR_CTX_BAD_VIDEO_MODE},  //! An attempt has been made to connect to a session whose video mode is not supported by the current client.
		ErrorCodeName{"ERROR_CTX_GRAPHICS_INVALID", ERROR_CTX_GRAPHICS_INVALID},  //! The application attempted to enable DOS graphics mode. DOS graphics mode is not supported.
		ErrorCodeName{"ERROR_CTX_LOGON_DISABLED", ERROR_CTX_LOGON_DISABLED},  //! Your interactive logon privilege has been disabled. Please contact your administrator.
		ErrorCodeName{"ERROR_CTX_NOT_CONSOLE", ERROR_CTX_NOT_CONSOLE},  //! The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access.
		ErrorCodeName{"ERROR_CTX_CLIENT_QUERY_TIMEOUT", ERROR_CTX_CLIENT_QUERY_TIMEOUT},  //! The client failed to respond to the server connect message.
		ErrorCodeName{"ERROR_CTX_CONSOLE_DISCONNECT", ERROR_CTX_CONSOLE_DISCONNECT},  //! Disconnecting the console session is not supported.
		ErrorCodeName{"ERROR_CTX_CONSOLE_CONNECT", ERROR_CTX_CONSOLE_CONNECT},  //! Reconnecting a disconnected session to the console is not supported.
		ErrorCodeName{"ERROR_CTX_SHADOW_DENIED", ERROR_CTX_SHADOW_DENIED},  //! The request to control another session remotely was denied.
		ErrorCodeName{"ERROR_CTX_WINSTATION_ACCESS_DENIED", ERROR_CTX_WINSTATION_ACCESS_DENIED},  //! The requested session access is denied.
		ErrorCodeName{"ERROR_CTX_INVALID_WD", ERROR_CTX_INVALID_WD},  //! The specified terminal connection driver is invalid.
		ErrorCodeName{"ERROR_CTX_SHADOW_INVALID", ERROR_CTX_SHADOW_INVALID},  //! The requested session cannot be controlled remotely. This may be because the session is disconnected or does not currently have a user logged on.
		ErrorCodeName{"ERROR_CTX_SHADOW_DISABLED", ERROR_CTX_SHADOW_DISABLED},  //! The requested session is not configured to allow remote control.
		ErrorCodeName{"ERROR_CTX_CLIENT_LICENSE_IN_USE", ERROR_CTX_CLIENT_LICENSE_IN_USE},  //! Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number is currently being used by another user. Please call your system administrator to obtain a unique license number.
		ErrorCodeName{"ERROR_CTX_CLIENT_LICENSE_NOT_SET", ERROR_CTX_CLIENT_LICENSE_NOT_SET},  //! Your request to connect to this Terminal Server has been rejected. Your Terminal Server client license number has not been entered for this copy of the Terminal Server client. Please contact your system administrator.
		ErrorCodeName{"ERROR_CTX_LICENSE_NOT_AVAILABLE", ERROR_CTX_LICENSE_NOT_AVAILABLE},  //! The number of connections to this computer is limited and all connections are in use right now. Try connecting later or contact your system administrator.
		ErrorCodeName{"ERROR_CTX_LICENSE_CLIENT_INVALID", ERROR_CTX_LICENSE_CLIENT_INVALID},  //! The client you are using is not licensed to use this system. Your logon request is denied.
		ErrorCodeName{"ERROR_CTX_LICENSE_EXPIRED", ERROR_CTX_LICENSE_EXPIRED},  //! The system license has expired. Your logon request is denied.
		ErrorCodeName{"ERROR_CTX_SHADOW_NOT_RUNNING", ERROR_CTX_SHADOW_NOT_RUNNING},  //! Remote control could not be terminated because the specified session is not currently being remotely controlled.
		ErrorCodeName{"ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE", ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE},  //! The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported.
		ErrorCodeName{"ERROR_ACTIVATION_COUNT_EXCEEDED", ERROR_ACTIVATION_COUNT_EXCEEDED},  //! Activation has already been reset the maximum number of times for this installation. Your activation timer will not be cleared.
		ErrorCodeName{"ERROR_CTX_WINSTATIONS_DISABLED", ERROR_CTX_WINSTATIONS_DISABLED},  //! Remote logins are currently disabled.
		ErrorCodeName{"ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED", ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED},  //! You do not have the proper encryption level to access this Session.
		ErrorCodeName{"ERROR_CTX_SESSION_IN_USE", ERROR_CTX_SESSION_IN_USE},  //! The user %s\\%s is currently logged on to this computer. Only the current user or an administrator can log on to this computer.
		ErrorCodeName{"ERROR_CTX_NO_FORCE_LOGOFF", ERROR_CTX_NO_FORCE_LOGOFF},  //! The user %s\\%s is already logged on to the console of this computer. You do not have permission to log in at this time. To resolve this issue, contact %s\\%s and have them log off.
		ErrorCodeName{"ERROR_CTX_ACCOUNT_RESTRICTION", ERROR_CTX_ACCOUNT_RESTRICTION},  //! Unable to log you on because of an account restriction.
		ErrorCodeName{"ERROR_RDP_PROTOCOL_ERROR", ERROR_RDP_PROTOCOL_ERROR},  //! The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client.
		ErrorCodeName{"ERROR_CTX_CDM_CONNECT", ERROR_CTX_CDM_CONNECT},  //! The Client Drive Mapping Service Has Connected on Terminal Connection.
		ErrorCodeName{"ERROR_CTX_CDM_DISCONNECT", ERROR_CTX_CDM_DISCONNECT},  //! The Client Drive Mapping Service Has Disconnected on Terminal Connection.
		ErrorCodeName{"ERROR_CTX_SECURITY_LAYER_ERROR", ERROR_CTX_SECURITY_LAYER_ERROR},  //! The Terminal Server security layer detected an error in the protocol stream and has disconnected the client.
		ErrorCodeName{"ERROR_TS_INCOMPATIBLE_SESSIONS", ERROR_TS_INCOMPATIBLE_SESSIONS},  //! The target session is incompatible with the current session.
		ErrorCodeName{"ERROR_TS_VIDEO_SUBSYSTEM_ERROR", ERROR_TS_VIDEO_SUBSYSTEM_ERROR},  //! Windows can't connect to your session because a problem occurred in the Windows video subsystem. Try connecting again later, or contact the server administrator for assistance.
		ErrorCodeName{"FRS_ERR_INVALID_API_SEQUENCE", FRS_ERR_INVALID_API_SEQUENCE},  //! The file replication service API was called incorrectly.
		ErrorCodeName{"FRS_ERR_STARTING_SERVICE", FRS_ERR_STARTING_SERVICE},  //! The file replication service cannot be started.
		ErrorCodeName{"FRS_ERR_STOPPING_SERVICE", FRS_ERR_STOPPING_SERVICE},  //! The file replication service cannot be stopped.
		ErrorCodeName{"FRS_ERR_INTERNAL_API", FRS_ERR_INTERNAL_API},  //! The file replication service API terminated the request. The event log may have more information.
		ErrorCodeName{"FRS_ERR_INTERNAL", FRS_ERR_INTERNAL},  //! The file replication service terminated the request. The event log may have more information.
		ErrorCodeName{"FRS_ERR_SERVICE_COMM", FRS_ERR_SERVICE_COMM},  //! The file replication service cannot be contacted. The event log may have more information.
		ErrorCodeName{"FRS_ERR_INSUFFICIENT_PRIV", FRS_ERR_INSUFFICIENT_PRIV},  //! The file replication service cannot satisfy the request because the user has insufficient privileges. The event log may have more information.
		ErrorCodeName{"FRS_ERR_AUTHENTICATION", FRS_ERR_AUTHENTICATION},  //! The file replication service cannot satisfy the request because authenticated RPC is not available. The event log may have more information.
		ErrorCodeName{"FRS_ERR_PARENT_INSUFFICIENT_PRIV", FRS_ERR_PARENT_INSUFFICIENT_PRIV},  //! The file replication service cannot satisfy the request because the user has insufficient privileges on the domain controller. The event log may have more information.
		ErrorCodeName{"FRS_ERR_PARENT_AUTHENTICATION", FRS_ERR_PARENT_AUTHENTICATION},  //! The file replication service cannot satisfy the request because authenticated RPC is not available on the domain controller. The event log may have more information.
		ErrorCodeName{"FRS_ERR_CHILD_TO_PARENT_COMM", FRS_ERR_CHILD_TO_PARENT_COMM},  //! The file replication service cannot communicate with the file replication service on the domain controller. The event log may have more information.
		ErrorCodeName{"FRS_ERR_PARENT_TO_CHILD_COMM", FRS_ERR_PARENT_TO_CHILD_COMM},  //! The file replication service on the domain controller cannot communicate with the file replication service on this computer. The event log may have more information.
		ErrorCodeName{"FRS_ERR_SYSVOL_POPULATE", FRS_ERR_SYSVOL_POPULATE},  //! The file replication service cannot populate the system volume because of an internal error. The event log may have more information.
		ErrorCodeName{"FRS_ERR_SYSVOL_POPULATE_TIMEOUT", FRS_ERR_SYSVOL_POPULATE_TIMEOUT},  //! The file replication service cannot populate the system volume because of an internal timeout. The event log may have more information.
		ErrorCodeName{"FRS_ERR_SYSVOL_IS_BUSY", FRS_ERR_SYSVOL_IS_BUSY},  //! The file replication service cannot process the request. The system volume is busy with a previous request.
		ErrorCodeName{"FRS_ERR_SYSVOL_DEMOTE", FRS_ERR_SYSVOL_DEMOTE},  //! The file replication service cannot stop replicating the system volume because of an internal error. The event log may have more information.
		ErrorCodeName{"FRS_ERR_INVALID_SERVICE_PARAMETER", FRS_ERR_INVALID_SERVICE_PARAMETER},  //! The file replication service detected an invalid parameter.
		ErrorCodeName{"ERROR_DS_NOT_INSTALLED", ERROR_DS_NOT_INSTALLED},  //! An error occurred while installing the directory service. For more information, see the event log.
		ErrorCodeName{"ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY", ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY},  //! The directory service evaluated group memberships locally.
		ErrorCodeName{"ERROR_DS_NO_ATTRIBUTE_OR_VALUE", ERROR_DS_NO_ATTRIBUTE_OR_VALUE},  //! The specified directory service attribute or value does not exist.
		ErrorCodeName{"ERROR_DS_INVALID_ATTRIBUTE_SYNTAX", ERROR_DS_INVALID_ATTRIBUTE_SYNTAX},  //! The attribute syntax specified to the directory service is invalid.
		ErrorCodeName{"ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED", ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED},  //! The attribute type specified to the directory service is not defined.
		ErrorCodeName{"ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS", ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS},  //! The specified directory service attribute or value already exists.
		ErrorCodeName{"ERROR_DS_BUSY", ERROR_DS_BUSY},  //! The directory service is busy.
		ErrorCodeName{"ERROR_DS_UNAVAILABLE", ERROR_DS_UNAVAILABLE},  //! The directory service is unavailable.
		ErrorCodeName{"ERROR_DS_NO_RIDS_ALLOCATED", ERROR_DS_NO_RIDS_ALLOCATED},  //! The directory service was unable to allocate a relative identifier.
		ErrorCodeName{"ERROR_DS_NO_MORE_RIDS", ERROR_DS_NO_MORE_RIDS},  //! The directory service has exhausted the pool of relative identifiers.
		ErrorCodeName{"ERROR_DS_INCORRECT_ROLE_OWNER", ERROR_DS_INCORRECT_ROLE_OWNER},  //! The requested operation could not be performed because the directory service is not the master for that type of operation.
		ErrorCodeName{"ERROR_DS_RIDMGR_INIT_ERROR", ERROR_DS_RIDMGR_INIT_ERROR},  //! The directory service was unable to initialize the subsystem that allocates relative identifiers.
		ErrorCodeName{"ERROR_DS_OBJ_CLASS_VIOLATION", ERROR_DS_OBJ_CLASS_VIOLATION},  //! The requested operation did not satisfy one or more constraints associated with the class of the object.
		ErrorCodeName{"ERROR_DS_CANT_ON_NON_LEAF", ERROR_DS_CANT_ON_NON_LEAF},  //! The directory service can perform the requested operation only on a leaf object.
		ErrorCodeName{"ERROR_DS_CANT_ON_RDN", ERROR_DS_CANT_ON_RDN},  //! The directory service cannot perform the requested operation on the RDN attribute of an object.
		ErrorCodeName{"ERROR_DS_CANT_MOD_OBJ_CLASS", ERROR_DS_CANT_MOD_OBJ_CLASS},  //! The directory service detected an attempt to modify the object class of an object.
		ErrorCodeName{"ERROR_DS_CROSS_DOM_MOVE_ERROR", ERROR_DS_CROSS_DOM_MOVE_ERROR},  //! The requested cross-domain move operation could not be performed.
		ErrorCodeName{"ERROR_DS_GC_NOT_AVAILABLE", ERROR_DS_GC_NOT_AVAILABLE},  //! Unable to contact the global catalog server.
		ErrorCodeName{"ERROR_SHARED_POLICY", ERROR_SHARED_POLICY},  //! The policy object is shared and can only be modified at the root.
		ErrorCodeName{"ERROR_POLICY_OBJECT_NOT_FOUND", ERROR_POLICY_OBJECT_NOT_FOUND},  //! The policy object does not exist.
		ErrorCodeName{"ERROR_POLICY_ONLY_IN_DS", ERROR_POLICY_ONLY_IN_DS},  //! The requested policy information is only in the directory service.
		ErrorCodeName{"ERROR_PROMOTION_ACTIVE", ERROR_PROMOTION_ACTIVE},  //! A domain controller promotion is currently active.
		ErrorCodeName{"ERROR_NO_PROMOTION_ACTIVE", ERROR_NO_PROMOTION_ACTIVE},  //! A domain controller promotion is not currently active.
		ErrorCodeName{"ERROR_DS_OPERATIONS_ERROR", ERROR_DS_OPERATIONS_ERROR},  //! An operations error occurred.
		ErrorCodeName{"ERROR_DS_PROTOCOL_ERROR", ERROR_DS_PROTOCOL_ERROR},  //! A protocol error occurred.
		ErrorCodeName{"ERROR_DS_TIMELIMIT_EXCEEDED", ERROR_DS_TIMELIMIT_EXCEEDED},  //! The time limit for this request was exceeded.
		ErrorCodeName{"ERROR_DS_SIZELIMIT_EXCEEDED", ERROR_DS_SIZELIMIT_EXCEEDED},  //! The size limit for this request was exceeded.
		ErrorCodeName{"ERROR_DS_ADMIN_LIMIT_EXCEEDED", ERROR_DS_ADMIN_LIMIT_EXCEEDED},  //! The administrative limit for this request was exceeded.
		ErrorCodeName{"ERROR_DS_COMPARE_FALSE", ERROR_DS_COMPARE_FALSE},  //! The compare response was false.
		ErrorCodeName{"ERROR_DS_COMPARE_TRUE", ERROR_DS_COMPARE_TRUE},  //! The compare response was true.
		ErrorCodeName{"ERROR_DS_AUTH_METHOD_NOT_SUPPORTED", ERROR_DS_AUTH_METHOD_NOT_SUPPORTED},  //! The requested authentication method is not supported by the server.
		ErrorCodeName{"ERROR_DS_STRONG_AUTH_REQUIRED", ERROR_DS_STRONG_AUTH_REQUIRED},  //! A more secure authentication method is required for this server.
		ErrorCodeName{"ERROR_DS_INAPPROPRIATE_AUTH", ERROR_DS_INAPPROPRIATE_AUTH},  //! Inappropriate authentication.
		ErrorCodeName{"ERROR_DS_AUTH_UNKNOWN", ERROR_DS_AUTH_UNKNOWN},  //! The authentication mechanism is unknown.
		ErrorCodeName{"ERROR_DS_REFERRAL", ERROR_DS_REFERRAL},  //! A referral was returned from the server.
		ErrorCodeName{"ERROR_DS_UNAVAILABLE_CRIT_EXTENSION", ERROR_DS_UNAVAILABLE_CRIT_EXTENSION},  //! The server does not support the requested critical extension.
		ErrorCodeName{"ERROR_DS_CONFIDENTIALITY_REQUIRED", ERROR_DS_CONFIDENTIALITY_REQUIRED},  //! This request requires a secure connection.
		ErrorCodeName{"ERROR_DS_INAPPROPRIATE_MATCHING", ERROR_DS_INAPPROPRIATE_MATCHING},  //! Inappropriate matching.
		ErrorCodeName{"ERROR_DS_CONSTRAINT_VIOLATION", ERROR_DS_CONSTRAINT_VIOLATION},  //! A constraint violation occurred.
		ErrorCodeName{"ERROR_DS_NO_SUCH_OBJECT", ERROR_DS_NO_SUCH_OBJECT},  //! There is no such object on the server.
		ErrorCodeName{"ERROR_DS_ALIAS_PROBLEM", ERROR_DS_ALIAS_PROBLEM},  //! There is an alias problem.
		ErrorCodeName{"ERROR_DS_INVALID_DN_SYNTAX", ERROR_DS_INVALID_DN_SYNTAX},  //! An invalid dn syntax has been specified.
		ErrorCodeName{"ERROR_DS_IS_LEAF", ERROR_DS_IS_LEAF},  //! The object is a leaf object.
		ErrorCodeName{"ERROR_DS_ALIAS_DEREF_PROBLEM", ERROR_DS_ALIAS_DEREF_PROBLEM},  //! There is an alias dereferencing problem.
		ErrorCodeName{"ERROR_DS_UNWILLING_TO_PERFORM", ERROR_DS_UNWILLING_TO_PERFORM},  //! The server is unwilling to process the request.
		ErrorCodeName{"ERROR_DS_LOOP_DETECT", ERROR_DS_LOOP_DETECT},  //! A loop has been detected.
		ErrorCodeName{"ERROR_DS_NAMING_VIOLATION", ERROR_DS_NAMING_VIOLATION},  //! There is a naming violation.
		ErrorCodeName{"ERROR_DS_OBJECT_RESULTS_TOO_LARGE", ERROR_DS_OBJECT_RESULTS_TOO_LARGE},  //! The result set is too large.
		ErrorCodeName{"ERROR_DS_AFFECTS_MULTIPLE_DSAS", ERROR_DS_AFFECTS_MULTIPLE_DSAS},  //! The operation affects multiple DSAs.
		ErrorCodeName{"ERROR_DS_SERVER_DOWN", ERROR_DS_SERVER_DOWN},  //! The server is not operational.
		ErrorCodeName{"ERROR_DS_LOCAL_ERROR", ERROR_DS_LOCAL_ERROR},  //! A local error has occurred.
		ErrorCodeName{"ERROR_DS_ENCODING_ERROR", ERROR_DS_ENCODING_ERROR},  //! An encoding error has occurred.
		ErrorCodeName{"ERROR_DS_DECODING_ERROR", ERROR_DS_DECODING_ERROR},  //! A decoding error has occurred.
		ErrorCodeName{"ERROR_DS_FILTER_UNKNOWN", ERROR_DS_FILTER_UNKNOWN},  //! The search filter cannot be recognized.
		ErrorCodeName{"ERROR_DS_PARAM_ERROR", ERROR_DS_PARAM_ERROR},  //! One or more parameters are illegal.
		ErrorCodeName{"ERROR_DS_NOT_SUPPORTED", ERROR_DS_NOT_SUPPORTED},  //! The specified method is not supported.
		ErrorCodeName{"ERROR_DS_NO_RESULTS_RETURNED", ERROR_DS_NO_RESULTS_RETURNED},  //! No results were returned.
		ErrorCodeName{"ERROR_DS_CONTROL_NOT_FOUND", ERROR_DS_CONTROL_NOT_FOUND},  //! The specified control is not supported by the server.
		ErrorCodeName{"ERROR_DS_CLIENT_LOOP", ERROR_DS_CLIENT_LOOP},  //! A referral loop was detected by the client.
		ErrorCodeName{"ERROR_DS_REFERRAL_LIMIT_EXCEEDED", ERROR_DS_REFERRAL_LIMIT_EXCEEDED},  //! The preset referral limit was exceeded.
		ErrorCodeName{"ERROR_DS_SORT_CONTROL_MISSING", ERROR_DS_SORT_CONTROL_MISSING},  //! The search requires a SORT control.
		ErrorCodeName{"ERROR_DS_OFFSET_RANGE_ERROR", ERROR_DS_OFFSET_RANGE_ERROR},  //! The search results exceed the offset range specified.
		ErrorCodeName{"ERROR_DS_RIDMGR_DISABLED", ERROR_DS_RIDMGR_DISABLED},  //! The directory service detected the subsystem that allocates relative identifiers is disabled. This can occur as a protective mechanism when the system determines a significant portion of relative identifiers (RIDs) have been exhausted. Please see https://go.microsoft.com/fwlink/p/?linkid=228610 for recommended diagnostic steps and the procedure to re-enable account creation.
		ErrorCodeName{"ERROR_DS_ROOT_MUST_BE_NC", ERROR_DS_ROOT_MUST_BE_NC},  //! The root object must be the head of a naming context. The root object cannot have an instantiated parent.
		ErrorCodeName{"ERROR_DS_ADD_REPLICA_INHIBITED", ERROR_DS_ADD_REPLICA_INHIBITED},  //! The add replica operation cannot be performed. The naming context must be writeable in order to create the replica.
		ErrorCodeName{"ERROR_DS_ATT_NOT_DEF_IN_SCHEMA", ERROR_DS_ATT_NOT_DEF_IN_SCHEMA},  //! A reference to an attribute that is not defined in the schema occurred.
		ErrorCodeName{"ERROR_DS_MAX_OBJ_SIZE_EXCEEDED", ERROR_DS_MAX_OBJ_SIZE_EXCEEDED},  //! The maximum size of an object has been exceeded.
		ErrorCodeName{"ERROR_DS_OBJ_STRING_NAME_EXISTS", ERROR_DS_OBJ_STRING_NAME_EXISTS},  //! An attempt was made to add an object to the directory with a name that is already in use.
		ErrorCodeName{"ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA", ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA},  //! An attempt was made to add an object of a class that does not have an RDN defined in the schema.
		ErrorCodeName{"ERROR_DS_RDN_DOESNT_MATCH_SCHEMA", ERROR_DS_RDN_DOESNT_MATCH_SCHEMA},  //! An attempt was made to add an object using an RDN that is not the RDN defined in the schema.
		ErrorCodeName{"ERROR_DS_NO_REQUESTED_ATTS_FOUND", ERROR_DS_NO_REQUESTED_ATTS_FOUND},  //! None of the requested attributes were found on the objects.
		ErrorCodeName{"ERROR_DS_USER_BUFFER_TO_SMALL", ERROR_DS_USER_BUFFER_TO_SMALL},  //! The user buffer is too small.
		ErrorCodeName{"ERROR_DS_ATT_IS_NOT_ON_OBJ", ERROR_DS_ATT_IS_NOT_ON_OBJ},  //! The attribute specified in the operation is not present on the object.
		ErrorCodeName{"ERROR_DS_ILLEGAL_MOD_OPERATION", ERROR_DS_ILLEGAL_MOD_OPERATION},  //! Illegal modify operation. Some aspect of the modification is not permitted.
		ErrorCodeName{"ERROR_DS_OBJ_TOO_LARGE", ERROR_DS_OBJ_TOO_LARGE},  //! The specified object is too large.
		ErrorCodeName{"ERROR_DS_BAD_INSTANCE_TYPE", ERROR_DS_BAD_INSTANCE_TYPE},  //! The specified instance type is not valid.
		ErrorCodeName{"ERROR_DS_MASTERDSA_REQUIRED", ERROR_DS_MASTERDSA_REQUIRED},  //! The operation must be performed at a master DSA.
		ErrorCodeName{"ERROR_DS_OBJECT_CLASS_REQUIRED", ERROR_DS_OBJECT_CLASS_REQUIRED},  //! The object class attribute must be specified.
		ErrorCodeName{"ERROR_DS_MISSING_REQUIRED_ATT", ERROR_DS_MISSING_REQUIRED_ATT},  //! A required attribute is missing.
		ErrorCodeName{"ERROR_DS_ATT_NOT_DEF_FOR_CLASS", ERROR_DS_ATT_NOT_DEF_FOR_CLASS},  //! An attempt was made to modify an object to include an attribute that is not legal for its class.
		ErrorCodeName{"ERROR_DS_ATT_ALREADY_EXISTS", ERROR_DS_ATT_ALREADY_EXISTS},  //! The specified attribute is already present on the object.
		ErrorCodeName{"ERROR_DS_CANT_ADD_ATT_VALUES", ERROR_DS_CANT_ADD_ATT_VALUES},  //! The specified attribute is not present, or has no values.
		ErrorCodeName{"ERROR_DS_SINGLE_VALUE_CONSTRAINT", ERROR_DS_SINGLE_VALUE_CONSTRAINT},  //! Multiple values were specified for an attribute that can have only one value.
		ErrorCodeName{"ERROR_DS_RANGE_CONSTRAINT", ERROR_DS_RANGE_CONSTRAINT},  //! A value for the attribute was not in the acceptable range of values.
		ErrorCodeName{"ERROR_DS_ATT_VAL_ALREADY_EXISTS", ERROR_DS_ATT_VAL_ALREADY_EXISTS},  //! The specified value already exists.
		ErrorCodeName{"ERROR_DS_CANT_REM_MISSING_ATT", ERROR_DS_CANT_REM_MISSING_ATT},  //! The attribute cannot be removed because it is not present on the object.
		ErrorCodeName{"ERROR_DS_CANT_REM_MISSING_ATT_VAL", ERROR_DS_CANT_REM_MISSING_ATT_VAL},  //! The attribute value cannot be removed because it is not present on the object.
		ErrorCodeName{"ERROR_DS_ROOT_CANT_BE_SUBREF", ERROR_DS_ROOT_CANT_BE_SUBREF},  //! The specified root object cannot be a subref.
		ErrorCodeName{"ERROR_DS_NO_CHAINING", ERROR_DS_NO_CHAINING},  //! Chaining is not permitted.
		ErrorCodeName{"ERROR_DS_NO_CHAINED_EVAL", ERROR_DS_NO_CHAINED_EVAL},  //! Chained evaluation is not permitted.
		ErrorCodeName{"ERROR_DS_NO_PARENT_OBJECT", ERROR_DS_NO_PARENT_OBJECT},  //! The operation could not be performed because the object's parent is either uninstantiated or deleted.
		ErrorCodeName{"ERROR_DS_PARENT_IS_AN_ALIAS", ERROR_DS_PARENT_IS_AN_ALIAS},  //! Having a parent that is an alias is not permitted. Aliases are leaf objects.
		ErrorCodeName{"ERROR_DS_CANT_MIX_MASTER_AND_REPS", ERROR_DS_CANT_MIX_MASTER_AND_REPS},  //! The object and parent must be of the same type, either both masters or both replicas.
		ErrorCodeName{"ERROR_DS_CHILDREN_EXIST", ERROR_DS_CHILDREN_EXIST},  //! The operation cannot be performed because child objects exist. This operation can only be performed on a leaf object.
		ErrorCodeName{"ERROR_DS_OBJ_NOT_FOUND", ERROR_DS_OBJ_NOT_FOUND},  //! Directory object not found.
		ErrorCodeName{"ERROR_DS_ALIASED_OBJ_MISSING", ERROR_DS_ALIASED_OBJ_MISSING},  //! The aliased object is missing.
		ErrorCodeName{"ERROR_DS_BAD_NAME_SYNTAX", ERROR_DS_BAD_NAME_SYNTAX},  //! The object name has bad syntax.
		ErrorCodeName{"ERROR_DS_ALIAS_POINTS_TO_ALIAS", ERROR_DS_ALIAS_POINTS_TO_ALIAS},  //! It is not permitted for an alias to refer to another alias.
		ErrorCodeName{"ERROR_DS_CANT_DEREF_ALIAS", ERROR_DS_CANT_DEREF_ALIAS},  //! The alias cannot be dereferenced.
		ErrorCodeName{"ERROR_DS_OUT_OF_SCOPE", ERROR_DS_OUT_OF_SCOPE},  //! The operation is out of scope.
		ErrorCodeName{"ERROR_DS_OBJECT_BEING_REMOVED", ERROR_DS_OBJECT_BEING_REMOVED},  //! The operation cannot continue because the object is in the process of being removed.
		ErrorCodeName{"ERROR_DS_CANT_DELETE_DSA_OBJ", ERROR_DS_CANT_DELETE_DSA_OBJ},  //! The DSA object cannot be deleted.
		ErrorCodeName{"ERROR_DS_GENERIC_ERROR", ERROR_DS_GENERIC_ERROR},  //! A directory service error has occurred.
		ErrorCodeName{"ERROR_DS_DSA_MUST_BE_INT_MASTER", ERROR_DS_DSA_MUST_BE_INT_MASTER},  //! The operation can only be performed on an internal master DSA object.
		ErrorCodeName{"ERROR_DS_CLASS_NOT_DSA", ERROR_DS_CLASS_NOT_DSA},  //! The object must be of class DSA.
		ErrorCodeName{"ERROR_DS_INSUFF_ACCESS_RIGHTS", ERROR_DS_INSUFF_ACCESS_RIGHTS},  //! Insufficient access rights to perform the operation.
		ErrorCodeName{"ERROR_DS_ILLEGAL_SUPERIOR", ERROR_DS_ILLEGAL_SUPERIOR},  //! The object cannot be added because the parent is not on the list of possible superiors.
		ErrorCodeName{"ERROR_DS_ATTRIBUTE_OWNED_BY_SAM", ERROR_DS_ATTRIBUTE_OWNED_BY_SAM},  //! Access to the attribute is not permitted because the attribute is owned by the Security Accounts Manager (SAM).
		ErrorCodeName{"ERROR_DS_NAME_TOO_MANY_PARTS", ERROR_DS_NAME_TOO_MANY_PARTS},  //! The name has too many parts.
		ErrorCodeName{"ERROR_DS_NAME_TOO_LONG", ERROR_DS_NAME_TOO_LONG},  //! The name is too long.
		ErrorCodeName{"ERROR_DS_NAME_VALUE_TOO_LONG", ERROR_DS_NAME_VALUE_TOO_LONG},  //! The name value is too long.
		ErrorCodeName{"ERROR_DS_NAME_UNPARSEABLE", ERROR_DS_NAME_UNPARSEABLE},  //! The directory service encountered an error parsing a name.
		ErrorCodeName{"ERROR_DS_NAME_TYPE_UNKNOWN", ERROR_DS_NAME_TYPE_UNKNOWN},  //! The directory service cannot get the attribute type for a name.
		ErrorCodeName{"ERROR_DS_NOT_AN_OBJECT", ERROR_DS_NOT_AN_OBJECT},  //! The name does not identify an object; the name identifies a phantom.
		ErrorCodeName{"ERROR_DS_SEC_DESC_TOO_SHORT", ERROR_DS_SEC_DESC_TOO_SHORT},  //! The security descriptor is too short.
		ErrorCodeName{"ERROR_DS_SEC_DESC_INVALID", ERROR_DS_SEC_DESC_INVALID},  //! The security descriptor is invalid.
		ErrorCodeName{"ERROR_DS_NO_DELETED_NAME", ERROR_DS_NO_DELETED_NAME},  //! Failed to create name for deleted object.
		ErrorCodeName{"ERROR_DS_SUBREF_MUST_HAVE_PARENT", ERROR_DS_SUBREF_MUST_HAVE_PARENT},  //! The parent of a new subref must exist.
		ErrorCodeName{"ERROR_DS_NCNAME_MUST_BE_NC", ERROR_DS_NCNAME_MUST_BE_NC},  //! The object must be a naming context.
		ErrorCodeName{"ERROR_DS_CANT_ADD_SYSTEM_ONLY", ERROR_DS_CANT_ADD_SYSTEM_ONLY},  //! It is not permitted to add an attribute which is owned by the system.
		ErrorCodeName{"ERROR_DS_CLASS_MUST_BE_CONCRETE", ERROR_DS_CLASS_MUST_BE_CONCRETE},  //! The class of the object must be structural; you cannot instantiate an abstract class.
		ErrorCodeName{"ERROR_DS_INVALID_DMD", ERROR_DS_INVALID_DMD},  //! The schema object could not be found.
		ErrorCodeName{"ERROR_DS_OBJ_GUID_EXISTS", ERROR_DS_OBJ_GUID_EXISTS},  //! A local object with this GUID (dead or alive) already exists.
		ErrorCodeName{"ERROR_DS_NOT_ON_BACKLINK", ERROR_DS_NOT_ON_BACKLINK},  //! The operation cannot be performed on a back link.
		ErrorCodeName{"ERROR_DS_NO_CROSSREF_FOR_NC", ERROR_DS_NO_CROSSREF_FOR_NC},  //! The cross reference for the specified naming context could not be found.
		ErrorCodeName{"ERROR_DS_SHUTTING_DOWN", ERROR_DS_SHUTTING_DOWN},  //! The operation could not be performed because the directory service is shutting down.
		ErrorCodeName{"ERROR_DS_UNKNOWN_OPERATION", ERROR_DS_UNKNOWN_OPERATION},  //! The directory service request is invalid.
		ErrorCodeName{"ERROR_DS_INVALID_ROLE_OWNER", ERROR_DS_INVALID_ROLE_OWNER},  //! The role owner attribute could not be read.
		ErrorCodeName{"ERROR_DS_COULDNT_CONTACT_FSMO", ERROR_DS_COULDNT_CONTACT_FSMO},  //! The requested FSMO operation failed. The current FSMO holder could not be contacted.
		ErrorCodeName{"ERROR_DS_CROSS_NC_DN_RENAME", ERROR_DS_CROSS_NC_DN_RENAME},  //! Modification of a DN across a naming context is not permitted.
		ErrorCodeName{"ERROR_DS_CANT_MOD_SYSTEM_ONLY", ERROR_DS_CANT_MOD_SYSTEM_ONLY},  //! The attribute cannot be modified because it is owned by the system.
		ErrorCodeName{"ERROR_DS_REPLICATOR_ONLY", ERROR_DS_REPLICATOR_ONLY},  //! Only the replicator can perform this function.
		ErrorCodeName{"ERROR_DS_OBJ_CLASS_NOT_DEFINED", ERROR_DS_OBJ_CLASS_NOT_DEFINED},  //! The specified class is not defined.
		ErrorCodeName{"ERROR_DS_OBJ_CLASS_NOT_SUBCLASS", ERROR_DS_OBJ_CLASS_NOT_SUBCLASS},  //! The specified class is not a subclass.
		ErrorCodeName{"ERROR_DS_NAME_REFERENCE_INVALID", ERROR_DS_NAME_REFERENCE_INVALID},  //! The name reference is invalid.
		ErrorCodeName{"ERROR_DS_CROSS_REF_EXISTS", ERROR_DS_CROSS_REF_EXISTS},  //! A cross reference already exists.
		ErrorCodeName{"ERROR_DS_CANT_DEL_MASTER_CROSSREF", ERROR_DS_CANT_DEL_MASTER_CROSSREF},  //! It is not permitted to delete a master cross reference.
		ErrorCodeName{"ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD", ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD},  //! Subtree notifications are only supported on NC heads.
		ErrorCodeName{"ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX", ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX},  //! Notification filter is too complex.
		ErrorCodeName{"ERROR_DS_DUP_RDN", ERROR_DS_DUP_RDN},  //! Schema update failed: duplicate RDN.
		ErrorCodeName{"ERROR_DS_DUP_OID", ERROR_DS_DUP_OID},  //! Schema update failed: duplicate OID.
		ErrorCodeName{"ERROR_DS_DUP_MAPI_ID", ERROR_DS_DUP_MAPI_ID},  //! Schema update failed: duplicate MAPI identifier.
		ErrorCodeName{"ERROR_DS_DUP_SCHEMA_ID_GUID", ERROR_DS_DUP_SCHEMA_ID_GUID},  //! Schema update failed: duplicate schema-id GUID.
		ErrorCodeName{"ERROR_DS_DUP_LDAP_DISPLAY_NAME", ERROR_DS_DUP_LDAP_DISPLAY_NAME},  //! Schema update failed: duplicate LDAP display name.
		ErrorCodeName{"ERROR_DS_SEMANTIC_ATT_TEST", ERROR_DS_SEMANTIC_ATT_TEST},  //! Schema update failed: range-lower less than range upper.
		ErrorCodeName{"ERROR_DS_SYNTAX_MISMATCH", ERROR_DS_SYNTAX_MISMATCH},  //! Schema update failed: syntax mismatch.
		ErrorCodeName{"ERROR_DS_EXISTS_IN_MUST_HAVE", ERROR_DS_EXISTS_IN_MUST_HAVE},  //! Schema deletion failed: attribute is used in must-contain.
		ErrorCodeName{"ERROR_DS_EXISTS_IN_MAY_HAVE", ERROR_DS_EXISTS_IN_MAY_HAVE},  //! Schema deletion failed: attribute is used in may-contain.
		ErrorCodeName{"ERROR_DS_NONEXISTENT_MAY_HAVE", ERROR_DS_NONEXISTENT_MAY_HAVE},  //! Schema update failed: attribute in may-contain does not exist.
		ErrorCodeName{"ERROR_DS_NONEXISTENT_MUST_HAVE", ERROR_DS_NONEXISTENT_MUST_HAVE},  //! Schema update failed: attribute in must-contain does not exist.
		ErrorCodeName{"ERROR_DS_AUX_CLS_TEST_FAIL", ERROR_DS_AUX_CLS_TEST_FAIL},  //! Schema update failed: class in aux-class list does not exist or is not an auxiliary class.
		ErrorCodeName{"ERROR_DS_NONEXISTENT_POSS_SUP", ERROR_DS_NONEXISTENT_POSS_SUP},  //! Schema update failed: class in poss-superiors does not exist.
		ErrorCodeName{"ERROR_DS_SUB_CLS_TEST_FAIL", ERROR_DS_SUB_CLS_TEST_FAIL},  //! Schema update failed: class in subclassof list does not exist or does not satisfy hierarchy rules.
		ErrorCodeName{"ERROR_DS_BAD_RDN_ATT_ID_SYNTAX", ERROR_DS_BAD_RDN_ATT_ID_SYNTAX},  //! Schema update failed: Rdn-Att-Id has wrong syntax.
		ErrorCodeName{"ERROR_DS_EXISTS_IN_AUX_CLS", ERROR_DS_EXISTS_IN_AUX_CLS},  //! Schema deletion failed: class is used as auxiliary class.
		ErrorCodeName{"ERROR_DS_EXISTS_IN_SUB_CLS", ERROR_DS_EXISTS_IN_SUB_CLS},  //! Schema deletion failed: class is used as sub class.
		ErrorCodeName{"ERROR_DS_EXISTS_IN_POSS_SUP", ERROR_DS_EXISTS_IN_POSS_SUP},  //! Schema deletion failed: class is used as poss superior.
		ErrorCodeName{"ERROR_DS_RECALCSCHEMA_FAILED", ERROR_DS_RECALCSCHEMA_FAILED},  //! Schema update failed in recalculating validation cache.
		ErrorCodeName{"ERROR_DS_TREE_DELETE_NOT_FINISHED", ERROR_DS_TREE_DELETE_NOT_FINISHED},  //! The tree deletion is not finished. The request must be made again to continue deleting the tree.
		ErrorCodeName{"ERROR_DS_CANT_DELETE", ERROR_DS_CANT_DELETE},  //! The requested delete operation could not be performed.
		ErrorCodeName{"ERROR_DS_ATT_SCHEMA_REQ_ID", ERROR_DS_ATT_SCHEMA_REQ_ID},  //! Cannot read the governs class identifier for the schema record.
		ErrorCodeName{"ERROR_DS_BAD_ATT_SCHEMA_SYNTAX", ERROR_DS_BAD_ATT_SCHEMA_SYNTAX},  //! The attribute schema has bad syntax.
		ErrorCodeName{"ERROR_DS_CANT_CACHE_ATT", ERROR_DS_CANT_CACHE_ATT},  //! The attribute could not be cached.
		ErrorCodeName{"ERROR_DS_CANT_CACHE_CLASS", ERROR_DS_CANT_CACHE_CLASS},  //! The class could not be cached.
		ErrorCodeName{"ERROR_DS_CANT_REMOVE_ATT_CACHE", ERROR_DS_CANT_REMOVE_ATT_CACHE},  //! The attribute could not be removed from the cache.
		ErrorCodeName{"ERROR_DS_CANT_REMOVE_CLASS_CACHE", ERROR_DS_CANT_REMOVE_CLASS_CACHE},  //! The class could not be removed from the cache.
		ErrorCodeName{"ERROR_DS_CANT_RETRIEVE_DN", ERROR_DS_CANT_RETRIEVE_DN},  //! The distinguished name attribute could not be read.
		ErrorCodeName{"ERROR_DS_MISSING_SUPREF", ERROR_DS_MISSING_SUPREF},  //! No superior reference has been configured for the directory service. The directory service is therefore unable to issue referrals to objects outside this forest.
		ErrorCodeName{"ERROR_DS_CANT_RETRIEVE_INSTANCE", ERROR_DS_CANT_RETRIEVE_INSTANCE},  //! The instance type attribute could not be retrieved.
		ErrorCodeName{"ERROR_DS_CODE_INCONSISTENCY", ERROR_DS_CODE_INCONSISTENCY},  //! An internal error has occurred.
		ErrorCodeName{"ERROR_DS_DATABASE_ERROR", ERROR_DS_DATABASE_ERROR},  //! A database error has occurred.
		ErrorCodeName{"ERROR_DS_GOVERNSID_MISSING", ERROR_DS_GOVERNSID_MISSING},  //! The attribute GOVERNSID is missing.
		ErrorCodeName{"ERROR_DS_MISSING_EXPECTED_ATT", ERROR_DS_MISSING_EXPECTED_ATT},  //! An expected attribute is missing.
		ErrorCodeName{"ERROR_DS_NCNAME_MISSING_CR_REF", ERROR_DS_NCNAME_MISSING_CR_REF},  //! The specified naming context is missing a cross reference.
		ErrorCodeName{"ERROR_DS_SECURITY_CHECKING_ERROR", ERROR_DS_SECURITY_CHECKING_ERROR},  //! A security checking error has occurred.
		ErrorCodeName{"ERROR_DS_SCHEMA_NOT_LOADED", ERROR_DS_SCHEMA_NOT_LOADED},  //! The schema is not loaded.
		ErrorCodeName{"ERROR_DS_SCHEMA_ALLOC_FAILED", ERROR_DS_SCHEMA_ALLOC_FAILED},  //! Schema allocation failed. Please check if the machine is running low on memory.
		ErrorCodeName{"ERROR_DS_ATT_SCHEMA_REQ_SYNTAX", ERROR_DS_ATT_SCHEMA_REQ_SYNTAX},  //! Failed to obtain the required syntax for the attribute schema.
		ErrorCodeName{"ERROR_DS_GCVERIFY_ERROR", ERROR_DS_GCVERIFY_ERROR},  //! The global catalog verification failed. The global catalog is not available or does not support the operation. Some part of the directory is currently not available.
		ErrorCodeName{"ERROR_DS_DRA_SCHEMA_MISMATCH", ERROR_DS_DRA_SCHEMA_MISMATCH},  //! The replication operation failed because of a schema mismatch between the servers involved.
		ErrorCodeName{"ERROR_DS_CANT_FIND_DSA_OBJ", ERROR_DS_CANT_FIND_DSA_OBJ},  //! The DSA object could not be found.
		ErrorCodeName{"ERROR_DS_CANT_FIND_EXPECTED_NC", ERROR_DS_CANT_FIND_EXPECTED_NC},  //! The naming context could not be found.
		ErrorCodeName{"ERROR_DS_CANT_FIND_NC_IN_CACHE", ERROR_DS_CANT_FIND_NC_IN_CACHE},  //! The naming context could not be found in the cache.
		ErrorCodeName{"ERROR_DS_CANT_RETRIEVE_CHILD", ERROR_DS_CANT_RETRIEVE_CHILD},  //! The child object could not be retrieved.
		ErrorCodeName{"ERROR_DS_SECURITY_ILLEGAL_MODIFY", ERROR_DS_SECURITY_ILLEGAL_MODIFY},  //! The modification was not permitted for security reasons.
		ErrorCodeName{"ERROR_DS_CANT_REPLACE_HIDDEN_REC", ERROR_DS_CANT_REPLACE_HIDDEN_REC},  //! The operation cannot replace the hidden record.
		ErrorCodeName{"ERROR_DS_BAD_HIERARCHY_FILE", ERROR_DS_BAD_HIERARCHY_FILE},  //! The hierarchy file is invalid.
		ErrorCodeName{"ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED", ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED},  //! The attempt to build the hierarchy table failed.
		ErrorCodeName{"ERROR_DS_CONFIG_PARAM_MISSING", ERROR_DS_CONFIG_PARAM_MISSING},  //! The directory configuration parameter is missing from the registry.
		ErrorCodeName{"ERROR_DS_COUNTING_AB_INDICES_FAILED", ERROR_DS_COUNTING_AB_INDICES_FAILED},  //! The attempt to count the address book indices failed.
		ErrorCodeName{"ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED", ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED},  //! The allocation of the hierarchy table failed.
		ErrorCodeName{"ERROR_DS_INTERNAL_FAILURE", ERROR_DS_INTERNAL_FAILURE},  //! The directory service encountered an internal failure.
		ErrorCodeName{"ERROR_DS_UNKNOWN_ERROR", ERROR_DS_UNKNOWN_ERROR},  //! The directory service encountered an unknown failure.
		ErrorCodeName{"ERROR_DS_ROOT_REQUIRES_CLASS_TOP", ERROR_DS_ROOT_REQUIRES_CLASS_TOP},  //! A root object requires a class of 'top'.
		ErrorCodeName{"ERROR_DS_REFUSING_FSMO_ROLES", ERROR_DS_REFUSING_FSMO_ROLES},  //! This directory server is shutting down, and cannot take ownership of new floating single-master operation roles.
		ErrorCodeName{"ERROR_DS_MISSING_FSMO_SETTINGS", ERROR_DS_MISSING_FSMO_SETTINGS},  //! The directory service is missing mandatory configuration information, and is unable to determine the ownership of floating single-master operation roles.
		ErrorCodeName{"ERROR_DS_UNABLE_TO_SURRENDER_ROLES", ERROR_DS_UNABLE_TO_SURRENDER_ROLES},  //! The directory service was unable to transfer ownership of one or more floating single-master operation roles to other servers.
		ErrorCodeName{"ERROR_DS_DRA_GENERIC", ERROR_DS_DRA_GENERIC},  //! The replication operation failed.
		ErrorCodeName{"ERROR_DS_DRA_INVALID_PARAMETER", ERROR_DS_DRA_INVALID_PARAMETER},  //! An invalid parameter was specified for this replication operation.
		ErrorCodeName{"ERROR_DS_DRA_BUSY", ERROR_DS_DRA_BUSY},  //! The directory service is too busy to complete the replication operation at this time.
		ErrorCodeName{"ERROR_DS_DRA_BAD_DN", ERROR_DS_DRA_BAD_DN},  //! The distinguished name specified for this replication operation is invalid.
		ErrorCodeName{"ERROR_DS_DRA_BAD_NC", ERROR_DS_DRA_BAD_NC},  //! The naming context specified for this replication operation is invalid.
		ErrorCodeName{"ERROR_DS_DRA_DN_EXISTS", ERROR_DS_DRA_DN_EXISTS},  //! The distinguished name specified for this replication operation already exists.
		ErrorCodeName{"ERROR_DS_DRA_INTERNAL_ERROR", ERROR_DS_DRA_INTERNAL_ERROR},  //! The replication system encountered an internal error.
		ErrorCodeName{"ERROR_DS_DRA_INCONSISTENT_DIT", ERROR_DS_DRA_INCONSISTENT_DIT},  //! The replication operation encountered a database inconsistency.
		ErrorCodeName{"ERROR_DS_DRA_CONNECTION_FAILED", ERROR_DS_DRA_CONNECTION_FAILED},  //! The server specified for this replication operation could not be contacted.
		ErrorCodeName{"ERROR_DS_DRA_BAD_INSTANCE_TYPE", ERROR_DS_DRA_BAD_INSTANCE_TYPE},  //! The replication operation encountered an object with an invalid instance type.
		ErrorCodeName{"ERROR_DS_DRA_OUT_OF_MEM", ERROR_DS_DRA_OUT_OF_MEM},  //! The replication operation failed to allocate memory.
		ErrorCodeName{"ERROR_DS_DRA_MAIL_PROBLEM", ERROR_DS_DRA_MAIL_PROBLEM},  //! The replication operation encountered an error with the mail system.
		ErrorCodeName{"ERROR_DS_DRA_REF_ALREADY_EXISTS", ERROR_DS_DRA_REF_ALREADY_EXISTS},  //! The replication reference information for the target server already exists.
		ErrorCodeName{"ERROR_DS_DRA_REF_NOT_FOUND", ERROR_DS_DRA_REF_NOT_FOUND},  //! The replication reference information for the target server does not exist.
		ErrorCodeName{"ERROR_DS_DRA_OBJ_IS_REP_SOURCE", ERROR_DS_DRA_OBJ_IS_REP_SOURCE},  //! The naming context cannot be removed because it is replicated to another server.
		ErrorCodeName{"ERROR_DS_DRA_DB_ERROR", ERROR_DS_DRA_DB_ERROR},  //! The replication operation encountered a database error.
		ErrorCodeName{"ERROR_DS_DRA_NO_REPLICA", ERROR_DS_DRA_NO_REPLICA},  //! The naming context is in the process of being removed or is not replicated from the specified server.
		ErrorCodeName{"ERROR_DS_DRA_ACCESS_DENIED", ERROR_DS_DRA_ACCESS_DENIED},  //! Replication access was denied.
		ErrorCodeName{"ERROR_DS_DRA_NOT_SUPPORTED", ERROR_DS_DRA_NOT_SUPPORTED},  //! The requested operation is not supported by this version of the directory service.
		ErrorCodeName{"ERROR_DS_DRA_RPC_CANCELLED", ERROR_DS_DRA_RPC_CANCELLED},  //! The replication remote procedure call was cancelled.
		ErrorCodeName{"ERROR_DS_DRA_SOURCE_DISABLED", ERROR_DS_DRA_SOURCE_DISABLED},  //! The source server is currently rejecting replication requests.
		ErrorCodeName{"ERROR_DS_DRA_SINK_DISABLED", ERROR_DS_DRA_SINK_DISABLED},  //! The destination server is currently rejecting replication requests.
		ErrorCodeName{"ERROR_DS_DRA_NAME_COLLISION", ERROR_DS_DRA_NAME_COLLISION},  //! The replication operation failed due to a collision of object names.
		ErrorCodeName{"ERROR_DS_DRA_SOURCE_REINSTALLED", ERROR_DS_DRA_SOURCE_REINSTALLED},  //! The replication source has been reinstalled.
		ErrorCodeName{"ERROR_DS_DRA_MISSING_PARENT", ERROR_DS_DRA_MISSING_PARENT},  //! The replication operation failed because a required parent object is missing.
		ErrorCodeName{"ERROR_DS_DRA_PREEMPTED", ERROR_DS_DRA_PREEMPTED},  //! The replication operation was preempted.
		ErrorCodeName{"ERROR_DS_DRA_ABANDON_SYNC", ERROR_DS_DRA_ABANDON_SYNC},  //! The replication synchronization attempt was abandoned because of a lack of updates.
		ErrorCodeName{"ERROR_DS_DRA_SHUTDOWN", ERROR_DS_DRA_SHUTDOWN},  //! The replication operation was terminated because the system is shutting down.
		ErrorCodeName{"ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET", ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET},  //! Synchronization attempt failed because the destination DC is currently waiting to synchronize new partial attributes from source. This condition is normal if a recent schema change modified the partial attribute set. The destination partial attribute set is not a subset of source partial attribute set.
		ErrorCodeName{"ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA", ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA},  //! The replication synchronization attempt failed because a master replica attempted to sync from a partial replica.
		ErrorCodeName{"ERROR_DS_DRA_EXTN_CONNECTION_FAILED", ERROR_DS_DRA_EXTN_CONNECTION_FAILED},  //! The server specified for this replication operation was contacted, but that server was unable to contact an additional server needed to complete the operation.
		ErrorCodeName{"ERROR_DS_INSTALL_SCHEMA_MISMATCH", ERROR_DS_INSTALL_SCHEMA_MISMATCH},  //! The version of the directory service schema of the source forest is not compatible with the version of directory service on this computer.
		ErrorCodeName{"ERROR_DS_DUP_LINK_ID", ERROR_DS_DUP_LINK_ID},  //! Schema update failed: An attribute with the same link identifier already exists.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_RESOLVING", ERROR_DS_NAME_ERROR_RESOLVING},  //! Name translation: Generic processing error.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_NOT_FOUND", ERROR_DS_NAME_ERROR_NOT_FOUND},  //! Name translation: Could not find the name or insufficient right to see name.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_NOT_UNIQUE", ERROR_DS_NAME_ERROR_NOT_UNIQUE},  //! Name translation: Input name mapped to more than one output name.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_NO_MAPPING", ERROR_DS_NAME_ERROR_NO_MAPPING},  //! Name translation: Input name found, but not the associated output format.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_DOMAIN_ONLY", ERROR_DS_NAME_ERROR_DOMAIN_ONLY},  //! Name translation: Unable to resolve completely, only the domain was found.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING", ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING},  //! Name translation: Unable to perform purely syntactical mapping at the client without going out to the wire.
		ErrorCodeName{"ERROR_DS_CONSTRUCTED_ATT_MOD", ERROR_DS_CONSTRUCTED_ATT_MOD},  //! Modification of a constructed attribute is not allowed.
		ErrorCodeName{"ERROR_DS_WRONG_OM_OBJ_CLASS", ERROR_DS_WRONG_OM_OBJ_CLASS},  //! The OM-Object-Class specified is incorrect for an attribute with the specified syntax.
		ErrorCodeName{"ERROR_DS_DRA_REPL_PENDING", ERROR_DS_DRA_REPL_PENDING},  //! The replication request has been posted; waiting for reply.
		ErrorCodeName{"ERROR_DS_DS_REQUIRED", ERROR_DS_DS_REQUIRED},  //! The requested operation requires a directory service, and none was available.
		ErrorCodeName{"ERROR_DS_INVALID_LDAP_DISPLAY_NAME", ERROR_DS_INVALID_LDAP_DISPLAY_NAME},  //! The LDAP display name of the class or attribute contains non-ASCII characters.
		ErrorCodeName{"ERROR_DS_NON_BASE_SEARCH", ERROR_DS_NON_BASE_SEARCH},  //! The requested search operation is only supported for base searches.
		ErrorCodeName{"ERROR_DS_CANT_RETRIEVE_ATTS", ERROR_DS_CANT_RETRIEVE_ATTS},  //! The search failed to retrieve attributes from the database.
		ErrorCodeName{"ERROR_DS_BACKLINK_WITHOUT_LINK", ERROR_DS_BACKLINK_WITHOUT_LINK},  //! The schema update operation tried to add a backward link attribute that has no corresponding forward link.
		ErrorCodeName{"ERROR_DS_EPOCH_MISMATCH", ERROR_DS_EPOCH_MISMATCH},  //! Source and destination of a cross-domain move do not agree on the object's epoch number. Either source or destination does not have the latest version of the object.
		ErrorCodeName{"ERROR_DS_SRC_NAME_MISMATCH", ERROR_DS_SRC_NAME_MISMATCH},  //! Source and destination of a cross-domain move do not agree on the object's current name. Either source or destination does not have the latest version of the object.
		ErrorCodeName{"ERROR_DS_SRC_AND_DST_NC_IDENTICAL", ERROR_DS_SRC_AND_DST_NC_IDENTICAL},  //! Source and destination for the cross-domain move operation are identical. Caller should use local move operation instead of cross-domain move operation.
		ErrorCodeName{"ERROR_DS_DST_NC_MISMATCH", ERROR_DS_DST_NC_MISMATCH},  //! Source and destination for a cross-domain move are not in agreement on the naming contexts in the forest. Either source or destination does not have the latest version of the Partitions container.
		ErrorCodeName{"ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC", ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC},  //! Destination of a cross-domain move is not authoritative for the destination naming context.
		ErrorCodeName{"ERROR_DS_SRC_GUID_MISMATCH", ERROR_DS_SRC_GUID_MISMATCH},  //! Source and destination of a cross-domain move do not agree on the identity of the source object. Either source or destination does not have the latest version of the source object.
		ErrorCodeName{"ERROR_DS_CANT_MOVE_DELETED_OBJECT", ERROR_DS_CANT_MOVE_DELETED_OBJECT},  //! Object being moved across-domains is already known to be deleted by the destination server. The source server does not have the latest version of the source object.
		ErrorCodeName{"ERROR_DS_PDC_OPERATION_IN_PROGRESS", ERROR_DS_PDC_OPERATION_IN_PROGRESS},  //! Another operation which requires exclusive access to the PDC FSMO is already in progress.
		ErrorCodeName{"ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD", ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD},  //! A cross-domain move operation failed such that two versions of the moved object exist - one each in the source and destination domains. The destination object needs to be removed to restore the system to a consistent state.
		ErrorCodeName{"ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION", ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION},  //! This object may not be moved across domain boundaries either because cross-domain moves for this class are disallowed, or the object has some special characteristics, e.g.: trust account or restricted RID, which prevent its move.
		ErrorCodeName{"ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS", ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS},  //! Can't move objects with memberships across domain boundaries as once moved, this would violate the membership conditions of the account group. Remove the object from any account group memberships and retry.
		ErrorCodeName{"ERROR_DS_NC_MUST_HAVE_NC_PARENT", ERROR_DS_NC_MUST_HAVE_NC_PARENT},  //! A naming context head must be the immediate child of another naming context head, not of an interior node.
		ErrorCodeName{"ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE", ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE},  //! The directory cannot validate the proposed naming context name because it does not hold a replica of the naming context above the proposed naming context. Please ensure that the domain naming master role is held by a server that is configured as a global catalog server, and that the server is up to date with its replication partners. (Applies only to Windows 2000 Domain Naming masters.)
		ErrorCodeName{"ERROR_DS_DST_DOMAIN_NOT_NATIVE", ERROR_DS_DST_DOMAIN_NOT_NATIVE},  //! Destination domain must be in native mode.
		ErrorCodeName{"ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER", ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER},  //! The operation cannot be performed because the server does not have an infrastructure container in the domain of interest.
		ErrorCodeName{"ERROR_DS_CANT_MOVE_ACCOUNT_GROUP", ERROR_DS_CANT_MOVE_ACCOUNT_GROUP},  //! Cross-domain move of non-empty account groups is not allowed.
		ErrorCodeName{"ERROR_DS_CANT_MOVE_RESOURCE_GROUP", ERROR_DS_CANT_MOVE_RESOURCE_GROUP},  //! Cross-domain move of non-empty resource groups is not allowed.
		ErrorCodeName{"ERROR_DS_INVALID_SEARCH_FLAG", ERROR_DS_INVALID_SEARCH_FLAG},  //! The search flags for the attribute are invalid. The ANR bit is valid only on attributes of Unicode or Teletex strings.
		ErrorCodeName{"ERROR_DS_NO_TREE_DELETE_ABOVE_NC", ERROR_DS_NO_TREE_DELETE_ABOVE_NC},  //! Tree deletions starting at an object which has an NC head as a descendant are not allowed.
		ErrorCodeName{"ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE", ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE},  //! The directory service failed to lock a tree in preparation for a tree deletion because the tree was in use.
		ErrorCodeName{"ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE", ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE},  //! The directory service failed to identify the list of objects to delete while attempting a tree deletion.
		ErrorCodeName{"ERROR_DS_SAM_INIT_FAILURE", ERROR_DS_SAM_INIT_FAILURE},  //! Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Please shutdown this system and reboot into Directory Services Restore Mode, check the event log for more detailed information.
		ErrorCodeName{"ERROR_DS_SENSITIVE_GROUP_VIOLATION", ERROR_DS_SENSITIVE_GROUP_VIOLATION},  //! Only an administrator can modify the membership list of an administrative group.
		ErrorCodeName{"ERROR_DS_CANT_MOD_PRIMARYGROUPID", ERROR_DS_CANT_MOD_PRIMARYGROUPID},  //! Cannot change the primary group ID of a domain controller account.
		ErrorCodeName{"ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD", ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD},  //! An attempt is made to modify the base schema.
		ErrorCodeName{"ERROR_DS_NONSAFE_SCHEMA_CHANGE", ERROR_DS_NONSAFE_SCHEMA_CHANGE},  //! Adding a new mandatory attribute to an existing class, deleting a mandatory attribute from an existing class, or adding an optional attribute to the special class Top that is not a backlink attribute (directly or through inheritance, for example, by adding or deleting an auxiliary class) is not allowed.
		ErrorCodeName{"ERROR_DS_SCHEMA_UPDATE_DISALLOWED", ERROR_DS_SCHEMA_UPDATE_DISALLOWED},  //! Schema update is not allowed on this DC because the DC is not the schema FSMO Role Owner.
		ErrorCodeName{"ERROR_DS_CANT_CREATE_UNDER_SCHEMA", ERROR_DS_CANT_CREATE_UNDER_SCHEMA},  //! An object of this class cannot be created under the schema container. You can only create attribute-schema and class-schema objects under the schema container.
		ErrorCodeName{"ERROR_DS_INSTALL_NO_SRC_SCH_VERSION", ERROR_DS_INSTALL_NO_SRC_SCH_VERSION},  //! The replica/child install failed to get the objectVersion attribute on the schema container on the source DC. Either the attribute is missing on the schema container or the credentials supplied do not have permission to read it.
		ErrorCodeName{"ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE", ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE},  //! The replica/child install failed to read the objectVersion attribute in the SCHEMA section of the file schema.ini in the system32 directory.
		ErrorCodeName{"ERROR_DS_INVALID_GROUP_TYPE", ERROR_DS_INVALID_GROUP_TYPE},  //! The specified group type is invalid.
		ErrorCodeName{"ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN", ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN},  //! You cannot nest global groups in a mixed domain if the group is security-enabled.
		ErrorCodeName{"ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN", ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN},  //! You cannot nest local groups in a mixed domain if the group is security-enabled.
		ErrorCodeName{"ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER", ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER},  //! A global group cannot have a local group as a member.
		ErrorCodeName{"ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER", ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER},  //! A global group cannot have a universal group as a member.
		ErrorCodeName{"ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER", ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER},  //! A universal group cannot have a local group as a member.
		ErrorCodeName{"ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER", ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER},  //! A global group cannot have a cross-domain member.
		ErrorCodeName{"ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER", ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER},  //! A local group cannot have another cross domain local group as a member.
		ErrorCodeName{"ERROR_DS_HAVE_PRIMARY_MEMBERS", ERROR_DS_HAVE_PRIMARY_MEMBERS},  //! A group with primary members cannot change to a security-disabled group.
		ErrorCodeName{"ERROR_DS_STRING_SD_CONVERSION_FAILED", ERROR_DS_STRING_SD_CONVERSION_FAILED},  //! The schema cache load failed to convert the string default SD on a class-schema object.
		ErrorCodeName{"ERROR_DS_NAMING_MASTER_GC", ERROR_DS_NAMING_MASTER_GC},  //! Only DSAs configured to be Global Catalog servers should be allowed to hold the Domain Naming Master FSMO role. (Applies only to Windows 2000 servers.)
		ErrorCodeName{"ERROR_DS_DNS_LOOKUP_FAILURE", ERROR_DS_DNS_LOOKUP_FAILURE},  //! The DSA operation is unable to proceed because of a DNS lookup failure.
		ErrorCodeName{"ERROR_DS_COULDNT_UPDATE_SPNS", ERROR_DS_COULDNT_UPDATE_SPNS},  //! While processing a change to the DNS Host Name for an object, the Service Principal Name values could not be kept in sync.
		ErrorCodeName{"ERROR_DS_CANT_RETRIEVE_SD", ERROR_DS_CANT_RETRIEVE_SD},  //! The Security Descriptor attribute could not be read.
		ErrorCodeName{"ERROR_DS_KEY_NOT_UNIQUE", ERROR_DS_KEY_NOT_UNIQUE},  //! The object requested was not found, but an object with that key was found.
		ErrorCodeName{"ERROR_DS_WRONG_LINKED_ATT_SYNTAX", ERROR_DS_WRONG_LINKED_ATT_SYNTAX},  //! The syntax of the linked attribute being added is incorrect. Forward links can only have syntax 2.5.5.1, 2.5.5.7, and 2.5.5.14, and backlinks can only have syntax 2.5.5.1.
		ErrorCodeName{"ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD", ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD},  //! Security Account Manager needs to get the boot password.
		ErrorCodeName{"ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY", ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY},  //! Security Account Manager needs to get the boot key from floppy disk.
		ErrorCodeName{"ERROR_DS_CANT_START", ERROR_DS_CANT_START},  //! Directory Service cannot start.
		ErrorCodeName{"ERROR_DS_INIT_FAILURE", ERROR_DS_INIT_FAILURE},  //! Directory Services could not start.
		ErrorCodeName{"ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION", ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION},  //! The connection between client and server requires packet privacy or better.
		ErrorCodeName{"ERROR_DS_SOURCE_DOMAIN_IN_FOREST", ERROR_DS_SOURCE_DOMAIN_IN_FOREST},  //! The source domain may not be in the same forest as destination.
		ErrorCodeName{"ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST", ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST},  //! The destination domain must be in the forest.
		ErrorCodeName{"ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED", ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED},  //! The operation requires that destination domain auditing be enabled.
		ErrorCodeName{"ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN", ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN},  //! The operation couldn't locate a DC for the source domain.
		ErrorCodeName{"ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER", ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER},  //! The source object must be a group or user.
		ErrorCodeName{"ERROR_DS_SRC_SID_EXISTS_IN_FOREST", ERROR_DS_SRC_SID_EXISTS_IN_FOREST},  //! The source object's SID already exists in destination forest.
		ErrorCodeName{"ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH", ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH},  //! The source and destination object must be of the same type.
		ErrorCodeName{"ERROR_SAM_INIT_FAILURE", ERROR_SAM_INIT_FAILURE},  //! Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Click OK to shut down the system and reboot into Safe Mode. Check the event log for detailed information.
		ErrorCodeName{"ERROR_DS_DRA_SCHEMA_INFO_SHIP", ERROR_DS_DRA_SCHEMA_INFO_SHIP},  //! Schema information could not be included in the replication request.
		ErrorCodeName{"ERROR_DS_DRA_SCHEMA_CONFLICT", ERROR_DS_DRA_SCHEMA_CONFLICT},  //! The replication operation could not be completed due to a schema incompatibility.
		ErrorCodeName{"ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT", ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT},  //! The replication operation could not be completed due to a previous schema incompatibility.
		ErrorCodeName{"ERROR_DS_DRA_OBJ_NC_MISMATCH", ERROR_DS_DRA_OBJ_NC_MISMATCH},  //! The replication update could not be applied because either the source or the destination has not yet received information regarding a recent cross-domain move operation.
		ErrorCodeName{"ERROR_DS_NC_STILL_HAS_DSAS", ERROR_DS_NC_STILL_HAS_DSAS},  //! The requested domain could not be deleted because there exist domain controllers that still host this domain.
		ErrorCodeName{"ERROR_DS_GC_REQUIRED", ERROR_DS_GC_REQUIRED},  //! The requested operation can be performed only on a global catalog server.
		ErrorCodeName{"ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY", ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY},  //! A local group can only be a member of other local groups in the same domain.
		ErrorCodeName{"ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS", ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS},  //! Foreign security principals cannot be members of universal groups.
		ErrorCodeName{"ERROR_DS_CANT_ADD_TO_GC", ERROR_DS_CANT_ADD_TO_GC},  //! The attribute is not allowed to be replicated to the GC because of security reasons.
		ErrorCodeName{"ERROR_DS_NO_CHECKPOINT_WITH_PDC", ERROR_DS_NO_CHECKPOINT_WITH_PDC},  //! The checkpoint with the PDC could not be taken because there too many modifications being processed currently.
		ErrorCodeName{"ERROR_DS_SOURCE_AUDITING_NOT_ENABLED", ERROR_DS_SOURCE_AUDITING_NOT_ENABLED},  //! The operation requires that source domain auditing be enabled.
		ErrorCodeName{"ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC", ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC},  //! Security principal objects can only be created inside domain naming contexts.
		ErrorCodeName{"ERROR_DS_INVALID_NAME_FOR_SPN", ERROR_DS_INVALID_NAME_FOR_SPN},  //! A Service Principal Name (SPN) could not be constructed because the provided hostname is not in the necessary format.
		ErrorCodeName{"ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS", ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS},  //! A Filter was passed that uses constructed attributes.
		ErrorCodeName{"ERROR_DS_UNICODEPWD_NOT_IN_QUOTES", ERROR_DS_UNICODEPWD_NOT_IN_QUOTES},  //! The unicodePwd attribute value must be enclosed in double quotes.
		ErrorCodeName{"ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED", ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED},  //! Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased.
		ErrorCodeName{"ERROR_DS_MUST_BE_RUN_ON_DST_DC", ERROR_DS_MUST_BE_RUN_ON_DST_DC},  //! For security reasons, the operation must be run on the destination DC.
		ErrorCodeName{"ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER", ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER},  //! For security reasons, the source DC must be NT4SP4 or greater.
		ErrorCodeName{"ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ", ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ},  //! Critical Directory Service System objects cannot be deleted during tree delete operations. The tree delete may have been partially performed.
		ErrorCodeName{"ERROR_DS_INIT_FAILURE_CONSOLE", ERROR_DS_INIT_FAILURE_CONSOLE},  //! Directory Services could not start because of the following error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
		ErrorCodeName{"ERROR_DS_SAM_INIT_FAILURE_CONSOLE", ERROR_DS_SAM_INIT_FAILURE_CONSOLE},  //! Security Accounts Manager initialization failed because of the following error: %1. Error Status: 0x%2. Please click OK to shutdown the system. You can use the recovery console to diagnose the system further.
		ErrorCodeName{"ERROR_DS_FOREST_VERSION_TOO_HIGH", ERROR_DS_FOREST_VERSION_TOO_HIGH},  //! The version of the operating system is incompatible with the current AD DS forest functional level or AD LDS Configuration Set functional level. You must upgrade to a new version of the operating system before this server can become an AD DS Domain Controller or add an AD LDS Instance in this AD DS Forest or AD LDS Configuration Set.
		ErrorCodeName{"ERROR_DS_DOMAIN_VERSION_TOO_HIGH", ERROR_DS_DOMAIN_VERSION_TOO_HIGH},  //! The version of the operating system installed is incompatible with the current domain functional level. You must upgrade to a new version of the operating system before this server can become a domain controller in this domain.
		ErrorCodeName{"ERROR_DS_FOREST_VERSION_TOO_LOW", ERROR_DS_FOREST_VERSION_TOO_LOW},  //! The version of the operating system installed on this server no longer supports the current AD DS Forest functional level or AD LDS Configuration Set functional level. You must raise the AD DS Forest functional level or AD LDS Configuration Set functional level before this server can become an AD DS Domain Controller or an AD LDS Instance in this Forest or Configuration Set.
		ErrorCodeName{"ERROR_DS_DOMAIN_VERSION_TOO_LOW", ERROR_DS_DOMAIN_VERSION_TOO_LOW},  //! The version of the operating system installed on this server no longer supports the current domain functional level. You must raise the domain functional level before this server can become a domain controller in this domain.
		ErrorCodeName{"ERROR_DS_INCOMPATIBLE_VERSION", ERROR_DS_INCOMPATIBLE_VERSION},  //! The version of the operating system installed on this server is incompatible with the functional level of the domain or forest.
		ErrorCodeName{"ERROR_DS_LOW_DSA_VERSION", ERROR_DS_LOW_DSA_VERSION},  //! The functional level of the domain (or forest) cannot be raised to the requested value, because there exist one or more domain controllers in the domain (or forest) that are at a lower incompatible functional level.
		ErrorCodeName{"ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN", ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN},  //! The forest functional level cannot be raised to the requested value since one or more domains are still in mixed domain mode. All domains in the forest must be in native mode, for you to raise the forest functional level.
		ErrorCodeName{"ERROR_DS_NOT_SUPPORTED_SORT_ORDER", ERROR_DS_NOT_SUPPORTED_SORT_ORDER},  //! The sort order requested is not supported.
		ErrorCodeName{"ERROR_DS_NAME_NOT_UNIQUE", ERROR_DS_NAME_NOT_UNIQUE},  //! The requested name already exists as a unique identifier.
		ErrorCodeName{"ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4", ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4},  //! The machine account was created pre-NT4. The account needs to be recreated.
		ErrorCodeName{"ERROR_DS_OUT_OF_VERSION_STORE", ERROR_DS_OUT_OF_VERSION_STORE},  //! The database is out of version store.
		ErrorCodeName{"ERROR_DS_INCOMPATIBLE_CONTROLS_USED", ERROR_DS_INCOMPATIBLE_CONTROLS_USED},  //! Unable to continue operation because multiple conflicting controls were used.
		ErrorCodeName{"ERROR_DS_NO_REF_DOMAIN", ERROR_DS_NO_REF_DOMAIN},  //! Unable to find a valid security descriptor reference domain for this partition.
		ErrorCodeName{"ERROR_DS_RESERVED_LINK_ID", ERROR_DS_RESERVED_LINK_ID},  //! Schema update failed: The link identifier is reserved.
		ErrorCodeName{"ERROR_DS_LINK_ID_NOT_AVAILABLE", ERROR_DS_LINK_ID_NOT_AVAILABLE},  //! Schema update failed: There are no link identifiers available.
		ErrorCodeName{"ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER", ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER},  //! An account group cannot have a universal group as a member.
		ErrorCodeName{"ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE", ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE},  //! Rename or move operations on naming context heads or read-only objects are not allowed.
		ErrorCodeName{"ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC", ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC},  //! Move operations on objects in the schema naming context are not allowed.
		ErrorCodeName{"ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG", ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG},  //! A system flag has been set on the object and does not allow the object to be moved or renamed.
		ErrorCodeName{"ERROR_DS_MODIFYDN_WRONG_GRANDPARENT", ERROR_DS_MODIFYDN_WRONG_GRANDPARENT},  //! This object is not allowed to change its grandparent container. Moves are not forbidden on this object, but are restricted to sibling containers.
		ErrorCodeName{"ERROR_DS_NAME_ERROR_TRUST_REFERRAL", ERROR_DS_NAME_ERROR_TRUST_REFERRAL},  //! Unable to resolve completely, a referral to another forest is generated.
		ErrorCodeName{"ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER", ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER},  //! The requested action is not supported on standard server.
		ErrorCodeName{"ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD", ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD},  //! Could not access a partition of the directory service located on a remote server. Make sure at least one server is running for the partition in question.
		ErrorCodeName{"ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2", ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2},  //! The directory cannot validate the proposed naming context (or partition) name because it does not hold a replica nor can it contact a replica of the naming context above the proposed naming context. Please ensure that the parent naming context is properly registered in DNS, and at least one replica of this naming context is reachable by the Domain Naming master.
		ErrorCodeName{"ERROR_DS_THREAD_LIMIT_EXCEEDED", ERROR_DS_THREAD_LIMIT_EXCEEDED},  //! The thread limit for this request was exceeded.
		ErrorCodeName{"ERROR_DS_NOT_CLOSEST", ERROR_DS_NOT_CLOSEST},  //! The Global catalog server is not in the closest site.
		ErrorCodeName{"ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF", ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF},  //! The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the corresponding server object in the local DS database has no serverReference attribute.
		ErrorCodeName{"ERROR_DS_SINGLE_USER_MODE_FAILED", ERROR_DS_SINGLE_USER_MODE_FAILED},  //! The Directory Service failed to enter single user mode.
		ErrorCodeName{"ERROR_DS_NTDSCRIPT_SYNTAX_ERROR", ERROR_DS_NTDSCRIPT_SYNTAX_ERROR},  //! The Directory Service cannot parse the script because of a syntax error.
		ErrorCodeName{"ERROR_DS_NTDSCRIPT_PROCESS_ERROR", ERROR_DS_NTDSCRIPT_PROCESS_ERROR},  //! The Directory Service cannot process the script because of an error.
		ErrorCodeName{"ERROR_DS_DIFFERENT_REPL_EPOCHS", ERROR_DS_DIFFERENT_REPL_EPOCHS},  //! The directory service cannot perform the requested operation because the servers involved are of different replication epochs (which is usually related to a domain rename that is in progress).
		ErrorCodeName{"ERROR_DS_DRS_EXTENSIONS_CHANGED", ERROR_DS_DRS_EXTENSIONS_CHANGED},  //! The directory service binding must be renegotiated due to a change in the server extensions information.
		ErrorCodeName{"ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR", ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR},  //! Operation not allowed on a disabled cross ref.
		ErrorCodeName{"ERROR_DS_NO_MSDS_INTID", ERROR_DS_NO_MSDS_INTID},  //! Schema update failed: No values for msDS-IntId are available.
		ErrorCodeName{"ERROR_DS_DUP_MSDS_INTID", ERROR_DS_DUP_MSDS_INTID},  //! Schema update failed: Duplicate msDS-INtId. Retry the operation.
		ErrorCodeName{"ERROR_DS_EXISTS_IN_RDNATTID", ERROR_DS_EXISTS_IN_RDNATTID},  //! Schema deletion failed: attribute is used in rDNAttID.
		ErrorCodeName{"ERROR_DS_AUTHORIZATION_FAILED", ERROR_DS_AUTHORIZATION_FAILED},  //! The directory service failed to authorize the request.
		ErrorCodeName{"ERROR_DS_INVALID_SCRIPT", ERROR_DS_INVALID_SCRIPT},  //! The Directory Service cannot process the script because it is invalid.
		ErrorCodeName{"ERROR_DS_REMOTE_CROSSREF_OP_FAILED", ERROR_DS_REMOTE_CROSSREF_OP_FAILED},  //! The remote create cross reference operation failed on the Domain Naming Master FSMO. The operation's error is in the extended data.
		ErrorCodeName{"ERROR_DS_CROSS_REF_BUSY", ERROR_DS_CROSS_REF_BUSY},  //! A cross reference is in use locally with the same name.
		ErrorCodeName{"ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN", ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN},  //! The DS cannot derive a service principal name (SPN) with which to mutually authenticate the target server because the server's domain has been deleted from the forest.
		ErrorCodeName{"ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC", ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC},  //! Writeable NCs prevent this DC from demoting.
		ErrorCodeName{"ERROR_DS_DUPLICATE_ID_FOUND", ERROR_DS_DUPLICATE_ID_FOUND},  //! The requested object has a non-unique identifier and cannot be retrieved.
		ErrorCodeName{"ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT", ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT},  //! Insufficient attributes were given to create an object. This object may not exist because it may have been deleted and already garbage collected.
		ErrorCodeName{"ERROR_DS_GROUP_CONVERSION_ERROR", ERROR_DS_GROUP_CONVERSION_ERROR},  //! The group cannot be converted due to attribute restrictions on the requested group type.
		ErrorCodeName{"ERROR_DS_CANT_MOVE_APP_BASIC_GROUP", ERROR_DS_CANT_MOVE_APP_BASIC_GROUP},  //! Cross-domain move of non-empty basic application groups is not allowed.
		ErrorCodeName{"ERROR_DS_CANT_MOVE_APP_QUERY_GROUP", ERROR_DS_CANT_MOVE_APP_QUERY_GROUP},  //! Cross-domain move of non-empty query based application groups is not allowed.
		ErrorCodeName{"ERROR_DS_ROLE_NOT_VERIFIED", ERROR_DS_ROLE_NOT_VERIFIED},  //! The FSMO role ownership could not be verified because its directory partition has not replicated successfully with at least one replication partner.
		ErrorCodeName{"ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL", ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL},  //! The target container for a redirection of a well known object container cannot already be a special container.
		ErrorCodeName{"ERROR_DS_DOMAIN_RENAME_IN_PROGRESS", ERROR_DS_DOMAIN_RENAME_IN_PROGRESS},  //! The Directory Service cannot perform the requested operation because a domain rename operation is in progress.
		ErrorCodeName{"ERROR_DS_EXISTING_AD_CHILD_NC", ERROR_DS_EXISTING_AD_CHILD_NC},  //! The directory service detected a child partition below the requested partition name. The partition hierarchy must be created in a top down method.
		ErrorCodeName{"ERROR_DS_REPL_LIFETIME_EXCEEDED", ERROR_DS_REPL_LIFETIME_EXCEEDED},  //! The directory service cannot replicate with this server because the time since the last replication with this server has exceeded the tombstone lifetime.
		ErrorCodeName{"ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER", ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER},  //! The requested operation is not allowed on an object under the system container.
		ErrorCodeName{"ERROR_DS_LDAP_SEND_QUEUE_FULL", ERROR_DS_LDAP_SEND_QUEUE_FULL},  //! The LDAP servers network send queue has filled up because the client is not processing the results of its requests fast enough. No more requests will be processed until the client catches up. If the client does not catch up then it will be disconnected.
		ErrorCodeName{"ERROR_DS_DRA_OUT_SCHEDULE_WINDOW", ERROR_DS_DRA_OUT_SCHEDULE_WINDOW},  //! The scheduled replication did not take place because the system was too busy to execute the request within the schedule window. The replication queue is overloaded. Consider reducing the number of partners or decreasing the scheduled replication frequency.
		ErrorCodeName{"ERROR_DS_POLICY_NOT_KNOWN", ERROR_DS_POLICY_NOT_KNOWN},  //! At this time, it cannot be determined if the branch replication policy is available on the hub domain controller. Please retry at a later time to account for replication latencies.
		ErrorCodeName{"ERROR_NO_SITE_SETTINGS_OBJECT", ERROR_NO_SITE_SETTINGS_OBJECT},  //! The site settings object for the specified site does not exist.
		ErrorCodeName{"ERROR_NO_SECRETS", ERROR_NO_SECRETS},  //! The local account store does not contain secret material for the specified account.
		ErrorCodeName{"ERROR_NO_WRITABLE_DC_FOUND", ERROR_NO_WRITABLE_DC_FOUND},  //! Could not find a writable domain controller in the domain.
		ErrorCodeName{"ERROR_DS_NO_SERVER_OBJECT", ERROR_DS_NO_SERVER_OBJECT},  //! The server object for the domain controller does not exist.
		ErrorCodeName{"ERROR_DS_NO_NTDSA_OBJECT", ERROR_DS_NO_NTDSA_OBJECT},  //! The NTDS Settings object for the domain controller does not exist.
		ErrorCodeName{"ERROR_DS_NON_ASQ_SEARCH", ERROR_DS_NON_ASQ_SEARCH},  //! The requested search operation is not supported for ASQ searches.
		ErrorCodeName{"ERROR_DS_AUDIT_FAILURE", ERROR_DS_AUDIT_FAILURE},  //! A required audit event could not be generated for the operation.
		ErrorCodeName{"ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE", ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE},  //! The search flags for the attribute are invalid. The subtree index bit is valid only on single valued attributes.
		ErrorCodeName{"ERROR_DS_INVALID_SEARCH_FLAG_TUPLE", ERROR_DS_INVALID_SEARCH_FLAG_TUPLE},  //! The search flags for the attribute are invalid. The tuple index bit is valid only on attributes of Unicode strings.
		ErrorCodeName{"ERROR_DS_HIERARCHY_TABLE_TOO_DEEP", ERROR_DS_HIERARCHY_TABLE_TOO_DEEP},  //! The address books are nested too deeply. Failed to build the hierarchy table.
		ErrorCodeName{"ERROR_DS_DRA_CORRUPT_UTD_VECTOR", ERROR_DS_DRA_CORRUPT_UTD_VECTOR},  //! The specified up-to-date-ness vector is corrupt.
		ErrorCodeName{"ERROR_DS_DRA_SECRETS_DENIED", ERROR_DS_DRA_SECRETS_DENIED},  //! The request to replicate secrets is denied.
		ErrorCodeName{"ERROR_DS_RESERVED_MAPI_ID", ERROR_DS_RESERVED_MAPI_ID},  //! Schema update failed: The MAPI identifier is reserved.
		ErrorCodeName{"ERROR_DS_MAPI_ID_NOT_AVAILABLE", ERROR_DS_MAPI_ID_NOT_AVAILABLE},  //! Schema update failed: There are no MAPI identifiers available.
		ErrorCodeName{"ERROR_DS_DRA_MISSING_KRBTGT_SECRET", ERROR_DS_DRA_MISSING_KRBTGT_SECRET},  //! The replication operation failed because the required attributes of the local krbtgt object are missing.
		ErrorCodeName{"ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST", ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST},  //! The domain name of the trusted domain already exists in the forest.
		ErrorCodeName{"ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST", ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST},  //! The flat name of the trusted domain already exists in the forest.
		ErrorCodeName{"ERROR_INVALID_USER_PRINCIPAL_NAME", ERROR_INVALID_USER_PRINCIPAL_NAME},  //! The User Principal Name (UPN) is invalid.
		ErrorCodeName{"ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS", ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS},  //! OID mapped groups cannot have members.
		ErrorCodeName{"ERROR_DS_OID_NOT_FOUND", ERROR_DS_OID_NOT_FOUND},  //! The specified OID cannot be found.
		ErrorCodeName{"ERROR_DS_DRA_RECYCLED_TARGET", ERROR_DS_DRA_RECYCLED_TARGET},  //! The replication operation failed because the target object referred by a link value is recycled.
		ErrorCodeName{"ERROR_DS_DISALLOWED_NC_REDIRECT", ERROR_DS_DISALLOWED_NC_REDIRECT},  //! The redirect operation failed because the target object is in a NC different from the domain NC of the current domain controller.
		ErrorCodeName{"ERROR_DS_HIGH_ADLDS_FFL", ERROR_DS_HIGH_ADLDS_FFL},  //! The functional level of the AD LDS configuration set cannot be lowered to the requested value.
		ErrorCodeName{"ERROR_DS_HIGH_DSA_VERSION", ERROR_DS_HIGH_DSA_VERSION},  //! The functional level of the domain (or forest) cannot be lowered to the requested value.
		ErrorCodeName{"ERROR_DS_LOW_ADLDS_FFL", ERROR_DS_LOW_ADLDS_FFL},  //! The functional level of the AD LDS configuration set cannot be raised to the requested value, because there exist one or more ADLDS instances that are at a lower incompatible functional level.
		ErrorCodeName{"ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION", ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION},  //! The domain join cannot be completed because the SID of the domain you attempted to join was identical to the SID of this machine. This is a symptom of an improperly cloned operating system install. You should run sysprep on this machine in order to generate a new machine SID. Please see https://go.microsoft.com/fwlink/p/?linkid=168895 for more information.
		ErrorCodeName{"ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED", ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED},  //! The undelete operation failed because the Sam Account Name or Additional Sam Account Name of the object being undeleted conflicts with an existing live object.
		ErrorCodeName{"ERROR_INCORRECT_ACCOUNT_TYPE", ERROR_INCORRECT_ACCOUNT_TYPE},  //! The system is not authoritative for the specified account and therefore cannot complete the operation. Please retry the operation using the provider associated with this account. If this is an online provider please use the provider's online site.
		ErrorCodeName{"DNS_ERROR_RCODE_FORMAT_ERROR", DNS_ERROR_RCODE_FORMAT_ERROR},  //! DNS server unable to interpret format.
		ErrorCodeName{"DNS_ERROR_RCODE_SERVER_FAILURE", DNS_ERROR_RCODE_SERVER_FAILURE},  //! DNS server failure.
		ErrorCodeName{"DNS_ERROR_RCODE_NAME_ERROR", DNS_ERROR_RCODE_NAME_ERROR},  //! DNS name does not exist.
		ErrorCodeName{"DNS_ERROR_RCODE_NOT_IMPLEMENTED", DNS_ERROR_RCODE_NOT_IMPLEMENTED},  //! DNS request not supported by name server.
		ErrorCodeName{"DNS_ERROR_RCODE_REFUSED", DNS_ERROR_RCODE_REFUSED},  //! DNS operation refused.
		ErrorCodeName{"DNS_ERROR_RCODE_YXDOMAIN", DNS_ERROR_RCODE_YXDOMAIN},  //! DNS name that ought not exist, does exist.
		ErrorCodeName{"DNS_ERROR_RCODE_YXRRSET", DNS_ERROR_RCODE_YXRRSET},  //! DNS RR set that ought not exist, does exist.
		ErrorCodeName{"DNS_ERROR_RCODE_NXRRSET", DNS_ERROR_RCODE_NXRRSET},  //! DNS RR set that ought to exist, does not exist.
		ErrorCodeName{"DNS_ERROR_RCODE_NOTAUTH", DNS_ERROR_RCODE_NOTAUTH},  //! DNS server not authoritative for zone.
		ErrorCodeName{"DNS_ERROR_RCODE_NOTZONE", DNS_ERROR_RCODE_NOTZONE},  //! DNS name in update or prereq is not in zone.
		ErrorCodeName{"DNS_ERROR_RCODE_BADSIG", DNS_ERROR_RCODE_BADSIG},  //! DNS signature failed to verify.
		ErrorCodeName{"DNS_ERROR_RCODE_BADKEY", DNS_ERROR_RCODE_BADKEY},  //! DNS bad key.
		ErrorCodeName{"DNS_ERROR_RCODE_BADTIME", DNS_ERROR_RCODE_BADTIME},  //! DNS signature validity expired.
		ErrorCodeName{"DNS_ERROR_KEYMASTER_REQUIRED", DNS_ERROR_KEYMASTER_REQUIRED},  //! Only the DNS server acting as the key master for the zone may perform this operation.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE", DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE},  //! This operation is not allowed on a zone that is signed or has signing keys.
		ErrorCodeName{"DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1", DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1},  //! NSEC3 is not compatible with the RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC.
		ErrorCodeName{"DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS", DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS},  //! The zone does not have enough signing keys. There must be at least one key signing key (KSK) and at least one zone signing key (ZSK).
		ErrorCodeName{"DNS_ERROR_UNSUPPORTED_ALGORITHM", DNS_ERROR_UNSUPPORTED_ALGORITHM},  //! The specified algorithm is not supported.
		ErrorCodeName{"DNS_ERROR_INVALID_KEY_SIZE", DNS_ERROR_INVALID_KEY_SIZE},  //! The specified key size is not supported.
		ErrorCodeName{"DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE", DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE},  //! One or more of the signing keys for a zone are not accessible to the DNS server. Zone signing will not be operational until this error is resolved.
		ErrorCodeName{"DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION", DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION},  //! The specified key storage provider does not support DPAPI++ data protection. Zone signing will not be operational until this error is resolved.
		ErrorCodeName{"DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR", DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR},  //! An unexpected DPAPI++ error was encountered. Zone signing will not be operational until this error is resolved.
		ErrorCodeName{"DNS_ERROR_UNEXPECTED_CNG_ERROR", DNS_ERROR_UNEXPECTED_CNG_ERROR},  //! An unexpected crypto error was encountered. Zone signing may not be operational until this error is resolved.
		ErrorCodeName{"DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION", DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION},  //! The DNS server encountered a signing key with an unknown version. Zone signing will not be operational until this error is resolved.
		ErrorCodeName{"DNS_ERROR_KSP_NOT_ACCESSIBLE", DNS_ERROR_KSP_NOT_ACCESSIBLE},  //! The specified key service provider cannot be opened by the DNS server.
		ErrorCodeName{"DNS_ERROR_TOO_MANY_SKDS", DNS_ERROR_TOO_MANY_SKDS},  //! The DNS server cannot accept any more signing keys with the specified algorithm and KSK flag value for this zone.
		ErrorCodeName{"DNS_ERROR_INVALID_ROLLOVER_PERIOD", DNS_ERROR_INVALID_ROLLOVER_PERIOD},  //! The specified rollover period is invalid.
		ErrorCodeName{"DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET", DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET},  //! The specified initial rollover offset is invalid.
		ErrorCodeName{"DNS_ERROR_ROLLOVER_IN_PROGRESS", DNS_ERROR_ROLLOVER_IN_PROGRESS},  //! The specified signing key is already in process of rolling over keys.
		ErrorCodeName{"DNS_ERROR_STANDBY_KEY_NOT_PRESENT", DNS_ERROR_STANDBY_KEY_NOT_PRESENT},  //! The specified signing key does not have a standby key to revoke.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_ON_ZSK", DNS_ERROR_NOT_ALLOWED_ON_ZSK},  //! This operation is not allowed on a zone signing key (ZSK).
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD", DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD},  //! This operation is not allowed on an active signing key.
		ErrorCodeName{"DNS_ERROR_ROLLOVER_ALREADY_QUEUED", DNS_ERROR_ROLLOVER_ALREADY_QUEUED},  //! The specified signing key is already queued for rollover.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE", DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE},  //! This operation is not allowed on an unsigned zone.
		ErrorCodeName{"DNS_ERROR_BAD_KEYMASTER", DNS_ERROR_BAD_KEYMASTER},  //! This operation could not be completed because the DNS server listed as the current key master for this zone is down or misconfigured. Resolve the problem on the current key master for this zone or use another DNS server to seize the key master role.
		ErrorCodeName{"DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD", DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD},  //! The specified signature validity period is invalid.
		ErrorCodeName{"DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT", DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT},  //! The specified NSEC3 iteration count is higher than allowed by the minimum key length used in the zone.
		ErrorCodeName{"DNS_ERROR_DNSSEC_IS_DISABLED", DNS_ERROR_DNSSEC_IS_DISABLED},  //! This operation could not be completed because the DNS server has been configured with DNSSEC features disabled. Enable DNSSEC on the DNS server.
		ErrorCodeName{"DNS_ERROR_INVALID_XML", DNS_ERROR_INVALID_XML},  //! This operation could not be completed because the XML stream received is empty or syntactically invalid.
		ErrorCodeName{"DNS_ERROR_NO_VALID_TRUST_ANCHORS", DNS_ERROR_NO_VALID_TRUST_ANCHORS},  //! This operation completed, but no trust anchors were added because all of the trust anchors received were either invalid, unsupported, expired, or would not become valid in less than 30 days.
		ErrorCodeName{"DNS_ERROR_ROLLOVER_NOT_POKEABLE", DNS_ERROR_ROLLOVER_NOT_POKEABLE},  //! The specified signing key is not waiting for parental DS update.
		ErrorCodeName{"DNS_ERROR_NSEC3_NAME_COLLISION", DNS_ERROR_NSEC3_NAME_COLLISION},  //! Hash collision detected during NSEC3 signing. Specify a different user-provided salt, or use a randomly generated salt, and attempt to sign the zone again.
		ErrorCodeName{"DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1", DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1},  //! NSEC is not compatible with the NSEC3-RSA-SHA-1 algorithm. Choose a different algorithm or use NSEC3.
		ErrorCodeName{"DNS_INFO_NO_RECORDS", DNS_INFO_NO_RECORDS},  //! No records found for given DNS query.
		ErrorCodeName{"DNS_ERROR_BAD_PACKET", DNS_ERROR_BAD_PACKET},  //! Bad DNS packet.
		ErrorCodeName{"DNS_ERROR_NO_PACKET", DNS_ERROR_NO_PACKET},  //! No DNS packet.
		ErrorCodeName{"DNS_ERROR_RCODE", DNS_ERROR_RCODE},  //! DNS error, check rcode.
		ErrorCodeName{"DNS_ERROR_UNSECURE_PACKET", DNS_ERROR_UNSECURE_PACKET},  //! Unsecured DNS packet.
		ErrorCodeName{"DNS_REQUEST_PENDING", DNS_REQUEST_PENDING},  //! DNS query request is pending.
		ErrorCodeName{"DNS_ERROR_INVALID_TYPE", DNS_ERROR_INVALID_TYPE},  //! Invalid DNS type.
		ErrorCodeName{"DNS_ERROR_INVALID_IP_ADDRESS", DNS_ERROR_INVALID_IP_ADDRESS},  //! Invalid IP address.
		ErrorCodeName{"DNS_ERROR_INVALID_PROPERTY", DNS_ERROR_INVALID_PROPERTY},  //! Invalid property.
		ErrorCodeName{"DNS_ERROR_TRY_AGAIN_LATER", DNS_ERROR_TRY_AGAIN_LATER},  //! Try DNS operation again later.
		ErrorCodeName{"DNS_ERROR_NOT_UNIQUE", DNS_ERROR_NOT_UNIQUE},  //! Record for given name and type is not unique.
		ErrorCodeName{"DNS_ERROR_NON_RFC_NAME", DNS_ERROR_NON_RFC_NAME},  //! DNS name does not comply with RFC specifications.
		ErrorCodeName{"DNS_STATUS_FQDN", DNS_STATUS_FQDN},  //! DNS name is a fully-qualified DNS name.
		ErrorCodeName{"DNS_STATUS_DOTTED_NAME", DNS_STATUS_DOTTED_NAME},  //! DNS name is dotted (multi-label).
		ErrorCodeName{"DNS_STATUS_SINGLE_PART_NAME", DNS_STATUS_SINGLE_PART_NAME},  //! DNS name is a single-part name.
		ErrorCodeName{"DNS_ERROR_INVALID_NAME_CHAR", DNS_ERROR_INVALID_NAME_CHAR},  //! DNS name contains an invalid character.
		ErrorCodeName{"DNS_ERROR_NUMERIC_NAME", DNS_ERROR_NUMERIC_NAME},  //! DNS name is entirely numeric.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER", DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER},  //! The operation requested is not permitted on a DNS root server.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION", DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION},  //! The record could not be created because this part of the DNS namespace has been delegated to another server.
		ErrorCodeName{"DNS_ERROR_CANNOT_FIND_ROOT_HINTS", DNS_ERROR_CANNOT_FIND_ROOT_HINTS},  //! The DNS server could not find a set of root hints.
		ErrorCodeName{"DNS_ERROR_INCONSISTENT_ROOT_HINTS", DNS_ERROR_INCONSISTENT_ROOT_HINTS},  //! The DNS server found root hints but they were not consistent across all adapters.
		ErrorCodeName{"DNS_ERROR_DWORD_VALUE_TOO_SMALL", DNS_ERROR_DWORD_VALUE_TOO_SMALL},  //! The specified value is too small for this parameter.
		ErrorCodeName{"DNS_ERROR_DWORD_VALUE_TOO_LARGE", DNS_ERROR_DWORD_VALUE_TOO_LARGE},  //! The specified value is too large for this parameter.
		ErrorCodeName{"DNS_ERROR_BACKGROUND_LOADING", DNS_ERROR_BACKGROUND_LOADING},  //! This operation is not allowed while the DNS server is loading zones in the background. Please try again later.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_ON_RODC", DNS_ERROR_NOT_ALLOWED_ON_RODC},  //! The operation requested is not permitted on against a DNS server running on a read-only DC.
		ErrorCodeName{"DNS_ERROR_NOT_ALLOWED_UNDER_DNAME", DNS_ERROR_NOT_ALLOWED_UNDER_DNAME},  //! No data is allowed to exist underneath a DNAME record.
		ErrorCodeName{"DNS_ERROR_DELEGATION_REQUIRED", DNS_ERROR_DELEGATION_REQUIRED},  //! This operation requires credentials delegation.
		ErrorCodeName{"DNS_ERROR_INVALID_POLICY_TABLE", DNS_ERROR_INVALID_POLICY_TABLE},  //! Name resolution policy table has been corrupted. DNS resolution will fail until it is fixed. Contact your network administrator.
		ErrorCodeName{"DNS_ERROR_ZONE_DOES_NOT_EXIST", DNS_ERROR_ZONE_DOES_NOT_EXIST},  //! DNS zone does not exist.
		ErrorCodeName{"DNS_ERROR_NO_ZONE_INFO", DNS_ERROR_NO_ZONE_INFO},  //! DNS zone information not available.
		ErrorCodeName{"DNS_ERROR_INVALID_ZONE_OPERATION", DNS_ERROR_INVALID_ZONE_OPERATION},  //! Invalid operation for DNS zone.
		ErrorCodeName{"DNS_ERROR_ZONE_CONFIGURATION_ERROR", DNS_ERROR_ZONE_CONFIGURATION_ERROR},  //! Invalid DNS zone configuration.
		ErrorCodeName{"DNS_ERROR_ZONE_HAS_NO_SOA_RECORD", DNS_ERROR_ZONE_HAS_NO_SOA_RECORD},  //! DNS zone has no start of authority (SOA) record.
		ErrorCodeName{"DNS_ERROR_ZONE_HAS_NO_NS_RECORDS", DNS_ERROR_ZONE_HAS_NO_NS_RECORDS},  //! DNS zone has no Name Server (NS) record.
		ErrorCodeName{"DNS_ERROR_ZONE_LOCKED", DNS_ERROR_ZONE_LOCKED},  //! DNS zone is locked.
		ErrorCodeName{"DNS_ERROR_ZONE_CREATION_FAILED", DNS_ERROR_ZONE_CREATION_FAILED},  //! DNS zone creation failed.
		ErrorCodeName{"DNS_ERROR_ZONE_ALREADY_EXISTS", DNS_ERROR_ZONE_ALREADY_EXISTS},  //! DNS zone already exists.
		ErrorCodeName{"DNS_ERROR_AUTOZONE_ALREADY_EXISTS", DNS_ERROR_AUTOZONE_ALREADY_EXISTS},  //! DNS automatic zone already exists.
		ErrorCodeName{"DNS_ERROR_INVALID_ZONE_TYPE", DNS_ERROR_INVALID_ZONE_TYPE},  //! Invalid DNS zone type.
		ErrorCodeName{"DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP", DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP},  //! Secondary DNS zone requires master IP address.
		ErrorCodeName{"DNS_ERROR_ZONE_NOT_SECONDARY", DNS_ERROR_ZONE_NOT_SECONDARY},  //! DNS zone not secondary.
		ErrorCodeName{"DNS_ERROR_NEED_SECONDARY_ADDRESSES", DNS_ERROR_NEED_SECONDARY_ADDRESSES},  //! Need secondary IP address.
		ErrorCodeName{"DNS_ERROR_WINS_INIT_FAILED", DNS_ERROR_WINS_INIT_FAILED},  //! WINS initialization failed.
		ErrorCodeName{"DNS_ERROR_NEED_WINS_SERVERS", DNS_ERROR_NEED_WINS_SERVERS},  //! Need WINS servers.
		ErrorCodeName{"DNS_ERROR_NBSTAT_INIT_FAILED", DNS_ERROR_NBSTAT_INIT_FAILED},  //! NBTSTAT initialization call failed.
		ErrorCodeName{"DNS_ERROR_SOA_DELETE_INVALID", DNS_ERROR_SOA_DELETE_INVALID},  //! Invalid delete of start of authority (SOA).
		ErrorCodeName{"DNS_ERROR_FORWARDER_ALREADY_EXISTS", DNS_ERROR_FORWARDER_ALREADY_EXISTS},  //! A conditional forwarding zone already exists for that name.
		ErrorCodeName{"DNS_ERROR_ZONE_REQUIRES_MASTER_IP", DNS_ERROR_ZONE_REQUIRES_MASTER_IP},  //! This zone must be configured with one or more master DNS server IP addresses.
		ErrorCodeName{"DNS_ERROR_ZONE_IS_SHUTDOWN", DNS_ERROR_ZONE_IS_SHUTDOWN},  //! The operation cannot be performed because this zone is shut down.
		ErrorCodeName{"DNS_ERROR_ZONE_LOCKED_FOR_SIGNING", DNS_ERROR_ZONE_LOCKED_FOR_SIGNING},  //! This operation cannot be performed because the zone is currently being signed. Please try again later.
		ErrorCodeName{"DNS_ERROR_PRIMARY_REQUIRES_DATAFILE", DNS_ERROR_PRIMARY_REQUIRES_DATAFILE},  //! Primary DNS zone requires datafile.
		ErrorCodeName{"DNS_ERROR_INVALID_DATAFILE_NAME", DNS_ERROR_INVALID_DATAFILE_NAME},  //! Invalid datafile name for DNS zone.
		ErrorCodeName{"DNS_ERROR_DATAFILE_OPEN_FAILURE", DNS_ERROR_DATAFILE_OPEN_FAILURE},  //! Failed to open datafile for DNS zone.
		ErrorCodeName{"DNS_ERROR_FILE_WRITEBACK_FAILED", DNS_ERROR_FILE_WRITEBACK_FAILED},  //! Failed to write datafile for DNS zone.
		ErrorCodeName{"DNS_ERROR_DATAFILE_PARSING", DNS_ERROR_DATAFILE_PARSING},  //! Failure while reading datafile for DNS zone.
		ErrorCodeName{"DNS_ERROR_RECORD_DOES_NOT_EXIST", DNS_ERROR_RECORD_DOES_NOT_EXIST},  //! DNS record does not exist.
		ErrorCodeName{"DNS_ERROR_RECORD_FORMAT", DNS_ERROR_RECORD_FORMAT},  //! DNS record format error.
		ErrorCodeName{"DNS_ERROR_NODE_CREATION_FAILED", DNS_ERROR_NODE_CREATION_FAILED},  //! Node creation failure in DNS.
		ErrorCodeName{"DNS_ERROR_UNKNOWN_RECORD_TYPE", DNS_ERROR_UNKNOWN_RECORD_TYPE},  //! Unknown DNS record type.
		ErrorCodeName{"DNS_ERROR_RECORD_TIMED_OUT", DNS_ERROR_RECORD_TIMED_OUT},  //! DNS record timed out.
		ErrorCodeName{"DNS_ERROR_NAME_NOT_IN_ZONE", DNS_ERROR_NAME_NOT_IN_ZONE},  //! Name not in DNS zone.
		ErrorCodeName{"DNS_ERROR_CNAME_LOOP", DNS_ERROR_CNAME_LOOP},  //! CNAME loop detected.
		ErrorCodeName{"DNS_ERROR_NODE_IS_CNAME", DNS_ERROR_NODE_IS_CNAME},  //! Node is a CNAME DNS record.
		ErrorCodeName{"DNS_ERROR_CNAME_COLLISION", DNS_ERROR_CNAME_COLLISION},  //! A CNAME record already exists for given name.
		ErrorCodeName{"DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT", DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT},  //! Record only at DNS zone root.
		ErrorCodeName{"DNS_ERROR_RECORD_ALREADY_EXISTS", DNS_ERROR_RECORD_ALREADY_EXISTS},  //! DNS record already exists.
		ErrorCodeName{"DNS_ERROR_SECONDARY_DATA", DNS_ERROR_SECONDARY_DATA},  //! Secondary DNS zone data error.
		ErrorCodeName{"DNS_ERROR_NO_CREATE_CACHE_DATA", DNS_ERROR_NO_CREATE_CACHE_DATA},  //! Could not create DNS cache data.
		ErrorCodeName{"DNS_ERROR_NAME_DOES_NOT_EXIST", DNS_ERROR_NAME_DOES_NOT_EXIST},  //! DNS name does not exist.
		ErrorCodeName{"DNS_WARNING_PTR_CREATE_FAILED", DNS_WARNING_PTR_CREATE_FAILED},  //! Could not create pointer (PTR) record.
		ErrorCodeName{"DNS_WARNING_DOMAIN_UNDELETED", DNS_WARNING_DOMAIN_UNDELETED},  //! DNS domain was undeleted.
		ErrorCodeName{"DNS_ERROR_DS_UNAVAILABLE", DNS_ERROR_DS_UNAVAILABLE},  //! The directory service is unavailable.
		ErrorCodeName{"DNS_ERROR_DS_ZONE_ALREADY_EXISTS", DNS_ERROR_DS_ZONE_ALREADY_EXISTS},  //! DNS zone already exists in the directory service.
		ErrorCodeName{"DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE", DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE},  //! DNS server not creating or reading the boot file for the directory service integrated DNS zone.
		ErrorCodeName{"DNS_ERROR_NODE_IS_DNAME", DNS_ERROR_NODE_IS_DNAME},  //! Node is a DNAME DNS record.
		ErrorCodeName{"DNS_ERROR_DNAME_COLLISION", DNS_ERROR_DNAME_COLLISION},  //! A DNAME record already exists for given name.
		ErrorCodeName{"DNS_ERROR_ALIAS_LOOP", DNS_ERROR_ALIAS_LOOP},  //! An alias loop has been detected with either CNAME or DNAME records.
		ErrorCodeName{"DNS_INFO_AXFR_COMPLETE", DNS_INFO_AXFR_COMPLETE},  //! DNS AXFR (zone transfer) complete.
		ErrorCodeName{"DNS_ERROR_AXFR", DNS_ERROR_AXFR},  //! DNS zone transfer failed.
		ErrorCodeName{"DNS_INFO_ADDED_LOCAL_WINS", DNS_INFO_ADDED_LOCAL_WINS},  //! Added local WINS server.
		ErrorCodeName{"DNS_STATUS_CONTINUE_NEEDED", DNS_STATUS_CONTINUE_NEEDED},  //! Secure update call needs to continue update request.
		ErrorCodeName{"DNS_ERROR_NO_TCPIP", DNS_ERROR_NO_TCPIP},  //! TCP/IP network protocol not installed.
		ErrorCodeName{"DNS_ERROR_NO_DNS_SERVERS", DNS_ERROR_NO_DNS_SERVERS},  //! No DNS servers configured for local system.
		ErrorCodeName{"DNS_ERROR_DP_DOES_NOT_EXIST", DNS_ERROR_DP_DOES_NOT_EXIST},  //! The specified directory partition does not exist.
		ErrorCodeName{"DNS_ERROR_DP_ALREADY_EXISTS", DNS_ERROR_DP_ALREADY_EXISTS},  //! The specified directory partition already exists.
		ErrorCodeName{"DNS_ERROR_DP_NOT_ENLISTED", DNS_ERROR_DP_NOT_ENLISTED},  //! This DNS server is not enlisted in the specified directory partition.
		ErrorCodeName{"DNS_ERROR_DP_ALREADY_ENLISTED", DNS_ERROR_DP_ALREADY_ENLISTED},  //! This DNS server is already enlisted in the specified directory partition.
		ErrorCodeName{"DNS_ERROR_DP_NOT_AVAILABLE", DNS_ERROR_DP_NOT_AVAILABLE},  //! The directory partition is not available at this time. Please wait a few minutes and try again.
		ErrorCodeName{"DNS_ERROR_DP_FSMO_ERROR", DNS_ERROR_DP_FSMO_ERROR},  //! The operation failed because the domain naming master FSMO role could not be reached. The domain controller holding the domain naming master FSMO role is down or unable to service the request or is not running Windows Server 2003 or later.
		ErrorCodeName{"WSAEINTR", WSAEINTR},  //! A blocking operation was interrupted by a call to WSACancelBlockingCall.
		ErrorCodeName{"WSAEBADF", WSAEBADF},  //! The file handle supplied is not valid.
		ErrorCodeName{"WSAEACCES", WSAEACCES},  //! An attempt was made to access a socket in a way forbidden by its access permissions.
		ErrorCodeName{"WSAEFAULT", WSAEFAULT},  //! The system detected an invalid pointer address in attempting to use a pointer argument in a call.
		ErrorCodeName{"WSAEINVAL", WSAEINVAL},  //! An invalid argument was supplied.
		ErrorCodeName{"WSAEMFILE", WSAEMFILE},  //! Too many open sockets.
		ErrorCodeName{"WSAEWOULDBLOCK", WSAEWOULDBLOCK},  //! A non-blocking socket operation could not be completed immediately.
		ErrorCodeName{"WSAEINPROGRESS", WSAEINPROGRESS},  //! A blocking operation is currently executing.
		ErrorCodeName{"WSAEALREADY", WSAEALREADY},  //! An operation was attempted on a non-blocking socket that already had an operation in progress.
		ErrorCodeName{"WSAENOTSOCK", WSAENOTSOCK},  //! An operation was attempted on something that is not a socket.
		ErrorCodeName{"WSAEDESTADDRREQ", WSAEDESTADDRREQ},  //! A required address was omitted from an operation on a socket.
		ErrorCodeName{"WSAEMSGSIZE", WSAEMSGSIZE},  //! A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram into was smaller than the datagram itself.
		ErrorCodeName{"WSAEPROTOTYPE", WSAEPROTOTYPE},  //! A protocol was specified in the socket function call that does not support the semantics of the socket type requested.
		ErrorCodeName{"WSAENOPROTOOPT", WSAENOPROTOOPT},  //! An unknown, invalid, or unsupported option or level was specified in a getsockopt or setsockopt call.
		ErrorCodeName{"WSAEPROTONOSUPPORT", WSAEPROTONOSUPPORT},  //! The requested protocol has not been configured into the system, or no implementation for it exists.
		ErrorCodeName{"WSAESOCKTNOSUPPORT", WSAESOCKTNOSUPPORT},  //! The support for the specified socket type does not exist in this address family.
		ErrorCodeName{"WSAEOPNOTSUPP", WSAEOPNOTSUPP},  //! The attempted operation is not supported for the type of object referenced.
		ErrorCodeName{"WSAEPFNOSUPPORT", WSAEPFNOSUPPORT},  //! The protocol family has not been configured into the system or no implementation for it exists.
		ErrorCodeName{"WSAEAFNOSUPPORT", WSAEAFNOSUPPORT},  //! An address incompatible with the requested protocol was used.
		ErrorCodeName{"WSAEADDRINUSE", WSAEADDRINUSE},  //! Only one usage of each socket address (protocol/network address/port) is normally permitted.
		ErrorCodeName{"WSAEADDRNOTAVAIL", WSAEADDRNOTAVAIL},  //! The requested address is not valid in its context.
		ErrorCodeName{"WSAENETDOWN", WSAENETDOWN},  //! A socket operation encountered a dead network.
		ErrorCodeName{"WSAENETUNREACH", WSAENETUNREACH},  //! A socket operation was attempted to an unreachable network.
		ErrorCodeName{"WSAENETRESET", WSAENETRESET},  //! The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress.
		ErrorCodeName{"WSAECONNABORTED", WSAECONNABORTED},  //! An established connection was aborted by the software in your host machine.
		ErrorCodeName{"WSAECONNRESET", WSAECONNRESET},  //! An existing connection was forcibly closed by the remote host.
		ErrorCodeName{"WSAENOBUFS", WSAENOBUFS},  //! An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.
		ErrorCodeName{"WSAEISCONN", WSAEISCONN},  //! A connect request was made on an already connected socket.
		ErrorCodeName{"WSAENOTCONN", WSAENOTCONN},  //! A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using a sendto call) no address was supplied.
		ErrorCodeName{"WSAESHUTDOWN", WSAESHUTDOWN},  //! A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call.
		ErrorCodeName{"WSAETOOMANYREFS", WSAETOOMANYREFS},  //! Too many references to some kernel object.
		ErrorCodeName{"WSAETIMEDOUT", WSAETIMEDOUT},  //! A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
		ErrorCodeName{"WSAECONNREFUSED", WSAECONNREFUSED},  //! No connection could be made because the target machine actively refused it.
		ErrorCodeName{"WSAELOOP", WSAELOOP},  //! Cannot translate name.
		ErrorCodeName{"WSAENAMETOOLONG", WSAENAMETOOLONG},  //! Name component or name was too long.
		ErrorCodeName{"WSAEHOSTDOWN", WSAEHOSTDOWN},  //! A socket operation failed because the destination host was down.
		ErrorCodeName{"WSAEHOSTUNREACH", WSAEHOSTUNREACH},  //! A socket operation was attempted to an unreachable host.
		ErrorCodeName{"WSAENOTEMPTY", WSAENOTEMPTY},  //! Cannot remove a directory that is not empty.
		ErrorCodeName{"WSAEPROCLIM", WSAEPROCLIM},  //! A Windows Sockets implementation may have a limit on the number of applications that may use it simultaneously.
		ErrorCodeName{"WSAEUSERS", WSAEUSERS},  //! Ran out of quota.
		ErrorCodeName{"WSAEDQUOT", WSAEDQUOT},  //! Ran out of disk quota.
		ErrorCodeName{"WSAESTALE", WSAESTALE},  //! File handle reference is no longer available.
		ErrorCodeName{"WSAEREMOTE", WSAEREMOTE},  //! Item is not available locally.
		ErrorCodeName{"WSASYSNOTREADY", WSASYSNOTREADY},  //! WSAStartup cannot function at this time because the underlying system it uses to provide network services is currently unavailable.
		ErrorCodeName{"WSAVERNOTSUPPORTED", WSAVERNOTSUPPORTED},  //! The Windows Sockets version requested is not supported.
		ErrorCodeName{"WSANOTINITIALISED", WSANOTINITIALISED},  //! Either the application has not called WSAStartup, or WSAStartup failed.
		ErrorCodeName{"WSAEDISCON", WSAEDISCON},  //! Returned by WSARecv or WSARecvFrom to indicate the remote party has initiated a graceful shutdown sequence.
		ErrorCodeName{"WSAENOMORE", WSAENOMORE},  //! No more results can be returned by WSALookupServiceNext.
		ErrorCodeName{"WSAECANCELLED", WSAECANCELLED},  //! A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
		ErrorCodeName{"WSAEINVALIDPROCTABLE", WSAEINVALIDPROCTABLE},  //! The procedure call table is invalid.
		ErrorCodeName{"WSAEINVALIDPROVIDER", WSAEINVALIDPROVIDER},  //! The requested service provider is invalid.
		ErrorCodeName{"WSAEPROVIDERFAILEDINIT", WSAEPROVIDERFAILEDINIT},  //! The requested service provider could not be loaded or initialized.
		ErrorCodeName{"WSASYSCALLFAILURE", WSASYSCALLFAILURE},  //! A system call has failed.
		ErrorCodeName{"WSASERVICE_NOT_FOUND", WSASERVICE_NOT_FOUND},  //! No such service is known. The service cannot be found in the specified name space.
		ErrorCodeName{"WSATYPE_NOT_FOUND", WSATYPE_NOT_FOUND},  //! The specified class was not found.
		ErrorCodeName{"WSA_E_NO_MORE", WSA_E_NO_MORE},  //! No more results can be returned by WSALookupServiceNext.
		ErrorCodeName{"WSA_E_CANCELLED", WSA_E_CANCELLED},  //! A call to WSALookupServiceEnd was made while this call was still processing. The call has been canceled.
		ErrorCodeName{"WSAEREFUSED", WSAEREFUSED},  //! A database query failed because it was actively refused.
		ErrorCodeName{"WSAHOST_NOT_FOUND", WSAHOST_NOT_FOUND},  //! No such host is known.
		ErrorCodeName{"WSATRY_AGAIN", WSATRY_AGAIN},  //! This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server.
		ErrorCodeName{"WSANO_RECOVERY", WSANO_RECOVERY},  //! A non-recoverable error occurred during a database lookup.
		ErrorCodeName{"WSANO_DATA", WSANO_DATA},  //! The requested name is valid, but no data of the requested type was found.
		ErrorCodeName{"WSA_QOS_RECEIVERS", WSA_QOS_RECEIVERS},  //! At least one reserve has arrived.
		ErrorCodeName{"WSA_QOS_SENDERS", WSA_QOS_SENDERS},  //! At least one path has arrived.
		ErrorCodeName{"WSA_QOS_NO_SENDERS", WSA_QOS_NO_SENDERS},  //! There are no senders.
		ErrorCodeName{"WSA_QOS_NO_RECEIVERS", WSA_QOS_NO_RECEIVERS},  //! There are no receivers.
		ErrorCodeName{"WSA_QOS_REQUEST_CONFIRMED", WSA_QOS_REQUEST_CONFIRMED},  //! Reserve has been confirmed.
		ErrorCodeName{"WSA_QOS_ADMISSION_FAILURE", WSA_QOS_ADMISSION_FAILURE},  //! Error due to lack of resources.
		ErrorCodeName{"WSA_QOS_POLICY_FAILURE", WSA_QOS_POLICY_FAILURE},  //! Rejected for administrative reasons - bad credentials.
		ErrorCodeName{"WSA_QOS_BAD_STYLE", WSA_QOS_BAD_STYLE},  //! Unknown or conflicting style.
		ErrorCodeName{"WSA_QOS_BAD_OBJECT", WSA_QOS_BAD_OBJECT},  //! Problem with some part of the filterspec or providerspecific buffer in general.
		ErrorCodeName{"WSA_QOS_TRAFFIC_CTRL_ERROR", WSA_QOS_TRAFFIC_CTRL_ERROR},  //! Problem with some part of the flowspec.
		ErrorCodeName{"WSA_QOS_GENERIC_ERROR", WSA_QOS_GENERIC_ERROR},  //! General QOS error.
		ErrorCodeName{"WSA_QOS_ESERVICETYPE", WSA_QOS_ESERVICETYPE},  //! An invalid or unrecognized service type was found in the flowspec.
		ErrorCodeName{"WSA_QOS_EFLOWSPEC", WSA_QOS_EFLOWSPEC},  //! An invalid or inconsistent flowspec was found in the QOS structure.
		ErrorCodeName{"WSA_QOS_EPROVSPECBUF", WSA_QOS_EPROVSPECBUF},  //! Invalid QOS provider-specific buffer.
		ErrorCodeName{"WSA_QOS_EFILTERSTYLE", WSA_QOS_EFILTERSTYLE},  //! An invalid QOS filter style was used.
		ErrorCodeName{"WSA_QOS_EFILTERTYPE", WSA_QOS_EFILTERTYPE},  //! An invalid QOS filter type was used.
		ErrorCodeName{"WSA_QOS_EFILTERCOUNT", WSA_QOS_EFILTERCOUNT},  //! An incorrect number of QOS FILTERSPECs were specified in the FLOWDESCRIPTOR.
		ErrorCodeName{"WSA_QOS_EOBJLENGTH", WSA_QOS_EOBJLENGTH},  //! An object with an invalid ObjectLength field was specified in the QOS provider-specific buffer.
		ErrorCodeName{"WSA_QOS_EFLOWCOUNT", WSA_QOS_EFLOWCOUNT},  //! An incorrect number of flow descriptors was specified in the QOS structure.
		ErrorCodeName{"WSA_QOS_EUNKOWNPSOBJ", WSA_QOS_EUNKOWNPSOBJ},  //! An unrecognized object was found in the QOS provider-specific buffer.
		ErrorCodeName{"WSA_QOS_EPOLICYOBJ", WSA_QOS_EPOLICYOBJ},  //! An invalid policy object was found in the QOS provider-specific buffer.
		ErrorCodeName{"WSA_QOS_EFLOWDESC", WSA_QOS_EFLOWDESC},  //! An invalid QOS flow descriptor was found in the flow descriptor list.
		ErrorCodeName{"WSA_QOS_EPSFLOWSPEC", WSA_QOS_EPSFLOWSPEC},  //! An invalid or inconsistent flowspec was found in the QOS provider specific buffer.
		ErrorCodeName{"WSA_QOS_EPSFILTERSPEC", WSA_QOS_EPSFILTERSPEC},  //! An invalid FILTERSPEC was found in the QOS provider-specific buffer.
		ErrorCodeName{"WSA_QOS_ESDMODEOBJ", WSA_QOS_ESDMODEOBJ},  //! An invalid shape discard mode object was found in the QOS provider specific buffer.
		ErrorCodeName{"WSA_QOS_ESHAPERATEOBJ", WSA_QOS_ESHAPERATEOBJ},  //! An invalid shaping rate object was found in the QOS provider-specific buffer.
		ErrorCodeName{"WSA_QOS_RESERVED_PETYPE", WSA_QOS_RESERVED_PETYPE},  //! A reserved policy element was found in the QOS provider-specific buffer.
		ErrorCodeName{"WSA_SECURE_HOST_NOT_FOUND", WSA_SECURE_HOST_NOT_FOUND},  //! No such host is known securely.
		ErrorCodeName{"WSA_IPSEC_NAME_POLICY_ERROR", WSA_IPSEC_NAME_POLICY_ERROR},  //! Name based IPSEC policy could not be added.

#pragma region ERROR_INTERNET
		/*ERROR_INTERNET_*
		12000 - 12175 (0x2EE0)
		See Internet Error Codes and WinInet.h.*/
		ErrorCodeName{"ERROR_FTP_DROPPED", ERROR_FTP_DROPPED},  //! The FTP operation was not completed because the session was aborted.
		ErrorCodeName{"ERROR_FTP_NO_PASSIVE_MODE", ERROR_FTP_NO_PASSIVE_MODE},  //! Passive mode is not available on the server.
		ErrorCodeName{"ERROR_FTP_TRANSFER_IN_PROGRESS", ERROR_FTP_TRANSFER_IN_PROGRESS},  //! The requested operation cannot be made on the FTP session handle because an operation is already in progress.
		ErrorCodeName{"ERROR_GOPHER_ATTRIBUTE_NOT_FOUND", ERROR_GOPHER_ATTRIBUTE_NOT_FOUND},  //! The requested attribute could not be located.
		ErrorCodeName{"ERROR_GOPHER_DATA_ERROR", ERROR_GOPHER_DATA_ERROR},  //! An error was detected while receiving data from the Gopher server.
		ErrorCodeName{"ERROR_GOPHER_END_OF_DATA", ERROR_GOPHER_END_OF_DATA},  //! The end of the data has been reached.
		ErrorCodeName{"ERROR_GOPHER_INCORRECT_LOCATOR_TYPE", ERROR_GOPHER_INCORRECT_LOCATOR_TYPE},  //! The type of the locator is not correct for this operation.
		ErrorCodeName{"ERROR_GOPHER_INVALID_LOCATOR", ERROR_GOPHER_INVALID_LOCATOR},  //! The supplied locator is not valid.
		ErrorCodeName{"ERROR_GOPHER_NOT_FILE", ERROR_GOPHER_NOT_FILE},  //! The request must be made for a file locator.
		ErrorCodeName{"ERROR_GOPHER_NOT_GOPHER_PLUS", ERROR_GOPHER_NOT_GOPHER_PLUS},  //! The requested operation can be made only against a Gopher+ server, or with a locator that specifies a Gopher+ operation.
		ErrorCodeName{"ERROR_GOPHER_PROTOCOL_ERROR", ERROR_GOPHER_PROTOCOL_ERROR},  //! An error was detected while parsing data returned from the Gopher server.
		ErrorCodeName{"ERROR_GOPHER_UNKNOWN_LOCATOR", ERROR_GOPHER_UNKNOWN_LOCATOR},  //! The locator type is unknown.
		ErrorCodeName{"ERROR_HTTP_COOKIE_DECLINED", ERROR_HTTP_COOKIE_DECLINED},  //! The HTTP cookie was declined by the server.
		ErrorCodeName{"ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION", ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION},  //! The HTTP cookie requires confirmation.
		ErrorCodeName{"ERROR_HTTP_DOWNLEVEL_SERVER", ERROR_HTTP_DOWNLEVEL_SERVER},  //! The server did not return any headers.
		ErrorCodeName{"ERROR_HTTP_HEADER_ALREADY_EXISTS", ERROR_HTTP_HEADER_ALREADY_EXISTS},  //! The header could not be added because it already exists.
		ErrorCodeName{"ERROR_HTTP_HEADER_NOT_FOUND", ERROR_HTTP_HEADER_NOT_FOUND},  //! The requested header could not be located.
		ErrorCodeName{"ERROR_HTTP_INVALID_HEADER", ERROR_HTTP_INVALID_HEADER},  //! The supplied header is invalid.
		ErrorCodeName{"ERROR_HTTP_INVALID_QUERY_REQUEST", ERROR_HTTP_INVALID_QUERY_REQUEST},  //! The request made to HttpQueryInfo is invalid.
		ErrorCodeName{"ERROR_HTTP_INVALID_SERVER_RESPONSE", ERROR_HTTP_INVALID_SERVER_RESPONSE},  //! The server response could not be parsed.
		ErrorCodeName{"ERROR_HTTP_NOT_REDIRECTED", ERROR_HTTP_NOT_REDIRECTED},  //! The HTTP request was not redirected.
		ErrorCodeName{"ERROR_HTTP_REDIRECT_FAILED", ERROR_HTTP_REDIRECT_FAILED},  //! The redirection failed because either the scheme changed (for example, HTTP to FTP) or all attempts made to redirect failed (default is five attempts).
		ErrorCodeName{"ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION", ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION},  //! The redirection requires user confirmation.
		ErrorCodeName{"ERROR_INTERNET_ASYNC_THREAD_FAILED", ERROR_INTERNET_ASYNC_THREAD_FAILED},  //! The application could not start an asynchronous thread.
		ErrorCodeName{"ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT", ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT},  //! There was an error in the automatic proxy configuration script.
		ErrorCodeName{"ERROR_INTERNET_BAD_OPTION_LENGTH", ERROR_INTERNET_BAD_OPTION_LENGTH},  //! The length of an option supplied to InternetQueryOption or InternetSetOption is incorrect for the type of option specified.
		ErrorCodeName{"ERROR_INTERNET_BAD_REGISTRY_PARAMETER", ERROR_INTERNET_BAD_REGISTRY_PARAMETER},  //! A required registry value was located but is an incorrect type or has an invalid value.
		ErrorCodeName{"ERROR_INTERNET_CANNOT_CONNECT", ERROR_INTERNET_CANNOT_CONNECT},  //! The attempt to connect to the server failed.
		ErrorCodeName{"ERROR_INTERNET_CHG_POST_IS_NON_SECURE", ERROR_INTERNET_CHG_POST_IS_NON_SECURE},  //! The application is posting and attempting to change multiple lines of text on a server that is not secure.
		ErrorCodeName{"ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED", ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED},  //! The server is requesting client authentication.
		ErrorCodeName{"ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP", ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP},  //! Client authorization is not set up on this computer.
		ErrorCodeName{"ERROR_INTERNET_CONNECTION_ABORTED", ERROR_INTERNET_CONNECTION_ABORTED},  //! The connection with the server has been terminated.
		ErrorCodeName{"ERROR_INTERNET_CONNECTION_RESET", ERROR_INTERNET_CONNECTION_RESET},  //! The connection with the server has been reset.
		ErrorCodeName{"ERROR_INTERNET_DECODING_FAILED", ERROR_INTERNET_DECODING_FAILED},  //! WinINet failed to perform content decoding on the response. For more information, see the Content Encoding topic.
		ErrorCodeName{"ERROR_INTERNET_DIALOG_PENDING", ERROR_INTERNET_DIALOG_PENDING},  //! Another thread has a password dialog box in progress.
		ErrorCodeName{"ERROR_INTERNET_DISCONNECTED", ERROR_INTERNET_DISCONNECTED},  //! The Internet connection has been lost.
		ErrorCodeName{"ERROR_INTERNET_EXTENDED_ERROR", ERROR_INTERNET_EXTENDED_ERROR},  //! An extended error was returned from the server. This is typically a string or buffer containing a verbose error message. Call InternetGetLastResponseInfo to retrieve the error text.
		ErrorCodeName{"ERROR_INTERNET_FAILED_DUETOSECURITYCHECK", ERROR_INTERNET_FAILED_DUETOSECURITYCHECK},  //! The function failed due to a security check.
		ErrorCodeName{"ERROR_INTERNET_FORCE_RETRY", ERROR_INTERNET_FORCE_RETRY},  //! The function needs to redo the request.
		ErrorCodeName{"ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED", ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED},  //! The requested resource requires Fortezza authentication.
		ErrorCodeName{"ERROR_INTERNET_HANDLE_EXISTS", ERROR_INTERNET_HANDLE_EXISTS},  //! The request failed because the handle already exists.
		ErrorCodeName{"ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR", ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR},  //! The application is moving from a non-SSL to an SSL connection because of a redirect.
		ErrorCodeName{"ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR", ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR},  //! The data being submitted to an SSL connection is being redirected to a non-SSL connection.
		ErrorCodeName{"ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR", ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR},  //! The application is moving from an SSL to an non-SSL connection because of a redirect.
		ErrorCodeName{"ERROR_INTERNET_INCORRECT_FORMAT", ERROR_INTERNET_INCORRECT_FORMAT},  //! The format of the request is invalid.
		ErrorCodeName{"ERROR_INTERNET_INCORRECT_HANDLE_STATE", ERROR_INTERNET_INCORRECT_HANDLE_STATE},  //! The requested operation cannot be carried out because the handle supplied is not in the correct state.
		ErrorCodeName{"ERROR_INTERNET_INCORRECT_HANDLE_TYPE", ERROR_INTERNET_INCORRECT_HANDLE_TYPE},  //! The type of handle supplied is incorrect for this operation.
		ErrorCodeName{"ERROR_INTERNET_INCORRECT_PASSWORD", ERROR_INTERNET_INCORRECT_PASSWORD},  //! The request to connect and log on to an FTP server could not be completed because the supplied password is incorrect.
		ErrorCodeName{"ERROR_INTERNET_INCORRECT_USER_NAME", ERROR_INTERNET_INCORRECT_USER_NAME},  //! The request to connect and log on to an FTP server could not be completed because the supplied user name is incorrect.
		ErrorCodeName{"ERROR_INTERNET_INSERT_CDROM", ERROR_INTERNET_INSERT_CDROM},  //! The request requires a CD-ROM to be inserted in the CD-ROM drive to locate the resource requested.
		ErrorCodeName{"ERROR_INTERNET_INTERNAL_ERROR", ERROR_INTERNET_INTERNAL_ERROR},  //! An internal error has occurred.
		ErrorCodeName{"ERROR_INTERNET_INVALID_CA", ERROR_INTERNET_INVALID_CA},  //! The function is unfamiliar with the Certificate Authority that generated the server's certificate.
		ErrorCodeName{"ERROR_INTERNET_INVALID_OPERATION", ERROR_INTERNET_INVALID_OPERATION},  //! The requested operation is invalid.
		ErrorCodeName{"ERROR_INTERNET_INVALID_OPTION", ERROR_INTERNET_INVALID_OPTION},  //! A request to InternetQueryOption or InternetSetOption specified an invalid option value.
		ErrorCodeName{"ERROR_INTERNET_INVALID_PROXY_REQUEST", ERROR_INTERNET_INVALID_PROXY_REQUEST},  //! The request to the proxy was invalid.
		ErrorCodeName{"ERROR_INTERNET_INVALID_URL", ERROR_INTERNET_INVALID_URL},  //! The URL is invalid.
		ErrorCodeName{"ERROR_INTERNET_ITEM_NOT_FOUND", ERROR_INTERNET_ITEM_NOT_FOUND},  //! The requested item could not be located.
		ErrorCodeName{"ERROR_INTERNET_LOGIN_FAILURE", ERROR_INTERNET_LOGIN_FAILURE},  //! The request to connect and log on to an FTP server failed.
		ErrorCodeName{"ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY", ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY},  //! The MS-Logoff digest header has been returned from the website. This header specifically instructs the digest package to purge credentials for the associated realm. This error will only be returned if INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY option has been set; otherwise, ERROR_INTERNET_LOGIN_FAILURE is returned.
		ErrorCodeName{"ERROR_INTERNET_MIXED_SECURITY", ERROR_INTERNET_MIXED_SECURITY},  //! The content is not entirely secure. Some of the content being viewed may have come from unsecured servers.
		ErrorCodeName{"ERROR_INTERNET_NAME_NOT_RESOLVED", ERROR_INTERNET_NAME_NOT_RESOLVED},  //! The server name could not be resolved.
		ErrorCodeName{"ERROR_INTERNET_NEED_MSN_SSPI_PKG", ERROR_INTERNET_NEED_MSN_SSPI_PKG},  //! Not currently implemented.
		ErrorCodeName{"ERROR_INTERNET_NEED_UI", ERROR_INTERNET_NEED_UI},  //! A user interface or other blocking operation has been requested.
		ErrorCodeName{"ERROR_INTERNET_NO_CALLBACK", ERROR_INTERNET_NO_CALLBACK},  //! An asynchronous request could not be made because a callback function has not been set.
		ErrorCodeName{"ERROR_INTERNET_NO_CONTEXT", ERROR_INTERNET_NO_CONTEXT},  //! An asynchronous request could not be made because a zero context value was supplied.
		ErrorCodeName{"ERROR_INTERNET_NO_DIRECT_ACCESS", ERROR_INTERNET_NO_DIRECT_ACCESS},  //! Direct network access cannot be made at this time.
		ErrorCodeName{"ERROR_INTERNET_NOT_INITIALIZED", ERROR_INTERNET_NOT_INITIALIZED},  //! Initialization of the WinINet API has not occurred. Indicates that a higher-level function, such as InternetOpen, has not been called yet.
		ErrorCodeName{"ERROR_INTERNET_NOT_PROXY_REQUEST", ERROR_INTERNET_NOT_PROXY_REQUEST},  //! The request cannot be made via a proxy.
		ErrorCodeName{"ERROR_INTERNET_OPERATION_CANCELLED", ERROR_INTERNET_OPERATION_CANCELLED},  //! The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed.
		ErrorCodeName{"ERROR_INTERNET_OPTION_NOT_SETTABLE", ERROR_INTERNET_OPTION_NOT_SETTABLE},  //! The requested option cannot be set, only queried.
		ErrorCodeName{"ERROR_INTERNET_OUT_OF_HANDLES", ERROR_INTERNET_OUT_OF_HANDLES},  //! No more handles could be generated at this time.
		ErrorCodeName{"ERROR_INTERNET_POST_IS_NON_SECURE", ERROR_INTERNET_POST_IS_NON_SECURE},  //! The application is posting data to a server that is not secure.
		ErrorCodeName{"ERROR_INTERNET_PROTOCOL_NOT_FOUND", ERROR_INTERNET_PROTOCOL_NOT_FOUND},  //! The requested protocol could not be located.
		ErrorCodeName{"ERROR_INTERNET_PROXY_SERVER_UNREACHABLE", ERROR_INTERNET_PROXY_SERVER_UNREACHABLE},  //! The designated proxy server cannot be reached.
		ErrorCodeName{"ERROR_INTERNET_REDIRECT_SCHEME_CHANGE", ERROR_INTERNET_REDIRECT_SCHEME_CHANGE},  //! The function could not handle the redirection, because the scheme changed (for example, HTTP to FTP).
		ErrorCodeName{"ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND", ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND},  //! A required registry value could not be located.
		ErrorCodeName{"ERROR_INTERNET_REQUEST_PENDING", ERROR_INTERNET_REQUEST_PENDING},  //! The required operation could not be completed because one or more requests are pending.
		ErrorCodeName{"ERROR_INTERNET_RETRY_DIALOG", ERROR_INTERNET_RETRY_DIALOG},  //! The dialog box should be retried.
		ErrorCodeName{"ERROR_INTERNET_SEC_CERT_CN_INVALID", ERROR_INTERNET_SEC_CERT_CN_INVALID},  //! SSL certificate common name (host name field) is incorrect for example, if you entered www.server.com and the common name on the certificate says www.different.com.
		ErrorCodeName{"ERROR_INTERNET_SEC_CERT_DATE_INVALID", ERROR_INTERNET_SEC_CERT_DATE_INVALID},  //! SSL certificate date that was received from the server is bad. The certificate is expired.
		ErrorCodeName{"ERROR_INTERNET_SEC_CERT_ERRORS", ERROR_INTERNET_SEC_CERT_ERRORS},  //! The SSL certificate contains errors.
		ErrorCodeName{"ERROR_INTERNET_SEC_CERT_NO_REV", ERROR_INTERNET_SEC_CERT_NO_REV},  //! The SSL certificate was not revoked.
		ErrorCodeName{"ERROR_INTERNET_SEC_CERT_REV_FAILED", ERROR_INTERNET_SEC_CERT_REV_FAILED},  //! Revocation of the SSL certificate failed.
		ErrorCodeName{"ERROR_INTERNET_SEC_CERT_REVOKED", ERROR_INTERNET_SEC_CERT_REVOKED},  //! The SSL certificate was revoked.
		ErrorCodeName{"ERROR_INTERNET_SEC_INVALID_CERT", ERROR_INTERNET_SEC_INVALID_CERT},  //! The SSL certificate is invalid.
		ErrorCodeName{"ERROR_INTERNET_SECURITY_CHANNEL_ERROR", ERROR_INTERNET_SECURITY_CHANNEL_ERROR},  //! The application experienced an internal error loading the SSL libraries.
		ErrorCodeName{"ERROR_INTERNET_SERVER_UNREACHABLE", ERROR_INTERNET_SERVER_UNREACHABLE},  //! The website or server indicated is unreachable.
		ErrorCodeName{"ERROR_INTERNET_SHUTDOWN", ERROR_INTERNET_SHUTDOWN},  //! WinINet support is being shut down or unloaded.
		ErrorCodeName{"ERROR_INTERNET_TCPIP_NOT_INSTALLED", ERROR_INTERNET_TCPIP_NOT_INSTALLED},  //! The required protocol stack is not loaded and the application cannot start WinSock.
		ErrorCodeName{"ERROR_INTERNET_TIMEOUT", ERROR_INTERNET_TIMEOUT},  //! The request has timed out.
		ErrorCodeName{"ERROR_INTERNET_UNABLE_TO_CACHE_FILE", ERROR_INTERNET_UNABLE_TO_CACHE_FILE},  //! The function was unable to cache the file.
		ErrorCodeName{"ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT", ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT},  //! The automatic proxy configuration script could not be downloaded. The INTERNET_FLAG_MUST_CACHE_REQUEST flag was set.
		ErrorCodeName{"ERROR_INTERNET_UNRECOGNIZED_SCHEME", ERROR_INTERNET_UNRECOGNIZED_SCHEME},  //! The URL scheme could not be recognized, or is not supported.

#pragma endregion

#pragma region ERROR_WINHTTP
		/*ERROR_WINHTTP_*
		12001 - 12184 (0x2EE1)
		See WinHTTP Error Codes and Winhttp.h.*/

		ErrorCodeName{"ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR", ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR},  //! Returned by WinHttpGetProxyForUrl when a proxy for the specified URL cannot be located.
		ErrorCodeName{"ERROR_WINHTTP_AUTODETECTION_FAILED", ERROR_WINHTTP_AUTODETECTION_FAILED},  //! Returned by WinHttpDetectAutoProxyConfigUrl if WinHTTP was unable to discover the URL of the Proxy Auto-Configuration (PAC) file.
		ErrorCodeName{"ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT", ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT},  //! An error occurred executing the script code in the Proxy Auto-Configuration (PAC) file.
		ErrorCodeName{"ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN", ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN},  //! Returned by the HttpRequest object if a specified option cannot be requested after the Open method has been called.
		ErrorCodeName{"ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND", ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND},  //! Returned by the HttpRequest object if a requested operation cannot be performed after calling the Send method.
		ErrorCodeName{"ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN", ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN},  //! Returned by the HttpRequest object if a requested operation cannot be performed before calling the Open method.
		ErrorCodeName{"ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND", ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND},  //! Returned by the HttpRequest object if a requested operation cannot be performed before calling the Send method.
		ErrorCodeName{"ERROR_WINHTTP_CANNOT_CONNECT", ERROR_WINHTTP_CANNOT_CONNECT},  //! Returned if connection to the server failed.
		ErrorCodeName{"ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED", ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED},  //! The server requires SSL client Authentication. 
		ErrorCodeName{"ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY", ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY},  //! The application does not have the required privileges to access the private key associated with the client certificate.
		ErrorCodeName{"ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY", ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY},  //! The context for the SSL client certificate does not have a private key associated with it. The client certificate may have been imported to the computer without the private key.
		ErrorCodeName{"ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW", ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW},  //! Returned by WinHttpReceiveResponse when an overflow condition is encountered in the course of parsing chunked encoding.
		ErrorCodeName{"ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED", ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED},  //! Returned by WinHttpReceiveResponse when the server requests client authentication.
		ErrorCodeName{"ERROR_WINHTTP_CONNECTION_ERROR", ERROR_WINHTTP_CONNECTION_ERROR},  //! The connection with the server has been reset or terminated, or an incompatible SSL protocol was encountered. For example, WinHTTP version 5.1 does not support SSL2 unless the client specifically enables it.
		ErrorCodeName{"ERROR_WINHTTP_HEADER_ALREADY_EXISTS", ERROR_WINHTTP_HEADER_ALREADY_EXISTS},  //! Obsolete; no longer used.
		ErrorCodeName{"ERROR_WINHTTP_HEADER_COUNT_EXCEEDED", ERROR_WINHTTP_HEADER_COUNT_EXCEEDED},  //! Returned by WinHttpReceiveResponse when a larger number of headers were present in a response than WinHTTP could receive.
		ErrorCodeName{"ERROR_WINHTTP_HEADER_NOT_FOUND", ERROR_WINHTTP_HEADER_NOT_FOUND},  //! The requested header cannot be located.
		ErrorCodeName{"ERROR_WINHTTP_HEADER_SIZE_OVERFLOW", ERROR_WINHTTP_HEADER_SIZE_OVERFLOW},  //! Returned by WinHttpReceiveResponse when the size of headers received exceeds the limit for the request handle.
		ErrorCodeName{"ERROR_WINHTTP_INCORRECT_HANDLE_STATE", ERROR_WINHTTP_INCORRECT_HANDLE_STATE},  //! The requested operation cannot be carried out because the handle supplied is not in the correct state.
		ErrorCodeName{"ERROR_WINHTTP_INCORRECT_HANDLE_TYPE", ERROR_WINHTTP_INCORRECT_HANDLE_TYPE},  //! The type of handle supplied is incorrect for this operation.
		ErrorCodeName{"ERROR_WINHTTP_INTERNAL_ERROR", ERROR_WINHTTP_INTERNAL_ERROR},  //! An internal error has occurred.
		ErrorCodeName{"ERROR_WINHTTP_INVALID_OPTION", ERROR_WINHTTP_INVALID_OPTION},  //! A request to WinHttpQueryOption or WinHttpSetOption specified an invalid option value.
		ErrorCodeName{"ERROR_WINHTTP_INVALID_QUERY_REQUEST", ERROR_WINHTTP_INVALID_QUERY_REQUEST},  //! Obsolete; no longer used.
		ErrorCodeName{"ERROR_WINHTTP_INVALID_SERVER_RESPONSE", ERROR_WINHTTP_INVALID_SERVER_RESPONSE},  //! The server response cannot be parsed.
		ErrorCodeName{"ERROR_WINHTTP_INVALID_URL", ERROR_WINHTTP_INVALID_URL},  //! The URL is not valid.
		ErrorCodeName{"ERROR_WINHTTP_LOGIN_FAILURE", ERROR_WINHTTP_LOGIN_FAILURE},  //! The login attempt failed. When this error is encountered, the request handle should be closed with WinHttpCloseHandle. A new request handle must be created before retrying the function that originally produced this error.
		ErrorCodeName{"ERROR_WINHTTP_NAME_NOT_RESOLVED", ERROR_WINHTTP_NAME_NOT_RESOLVED},  //! The server name cannot be resolved.
		ErrorCodeName{"ERROR_WINHTTP_NOT_INITIALIZED", ERROR_WINHTTP_NOT_INITIALIZED},  //! Obsolete; no longer used.
		ErrorCodeName{"ERROR_WINHTTP_OPERATION_CANCELLED", ERROR_WINHTTP_OPERATION_CANCELLED},  //! The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed.
		ErrorCodeName{"ERROR_WINHTTP_OPTION_NOT_SETTABLE", ERROR_WINHTTP_OPTION_NOT_SETTABLE},  //! The requested option cannot be set, only queried.
		ErrorCodeName{"ERROR_WINHTTP_OUT_OF_HANDLES", ERROR_WINHTTP_OUT_OF_HANDLES},  //! Obsolete; no longer used.
		ErrorCodeName{"ERROR_WINHTTP_REDIRECT_FAILED", ERROR_WINHTTP_REDIRECT_FAILED},  //! The redirection failed because either the scheme changed or all attempts made to redirect failed (default is five attempts).
		ErrorCodeName{"ERROR_WINHTTP_RESEND_REQUEST", ERROR_WINHTTP_RESEND_REQUEST},  //! The WinHTTP function failed. The desired function can be retried on the same request handle.
		ErrorCodeName{"ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW", ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW},  //! Returned when an incoming response exceeds an internal WinHTTP size limit.
		ErrorCodeName{"ERROR_WINHTTP_SCRIPT_EXECUTION_ERROR", ERROR_WINHTTP_SCRIPT_EXECUTION_ERROR},  //! An error was encountered while executing a script.
		ErrorCodeName{"ERROR_WINHTTP_SECURE_CERT_CN_INVALID", ERROR_WINHTTP_SECURE_CERT_CN_INVALID},  //! Returned when a certificate CN name does not match the passed value (equivalent to a CERT_E_CN_NO_MATCH error).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_CERT_DATE_INVALID", ERROR_WINHTTP_SECURE_CERT_DATE_INVALID},  //! Indicates that a required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file, or that the validity periods of the certification chain do not nest correctly (equivalent to a CERT_E_EXPIRED or a CERT_E_VALIDITYPERIODNESTING error).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_CERT_REV_FAILED", ERROR_WINHTTP_SECURE_CERT_REV_FAILED},  //! Indicates that revocation cannot be checked because the revocation server was offline (equivalent to CRYPT_E_REVOCATION_OFFLINE).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_CERT_REVOKED", ERROR_WINHTTP_SECURE_CERT_REVOKED},  //! Indicates that a certificate has been revoked (equivalent to CRYPT_E_REVOKED).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE", ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE},  //! Indicates that a certificate is not valid for the requested usage (equivalent to CERT_E_WRONG_USAGE).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_CHANNEL_ERROR", ERROR_WINHTTP_SECURE_CHANNEL_ERROR},  //! Indicates that an error occurred having to do with a secure channel (equivalent to error codes that begin with "SEC_E_" and "SEC_I_" listed in the "winerror.h" header file).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_FAILURE", ERROR_WINHTTP_SECURE_FAILURE},  //! One or more errors were found in the Secure Sockets Layer (SSL) certificate sent by the server. To determine what type of error was encountered, check for a WINHTTP_CALLBACK_STATUS_SECURE_FAILURE notification in a status callback function. For more information, see WINHTTP_STATUS_CALLBACK.
		ErrorCodeName{"ERROR_WINHTTP_SECURE_INVALID_CA", ERROR_WINHTTP_SECURE_INVALID_CA},  //! Indicates that a certificate chain was processed, but terminated in a root certificate that is not trusted by the trust provider (equivalent to CERT_E_UNTRUSTEDROOT).
		ErrorCodeName{"ERROR_WINHTTP_SECURE_INVALID_CERT", ERROR_WINHTTP_SECURE_INVALID_CERT},  //! Indicates that a certificate is invalid (equivalent to errors such as CERT_E_ROLE, CERT_E_PATHLENCONST, CERT_E_CRITICAL, CERT_E_PURPOSE, CERT_E_ISSUERCHAINING, CERT_E_MALFORMED and CERT_E_CHAINING).
		ErrorCodeName{"ERROR_WINHTTP_SHUTDOWN", ERROR_WINHTTP_SHUTDOWN},  //! The WinHTTP function support is being shut down or unloaded.
		ErrorCodeName{"ERROR_WINHTTP_TIMEOUT", ERROR_WINHTTP_TIMEOUT},  //! The request has timed out.
		ErrorCodeName{"ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT", ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT},  //! The PAC file cannot be downloaded. For example, the server referenced by the PAC URL may not have been reachable, or the server returned a 404 NOT FOUND response.
		ErrorCodeName{"ERROR_WINHTTP_UNHANDLED_SCRIPT_TYPE", ERROR_WINHTTP_UNHANDLED_SCRIPT_TYPE},  //! The script type is not supported.
		ErrorCodeName{"ERROR_WINHTTP_UNRECOGNIZED_SCHEME", ERROR_WINHTTP_UNRECOGNIZED_SCHEME},  //! The URL specified a scheme other than "http:" or "https:".
#pragma endregion

		ErrorCodeName{"ERROR_IPSEC_QM_POLICY_EXISTS", ERROR_IPSEC_QM_POLICY_EXISTS},  //! The specified quick mode policy already exists.
		ErrorCodeName{"ERROR_IPSEC_QM_POLICY_NOT_FOUND", ERROR_IPSEC_QM_POLICY_NOT_FOUND},  //! The specified quick mode policy was not found.
		ErrorCodeName{"ERROR_IPSEC_QM_POLICY_IN_USE", ERROR_IPSEC_QM_POLICY_IN_USE},  //! The specified quick mode policy is being used.
		ErrorCodeName{"ERROR_IPSEC_MM_POLICY_EXISTS", ERROR_IPSEC_MM_POLICY_EXISTS},  //! The specified main mode policy already exists.
		ErrorCodeName{"ERROR_IPSEC_MM_POLICY_NOT_FOUND", ERROR_IPSEC_MM_POLICY_NOT_FOUND},  //! The specified main mode policy was not found.
		ErrorCodeName{"ERROR_IPSEC_MM_POLICY_IN_USE", ERROR_IPSEC_MM_POLICY_IN_USE},  //! The specified main mode policy is being used.
		ErrorCodeName{"ERROR_IPSEC_MM_FILTER_EXISTS", ERROR_IPSEC_MM_FILTER_EXISTS},  //! The specified main mode filter already exists.
		ErrorCodeName{"ERROR_IPSEC_MM_FILTER_NOT_FOUND", ERROR_IPSEC_MM_FILTER_NOT_FOUND},  //! The specified main mode filter was not found.
		ErrorCodeName{"ERROR_IPSEC_TRANSPORT_FILTER_EXISTS", ERROR_IPSEC_TRANSPORT_FILTER_EXISTS},  //! The specified transport mode filter already exists.
		ErrorCodeName{"ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND", ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND},  //! The specified transport mode filter does not exist.
		ErrorCodeName{"ERROR_IPSEC_MM_AUTH_EXISTS", ERROR_IPSEC_MM_AUTH_EXISTS},  //! The specified main mode authentication list exists.
		ErrorCodeName{"ERROR_IPSEC_MM_AUTH_NOT_FOUND", ERROR_IPSEC_MM_AUTH_NOT_FOUND},  //! The specified main mode authentication list was not found.
		ErrorCodeName{"ERROR_IPSEC_MM_AUTH_IN_USE", ERROR_IPSEC_MM_AUTH_IN_USE},  //! The specified main mode authentication list is being used.
		ErrorCodeName{"ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND", ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND},  //! The specified default main mode policy was not found.
		ErrorCodeName{"ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND", ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND},  //! The specified default main mode authentication list was not found.
		ErrorCodeName{"ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND", ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND},  //! The specified default quick mode policy was not found.
		ErrorCodeName{"ERROR_IPSEC_TUNNEL_FILTER_EXISTS", ERROR_IPSEC_TUNNEL_FILTER_EXISTS},  //! The specified tunnel mode filter exists.
		ErrorCodeName{"ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND", ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND},  //! The specified tunnel mode filter was not found.
		ErrorCodeName{"ERROR_IPSEC_MM_FILTER_PENDING_DELETION", ERROR_IPSEC_MM_FILTER_PENDING_DELETION},  //! The Main Mode filter is pending deletion.
		ErrorCodeName{"ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION", ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION},  //! The transport filter is pending deletion.
		ErrorCodeName{"ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION", ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION},  //! The tunnel filter is pending deletion.
		ErrorCodeName{"ERROR_IPSEC_MM_POLICY_PENDING_DELETION", ERROR_IPSEC_MM_POLICY_PENDING_DELETION},  //! The Main Mode policy is pending deletion.
		ErrorCodeName{"ERROR_IPSEC_MM_AUTH_PENDING_DELETION", ERROR_IPSEC_MM_AUTH_PENDING_DELETION},  //! The Main Mode authentication bundle is pending deletion.
		ErrorCodeName{"ERROR_IPSEC_QM_POLICY_PENDING_DELETION", ERROR_IPSEC_QM_POLICY_PENDING_DELETION},  //! The Quick Mode policy is pending deletion.
		ErrorCodeName{"WARNING_IPSEC_MM_POLICY_PRUNED", WARNING_IPSEC_MM_POLICY_PRUNED},  //! The Main Mode policy was successfully added, but some of the requested offers are not supported.
		ErrorCodeName{"WARNING_IPSEC_QM_POLICY_PRUNED", WARNING_IPSEC_QM_POLICY_PRUNED},  //! The Quick Mode policy was successfully added, but some of the requested offers are not supported.
		ErrorCodeName{"ERROR_IPSEC_IKE_NEG_STATUS_BEGIN", ERROR_IPSEC_IKE_NEG_STATUS_BEGIN},  //! ERROR_IPSEC_IKE_NEG_STATUS_BEGIN
		ErrorCodeName{"ERROR_IPSEC_IKE_AUTH_FAIL", ERROR_IPSEC_IKE_AUTH_FAIL},  //! IKE authentication credentials are unacceptable.
		ErrorCodeName{"ERROR_IPSEC_IKE_ATTRIB_FAIL", ERROR_IPSEC_IKE_ATTRIB_FAIL},  //! IKE security attributes are unacceptable.
		ErrorCodeName{"ERROR_IPSEC_IKE_NEGOTIATION_PENDING", ERROR_IPSEC_IKE_NEGOTIATION_PENDING},  //! IKE Negotiation in progress.
		ErrorCodeName{"ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR", ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR},  //! General processing error.
		ErrorCodeName{"ERROR_IPSEC_IKE_TIMED_OUT", ERROR_IPSEC_IKE_TIMED_OUT},  //! Negotiation timed out.
		ErrorCodeName{"ERROR_IPSEC_IKE_NO_CERT", ERROR_IPSEC_IKE_NO_CERT},  //! IKE failed to find valid machine certificate. Contact your Network Security Administrator about installing a valid certificate in the appropriate Certificate Store.
		ErrorCodeName{"ERROR_IPSEC_IKE_SA_DELETED", ERROR_IPSEC_IKE_SA_DELETED},  //! IKE SA deleted by peer before establishment completed.
		ErrorCodeName{"ERROR_IPSEC_IKE_SA_REAPED", ERROR_IPSEC_IKE_SA_REAPED},  //! IKE SA deleted before establishment completed.
		ErrorCodeName{"ERROR_IPSEC_IKE_MM_ACQUIRE_DROP", ERROR_IPSEC_IKE_MM_ACQUIRE_DROP},  //! Negotiation request sat in Queue too long.
		ErrorCodeName{"ERROR_IPSEC_IKE_QM_ACQUIRE_DROP", ERROR_IPSEC_IKE_QM_ACQUIRE_DROP},  //! Negotiation request sat in Queue too long.
		ErrorCodeName{"ERROR_IPSEC_IKE_QUEUE_DROP_MM", ERROR_IPSEC_IKE_QUEUE_DROP_MM},  //! Negotiation request sat in Queue too long.
		ErrorCodeName{"ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM", ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM},  //! Negotiation request sat in Queue too long.
		ErrorCodeName{"ERROR_IPSEC_IKE_DROP_NO_RESPONSE", ERROR_IPSEC_IKE_DROP_NO_RESPONSE},  //! No response from peer.
		ErrorCodeName{"ERROR_IPSEC_IKE_MM_DELAY_DROP", ERROR_IPSEC_IKE_MM_DELAY_DROP},  //! Negotiation took too long.
		ErrorCodeName{"ERROR_IPSEC_IKE_QM_DELAY_DROP", ERROR_IPSEC_IKE_QM_DELAY_DROP},  //! Negotiation took too long.
		ErrorCodeName{"ERROR_IPSEC_IKE_ERROR", ERROR_IPSEC_IKE_ERROR},  //! Unknown error occurred.
		ErrorCodeName{"ERROR_IPSEC_IKE_CRL_FAILED", ERROR_IPSEC_IKE_CRL_FAILED},  //! Certificate Revocation Check failed.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_KEY_USAGE", ERROR_IPSEC_IKE_INVALID_KEY_USAGE},  //! Invalid certificate key usage.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_CERT_TYPE", ERROR_IPSEC_IKE_INVALID_CERT_TYPE},  //! Invalid certificate type.
		ErrorCodeName{"ERROR_IPSEC_IKE_NO_PRIVATE_KEY", ERROR_IPSEC_IKE_NO_PRIVATE_KEY},  //! IKE negotiation failed because the machine certificate used does not have a private key. IPsec certificates require a private key. Contact your Network Security administrator about replacing with a certificate that has a private key.
		ErrorCodeName{"ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY", ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY},  //! Simultaneous rekeys were detected.
		ErrorCodeName{"ERROR_IPSEC_IKE_DH_FAIL", ERROR_IPSEC_IKE_DH_FAIL},  //! Failure in Diffie-Hellman computation.
		ErrorCodeName{"ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED", ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED},  //! Don't know how to process critical payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_HEADER", ERROR_IPSEC_IKE_INVALID_HEADER},  //! Invalid header.
		ErrorCodeName{"ERROR_IPSEC_IKE_NO_POLICY", ERROR_IPSEC_IKE_NO_POLICY},  //! No policy configured.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_SIGNATURE", ERROR_IPSEC_IKE_INVALID_SIGNATURE},  //! Failed to verify signature.
		ErrorCodeName{"ERROR_IPSEC_IKE_KERBEROS_ERROR", ERROR_IPSEC_IKE_KERBEROS_ERROR},  //! Failed to authenticate using Kerberos.
		ErrorCodeName{"ERROR_IPSEC_IKE_NO_PUBLIC_KEY", ERROR_IPSEC_IKE_NO_PUBLIC_KEY},  //! Peer's certificate did not have a public key.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR", ERROR_IPSEC_IKE_PROCESS_ERR},  //! Error processing error payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_SA", ERROR_IPSEC_IKE_PROCESS_ERR_SA},  //! Error processing SA payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_PROP", ERROR_IPSEC_IKE_PROCESS_ERR_PROP},  //! Error processing Proposal payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_TRANS", ERROR_IPSEC_IKE_PROCESS_ERR_TRANS},  //! Error processing Transform payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_KE", ERROR_IPSEC_IKE_PROCESS_ERR_KE},  //! Error processing KE payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_ID", ERROR_IPSEC_IKE_PROCESS_ERR_ID},  //! Error processing ID payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_CERT", ERROR_IPSEC_IKE_PROCESS_ERR_CERT},  //! Error processing Cert payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ", ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ},  //! Error processing Certificate Request payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_HASH", ERROR_IPSEC_IKE_PROCESS_ERR_HASH},  //! Error processing Hash payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_SIG", ERROR_IPSEC_IKE_PROCESS_ERR_SIG},  //! Error processing Signature payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_NONCE", ERROR_IPSEC_IKE_PROCESS_ERR_NONCE},  //! Error processing Nonce payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY", ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY},  //! Error processing Notify payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_DELETE", ERROR_IPSEC_IKE_PROCESS_ERR_DELETE},  //! Error processing Delete Payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR", ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR},  //! Error processing VendorId payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_PAYLOAD", ERROR_IPSEC_IKE_INVALID_PAYLOAD},  //! Invalid payload received.
		ErrorCodeName{"ERROR_IPSEC_IKE_LOAD_SOFT_SA", ERROR_IPSEC_IKE_LOAD_SOFT_SA},  //! Soft SA loaded.
		ErrorCodeName{"ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN", ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN},  //! Soft SA torn down.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_COOKIE", ERROR_IPSEC_IKE_INVALID_COOKIE},  //! Invalid cookie received.
		ErrorCodeName{"ERROR_IPSEC_IKE_NO_PEER_CERT", ERROR_IPSEC_IKE_NO_PEER_CERT},  //! Peer failed to send valid machine certificate.
		ErrorCodeName{"ERROR_IPSEC_IKE_PEER_CRL_FAILED", ERROR_IPSEC_IKE_PEER_CRL_FAILED},  //! Certification Revocation check of peer's certificate failed.
		ErrorCodeName{"ERROR_IPSEC_IKE_POLICY_CHANGE", ERROR_IPSEC_IKE_POLICY_CHANGE},  //! New policy invalidated SAs formed with old policy.
		ErrorCodeName{"ERROR_IPSEC_IKE_NO_MM_POLICY", ERROR_IPSEC_IKE_NO_MM_POLICY},  //! There is no available Main Mode IKE policy.
		ErrorCodeName{"ERROR_IPSEC_IKE_NOTCBPRIV", ERROR_IPSEC_IKE_NOTCBPRIV},  //! Failed to enabled TCB privilege.
		ErrorCodeName{"ERROR_IPSEC_IKE_SECLOADFAIL", ERROR_IPSEC_IKE_SECLOADFAIL},  //! Failed to load SECURITY.DLL.
		ErrorCodeName{"ERROR_IPSEC_IKE_FAILSSPINIT", ERROR_IPSEC_IKE_FAILSSPINIT},  //! Failed to obtain security function table dispatch address from SSPI.
		ErrorCodeName{"ERROR_IPSEC_IKE_FAILQUERYSSP", ERROR_IPSEC_IKE_FAILQUERYSSP},  //! Failed to query Kerberos package to obtain max token size.
		ErrorCodeName{"ERROR_IPSEC_IKE_SRVACQFAIL", ERROR_IPSEC_IKE_SRVACQFAIL},  //! Failed to obtain Kerberos server credentials for ISAKMP/ERROR_IPSEC_IKE service. Kerberos authentication will not function. The most likely reason for this is lack of domain membership. This is normal if your computer is a member of a workgroup.
		ErrorCodeName{"ERROR_IPSEC_IKE_SRVQUERYCRED", ERROR_IPSEC_IKE_SRVQUERYCRED},  //! Failed to determine SSPI principal name for ISAKMP/ERROR_IPSEC_IKE service (QueryCredentialsAttributes).
		ErrorCodeName{"ERROR_IPSEC_IKE_GETSPIFAIL", ERROR_IPSEC_IKE_GETSPIFAIL},  //! Failed to obtain new SPI for the inbound SA from IPsec driver. The most common cause for this is that the driver does not have the correct filter. Check your policy to verify the filters.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_FILTER", ERROR_IPSEC_IKE_INVALID_FILTER},  //! Given filter is invalid.
		ErrorCodeName{"ERROR_IPSEC_IKE_OUT_OF_MEMORY", ERROR_IPSEC_IKE_OUT_OF_MEMORY},  //! Memory allocation failed.
		ErrorCodeName{"ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED", ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED},  //! Failed to add Security Association to IPsec Driver. The most common cause for this is if the IKE negotiation took too long to complete. If the problem persists, reduce the load on the faulting machine.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_POLICY", ERROR_IPSEC_IKE_INVALID_POLICY},  //! Invalid policy.
		ErrorCodeName{"ERROR_IPSEC_IKE_UNKNOWN_DOI", ERROR_IPSEC_IKE_UNKNOWN_DOI},  //! Invalid DOI.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_SITUATION", ERROR_IPSEC_IKE_INVALID_SITUATION},  //! Invalid situation.
		ErrorCodeName{"ERROR_IPSEC_IKE_DH_FAILURE", ERROR_IPSEC_IKE_DH_FAILURE},  //! Diffie-Hellman failure.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_GROUP", ERROR_IPSEC_IKE_INVALID_GROUP},  //! Invalid Diffie-Hellman group.
		ErrorCodeName{"ERROR_IPSEC_IKE_ENCRYPT", ERROR_IPSEC_IKE_ENCRYPT},  //! Error encrypting payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_DECRYPT", ERROR_IPSEC_IKE_DECRYPT},  //! Error decrypting payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_POLICY_MATCH", ERROR_IPSEC_IKE_POLICY_MATCH},  //! Policy match error.
		ErrorCodeName{"ERROR_IPSEC_IKE_UNSUPPORTED_ID", ERROR_IPSEC_IKE_UNSUPPORTED_ID},  //! Unsupported ID.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_HASH", ERROR_IPSEC_IKE_INVALID_HASH},  //! Hash verification failed.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_HASH_ALG", ERROR_IPSEC_IKE_INVALID_HASH_ALG},  //! Invalid hash algorithm.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_HASH_SIZE", ERROR_IPSEC_IKE_INVALID_HASH_SIZE},  //! Invalid hash size.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG", ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG},  //! Invalid encryption algorithm.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_AUTH_ALG", ERROR_IPSEC_IKE_INVALID_AUTH_ALG},  //! Invalid authentication algorithm.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_SIG", ERROR_IPSEC_IKE_INVALID_SIG},  //! Invalid certificate signature.
		ErrorCodeName{"ERROR_IPSEC_IKE_LOAD_FAILED", ERROR_IPSEC_IKE_LOAD_FAILED},  //! Load failed.
		ErrorCodeName{"ERROR_IPSEC_IKE_RPC_DELETE", ERROR_IPSEC_IKE_RPC_DELETE},  //! Deleted via RPC call.
		ErrorCodeName{"ERROR_IPSEC_IKE_BENIGN_REINIT", ERROR_IPSEC_IKE_BENIGN_REINIT},  //! Temporary state created to perform reinitialization. This is not a real failure.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY", ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY},  //! The lifetime value received in the Responder Lifetime Notify is below the Windows 2000 configured minimum value. Please fix the policy on the peer machine.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION", ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION},  //! The recipient cannot handle version of IKE specified in the header.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN", ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN},  //! Key length in certificate is too small for configured security requirements.
		ErrorCodeName{"ERROR_IPSEC_IKE_MM_LIMIT", ERROR_IPSEC_IKE_MM_LIMIT},  //! Max number of established MM SAs to peer exceeded.
		ErrorCodeName{"ERROR_IPSEC_IKE_NEGOTIATION_DISABLED", ERROR_IPSEC_IKE_NEGOTIATION_DISABLED},  //! IKE received a policy that disables negotiation.
		ErrorCodeName{"ERROR_IPSEC_IKE_QM_LIMIT", ERROR_IPSEC_IKE_QM_LIMIT},  //! Reached maximum quick mode limit for the main mode. New main mode will be started.
		ErrorCodeName{"ERROR_IPSEC_IKE_MM_EXPIRED", ERROR_IPSEC_IKE_MM_EXPIRED},  //! Main mode SA lifetime expired or peer sent a main mode delete.
		ErrorCodeName{"ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID", ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID},  //! Main mode SA assumed to be invalid because peer stopped responding.
		ErrorCodeName{"ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH", ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH},  //! Certificate doesn't chain to a trusted root in IPsec policy.
		ErrorCodeName{"ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID", ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID},  //! Received unexpected message ID.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD", ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD},  //! Received invalid authentication offers.
		ErrorCodeName{"ERROR_IPSEC_IKE_DOS_COOKIE_SENT", ERROR_IPSEC_IKE_DOS_COOKIE_SENT},  //! Sent DoS cookie notify to initiator.
		ErrorCodeName{"ERROR_IPSEC_IKE_SHUTTING_DOWN", ERROR_IPSEC_IKE_SHUTTING_DOWN},  //! IKE service is shutting down.
		ErrorCodeName{"ERROR_IPSEC_IKE_CGA_AUTH_FAILED", ERROR_IPSEC_IKE_CGA_AUTH_FAILED},  //! Could not verify binding between CGA address and certificate.
		ErrorCodeName{"ERROR_IPSEC_IKE_PROCESS_ERR_NATOA", ERROR_IPSEC_IKE_PROCESS_ERR_NATOA},  //! Error processing NatOA payload.
		ErrorCodeName{"ERROR_IPSEC_IKE_INVALID_MM_FOR_QM", ERROR_IPSEC_IKE_INVALID_MM_FOR_QM},  //! Parameters of the main mode are invalid for this quick mode.
		ErrorCodeName{"ERROR_IPSEC_IKE_QM_EXPIRED", ERROR_IPSEC_IKE_QM_EXPIRED},  //! Quick mode SA was expired by IPsec driver.
		ErrorCodeName{"ERROR_IPSEC_IKE_TOO_MANY_FILTERS", ERROR_IPSEC_IKE_TOO_MANY_FILTERS},  //! Too many dynamically added IKEEXT filters were detected.
		ErrorCodeName{"ERROR_IPSEC_IKE_NEG_STATUS_END", ERROR_IPSEC_IKE_NEG_STATUS_END},  //! ERROR_IPSEC_IKE_NEG_STATUS_END
		ErrorCodeName{"ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL", ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL},  //! NAP reauth succeeded and must delete the dummy NAP IKEv2 tunnel.
		ErrorCodeName{"ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE", ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE},  //! Error in assigning inner IP address to initiator in tunnel mode.
		ErrorCodeName{"ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING", ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING},  //! Require configuration payload missing.
		ErrorCodeName{"ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING", ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING},  //! A negotiation running as the security principle who issued the connection is in progress.
		ErrorCodeName{"ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS", ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS},  //! SA was deleted due to IKEv1/AuthIP co-existence suppress check.
		ErrorCodeName{"ERROR_IPSEC_IKE_RATELIMIT_DROP", ERROR_IPSEC_IKE_RATELIMIT_DROP},  //! Incoming SA request was dropped due to peer IP address rate limiting.
		ErrorCodeName{"ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE", ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE},  //! Peer does not support MOBIKE.
		ErrorCodeName{"ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE", ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE},  //! SA establishment is not authorized.
		ErrorCodeName{"ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE", ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE},  //! SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential.
		ErrorCodeName{"ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY", ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY},  //! SA establishment is not authorized. You may need to enter updated or different credentials such as a smartcard.
		ErrorCodeName{"ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE", ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE},  //! SA establishment is not authorized because there is not a sufficiently strong PKINIT-based credential. This might be related to certificate-to-account mapping failure for the SA.
		ErrorCodeName{"ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END", ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END},  //! ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END
		ErrorCodeName{"ERROR_IPSEC_BAD_SPI", ERROR_IPSEC_BAD_SPI},  //! The SPI in the packet does not match a valid IPsec SA.
		ErrorCodeName{"ERROR_IPSEC_SA_LIFETIME_EXPIRED", ERROR_IPSEC_SA_LIFETIME_EXPIRED},  //! Packet was received on an IPsec SA whose lifetime has expired.
		ErrorCodeName{"ERROR_IPSEC_WRONG_SA", ERROR_IPSEC_WRONG_SA},  //! Packet was received on an IPsec SA that does not match the packet characteristics.
		ErrorCodeName{"ERROR_IPSEC_REPLAY_CHECK_FAILED", ERROR_IPSEC_REPLAY_CHECK_FAILED},  //! Packet sequence number replay check failed.
		ErrorCodeName{"ERROR_IPSEC_INVALID_PACKET", ERROR_IPSEC_INVALID_PACKET},  //! IPsec header and/or trailer in the packet is invalid.
		ErrorCodeName{"ERROR_IPSEC_INTEGRITY_CHECK_FAILED", ERROR_IPSEC_INTEGRITY_CHECK_FAILED},  //! IPsec integrity check failed.
		ErrorCodeName{"ERROR_IPSEC_CLEAR_TEXT_DROP", ERROR_IPSEC_CLEAR_TEXT_DROP},  //! IPsec dropped a clear text packet.
		ErrorCodeName{"ERROR_IPSEC_AUTH_FIREWALL_DROP", ERROR_IPSEC_AUTH_FIREWALL_DROP},  //! IPsec dropped an incoming ESP packet in authenticated firewall mode. This drop is benign.
		ErrorCodeName{"ERROR_IPSEC_THROTTLE_DROP", ERROR_IPSEC_THROTTLE_DROP},  //! IPsec dropped a packet due to DoS throttling.
		ErrorCodeName{"ERROR_IPSEC_DOSP_BLOCK", ERROR_IPSEC_DOSP_BLOCK},  //! IPsec DoS Protection matched an explicit block rule.
		ErrorCodeName{"ERROR_IPSEC_DOSP_RECEIVED_MULTICAST", ERROR_IPSEC_DOSP_RECEIVED_MULTICAST},  //! IPsec DoS Protection received an IPsec specific multicast packet which is not allowed.
		ErrorCodeName{"ERROR_IPSEC_DOSP_INVALID_PACKET", ERROR_IPSEC_DOSP_INVALID_PACKET},  //! IPsec DoS Protection received an incorrectly formatted packet.
		ErrorCodeName{"ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED", ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED},  //! IPsec DoS Protection failed to look up state.
		ErrorCodeName{"ERROR_IPSEC_DOSP_MAX_ENTRIES", ERROR_IPSEC_DOSP_MAX_ENTRIES},  //! IPsec DoS Protection failed to create state because the maximum number of entries allowed by policy has been reached.
		ErrorCodeName{"ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED", ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED},  //! IPsec DoS Protection received an IPsec negotiation packet for a keying module which is not allowed by policy.
		ErrorCodeName{"ERROR_IPSEC_DOSP_NOT_INSTALLED", ERROR_IPSEC_DOSP_NOT_INSTALLED},  //! IPsec DoS Protection has not been enabled.
		ErrorCodeName{"ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES", ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES},  //! IPsec DoS Protection failed to create a per internal IP rate limit queue because the maximum number of queues allowed by policy has been reached.
		ErrorCodeName{"ERROR_SXS_SECTION_NOT_FOUND", ERROR_SXS_SECTION_NOT_FOUND},  //! The requested section was not present in the activation context.
		ErrorCodeName{"ERROR_SXS_CANT_GEN_ACTCTX", ERROR_SXS_CANT_GEN_ACTCTX},  //! The application has failed to start because its side-by-side configuration is incorrect. Please see the application event log or use the command-line sxstrace.exe tool for more detail.
		ErrorCodeName{"ERROR_SXS_INVALID_ACTCTXDATA_FORMAT", ERROR_SXS_INVALID_ACTCTXDATA_FORMAT},  //! The application binding data format is invalid.
		ErrorCodeName{"ERROR_SXS_ASSEMBLY_NOT_FOUND", ERROR_SXS_ASSEMBLY_NOT_FOUND},  //! The referenced assembly is not installed on your system.
		ErrorCodeName{"ERROR_SXS_MANIFEST_FORMAT_ERROR", ERROR_SXS_MANIFEST_FORMAT_ERROR},  //! The manifest file does not begin with the required tag and format information.
		ErrorCodeName{"ERROR_SXS_MANIFEST_PARSE_ERROR", ERROR_SXS_MANIFEST_PARSE_ERROR},  //! The manifest file contains one or more syntax errors.
		ErrorCodeName{"ERROR_SXS_ACTIVATION_CONTEXT_DISABLED", ERROR_SXS_ACTIVATION_CONTEXT_DISABLED},  //! The application attempted to activate a disabled activation context.
		ErrorCodeName{"ERROR_SXS_KEY_NOT_FOUND", ERROR_SXS_KEY_NOT_FOUND},  //! The requested lookup key was not found in any active activation context.
		ErrorCodeName{"ERROR_SXS_VERSION_CONFLICT", ERROR_SXS_VERSION_CONFLICT},  //! A component version required by the application conflicts with another component version already active.
		ErrorCodeName{"ERROR_SXS_WRONG_SECTION_TYPE", ERROR_SXS_WRONG_SECTION_TYPE},  //! The type requested activation context section does not match the query API used.
		ErrorCodeName{"ERROR_SXS_THREAD_QUERIES_DISABLED", ERROR_SXS_THREAD_QUERIES_DISABLED},  //! Lack of system resources has required isolated activation to be disabled for the current thread of execution.
		ErrorCodeName{"ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET", ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET},  //! An attempt to set the process default activation context failed because the process default activation context was already set.
		ErrorCodeName{"ERROR_SXS_UNKNOWN_ENCODING_GROUP", ERROR_SXS_UNKNOWN_ENCODING_GROUP},  //! The encoding group identifier specified is not recognized.
		ErrorCodeName{"ERROR_SXS_UNKNOWN_ENCODING", ERROR_SXS_UNKNOWN_ENCODING},  //! The encoding requested is not recognized.
		ErrorCodeName{"ERROR_SXS_INVALID_XML_NAMESPACE_URI", ERROR_SXS_INVALID_XML_NAMESPACE_URI},  //! The manifest contains a reference to an invalid URI.
		ErrorCodeName{"ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED", ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED},  //! The application manifest contains a reference to a dependent assembly which is not installed.
		ErrorCodeName{"ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED", ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED},  //! The manifest for an assembly used by the application has a reference to a dependent assembly which is not installed.
		ErrorCodeName{"ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE", ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE},  //! The manifest contains an attribute for the assembly identity which is not valid.
		ErrorCodeName{"ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE", ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE},  //! The manifest is missing the required default namespace specification on the assembly element.
		ErrorCodeName{"ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE", ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE},  //! The manifest has a default namespace specified on the assembly element but its value is not "urn:schemas-microsoft-com:asm.v1".
		ErrorCodeName{"ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT", ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT},  //! The private manifest probed has crossed a path with an unsupported reparse point.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_DLL_NAME", ERROR_SXS_DUPLICATE_DLL_NAME},  //! Two or more components referenced directly or indirectly by the application manifest have files by the same name.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME", ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME},  //! Two or more components referenced directly or indirectly by the application manifest have window classes with the same name.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_CLSID", ERROR_SXS_DUPLICATE_CLSID},  //! Two or more components referenced directly or indirectly by the application manifest have the same COM server CLSIDs.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_IID", ERROR_SXS_DUPLICATE_IID},  //! Two or more components referenced directly or indirectly by the application manifest have proxies for the same COM interface IIDs.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_TLBID", ERROR_SXS_DUPLICATE_TLBID},  //! Two or more components referenced directly or indirectly by the application manifest have the same COM type library TLBIDs.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_PROGID", ERROR_SXS_DUPLICATE_PROGID},  //! Two or more components referenced directly or indirectly by the application manifest have the same COM ProgIDs.
		ErrorCodeName{"ERROR_SXS_DUPLICATE_ASSEMBLY_NAME", ERROR_SXS_DUPLICATE_ASSEMBLY_NAME},  //! Two or more components referenced directly or indirectly by the application manifest are different versions of the same component which is not permitted.
		ErrorCodeName{"ERROR_SXS_FILE_HASH_MISMATCH", ERROR_SXS_FILE_HASH_MISMATCH},  //! A component's file does not match the verification information present in the component manifest.
		ErrorCodeName{"ERROR_SXS_POLICY_PARSE_ERROR", ERROR_SXS_POLICY_PARSE_ERROR},  //! The policy manifest contains one or more syntax errors.
		ErrorCodeName{"ERROR_SXS_XML_E_MISSINGQUOTE", ERROR_SXS_XML_E_MISSINGQUOTE},  //! Manifest Parse Error : A string literal was expected, but no opening quote character was found.
		ErrorCodeName{"ERROR_SXS_XML_E_COMMENTSYNTAX", ERROR_SXS_XML_E_COMMENTSYNTAX},  //! Manifest Parse Error : Incorrect syntax was used in a comment.
		ErrorCodeName{"ERROR_SXS_XML_E_BADSTARTNAMECHAR", ERROR_SXS_XML_E_BADSTARTNAMECHAR},  //! Manifest Parse Error : A name was started with an invalid character.
		ErrorCodeName{"ERROR_SXS_XML_E_BADNAMECHAR", ERROR_SXS_XML_E_BADNAMECHAR},  //! Manifest Parse Error : A name contained an invalid character.
		ErrorCodeName{"ERROR_SXS_XML_E_BADCHARINSTRING", ERROR_SXS_XML_E_BADCHARINSTRING},  //! Manifest Parse Error : A string literal contained an invalid character.
		ErrorCodeName{"ERROR_SXS_XML_E_XMLDECLSYNTAX", ERROR_SXS_XML_E_XMLDECLSYNTAX},  //! Manifest Parse Error : Invalid syntax for an xml declaration.
		ErrorCodeName{"ERROR_SXS_XML_E_BADCHARDATA", ERROR_SXS_XML_E_BADCHARDATA},  //! Manifest Parse Error : An Invalid character was found in text content.
		ErrorCodeName{"ERROR_SXS_XML_E_MISSINGWHITESPACE", ERROR_SXS_XML_E_MISSINGWHITESPACE},  //! Manifest Parse Error : Required white space was missing.
		ErrorCodeName{"ERROR_SXS_XML_E_EXPECTINGTAGEND", ERROR_SXS_XML_E_EXPECTINGTAGEND},  //! Manifest Parse Error : The character '>' was expected.
		ErrorCodeName{"ERROR_SXS_XML_E_MISSINGSEMICOLON", ERROR_SXS_XML_E_MISSINGSEMICOLON},  //! Manifest Parse Error : A semi colon character was expected.
		ErrorCodeName{"ERROR_SXS_XML_E_UNBALANCEDPAREN", ERROR_SXS_XML_E_UNBALANCEDPAREN},  //! Manifest Parse Error : Unbalanced parentheses.
		ErrorCodeName{"ERROR_SXS_XML_E_INTERNALERROR", ERROR_SXS_XML_E_INTERNALERROR},  //! Manifest Parse Error : Internal error.
		ErrorCodeName{"ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE", ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE},  //! Manifest Parse Error : Whitespace is not allowed at this location.
		ErrorCodeName{"ERROR_SXS_XML_E_INCOMPLETE_ENCODING", ERROR_SXS_XML_E_INCOMPLETE_ENCODING},  //! Manifest Parse Error : End of file reached in invalid state for current encoding.
		ErrorCodeName{"ERROR_SXS_XML_E_MISSING_PAREN", ERROR_SXS_XML_E_MISSING_PAREN},  //! Manifest Parse Error : Missing parenthesis.
		ErrorCodeName{"ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE", ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE},  //! Manifest Parse Error : A single or double closing quote character (\' or \") is missing.
		ErrorCodeName{"ERROR_SXS_XML_E_MULTIPLE_COLONS", ERROR_SXS_XML_E_MULTIPLE_COLONS},  //! Manifest Parse Error : Multiple colons are not allowed in a name.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALID_DECIMAL", ERROR_SXS_XML_E_INVALID_DECIMAL},  //! Manifest Parse Error : Invalid character for decimal digit.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALID_HEXIDECIMAL", ERROR_SXS_XML_E_INVALID_HEXIDECIMAL},  //! Manifest Parse Error : Invalid character for hexadecimal digit.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALID_UNICODE", ERROR_SXS_XML_E_INVALID_UNICODE},  //! Manifest Parse Error : Invalid unicode character value for this platform.
		ErrorCodeName{"ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK", ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK},  //! Manifest Parse Error : Expecting whitespace or '?'.
		ErrorCodeName{"ERROR_SXS_XML_E_UNEXPECTEDENDTAG", ERROR_SXS_XML_E_UNEXPECTEDENDTAG},  //! Manifest Parse Error : End tag was not expected at this location.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDTAG", ERROR_SXS_XML_E_UNCLOSEDTAG},  //! Manifest Parse Error : The following tags were not closed: %1.
		ErrorCodeName{"ERROR_SXS_XML_E_DUPLICATEATTRIBUTE", ERROR_SXS_XML_E_DUPLICATEATTRIBUTE},  //! Manifest Parse Error : Duplicate attribute.
		ErrorCodeName{"ERROR_SXS_XML_E_MULTIPLEROOTS", ERROR_SXS_XML_E_MULTIPLEROOTS},  //! Manifest Parse Error : Only one top level element is allowed in an XML document.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALIDATROOTLEVEL", ERROR_SXS_XML_E_INVALIDATROOTLEVEL},  //! Manifest Parse Error : Invalid at the top level of the document.
		ErrorCodeName{"ERROR_SXS_XML_E_BADXMLDECL", ERROR_SXS_XML_E_BADXMLDECL},  //! Manifest Parse Error : Invalid xml declaration.
		ErrorCodeName{"ERROR_SXS_XML_E_MISSINGROOT", ERROR_SXS_XML_E_MISSINGROOT},  //! Manifest Parse Error : XML document must have a top level element.
		ErrorCodeName{"ERROR_SXS_XML_E_UNEXPECTEDEOF", ERROR_SXS_XML_E_UNEXPECTEDEOF},  //! Manifest Parse Error : Unexpected end of file.
		ErrorCodeName{"ERROR_SXS_XML_E_BADPEREFINSUBSET", ERROR_SXS_XML_E_BADPEREFINSUBSET},  //! Manifest Parse Error : Parameter entities cannot be used inside markup declarations in an internal subset.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDSTARTTAG", ERROR_SXS_XML_E_UNCLOSEDSTARTTAG},  //! Manifest Parse Error : Element was not closed.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDENDTAG", ERROR_SXS_XML_E_UNCLOSEDENDTAG},  //! Manifest Parse Error : End element was missing the character '>'.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDSTRING", ERROR_SXS_XML_E_UNCLOSEDSTRING},  //! Manifest Parse Error : A string literal was not closed.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDCOMMENT", ERROR_SXS_XML_E_UNCLOSEDCOMMENT},  //! Manifest Parse Error : A comment was not closed.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDDECL", ERROR_SXS_XML_E_UNCLOSEDDECL},  //! Manifest Parse Error : A declaration was not closed.
		ErrorCodeName{"ERROR_SXS_XML_E_UNCLOSEDCDATA", ERROR_SXS_XML_E_UNCLOSEDCDATA},  //! Manifest Parse Error : A CDATA section was not closed.
		ErrorCodeName{"ERROR_SXS_XML_E_RESERVEDNAMESPACE", ERROR_SXS_XML_E_RESERVEDNAMESPACE},  //! Manifest Parse Error : The namespace prefix is not allowed to start with the reserved string "xml".
		ErrorCodeName{"ERROR_SXS_XML_E_INVALIDENCODING", ERROR_SXS_XML_E_INVALIDENCODING},  //! Manifest Parse Error : System does not support the specified encoding.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALIDSWITCH", ERROR_SXS_XML_E_INVALIDSWITCH},  //! Manifest Parse Error : Switch from current encoding to specified encoding not supported.
		ErrorCodeName{"ERROR_SXS_XML_E_BADXMLCASE", ERROR_SXS_XML_E_BADXMLCASE},  //! Manifest Parse Error : The name 'xml' is reserved and must be lower case.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALID_STANDALONE", ERROR_SXS_XML_E_INVALID_STANDALONE},  //! Manifest Parse Error : The standalone attribute must have the value 'yes' or 'no'.
		ErrorCodeName{"ERROR_SXS_XML_E_UNEXPECTED_STANDALONE", ERROR_SXS_XML_E_UNEXPECTED_STANDALONE},  //! Manifest Parse Error : The standalone attribute cannot be used in external entities.
		ErrorCodeName{"ERROR_SXS_XML_E_INVALID_VERSION", ERROR_SXS_XML_E_INVALID_VERSION},  //! Manifest Parse Error : Invalid version number.
		ErrorCodeName{"ERROR_SXS_XML_E_MISSINGEQUALS", ERROR_SXS_XML_E_MISSINGEQUALS},  //! Manifest Parse Error : Missing equals sign between attribute and attribute value.
		ErrorCodeName{"ERROR_SXS_PROTECTION_RECOVERY_FAILED", ERROR_SXS_PROTECTION_RECOVERY_FAILED},  //! Assembly Protection Error : Unable to recover the specified assembly.
		ErrorCodeName{"ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT", ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT},  //! Assembly Protection Error : The public key for an assembly was too short to be allowed.
		ErrorCodeName{"ERROR_SXS_PROTECTION_CATALOG_NOT_VALID", ERROR_SXS_PROTECTION_CATALOG_NOT_VALID},  //! Assembly Protection Error : The catalog for an assembly is not valid, or does not match the assembly's manifest.
		ErrorCodeName{"ERROR_SXS_UNTRANSLATABLE_HRESULT", ERROR_SXS_UNTRANSLATABLE_HRESULT},  //! An HRESULT could not be translated to a corresponding Win32 error code.
		ErrorCodeName{"ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING", ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING},  //! Assembly Protection Error : The catalog for an assembly is missing.
		ErrorCodeName{"ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE", ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE},  //! The supplied assembly identity is missing one or more attributes which must be present in this context.
		ErrorCodeName{"ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME", ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME},  //! The supplied assembly identity has one or more attribute names that contain characters not permitted in XML names.
		ErrorCodeName{"ERROR_SXS_ASSEMBLY_MISSING", ERROR_SXS_ASSEMBLY_MISSING},  //! The referenced assembly could not be found.
		ErrorCodeName{"ERROR_SXS_CORRUPT_ACTIVATION_STACK", ERROR_SXS_CORRUPT_ACTIVATION_STACK},  //! The activation context activation stack for the running thread of execution is corrupt.
		ErrorCodeName{"ERROR_SXS_CORRUPTION", ERROR_SXS_CORRUPTION},  //! The application isolation metadata for this process or thread has become corrupt.
		ErrorCodeName{"ERROR_SXS_EARLY_DEACTIVATION", ERROR_SXS_EARLY_DEACTIVATION},  //! The activation context being deactivated is not the most recently activated one.
		ErrorCodeName{"ERROR_SXS_INVALID_DEACTIVATION", ERROR_SXS_INVALID_DEACTIVATION},  //! The activation context being deactivated is not active for the current thread of execution.
		ErrorCodeName{"ERROR_SXS_MULTIPLE_DEACTIVATION", ERROR_SXS_MULTIPLE_DEACTIVATION},  //! The activation context being deactivated has already been deactivated.
		ErrorCodeName{"ERROR_SXS_PROCESS_TERMINATION_REQUESTED", ERROR_SXS_PROCESS_TERMINATION_REQUESTED},  //! A component used by the isolation facility has requested to terminate the process.
		ErrorCodeName{"ERROR_SXS_RELEASE_ACTIVATION_CONTEXT", ERROR_SXS_RELEASE_ACTIVATION_CONTEXT},  //! A kernel mode component is releasing a reference on an activation context.
		ErrorCodeName{"ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY", ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY},  //! The activation context of system default assembly could not be generated.
		ErrorCodeName{"ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE", ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE},  //! The value of an attribute in an identity is not within the legal range.
		ErrorCodeName{"ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME", ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME},  //! The name of an attribute in an identity is not within the legal range.
		ErrorCodeName{"ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE", ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE},  //! An identity contains two definitions for the same attribute.
		ErrorCodeName{"ERROR_SXS_IDENTITY_PARSE_ERROR", ERROR_SXS_IDENTITY_PARSE_ERROR},  //! The identity string is malformed. This may be due to a trailing comma, more than two unnamed attributes, missing attribute name or missing attribute value.
		ErrorCodeName{"ERROR_MALFORMED_SUBSTITUTION_STRING", ERROR_MALFORMED_SUBSTITUTION_STRING},  //! A string containing localized substitutable content was malformed. Either a dollar sign ($) was followed by something other than a left parenthesis or another dollar sign or an substitution's right parenthesis was not found.
		ErrorCodeName{"ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN", ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN},  //! The public key token does not correspond to the public key specified.
		ErrorCodeName{"ERROR_UNMAPPED_SUBSTITUTION_STRING", ERROR_UNMAPPED_SUBSTITUTION_STRING},  //! A substitution string had no mapping.
		ErrorCodeName{"ERROR_SXS_ASSEMBLY_NOT_LOCKED", ERROR_SXS_ASSEMBLY_NOT_LOCKED},  //! The component must be locked before making the request.
		ErrorCodeName{"ERROR_SXS_COMPONENT_STORE_CORRUPT", ERROR_SXS_COMPONENT_STORE_CORRUPT},  //! The component store has been corrupted.
		ErrorCodeName{"ERROR_ADVANCED_INSTALLER_FAILED", ERROR_ADVANCED_INSTALLER_FAILED},  //! An advanced installer failed during setup or servicing.
		ErrorCodeName{"ERROR_XML_ENCODING_MISMATCH", ERROR_XML_ENCODING_MISMATCH},  //! The character encoding in the XML declaration did not match the encoding used in the document.
		ErrorCodeName{"ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT", ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT},  //! The identities of the manifests are identical but their contents are different.
		ErrorCodeName{"ERROR_SXS_IDENTITIES_DIFFERENT", ERROR_SXS_IDENTITIES_DIFFERENT},  //! The component identities are different.
		ErrorCodeName{"ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT", ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT},  //! The assembly is not a deployment.
		ErrorCodeName{"ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY", ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY},  //! The file is not a part of the assembly.
		ErrorCodeName{"ERROR_SXS_MANIFEST_TOO_BIG", ERROR_SXS_MANIFEST_TOO_BIG},  //! The size of the manifest exceeds the maximum allowed.
		ErrorCodeName{"ERROR_SXS_SETTING_NOT_REGISTERED", ERROR_SXS_SETTING_NOT_REGISTERED},  //! The setting is not registered.
		ErrorCodeName{"ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE", ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE},  //! One or more required members of the transaction are not present.
		ErrorCodeName{"ERROR_SMI_PRIMITIVE_INSTALLER_FAILED", ERROR_SMI_PRIMITIVE_INSTALLER_FAILED},  //! The SMI primitive installer failed during setup or servicing.
		ErrorCodeName{"ERROR_GENERIC_COMMAND_FAILED", ERROR_GENERIC_COMMAND_FAILED},  //! A generic command executable returned a result that indicates failure.
		ErrorCodeName{"ERROR_SXS_FILE_HASH_MISSING", ERROR_SXS_FILE_HASH_MISSING},  //! A component is missing file verification information in its manifest.
		ErrorCodeName{"ERROR_EVT_INVALID_CHANNEL_PATH", ERROR_EVT_INVALID_CHANNEL_PATH},  //! The specified channel path is invalid.
		ErrorCodeName{"ERROR_EVT_INVALID_QUERY", ERROR_EVT_INVALID_QUERY},  //! The specified query is invalid.
		ErrorCodeName{"ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND", ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND},  //! The publisher metadata cannot be found in the resource.
		ErrorCodeName{"ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND", ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND},  //! The template for an event definition cannot be found in the resource (error = %1).
		ErrorCodeName{"ERROR_EVT_INVALID_PUBLISHER_NAME", ERROR_EVT_INVALID_PUBLISHER_NAME},  //! The specified publisher name is invalid.
		ErrorCodeName{"ERROR_EVT_INVALID_EVENT_DATA", ERROR_EVT_INVALID_EVENT_DATA},  //! The event data raised by the publisher is not compatible with the event template definition in the publisher's manifest.
		ErrorCodeName{"ERROR_EVT_CHANNEL_NOT_FOUND", ERROR_EVT_CHANNEL_NOT_FOUND},  //! The specified channel could not be found. Check channel configuration.
		ErrorCodeName{"ERROR_EVT_MALFORMED_XML_TEXT", ERROR_EVT_MALFORMED_XML_TEXT},  //! The specified xml text was not well-formed. See Extended Error for more details.
		ErrorCodeName{"ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL", ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL},  //! The caller is trying to subscribe to a direct channel which is not allowed. The events for a direct channel go directly to a logfile and cannot be subscribed to.
		ErrorCodeName{"ERROR_EVT_CONFIGURATION_ERROR", ERROR_EVT_CONFIGURATION_ERROR},  //! Configuration error.
		ErrorCodeName{"ERROR_EVT_QUERY_RESULT_STALE", ERROR_EVT_QUERY_RESULT_STALE},  //! The query result is stale / invalid. This may be due to the log being cleared or rolling over after the query result was created. Users should handle this code by releasing the query result object and reissuing the query.
		ErrorCodeName{"ERROR_EVT_QUERY_RESULT_INVALID_POSITION", ERROR_EVT_QUERY_RESULT_INVALID_POSITION},  //! Query result is currently at an invalid position.
		ErrorCodeName{"ERROR_EVT_NON_VALIDATING_MSXML", ERROR_EVT_NON_VALIDATING_MSXML},  //! Registered MSXML doesn't support validation.
		ErrorCodeName{"ERROR_EVT_FILTER_ALREADYSCOPED", ERROR_EVT_FILTER_ALREADYSCOPED},  //! An expression can only be followed by a change of scope operation if it itself evaluates to a node set and is not already part of some other change of scope operation.
		ErrorCodeName{"ERROR_EVT_FILTER_NOTELTSET", ERROR_EVT_FILTER_NOTELTSET},  //! Can't perform a step operation from a term that does not represent an element set.
		ErrorCodeName{"ERROR_EVT_FILTER_INVARG", ERROR_EVT_FILTER_INVARG},  //! Left hand side arguments to binary operators must be either attributes, nodes or variables and right hand side arguments must be constants.
		ErrorCodeName{"ERROR_EVT_FILTER_INVTEST", ERROR_EVT_FILTER_INVTEST},  //! A step operation must involve either a node test or, in the case of a predicate, an algebraic expression against which to test each node in the node set identified by the preceding node set can be evaluated.
		ErrorCodeName{"ERROR_EVT_FILTER_INVTYPE", ERROR_EVT_FILTER_INVTYPE},  //! This data type is currently unsupported.
		ErrorCodeName{"ERROR_EVT_FILTER_PARSEERR", ERROR_EVT_FILTER_PARSEERR},  //! A syntax error occurred at position %1!d!.
		ErrorCodeName{"ERROR_EVT_FILTER_UNSUPPORTEDOP", ERROR_EVT_FILTER_UNSUPPORTEDOP},  //! This operator is unsupported by this implementation of the filter.
		ErrorCodeName{"ERROR_EVT_FILTER_UNEXPECTEDTOKEN", ERROR_EVT_FILTER_UNEXPECTEDTOKEN},  //! The token encountered was unexpected.
		ErrorCodeName{"ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL", ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL},  //! The requested operation cannot be performed over an enabled direct channel. The channel must first be disabled before performing the requested operation.
		ErrorCodeName{"ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE", ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE},  //! Channel property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of channel.
		ErrorCodeName{"ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE", ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE},  //! Publisher property %1!s! contains invalid value. The value has invalid type, is outside of valid range, can't be updated or is not supported by this type of publisher.
		ErrorCodeName{"ERROR_EVT_CHANNEL_CANNOT_ACTIVATE", ERROR_EVT_CHANNEL_CANNOT_ACTIVATE},  //! The channel fails to activate.
		ErrorCodeName{"ERROR_EVT_FILTER_TOO_COMPLEX", ERROR_EVT_FILTER_TOO_COMPLEX},  //! The xpath expression exceeded supported complexity. Please symplify it or split it into two or more simple expressions.
		ErrorCodeName{"ERROR_EVT_MESSAGE_NOT_FOUND", ERROR_EVT_MESSAGE_NOT_FOUND},  //! the message resource is present but the message is not found in the string/message table.
		ErrorCodeName{"ERROR_EVT_MESSAGE_ID_NOT_FOUND", ERROR_EVT_MESSAGE_ID_NOT_FOUND},  //! The message id for the desired message could not be found.
		ErrorCodeName{"ERROR_EVT_UNRESOLVED_VALUE_INSERT", ERROR_EVT_UNRESOLVED_VALUE_INSERT},  //! The substitution string for insert index (%1) could not be found.
		ErrorCodeName{"ERROR_EVT_UNRESOLVED_PARAMETER_INSERT", ERROR_EVT_UNRESOLVED_PARAMETER_INSERT},  //! The description string for parameter reference (%1) could not be found.
		ErrorCodeName{"ERROR_EVT_MAX_INSERTS_REACHED", ERROR_EVT_MAX_INSERTS_REACHED},  //! The maximum number of replacements has been reached.
		ErrorCodeName{"ERROR_EVT_EVENT_DEFINITION_NOT_FOUND", ERROR_EVT_EVENT_DEFINITION_NOT_FOUND},  //! The event definition could not be found for event id (%1).
		ErrorCodeName{"ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND", ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND},  //! The locale specific resource for the desired message is not present.
		ErrorCodeName{"ERROR_EVT_VERSION_TOO_OLD", ERROR_EVT_VERSION_TOO_OLD},  //! The resource is too old to be compatible.
		ErrorCodeName{"ERROR_EVT_VERSION_TOO_NEW", ERROR_EVT_VERSION_TOO_NEW},  //! The resource is too new to be compatible.
		ErrorCodeName{"ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY", ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY},  //! The channel at index %1!d! of the query can't be opened.
		ErrorCodeName{"ERROR_EVT_PUBLISHER_DISABLED", ERROR_EVT_PUBLISHER_DISABLED},  //! The publisher has been disabled and its resource is not available. This usually occurs when the publisher is in the process of being uninstalled or upgraded.
		ErrorCodeName{"ERROR_EVT_FILTER_OUT_OF_RANGE", ERROR_EVT_FILTER_OUT_OF_RANGE},  //! Attempted to create a numeric type that is outside of its valid range.
		ErrorCodeName{"ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE", ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE},  //! The subscription fails to activate.
		ErrorCodeName{"ERROR_EC_LOG_DISABLED", ERROR_EC_LOG_DISABLED},  //! The log of the subscription is in disabled state, and cannot be used to forward events to. The log must first be enabled before the subscription can be activated.
		ErrorCodeName{"ERROR_EC_CIRCULAR_FORWARDING", ERROR_EC_CIRCULAR_FORWARDING},  //! When forwarding events from local machine to itself, the query of the subscription can't contain target log of the subscription.
		ErrorCodeName{"ERROR_EC_CREDSTORE_FULL", ERROR_EC_CREDSTORE_FULL},  //! The credential store that is used to save credentials is full.
		ErrorCodeName{"ERROR_EC_CRED_NOT_FOUND", ERROR_EC_CRED_NOT_FOUND},  //! The credential used by this subscription can't be found in credential store.
		ErrorCodeName{"ERROR_EC_NO_ACTIVE_CHANNEL", ERROR_EC_NO_ACTIVE_CHANNEL},  //! No active channel is found for the query.
		ErrorCodeName{"ERROR_MUI_FILE_NOT_FOUND", ERROR_MUI_FILE_NOT_FOUND},  //! The resource loader failed to find MUI file.
		ErrorCodeName{"ERROR_MUI_INVALID_FILE", ERROR_MUI_INVALID_FILE},  //! The resource loader failed to load MUI file because the file fail to pass validation.
		ErrorCodeName{"ERROR_MUI_INVALID_RC_CONFIG", ERROR_MUI_INVALID_RC_CONFIG},  //! The RC Manifest is corrupted with garbage data or unsupported version or missing required item.
		ErrorCodeName{"ERROR_MUI_INVALID_LOCALE_NAME", ERROR_MUI_INVALID_LOCALE_NAME},  //! The RC Manifest has invalid culture name.
		ErrorCodeName{"ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME", ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME},  //! The RC Manifest has invalid ultimatefallback name.
		ErrorCodeName{"ERROR_MUI_FILE_NOT_LOADED", ERROR_MUI_FILE_NOT_LOADED},  //! The resource loader cache doesn't have loaded MUI entry.
		ErrorCodeName{"ERROR_RESOURCE_ENUM_USER_STOP", ERROR_RESOURCE_ENUM_USER_STOP},  //! User stopped resource enumeration.
		ErrorCodeName{"ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED", ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED},  //! UI language installation failed.
		ErrorCodeName{"ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME", ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME},  //! Locale installation failed.
		ErrorCodeName{"ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE", ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE},  //! A resource does not have default or neutral value.
		ErrorCodeName{"ERROR_MRM_INVALID_PRICONFIG", ERROR_MRM_INVALID_PRICONFIG},  //! Invalid PRI config file.
		ErrorCodeName{"ERROR_MRM_INVALID_FILE_TYPE", ERROR_MRM_INVALID_FILE_TYPE},  //! Invalid file type.
		ErrorCodeName{"ERROR_MRM_UNKNOWN_QUALIFIER", ERROR_MRM_UNKNOWN_QUALIFIER},  //! Unknown qualifier.
		ErrorCodeName{"ERROR_MRM_INVALID_QUALIFIER_VALUE", ERROR_MRM_INVALID_QUALIFIER_VALUE},  //! Invalid qualifier value.
		ErrorCodeName{"ERROR_MRM_NO_CANDIDATE", ERROR_MRM_NO_CANDIDATE},  //! No Candidate found.
		ErrorCodeName{"ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE", ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE},  //! The ResourceMap or NamedResource has an item that does not have default or neutral resource..
		ErrorCodeName{"ERROR_MRM_RESOURCE_TYPE_MISMATCH", ERROR_MRM_RESOURCE_TYPE_MISMATCH},  //! Invalid ResourceCandidate type.
		ErrorCodeName{"ERROR_MRM_DUPLICATE_MAP_NAME", ERROR_MRM_DUPLICATE_MAP_NAME},  //! Duplicate Resource Map.
		ErrorCodeName{"ERROR_MRM_DUPLICATE_ENTRY", ERROR_MRM_DUPLICATE_ENTRY},  //! Duplicate Entry.
		ErrorCodeName{"ERROR_MRM_INVALID_RESOURCE_IDENTIFIER", ERROR_MRM_INVALID_RESOURCE_IDENTIFIER},  //! Invalid Resource Identifier.
		ErrorCodeName{"ERROR_MRM_FILEPATH_TOO_LONG", ERROR_MRM_FILEPATH_TOO_LONG},  //! Filepath too long.
		ErrorCodeName{"ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE", ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE},  //! Unsupported directory type.
		ErrorCodeName{"ERROR_MRM_INVALID_PRI_FILE", ERROR_MRM_INVALID_PRI_FILE},  //! Invalid PRI File.
		ErrorCodeName{"ERROR_MRM_NAMED_RESOURCE_NOT_FOUND", ERROR_MRM_NAMED_RESOURCE_NOT_FOUND},  //! NamedResource Not Found.
		ErrorCodeName{"ERROR_MRM_MAP_NOT_FOUND", ERROR_MRM_MAP_NOT_FOUND},  //! ResourceMap Not Found.
		ErrorCodeName{"ERROR_MRM_UNSUPPORTED_PROFILE_TYPE", ERROR_MRM_UNSUPPORTED_PROFILE_TYPE},  //! Unsupported MRT profile type.
		ErrorCodeName{"ERROR_MRM_INVALID_QUALIFIER_OPERATOR", ERROR_MRM_INVALID_QUALIFIER_OPERATOR},  //! Invalid qualifier operator.
		ErrorCodeName{"ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE", ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE},  //! Unable to determine qualifier value or qualifier value has not been set.
		ErrorCodeName{"ERROR_MRM_AUTOMERGE_ENABLED", ERROR_MRM_AUTOMERGE_ENABLED},  //! Automerge is enabled in the PRI file.
		ErrorCodeName{"ERROR_MRM_TOO_MANY_RESOURCES", ERROR_MRM_TOO_MANY_RESOURCES},  //! Too many resources defined for package.
		ErrorCodeName{"ERROR_MCA_INVALID_CAPABILITIES_STRING", ERROR_MCA_INVALID_CAPABILITIES_STRING},  //! The monitor returned a DDC/CI capabilities string that did not comply with the ACCESS.bus 3.0, DDC/CI 1.1 or MCCS 2 Revision 1 specification.
		ErrorCodeName{"ERROR_MCA_INVALID_VCP_VERSION", ERROR_MCA_INVALID_VCP_VERSION},  //! The monitor's VCP Version (0xDF) VCP code returned an invalid version value.
		ErrorCodeName{"ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION", ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION},  //! The monitor does not comply with the MCCS specification it claims to support.
		ErrorCodeName{"ERROR_MCA_MCCS_VERSION_MISMATCH", ERROR_MCA_MCCS_VERSION_MISMATCH},  //! The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.
		ErrorCodeName{"ERROR_MCA_UNSUPPORTED_MCCS_VERSION", ERROR_MCA_UNSUPPORTED_MCCS_VERSION},  //! The Monitor Configuration API only works with monitors that support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.
		ErrorCodeName{"ERROR_MCA_INTERNAL_ERROR", ERROR_MCA_INTERNAL_ERROR},  //! An internal Monitor Configuration API error occurred.
		ErrorCodeName{"ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED", ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED},  //! The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
		ErrorCodeName{"ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE", ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE},  //! The caller of SetMonitorColorTemperature specified a color temperature that the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
		ErrorCodeName{"ERROR_AMBIGUOUS_SYSTEM_DEVICE", ERROR_AMBIGUOUS_SYSTEM_DEVICE},  //! The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria.
		ErrorCodeName{"ERROR_SYSTEM_DEVICE_NOT_FOUND", ERROR_SYSTEM_DEVICE_NOT_FOUND},  //! The requested system device cannot be found.
		ErrorCodeName{"ERROR_HASH_NOT_SUPPORTED", ERROR_HASH_NOT_SUPPORTED},  //! Hash generation for the specified hash version and hash type is not enabled on the server.
		ErrorCodeName{"ERROR_HASH_NOT_PRESENT", ERROR_HASH_NOT_PRESENT},  //! The hash requested from the server is not available or no longer valid.
		ErrorCodeName{"ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED", ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED},  //! The secondary interrupt controller instance that manages the specified interrupt is not registered.
		ErrorCodeName{"ERROR_GPIO_CLIENT_INFORMATION_INVALID", ERROR_GPIO_CLIENT_INFORMATION_INVALID},  //! The information supplied by the GPIO client driver is invalid.
		ErrorCodeName{"ERROR_GPIO_VERSION_NOT_SUPPORTED", ERROR_GPIO_VERSION_NOT_SUPPORTED},  //! The version specified by the GPIO client driver is not supported.
		ErrorCodeName{"ERROR_GPIO_INVALID_REGISTRATION_PACKET", ERROR_GPIO_INVALID_REGISTRATION_PACKET},  //! The registration packet supplied by the GPIO client driver is not valid.
		ErrorCodeName{"ERROR_GPIO_OPERATION_DENIED", ERROR_GPIO_OPERATION_DENIED},  //! The requested operation is not supported for the specified handle.
		ErrorCodeName{"ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE", ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE},  //! The requested connect mode conflicts with an existing mode on one or more of the specified pins.
		ErrorCodeName{"ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED", ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED},  //! The interrupt requested to be unmasked is not masked.
		ErrorCodeName{"ERROR_CANNOT_SWITCH_RUNLEVEL", ERROR_CANNOT_SWITCH_RUNLEVEL},  //! The requested run level switch cannot be completed successfully.
		ErrorCodeName{"ERROR_INVALID_RUNLEVEL_SETTING", ERROR_INVALID_RUNLEVEL_SETTING},  //! The service has an invalid run level setting. The run level for a service must not be higher than the run level of its dependent services.
		ErrorCodeName{"ERROR_RUNLEVEL_SWITCH_TIMEOUT", ERROR_RUNLEVEL_SWITCH_TIMEOUT},  //! The requested run level switch cannot be completed successfully since one or more services will not stop or restart within the specified timeout.
		ErrorCodeName{"ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT", ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT},  //! A run level switch agent did not respond within the specified timeout.
		ErrorCodeName{"ERROR_RUNLEVEL_SWITCH_IN_PROGRESS", ERROR_RUNLEVEL_SWITCH_IN_PROGRESS},  //! A run level switch is currently in progress.
		ErrorCodeName{"ERROR_SERVICES_FAILED_AUTOSTART", ERROR_SERVICES_FAILED_AUTOSTART},  //! One or more services failed to start during the service startup phase of a run level switch.
		ErrorCodeName{"ERROR_COM_TASK_STOP_PENDING", ERROR_COM_TASK_STOP_PENDING},  //! The task stop request cannot be completed immediately since task needs more time to shutdown.
		ErrorCodeName{"ERROR_INSTALL_OPEN_PACKAGE_FAILED", ERROR_INSTALL_OPEN_PACKAGE_FAILED},  //! Package could not be opened.
		ErrorCodeName{"ERROR_INSTALL_PACKAGE_NOT_FOUND", ERROR_INSTALL_PACKAGE_NOT_FOUND},  //! Package was not found.
		ErrorCodeName{"ERROR_INSTALL_INVALID_PACKAGE", ERROR_INSTALL_INVALID_PACKAGE},  //! Package data is invalid.
		ErrorCodeName{"ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED", ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED},  //! Package failed updates, dependency or conflict validation.
		ErrorCodeName{"ERROR_INSTALL_OUT_OF_DISK_SPACE", ERROR_INSTALL_OUT_OF_DISK_SPACE},  //! There is not enough disk space on your computer. Please free up some space and try again.
		ErrorCodeName{"ERROR_INSTALL_NETWORK_FAILURE", ERROR_INSTALL_NETWORK_FAILURE},  //! There was a problem downloading your product.
		ErrorCodeName{"ERROR_INSTALL_REGISTRATION_FAILURE", ERROR_INSTALL_REGISTRATION_FAILURE},  //! Package could not be registered.
		ErrorCodeName{"ERROR_INSTALL_DEREGISTRATION_FAILURE", ERROR_INSTALL_DEREGISTRATION_FAILURE},  //! Package could not be unregistered.
		ErrorCodeName{"ERROR_INSTALL_CANCEL", ERROR_INSTALL_CANCEL},  //! User cancelled the install request.
		ErrorCodeName{"ERROR_INSTALL_FAILED", ERROR_INSTALL_FAILED},  //! Install failed. Please contact your software vendor.
		ErrorCodeName{"ERROR_REMOVE_FAILED", ERROR_REMOVE_FAILED},  //! Removal failed. Please contact your software vendor.
		ErrorCodeName{"ERROR_PACKAGE_ALREADY_EXISTS", ERROR_PACKAGE_ALREADY_EXISTS},  //! The provided package is already installed, and reinstallation of the package was blocked. Check the AppXDeployment-Server event log for details.
		ErrorCodeName{"ERROR_NEEDS_REMEDIATION", ERROR_NEEDS_REMEDIATION},  //! The application cannot be started. Try reinstalling the application to fix the problem.
		ErrorCodeName{"ERROR_INSTALL_PREREQUISITE_FAILED", ERROR_INSTALL_PREREQUISITE_FAILED},  //! A Prerequisite for an install could not be satisfied.
		ErrorCodeName{"ERROR_PACKAGE_REPOSITORY_CORRUPTED", ERROR_PACKAGE_REPOSITORY_CORRUPTED},  //! The package repository is corrupted.
		ErrorCodeName{"ERROR_INSTALL_POLICY_FAILURE", ERROR_INSTALL_POLICY_FAILURE},  //! To install this application you need either a Windows developer license or a sideloading-enabled system.
		ErrorCodeName{"ERROR_PACKAGE_UPDATING", ERROR_PACKAGE_UPDATING},  //! The application cannot be started because it is currently updating.
		ErrorCodeName{"ERROR_DEPLOYMENT_BLOCKED_BY_POLICY", ERROR_DEPLOYMENT_BLOCKED_BY_POLICY},  //! The package deployment operation is blocked by policy. Please contact your system administrator.
		ErrorCodeName{"ERROR_PACKAGES_IN_USE", ERROR_PACKAGES_IN_USE},  //! The package could not be installed because resources it modifies are currently in use.
		ErrorCodeName{"ERROR_RECOVERY_FILE_CORRUPT", ERROR_RECOVERY_FILE_CORRUPT},  //! The package could not be recovered because necessary data for recovery have been corrupted.
		ErrorCodeName{"ERROR_INVALID_STAGED_SIGNATURE", ERROR_INVALID_STAGED_SIGNATURE},  //! The signature is invalid. To register in developer mode, AppxSignature.p7x and AppxBlockMap.xml must be valid or should not be present.
		ErrorCodeName{"ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED", ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED},  //! An error occurred while deleting the package's previously existing application data.
		ErrorCodeName{"ERROR_INSTALL_PACKAGE_DOWNGRADE", ERROR_INSTALL_PACKAGE_DOWNGRADE},  //! The package could not be installed because a higher version of this package is already installed.
		ErrorCodeName{"ERROR_SYSTEM_NEEDS_REMEDIATION", ERROR_SYSTEM_NEEDS_REMEDIATION},  //! An error in a system binary was detected. Try refreshing the PC to fix the problem.
		ErrorCodeName{"ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN", ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN},  //! A corrupted CLR NGEN binary was detected on the system.
		ErrorCodeName{"ERROR_RESILIENCY_FILE_CORRUPT", ERROR_RESILIENCY_FILE_CORRUPT},  //! The operation could not be resumed because necessary data for recovery have been corrupted.
		ErrorCodeName{"ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING", ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING},  //! The package could not be installed because the Windows Firewall service is not running. Enable the Windows Firewall service and try again.
		ErrorCodeName{"APPMODEL_ERROR_NO_PACKAGE", APPMODEL_ERROR_NO_PACKAGE},  //! The process has no package identity.
		ErrorCodeName{"APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT", APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT},  //! The package runtime information is corrupted.
		ErrorCodeName{"APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT", APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT},  //! The package identity is corrupted.
		ErrorCodeName{"APPMODEL_ERROR_NO_APPLICATION", APPMODEL_ERROR_NO_APPLICATION},  //! The process has no application identity.
		ErrorCodeName{"ERROR_STATE_LOAD_STORE_FAILED", ERROR_STATE_LOAD_STORE_FAILED},  //! Loading the state store failed.
		ErrorCodeName{"ERROR_STATE_GET_VERSION_FAILED", ERROR_STATE_GET_VERSION_FAILED},  //! Retrieving the state version for the application failed.
		ErrorCodeName{"ERROR_STATE_SET_VERSION_FAILED", ERROR_STATE_SET_VERSION_FAILED},  //! Setting the state version for the application failed.
		ErrorCodeName{"ERROR_STATE_STRUCTURED_RESET_FAILED", ERROR_STATE_STRUCTURED_RESET_FAILED},  //! Resetting the structured state of the application failed.
		ErrorCodeName{"ERROR_STATE_OPEN_CONTAINER_FAILED", ERROR_STATE_OPEN_CONTAINER_FAILED},  //! State Manager failed to open the container.
		ErrorCodeName{"ERROR_STATE_CREATE_CONTAINER_FAILED", ERROR_STATE_CREATE_CONTAINER_FAILED},  //! State Manager failed to create the container.
		ErrorCodeName{"ERROR_STATE_DELETE_CONTAINER_FAILED", ERROR_STATE_DELETE_CONTAINER_FAILED},  //! State Manager failed to delete the container.
		ErrorCodeName{"ERROR_STATE_READ_SETTING_FAILED", ERROR_STATE_READ_SETTING_FAILED},  //! State Manager failed to read the setting.
		ErrorCodeName{"ERROR_STATE_WRITE_SETTING_FAILED", ERROR_STATE_WRITE_SETTING_FAILED},  //! State Manager failed to write the setting.
		ErrorCodeName{"ERROR_STATE_DELETE_SETTING_FAILED", ERROR_STATE_DELETE_SETTING_FAILED},  //! State Manager failed to delete the setting.
		ErrorCodeName{"ERROR_STATE_QUERY_SETTING_FAILED", ERROR_STATE_QUERY_SETTING_FAILED},  //! State Manager failed to query the setting.
		ErrorCodeName{"ERROR_STATE_READ_COMPOSITE_SETTING_FAILED", ERROR_STATE_READ_COMPOSITE_SETTING_FAILED},  //! State Manager failed to read the composite setting.
		ErrorCodeName{"ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED", ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED},  //! State Manager failed to write the composite setting.
		ErrorCodeName{"ERROR_STATE_ENUMERATE_CONTAINER_FAILED", ERROR_STATE_ENUMERATE_CONTAINER_FAILED},  //! State Manager failed to enumerate the containers.
		ErrorCodeName{"ERROR_STATE_ENUMERATE_SETTINGS_FAILED", ERROR_STATE_ENUMERATE_SETTINGS_FAILED},  //! State Manager failed to enumerate the settings.
		ErrorCodeName{"ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED", ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED},  //! The size of the state manager composite setting value has exceeded the limit.
		ErrorCodeName{"ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED", ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED},  //! The size of the state manager setting value has exceeded the limit.
		ErrorCodeName{"ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED", ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED},  //! The length of the state manager setting name has exceeded the limit.
		ErrorCodeName{"ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED", ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED},  //! The length of the state manager container name has exceeded the limit.
#pragma endregion
		ErrorCodeName{"ERROR_API_UNAVAILABLE", ERROR_API_UNAVAILABLE},  //! This API cannot be used in the context of the caller's application type.
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o