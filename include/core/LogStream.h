#pragma once
#include "library/core.Platform.h"
#include "core/LogEntry.h"

namespace core
{
	namespace detail {
		template <typename WritableValue>
		class repeat {
			using type = repeat<WritableValue>;

		private:
			WritableValue  value;
			uint32_t       count;

		public:
			repeat(WritableValue val, uint32_t num) : value{val}, count{num}
			{}

		public:
			std::type_identity_t<std::ostream&>
			friend operator<<(std::ostream& os, type const& repetition) {
				for (uint32_t idx = 0; idx < repetition.count; ++idx)
					os << repetition.value;
				return os;
			}
		};
	}

	class PlatformExport LogStream
	{
        using ThreadIdCollection = std::unordered_map<std::thread::id,int>;

    private:
        ThreadIdCollection
        inline static CallDepth;
		
        std::recursive_mutex
        inline static IsWriting;
		
        char constexpr
        inline static PaddingChars[] = "\xe2\x95\x91\x20"; // UTF-8 encoded "║ "
        
	private:
		std::ostream* outputStream;

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
			this->outputStream = &out;
			return *this;
		}

	private:
        std::type_identity_t<int&>
        static currentDepth() {
            return LogStream::CallDepth[std::this_thread::get_id()];
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
			if (this->outputStream)
				*this->outputStream << std::format("[{:%H:%M:%OS}]", chrono::system_clock::now())
			                        << " P-" << ::GetCurrentProcessId() 
			                        << " T-" << std::this_thread::get_id()
			                        << " "   << std::setw(9) << std::left << as_string(sev)
			                        << " : " << detail::repeat(LogStream::PaddingChars, LogStream::currentDepth()) << str
			                        << std::endl;
		}
		
		void
		write(Severity sev, std::wstring_view wstr) {
			this->write(sev, as_string(wstr));
		}
	};

	//! @brief	Line-orientated log-file
	LogStream constinit
    extern PlatformExport clog;
}