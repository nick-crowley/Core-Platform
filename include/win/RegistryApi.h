#pragma once
#include "corePlatform.h"
#include "win/SmartHandle.h"
#include "win/RegistryValue.h"
#include "security/AccessRight.h"

namespace win
{
	class RegistryApi
	{
	public:
		enum Lifetime { Volatile, NonVolatile };
		enum View { Wow32, Wow64 };

		virtual ~RegistryApi() = default;

		SharedRegistryKey
		virtual createKey(SharedRegistryKey root, std::wstring_view path, AccessRight rights, Lifetime life = NonVolatile) const;

		SharedRegistryKey
		virtual openKey(SharedRegistryKey root, std::wstring_view path, AccessRight rights) const;
		
		RegistryValue
		virtual getValue(SharedRegistryKey root, std::wstring_view path, std::wstring_view name) const;
		
		void
		virtual setValue(SharedRegistryKey root, std::wstring_view path, std::wstring_view name, RegistryValue value) const;
		
		void
		virtual removeKey(SharedRegistryKey root, std::wstring_view path) const;
		
		void
		virtual removeValue(SharedRegistryKey root, std::wstring_view path, std::wstring_view name) const;
	};

	std::shared_ptr<RegistryApi>
	registryApi();
}
