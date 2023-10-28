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
#	define CorePlatform_h_included
#endif

#if (defined(_MSVC_LANG) && _MSVC_LANG <= 202002L)                                                \
 || (defined(__clang__) && __cplusplus <= 202002L)
#	error Core-Platform requires C++23
#endif

#ifdef __clang__
#	error Core-Platform doesn't yet support clang compiler
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
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
#include "nstd/experimental/scoped.h"
#include "nstd/experimental/lengthof.h"
#include "nstd/experimental/finally.h"
#include "nstd/TypeTraits.h"
#include "nstd/Concepts.h"
#include "nstd/Bitset.h"
#include "nstd/FormatString.h"
#include "nstd/Iterator.h"
#include "nstd/IoManip.h"
#include "nstd/IndexedTuple.h"
#include "nstd/Memory.h"
#include "nstd/Optional.h"
#include "nstd/Sequence.h"
#include "nstd/SizeOf.h"
#include "nstd/SourceLocation.h"
#include "nstd/StringView.h"
#include "nstd/String.h"
#include "nstd/Tuple.h"
#include "nstd/Utility.h"

#include "meta/TagTypes.h"
#include "meta/Settings.h"

#include "core/Exceptions.h"
#include "core/ThrowIfEmpty.h"
#include "core/ThrowIfNot.h"
#include "core/ThrowIfNull.h"
#include "core/ThrowIfOutOfRange.h"
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
#include "win/ApiHelpers.h"
#include "win/Boolean.h"
#include "win/LResult.h"
#include "win/HResult.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o