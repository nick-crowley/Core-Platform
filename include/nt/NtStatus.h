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
	class NtStatus
	{
		::NTSTATUS m_value;

	public:
		implicit
		NtStatus(::NTSTATUS value, std::source_location loc = std::source_location::current()) 
		  : m_value{value}
		{
		}
		
	public:
		std::string
		str() const {
			return detail::formatMessage(this->m_value);
		}
		
		void 
		throwAlways [[noreturn]]() const {
			// BUG: this will result in the wrong error category
			throw std::system_error{this->m_value, std::system_category(), this->str()};
		}
		
		template <typename... Params> 
		void 
		throwAlways [[noreturn]](std::string_view msg, Params&&... args) const {
			// BUG: this will result in the wrong error category
			throw std::system_error{this->m_value, 
			                        std::system_category(),
			                        std::vformat(msg,std::make_format_args(args...)) + ". " + this->str()};
		}
		
		template <typename... Params>
		void 
		throwIfError(std::string_view msg, Params&&... args) const {
			if (this->m_value < 0)
				// BUG: this will result in the wrong error category
				throw std::system_error{this->m_value, 
										std::system_category(),
										std::vformat(msg,std::make_format_args(args...)) + ". " + this->str()};
		}

		explicit operator
		bool() const {
			return this->m_value >= 0;
		}

		implicit operator
		::NTSTATUS() const {
			return this->m_value;
		}
	};

	
	class ThrowingNtStatus
	{
		::NTSTATUS m_value;

	public:
		implicit
		ThrowingNtStatus(::NTSTATUS value, std::source_location loc = std::source_location::current()) 
		  : m_value{value}
		{
			if (value < 0)
				throw win::system_error{value};	// BUG: this will result in the wrong error category
		}
		
	public:
		std::string
		str() const {
			return detail::formatMessage(this->m_value);
		}

		explicit operator
		bool() const {
			return this->m_value >= 0;
		}

		implicit operator
		::NTSTATUS() const {
			return this->m_value;
		}
	};
}
