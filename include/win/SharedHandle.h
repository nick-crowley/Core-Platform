#pragma once
#include "core/SmartHandle.h"

#ifdef __clang__
#	error Clang doesn't support compiling SharedHandle.h yet
#endif

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
}

namespace core::win
{
    namespace detail 
    {
        struct FileHandleTraits {
            ::HANDLE constexpr
            inline static empty = INVALID_HANDLE_VALUE;

            auto constexpr
            inline static release = &::CloseHandle;
        };

        struct ServiceManagerHandleTraits : core::detail::HandleTraits<::SC_HANDLE>
        {};
    }

    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedHandle = SmartHandle<::HANDLE>;

    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedEvent = SharedHandle;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle() and @c INVALID_HANDLE_VALUE sentinel value
    using SharedFile = SmartHandle<::HANDLE, detail::FileHandleTraits>;
    
    //! @brief  Shared @c ::HKEY released using @c ::RegCloseKey()
    using SharedRegistryKey = SmartHandle<::HKEY>;

    //! @brief  Shared @c ::HMODULE released using @c ::FreeLibrary()
    using SharedModule = SmartHandle<::HMODULE>;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedProcess = SharedHandle;
    
    //! @brief  Shared @c ::SC_HANDLE released using @c ::CloseServiceHandle()
    using SharedService = SmartHandle<::SC_HANDLE>;
    
    //! @brief  Shared @c ::SC_HANDLE released using @c ::CloseServiceHandle() but distinct from service handles
    using SharedServiceManager = SmartHandle<::SC_HANDLE, detail::ServiceManagerHandleTraits>;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedThread = SharedHandle;
    
    //! @brief  Shared @c ::HANDLE released using @c ::CloseHandle()
    using SharedToken = SharedHandle;    

} // namespace core::win