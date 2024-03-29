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
#ifndef DISABLE_SERVICE_MANAGER_SYSTEM_TESTS
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include <gtest/gtest.h>
#include <win/ServiceManager.h>
#include <win/ManualResetEvent.h>
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
using namespace core;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

TEST(ServiceManager_ST, OpenAnyService) 
{
	using enum win::ServiceManagerRight;

	//! @post	Service control manager can be opened successfully
	auto const mgr = win::ServiceManager{Connect|EnumerateService};

	//! @test	Verify DHCP service existing and is running
	EXPECT_EQ(
		mgr.open(L"Dhcp", win::ServiceRight::QueryStatus).status(),
		win::ServiceStatus::Running
	);
}

TEST(ServiceManager_ST, QueryServiceDescription) 
{
	using enum win::ServiceManagerRight;

	//! @post	Service control manager can be opened successfully
	auto const mgr = win::ServiceManager{Connect|EnumerateService};

	//! @test	Verify description of DHCP service
	EXPECT_EQ(
		mgr.open(L"Dhcp", win::ServiceRight::QueryConfig).description(),
		L"Registers and updates IP addresses and DNS records for this computer. If this service is stopped, this computer will not receive dynamic IP addresses and DNS updates. If this service is disabled, any services that explicitly depend on it will fail to start."
	);
}

TEST(ServiceManager_ST, EnumerateInstalledServices) 
{
	//! @test  Verify service control manager can be enumerated successfully
	EXPECT_NO_THROW(
		for (auto& service : win::ServiceManager::ExistingServices)
			std::wcout << std::format("Installed: {} ({})", to_utf8(service.name()), to_string(service.status())) << std::endl;
	);
}

TEST(ServiceManager_ST, EnumerateAndOpenAnInstalledService) 
{
	auto const inRunningState = [](auto const& service) { return service.status() == win::ServiceStatus::Running; };
	
	//! @test  Verify enumerated services can be used to open a handle to the actual service
	EXPECT_NO_THROW(
		auto running = win::ServiceManager::ExistingServices | views::filter(inRunningState) | views::drop(4);
		auto service = running.front().open(win::ServiceRight::QueryConfig);
		std::wcout << service.description();
	);
}

TEST(ServiceManager_ST, NotifyServiceStatusChanged) 
{
	using namespace win;
	using enum ServiceManagerRight;
	
	std::optional<win::ServiceManager> scm;
	std::optional<win::Service> service;
	
	//! @post  Service control manager can be opened successfully
	EXPECT_NO_THROW(
		scm = ServiceManager{Connect|EnumerateService};
	);
	
	//! @post  Print Spooler service can be opened successfully
	EXPECT_NO_THROW(
		service.emplace(scm->open(L"Spooler", ServiceRight::Start|ServiceRight::Stop|ServiceRight::QueryStatus));
	);
	
	ManualResetEvent receivedNotification{false};
	unsigned numNotifications = 0;

	//! @test  Verify service status change event can be listened upon successfully
	EXPECT_NO_THROW(
		service->StatusChanged += [&](win::Service& sender, ServiceNotify mask) {
			++numNotifications;
			receivedNotification.signal();
		};
	);

	// Trigger notifications
	service->start();
	win::waitFor(*receivedNotification.handle(), chrono::seconds{1});
	std::wcout << "Service status changed to " << to_string(service->status()) << std::endl;

	receivedNotification.reset();
	service->stop();
	win::waitFor(*receivedNotification.handle(), chrono::seconds{1});
	std::wcout << "Service status changed to " << to_string(service->status()) << std::endl;

	//! @post	Status notifications are received
	EXPECT_TRUE(
		receivedNotification.signalled()
	);

	//! @post	Expected number of status notifications are received
	EXPECT_EQ(
		4u,         // TODO: Set to correct number
		numNotifications
	);
}

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif	// DISABLE_SERVICE_MANAGER_SYSTEM_TESTS