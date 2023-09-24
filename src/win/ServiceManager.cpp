#include "win/ServiceManager.h"
using namespace core;

win::ServiceManager::ExistingServicesCollection const
win::ServiceManager::ExistingServices{ServiceManager{ServiceManagerRight::EnumerateService}.handle()};
