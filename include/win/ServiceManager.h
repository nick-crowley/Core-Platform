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
#include "security/ServiceManagerRight.h"
#include "win/Service.h"
#include "win/SharedHandle.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	class PlatformExport ServiceManager
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:	
		//! @brief  Wrapper for variable-length service snapshot data
		class InstalledService {
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			SharedServiceManager         ManagerHandle;
			::ENUM_SERVICE_STATUS const& ServiceData;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			InstalledService(SharedServiceManager scm, ::ENUM_SERVICE_STATUS const& data) 
			  : ManagerHandle{std::move(scm)},
				ServiceData{data}
			{}
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(InstalledService, 
				NotDefaultConstructible,
				IsCopyable,
				IsMovable noexcept,
				NotSortable,
				NotEqualityComparable
			);
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			std::wstring
			displayName() const {
				return this->ServiceData.lpDisplayName;
			}

			std::wstring
			name() const {
				return this->ServiceData.lpServiceName;
			}

			Service
			open(ServiceRight rights) const {
				return ServiceManager{this->ManagerHandle}.open(this->name(), rights);
			}

			ServiceStatus
			status() const {
				return static_cast<ServiceStatus>(this->ServiceData.ServiceStatus.dwCurrentState);
			}
		};

		//! @brief	Virtual collection of currently installed services
		//! @remarks  Iteration occurs over a snapshot taken at enumeration time
		class InstalledServicesCollection {
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			//! @brief  Navigates over snapshot of all currently installed services
			class ConstIterator : public boost::iterator_facade<ConstIterator, InstalledService const, boost::forward_traversal_tag>
			{
				friend class boost::iterator_core_access;
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				using SharedServiceStatusArray = std::shared_ptr<::ENUM_SERVICE_STATUS[]>;
				using SharedInstallServiceArray = std::shared_ptr<InstalledService[]>;

				ptrdiff_t constexpr
				static npos = -1;
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				ptrdiff_t                                Index = ConstIterator::npos;
				size_t                                   NumServices = 0;
				std::optional<SharedServiceStatusArray>  DataStorage;
				std::optional<SharedInstallServiceArray> Services;
				std::optional<SharedServiceManager>      ManagerHandle;
				// o~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~o
			public:
				explicit
				ConstIterator(SharedServiceManager manager)
				{
					DWORD bytesNeeded{}, numServices{}, idxStart{};
					::EnumServicesStatusW(*ThrowIfEmpty(manager), SERVICE_DRIVER|SERVICE_WIN32, SERVICE_STATE_ALL, nullptr, 0, &bytesNeeded, &numServices, &idxStart);
					if (LastError err; err != ERROR_MORE_DATA) 
						LastError{}.throwAlways("EnumServicesStatusW() failed");
					else {
						auto buffer = std::reinterpret_pointer_cast<::ENUM_SERVICE_STATUS[]>(
							std::make_shared_for_overwrite<std::byte[]>(bytesNeeded)
						);
						if (!::EnumServicesStatusW(*manager, SERVICE_DRIVER|SERVICE_WIN32, SERVICE_STATE_ALL, buffer.get(), bytesNeeded, &bytesNeeded, &numServices, &idxStart))
							LastError{}.throwAlways("EnumServicesStatusW({} bytes) failed", bytesNeeded);

						auto wrappers = std::reinterpret_pointer_cast<InstalledService[]>(
							std::make_shared_for_overwrite<std::byte[]>(nstd::sizeof_n<InstalledService>(numServices))
						);
						for (unsigned idx = 0; idx < numServices; ++idx)
							std::construct_at(&wrappers[idx], manager, buffer[idx]);
						
						this->Index = 0;
						this->DataStorage = std::move(buffer);
						this->Services = std::move(wrappers);
						this->NumServices = numServices;
						this->ManagerHandle = manager;
					}
				}
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~o
			public:
				satisfies(ConstIterator,
					IsDefaultConstructible,
					IsCopyable
				);
				// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

				// o~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				InstalledService const&
				dereference() const {
					return (*this->Services)[this->Index];
				}

				bool
				equal(const ConstIterator& r) const noexcept {
					return this->Index == r.Index;
				}
				// o~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~o
			private:
				void
				increment() {
					if (this->Index != ConstIterator::npos 
					 && ++this->Index == static_cast<ptrdiff_t>(this->NumServices))
						*this = ConstIterator{};
				}
			};

		public:
			using const_iterator = ConstIterator;
			using const_reference = std::iter_const_reference_t<ConstIterator>;
			using iterator = const_iterator;
			using reference = std::iter_reference_t<ConstIterator>;
			using value_type = InstalledService;
			using size_type = size_t;
			using different_type = ptrdiff_t;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			SharedServiceManager ManagerHandle;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			explicit
			InstalledServicesCollection(SharedServiceManager scm)
			  : ManagerHandle{scm}
			{}
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(InstalledServicesCollection,
				NotDefaultConstructible,
				NotCopyable,
				NotEqualityComparable,
				NotSortable
			);
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			const_iterator
			begin() const {
				return const_iterator{this->ManagerHandle};
			}

			const_iterator
			end() const {
				return const_iterator{};
			}

			size_type
			size() const = delete;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		};

	public:
		InstalledServicesCollection const
		static ExistingServices;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedServiceManager Handle;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		explicit
		ServiceManager(SharedServiceManager existing)
		  : Handle{std::move(existing)}
		{}

	public:
		explicit
		ServiceManager(ServiceManagerRight rights) 
		  : Handle{::OpenSCManagerW(nullptr, SERVICES_ACTIVE_DATABASE, DWord{rights})}
		{
			if (!this->Handle)
				LastError{}.throwAlways("OpenSCManager('{}') failed", core::to_string(rights));
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		Service
		open(std::wstring_view name, ServiceRight rights) const {
			if (auto handle = ::OpenServiceW(*this->Handle, ThrowIfEmpty(name).data(), DWord{rights}); !handle)
				LastError{}.throwAlways("OpenService('{}') failed", to_utf8(name));
			else 
				return Service{SharedService{handle}};
		}

		SharedServiceManager
		handle() const {
			return this->Handle;
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	
}	
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o