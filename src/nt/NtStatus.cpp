#include "library/core.Platform.h"
using namespace core;

std::string 
nt::detail::formatMessage(::NTSTATUS err)
{
	auto ntdll = ::LoadLibraryA("NTDLL.DLL");
	std::string msg(128,'\0');
	msg.resize(
		::FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_FROM_HMODULE, ntdll, err, NULL, msg.data(), win::DWord{msg.capacity()}, nullptr)
	);
	if (auto lastChar = msg.find_last_not_of("\r\n\t "); lastChar != std::string::npos)
		msg.erase(++lastChar);
	::FreeLibrary(ntdll);
	return msg;
}
