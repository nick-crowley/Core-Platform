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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    private:
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
            RawHandle const  Handle;

        public:
            BorrowedHandle(RawHandle h) 
              : Handle{h}
            {}
            
        public:
            bool
            empty() const noexcept override {
                return this->Handle == Traits::empty;
            }

        public:
            RawHandle
            get() const noexcept override {
                return this->Handle;
            }

            void
            close() noexcept override
            {}
        };
        
        template <std::invocable<RawHandle> ReleaseDelegate>
        class ManagedHandle : public IHandleResource 
        {
            RawHandle const        Handle;
            ReleaseDelegate const  Release;

        public:
            ManagedHandle(RawHandle h, ReleaseDelegate dx)
              : Handle{h}, Release{std::move(dx)}
            {}

            ~ManagedHandle() noexcept {
                this->close();
            }
            
        public:
            bool
            empty() const noexcept override {
                return this->Handle == Traits::empty;
            }

        public:
            RawHandle
            get() const noexcept override {
                return this->Handle;
            }

            void
            close() noexcept override {
                this->Release(this->Handle);
            }
        };
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    private:
        std::shared_ptr<IHandleResource> Object;
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    public:
        template <std::invocable<RawHandle> ReleaseDelegate = decltype(Traits::release)>
        explicit
        SmartHandle(RawHandle raw, ReleaseDelegate release = Traits::release) 
          : Object{new ManagedHandle{raw,std::move(release)}}
        {
        }
        
        SmartHandle(RawHandle raw, meta::weakref_t) 
          : Object{new BorrowedHandle{raw}}
        {
        }
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    public:
        satisfies(SmartHandle,
            IsRegular noexcept,
            NotSortable
        );
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    public:
        //! @brief  Close the managed handle prematurely thereby invalidating (but not releasing) it
        void
        static close(type& handle) noexcept
        {
            if (!handle.empty())
                handle.Object->close();
        }
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    public:
        bool
        empty() const noexcept {
            return !this->Object || this->Object->empty();
        }

        RawHandle
        get() const noexcept {
            return this->Object ? this->Object->get() : Traits::empty;
        }
        
        RawHandle 
        operator*() const noexcept {
            return this->get();
        }

        implicit operator 
        bool() const noexcept {
            return !this->empty();
        }
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    public:
        void 
        reset() {
            this->Object.reset();
        }
        
        template <std::invocable<RawHandle> ReleaseDelegate = decltype(Traits::release)>
        void 
        reset(RawHandle raw, ReleaseDelegate release = Traits::release) {
            type{raw,release}.swap(*this);
        }
        
        void 
        reset(RawHandle raw, meta::weakref_t) {
            type{raw}.swap(*this);
        }

        void 
        swap(type& r) noexcept {
            this->Object.swap(r.Object);
        }
    };
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
    template <std::semiregular RawHandle, meta::SmartHandleTraits Traits>
    bool 
    empty(SmartHandle<RawHandle,Traits> const& handle) {
        return handle.empty();
    }
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o