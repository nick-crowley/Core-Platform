#pragma once
#include "corePlatform.h"

namespace core::win
{	
    namespace detail
    {
        enum WaitStrategy { WaitAny, WaitAll };
        
        std::optional<::HANDLE>
        waitForMultipleObjects(std::span<::HANDLE> handles, WaitStrategy strategy, std::optional<std::chrono::milliseconds> timeout);
        
        template <meta::InputRangeOf<::HANDLE> HandleCollection> 
            requires (!std::ranges::contiguous_range<HandleCollection>)
        std::optional<::HANDLE>
        waitForMultipleObjects(HandleCollection r, WaitStrategy strategy, std::optional<std::chrono::milliseconds> timeout)
        {
            std::vector<::HANDLE> handles{std::ranges::begin(r), std::ranges::end(r)};
            return waitForMultipleObjects(handles, strategy, timeout);
        }
        
        template <meta::ContiguousRangeOf<::HANDLE> HandleCollection>
        std::optional<::HANDLE>
        waitForMultipleObjects(HandleCollection r, WaitStrategy strategy, std::optional<std::chrono::milliseconds> timeout)
        {
            return waitForMultipleObjects(std::span<::HANDLE>{r}, strategy, timeout);
        }
    }
    
    template <meta::InputRangeOf<::HANDLE> HandleCollection>
    bool
    allSignalled(HandleCollection&& handles)
    {
        using namespace std::chrono;
        return detail::waitForMultipleObjects(handles, detail::WaitAll, 0ms).has_value();
    }

    template <meta::InputRangeOf<::HANDLE> HandleCollection>
    bool
    anySignalled(HandleCollection&& handles)
    {
        using namespace std::chrono;
        return detail::waitForMultipleObjects(handles, detail::WaitAny, 0ms).has_value();
    }

    template <meta::InputRangeOf<::HANDLE> HandleCollection>
    bool
    waitForAll(HandleCollection&& handles, std::optional<std::chrono::milliseconds> timeout = std::nullopt)
    {
        return detail::waitForMultipleObjects(handles, detail::WaitAll, timeout).has_value();
    }
    
    template <meta::InputRangeOf<::HANDLE> HandleCollection>
    std::optional<::HANDLE>
    waitForAny(HandleCollection&& handles, std::optional<std::chrono::milliseconds> timeout = std::nullopt)
    {
        return detail::waitForMultipleObjects(handles, detail::WaitAny, timeout);
    }

    template <meta::InputRangeOf<::HANDLE> HandleCollection, meta::Clock Clock> 
    bool
    waitUntilAll(HandleCollection&& handles, std::chrono::time_point<Clock> deadline)
    {
        using namespace std::chrono;
        auto const timeout = duration_cast<milliseconds>(Clock::now() - deadline);
        return detail::waitForMultipleObjects(handles, detail::WaitAll, timeout).has_value();
    }
    
    template <meta::InputRangeOf<::HANDLE> HandleCollection, meta::Clock Clock> 
    std::optional<::HANDLE>
    waitUntilAny(HandleCollection&& handles, std::chrono::time_point<Clock> deadline)
    {
        using namespace std::chrono;
        auto const timeout = duration_cast<milliseconds>(Clock::now() - deadline);
        return detail::waitForMultipleObjects(handles, detail::WaitAny, timeout);
    }
    
    bool
    inline isSignalled(::HANDLE handle)
    {
        return anySignalled(std::ranges::single_view{handle});
    }

    bool
    inline waitFor(::HANDLE handle, std::optional<std::chrono::milliseconds> timeout = std::nullopt)
    {
        return waitForAll(std::ranges::single_view{handle}, timeout);
    }
    
    template <meta::Clock Clock>
    bool
    waitUntil(::HANDLE handle, std::chrono::time_point<Clock> deadline)
    {
        return waitUntilAll(std::ranges::single_view{handle}, deadline);
    }
} // namespace core::win
