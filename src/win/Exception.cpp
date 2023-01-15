#include "library/core.Platform.h"
#include "win/DWord.h"
#include "win/Exception.h"
using namespace core;

std::string 
formatMessage(int err)
{
	std::string msg(128,'\0');
	msg.resize(
		::FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, err, NULL, msg.data(), win::DWord{msg.capacity()}, nullptr)
	);
	msg.erase(msg.find_last_not_of("\r\n\t "));
	return msg;
}

void 
win::throw_exception(::LRESULT r)
{
	throw std::runtime_error{formatMessage(r)};
}

void 
win::throw_exception(::LRESULT r, std::string message)
{
	throw std::runtime_error{message + "." + formatMessage(r)};
}
