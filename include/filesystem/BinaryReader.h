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
	//! @brief  Reads trivially-copyable objects from a stream
	template <nstd::AnyCvOrSignOf<std::byte,char,wchar_t,char8_t,char16_t> Element>
	class BinaryReader
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = BinaryReader<Element>;      //!< Aliases our specialization
		using element_t = Element;               //!< Stream element type
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		IStream<element_t>* Input;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/*!
		* @brief  Construct from input stream
		*
		* @param[in]  input  Input stream
		*/
		explicit
		BinaryReader(IStream<element_t>& source)
		  : Input{&source}
		{
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(BinaryReader, 
			NotDefaultConstructible, 
			NotCopyable,
			IsMovable, 
			NotEqualityComparable, 
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/*!
		* @brief  Reads an object from the current position in the stream
		* 
		* @throws  std::invalid_argument  Insufficient space remaining to read an object of @c T
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Read operations on input stream not supported
		* @throws  std::system_error      Operation failed
		*/
		template <typename T>
			requires std::is_trivially_copyable_v<T>
		T 
		peek() const {
			T value = this->read<T>();
			this->Input->seek(Origin::Current, 0 - sizeof(T));
			return value;
		}
		
		/*!
		* @brief  Reads an object from the current position in the stream
		* 
		* @throws  std::exception         Insufficient space remaining to read an object of @c T
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Read operations on input stream not supported
		* @throws  std::system_error      Operation failed
		*/
		template <typename T>
			requires std::is_trivially_copyable_v<T>
		T 
		read() {
			std::vector<std::byte> bytes = this->Input->read(sizeof(T));
			return *reinterpret_cast<T*>(bytes.data());
		}
		
		/*!
		* @brief  Reads multiple objects from the current position in the stream
		* 
		* @param  n  Number of objects to read
		* 
		* @throws  std::exception         Insufficient space remaining to read an object of @c T
		* @throws  std::logic_error       Stream has been closed
		* @throws  std::logic_error       Read operations on input stream not supported
		* @throws  std::system_error      Operation failed
		*/
		template <typename T>
			requires std::is_trivially_copyable_v<T>
		std::vector<T> 
		read(size_t n) {
			ThrowIfZero(n);
			std::vector<T> values{n};
			for (auto idx = 0; idx < n; ++idx)
				values[idx] = this->read<T>();
			return values;
		}
		
		/*!
		* @brief  Skip arbitrary number of elements in the input stream
		* 
		* @param  n  Number of elements to skip
		*/
		void
		skip(size_t n) {
			this->Input->seek(Origin::Current, n);
		}
		
		/*!
		* @brief  Skip arbitrary number of objects in the input stream
		* 
		* @param  n  Number of objects to skip
		*/
		template <typename T>
		void
		skip(size_t n) {
			this->skip(nstd::sizeof_n<T>(n));
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};

	template <nstd::AnyCvOrSignOf<std::byte,char,wchar_t,char8_t,char16_t> Element>
	BinaryReader(IStream<Element>&) -> BinaryReader<Element>;
} 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o