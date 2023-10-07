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
	//! @brief 	Attributes of file-system volumes
	enum class VolumeAttribute { 
		None,															 //!< None
		CasePreservedNames = FILE_CASE_PRESERVED_NAMES,                  //!< Supports preserved case of file names when it places a name on disk.
		CaseSensitiveSearch = FILE_CASE_SENSITIVE_SEARCH,                //!< Supports case-sensitive file names.
		DaxValue = FILE_DAX_VOLUME,                                      //!< Is a direct access (DAX) volume.
		FileCompression = FILE_FILE_COMPRESSION,                         //!< Supports file-based compression.
		NamedStreams = FILE_NAMED_STREAMS,                               //!< Supports named streams.
		PersistentAcls = FILE_PERSISTENT_ACLS,                           //!< Preserves and enforces access control lists (ACL)
		ReadOnly = FILE_READ_ONLY_VOLUME,                                //!< Is read-only.
		SingleSequentialWrite = FILE_SEQUENTIAL_WRITE_ONCE,              //!< Supports a single sequential write.
		SupportsEncryption = FILE_SUPPORTS_ENCRYPTION,                   //!< Supports the Encrypted File System (EFS).
		SupportsExtendedAttributes = FILE_SUPPORTS_EXTENDED_ATTRIBUTES,  //!< Supports extended attributes. 
		SupportsHardLinks = FILE_SUPPORTS_HARD_LINKS,                    //!< Supports hard links.
		SupportsObjectIds = FILE_SUPPORTS_OBJECT_IDS,                    //!< Supports object identifiers.
		SupportsOpenByFileId = FILE_SUPPORTS_OPEN_BY_FILE_ID,            //!< Supports open by FileID. 
		SupportsReparse_points = FILE_SUPPORTS_REPARSE_POINTS,           //!< Supports reparse points.
		SupportsSparseFiles = FILE_SUPPORTS_SPARSE_FILES,                //!< Supports sparse files.
		SupportsTransactions = FILE_SUPPORTS_TRANSACTIONS,               //!< Supports transactions. 
		SupportsUsnJournal = FILE_SUPPORTS_USN_JOURNAL,                  //!< Supports update sequence number (USN) journals
		UnicodeOnDisk = FILE_UNICODE_ON_DISK,                            //!< Supports Unicode in file names as they appear on disk.
		VolumeIsCompressed = FILE_VOLUME_IS_COMPRESSED,                  //!< Compressed volume (DoubleSpace, for example)
		VolumeQuotas = FILE_VOLUME_QUOTAS                                //!< Supports disk quotas. 
	};
} 

//! @brief	@c core::filesystem::VolumeAttribute is a bitflag
metadata bool core::meta::Settings<core::bitwise_enum, core::filesystem::VolumeAttribute> = true;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
