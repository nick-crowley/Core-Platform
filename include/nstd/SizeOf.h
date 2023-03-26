#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../src/StdLibrary.h"

namespace nstd
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Total size of set of types
	*
	* @returns	Sum of sizes of types within set @p Types
	*/
	template <typename... Types>
	std::size_t constexpr
	inline sizeof_v = (... + sizeof(Types));

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Retrieve size of N objects (at run-time) of the same type
	*
	* @param[in]	n		Number of instance of type @p T
	*/
	template <typename T>
	std::size_t constexpr
	sizeof_n(std::size_t n)
	{
		return n * sizeof(T);
	}
}
