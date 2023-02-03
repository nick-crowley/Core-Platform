#pragma once
#include "core/SmartHandle.h"

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
    using SharedThread = SharedHandle;
    
} // namespace core::win