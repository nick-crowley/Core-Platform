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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem 
{
	//! @brief	Stream element encoding
	enum class Encoding {
		Ascii,
		Binary,
		Utf8,
		Utf16,
	};

	//! @brief	Supported stream operations
	enum class Operation{
		None,
		Read,
		Write,
		Seek,
		Resize,
	};
} 

//! @brief	@c core::filesystem::Operation is a bitflag
metadata bool core::meta::Settings<core::bitwise_enum, core::filesystem::Operation> = true;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem 
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Common interface for stream classes
	* 
	* @todo		Add IStream::lock() and IStream::unlock() methods
	*/
	template <nstd::AnyCvOrSignOf<std::byte,char,wchar_t,char8_t,char16_t> Element>
	struct IStream
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		//! @brief 	Aliases our own type
		using type = IStream<Element>;

	protected:
		//! @brief 	Sentry type which ensures stream supports an operation
		struct OperationIsSupportedSentry {
			OperationIsSupportedSentry(type const& obj, Operation op) {
				if (!obj.supports().test(op)) 
					throw core::logic_error{"{} operations are not supported", op};
			}
		};
	
		//! @brief 	Sentry type which ensures stream is not closed
		struct StreamIsOpenSentry {
			explicit
			StreamIsOpenSentry(type const& obj) {
				if (obj.closed()) 
					throw std::logic_error{"Stream has been closed"};
			}
		};

	public:
		using element_t = Element;             //!< Stream element type
		using difference_type = std::int64_t;  //!< Stream offset type
		using size_type = std::uint64_t;       //!< Stream length/position type
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	protected:
		satisfies(IStream,
			IsInterface
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Query whether stream has been closed
		*
		* @return  True iff already closed
		*/
		bool
		virtual closed() const noexcept abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieve stream length
		*
		* @return  Stream length in elements
		*
		* @throws  std::logic_error  Stream has been closed
		* @throws  std::logic_error  Stream has no @c length property
		*/
		size_type
		virtual length() const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Retrieve current read/write position
		*
		* @return  Position (in elements)
		*
		* @throws  std::logic_error  Stream has been closed
		* @throws  std::logic_error  Stream has no @c position property
		*/
		size_type 
		virtual position() const abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Query which operations the stream supports
		*
		* @return  Bit-flag reflecting supported operations
		*/
		nstd::bitset<Operation>
		virtual supports() const noexcept abstract;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Closes the stream and releases all resources (thus preventing any further operations)
		*
		* @throws  std::logic_error   Stream has been closed
		* @throws  std::system_error  Operation failed
		*/
		void
		virtual close() abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Flushes any/all internal buffers to the underlying medium
		* 
		* @throws  std::logic_error   Stream has been closed
		* @throws  std::system_error  Operation failed
		*/
		void
		virtual flush() abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Reads (up to) @p n elements from the current position
		*
		* @param[in]  n  Number of elements to read
		*
		* @return  Elements successfully extracted from stream (possibly less than @p n)
		* 
		* @throws  std::invalid_argument  Invalid number of elements to read
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Read operations not supported
		* @throws  std::system_error      Operation failed
		*/
		std::vector<element_t>
		virtual read(size_type n) abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Reads all elements from the current position then closes the stream
		*
		* @return  Elements successfully extracted from stream
		* 
		* @throws  std::invalid_argument  Invalid number of elements to read
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Read operations not supported
		* @throws  std::system_error      Operation failed
		*/
		std::vector<element_t>
		virtual readAll() abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Enlarge or truncate the length of the stream
		*
		* @param[in]  n  New maximum length, in elements
		*
		* @throws  std::logic_error   Stream has been closed
		* @throws  std::logic_error   Resize operations not supported
		* @throws  std::system_error  Operation failed
		*/
		void
		virtual resize(size_type length) abstract;
	
		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Adjusts the current read/write position
		*
		* @param[in]  from  Whether movement is relative or absolute
		* @param[in]  n     Offset (in elements) by which to adjust position
		* 
		* @returns  New position following seek
		* 
		* @throws  std::logic_error   Stream has been closed
		* @throws  std::logic_error   Seek operations not supported
		* @throws  std::system_error  Operation failed
		*/
		size_type
		virtual seek(Origin from, difference_type n) abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Writes (up to) @p n elements at the current position
		*
		* @param[in]  data  Elements to write
		*
		* @return  Number of elements written to stream (possibly less @p bytes.size())
		* 
		* @throws  std::invalid_argument  Empty data range
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Write operations not supported
		* @throws  std::system_error      Operation failed
		*/
		size_type
		virtual write(gsl::span<element_t const> data) abstract;

		/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
		* @brief  Writes @p n elements at current position before closing the stream
		*
		* @param[in]  data  Elements to write
		* 
		* @throws  std::invalid_argument  Empty data range
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Write operations not supported
		* @throws  std::system_error      Operation failed
		*/
		void
		virtual writeAll(gsl::span<element_t const> data) abstract;
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o