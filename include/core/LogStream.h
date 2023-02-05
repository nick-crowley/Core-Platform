#pragma once
#include "library/core.Platform.h"

namespace core
{
	enum class Severity {Verbose,Important,Warning,Failure};
	
	std::string_view
	inline to_string(Severity s) {
		switch (s) {
		default: 
		case Severity::Failure:  return "Failure";
		case Severity::Important:return "Important";
		case Severity::Warning:  return "Warning";
		case Severity::Verbose:  return "Verbose";
		}
	}

	template <Severity>
	class LogEntry;
	
	class LogStream
	{
		std::ostream* m_output;

	public:
		satisfies(LogStream,
			constexpr IsDefaultConstructible noexcept,
			NotCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);

		LogStream&
		operator=(std::ostream& out)
		{
			this->m_output = &out;
			return *this;
		}

	public:
		template <Severity S>
		LogStream&
		operator<<(LogEntry<S> const& entry);
		
		LogStream&
		operator<<(std::exception const& e) {
			this->write(Severity::Failure, e.what());
			return *this;
		}
		
	private:
		void
		write(Severity sev, std::string_view str) 
		{
			auto t = std::time(nullptr);
			auto tm = *std::localtime(&t);
			if (this->m_output)
			    *this->m_output << std::put_time(&tm, "[%H:%M:%S]")
			                    << " P-" << ::GetCurrentProcessId() 
			                    << " T-" << ::GetCurrentThreadId() 
			                    << " "   << to_string(sev)
			                    << " : " << str
			                    << std::endl;
		}
		
		void
		write(Severity sev, std::wstring_view wstr) {
			this->write(sev, core::to_string(wstr));
		}
	};

	template <Severity>
	class LogEntry 
	{
		template <Severity S>
		std::add_lvalue_reference_t<LogStream> 
		friend LogStream::operator<<(LogEntry<S> const&);

	private:
		std::variant<std::string,std::wstring>  Text;

	public:
		template <meta::ConvertibleTo<std::string_view,std::wstring_view> StringView>
		explicit
		LogEntry(meta::noformat_t, StringView msg)
		  : Text{msg}
		{}
		
		template <meta::ConvertibleTo<std::string_view,std::wstring_view> StringView, typename... Params>
		explicit
		LogEntry(StringView msg, Params&&... args)
		  : Text{std::vformat(msg,std::make_format_args(args...))}
		{}
	};

	template <Severity Sev>
	LogStream&
	LogStream::operator<<(LogEntry<Sev> const& entry) {
		if (auto* str = std::get_if<std::string>(&entry.Text))
			this->write(Sev,*str);
		else
			this->write(Sev,std::get<std::wstring>(entry.Text));
		return *this;
	}
	
	//! @brief	Error/failure log-entry
	using Failure = LogEntry<Severity::Failure>;
	
	//! @brief	High-level/important log-entry
	using Important = LogEntry<Severity::Important>;
	
	//! @brief	Warning log-entry
	using Warning = LogEntry<Severity::Warning>;
	
	//! @brief	Detailed/debug log-entry
	using Verbose = LogEntry<Severity::Verbose>;
	
	//! @brief	Line-orientated log-file
    LogStream constinit 
    inline clog;
}