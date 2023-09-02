#include "win/ResourceId.h"
#include "core/ToString.h"
using namespace core;
using namespace win;

ResourceId const 
win::ResourceId::Null {};

std::string
win::to_string(ResourceId const& res)
{
	if (res.is_numeric())
		return '#' + std::to_string(res.as_number());
	else 
		return as_string(res.as_string());
}
