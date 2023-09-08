#include "win/Module.h"
using namespace core;

win::Module const
PlatformExport ProcessModule {win::SharedModule{::GetModuleHandleW(nullptr), weakref}};
	
win::Module const
PlatformExport SystemResource {win::SharedModule{nullptr, weakref}};
