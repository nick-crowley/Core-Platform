#pragma once
#ifndef CorePlatform_h_included
#	define CorePlatform_h_included
#endif

#include "../../src/PlatformSdk.h"
#include "../../src/StdLibrary.h"
#include "../../src/libBoost.h"

#include "nstd/experimental/abstract.h"
#include "nstd/experimental/implicit.h"
#include "nstd/experimental/intern.h"
#include "nstd/experimental/nameof.h"
#include "nstd/experimental/satisfies.h"
#include "nstd/experimental/lengthof.h"
#include "nstd/experimental/finally.h"
#include "nstd/FormatString.h"
#include "nstd/SourceLocation.h"

#include "meta/SizeOf.h"
#include "meta/TagTypes.h"
#include "meta/Settings.h"
#include "meta/TypeTraits.h"
#include "meta/Concepts.h"
#include "meta/Tuple.h"

#include "core/Exceptions.h"
#include "core/ThrowIfEmpty.h"
#include "core/ThrowIfNot.h"
#include "core/ThrowIfNull.h"
#include "core/ThrowIfZero.h"

#include "nt/NtStatus.h"
#include "win/LResult.h"
#include "win/DWord.h"