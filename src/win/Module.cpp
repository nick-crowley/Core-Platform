#include "win/Module.h"
using namespace core;

win::Module const
PlatformExport win::ProcessModule {win::SharedModule{::GetModuleHandleW(nullptr), weakref}};
	
win::Module const
PlatformExport win::SystemResource {win::SharedModule{nullptr, weakref}};
