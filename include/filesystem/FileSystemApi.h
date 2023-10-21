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
#pragma comment(lib, "shlwapi.lib")
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
#include "filesystem/FileAttribute.h"
#include "filesystem/FileSize.h"
#include "filesystem/FileShare.h"
#include "filesystem/Origin.h"
#include "filesystem/SearchResult.h"
#include "filesystem/SharedHandle.h"
#include "filesystem/VolumeProperties.h"
#include "filesystem/VolumeSpace.h"
#include "security/FileRight.h"
#include "security/StandardRights.h"
#include "win/ConstMultiStringIterator.h"
#include "win/ApiHelpers.h"
#include "win/Boolean.h"
#include "win/LResult.h"
#include "win/PackedInteger.h"
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
	public:
		satisfies(FileSystemApi, 
			constexpr IsRegular noexcept
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:		
		//! @brief  Convert Windows file-time to POSIX epoch
		//! @see  https://learn.microsoft.com/en-us/windows/win32/sysinfo/converting-a-time-t-value-to-a-file-time
		std::time_t 
		static toEpoch(::FILETIME const& ft) {
			win::PackedInteger<unsigned> const dateTime{ft.dwLowDateTime,ft.dwHighDateTime};
			return (dateTime.Whole / 10'000'000) - 11'644'473'600;
		};
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Create or open a file (or handle to I/O device)
		*
		* @param[in] file       Name of the file or device to be created or opened
		* @param[in] mode       Action to take when file/device exists (or does not exist)
		* @param[in] rights     [optional] Requested access for (the handle to) the file/device
		* @param[in] sharing    [optional] Requested sharing mode of the file or device
		* @param[in] attributes [optional] Attributes to apply upon creation
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
		                   nstd::bitset<FileShare>      sharing = FileShare::DenyAll,
		                   nstd::bitset<FileAttribute>  attributes = FileAttribute::None) const 
		{
			ThrowIfEmpty(file);

			if (::HANDLE handle = ::CreateFileW(file.c_str(),
												rights.value(),
												win::DWord{sharing.value()},
												win::Unsecured,
												win::DWord{mode},
												win::DWord{attributes.value()},
												nullptr); handle == INVALID_HANDLE_VALUE) 
				win::LastError{}.throwAlways("CreateFile() failed");
			else
				return SharedFile{handle};
		}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Copies an existing file to a new location
		*
		* @param[in] source       Source path
		* @param[in] destination  Destination path
		* @param[in] overwrite    Whether to overwrite if @p destination already exists
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual copyFile(path source, path destination, CopyBehaviour overwrite) const {
			ThrowIfEmpty(source);
			ThrowIfEmpty(destination);

			if (!::CopyFileW(source.c_str(), destination.c_str(), win::Boolean{overwrite == FailIfExists}))
				win::LastError{}.throwAlways("CopyFile() failed");
		}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Deletes an existing file
		*
		* @param[in]  file  Path of file to delete
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual deleteFile(path file) const {
			ThrowIfEmpty(file);

			// Attempt to delete file
			if (!::DeleteFileW(file.c_str())) 
				win::LastError{}.throwAlways("DeleteFile() failed");
		}

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
		virtual findFirstFile(path folder, path pattern, SearchResult& result) const {
			ThrowIfEmpty(folder);
			ThrowIfEmpty(pattern);

			::WIN32_FIND_DATAW raw{};
			if (::HANDLE h = ::FindFirstFileW((folder / pattern).c_str(), &raw); h != INVALID_HANDLE_VALUE) {
				// [SUCCESS] Return first result and query handle
				result = SearchResult{ 
					static_cast<FileAttribute>(raw.dwFileAttributes), 
					raw.cFileName, 
					folder,
					FileTime{
						DateTime{FileSystemApi::toEpoch(raw.ftCreationTime)},
						DateTime{FileSystemApi::toEpoch(raw.ftLastAccessTime)},
						DateTime{FileSystemApi::toEpoch(raw.ftLastWriteTime)}
					},
					win::PackedInteger<unsigned>{raw.nFileSizeLow,raw.nFileSizeHigh}.Whole
				};
				return SharedFileSearch{h};
			}
			// [NO-RESULTS] 
			else if (win::LastError err; err == ERROR_FILE_NOT_FOUND)
				return SharedFileSearch{};
			else
				err.throwAlways("FindFirstFile() failed");
		}

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
		virtual findNextFile(SharedFileSearch search, SearchResult& result) const {
			ThrowIfEmpty(search);

			// Continue file search
			::WIN32_FIND_DATAW raw{};
			if (::FindNextFileW(*search, &raw)) {
				// [SUCCESS] Convert search result data
				result.update(
					static_cast<FileAttribute>(raw.dwFileAttributes), 
					raw.cFileName, 
					FileTime{
						DateTime{FileSystemApi::toEpoch(raw.ftCreationTime)},
						DateTime{FileSystemApi::toEpoch(raw.ftLastAccessTime)},
						DateTime{FileSystemApi::toEpoch(raw.ftLastWriteTime)}
					},
					win::PackedInteger<unsigned>{raw.nFileSizeLow,raw.nFileSizeHigh}.Whole
				);
				return true;
			}
			// [EXHAUSTED] Return negative
			else if (win::LastError err; err == ERROR_NO_MORE_FILES)
				return false;
			else
				err.throwAlways("FindNextFile() failed");
		}

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
		virtual findFirstVolume(std::wstring& guid) const {
			wchar_t ident[128]{};
			if (::HANDLE handle = ::FindFirstVolumeW(ident, win::DWord{lengthof(ident)}); handle == INVALID_HANDLE_VALUE) 
				win::LastError{}.throwAlways("FindFirstVolume() failed");
			else {
				guid = ident;
				return SharedVolumeSearch{handle};
			}
		}

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
		virtual findNextVolume(SharedVolumeSearch search, std::wstring& guid) const {
			ThrowIfEmpty(search);
			
			// Continue volume search
			wchar_t ident[128]{};
			if (::FindNextVolumeW(*search, ident, win::DWord{lengthof(ident)})) {
				guid = ident;
				return true;
			}
			// [EXHAUSTED] Return negative
			else if (win::LastError err; err == ERROR_NO_MORE_FILES)
				return false;
			else
				err.throwAlways("FindNextVolume() failed");
		}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Flushes data and meta-data buffers from caches, if used
		*
		* @param[in]  file   Open handle to file
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		* 
		* @see  https://learn.microsoft.com/en-us/windows/win32/fileio/file-caching
		*/
		void
		virtual flushFileBuffers(SharedFile file) const {
			ThrowIfEmpty(file);
			if (!::FlushFileBuffers(*file))
				win::LastError{}.throwAlways("FlushFileBuffers() failed");
		}

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
		virtual getFileAttributes(path file) const {
			ThrowIfEmpty(file);

			if (::DWORD attr = ::GetFileAttributesW(file.c_str()); attr == INVALID_FILE_ATTRIBUTES) 
				win::LastError{}.throwAlways("GetFileAttributes() failed");
			else
				return static_cast<FileAttribute>(attr);
		}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Query whether a file/directory exists
		*
		* @param[in]  path   Path of the file/directory
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] bool
		virtual getFileExists(path path) const {
			ThrowIfEmpty(path);

			return ::PathFileExistsW(path.c_str()) != FALSE;
		}

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
		virtual getFileTime(SharedFile handle) const {
			ThrowIfEmpty(handle);

			// Query file access times
			::FILETIME creation{}, access{}, modification{};
			if (!::GetFileTime(*handle, &creation, &access, &modification)) 
				win::LastError{}.throwAlways("GetFileTime() failed");
			else
				return FileTime{
					DateTime(toEpoch(creation)), 
					DateTime(toEpoch(access)), 
					DateTime(toEpoch(modification))
				};
		}

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
		virtual getFileSize(SharedFile handle) const {
			ThrowIfEmpty(handle);

			::LARGE_INTEGER size{};
			if (!::GetFileSizeEx(*handle, &size)) 
				win::LastError{}.throwAlways("GetFileSizeEx() failed");
			else
				return static_cast<filesize_t>(size.QuadPart);
		}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieves unique volume identifier path
		*
		* @param[in]  drive  Volume mount point
		*
		* @returns  Volume GUID path of the form "\\?\Volume{GUID}\"
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] path
		virtual getVolumeGuid(path drive) const {
			ThrowIfEmpty(drive);

			wchar_t guid[64]{};
			if (!::GetVolumeNameForVolumeMountPointW(drive.c_str(), guid, win::DWord{lengthof(guid)})) 
				win::LastError{}.throwAlways("GetVolumeNameForVolumeMountPoint() failed");
			else
				return guid;
		}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieve collection of volume identifiers
		*
		* @returns  Collection of volume drive letters
		*
		* @throws  std::system_error  Operation failed
		*/
		[[nodiscard]] std::vector<path>
		virtual getVolumeLetters() const {
			wchar_t drives[256]{};
			if (!::GetLogicalDriveStringsW(win::DWord{lengthof(drives)}, drives)) 
				win::LastError{}.throwAlways("GetLogicalDriveStrings() failed");
			else
				return {win::ConstMultiStringIterator{drives}, win::ConstMultiStringIterator{}};
		}

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
		virtual getVolumeProperties(path drive) const {
			ThrowIfEmpty(drive);
			ThrowIfNot(drive, drive.native().ends_with('\\'));
			
			// Query volume properties
			::DWORD attributes{};
			wchar_t label[32]{};
			::DWORD maxFilename{};
			::DWORD serial{};
			wchar_t system[32]{};
			if (!::GetVolumeInformationW(drive.c_str(),
			                             label,
				                         win::DWord{lengthof(label)},
			                             &serial,
			                             &maxFilename,
			                             &attributes,
			                             system,
				                         win::DWord{lengthof(system)})) 
				win::LastError{}.throwAlways("GetVolumeInformation() failed");
			// Query drive category
			else if (::DWORD const category = ::GetDriveTypeW(drive.c_str()); category == DRIVE_UNKNOWN) 
				win::LastError{}.throwAlways("GetDriveType() failed");
			else 
				// [SUCCESS] Convert volume properties
				return VolumeProperties{static_cast<VolumeAttribute>(attributes),
										static_cast<DriveCategory>(category),
										label,
										std::to_string(serial),
										static_cast<std::uint32_t>(maxFilename),
										from_string<FileSystem>(core::narrow(system, CodePage::Latin1))};
		}
	
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
		virtual getVolumeSpace(path drive) const {
			ThrowIfEmpty(drive);

			// Attempt to query volume capacities
			::ULARGE_INTEGER free{}, total{}, user{};
			if (::GetDiskFreeSpaceExW(drive.c_str(), &user, &total, &free)) 
				win::LastError{}.throwAlways("GetDiskFreeSpaceEx() failed");
			else
				return VolumeSpace{total.QuadPart, (total.QuadPart - free.QuadPart), user.QuadPart};
		}

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
		virtual moveFile(path source, path destination) const {
			ThrowIfEmpty(source);
			ThrowIfEmpty(destination);

			if (!::MoveFileW(source.c_str(), destination.c_str())) 
				win::LastError{}.throwAlways("MoveFile() failed");
		}
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Sets the file length to the current position of the file pointer
		*
		* @param[in]  file   Open handle to file
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual setEndOfFile(SharedFile file) const {
			ThrowIfEmpty(file);
			if (!::SetEndOfFile(*file))
				win::LastError{}.throwAlways("SetEndOfFile() failed");
		}

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
		virtual setFileAttributes(path file, FileAttribute attributes) const {		
			ThrowIfEmpty(file);

			if (!::SetFileAttributesW(file.c_str(), std::to_underlying(attributes))) 
				win::LastError{}.throwAlways("SetFileAttributes() failed");
		}
		
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Moves the file pointer of a specified file
		*
		* @param[in]  file   Open handle to file
		* @param[in]  from   Start position of seek
		* @param[in]  n      Distance to move
		* 
		* @returns  Position after seek completed
		*
		* @throws  std::invalid_argument  Missing or invalid argument
		* @throws  std::system_error      Operation failed
		*/
		int64_t
		virtual setFilePointer(SharedFile file, Origin from, ptrdiff_t n) const {
			ThrowIfEmpty(file);
			ThrowIfUndefined(from);

			win::PackedInteger<signed> const distance{static_cast<int64_t>(n)};
			::LONG hoNewPos = distance.Split.High;
			if (::LONG const loNewPos = ::SetFilePointer(*file, distance.Split.Low, &hoNewPos, win::DWord{from}); loNewPos == INVALID_SET_FILE_POINTER)
				win::LastError{}.throwAlways("SetFilePointer() failed");
			else
				return win::PackedInteger<signed>(loNewPos, hoNewPos).Whole;
		}

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
		virtual setVolumeLabel(path drive, std::wstring label) const {
			ThrowIfEmpty(drive);
			ThrowIfOutOfRange(label.length(), 0u, 32u);

			if (!::SetVolumeLabelW(drive.c_str(), !label.empty() ? label.c_str() : nullptr)) 
				win::LastError{}.throwAlways("SetVolumeLabel() failed");
		}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Reads data from the specified file or input/output (I/O) device
		*
		* @param[in]  file    Handle to the file (or device)
		* @param[in]  count   Maximum number of bytes to be read
		*
		* @returns  Collection of bytes, possibly fewer than @p count
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] std::vector<std::byte>
		virtual readFile(SharedFile file, std::uint32_t count) const {		
			ThrowIfEmpty(file);
			ThrowIfZero(count);

			// Attempt to read data from handle
			std::vector<std::byte> buffer(count);
			if (::DWORD n{}; !::ReadFile(*file, buffer.data(), win::DWord{count}, &n, nullptr)) 
				win::LastError{}.throwAlways("ReadFile() failed");
			else if (n == 0)
				win::LastError{}.throwAlways("ReadFile() no data received");

			// [LESS] Truncate buffer before return
			else if (n != count)
				buffer.resize(n);

			return buffer;
		}

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Writes data to the specified file or input/output (I/O) device.
		*
		* @param[in]  file    Handle to the file (or I/O device)
		* @param[in]  buffer  Buffer containing the data to be written 
		*
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		[[nodiscard]] void
		virtual writeFile(SharedFile file, std::span<std::byte const> buffer) const {
			ThrowIfEmpty(file);
			ThrowIfEmpty(buffer);

			// Attempt to write data to handle
			if (::DWORD n{}; !::WriteFile(*file, buffer.data(), win::DWord{buffer.size()}, &n, nullptr))
				win::LastError{}.throwAlways("WriteFile() failed");
			else if (n < buffer.size())
				win::LastError{}.throwAlways("WriteFile() failed to write all data");
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
	
	using SharedFileSystemApi = std::shared_ptr<FileSystemApi>;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem
{
	SharedFileSystemApi
	inline filesystemApi() {
		return std::make_shared<FileSystemApi>();
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o