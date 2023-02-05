#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/Satisfies.h"

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

	struct hidden_t {} constexpr  
	inline hidden;
	
	struct noformat_t {} constexpr 
	inline noformat;

	struct open_existing_t {} constexpr 
	inline open_existing;

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
	inline hidden = meta::hidden;
	
	auto constexpr 
	inline noformat = meta::noformat;

	auto constexpr 
	inline open_existing = meta::open_existing;
	
	auto constexpr 
	inline undefined = meta::undefined;

	auto constexpr 
	inline use_default = meta::use_default;
	
	auto constexpr 
	inline weakref = meta::weakref;
}
