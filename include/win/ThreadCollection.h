#pragma once
#include "nstd/Thread.h"
#include "win/ManualResetEvent.h"

namespace core::win
{
	class ThreadCollection
	{
	private:
		stop_token               m_stopToken;
		std::vector<nstd::thread>  m_workers;

	public:
		explicit
		ThreadCollection(stop_token canx)
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
		stop_token
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
			static selectHandle = [](nstd::thread& t) { return t.native_handle(); };

			win::waitForAll(this->m_workers | std::views::transform(selectHandle), timeout);
		}

		ThreadCollection& 
		operator+=(nstd::thread&& t) noexcept
		{
			this->m_workers.push_back(std::move(t));
			return *this;
		}
	};
}
