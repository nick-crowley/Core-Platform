#include "library/core.Platform.h"
using namespace core;

std::string 
win::detail::formatMessage(::LRESULT err)
{
	std::string msg(128,'\0');
	msg.resize(
		::FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, err, NULL, msg.data(), win::DWord{msg.capacity()}, nullptr)
	);
	msg.erase(msg.find_last_not_of("\r\n\t "));
	return msg;
}
