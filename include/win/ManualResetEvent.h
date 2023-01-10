#pragma once
#include "corePlatform.h"
#include "win/SmartHandle.h"
#include "win/Boolean.h"
#include "win/ApiHelpers.h"
#include "win/Concurrency.h"

namespace win
{
	class ManualResetEvent 
	{
		SharedEvent  m_handle;

	public:
		explicit 
		ManualResetEvent(bool initialState)
		  : m_handle{::CreateEventW(Unsecured, TRUE, Boolean{initialState}, nullptr)}
		{
			if (!this->m_handle)
				throw_exception(::GetLastError());
		}

		satisfies(ManualResetEvent,
			NotDefaultConstructible,
			IsCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);

	public:
		SharedEvent 
		handle() const 
		{
			return this->m_handle;
		}

		bool 
		signalled() const 
		{
			return isSignalled(*this->m_handle);
		}
		
		implicit operator
		bool() const 
		{
			return this->signalled();
		}

	public:
		void 
		reset()
		{
			::ResetEvent(*this->m_handle);
		}

		void 
		signal() 
		{
			::SetEvent(*this->m_handle);
		}
	};
}
