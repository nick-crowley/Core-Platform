#pragma once

namespace nstd
{	
	//! @brief	Stringify any identifier
	//! 
	//! @param	identifier		Any identifier
	//! 
	//! @return	Narrow-character string representation of @p identifier
	#define nameof(identifier)       #identifier 

} // namespace nstd
