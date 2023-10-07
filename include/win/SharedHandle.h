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
#ifdef __clang__
#	error Clang doesn't support compiling SharedHandle.h yet
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "core/SmartHandle.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail
{
    template <>
    struct HandleTraits<::HANDLE> {
        ::HANDLE constexpr
        inline static empty = nullptr;

        auto constexpr
        inline static release = &::CloseHandle;
    };
        
    template <>
    struct HandleTraits<::HKEY> {
        ::HKEY constexpr
        inline static empty = nullptr;

        auto constexpr
        inline static release = &::RegCloseKey;
    };
        
    template <>
    struct HandleTraits<::HMODULE> {
        ::HMODULE constexpr
        inline static empty = nullptr;

        auto constexpr
        inline static release = &::FreeLibrary;
    };

    template <>
    struct HandleTraits<::SC_HANDLE> {
        ::SC_HANDLE constexpr
        inline static empty = nullptr;

        auto constexpr
        inline static release = &::CloseServiceHandle;
    };  
    
    template <>
    struct HandleTraits<::SERVICE_STATUS_HANDLE> {
        ::SERVICE_STATUS_HANDLE constexpr
        inline static empty = nullptr;

        auto constexpr
        inline static release = [](::SERVICE_STATUS_HANDLE) {};
    };
}

namespace core::win
{
    namespace detail 
    {
        struct ServiceManagerHandleTraits : core::detail::HandleTraits<::SC_HANDLE>
        {};
    }

    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedHandle = SmartHandle<::HANDLE>;

    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedEvent = SharedHandle;
    
    //! @brief  Shared @c ::HKEY released using @c ::RegCloseKey()
    using SharedRegistryKey = SmartHandle<::HKEY>;

    //! @brief  Shared @c ::HMODULE released using @c ::FreeLibrary()
    using SharedModule = SmartHandle<::HMODULE>;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedProcess = SharedHandle;
    
    //! @brief  Shared @c ::SC_HANDLE released using @c ::CloseServiceHandle()
    using SharedService = SmartHandle<::SC_HANDLE>;
    
    //! @brief  Shared @c ::SERVICE_STATUS_HANDLE
    using SharedServiceController = SmartHandle<::SERVICE_STATUS_HANDLE>;
    
    //! @brief  Shared @c ::SC_HANDLE released using @c ::CloseServiceHandle() but distinct from service handles
    using SharedServiceManager = SmartHandle<::SC_HANDLE, detail::ServiceManagerHandleTraits>;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedThread = SharedHandle;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedToken = SharedHandle;    

}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o