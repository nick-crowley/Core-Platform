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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "security/ProcessRight.h"
#include "security/Token.h"
#include "security/TokenRight.h"
#include "win/Boolean.h"
#include "win/Function.h"
#include "win/SharedHandle.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	class PlatformExport Process
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		//! @brief	Snapshot of (the PIDs of) the currently executing processes
		class PlatformExport ExistingProcessIdCollection : private std::vector<::DWORD> {
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			using base = std::vector<::DWORD>;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			ExistingProcessIdCollection() : base{static_cast<size_t>(256), 0} {
				auto const
				static enumProcesses = [](std::vector<::DWORD>& storage, ::DWORD& bytesReturned) {
					return ::EnumProcesses(storage.data(), 
				                           win::DWord{nstd::sizeof_n<::DWORD>(storage.size())}, 
				                           &bytesReturned);
				};
				
				::DWORD bytesReturned{};
				for (::BOOL result = enumProcesses(*this, bytesReturned); !result; /*no-op*/) {
					if (win::LastError err{}; err != ERROR_MORE_DATA)
						err.throwAlways("EnumProcesses() failed");

					this->resize(2 * this->size());
					result = enumProcesses(*this, bytesReturned); 
				}
				this->resize(bytesReturned / sizeof(::DWORD));
			}
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(ExistingProcessIdCollection,
				IsMovable,
				NotEqualityComparable,
				NotSortable
			);
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		
			// o~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			using base::begin;
			using base::end;
			using base::cbegin;
			using base::cend;
			using base::empty;
			using base::size;
			using base::operator[];
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};

		//! @brief	Limited query handles to currently accessible executing processes
		class PlatformExport ExistingProcessCollection {
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			class ConstIterator : public boost::iterator_facade<ConstIterator, Process, std::forward_iterator_tag, Process>
			{
				friend class boost::iterator_core_access;
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				const uint32_t
				static npos = static_cast<uint32_t>(-1);

				struct ProcessHandleProperties {
					ProcessRight                    AccessRights;
					std::optional<meta::inherits_t> Inheritability;
				};
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				std::optional<ExistingProcessIdCollection> Idents;
				uint32_t                                   Index = npos;
				ProcessHandleProperties                    Properties;
				std::optional<SharedProcess>               Value;
				// o~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~o
			public:
				explicit
				ConstIterator(ProcessRight rights, std::optional<meta::inherits_t> inheritance = std::nullopt) 
				  : Idents{std::make_optional<ExistingProcessIdCollection>()},
				    Index{this->Idents->empty() ? npos : 0},
					Properties{rights, inheritance}
				{
					if (this->Index != npos)
						this->Index = this->findNext();
				}
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~o
			public:
				satisfies(ConstIterator,
					IsSemiRegular,
					NotSortable
				);
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

				// o~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				Process
				dereference() const {
					return Process{*this->Value};
				}
				
				bool 
				equal(ConstIterator const& other) const {
					return this->Index == other.Index;
				}
				// o~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				uint32_t 
				findNext() {
					for (uint32_t idx = this->Index; idx < this->Idents->size(); ++idx) 
						if (SharedProcess tryOpen{::OpenProcess(std::to_underlying(this->Properties.AccessRights), 
										                        Boolean{this->Properties.Inheritability.has_value()}, 
										                        (*this->Idents)[this->Index])}; tryOpen) {
							this->Value = std::make_optional(tryOpen);
							return idx;
						}
					return npos;
				}

				void 
				increment() {
					if (this->Index != npos)
						this->Index = this->findNext();
				}
			};

		public:
			using const_iterator = ConstIterator;
			using iterator = const_iterator;
			using reference = Process&;
			using const_reference = Process const&;
			using value_type = Process;
			using size_type = std::size_t;
			using difference_type = std::ptrdiff_t;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
			
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(ExistingProcessCollection,
				IsDefaultConstructible,
				NotCopyable,
				NotEqualityComparable,
				NotSortable
			);
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			template <typename Self>
			const_iterator
			begin(this Self&&, ProcessRight rights = ProcessRight::LimitedQuery, 
			                   std::optional<meta::inherits_t> inheritance = std::nullopt) {
				return const_iterator{rights, inheritance};
			}

			template <typename Self>
			const_iterator
			end(this Self&&) {
				return const_iterator{};
			}
			// o~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			size_type
			size() const = delete;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};

	public:
		ExistingProcessCollection const
		static ExistingProcesses;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedProcess  handle;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		explicit
		Process(SharedProcess p)
		  : handle{ThrowIfEmpty(p)}
		{
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(Process,
			NotDefaultConstructible,
			IsCopyable,
			IsMovable noexcept,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		Process
		static fromPid(uint32_t pid, ProcessRight rights, std::optional<meta::inherits_t> inheritance = std::nullopt)
		{
			if (SharedProcess handle{::OpenProcess(std::to_underlying(rights), Boolean{!!inheritance}, pid)}; !handle)
				LastError{}.throwAlways("OpenProcess() failed");
			else
				return Process{handle};
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		uint32_t
		id() const {
			return ::GetProcessId(*this->handle);
		}

		filesystem::path
		path() const {
			auto constexpr usermodeFormat = 0;

			::DWORD      capacity{MAX_PATH};
			std::wstring buffer(capacity, L'\0');
			if (!::QueryFullProcessImageNameW(*this->handle, usermodeFormat, buffer.data(), &capacity))
				LastError{}.throwAlways("QueryFullProcessImageNameW() failed");
			buffer.resize(capacity);
			return buffer;
		}

		security::Token
		token(TokenRight rights) const {
			auto const openProcessToken = function<1>(::OpenProcessToken);

			SharedToken tokenHandle{openProcessToken(*this->handle, std::to_underlying(rights))};
			return security::Token{tokenHandle};
		}

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	win::Process const
	inline static currentProcess {win::SharedProcess{::GetCurrentProcess(), weakref}};
}	
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o