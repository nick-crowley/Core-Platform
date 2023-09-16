#include "library/core.Platform.h"
#include "core/LogStream.h"
#include "win/Process.h"
using namespace core;

enum E1 : unsigned { N1, N2 };
class C1 {};
struct S1 {};

namespace N {
	union U1 {};
	
	namespace N2 {
		class C2 {};
	}
}

int main()
try {
	clog.attach(std::cout);
	std::cout << "class_name_v of E1::N2 = " << core::enumerator_name(E1::N2) << std::endl;
	std::cout << "class_name_v of C1 = " << core::class_name_v<C1> << std::endl;
	std::cout << "class_name_v of S1 = " << core::class_name_v<S1> << std::endl;
	std::cout << "class_name_v of N::U1 = " << core::class_name_v<N::U1> << std::endl;
	
	//std::cout << "unqualified_class_name_v of E1::N2 = " << core::enumerator_name(E1::N2) << std::endl;
	std::cout << "unqualified_class_name_v of C1 = " << core::unqualified_class_name_v<C1> << std::endl;
	std::cout << "unqualified_class_name_v of S1 = " << core::unqualified_class_name_v<S1> << std::endl;
	std::cout << "unqualified_class_name_v of N::U1 = " << core::unqualified_class_name_v<N::U1> << std::endl;
	std::cout << "unqualified_class_name_v of N::N2::C2 = " << core::unqualified_class_name_v<N::N2::C2> << std::endl;

	std::cout << "Currently executing:\n";
	for (auto const& pid : win::Process::ExistingProcessIdCollection{})
		std::cout << "-> PID:" << pid << "\n";
	std::cout << std::endl;

	std::cout << "Currently executing:\n";
	for (win::Process const& process : win::Process::ExistingProcesses)
		std::cout << "-> " << process.path() << "\n";
	std::cout << std::endl;
}
catch (std::exception const& e) {
	clog << e;
	return -1;
}