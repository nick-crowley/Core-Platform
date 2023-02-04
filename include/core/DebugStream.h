#pragma once
#include "library/core.Platform.h"

namespace core
{
	namespace detail 
	{
		class DebugStreamBuffer : public std::wstreambuf 
		{
			unsigned constexpr
			static inline BufferSize = 256;

		private:
			std::vector<wchar_t>  Storage;

		public:
			DebugStreamBuffer() : Storage(BufferSize) {
				this->setp(this->Storage.data(), this->Storage.data() + (BufferSize-1)); //-1 to make overflow() easier
			}

			satisfies(DebugStreamBuffer,
				NotCopyable,
				IsMovable,
				NotEqualityComparable,
				NotSortable
			);

		private:
			int_type 
			overflow(int_type ch) override {
				*this->pptr() = ch;
				this->pbump(1);
				this->sync();

				return ch;
			}

			int 
			sync() override {
				::OutputDebugStringW(this->Storage.data());
		
				ptrdiff_t const len = this->pptr() - this->pbase();
				this->pbump(static_cast<int>(-len));

				ranges::fill(this->Storage, L'\0');
				return 0;
			}
		};
	}

	class DebugStream : public std::wostream
	{
		using base = std::wostream;

	private:
		detail::DebugStreamBuffer Buffer;

	public:
		DebugStream() : base(&this->Buffer) {
		};
	};

	std::add_lvalue_reference_t<std::wostream>
	inline operator<<(std::wostream& os, const std::string& s) {
		return os << s.c_str();
	}
	
	namespace detail 
	{
		DebugStream
		inline cdebug;
	}

	std::add_lvalue_reference_t<std::wostream>
	inline cdebug = detail::cdebug;
}