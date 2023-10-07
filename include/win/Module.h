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
#include "win/ResourceId.h"
#include "win/SharedHandle.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#ifdef CORE_BUILDING_DLL

//! @brief Expose the Microsoft linker pseudo-variable
extern "C"
::IMAGE_DOS_HEADER 
__ImageBase;

#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win 
{
	enum class Architecture { x86 = 1, x64 = 2, Both = x86|x64 };
}
namespace core::meta 
{
	metadata bool Settings<bitwise_enum, win::Architecture> = true;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	class PlatformExport Module 
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedModule	              Handle;
		std::optional<SharedProcess>  Owner;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		explicit
		Module(SharedModule m) : Handle{m} {
		}
		
		Module(SharedProcess p, SharedModule m) : Owner{p}, Handle{m} {
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		::HINSTANCE 
		handle() const {
			return *this->Handle;
		}

		std::vector<std::byte> 
		loadResource(ResourceId name, gsl::cwzstring category) const
		{
			if (::HRSRC resource = ::FindResourceW(this->handle(), name, category); !resource) {
				LastError{}.throwAlways("Failed to find resource '{}'", to_string(name));
			}
			else if (::HGLOBAL block = ::LoadResource(this->handle(), resource); !block) {
				LastError{}.throwAlways("Failed to load resource '{}'", to_string(name));
			}
			else if (::DWORD size = ::SizeofResource(this->handle(), resource); !size) {
				LastError{}.throwAlways("Failed to measure resource '{}'", to_string(name));
			}
			else if (auto data = (const std::byte*)::LockResource(block); !data) {
				LastError{}.throwAlways("Failed to lock resource '{}'", to_string(name));
			}
			else {
				final_act(=) noexcept { UnlockResource(block); };
				return { data, data + size };
			}
		}

		filesystem::path
		path() const {
			auto constexpr
			static getModuleFileName = [](std::optional<SharedProcess> process, SharedModule module, std::wstring_view buffer) {
				auto* const filePath = const_cast<wchar_t*>(buffer.data());
				auto const capacity = nstd::sizeof_n<wchar_t>(buffer.size());
				if (process)
					return ::GetModuleFileNameExW(**process, *module, filePath, DWord{capacity});
				else
					return ::GetModuleFileNameW(*module, filePath, DWord{capacity});
			};

			wchar_t staticBuffer[MAX_PATH] {};
			std::optional<std::wstring> dynamicBuffer;
			std::wstring_view buffer{std::begin(staticBuffer), std::end(staticBuffer)};
			
			do {
				if (auto const n = getModuleFileName(this->Owner, this->Handle, buffer); n == 0)
					LastError{}.throwAlways("GetModuleFileName[Ex]() failed");
				else if (n == buffer.size() && LastError{} == ERROR_INSUFFICIENT_BUFFER)
				{
					dynamicBuffer = std::make_optional<std::wstring>(2*buffer.size(), L'\0');
					buffer = *dynamicBuffer;
				}
				else
					return buffer.substr(0, n);
			}
			while (true);
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};

#ifdef CORE_BUILDING_DLL
	//! @brief  Library module loaded by the current process
	//! @remarks  This symbol only exists when building a DLL
	Module const
	inline DllModule {SharedModule{reinterpret_cast<::HMODULE>(&::__ImageBase), weakref}};
#endif

	//! @brief  Module of the currently executing process
	Module const
	extern PlatformExport ProcessModule;
	
	//! @brief  Sentinel value representing the currently executing process
	Module const
	extern PlatformExport SystemResource;

}	// namespace core::win
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o