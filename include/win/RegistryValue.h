#pragma once
#include "library/core.Platform.h"

namespace core::win
{
	using RegistryValue = std::variant<
		std::wstring_view,
		std::wstring,
		uint32_t,
		uint64_t,
		std::vector<std::byte>,
		std::vector<std::wstring>
	>;
}
