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
#include "win/RegistryKey.h"
using namespace core;

win::RegistryKey::RegistryKey(SharedRegistryKey handle, KeyRight rights, SharedRegistryApi api)
  : m_api{ThrowIfEmpty(api)}, 
    m_handle{handle}, 
    m_rights{rights}
{
}

win::RegistryKey::RegistryKey(SharedRegistryKey parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api)
  : m_api{api}, 
    m_handle{ThrowIfEmpty(api)->openKey(parent, child, rights)}, 
    m_rights{rights}
{
}

win::RegistryKey::RegistryKey(meta::create_new_t, SharedRegistryKey parent, std::wstring_view child, KeyRight rights, SharedRegistryApi api)
  : m_api{api}, 
    m_handle{ThrowIfEmpty(api)->createKey(parent, child, rights)}, 
    m_rights{rights}
{
}

win::RegistryKey
win::RegistryKey::subkey(std::wstring_view child, std::optional<KeyRight> rights) const
{
	return RegistryKey{this->m_handle, ThrowIfEmpty(child), rights.value_or(this->m_rights)};
}

void
win::RegistryKey::removeKey(std::wstring_view child)
{
	this->m_api->removeKey(this->m_handle, ThrowIfEmpty(child));
}

win::RegistryKey
win::RegistryKey::subkey(meta::create_new_t, std::wstring_view child, std::optional<KeyRight> rights)
{
	return RegistryKey{create_new, this->m_handle, ThrowIfEmpty(child), rights.value_or(this->m_rights)};
}
