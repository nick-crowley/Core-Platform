#pragma once
#include "corePlatform.h"
#include "nt/Exception.h"

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
			if (value < 0)
				throw_exception(value);
		}
		
		implicit
		NtStatus(std::nothrow_t, ::NTSTATUS value, std::source_location loc = std::source_location::current()) 
		  : m_value{value}
		{
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
