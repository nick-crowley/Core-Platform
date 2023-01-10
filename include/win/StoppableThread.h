#pragma once
#include "corePlatform.h"
#include "ManualResetEvent.h"

namespace win
{
	//! @brief	Custom stop-token
	using ThreadStopToken = ManualResetEvent;

	//! @brief	Thread supporting custom stop-tokens
	class StoppableThread : public std::thread
	{
		using base = std::thread;

	public:
		//! @brief	Construct from function of signature `T (ThreadStopToken)`
		template <typename UnaryFunction> 
			requires std::is_invocable_v<UnaryFunction,ThreadStopToken>
		explicit 
		StoppableThread(ThreadStopToken canx, UnaryFunction&& fx)
			: base(std::move(fx), std::move(canx))
		{
		}
		
		satisfies(StoppableThread,
			NotDefaultConstructible,
			NotCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);

	public:
		bool 
		wait(std::chrono::milliseconds timeout)
		{
			if (timeout == timeout.zero()) 
			{
				if (this->joinable())
					this->join();

				return true;
			}
			else
				return win::waitFor(this->native_handle(), timeout);
		}
	};
}
