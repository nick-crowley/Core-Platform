#pragma once
#if defined(BuildCorePlatformStaticLib)
#	define PlatformExport 
#elif defined(BuildCorePlatformDLL)
#	define PlatformExport __declspec(dllexport)
#else
#	define PlatformExport __declspec(dllimport)
#endif