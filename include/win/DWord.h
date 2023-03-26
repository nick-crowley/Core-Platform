#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/implicit.h"
#include "nstd/Concepts.h"
#include "../src/PlatformSdk.h"

namespace core::win
{
	template <nstd::ExplicitlyConvertible<::DWORD> ValueType> 
	class DWord
	{
		ValueType const& m_value;

	public:
		constexpr 
		explicit DWord(ValueType const& val)
		  : m_value{val}
		{}

	public:
		constexpr 
		implicit operator 
		::DWORD() const
		{
			return static_cast<::DWORD>(this->m_value);
		}
	};
}
