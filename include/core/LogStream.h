﻿/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
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
#ifdef __clang__
#	error Clang doesn't support compiling LogStream.h yet
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "core/LogEntry.h"
#include "com/SharedPtr.h"
#include "win/SharedLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core 
{
	class PlatformExport LogStream;
	
	//! @brief	Line-orientated log-file
	LogStream constinit
    extern PlatformExport clog;
}

namespace nstd
{
	class fontsize {
	public:
		unsigned Height;
	};

	template <typename Elem, typename Traits = std::char_traits<Elem>>
	std::basic_ostream<Elem,Traits>&
	grey(std::basic_ostream<Elem,Traits>&);

	template <typename Elem, typename Traits = std::char_traits<Elem>>
	std::basic_ostream<Elem,Traits>&
	blue(std::basic_ostream<Elem,Traits>&);
	
	template <typename Elem, typename Traits = std::char_traits<Elem>>
	std::basic_ostream<Elem,Traits>&
	orange(std::basic_ostream<Elem,Traits>&);

	template <typename Elem, typename Traits = std::char_traits<Elem>>
	std::basic_ostream<Elem,Traits>&
	red(std::basic_ostream<Elem,Traits>&);

	template <typename Elem, typename Traits = std::char_traits<Elem>>
	return_t<std::basic_ostream<Elem,Traits>&>
	operator<<(std::basic_ostream<Elem,Traits>& os, fontsize f);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
	class PlatformExport LogStream
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
        using ThreadIdCollection = std::unordered_map<std::thread::id,int>;

        char constexpr
        inline static PaddingChars[] = "\xe2\x95\x91\x20"; // UTF-8 encoded "║ "
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    private:
        ThreadIdCollection
        inline static CallDepth;
		
        std::recursive_mutex
        inline static IsWriting;
		
	private:
		std::ostream* outputStream = nullptr;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(LogStream,
			constexpr IsDefaultConstructible noexcept,
			NotCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
        nstd::return_t<int&>
        static currentDepth() {
            return LogStream::CallDepth[std::this_thread::get_id()];
        }

		auto
		static entryColour(Severity sev) {
			switch (sev) {
			case Severity::Heading:
			case Severity::Important: return nstd::blue<char>;
			case Severity::Failure:   return nstd::red<char>;
			case Severity::Warning:   return nstd::orange<char>;
			case Severity::Verbose:   return nstd::grey<char>;
			default:                  std::unreachable();
			}
		}
		
        std::string
        static prettyStackTrace(std::stacktrace const& trace)
        {
	        using enum std::regex_constants::match_flag_type;

            std::regex const 
	        static stripModulesAndOffsets{R"(^(\d+>\s+)[A-Za-z0-9_]+!([a-zA-Z0-9_<>:]+)\+0x[A-Ea-e0-9]+)"};

            return std::regex_replace(std::to_string(trace), stripModulesAndOffsets, R"($1$2())", match_not_null);
        }
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		attach(std::ostream& out) {
			if (out)
				this->outputStream = &out;
		}
		
		void
		createLogFile(std::string_view fileName);
		
		void
		indent() {
			++LogStream::currentDepth();
		}

		void
		outdent() {
			--LogStream::currentDepth();
		}
		
		LogStream&
		operator+=(std::ostream& out) {
			this->attach(out);
			return *this;
		}
		
		template <Severity Level>
		LogStream&
		operator<<(LogEntry<Level> const& entry) {
			if (!this->outputStream)
				return *this;

			std::lock_guard lock{LogStream::IsWriting};
			if (auto* str = std::get_if<std::string>(&entry.Text))
				this->write(Level, *str);
			else
				this->write(Level, std::get<std::wstring>(entry.Text));
			return *this;
		}
		
		template <>
		LogStream&
		operator<<(Heading const& entry) {
			if (!this->outputStream)
				return *this;

			std::lock_guard lock{LogStream::IsWriting};
			if (auto const* str = std::get_if<std::string>(&entry.Text)) {
				this->write(Severity::Important, *str);
				std::stringstream underline;
				underline << nstd::repeat{"\xe2\x95\x90", str->length()};
				this->write(Severity::Important, underline.str());
			}
			else if (auto const* wstr = std::get_if<std::wstring>(&entry.Text)) {
				this->write(Severity::Important, *wstr);
				std::wstringstream underline;
				underline << nstd::repeat{"\xe2\x95\x90", wstr->length()};
				this->write(Severity::Important, underline.str());
			}
			return *this;
		}
		
		LogStream&
		operator<<(std::exception const& e) {
			if (!this->outputStream)
				return *this;

			std::lock_guard lock{LogStream::IsWriting};
			if (auto* trace = dynamic_cast<std::stacktrace const*>(&e); !trace)
				this->write(Severity::Failure, e.what());
			else 
				this->write(Severity::Failure, std::format("{}\n{}", e.what(), LogStream::prettyStackTrace(*trace)));
			return *this;
		}
		
	private:
		void
		write(Severity sev, std::string_view str) 
		{
			*this->outputStream << LogStream::entryColour(sev) << nstd::fontsize{9u}
			                    << std::format("[{:%H:%M:%OS}]", chrono::system_clock::now())
			                    << " S-" << std::to_underlying(sev)
			                    << " P-" << std::setw(4) << std::left << ::GetCurrentProcessId()
			                    << " T-" << std::setw(4) << std::left << std::this_thread::get_id()
			                    << nstd::fontsize{11u}
			                    << " : " << nstd::repeat(LogStream::PaddingChars, LogStream::currentDepth())
			                    << str << "\n";
			this->outputStream->flush();
		}
		
		void
		write(Severity sev, std::wstring_view wstr) {
			this->write(sev, as_string(wstr));
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
	::HRESULT
	inline appendSymbolPath(std::string_view path) 
	{
		win::SharedLibrary const libDbgEng{L"dbgeng.dll", win::SharedLibrary::SearchSystem32};
		auto* const debugCreate = libDbgEng.loadFunction<decltype(::DebugCreate)>("DebugCreate");
		
		// Note from CRT: 
		//   "Deliberately not calling CoInitialize[Ex]. 
		//    <DbgEng.h> API works fine without it.
		//    COM initialization may have undesired interference with user's code."
		com::shared_ptr<IDebugSymbols> debugSymbols;
		win::HResult hr = debugCreate(IID_IDebugClient, std::out_ptr(debugSymbols));
		hr.throwIfError("DebugCreate() failed");
		return debugSymbols->AppendSymbolPath(".");
	}

	void
	inline startupBanner()
	{
		if (!meta::Settings<program_name>.empty() && !meta::Settings<program_version>.empty()) 
			clog << Heading{"{} (Ver: {})", meta::Settings<program_name>, meta::Settings<program_version>};

		else if (!meta::Settings<program_name>.empty()) 
			clog << Heading{meta::Settings<program_name>};

		clog << Verbose{"Built using _WIN32_WINNT = v{}.{}", HIBYTE(_WIN32_WINNT), LOBYTE(_WIN32_WINNT)};
		clog << Verbose{"Built using _WIN32_IE = v{}.{}", HIBYTE(_WIN32_IE), LOBYTE(_WIN32_IE)};
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o