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
#ifdef __clang__
#	error Clang doesn't support compiling LogStream.h yet
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "core/LogEntry.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core 
{
	class PlatformExport LogStream;
	
	//! @brief	Line-orientated log-file (symbol must be provided by consuming module)
	LogStream constinit
    extern PlatformExport clog;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta 
{	
	template <>
	struct DataType<program_name> : std::type_identity<std::string_view> {};

	template <>
	struct DataType<program_version> : std::type_identity<std::string_view> {};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
	class PlatformExport LogStream
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
        using ThreadIdCollection = std::unordered_map<std::thread::id,int>;

    private:
        ThreadIdCollection
        inline static CallDepth;
		
        std::recursive_mutex
        inline static IsWriting;
		
        char constexpr
#ifdef SUPPORT_UTF8_LOGFILE
        inline static PaddingChars[] = "\xe2\x95\x91\x20"; // UTF-8 encoded "║ "
#else
        inline static PaddingChars[] = "| ";
#endif
        
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
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
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		attach(std::ostream& out)
		{
			if (out)
				this->outputStream = &out;
		}
		
		void
		indent() {
			++LogStream::currentDepth();
		}

		void
		outdent() {
			--LogStream::currentDepth();
		}
		
		template <meta::lazy_t = lazy>
		void
		startupBanner() {
			if (!meta::Settings<program_name>.empty()) {
				size_t length {};
				if (meta::Settings<program_version>.empty()) {
					clog << Important{meta::Settings<program_name>};
					length = meta::Settings<program_name>.length();
				}
				else {
					using namespace std::literals;
					clog << Important{"{} (Ver: {})", meta::Settings<program_name>, meta::Settings<program_version>};
					length = meta::Settings<program_name>.length() + meta::Settings<program_version>.length() + " (Ver: )"sv.length();
				}
				clog << Important{std::string(length, '-')};
			}

			clog << Verbose{"Built using _WIN32_WINNT = v{}.{}", HIBYTE(_WIN32_WINNT), LOBYTE(_WIN32_WINNT)};
			clog << Verbose{"Built using _WIN32_IE = v{}.{}", HIBYTE(_WIN32_IE), LOBYTE(_WIN32_IE)};
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
		
		LogStream&
		operator<<(std::exception const& e) {
			if (!this->outputStream)
				return *this;

			std::lock_guard lock{LogStream::IsWriting};
			this->write(Severity::Failure, e.what());
			return *this;
		}
		
	private:
		void
		write(Severity sev, std::string_view str) 
		{
			*this->outputStream << std::format("[{:%H:%M:%OS}]", chrono::system_clock::now())
			                    << " P-" << std::setw(4) << std::left << ::GetCurrentProcessId() 
			                    << " T-" << std::setw(4) << std::left << std::this_thread::get_id()
			                    << " "   << std::setw(9) << std::left << as_string(sev)
			                    << " : " << nstd::repeat(LogStream::PaddingChars, LogStream::currentDepth()) << str
			                    << std::endl;
		}
		
		void
		write(Severity sev, std::wstring_view wstr) {
			this->write(sev, as_string(wstr));
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o