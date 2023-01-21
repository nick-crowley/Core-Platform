#pragma once
#include "../../../src/libBoost.h"

namespace nstd::detail
{
#	define _make_lambda_param(seq,ignored,param)  auto param

#	define _make_lambda(seq)	\
		[](BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_TRANSFORM(_make_lambda_param,~,BOOST_PP_SEQ_POP_BACK(seq)))) { \
			return BOOST_PP_SEQ_HEAD(BOOST_PP_SEQ_REVERSE(seq)); }
}

namespace nstd
{
	//! @brief	Condensed lambda definition syntax (non-standard)
	//! 
	//! @param	param1		First parameter name
	//! @param	param2...	[optional] More parameter names	
	//! @param	returnExpr	Return expression
	//! 
	//! @remarks	CV-qualifiers, pointers, and references are supported
	//! 
	//! @example	lambda(x, 42)				[](auto x) { return 42; }
	//! @example	lambda(const x, x == 42)	[](auto const x) { return x == 42; }
	//! @example	lambda(*p, delete p)		[](auto* p) -> void { return delete p; }
	//! @example	lambda(*x, &y, *x = y)		[](auto* x, auto& y) { return *x = y; }
#	define  lambda(...)   _make_lambda(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))
}