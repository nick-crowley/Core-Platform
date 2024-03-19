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
#include "filesystem/FileSystemApi.h"
#include "filesystem/IStream.h"
#include "filesystem/SharedHandle.h"
#include "core/LogStream.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::filesystem 
{	
	//! @brief  Stream abstraction over file/device I/O
	struct FileStream : public IStream<std::byte>
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = FileStream;           //!< Aliases our specialization
		using base = IStream<std::byte>;   //!< Aliases our base

	public:
		using CreateBehaviour = FileSystemApi::CreateBehaviour;
		using enum FileSystemApi::CreateBehaviour;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedFile           Handle;
		SharedFileSystemApi  Api;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		/*!
		* @brief  Construct from already opened handle
		*
		* @param[in]  h    Opened file handle
		* @param[in]  api  [optional] Implementation of filesystem API (or mock)
		* 
		* @throws  std::invalid_argument  Missing argument
		*/
		explicit
		FileStream(SharedFile h, SharedFileSystemApi api = filesystemApi())
		  : Handle{ThrowIfEmpty(h)},
			Api{ThrowIfEmpty(api)}
		{
			//! @todo	Query whether handle @p h posseses rights for reading and/or writing
		}
		
		/*!
		* @brief  Open existing file (or handle to device)
		*
		* @param[in] location   Name of the file (or device) to open
		* @param[in] rights     [optional] Requested access for (the handle to) the file/device
		* @param[in] sharing    [optional] Requested sharing mode of the file/device
		* @param[in] attributes [optional] Attributes to apply upon creation
		* @param[in] api        [optional] Implementation of filesystem API (or mock)
		* 
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::runtime_error     File does not exist
		*/
		FileStream(path                         location, 
		           nstd::bitset<win::FileRight> rights = win::GenericRight::Read,
		           nstd::bitset<FileShare>      sharing = FileShare::AllowRead,
		           nstd::bitset<FileAttribute>  attributes = FileAttribute::Normal,
		           SharedFileSystemApi          api = filesystemApi()
		) : Handle{ThrowIfEmpty(api)->createFile(location, FileSystemApi::OpenExisting, rights, sharing, attributes)},
			Api{ThrowIfEmpty(api)}
		{
		}
		
		/*!
		* @brief  Create new file (or handle to device)
		*
		* @param[in] location   Name of the file (or device) to be created
		* @param[in] rights     [optional] Requested access for (the handle to) the file/device
		* @param[in] sharing    [optional] Requested sharing mode of the file/device
		* @param[in] attributes [optional] Attributes to apply upon creation
		* @param[in] api        [optional] Implementation of filesystem API (or mock)
		* 
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::runtime_error     File already exists
		*/
		FileStream(meta::create_new_t, 
		           path                         location, 
		           nstd::bitset<win::FileRight> rights = win::StandardRight::Read|win::StandardRight::Write,
		           nstd::bitset<FileShare>      sharing = FileShare::DenyAll,
		           nstd::bitset<FileAttribute>  attributes = FileAttribute::Normal,
		           SharedFileSystemApi          api = filesystemApi()
		) : Handle{ThrowIfEmpty(api)->createFile(location, FileSystemApi::CreateNew, rights, sharing, attributes)},
			Api{ThrowIfEmpty(api)}
		{
		}
		
		/*!
		* @brief  Create/open/truncate new file (or handle to device)
		*
		* @param[in] exists     Behaviour when file already exists
		* @param[in] location   Name of the file (or device) to be created
		* @param[in] rights     [optional] Requested access for (the handle to) the file/device
		* @param[in] sharing    [optional] Requested sharing mode of the file/device
		* @param[in] attributes [optional] Attributes to apply upon creation
		* @param[in] api        [optional] Implementation of filesystem API (or mock)
		* 
		* @throws  std::invalid_argument  Missing argument
		* @throws  std::system_error      Operation failed
		*/
		FileStream(CreateBehaviour              exists,
		           path                         location, 
		           nstd::bitset<win::FileRight> rights = win::StandardRight::Read|win::StandardRight::Write,
		           nstd::bitset<FileShare>      sharing = FileShare::DenyAll,
		           nstd::bitset<FileAttribute>  attributes = FileAttribute::Normal,
		           SharedFileSystemApi          api = filesystemApi()
		) : Handle{ThrowIfEmpty(api)->createFile(location, exists, rights, sharing, attributes)},
			Api{ThrowIfEmpty(api)}
		{
		}
		
		//! @brief  Close stream upon destruction
		~FileStream() {
			try {
				if (!this->closed())
					this->close();
			}
			catch (std::exception const& e) {
				clog << Warning{"Failed to close file handle: {}", e.what()};
			}
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(FileStream, 
			NotDefaultConstructible, 
			NotCopyable,
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
			return this->Handle.empty();
		}

		//! @brief  Implements IStream::length() const
		size_type
		virtual length() const override {
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Seek};

			return this->Api->getFileSize(this->Handle);
		}

		//! @brief  Implements IStream::position() const
		size_type 
		virtual position() const override {
			StreamIsOpenSentry{*this};
			
			return this->Api->setFilePointer(this->Handle, Origin::Current, 0);
		}

		//! @brief  Implements IStream::supports() const
		nstd::bitset<Operation>
		virtual supports() const noexcept override {
			return Operation::Read | Operation::Resize | Operation::Seek | Operation::Write;
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief  Implements IStream::close()
		void
		virtual close() override {
			StreamIsOpenSentry{*this};

			this->Handle.reset();
		}
	
		//! @brief  Implements IStream::flush()
		void
		virtual flush() override {
			StreamIsOpenSentry{*this};

			this->Api->flushFileBuffers(this->Handle);
		}

		//! @brief  Implements IStream::read()
		std::vector<element_t>
		virtual read(size_type n) override {
			ThrowIfZero(n);
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Read};
		
			// Read from file/device
			return this->Api->readFile(this->Handle, uint32_t(n));
		}

		//! @brief	Implements IStream::readAll()
		std::vector<element_t>
		virtual readAll() override {
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Read};

			// Read from file/device and close handle
			auto data = this->Api->readFile(this->Handle, uint32_t(this->length() - this->position()));
			this->close();
			return data;
		}

		//! @brief  Implements IStream::resize()
		void
		virtual resize(size_type length) override {
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Resize};

			// Modify file length and preserve initial position if possible
			auto const initialPosition = this->Api->setFilePointer(this->Handle, Origin::Current, 0);
			this->Api->setFilePointer(this->Handle, Origin::Begin, length);
			this->Api->setEndOfFile(this->Handle);
			if (static_cast<size_type>(initialPosition) < length)
				this->Api->setFilePointer(this->Handle, Origin::Begin, initialPosition);
		}
	
		//! @brief  Implements IStream::seek()
		size_type
		virtual seek(Origin from, difference_type n) override {
			ThrowIfUndefined(from);
			ThrowIfZero(n);
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Seek};

			return this->Api->setFilePointer(this->Handle, from, n);
		}

		//! @brief  Implements IStream::write()
		size_type
		virtual write(gsl::span<element_t const> data) override {
			ThrowIfEmpty(data);
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Write};

			// Write data
			this->Api->writeFile(this->Handle, data);
			return data.size();
		}

		//! @brief  Implements IStream::write_all()
		void
		virtual writeAll(gsl::span<element_t const> data) override {
			ThrowIfEmpty(data);
			StreamIsOpenSentry{*this};
			OperationIsSupportedSentry{*this, Operation::Write};

			// Write data and close handle
			this->Api->writeFile(this->Handle, data);
			this->close();
		}
	};
} 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
