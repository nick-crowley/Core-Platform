#pragma once
#include "library/core.Platform.h"

namespace core
{
    namespace detail
    {   
        template <std::semiregular RawHandle>
        struct HandleTraits;
    }
    
    namespace meta 
    {
        template <typename T>
        concept SmartHandleTraits = requires {
            T::release(T::empty);
        };
    }
    
    //! @brief  Smart-handle with shared-ownership semantics
    template <std::semiregular  RawHandle, 
              meta::SmartHandleTraits  Traits = detail::HandleTraits<RawHandle>>
    class SmartHandle
    {
        using type = SmartHandle<RawHandle,Traits>;
        using reference = type&;
        
        struct IHandleResource
        {
            satisfies(IHandleResource,
                protected: IsDefaultConstructible,
                public: IsPolymorphic noexcept
            );

            bool
            virtual empty() const noexcept abstract;

            RawHandle
            virtual get() const noexcept abstract;
            
            void
            virtual close() noexcept abstract;
        };
        
        class BorrowedHandle : public IHandleResource 
        {
            RawHandle const  m_handle;

        public:
            BorrowedHandle(RawHandle h) 
              : m_handle{h}
            {}
            
        public:
            bool
            empty() const noexcept override {
                return this->m_handle == Traits::empty;
            }

        public:
            RawHandle
            get() const noexcept override {
                return this->m_handle;
            }

            void
            close() noexcept override
            {}
        };
        
        template <std::invocable<RawHandle> ReleaseDelegate>
        class ManagedHandle : public IHandleResource 
        {
            RawHandle const        m_handle;
            ReleaseDelegate const  m_releaser;

        public:
            ManagedHandle(RawHandle h, ReleaseDelegate dx)
              : m_handle{h}, m_releaser{std::move(dx)}
            {}

            ~ManagedHandle() noexcept {
                this->close();
            }
            
        public:
            bool
            empty() const noexcept override {
                return this->m_handle == Traits::empty;
            }

        public:
            RawHandle
            get() const noexcept override {
                return this->m_handle;
            }

            void
            close() noexcept override {
                this->m_releaser(this->m_handle);
            }
        };
        
    private:
        std::shared_ptr<IHandleResource> m_object;

    public:
        template <std::invocable<RawHandle> ReleaseDelegate = decltype(Traits::release)>
        explicit
        SmartHandle(RawHandle handle, ReleaseDelegate release = Traits::release) 
          : m_object{new ManagedHandle{handle,std::move(release)}}
        {
        }
        
        SmartHandle(RawHandle handle, meta::weakref_t) 
          : m_object{new BorrowedHandle{handle}}
        {
        }
        
        satisfies(SmartHandle,
            IsRegular noexcept,
            NotSortable
        );
        
    public:
        //! @brief  Close the managed handle prematurely thereby invalidating (but not releasing) it
        void
        static close(type& handle) noexcept
        {
            if (!handle->empty())
                handle.m_object->close();
        }
        
        bool
        empty() const noexcept {
            return !this->m_object || this->m_object->empty();
        }

        RawHandle
        get() const noexcept {
            return this->m_object->get();
        }
        
        RawHandle 
        operator*() const noexcept {
            return this->m_object->get();
        }

        implicit operator 
        bool() const noexcept {
            return !this->empty();
        }

    public:
        void 
        reset() {
            this->m_object.reset();
        }
        
        template <std::invocable<RawHandle> ReleaseDelegate = decltype(Traits::release)>
        void 
        reset(RawHandle handle, ReleaseDelegate release = Traits::release) {
            type{handle,release}.swap(*this);
        }
        
        void 
        reset(RawHandle handle, meta::weakref_t) {
            type{handle}.swap(*this);
        }

        void 
        swap(type& r) noexcept {
            this->m_object.swap(r.m_handle);
        }
    };
}