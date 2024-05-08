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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "win/Concurrency.h"
using namespace core;

std::optional<::HANDLE>
win::detail::waitForMultipleObjects(std::span<::HANDLE> handles, WaitStrategy strategy, std::optional<chrono::milliseconds> timeout)
{   
    auto result = ::WaitForMultipleObjects(static_cast<::DWORD>(handles.size()), 
                                            handles.data(), 
                                            strategy == WaitStrategy::WaitAll ? TRUE : FALSE, 
                                            timeout ? static_cast<::DWORD>(timeout->count()) : INFINITE);
    if (result == WAIT_TIMEOUT)
    {
        return nullopt;
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
        throw system_error{result, nstd::system_category{}, "Wait on {} handles failed", handles.size()};
}
