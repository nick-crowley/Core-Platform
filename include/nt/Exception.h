#pragma once
#include "corePlatform.h"

namespace core::nt
{
	[[noreturn]] 
	void 
	throw_exception(::NTSTATUS status);
}
