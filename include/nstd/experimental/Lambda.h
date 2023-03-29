#pragma once
#include "../../../src/libBoost.h"

namespace nstd::detail
{
	#define _make_lambda_param(seq,ignored,param)                                                     \
		auto param

	#define _make_lambda(mode,paramsAndExpr)                                                          \
		[mode](BOOST_PP_LIST_ENUM(                                                                    \
			BOOST_PP_LIST_TRANSFORM(_make_lambda_param,~,BOOST_PP_LIST_FIRST_N(                       \
				BOOST_PP_DEC(BOOST_PP_LIST_SIZE(paramsAndExpr)),                                      \
				paramsAndExpr                                                                         \
			))                                                                                        \
		)) { return BOOST_PP_LIST_FIRST(BOOST_PP_LIST_REVERSE(paramsAndExpr)); }
}

namespace nstd
{
	//! @brief	Condensed lambda definition syntax (non-standard)
	//! 
	//! @param  mode		Capture mode
	//! @param	param1		First parameter name
	//! @param	...			[optional] Name of further parameters
	//! @param	...			[mandatory] Return expression without @c return keyword
	//! 
	//! @remarks	CV-qualifiers and pointer/reference modifiers upon parameters are supported
	//! 
	//! @example	lambda(=, x, 42)                 [](auto x)           { return 42;       }
	//! @example	lambda(=, const x, x == 42)      [](auto const x)     { return x == 42;  }
	//! @example	lambda(=, *p, delete p)          [](auto* p) -> void  { return delete p; }
	//! @example	lambda(=, *x, &y, *x = y)        [](auto* x, auto& y) { return *x = y;   }
	#define  lambda(mode, param1, ...)                                                                \
		_make_lambda(                                                                                 \
			mode,                                                                                     \
			BOOST_PP_LIST_APPEND((param1, BOOST_PP_NIL), BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__))      \
		)
}