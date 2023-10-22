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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta
{
	struct adopt_t {} constexpr 
	inline adopt;
	
	struct bitwise_enum_t {} constexpr 
	inline bitwise_enum;
	
	struct compatible_enum_t {} constexpr 
	inline compatible_enum;

	struct create_new_t {} constexpr 
	inline create_new;
	
	struct destroy_t {} constexpr  
	inline destroy;
	
	struct hidden_t {} constexpr  
	inline hidden;
	
	struct inherits_t {} constexpr  
	inline inherits;
	
	struct lazy_t {} constexpr 
	inline lazy;
	
	struct noconversion_t {} constexpr 
	inline noconversion;

	struct noformat_t {} constexpr 
	inline noformat;

	struct open_existing_t {} constexpr 
	inline open_existing;
	
	struct program_name_t {} constexpr 
	inline program_name;
	
	struct program_version_t {} constexpr 
	inline program_version;

	struct unconstrained_t {} constexpr 
	inline unconstrained;

	struct undefined_t {} constexpr 
	inline undefined;
	
    struct use_default_t {} constexpr 
    inline use_default;
	
	struct weakref_t {} constexpr 
	inline weakref;
}

namespace core
{
	//using adopt_t = meta::adopt_t;
	//using create_new_t = meta::create_new_t;
	//using hidden_t = meta::hidden_t;
	//using open_existing_t = meta::open_existing_t;
	//using undefined_t = meta::undefined_t;
	//using use_default_t = meta::use_default_t;

	auto constexpr 
	inline adopt = meta::adopt;
	
	auto constexpr 
	inline bitwise_enum = meta::bitwise_enum;

	auto constexpr 
	inline compatible_enum = meta::compatible_enum;

	auto constexpr 
	inline create_new = meta::create_new;
	
	auto constexpr 
	inline destroy = meta::destroy;
	
	auto constexpr 
	inline hidden = meta::hidden;
	
	auto constexpr 
	inline inherits = meta::inherits;
	
	auto constexpr 
	inline lazy = meta::lazy;
	
	auto constexpr 
	inline noconversion = meta::noconversion;

	auto constexpr 
	inline noformat = meta::noformat;

	auto constexpr 
	inline open_existing = meta::open_existing;
	
	auto constexpr 
	inline program_name = meta::program_name;
	
	auto constexpr 
	inline program_version = meta::program_version;
	
	auto constexpr 
	inline unconstrained = meta::unconstrained;

	auto constexpr 
	inline undefined = meta::undefined;

	auto constexpr 
	inline use_default = meta::use_default;
	
	auto constexpr 
	inline weakref = meta::weakref;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::meta
{
	bool consteval
	operator==(undefined_t, undefined_t) noexcept {
		return true;
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o