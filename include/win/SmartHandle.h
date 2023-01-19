#pragma once
#include "library/core.Platform.h"

namespace core::win
{
    namespace detail
    {   
        auto constexpr
        inline CloseHandlePolicy = [](::HANDLE handle) noexcept {
            ::CloseHandle(handle);
        };

        auto constexpr
        inline RegCloseKeyPolicy = [](::HKEY key) noexcept {
            ::RegCloseKey(key);
        };
        
        auto constexpr
        inline FreeLibraryPolicy = [](::HMODULE handle) noexcept {
            ::FreeLibrary(handle);
        };
        
        using InvalidHandle = std::integral_constant<::HANDLE,INVALID_HANDLE_VALUE>;
    } 

    //! @brief  Smart-handle with shared-ownership semantics
    template <typename RawHandle, 
              auto Releaser = detail::CloseHandlePolicy, 
              auto Empty = nullptr>
    class SmartHandle
    {
        using type = SmartHandle<RawHandle,Releaser,Empty>;
        
        auto constexpr 
        inline static Deleter = [](RawHandle* ptr) 
        {
            if (ptr && *ptr != Empty)
            {
                Releaser(*ptr);
            }
        };

    private:
        std::shared_ptr<RawHandle> m_handle;

    public:
        constexpr
        explicit
        SmartHandle(RawHandle handle) 
          : m_handle{new RawHandle{handle},Deleter}
        {
        }
        
        SmartHandle& 
        operator=(RawHandle handle) 
        {
            type{handle}.swap(*this);
            return *this;
        }

        satisfies(SmartHandle,
            constexpr IsRegular noexcept
        );
        
    public:
        //! @brief  Close the managed handle prematurely thereby invalidating (but not releasing) it
        void
        static close(type& handle) noexcept
        {
            Releaser(*handle);
        }
        
        bool
        empty() const noexcept
        {
            return !this->m_handle ||
                   *this->m_handle == Empty;
        }

        RawHandle*
        get() const noexcept
        {
            return this->m_handle.get();
        }
        
        void 
        reset() 
        {
            this->m_handle.reset();
        }

        void 
        reset(RawHandle handle) 
        {
            this->m_handle.reset(new RawHandle{handle},Deleter);
        }

        void 
        swap(type& r) noexcept
        {
            this->m_handle.swap(r.m_handle);
        }
        
        RawHandle 
        operator*() const noexcept
        {
            return *this->m_handle.get();
        }

        implicit operator 
        bool() const noexcept
        {
            return !this->empty();
        }
    };
    
    //! @brief  Smart-handle released using ::CloseHandle()
    using SharedHandle = SmartHandle<::HANDLE>;

    //! @brief  Smart-handle released using ::CloseHandle()
    using SharedEvent = SharedHandle;
    
    //! @brief  Smart-handle released using ::CloseHandle()
    using SharedFile = SmartHandle<::HANDLE, detail::CloseHandlePolicy, detail::InvalidHandle::value>;
    
    //! @brief  Smart-handle released using ::RegCloseKey()
    using SharedRegistryKey = SmartHandle<::HKEY, detail::RegCloseKeyPolicy>;

    //! @brief  Smart-handle released using ::FreeLibrary()
    using SharedModule = SmartHandle<::HMODULE, detail::FreeLibraryPolicy>;

} // namespace core::win