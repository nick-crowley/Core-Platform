#pragma once
#include "library/core.Platform.h"
#include "core/LogEntry.h"

namespace core
{
	class PlatformExport LogStream
	{
        using ThreadIdCollection = std::unordered_map<std::thread::id,int>;

    private:
        ThreadIdCollection
        inline static CallDepth;
		
        std::recursive_mutex
        inline static IsWriting;
		
        char constexpr
        inline static PaddingChars[] = "                      ";
        
	private:
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

	private:
        std::type_identity_t<int&>
        static currentDepth() {
            return LogStream::CallDepth[std::this_thread::get_id()];
        }

        std::string_view
        static padding() {
            auto const charCount = std::clamp<int>(2*LogStream::currentDepth(), 0, lengthof(LogStream::PaddingChars)-3);
            return { 
                LogStream::PaddingChars, 
                LogStream::PaddingChars + charCount
            };
        }

	public:
		void
		indent() {
			++LogStream::currentDepth();
		}

		void
		outdent() {
			--LogStream::currentDepth();
		}

		template <Severity Level>
		LogStream&
		operator<<(LogEntry<Level> const& entry) {
			std::lock_guard lock{LogStream::IsWriting};
			if (auto* str = std::get_if<std::string>(&entry.Text))
				this->write(Level, *str);
			else
				this->write(Level, std::get<std::wstring>(entry.Text));
			return *this;
		}
		
		LogStream&
		operator<<(std::exception const& e) {
			std::lock_guard lock{LogStream::IsWriting};
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
			                    << " "   << std::setw(9) << std::left << core::to_string(sev)
			                    << " : " << LogStream::padding() << str
			                    << std::endl;
		}
		
		void
		write(Severity sev, std::wstring_view wstr) {
			this->write(sev, core::to_string(wstr));
		}
	};

	//! @brief	Line-orientated log-file
	LogStream constinit
    extern PlatformExport clog;
}