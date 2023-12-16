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
#include "library/core.platform.h"
#include "security/Identifier.h"
#include "security/SecurityApi.h" 
#include "security/TokenGroup.h"
#include "security/TokenPrivilege.h"
#include "security/TokenProperty.h"
#include "win/SharedHandle.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::security
{
	enum class Integrity {
		Untrusted,
		Low,
		Medium,
		MediumPlus,
		High,
		System,
		Protected,
	};

	class Token 
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		auto const 
		inline static makeGroup = [](::SID_AND_ATTRIBUTES const& in) -> TokenGroup {
			return TokenGroup{
				Identifier{ConstSidWrapper{static_cast<::SID const*>(in.Sid)}.bytes()},
				static_cast<GroupFlag>(in.Attributes)
			};
		};
		
		auto const 
		inline static makeLuidAttribute = [](TokenPrivilege const& in) -> ::LUID_AND_ATTRIBUTES {
			return {in.LocalId, in.Flags.value()};
		};

		auto const
		inline static makePrivilege = [](::LUID_AND_ATTRIBUTES const& in) -> TokenPrivilege {
			return TokenPrivilege{in.Luid, static_cast<PrivilegeFlag>(in.Attributes)};
		};

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		win::SharedToken  token;
		SharedSecurityApi api;          //!< Security API implementation

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		explicit
		Token(win::SharedToken existing, SharedSecurityApi api = security_api()) 
		  : token{std::move(ThrowIfEmpty(existing))},
		    api{std::move(ThrowIfEmpty(api))}
		{}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		std::vector<TokenGroup>
		groups() const {
			auto const data = boost::reinterpret_pointer_cast<::TOKEN_GROUPS>(
				this->api->tokenInformation(this->token, TokenProperty::Groups)
			);
			
			return {
				std::from_range,
				views::transform(std::span{data->Groups, data->GroupCount}, Token::makeGroup) 
			};
		}

		win::SharedToken 
		handle() const {
			return this->token;
		}

		Integrity
		integrity() const {
			auto const data = boost::reinterpret_pointer_cast<::TOKEN_MANDATORY_LABEL>(
				this->api->tokenInformation(this->token, TokenProperty::IntegrityLevel)
			);
			ConstSidWrapper const sid{static_cast<::SID const*>(data->Label.Sid)};
            if (DWORD level = sid.SubAuthority[sid.SubAuthorityCount - 1]; level < SECURITY_MANDATORY_LOW_RID)
				return Integrity::Untrusted;
			else if (level >= SECURITY_MANDATORY_LOW_RID && level < SECURITY_MANDATORY_MEDIUM_RID)
				return Integrity::Low;
            else if (level >= SECURITY_MANDATORY_MEDIUM_RID && level < SECURITY_MANDATORY_MEDIUM_PLUS_RID)
				return Integrity::Medium;
            else if (level >= SECURITY_MANDATORY_MEDIUM_PLUS_RID && level < SECURITY_MANDATORY_HIGH_RID)
				return Integrity::MediumPlus;
            else if (level >= SECURITY_MANDATORY_HIGH_RID && level < SECURITY_MANDATORY_SYSTEM_RID)
				return Integrity::High;
            else if (level >= SECURITY_MANDATORY_SYSTEM_RID && level < SECURITY_MANDATORY_PROTECTED_PROCESS_RID)
				return Integrity::System;
			else 
				return Integrity::Protected;
		}

		bool
		memberOf(Identifier group) const {
			return this->api->checkMembership(this->token, group.bytes());
		}
		
		std::vector<TokenPrivilege>
		privileges() const {
			auto const data = boost::reinterpret_pointer_cast<::TOKEN_PRIVILEGES>(
				this->api->tokenInformation(this->token, TokenProperty::Privileges)
			);
			
			return {
				std::from_range,
				views::transform(std::span{&data->Privileges[0], data->PrivilegeCount}, Token::makePrivilege)
			};
		}

		uint32_t
		sessionId() const {
			auto const data = boost::reinterpret_pointer_cast<::DWORD>(
				this->api->tokenInformation(this->token, TokenProperty::SessionId)
			);

			return *data;
		}

		Identifier
		user() const {
			auto const data = boost::reinterpret_pointer_cast<::SID_AND_ATTRIBUTES>(
				this->api->tokenInformation(this->token, TokenProperty::User)
			);
			
			return Identifier{
				ConstSidWrapper{static_cast<::SID const*>(data->Sid)}.bytes()
			};
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		sessionId(uint32_t id) {
			auto const data = std::as_writable_bytes(std::span{&id,1});
			this->api->tokenInformation(this->token, TokenProperty::SessionId, data);
		}

		void
		privileges(std::vector<TokenPrivilege> privs) {
			ThrowIfEmpty(privs);

			size_t const capacity = nstd::sizeof_v<::DWORD> 
			                      + nstd::sizeof_n<::LUID_AND_ATTRIBUTES>(privs.size());

			auto const data = boost::reinterpret_pointer_cast<::TOKEN_PRIVILEGES>(
				std::make_unique<std::byte[]>(capacity)
			);
			
			data->PrivilegeCount = win::DWord{privs.size()};
			ranges::transform(privs, std::begin(data->Privileges), Token::makeLuidAttribute);
			if (!::AdjustTokenPrivileges(*this->token, FALSE, data.get(), NULL, nullptr, nullptr))
				win::LastError{}.throwAlways("::AdjustTokenPrivileges() failed");
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o