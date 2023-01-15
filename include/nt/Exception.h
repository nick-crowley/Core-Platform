#pragma once
#include "library/core.Platform.h"

namespace core::nt
{
	[[noreturn]] 
	void 
	throw_exception(::NTSTATUS status);
}
