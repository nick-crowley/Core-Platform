/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2018, Nick Crowley. All rights reserved.
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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.platform.h"
#include "filesystem/IStream.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem 
{	
	//! @brief  Stream abstraction over a fixed-length buffer
	template <nstd::AnyCvOrSignOf<std::byte,char,wchar_t,char8_t,char16_t> Element>
	class MemoryStream : public IStream<Element>
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = MemoryStream;         //!< Aliases our specialization
		using base = IStream<Element>;     //!< Aliases our base
		
	protected:
		using base::OperationIsSupportedSentry;
		using base::StreamIsOpenSentry;

	public:
		using base::element_t;
		using base::difference_type;
		using base::size_type;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		std::span<element_t> Content;
		size_type            Position = 0;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/*!
		* @brief  Construct from range of (possibly const-qualified) bytes
		*
		* @param[in]  source  Input range of bytes
		* 
		* @throws  std::invalid_argument  Range is empty
		*/
		explicit
		MemoryStream(std::span<element_t> source)
		  : Content{ThrowIfEmpty(source)}
		{}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(MemoryStream, 
			NotDefaultConstructible, 
			IsMovable, 
			NotEqualityComparable, 
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief  Implements IStream::closed() const noexcept
		bool
		virtual closed() const noexcept override {
			return false;
		}

		//! @brief  Implements IStream::length() const
		size_type
		virtual length() const override {
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Seek};
			return this->Content.size();
		}

		//! @brief  Implements IStream::position() const
		size_type 
		virtual position() const override {
			StreamIsOpenSentry{*this};
			return this->Position;
		}

		//! @brief  Implements IStream::supports() const
		nstd::bitset<Operation>
		virtual supports() const noexcept override {
			if constexpr (std::is_const_v<element_t>)
				return Operation::Read | Operation::Seek;
			else
				return Operation::Read | Operation::Seek | Operation::Write;
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief  Implements IStream::close()
		void
		virtual close() override {
			StreamIsOpenSentry{*this};
			/*no-op*/
		}
	
		//! @brief  Implements IStream::flush()
		void
		virtual flush() override {
			StreamIsOpenSentry{*this};
			/*no-op*/
		}

		//! @brief  Implements IStream::read()
		std::vector<std::remove_const_t<element_t>>
		virtual read(size_type n) override {
			ThrowIfZero(n);
			ThrowIf(n, n > this->remaining());
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Read};
		
			// Read from current position
			auto bytes = this->Content.subspan(this->position(), n);
			this->Position += n;
			return std::vector<std::remove_const_t<element_t>>(bytes.begin(), bytes.end());
		}

		//! @brief	Implements IStream::readAll()
		std::vector<std::remove_const_t<element_t>>
		virtual readAll() override {
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Read};

			// Read remainder of stream
			auto bytes = this->read(this->length() - this->position());
			this->close();
			return bytes;
		}
		
		//! @brief  Number of elements between current position and end-of-stream
		size_type
		remaining() const noexcept {
			return this->length() - this->position();
		}

		//! @brief  Implements IStream::resize()
		[[noreturn]]
		void
		virtual resize([[maybe_unused]] size_type length) override {
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Resize};
			std::unreachable();
		}
	
		//! @brief  Implements IStream::seek()
		size_type
		virtual seek(Origin from, difference_type n) override {
			ThrowIfUndefined(from);
			ThrowIfZero(n);
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Seek};

			auto const currentPosition = static_cast<difference_type>(this->position());
			auto const currentLength = static_cast<difference_type>(this->length());
			switch (from) {
			case Origin::Begin:
				ThrowIf(n, n < 0);
				ThrowIf(n, n > currentLength);
				this->Position = n;
				break;

			case Origin::Current:
				ThrowIf(n, (n < 0) && (currentPosition - n < 0));
				ThrowIf(n, (n > 0) && (currentPosition + n > currentLength));
				this->Position += n;
				break;

			case Origin::End:
				ThrowIf(n, n > 0);
				ThrowIf(n, std::abs(n) > currentLength);
				this->Position = currentLength - std::abs(n);
				break;
			}
			
			return this->Position;
		}

		//! @brief  Implements IStream::write()
		size_type
		virtual write(gsl::span<element_t const> data) override {
			ThrowIfEmpty(data);
			ThrowIf(data, data.size() > this->remaining());
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Write};
			
			// Write data to stream at current position
			if constexpr (std::is_const_v<element_t>)
				std::unreachable();
			else {
				ranges::copy(data, this->Content.begin() + this->Position);
				this->Position += data.size();
				return data.size();
			}
		}

		//! @brief  Implements IStream::write_all()
		void
		virtual writeAll(gsl::span<element_t const> data) override {
			ThrowIfEmpty(data);
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Write};

			// Write data and close handle
			this->write(data);
			this->close();
		}
	};

	template <nstd::AnyCvOrSignOf<std::byte,char,wchar_t,char8_t,char16_t> Element>
	MemoryStream(std::span<Element>) -> MemoryStream<Element>;
} 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o