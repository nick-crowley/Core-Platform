#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/implicit.h"
#include "win/SystemError.h"

namespace core::win::detail
{
	std::string 
	formatMessage(::LRESULT err);
}

namespace core::win
{
	class LResult
	{
		::LRESULT m_value;
	public:
		implicit
		LResult(::LRESULT value, std::source_location loc = std::source_location::current()) 
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
			throw system_error{this->m_value};
		}
		
		template <typename... Params>
		void 
		throwAlways [[noreturn]](std::string_view msg, Params&&... args) const {
			throw system_error{this->m_value, 
			                   std::vformat(msg,std::make_format_args(args...)) + ". " + this->str()};
		}
		
		template <typename... Params>
		void 
		throwIfError [[noreturn]](std::string_view msg, Params&&... args) const {
			throw system_error{this->m_value, 
			                   std::vformat(msg,std::make_format_args(args...)) + ". " + this->str()};
		}

		explicit operator
		bool() const {
			return this->m_value == ERROR_SUCCESS;
		}

		implicit operator
		::LRESULT() const {
			return this->m_value;
		}
	};
		
	struct LastError : public LResult 
	{
		LastError(std::source_location loc = std::source_location::current()) 
			: LResult{::GetLastError(), loc} 
		{}
	};

	class ThrowingLResult
	{
		::LRESULT m_value;
	public:
		implicit
		ThrowingLResult(::LRESULT value, std::source_location loc = std::source_location::current()) {
			if (value != ERROR_SUCCESS)
				throw system_error{value};
		}

	public:
		std::string
		str() const {
			return detail::formatMessage(this->m_value);
		}

		explicit operator
		bool() const {
			return this->m_value == ERROR_SUCCESS;
		}

		implicit operator
		::LRESULT() const {
			return this->m_value;
		}
	};
}
