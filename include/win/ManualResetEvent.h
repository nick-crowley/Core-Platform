#pragma once
#include "library/core.Platform.h"
#include "win/SharedHandle.h"
#include "win/Boolean.h"
#include "win/ApiHelpers.h"
#include "win/Concurrency.h"

namespace core::win
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
				LastError{}.throwAlways();
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
