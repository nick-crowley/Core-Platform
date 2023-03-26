#pragma once
#include "library/core.Platform.h"

namespace core
{
	enum class Severity {Verbose,Important,Warning,Failure};
	
	std::string_view
	inline to_string(Severity s) {
		using enum Severity;
		switch (s) {
		default: return "Invalid";
#define _CaseStringify(value)  \
			case value: return #value
		_CaseStringify(Failure);
		_CaseStringify(Important);
		_CaseStringify(Warning);
		_CaseStringify(Verbose);
#undef _CaseStringify
		}
	}

	template <Severity>
	class LogEntry 
	{
	public:
		std::variant<std::string,std::wstring> const  Text;

	public:
		template <nstd::ConvertibleToAnyOf<std::string_view,std::wstring_view> StringView>
		explicit
		LogEntry(meta::noformat_t, StringView msg)
		  : Text{msg}
		{}
		
		template <nstd::ConvertibleToAnyOf<std::string_view,std::wstring_view> StringView, typename... Params>
		explicit
		LogEntry(StringView msg, Params&&... args)
		  : Text{std::vformat(msg,std::make_format_args(args...))}
		{}
	};

	//! @brief	Error/failure log-entry
	using Failure = LogEntry<Severity::Failure>;
	
	//! @brief	High-level/important log-entry
	using Important = LogEntry<Severity::Important>;
	
	//! @brief	Warning log-entry
	using Warning = LogEntry<Severity::Warning>;
	
	//! @brief	Detailed/debug log-entry
	using Verbose = LogEntry<Severity::Verbose>;
}