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
#include "security/ServiceRight.h"
#include "core/ObservableEvent.h"
#include "win/SharedHandle.h"
#include "win/SharedLibrary.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	enum class ServiceStatus : DWORD {
		ContinuePending = SERVICE_CONTINUE_PENDING,   //!< The service continue is pending.
		PausePending = SERVICE_PAUSE_PENDING,         //!< The service pause is pending.
		Paused = SERVICE_PAUSED,                      //!< The service is paused.
		Running = SERVICE_RUNNING,                    //!< The service is running.
		StartPending = SERVICE_START_PENDING,         //!< The service is starting.
		StopPending = SERVICE_STOP_PENDING,           //!< The service is stopping.
		Stopped = SERVICE_STOPPED,                    //!< The service is not running.
	};

	enum class ServiceNotify : DWORD {
		Unspecified = 0,                                     //!< [CUSTOM] Occurs when application must determine that itself
		Created = SERVICE_NOTIFY_CREATED,                    //!< Report when the service has been created.
		ContinuePending = SERVICE_NOTIFY_CONTINUE_PENDING,   //!< Report when the service is about to continue.
		DeletePending = SERVICE_NOTIFY_DELETE_PENDING,       //!< Report when service has been passed to @c DeleteService() (Your application should close any handles to the service so it can be deleted)
		Deleted = SERVICE_NOTIFY_DELETED,                    //!< Report when the service has been deleted. (An application cannot receive this notification if it has an open handle to the service)
		PausePending = SERVICE_NOTIFY_PAUSE_PENDING,         //!< Report when the service is pausing.
		Paused = SERVICE_NOTIFY_PAUSED,                      //!< Report when the service has paused.
		Running = SERVICE_NOTIFY_RUNNING,                    //!< Report when the service is running.
		StartPending = SERVICE_NOTIFY_START_PENDING,         //!< Report when the service is starting.
		StopPending = SERVICE_NOTIFY_STOP_PENDING,           //!< Report when the service is stopping.
		Stopped = SERVICE_NOTIFY_STOPPED,                    //!< Report when the service has stopped.
	};
}
namespace core::meta 
{
	//! @brief	@c core::win::ServiceNotify is a bitflag
	metadata bool Settings<bitwise_enum, win::ServiceNotify> = true;	
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	class Service
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		using StatusChangedDelegate = Delegate<void(Service&,ServiceNotify)>;

	private:
		class StatusChangedEvent : public ObservableEvent<StatusChangedDelegate> {
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			Service&                       Owner;
			PSC_NOTIFICATION_REGISTRATION  Cookie;
			SharedLibrary                  SecHostLib;
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			StatusChangedEvent(Service& s) 
			  : Owner{s},
			    SecHostLib{L"sechost.dll"}
			{}
			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			void
			virtual regist�r() override {
				auto const subscribeChangeNotifications = this->SecHostLib.loadFunction<decltype(::SubscribeServiceChangeNotifications)>("SubscribeServiceChangeNotifications");

				if (BOOL const result = subscribeChangeNotifications(*this->Owner.Handle, 
				                                                     SC_EVENT_STATUS_CHANGE, 
				                                                     &Service::OnStatusChanged, 
				                                                     &this->Owner, 
				                                                     &this->Cookie); !result)
					LastError{}.throwAlways("SubscribeServiceChangeNotifications() failed");
			}

			void
			virtual unregister() override {
				auto const unsubscribeChangeNotifications = this->SecHostLib.loadFunction<decltype(::UnsubscribeServiceChangeNotifications)>("UnsubscribeServiceChangeNotifications");

				unsubscribeChangeNotifications(this->Cookie);
				this->Cookie = nullptr;
			}
		};
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedService  Handle;

	public:
		StatusChangedEvent  StatusChanged;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		explicit
		Service(SharedService srvc) 
		  : Handle{ThrowIfEmpty(srvc)},
			StatusChanged{*this}  // @c Handle must be initialized prior to @c StatusChanged
		{
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		void
		static CALLBACK OnStatusChanged(DWORD notifyMask, void* param) {
			auto* const self = static_cast<Service*>(param);
			self->StatusChanged.raise(*self, static_cast<ServiceNotify>(notifyMask));
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		std::wstring
		description() const {
			::DWORD bytesNeeded = 0;
			::QueryServiceConfig2W(*this->Handle, SERVICE_CONFIG_DESCRIPTION, nullptr, 0, &bytesNeeded);
			if (LastError err; err != ERROR_INSUFFICIENT_BUFFER)
				err.throwAlways("QueryServiceConfig2W() failed");

			auto buffer = boost::reinterpret_pointer_cast<::SERVICE_DESCRIPTION>(
				std::make_unique<std::byte[]>(bytesNeeded)
			);
			if (!::QueryServiceConfig2W(*this->Handle, 
			                            SERVICE_CONFIG_DESCRIPTION, 
			                            nstd::cast_to<::BYTE*>(buffer.get()), 
			                            bytesNeeded, 
			                            &bytesNeeded))
				LastError{}.throwAlways("QueryServiceConfig2W() failed");
			
			if (!buffer->lpDescription)
				return {};
			return std::wstring{buffer->lpDescription, (bytesNeeded / sizeof(wchar_t)) - 5};
		}

		SharedService
		handle() const {
			return this->Handle;
		}

		ServiceStatus
		status() const {
			if (::SERVICE_STATUS info{}; !::QueryServiceStatus(*this->Handle, &info))
				LastError{}.throwAlways("QueryServiceStatus() failed");
			else
				return static_cast<ServiceStatus>(info.dwCurrentState);
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		continu�() {
			::SERVICE_STATUS status{};
			if (!::ControlService(*this->Handle, SERVICE_CONTROL_CONTINUE, &status))
				LastError{}.throwIfError("ControlService() failed");
		}

		void
		pause() {
			::SERVICE_STATUS status{};
			if (!::ControlService(*this->Handle, SERVICE_CONTROL_PAUSE, &status))
				LastError{}.throwIfError("ControlService() failed");
		}

		void
		start() {
			if (!::StartServiceW(*this->Handle, 0, nullptr))
				LastError{}.throwIfError("StartService() failed");
		}
		
		void
		stop() {
			::SERVICE_STATUS status{};
			if (!::ControlService(*this->Handle, SERVICE_CONTROL_STOP, &status))
				LastError{}.throwIfError("ControlService() failed");
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	
}	
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o