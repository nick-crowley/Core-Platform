#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.
// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.
#include <SDKDDKVer.h>

#ifndef NOMINMAX
#	error Core-Platform requires NOMINMAX be defined
#endif

#include <Windows.h>

#include <ntsecapi.h>
#include <sddl.h>			// SID functions
#include <Aclapi.h>         // ACL functions

#ifdef __ATLSTR_H__
#	define HAS_ATL_STRING
#endif
