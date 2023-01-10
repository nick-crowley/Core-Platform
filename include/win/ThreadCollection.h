#pragma once
#include "StoppableThread.h"
#include "ManualResetEvent.h"

namespace win
{
	class ThreadCollection
	{
	private:
		ThreadStopToken               m_stopToken;
		std::vector<StoppableThread>  m_workers;

	public:
		explicit
		ThreadCollection(ThreadStopToken canx)
		  : m_stopToken{std::move(canx)}
		{
		}

		satisfies(ThreadCollection,
			NotDefaultConstructible,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);

	public:
		ThreadStopToken
		getStopToken() const
		{
			return this->m_stopToken;
		}
	
	public:
		void
		asyncStop() 
		{
			this->m_stopToken.signal();
		}

		void
		waitForAll(std::chrono::milliseconds timeout)
		{	
			auto constexpr 
			static selectHandle = [](StoppableThread& t) { return t.native_handle(); };

			win::waitForAll(this->m_workers | std::views::transform(selectHandle), timeout);
		}

		ThreadCollection& 
		operator+=(StoppableThread&& t) noexcept
		{
			this->m_workers.push_back(std::move(t));
			return *this;
		}
	};
}
