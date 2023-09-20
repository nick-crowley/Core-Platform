#include "library/core.Platform.h"
#include "core/LogStream.h"
#include "win/Process.h"
using namespace core;

int main()
try {
	clog.attach(std::cout);

	std::cout << "Currently executing:\n";
	for (auto const& pid : win::Process::ExistingProcessIdCollection{})
		std::cout << "-> PID:" << pid << "\n";
	std::cout << std::endl;

	std::cout << "Currently executing:\n";
	for (win::Process const& process : win::Process::ExistingProcesses)
		std::cout << "-> " << process.path() << "\n";
	std::cout << std::endl;

	std::cout << "Currently loaded modules:\n";
	for (win::Module const& module : win::currentProcess.modules())
		std::cout << "-> " << module.path() << "\n";
	std::cout << std::endl;
}
catch (std::exception const& e) {
	clog << e;
	return -1;
}