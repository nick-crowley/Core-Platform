#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "nstd/experimental/Implicit.h"
#include "nstd/experimental/Satisfies.h"
#include <functional>

namespace nstd
{
	//! @brief	Unconditionally executes a delegate upon destruction
	class FinalAction
	{
		std::function<void()> m_action;

	public:
		template <std::invocable<> Callable>
		implicit 
		FinalAction(Callable&& fx) : m_action{fx}
		{}

		~FinalAction() {
			this->m_action();
		}

		satisfies(FinalAction,
			NotDefaultConstructible,
			NotCopyable,
			NotMovable);
	};

	//! @brief	Execute a block of code on normal/abnormal function exit (non-standard)
	//! @param	...		[optional] Lambda capture-mode
#	define final_act(...)		\
		::nstd::FinalAction const BOOST_PP_CAT(_finalAct,__COUNTER__) = [__VA_ARGS__]()
}
