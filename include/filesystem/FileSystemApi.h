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
#include "filesystem/FileAttribute.h"
#include "filesystem/FileSize.h"
#include "filesystem/FileShare.h"
#include "filesystem/SearchResult.h"
#include "filesystem/SharedHandle.h"
#include "filesystem/VolumeProperties.h"
#include "filesystem/VolumeSpace.h"
#include "security/FileRight.h"
#include "security/StandardRights.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem
{
	class FileSystemApi 
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Flags controlling behaviour of @c createFile() method
		enum CreateBehaviour
		{
			CreateAlways	 = CREATE_ALWAYS,       //!< Creates a new file, always.
			CreateNew		 = CREATE_NEW,			//!< Creates a new file, only if it does not already exist.
			OpenAlways		 = OPEN_ALWAYS,			//!< Opens a file, always.
			OpenExisting	 = OPEN_EXISTING,       //!< Opens a file or device, only if it exists.
			TruncateExisting = TRUNCATE_EXISTING    //!< Opens a file and truncates it to zero bytes, only if it exists.
		};

		//! @brief	Flags controlling behaviour of @c copyFile() method
		enum CopyBehaviour
		{
			OverwriteExisting,      //!< Overwrite destination file, if it exists
			FailIfExists            //!< Fail if destination exists
		};
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Creates or opens a file or I/O device
		*
		* @param[in] file       Name of the file or device to be created or opened
		* @param[in] mode       Action to take when file/device exists (or does not exist)
		* @param[in] rights     [optional] Requested access for (the handle to) the file/device
		* @param[in] sharing    [optional] Requested sharing mode of the file or device
		* @param[in] attributes [optional] File/device attributes
		*
		* @returns  Valid file handle
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] SharedFile
		virtual createFile(path                         file,
		                   CreateBehaviour              mode,
		                   nstd::bitset<win::FileRight> rights = win::StandardRight::Read,
		                   std::optional<FileShare>     sharing = std::nullopt,
		                   std::optional<FileAttribute> attributes = std::nullopt) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Copies an existing file to a new file
		*
		* @param[in] source       Source path
		* @param[in] destination  Destination path
		* @param[in] overwrite    Whether to overwrite if @p destination already exists
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual copyFile(path source, path destination, CopyBehaviour overwrite) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Deletes an existing file
		*
		* @param[in]  file  Path of file to delete
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual deleteFile(path file) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Searches a directory for a file (or subdirectory) with a name that matches a specific name
		*
		* @param[in]   folder   Directory to search
		* @param[in]   pattern  Search filter @e without trailing backslash (* and ? wildcards supported)
		* @param[out]  result   Structure which receives information about a found file or directory
		*
		* @returns  Valid search handle if result was returned, otherwise empty search handle
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] SharedFileSearch
		virtual findFirstFile(path folder, path pattern, SearchResult& result) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Continues a file search from a previous call to the @c findFirstFile()
		*
		* @param[in]   search   Search handle returned by a previous call to the @c findFirstFile()
		* @param[out]  result   Structure which receives information about a found file or directory
		*
		* @returns  @c true if result was returned; @c false if search exhausted
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] bool
		virtual findNextFile(SharedFileSearch search, SearchResult& result) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Searches for volumes
		*
		* @param[out]  guid   Volume GUID path of the first volume to be found
		*
		* @returns  Valid search handle if result was returned, otherwise empty search handle
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] SharedVolumeSearch
		virtual findFirstVolume(std::wstring& guid) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Continues a volume search started by a call to the @c findFirstVolume()
		*
		* @param[in]   search  Valid volume search handle returned by a previous call to the @c findFirstVolume()
		* @param[out]  guid    Volume GUID path of the returned volume
		*
		* @returns  @c true if result was returned; @c false if search exhausted
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] bool
		virtual findNextVolume(SharedVolumeSearch search, std::wstring& guid) const abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves file system attributes for a specified file or directory.
		*
		* @param[in]  file   Path of the file/directory
		*
		* @returns  File/folder attributes
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] FileAttribute
		virtual getFileAttributes(path file) const abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Query whether a file/directory exists
		*
		* @param[in]  path   Path of the file/directory
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] bool
		virtual getFileExists(path path) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves the date and time that a file or directory was created, last accessed, and last modified
		*
		* @param[in]    handle   Valid handle to the file or directory 
		*
		* @returns  Structure containing creation time, last-accessed time, and last-written time
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] FileTime
		virtual getFileTime(SharedFile handle) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves the size of the specified file
		*
		* @param[in]  handle   Valid file handle (with @c FileRight::ReadAttributes right)
		*
		* @returns  File size (in bytes)
		*
		* @throws  std::invalid_argument   Missing argument
		* @throws  std::system_error       @p handle is missing @c FileRight::ReadAttributes right
		* @throws  std::system_error       Operation failed
		*/
		[[nodiscard]] filesize_t
		virtual getFileSize(SharedFile handle) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves unique volume identifier path
		*
		* @param[in]  drive  Volume drive letter
		*
		* @returns  Volume GUID path of the form "\\?\Volume{GUID}\"
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] path
		virtual getVolumeGuid(path drive) const abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieve collection of volume (ie. logical drive) specifiers
		*
		* @returns  Collection of volume drive letters
		*
		* @throws  std::system_error  Operation failed
		*/
		[[nodiscard]] std::vector<path>
		virtual getVolumeLetters() const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves properties of a volume
		*
		* @param[in]  drive  Volume drive letter
		*
		* @returns  Volume properties
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] VolumeProperties
		virtual getVolumeProperties(path drive) const abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves the total capacity and free space of a volume
		*
		* @param[in]  drive  Volume drive letter
		*
		* @returns  Structure containing volume capacity and free space, in bytes
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] VolumeSpace
		virtual getVolumeSpace(path drive) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Moves an existing file or a directory, including its children
		*
		* @param[in]  source       Path of the source file/directory
		* @param[in]  destination  Path of the destination file/directory
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*
		* @remarks  The destination file/directory must not already exist
		*
		* @remarks  Directories can only be moved to destination upon the same drive 
		*/
		void
		virtual moveFile(path source, path destination) const abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Sets the attributes for a file or directory
		*
		* @param[in]  file        Name of the file whose attributes are to be set.
		* @param[in]  attributes  File attributes to set for the file.
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual setFileAttributes(path file, FileAttribute attributes) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Sets the label of a file system volume
		*
		* @param[in]  drive  Volume drive letter
		* @param[in]  label  New volume label
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::invalid_argument  Volume label exceeds maximum
		* @throws  std::system_error      Operation failed
		* 
		* @remarks  Maximum volume label length is 32 characters (or 11 characers on FAT16)
		*/
		void
		virtual setVolumeLabel(path drive, std::wstring label) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Reads data from the specified file or input/output (I/O) device
		*
		* @param[in]  handle  Handle to the file or device
		* @param[in]  count   Maximum number of bytes to be read
		*
		* @returns  Collection of bytes, possibly fewer than @p count
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] std::vector<std::byte>
		virtual readFile(SharedFile handle, std::uint32_t count) const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Writes data to the specified file or input/output (I/O) device.
		*
		* @param[in]  handle  Handle to the file or I/O device 
		* @param[in]  buffer  Buffer containing the data to be written 
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] void
		virtual writeFile(SharedFile handle, std::span<std::byte const> buffer) const abstract;
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o