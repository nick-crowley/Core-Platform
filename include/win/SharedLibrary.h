#pragma once
#include "library/core.Platform.h"
#include "core/SmartHandle.h"
#include "meta/TypeTraits.h"

namespace core::win
{
	class SharedLibrary
	{
		SharedModule m_module;

	public:
		SharedLibrary(std::wstring_view path) 
		  : m_module{::LoadLibraryW(ThrowIfEmpty(path).data())}
		{
			if (!this->m_module)
				LastError{}.throwAlways();
		}

		template <typename Signature, size_t NumResultParameters = 0>
		auto
		loadFunction(std::string_view name)
		{
			using proc_signature_t = meta::add_function_pointer_t<Signature>;
			if (auto* const pfx = reinterpret_cast<proc_signature_t>(::GetProcAddress(*this->m_module, name.data())); !pfx)
				LastError{}.throwAlways();
			else
				return pfx;
		}
	};
}
