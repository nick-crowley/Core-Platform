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
#include "library/core.platform.h"
#include "win/SharedLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	enum class Platform { 
		Windows9x,
		Windows2k,
		WindowsXp,
		Server2k3,
		Vista,
		Server2k8,
		Windows7,
		Server2k12,
		Windows8,
		Windows8p1,
		Server2k16,
		Windows10, 
		Windows11
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	struct Version 
	{
		uint32_t  Major, Minor, Build;

		template <nstd::Integer Integer>
		constexpr
		Version(Integer major, Integer minor = 0, Integer build = 0)
		  : Major{static_cast<uint32_t>(major)},
		    Minor{static_cast<uint32_t>(minor)},
		    Build{static_cast<uint32_t>(build)}
		{
		}

		satisfies(Version,
			constexpr IsCopyable,
			constexpr IsSortable
		);
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	Platform
	platform() {
		Version constexpr  static Win11     {10, 0, 22000};
		Version constexpr  static Win10     {10, 0};
		Version constexpr  static Win81     {6, 3};
		Version constexpr  static Win8      {6, 2};
		Version constexpr  static Win7      {6, 1};
		Version constexpr  static WinVista  {6, 0};
		Version constexpr  static Server2k3 {5, 2};
		Version constexpr  static WinXp     {5, 1};
		Version constexpr  static Win2k     {5, 0};

		::OSVERSIONINFOEXW info{sizeof(info)};
		scoped {
			SharedLibrary ntdll{L"Ntdll.dll"};
			auto rtlGetVersion = ntdll.loadFunction<NTSTATUS(::OSVERSIONINFOW*)>("RtlGetVersion");
			nt::NtStatus const r = rtlGetVersion(reinterpret_cast<OSVERSIONINFOW*>(&info));
			r.throwIfError("GetVersionEx() failed");
		}

		bool const isClient = info.wProductType == VER_NT_WORKSTATION;
		Version const v{
			info.dwMajorVersion, 
			info.dwMinorVersion, 
			info.dwMajorVersion == 10 ? info.dwBuildNumber : 0
		};
		if (v < Win2k)
			return Platform::Windows9x;
		else if (v < WinXp)
			return Platform::Windows2k;
		else if (v < Server2k3)
			return Platform::WindowsXp;
		else if (v < WinVista)
			return Platform::Server2k3;
		else if (v < Win7)
			return isClient ? Platform::Vista : Platform::Server2k8;
		else if (v < Win8)
			return isClient ? Platform::Windows7 : Platform::Server2k8;
		else if (v < Win81)
			return isClient ? Platform::Windows8 : Platform::Server2k12;
		else if (v < Win10)
			return isClient ? Platform::Windows8p1 : Platform::Server2k12;
		else if (v >= Win10 && v < Win11)
			return isClient ? Platform::Windows10 : Platform::Server2k16;
		else
			return Platform::Windows11;
	}

	std::string
	platformName() {
		switch (Platform const p = platform()) {
		case Platform::Server2k3:    return "Server 2003";
		case Platform::Server2k8:    return "Server 2008";
		case Platform::Server2k12:   return "Server 2012";
		case Platform::Server2k16:   return "Server 2016";
		case Platform::Windows9x:    return "Windows 9x";
		case Platform::Windows2k:    return "Windows 2000";
		case Platform::WindowsXp:    return "Windows XP";
		case Platform::Vista:        return "Windows Vista";
		case Platform::Windows7:     return "Windows 7";
		case Platform::Windows8:     return "Windows 8";
		case Platform::Windows8p1:   return "Windows 8.1";
		case Platform::Windows10:    return "Windows 10";
		case Platform::Windows11:    return "Windows 11";
		default:                     return std::format("{:x}", std::to_underlying(p));
		}
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win::testing
{
	//! @test  Verify lower versions compare as less than higher versions
	static_assert(Version{1,0} < Version{2,0});

	//! @test  Verify major number takes precedence over minor number when comparing versions
	static_assert(Version{1,1} < Version{2,0});
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o