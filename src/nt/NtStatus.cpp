#include "library/core.Platform.h"
using namespace core;

std::string 
nt::detail::formatMessage(::LRESULT err)
{
	return win::detail::formatMessage(err);
}
