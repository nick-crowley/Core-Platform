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

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{	
    namespace detail
    {
        enum WaitStrategy { WaitAny, WaitAll };
        
        std::optional<::HANDLE>
        PlatformExport waitForMultipleObjects(std::span<::HANDLE> handles, WaitStrategy strategy, std::optional<chrono::milliseconds> timeout);
        
        template <nstd::InputRangeOf<::HANDLE> HandleCollection> 
            requires (!ranges::contiguous_range<HandleCollection>)
        std::optional<::HANDLE>
        waitForMultipleObjects(HandleCollection r, WaitStrategy strategy, std::optional<chrono::milliseconds> timeout)
        {
            std::vector<::HANDLE> handles{ranges::begin(r), ranges::end(r)};
            return waitForMultipleObjects(handles, strategy, timeout);
        }
        
        template <nstd::ContiguousRangeOf<::HANDLE> HandleCollection>
        std::optional<::HANDLE>
        waitForMultipleObjects(HandleCollection r, WaitStrategy strategy, std::optional<chrono::milliseconds> timeout)
        {
            return waitForMultipleObjects(std::span<::HANDLE>{r}, strategy, timeout);
        }
    }
    
	//! @brief	Wait indefinitely until @e all handles in range are signalled
    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    bool
    allSignalled(HandleCollection&& handles)
    {
        using namespace chrono;
        return detail::waitForMultipleObjects(handles, detail::WaitAll, 0ms).has_value();
    }

    //! @brief	Wait indefinitely until @e any handles in range are signalled
    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    bool
    anySignalled(HandleCollection&& handles)
    {
        using namespace chrono;
        return detail::waitForMultipleObjects(handles, detail::WaitAny, 0ms).has_value();
    }

    //! @brief	Wait for @p timeout until all handles in range are signalled
    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    bool
    waitForAll(HandleCollection&& handles, std::optional<chrono::milliseconds> timeout = nullopt)
    {
        return detail::waitForMultipleObjects(handles, detail::WaitAll, timeout).has_value();
    }
    
    //! @brief	Wait for @p timeout until any handles in range are signalled
    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    std::optional<::HANDLE>
    waitForAny(HandleCollection&& handles, std::optional<chrono::milliseconds> timeout = nullopt)
    {
        return detail::waitForMultipleObjects(handles, detail::WaitAny, timeout);
    }

    //! @brief	Wait until @p deadline for all handles in range to be signalled
    template <nstd::InputRangeOf<::HANDLE> HandleCollection, nstd::Clock Clock> 
    bool
    waitUntilAll(HandleCollection&& handles, chrono::time_point<Clock> deadline)
    {
        using namespace chrono;
        auto const timeout = duration_cast<milliseconds>(Clock::now() - deadline);
        return detail::waitForMultipleObjects(handles, detail::WaitAll, timeout).has_value();
    }
    
    //! @brief	Wait until @p deadline for any handles in range to be signalled
    template <nstd::InputRangeOf<::HANDLE> HandleCollection, nstd::Clock Clock> 
    std::optional<::HANDLE>
    waitUntilAny(HandleCollection&& handles, chrono::time_point<Clock> deadline)
    {
        using namespace chrono;
        auto const timeout = duration_cast<milliseconds>(Clock::now() - deadline);
        return detail::waitForMultipleObjects(handles, detail::WaitAny, timeout);
    }
    
    //! @brief	Query whether @p handle is signalled
    bool
    inline isSignalled(::HANDLE handle)
    {
        return anySignalled(ranges::single_view{handle});
    }

    //! @brief	Wait at most @p timeout for @p handle to become signalled
    bool
    inline waitFor(::HANDLE handle, std::optional<chrono::milliseconds> timeout = nullopt)
    {
        return waitForAll(ranges::single_view{handle}, timeout);
    }
    
    //! @brief	Wait until @p deadline for @p handle to become signalled
    template <nstd::Clock Clock>
    bool
    waitUntil(::HANDLE handle, chrono::time_point<Clock> deadline)
    {
        return waitUntilAll(ranges::single_view{handle}, deadline);
    }
} // namespace core::win
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o