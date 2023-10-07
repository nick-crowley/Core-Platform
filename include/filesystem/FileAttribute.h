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
#pragma once
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem 
{	
	//! @brief 	Attributes of files and/or directories
	enum class FileAttribute { 
		None,
		Archive = FILE_ATTRIBUTE_ARCHIVE,							//!< File/directory has not been archived.
		Compressed = FILE_ATTRIBUTE_COMPRESSED,						//!< File/directory is compressed.
		Device = FILE_ATTRIBUTE_DEVICE,								//!< [Reserved]
		Directory = FILE_ATTRIBUTE_DIRECTORY,						//!< Handle identifies a directory.
		Encrypted = FILE_ATTRIBUTE_ENCRYPTED,						//!< File/directory is encrypted.
		Hidden = FILE_ATTRIBUTE_HIDDEN,								//!< File/directory is hidden.
		IntegrityStream = FILE_ATTRIBUTE_INTEGRITY_STREAM,			//!< Directory (or user data stream) is configured with integrity (only supported on ReFS volumes).
		Normal = FILE_ATTRIBUTE_NORMAL,								//!< File that does not have other attributes set.
		NotContentIndexed = FILE_ATTRIBUTE_NOT_CONTENT_INDEXED,		//!< File/directory is not to be indexed by the content indexing service.
		NoScrubData = FILE_ATTRIBUTE_NO_SCRUB_DATA,					//!< User data stream not to be read by the background data integrity scanner.
		Offline = FILE_ATTRIBUTE_OFFLINE,							//!< File data is not available immediately.
		ReadOnly = FILE_ATTRIBUTE_READONLY,							//!< File that is read-only.
		RecallOnDataAccess = FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS,	//!< File/directory is not fully present locally.
		RecallOnOpen = FILE_ATTRIBUTE_RECALL_ON_OPEN,				//!< This attribute only appears in directory enumeration classes.
		ReparsePoint = FILE_ATTRIBUTE_REPARSE_POINT,				//!< File/directory has an associated reparse point, or a file that is a symbolic link.
		SparseFile = FILE_ATTRIBUTE_SPARSE_FILE,					//!< File is a sparse file.
		System = FILE_ATTRIBUTE_SYSTEM,								//!< File/directory used by the operating system
		Temporary = FILE_ATTRIBUTE_TEMPORARY,						//!< File used for temporary storage.
		Virtual = FILE_ATTRIBUTE_VIRTUAL,							//!< [Reserved]
	};
} 

//! @brief	@c core::filesystem::FileAttribute is a bitflag
metadata bool core::meta::Settings<core::bitwise_enum, core::filesystem::FileAttribute> = true;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
