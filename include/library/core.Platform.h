#pragma once
#ifndef CorePlatform_h_included
#	define CorePlatform_h_included
#endif

//C++98: __cplusplus is 199711L
//C++11: __cplusplus is 201103L
//C++14: __cplusplus is 201402L
//C++17: __cplusplus is 201703L
//C++20: __cplusplus is 202002L

#ifdef _MSVC_LANG
#	if _MSVC_LANG <= 202002L
#		error Core-Platform requires C++23
#	endif
#elif __cplusplus <= 202002L
#	error Core-Platform requires C++23
#endif

#ifdef __clang__
#	error Core-Platform doesn't yet support clang compiler
#endif

#include "../../src/PlatformSdk.h"
#include "../../src/StdLibrary.h"
#include "../../src/libBoost.h"

#include "../../src/library/PlatformExport.h"

#include "nstd/experimental/abstract.h"
#include "nstd/experimental/implicit.h"
#include "nstd/experimental/intern.h"
#include "nstd/experimental/lambda.h"
#include "nstd/experimental/metafunc.h"
#include "nstd/experimental/nameof.h"
#include "nstd/experimental/satisfies.h"
#include "nstd/experimental/lengthof.h"
#include "nstd/experimental/finally.h"
#include "nstd/TypeTraits.h"
#include "nstd/Concepts.h"
#include "nstd/Bitset.h"
#include "nstd/FormatString.h"
#include "nstd/Iterator.h"
#include "nstd/Memory.h"
#include "nstd/Sequence.h"
#include "nstd/SizeOf.h"
#include "nstd/SourceLocation.h"
#include "nstd/Tuple.h"
#include "nstd/Utility.h"

#include "meta/TagTypes.h"
#include "meta/Settings.h"

#include "core/Exceptions.h"
#include "core/ThrowIfEmpty.h"
#include "core/ThrowIfNot.h"
#include "core/ThrowIfNull.h"
#include "core/ThrowIfZero.h"
#include "core/ThrowInvalidArg.h"
#include "core/Invariant.h"
#include "core/PostCondition.h"

#include "core/CharacterConversion.h"
#include "core/BitwiseEnum.h"
#ifndef __clang__
#	include "core/EnumNames.h"
#	include "core/ThrowIfUndefined.h"
#endif
#include "core/ToHexString.h"
#include "core/ToString.h"

#include "nt/NtStatus.h"
#include "win/LResult.h"
#include "win/DWord.h"