#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace core 
{
	template <typename T> 
		requires std::is_same_v<std::remove_reference_t<T>,bool> 
			  || std::is_arithmetic_v<std::remove_reference_t<T>>
			  || std::is_pointer_v<std::remove_reference_t<T>>
	bool 
	empty(T&& value)
	{
		return value == static_cast<std::remove_reference_t<T>>(0);
	}
}

namespace std 
{
	template <typename T>
	bool
	empty(std::shared_ptr<T> const& value)
	{
		return !static_cast<bool>(value);
	}

	template <typename T>
	bool
	empty(std::unique_ptr<T> const& value)
	{
		return !static_cast<bool>(value);
	}

	template <typename T>
	bool
	empty(std::weak_ptr<T> const& value)
	{
		return !value.expired();
	}
}

namespace core::meta 
{
	template <typename T> 
	concept EmptyCompatible = requires(T&& value) 
	{ 
		empty(std::forward<T>(value)); 
	};
}

namespace core
{
	template <meta::EmptyCompatible T> 
	decltype(auto) 
	inline ThrowIfEmptyImpl(T&& value, char const* argName, std::source_location loc = std::source_location::current())
	{
		using std::empty;
		using core::empty;

		if (empty(value))
			throw invalid_argument{"{}(..) Empty '{}' argument", loc.function_name(), argName};

		return std::forward<T>(value);
	}
}
#define ThrowIfEmpty(arg)  ThrowIfEmptyImpl(arg, #arg)
