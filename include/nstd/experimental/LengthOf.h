#pragma once
#include <array>

namespace nstd
{	
	template <typename T>
	unsigned constexpr 
	lengthof_v = 0;

	template <typename T, unsigned N>
	unsigned constexpr 
	lengthof_v<T[N]> = N;

	template <typename T, unsigned N>
	unsigned constexpr 
	lengthof_v<std::array<T,N>> = N;
	
	//! @brief	Retrieve the length of an array, in elements
	//! 
	//! @param	expr	Built-in array or std::array (of any type)
	//! 
	//! @return	Compile-time constant
	#define lengthof(expr)  ::nstd::lengthof_v<decltype(expr)>
}