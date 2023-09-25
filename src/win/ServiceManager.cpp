#include "win/ServiceManager.h"
using namespace core;

win::ServiceManager::InstalledServicesCollection const
win::ServiceManager::ExistingServices{ServiceManager{ServiceManagerRight::EnumerateService}.handle()};
