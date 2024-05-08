/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2024, Nick Crowley. All rights reserved.
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
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "../../src/StdLibrary.h"
#include "../../src/PlatformSdk.h"
#include "../../src/library/PlatformExport.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{	
	namespace detail
	{
		class PlatformExport HResultCategoryMessage
		{
		private:
			struct ErrorConstant { 
				std::string_view Name; 
				::HRESULT        Code;
			};

		private:
			std::array<ErrorConstant, 198> const
			static ErrorConstantNames;

		public:
			std::string_view
			static fromCondition(long condition) noexcept;
		};

		std::string 
		PlatformExport formatMessage(::DWORD condition);
	}

	//! @brief @c std::error_category for ::HRESULT error-codes
	class hresult_category : public std::error_category
	{
		using base = std::error_category;
		
	private:
		uintptr_t constexpr
		static CategoryId = 9;

	public:
		hresult_category() : base{hresult_category::CategoryId}
		{}

	public:
		[[nodiscard]]
		std::string
		message(int condition) const override {
			static_assert(sizeof(int) == sizeof(::HRESULT));

			if (auto const symbol = detail::HResultCategoryMessage::fromCondition(condition); !symbol.empty())
				return std::string{symbol};

			return std::format("{} ({:#x})", detail::formatMessage(condition), static_cast<::DWORD>(condition));
		}

		gsl::czstring
		virtual name() const noexcept {
			return "::HRESULT";
		}
	};

	//! @brief @c std::error_category for ::NTSTATUS error-codes
	class ntstatus_category : public std::error_category
	{
		using base = std::error_category;
		
	private:
		uintptr_t constexpr
		static CategoryId = 12;

	public:
		ntstatus_category() : base{ntstatus_category::CategoryId}
		{}

	public:
		[[nodiscard]]
		std::string
		message(int condition) const override;

		gsl::czstring
		virtual name() const noexcept {
			return "ntstatus";
		}
	};

	namespace detail
	{
		class PlatformExport SystemCategoryMessage
		{
		private:
			struct ErrorConstant { 
				std::string_view Name; 
				long             Code;
			};

		private:
			std::array<ErrorConstant, 2887> const
			static ErrorConstantNames;

		public:
			std::string_view
			static fromCondition(long condition) noexcept;
		};
	}

	//! @brief @c std::error_category for Win32 error-codes
	class system_category : public std::error_category
	{
		using base = std::error_category;
		
	private:
		uintptr_t constexpr
		static CategoryId = 11;

	public:
		system_category() : base{system_category::CategoryId}
		{}

	public:
		[[nodiscard]]
		std::string
		message(int condition) const override {
			if (auto const symbol = detail::SystemCategoryMessage::fromCondition(condition); !symbol.empty())
				return std::string{symbol};

			return std::format("{} ({:#x})", detail::formatMessage(condition), static_cast<::DWORD>(condition));
		}

		gsl::czstring
		virtual name() const noexcept {
			return "system";
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Separator o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o