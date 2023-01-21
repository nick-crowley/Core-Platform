#pragma once
#include "library/core.Platform.h"
#include "win/ManualResetEvent.h"

namespace nstd
{
	//! @brief	Custom stop-token
	class stop_token : public core::win::ManualResetEvent
	{
	public:
		stop_token() : core::win::ManualResetEvent{false}
		{}

	public:
		void 
		reset() = delete;
	};

	//! @brief	Thread supporting custom stop-tokens
	class thread : protected std::thread
	{
		using base = std::thread;

	public:
		//! @brief	Construct from function of signature `T (stop_token)`
		template <std::invocable<stop_token> UnaryFunction>
		explicit 
		thread(stop_token canx, UnaryFunction&& fx)
			: base(std::move(fx), std::move(canx))
		{
		}
		
		satisfies(thread,
			NotDefaultConstructible,
			NotCopyable,
			IsMovable,
			NotEqualityComparable,
			NotSortable
		);

	public:
		using base::joinable;
		using base::get_id;

	public:
		using base::detach;
		using base::join;
		using base::native_handle;
		using base::swap;
		
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
				return core::win::waitFor(this->native_handle(), timeout);
		}
	};
}
