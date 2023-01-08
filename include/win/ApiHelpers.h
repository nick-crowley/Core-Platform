#pragma once
#include "corePlatform.h"

namespace win
{
	template <typename Value>
	constexpr Value Reserved = {};

	constexpr SECURITY_ATTRIBUTES* Unsecured {};
}
