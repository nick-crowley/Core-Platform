#pragma once
#include "corePlatform.h"

namespace nt
{
	[[noreturn]] 
	void 
	throw_exception(::NTSTATUS status);
}
