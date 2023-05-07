/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2023, Nick Crowley. All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions
*    and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of
*    conditions and the following disclaimer in the documentation and/or other materials provided
*    with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
* FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
* WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* The views and conclusions contained in the software and documentation are those of the author 
* and should not be interpreted as representing official policies, either expressed or implied, of
* the projects which contain it.
*/
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Preprocessor Directives o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "nstd/Concepts.h"
#include "meta/Settings.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta 
{	
	template <>
	struct DataType<bitwise_enum> : std::type_identity<bool> {};

	template <typename E>
	concept BitwiseEnumeration = nstd::Enumeration<E> && Settings<bitwise_enum,E>;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

template <core::meta::BitwiseEnumeration E>
E constexpr
operator&(E lhs, E rhs) { 
	return static_cast<E>(
		std::to_underlying<E>(lhs) & std::to_underlying<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator|(E lhs, E rhs) { 
	return static_cast<E>(
		std::to_underlying<E>(lhs) | std::to_underlying<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator^(E lhs, E rhs) { 
	return static_cast<E>(
		std::to_underlying<E>(lhs) ^ std::to_underlying<E>(rhs)
	);
};

template <core::meta::BitwiseEnumeration E>
E constexpr
operator~(E lhs) { 
	return static_cast<E>(
		~std::to_underlying<E>(lhs)
	);
};

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta 
{
	template <>
	struct DataType<compatible_enum> : std::type_identity<bool> {};

	template <typename E1, typename E2>
	concept CompatibleEnumeration = nstd::Enumeration<E1> 
	                             && nstd::Enumeration<E2> 
	                             && (Settings<compatible_enum,E1,E2> || Settings<compatible_enum,E2,E1>);

	template <nstd::Enumeration E>
	bool constexpr inline Settings<compatible_enum, E, E> = true;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

template <core::meta::BitwiseEnumeration E1, core::meta::CompatibleEnumeration<E1> E2>
E1 constexpr
operator&(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) & std::underlying_type_t<E2>(rhs)
	);
}

template <core::meta::BitwiseEnumeration E1, core::meta::CompatibleEnumeration<E1> E2>
E1 constexpr
operator|(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) | std::underlying_type_t<E2>(rhs)
	);
}

template <core::meta::BitwiseEnumeration E1, core::meta::CompatibleEnumeration<E1> E2>
E1 constexpr
operator^(E1 lhs, E2 rhs) { 
	return static_cast<E1>(
		std::underlying_type_t<E1>(lhs) ^ std::underlying_type_t<E2>(rhs)
	);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o