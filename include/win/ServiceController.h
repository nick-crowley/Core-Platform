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
#include "win/ManualResetEvent.h"
#include "win/SharedHandle.h"
#include "win/Service.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	class ServiceController;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win 
{
	enum class ServiceAccept {
		None = 0,                                                      //!< Service can't accept any requests
		NetBindChange = SERVICE_ACCEPT_NETBINDCHANGE,                  //!< Service is a network component that can accept changes in its binding without being stopped and restarted.
		ParamChange = SERVICE_ACCEPT_PARAMCHANGE,                      //!< Service can reread its startup parameters without being stopped and restarted.
		PauseContinue = SERVICE_ACCEPT_PAUSE_CONTINUE,                 //!< Service can be paused and continued.
		PreShutdown = SERVICE_ACCEPT_PRESHUTDOWN,                      //!< Service can perform preshutdown tasks.
		Shutdown = SERVICE_ACCEPT_SHUTDOWN,                            //!< Service is notified when system shutdown occurs.
		Stop = SERVICE_ACCEPT_STOP,                                    //!< Service can be stopped.
		HardwareProfileChange = SERVICE_ACCEPT_HARDWAREPROFILECHANGE,  //!< Service is notified when the computer's hardware profile has changed. This enables the system to send SERVICE_CONTROL_HARDWAREPROFILECHANGE notifications to the service.
		PowerEvent = SERVICE_ACCEPT_POWEREVENT,                        //!< Service is notified when the computer's power status has changed. This enables the system to send SERVICE_CONTROL_POWEREVENT notifications to the service.
		SessionChange = SERVICE_ACCEPT_SESSIONCHANGE,                  //!< Service is notified when the computer's session status has changed. This enables the system to send SERVICE_CONTROL_SESSIONCHANGE notifications to the service.
		TimeChange = SERVICE_ACCEPT_TIMECHANGE,                        //!< Service is notified when the system time has changed. This enables the system to send SERVICE_CONTROL_TIMECHANGE notifications to the service.
		TriggerEvent = SERVICE_ACCEPT_TRIGGEREVENT,                    //!< Service is notified when an event for which the service has registered occurs. This enables the system to send SERVICE_CONTROL_TRIGGEREVENT notifications to the service.
	};

	enum class ServiceControl : DWORD {
		Continue = SERVICE_CONTROL_CONTINUE,                //!< Ask _paused_ service to resume  (Requires @c core::win::ServiceRight::PauseContinue)
		Interrogate = SERVICE_CONTROL_INTERROGATE,          //!< Ask service that it should report its current status  (Requires @c core::win::ServiceRight::Interrogate)
		NetBindAdd = SERVICE_CONTROL_NETBINDADD,            //!< [deprecated] Inform network service there's a new component for binding  (Requires @c core::win::ServiceRight::PauseContinue)
		NetBindDisable = SERVICE_CONTROL_NETBINDDISABLE,    //!< [deprecated] Ask network service that one of its bindings has been disabled  (Requires @c core::win::ServiceRight::PauseContinue)
		NetBindEnable = SERVICE_CONTROL_NETBINDENABLE,      //!< [deprecated] Ask network service that a disabled binding has been enabled  (Requires @c core::win::ServiceRight::PauseContinue)
		NetBindRemove = SERVICE_CONTROL_NETBINDREMOVE,      //!< [deprecated] Ask network service that a component for binding has been removed  (Requires @c core::win::ServiceRight::PauseContinue)
		ParamChange = SERVICE_CONTROL_PARAMCHANGE,          //!< Ask service that its startup parameters have changed  (Requires @c core::win::ServiceRight::PauseContinue)
		Pause = SERVICE_CONTROL_PAUSE,                      //!< Ask service that it should pause  (Requires @c core::win::ServiceRight::PauseContinue)
		Stop = SERVICE_CONTROL_STOP,                        //!< Ask service that it should stop (Requires @c core::win::ServiceRight::Stop)
										                    //!<   NB: You cannot send futher commands following 'Stop'
		Shutdown = SERVICE_CONTROL_SHUTDOWN,                //!< Notifies a service that the system is shutting down so the service can perform cleanup tasks.
		PreShutdown = SERVICE_CONTROL_PRESHUTDOWN,          //!< Notifies a service that the system _will be_ shutting down.
		DeviceEvent = SERVICE_CONTROL_DEVICEEVENT,          //!< Notifies a service of device events.
		HardwareProfileChange = SERVICE_CONTROL_HARDWAREPROFILECHANGE,    //!< Notifies a service that the computer's hardware profile has changed.
		PowerEvent = SERVICE_CONTROL_POWEREVENT,            //!< Notifies a service of system power events.
		SessionChange = SERVICE_CONTROL_SESSIONCHANGE,      //!< Notifies a service of session change events.
		TimeChange = SERVICE_CONTROL_TIMECHANGE,            //!< Notifies a service that the system time has changed.
		TriggerEvent = SERVICE_CONTROL_TRIGGEREVENT,        //!< Notifies a service registered for a service trigger event that the event has occurred.
		UserDefined = 128,                                  //!< Notifies a service of a user-define control code.
		Invalid = 256,                                      //!< End of user-defined range
	};
}
namespace core::meta 
{
	//! @brief	@c core::win::ServiceAccept is a bitflag
	metadata bool Settings<bitwise_enum, win::ServiceAccept> = true;	
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta
{
	//! @brief  Well-formed service declaration
	template <typename T>
	concept CoreService = std::derived_from<T,win::ServiceController> 
		&& requires {
			{ T::service_name } -> std::convertible_to<std::wstring_view>;
		} && requires(std::span<std::wstring_view> args) {
			T(args);
		};
}
namespace core::win
{
	//! @brief  Base class for all custom service implementations
	class ServiceController
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		SharedServiceController  Handle;
		ManualResetEvent         HasStopped {false};
		::SERVICE_STATUS         Status {sizeof(::SERVICE_STATUS), SERVICE_WIN32_OWN_PROCESS};
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		satisfies(ServiceController, 
			protected: IsDefaultConstructible,
			public: IsMovable,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		template <meta::CoreService Service>
		SharedServiceController
		static registerControlHandler(Service& self) {
			if (auto handle = ::RegisterServiceCtrlHandlerExW(Service::service_name.data(), 
			                                                  &Service::onServiceControl, 
			                                                  &self); !handle)
				LastError{}.throwAlways("RegisterServiceCtrlHandlerW() failed");
			else
				return SharedServiceController{handle, weakref};
		}

		DWORD
		static WINAPI onServiceControl(DWORD control, DWORD eventType, void* eventData, void* context) {
			if (!context)
				return ERROR_INVALID_PARAMETER;
			auto& instance = *static_cast<ServiceController*>(context);
			switch (auto const cmd = static_cast<ServiceControl>(control); cmd) {
			case ServiceControl::Continue:
			case ServiceControl::Interrogate:
			case ServiceControl::NetBindAdd:
			case ServiceControl::NetBindDisable:
			case ServiceControl::NetBindEnable:
			case ServiceControl::NetBindRemove:
			case ServiceControl::ParamChange:
			case ServiceControl::Pause:
			case ServiceControl::Stop:
			case ServiceControl::UserDefined:
			default:
				return instance.onControl(cmd);
			
			case ServiceControl::DeviceEvent:
				return instance.onDeviceEvent(eventType, std::bit_cast<LPARAM>(eventData));
			case ServiceControl::PowerEvent:
				return instance.onPowerEvent(eventType, std::bit_cast<LPARAM>(eventData));
			case ServiceControl::SessionChange:
				return instance.onSessionChange(eventType, *static_cast<::WTSSESSION_NOTIFICATION*>(eventData));
			case ServiceControl::TimeChange:
				return instance.onTimeChange(eventType, *static_cast<::SERVICE_TIMECHANGE_INFO*>(eventData));
			case ServiceControl::HardwareProfileChange:
				return instance.onHardwareProfileChange(eventType);
			case ServiceControl::TriggerEvent:
				return instance.onCustomEvent();
			case ServiceControl::Shutdown:
			case ServiceControl::PreShutdown:
				return instance.onShutdown();
			}
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		void
		join() {
			waitFor(*this->HasStopped.handle());
		}
		
		template <typename Self>
			requires meta::CoreService<std::remove_reference_t<Self>>
		void
		start(this Self&& self) {
			using service_t = std::remove_reference_t<Self>;
			auto* const thís = static_cast<ServiceController*>(&self);
			thís->Handle = ServiceController::registerControlHandler<service_t>(self);
			thís->status(ServiceStatus::StartPending);
			thís->onStart();
		}

	protected:
		DWORD
		virtual onControl(ServiceControl cmd) {
			switch (cmd) {
			case ServiceControl::Interrogate:
				return NO_ERROR;

			case ServiceControl::Stop:
				this->status(ServiceStatus::Stopped);
				this->HasStopped.signal();
				return NO_ERROR;

			default:
				return ERROR_CALL_NOT_IMPLEMENTED;
			}
		}
		
		DWORD
		virtual onCustomEvent() {
			return ERROR_CALL_NOT_IMPLEMENTED;
		}
		
		DWORD
		virtual onDeviceEvent(DWORD, LPARAM) {
			return NO_ERROR;  // Allow the request
		}
		
		DWORD
		virtual onHardwareProfileChange(LPARAM) {
			return NO_ERROR;  // Allow the request
		}
		
		DWORD
		virtual onPowerEvent(DWORD, LPARAM) {
			return NO_ERROR;  // Allow the request
		}
		
		DWORD
		virtual onSessionChange(DWORD, ::WTSSESSION_NOTIFICATION& notify) {
			return ERROR_CALL_NOT_IMPLEMENTED;
		}
		
		DWORD
		virtual onShutdown() {
			return NO_ERROR;  // Allow the request
		}
		
		void
		virtual onStart() {
			this->status(ServiceStatus::Running, ServiceAccept::Stop);
		}

		DWORD
		virtual onTimeChange(DWORD, ::SERVICE_TIMECHANGE_INFO& notify) {
			return ERROR_CALL_NOT_IMPLEMENTED;
		}

		void
		status(ServiceStatus newStatus, ServiceAccept accepted = ServiceAccept::None)
		{
			this->Status.dwControlsAccepted = std::to_underlying(accepted);
			this->Status.dwCurrentState = std::to_underlying(newStatus);
			this->Status.dwWin32ExitCode = 0;
			this->Status.dwServiceSpecificExitCode = 0;
			this->Status.dwCheckPoint = 0;
			if (!::SetServiceStatus(*this->Handle, &this->Status))
				LastError{}.throwAlways("SetServiceStatus() failed");
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win {
	namespace detail {
		template <meta::CoreService CustomService>
		void
		static WINAPI ServiceMain(DWORD argc, wchar_t* argv[])
		{
			std::vector<std::wstring_view> args{argv[0], argv[argc]};
			CustomService service{args};
			service.start();
			service.join();
		}
	}

	template <meta::CoreService... CustomServices>
	int
	runServiceUntilStopped()
	{
		::SERVICE_TABLE_ENTRYW ServiceTable[] {
			{const_cast<wchar_t*>(CustomServices::service_name.data()), &detail::ServiceMain<CustomServices>}..., 
			{}
		};
 
		if (!::StartServiceCtrlDispatcherW(ServiceTable))
			LastError{}.throwAlways("StartServiceCtrlDispatcherW() failed");
 
		return 0;
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o