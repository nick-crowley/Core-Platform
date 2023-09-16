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
#include "win/Module.h"
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
			ExistingProcessIdCollection() : base(static_cast<size_t>(256), 0) {
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
					if (this->Index != ConstIterator::npos)
						this->Index = this->findNext(0);
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
				findNext(uint32_t initialIndex) {
					auto constexpr
					static notSystemIdleProcess = [](::DWORD id){ return id != 0; };
					
					uint32_t idx = initialIndex;
					for (::DWORD pid : views::drop(*this->Idents, initialIndex) 
						             | views::filter(notSystemIdleProcess))
						if (SharedProcess tryOpen = Process::handleFromPid(pid, 
						                                                   this->Properties.AccessRights, 
						                                                   this->Properties.Inheritability); !tryOpen) {
							++idx;
						}
						else {
							this->Value = tryOpen;
							return idx;
						}

					return ConstIterator::npos;
				}

				void 
				increment() {
					if (this->Index != ConstIterator::npos)
						this->Index = this->findNext(this->Index + 1);
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
			bool
			empty() const = delete;

			size_type
			size() const = delete;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};

		//! @brief
		class PlatformExport LoadedModulesCollection : private std::vector<::HMODULE> {
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			using base = std::vector<::HMODULE>;

			auto constexpr
			static asWeakRefModule = [](::HMODULE h) { return Module{SharedModule{h, weakref}}; };

		public:
			using const_iterator = boost::transform_iterator<decltype(asWeakRefModule), base::const_iterator>;
			using iterator = const_iterator;
			using reference = Module&;
			using const_reference = Module const&;
			using value_type = Module;
			using size_type = std::size_t;
			using difference_type = std::ptrdiff_t;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			LoadedModulesCollection(SharedProcess process, Architecture arch)
			  : base(size_t{16}, nullptr)
			{
				auto constexpr
				static enumProcessModulesEx = [](SharedProcess process, std::vector<::HMODULE> modules, ::DWORD& bytesRequired, Architecture arch) {
					auto constexpr
					static convertFlags = [](Architecture a) {
						switch (a) {
						case Architecture::x64:  return LIST_MODULES_64BIT;
						case Architecture::x86:  return LIST_MODULES_32BIT;
						case Architecture::Both: return LIST_MODULES_ALL;
						default:                 return LIST_MODULES_DEFAULT;
						}
					};

					return EnumProcessModulesEx(
						*process, 
						modules.data(), 
						win::DWord{nstd::sizeof_n<::HMODULE>(modules.size())}, 
						&bytesRequired, 
						convertFlags(arch)
					);
				};

				::DWORD bytesRequired = 0;
				for (::BOOL result = enumProcessModulesEx(ThrowIfEmpty(process), *this, bytesRequired, arch); !result; /*no-op*/) {
					if (win::LastError err{}; err != ERROR_MORE_DATA)
						err.throwAlways("EnumProcessModulesEx() failed");

					this->resize(2 * this->size());
					result = enumProcessModulesEx(process, *this, bytesRequired, arch);
				}
				this->resize(bytesRequired / sizeof(::HMODULE));
			}
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(LoadedModulesCollection,
				NotDefaultConstructible,
				IsCopyable,
				IsMovable,
				NotEqualityComparable,
				NotSortable
			);
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			template <typename Self>
			const_iterator
			begin(this Self&& self) {
				return boost::make_transform_iterator(self.cbegin(), LoadedModulesCollection::asWeakRefModule);
			}

			template <typename Self>
			const_iterator
			end(this Self&& self) {
				return boost::make_transform_iterator(self.cend(), LoadedModulesCollection::asWeakRefModule);
			}

			using base::empty;
			using base::size;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};

	public:
		ExistingProcessCollection const
		static ExistingProcesses;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedProcess  Handle;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		explicit
		Process(SharedProcess p)
		  : Handle{ThrowIfEmpty(p)}
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
			if (SharedProcess handle = Process::handleFromPid(pid,rights,inheritance); !handle)
				LastError{}.throwAlways("OpenProcess() failed");
			else
				return Process{handle};
		}
	
	private:
		SharedProcess
		static handleFromPid(uint32_t pid, ProcessRight rights, std::optional<meta::inherits_t> inheritance = std::nullopt)
		{
			return SharedProcess{::OpenProcess(std::to_underlying(rights), Boolean{inheritance.has_value()}, pid)};
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		uint32_t
		id() const {
			return ::GetProcessId(*this->Handle);
		}

		LoadedModulesCollection
		modules() const {
			return LoadedModulesCollection{this->Handle, Architecture::x86|Architecture::x64};
		}

		filesystem::path
		path() const {
			auto constexpr usermodeFormat = 0;

			::DWORD      capacity{MAX_PATH};
			std::wstring buffer(capacity, L'\0');
			if (!::QueryFullProcessImageNameW(*this->Handle, usermodeFormat, buffer.data(), &capacity))
				LastError{}.throwAlways("QueryFullProcessImageNameW() failed");
			buffer.resize(capacity);
			return buffer;
		}

		security::Token
		token(TokenRight rights) const {
			auto const openProcessToken = function<1>(::OpenProcessToken);

			SharedToken tokenHandle{openProcessToken(*this->Handle, std::to_underlying(rights))};
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