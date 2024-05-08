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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "win/SharedHandle.h"
#include "nstd/TypeTraits.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	enum class LoadLibraryFlags : DWORD {
		None                  = 0,
		DontResolveReferences = DONT_RESOLVE_DLL_REFERENCES,         //!< System does not call DllMain for process and thread initialization and termination or load additional executable modules.
		IgnoreCodeAuthzLevel  = LOAD_IGNORE_CODE_AUTHZ_LEVEL,        //!< System does not check AppLocker rules or apply Software Restriction Policies.
		AsDatafile            = LOAD_LIBRARY_AS_DATAFILE,            //!< System maps the file into the calling process's virtual address space as if it were a data file.
		AsDatafileExclusive   = LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE,  //!< Similar to LOAD_LIBRARY_AS_DATAFILE, except that the DLL file is opened with exclusive write access for the calling process.
		AsImageResource       = LOAD_LIBRARY_AS_IMAGE_RESOURCE,      //!< System maps the file into the process's virtual address space as an image file.
		SearchApplicationDir  = LOAD_LIBRARY_SEARCH_APPLICATION_DIR, //!< Application's installation directory is searched for the DLL and its dependencies.
		SearchDefaultDirs     = LOAD_LIBRARY_SEARCH_DEFAULT_DIRS,    //!< This value is a combination of LOAD_LIBRARY_SEARCH_APPLICATION_DIR, LOAD_LIBRARY_SEARCH_SYSTEM32, and LOAD_LIBRARY_SEARCH_USER_DIRS.
		SearchDllLoadDir      = LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR,    //!< Directory that contains the DLL is temporarily added to the beginning of the list of directories that are searched for dependencies.
		SearchSystem32        = LOAD_LIBRARY_SEARCH_SYSTEM32,        //!< %windows%\system32 is searched for the DLL and its dependencies.
		SearchUserDirs        = LOAD_LIBRARY_SEARCH_USER_DIRS,       //!< Directories added using the AddDllDirectory or the SetDllDirectory function are searched for the DLL and its dependencies.
		AlteredSearchPath     = LOAD_WITH_ALTERED_SEARCH_PATH,       //!< System uses the alternate file search strategy discussed in the Remarks section
		RequireSignedTarget   = LOAD_LIBRARY_REQUIRE_SIGNED_TARGET,  //!< Specifies that the digital signature of the binary image must be checked at load time.
		SafeCurrentDirs       = LOAD_LIBRARY_SAFE_CURRENT_DIRS,      //!< Loading a DLL for execution from the current directory is only allowed if it is under a directory in the Safe load list.
	};
}

//! @brief	@c core::win::LoadLibraryFlags is a bitflag
metadata bool core::meta::Settings<core::bitwise_enum, core::win::LoadLibraryFlags> = true;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Dynamic library loaded into current process
	*/
	class SharedLibrary
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		using enum LoadLibraryFlags;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedModule  Handle;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		SharedLibrary(filesystem::path path, LoadLibraryFlags flags = LoadLibraryFlags::None) 
		  : Handle{::LoadLibraryExW(ThrowIfEmpty(path).native().c_str(), nullptr, std::to_underlying(flags))}
		{
			if (!this->Handle)
				LastError{}.throwAlways("LoadLibraryExW() failed");
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(SharedLibrary,
			NotDefaultConstructible,
			IsCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		SharedModule
		handle() const noexcept {
			return this->Handle;
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		template <nstd::Function Signature, size_t NumResultParameters = 0>
		auto
		loadFunction(std::string_view name) const
		{
			using proc_signature_t = nstd::add_function_pointer_t<Signature>;
			if (auto* const pfx = reinterpret_cast<proc_signature_t>(::GetProcAddress(*this->Handle, name.data())); !pfx)
				LastError{}.throwAlways("GetProcAddress() failed");
			else
				return pfx;
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o