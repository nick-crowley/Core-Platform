#pragma once
#include "library/core.Platform.h"

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
    
    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    bool
    allSignalled(HandleCollection&& handles)
    {
        using namespace chrono;
        return detail::waitForMultipleObjects(handles, detail::WaitAll, 0ms).has_value();
    }

    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    bool
    anySignalled(HandleCollection&& handles)
    {
        using namespace chrono;
        return detail::waitForMultipleObjects(handles, detail::WaitAny, 0ms).has_value();
    }

    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    bool
    waitForAll(HandleCollection&& handles, std::optional<chrono::milliseconds> timeout = std::nullopt)
    {
        return detail::waitForMultipleObjects(handles, detail::WaitAll, timeout).has_value();
    }
    
    template <nstd::InputRangeOf<::HANDLE> HandleCollection>
    std::optional<::HANDLE>
    waitForAny(HandleCollection&& handles, std::optional<chrono::milliseconds> timeout = std::nullopt)
    {
        return detail::waitForMultipleObjects(handles, detail::WaitAny, timeout);
    }

    template <nstd::InputRangeOf<::HANDLE> HandleCollection, nstd::Clock Clock> 
    bool
    waitUntilAll(HandleCollection&& handles, chrono::time_point<Clock> deadline)
    {
        using namespace chrono;
        auto const timeout = duration_cast<milliseconds>(Clock::now() - deadline);
        return detail::waitForMultipleObjects(handles, detail::WaitAll, timeout).has_value();
    }
    
    template <nstd::InputRangeOf<::HANDLE> HandleCollection, nstd::Clock Clock> 
    std::optional<::HANDLE>
    waitUntilAny(HandleCollection&& handles, chrono::time_point<Clock> deadline)
    {
        using namespace chrono;
        auto const timeout = duration_cast<milliseconds>(Clock::now() - deadline);
        return detail::waitForMultipleObjects(handles, detail::WaitAny, timeout);
    }
    
    bool
    inline isSignalled(::HANDLE handle)
    {
        return anySignalled(ranges::single_view{handle});
    }

    bool
    inline waitFor(::HANDLE handle, std::optional<chrono::milliseconds> timeout = std::nullopt)
    {
        return waitForAll(ranges::single_view{handle}, timeout);
    }
    
    template <nstd::Clock Clock>
    bool
    waitUntil(::HANDLE handle, chrono::time_point<Clock> deadline)
    {
        return waitUntilAll(ranges::single_view{handle}, deadline);
    }
} // namespace core::win
