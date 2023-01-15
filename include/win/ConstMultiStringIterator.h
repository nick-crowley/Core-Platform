#pragma once
#include "library/core.Platform.h"

namespace core::win
{
	class ConstMultiStringIterator 
		: public boost::iterator_facade<ConstMultiStringIterator, std::wstring_view const, std::forward_iterator_tag>
	{
		friend class boost::iterator_core_access;
		using type = ConstMultiStringIterator;

		std::wstring_view const
		inline static npos;

	private:
		std::wstring_view  m_current;
		std::wstring_view  m_source;

	public:
		ConstMultiStringIterator()
		  : m_source{npos}
		{
		}

		ConstMultiStringIterator(std::wstring_view src)
		  : m_source{src}
		{
		}

	private:
		void
		increment() 
		{ 
			if (this->m_current.front() == L'\0')
				this->m_current = npos;
			else
				this->m_current.remove_prefix(this->m_current.find(L'\0')+1);
		}

		bool 
		equal(type const& other) const
		{
			return this->m_current == other.m_current;
		}

		std::wstring_view const& 
		dereference() const 
		{ 
			return this->m_current; 
		}
	};
}
