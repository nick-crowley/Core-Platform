#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/implicit.h"
#include "win/SystemError.h"
#include "../../src/library/PlatformExport.h"

namespace core::nt::detail
{
	std::string 
	PlatformExport formatMessage(::NTSTATUS err);
}

namespace core::nt
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Long return-type frequently used by kernel-mode Windows APIs
	*/
	class NtStatus
	{
		::NTSTATUS Value;

	public:
		implicit
		NtStatus(::NTSTATUS value, std::source_location loc = std::source_location::current()) 
		  : Value{value}
		{
		}
		
	public:
		std::string
		str() const {
			return detail::formatMessage(this->Value);
		}
		
		[[noreturn]] 
		void 
		throwAlways() const {
			// BUG: this will result in the wrong error category
			throw std::system_error{this->Value, std::system_category(), this->str()};
		}
		
		template <typename... Params> 
		[[noreturn]] 
		void 
		throwAlways(std::string_view msg, Params&&... args) const {
			// BUG: this will result in the wrong error category
			throw std::system_error{this->Value, 
			                        std::system_category(),
			                        std::vformat(msg,std::make_format_args(args...)) + ". " + this->str()};
		}
		
		template <typename... Params>
		void 
		throwIfError(std::string_view msg, Params&&... args) const {
			if (this->Value < 0)
				// BUG: this will result in the wrong error category
				throw std::system_error{this->Value, 
										std::system_category(),
										std::vformat(msg,std::make_format_args(args...)) + ". " + this->str()};
		}
		
		std::wstring
		wstr() const {
			return cwiden(this->str());
		}
		
		explicit
		operator bool() const {
			return this->Value >= 0;
		}

		implicit 
		operator ::NTSTATUS() const {
			return this->Value;
		}
	};

	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Success-only status-code which throws when assigned a failure code
	*/
	class ThrowingNtStatus
	{
		::NTSTATUS Value;

	public:
		implicit
		ThrowingNtStatus(::NTSTATUS value, std::source_location loc = std::source_location::current()) 
		  : Value{value}
		{
			if (value < 0)
				throw win::system_error{value};	// BUG: this will result in the wrong error category
		}
		
	public:
		std::string
		str() const {
			return detail::formatMessage(this->Value);
		}

		explicit 
		operator bool() const {
			return this->Value >= 0;
		}

		implicit
		operator ::NTSTATUS() const {
			return this->Value;
		}
	};
}
