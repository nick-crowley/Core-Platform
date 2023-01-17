#include "win/Concurrency.h"
using namespace core;

std::optional<::HANDLE>
win::detail::waitForMultipleObjects(std::span<::HANDLE> handles, WaitStrategy strategy, std::optional<std::chrono::milliseconds> timeout)
{   
    auto result = ::WaitForMultipleObjects(static_cast<::DWORD>(handles.size()), 
                                            handles.data(), 
                                            strategy == WaitStrategy::WaitAll ? TRUE : FALSE, 
                                            timeout ? static_cast<::DWORD>(timeout->count()) : INFINITE);
    if (result == WAIT_TIMEOUT)
    {
        return std::nullopt;
    }
    else if (result >= WAIT_OBJECT_0 && result < WAIT_OBJECT_0+handles.size())
    {
        return handles[result-WAIT_OBJECT_0];
    }
    else if (result >= WAIT_ABANDONED_0 && result < WAIT_ABANDONED_0+handles.size())
    {
        return handles[result-WAIT_ABANDONED_0];
    }
    else 
        throw system_error{result, "Wait on {} handles failed", handles.size()};
}
