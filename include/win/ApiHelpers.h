#pragma once
#include "corePlatform.h"

namespace core::win
{
	template <typename Value>
	constexpr Value Reserved = {};

	constexpr SECURITY_ATTRIBUTES* Unsecured {};
}
