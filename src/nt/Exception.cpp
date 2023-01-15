#include "library/core.Platform.h"
#include "nt/Exception.h"
using namespace core;

std::string 
extern formatMessage(int err);

void 
nt::throw_exception(::NTSTATUS r)
{
	throw std::runtime_error{formatMessage(::LsaNtStatusToWinError(r))};
}
