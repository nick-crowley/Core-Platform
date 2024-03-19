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
#ifndef _SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING
#	error _SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING must be defined to build <LogFile.h>
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "filesystem/FileStream.h"
#include "win/Module.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail
{	
	//! @brief  Stream buffer which transforms special characters prior to file output
	template <typename Elem, typename Traits = std::char_traits<Elem>>
	class LogFileBuffer : public std::basic_streambuf<Elem, Traits>
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = LogFileBuffer<Elem, Traits>;
		using base = std::basic_streambuf<Elem, Traits>;
		
	public:
		using int_type = typename Traits::int_type;
		using pos_type = typename Traits::pos_type;
		using off_type = typename Traits::off_type;
		using streamsize = std::streamsize;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		size_t constexpr
		inline static DefaultCapacity = 4 * 1024;

	private:
		std::vector<Elem>       Buffer;
		filesystem::FileStream  File;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		LogFileBuffer(filesystem::path                         location, 
		              nstd::bitset<win::FileRight>             rights = win::GenericRight::Write,
		              nstd::bitset<filesystem::FileShare>      sharing = filesystem::FileShare::AllowRead,
		              nstd::bitset<filesystem::FileAttribute>  attributes = filesystem::FileAttribute::Normal) 
		  : Buffer(type::DefaultCapacity),
			File{filesystem::FileStream::CreateAlways, location, rights, sharing, attributes}
		{
			this->setp(this->Buffer.data(),
			           this->Buffer.data() + type::DefaultCapacity);
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(LogFileBuffer,
			NotDefaultConstructible,
			NotCopyable,
			IsMovable noexcept,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
        streamsize
		sputn(meta::noconversion_t, Elem const* str, streamsize n)
		{
			if (base::pptr() + n >= base::epptr())
				this->sync();

            Traits::copy(base::pptr(), str, static_cast<size_t>(n));
			base::pbump(static_cast<int>(n));
			return n;
		}

	protected:
		int_type 
		overflow(int_type ch = Traits::eof()) override 
		{ 
            if (Traits::eq_int_type(Traits::eof(), ch))
                return Traits::not_eof(ch); // EOF, return success code
            
			if (base::pptr() == base::epptr())
				this->sync();
			
            *this->pptr() = Traits::to_char_type(ch);
			this->pbump(1);
            return ch;
        }

        streamsize
		xsputn(Elem const* str, streamsize n) override 
		{
			for (streamsize idx = 0; idx < n; ++idx) {
				// Translate special characters into RTF equivalents
				switch (str[idx]) {
				case '{':
				case '}':
				case '\\':
					this->overflow('\\');
					break;

				case '\n':
					for (char const ch : R"(\line)" | views::take(5))
						this->overflow(ch);
					this->overflow('\n');
					continue;

				case '\t':
					for (char const ch : R"(\tab)" | views::take(4))
						this->overflow(ch);
					continue;
				}

				this->overflow(str[idx]);
			}
			return n;
		}

		int 
		sync() override {
			ptrdiff_t const length = this->pptr() - this->pbase();
			std::span<Elem> const buffer(this->Buffer.data(), length);
			this->File.write(std::as_bytes(buffer));
			this->pbump(static_cast<int>(-length));
			ranges::fill(buffer, '\0');
			return 0;
		}
	};
}
namespace core
{
	class LogFile : public std::ostream 
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using base = std::ostream;

	public:
		enum Colour : ::COLORREF
		{
			Auto = 0xfful << 24,
			Black = RGB(0x00,0x00,0x00),      //!< 
			Grey = RGB(0x80,0x80,0x80),       //!< 
			DarkGrey = RGB(0x24,0x24,0x24),   //!< 
			Blue = RGB(0x00,0x4B,0xff),       //!< 
			Green = RGB(0x32,0xcd,0x32),      //!< 
			Gold = RGB(0xff,0xff,0x00),       //!< 
			Orange = RGB(0xff,0xc3,0x00),     //!< 
			Red = RGB(0xff,0x00,0x05),        //!< 
			Magenta = RGB(0x64,0x00,0xff),    //!< 
			White = RGB(0xff,0xff,0xff),      //!< 
		};

	private:
		std::array constexpr 
		inline static ColourTable{Auto,   // Define colour 0 as 'auto-colour'
			Black, Grey, DarkGrey, Blue, Green, Gold, Orange, Red, Magenta, White
		};
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		detail::LogFileBuffer<char> StreamBuf;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		LogFile(std::string_view fileName)
		  : base{&this->StreamBuf},
			StreamBuf{win::ProcessModule.path().parent_path() / ThrowIfEmpty(fileName)}
		{
			this->header();
			this->fontSize(11);
		}

		~LogFile() {
			this->footer();
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(LogFile,
			NotDefaultConstructible,
			NotCopyable,
			IsMovable noexcept,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void 
		forecolour(Colour c)
		{
			if (auto const entry = ranges::find(LogFile::ColourTable, c); entry != LogFile::ColourTable.cend())
				this->write(R"(\cf{})", entry - LogFile::ColourTable.cbegin());
		}

	protected:
		void 
		codePage(unsigned cp)
		{
			this->write(R"(\ansicpg{})", cp);
		}
		
		template <nstd::InputRangeConvertibleTo<::COLORREF> ColourCollection>
		void
		colourTable(ColourCollection&& colours) {
			
			this->write(R"({\colortbl)");
			for (COLORREF const c : colours)
				if (c == Auto)
					this->write(";");
				else
					this->write(R"(\red{}\green{}\blue{};)", GetRValue(c), GetGValue(c), GetBValue(c));
			this->write("}\n");
		}
		
		void 
		defaultFont(unsigned idxFont)
		{
			this->write(R"(\deff{})", idxFont);
		}
		
		void 
		fontSize(unsigned pts)
		{
			this->write(R"(\fs{})", pts * 2);
		}
		
		template <nstd::InputRangeConvertibleTo<std::string_view> FontNameCollection>
		void
		fontTable(FontNameCollection&& names) {
			
			this->write(R"({\fonttbl)");
			for (std::string_view const name : names)
				this->write(R"({{\f0\fswiss\fcharset0 {};}})", name);
			this->write("}\n");
		}
		
		void 
		footer()
		{
			this->write("\\par\n}");
		}
		
		void  
		header()
		{
			// Header
			this->write(R"({\rtf1\ansi)");

			// Set codepage + language
			this->codePage(1250);
			this->defaultFont(0);
			this->language(2057);      // English UK  (0x0809 == 2057)
			this->write("\n");

			// Font + colour tables
			this->fontTable(std::vector{"Bahnschrift"});
			this->colourTable(LogFile::ColourTable);

			// Set view: 0==None, 1==Page Layout view, 2==Outline view, 3==Master Document view, 4==Normal view, 5==Online Layout view
			this->write(R"(\viewkind4)");

			// Set unicode destination to single byte
			this->write(R"(\uc1)");

			// Reset paragraph
			this->resetParagraph();
			this->write("\n");
		}
		
		void 
		language(unsigned id)
		{
			this->write(R"(\deflang{})", id);
		}

		void 
		resetParagraph()
		{
			this->write(R"(\pard)");
		}

		template <typename... Params>
		void 
		write(std::string_view msg, Params&&... args)
		{
			auto const str = std::vformat(msg, std::make_format_args(std::forward<Params>(args)...));
			this->StreamBuf.sputn(noconversion, str.c_str(), str.size());
		}
		
		template <>
		void 
		write(std::string_view msg)
		{
			this->StreamBuf.sputn(noconversion, msg.data(), msg.size());
		}
	};
}

namespace nstd
{
	template <typename Elem, typename Traits>
	std::basic_ostream<Elem,Traits>&
	grey(std::basic_ostream<Elem,Traits>& os) {
		if (auto* logStream = dynamic_cast<core::LogFile*>(&os); logStream) 
			logStream->forecolour(core::LogFile::Grey);
		return os;
	}

	template <typename Elem, typename Traits>
	std::basic_ostream<Elem,Traits>&
	blue(std::basic_ostream<Elem,Traits>& os) {
		if (auto* logStream = dynamic_cast<core::LogFile*>(&os); logStream) 
			logStream->forecolour(core::LogFile::Blue);
		return os;
	}
	
	template <typename Elem, typename Traits>
	std::basic_ostream<Elem,Traits>&
	orange(std::basic_ostream<Elem,Traits>& os) {
		if (auto* logStream = dynamic_cast<core::LogFile*>(&os); logStream) 
			logStream->forecolour(core::LogFile::Orange);
		return os;
	}

	template <typename Elem, typename Traits>
	std::basic_ostream<Elem,Traits>&
	red(std::basic_ostream<Elem,Traits>& os) {
		if (auto* logStream = dynamic_cast<core::LogFile*>(&os); logStream) 
			logStream->forecolour(core::LogFile::Red);
		return os;
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o