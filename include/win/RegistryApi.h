#pragma once
#include "library/core.Platform.h"
#include "win/SmartHandle.h"
#include "win/RegistryValue.h"
#include "security/AccessRight.h"

namespace core::win
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

	using SharedRegistryApi = std::shared_ptr<RegistryApi>;

	SharedRegistryApi
	registryApi();
}
