#pragma once

namespace nstd
{

#define  _lambda(param,returnExpr)   [](auto param) { return returnExpr; }

}