#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "core/Exceptions.h"

namespace nstd
{
	struct postcondition_violated : ::core::runtime_error {
		postcondition_violated(std::string_view expression)
			: core::runtime_error{"'{}' was false at exit", expression}
		{}
	};
}

namespace nstd::detail
{
	class NormalExitSentry
	{
		std::function<void()> const m_action;

	public:
		template <std::invocable<> Callable>
		implicit 
		NormalExitSentry(Callable&& fx) 
		  : m_action{fx}
		{}

		~NormalExitSentry() noexcept(false) {
			if (std::uncaught_exceptions() == 0)
				this->m_action();
		}

		satisfies(NormalExitSentry,
			NotDefaultConstructible,
			NotCopyable,
			NotMovable);
	};

	//! @brief	Execute a block of code on normal/abnormal exit (non-standard)
	//! @param	...		[optional] Lambda capture-mode
#	define _on_exit_sentry(...)		\
		::nstd::detail::NormalExitSentry const BOOST_PP_CAT(_onExitSentry,__COUNTER__) = [__VA_ARGS__]()
}

namespace nstd
{
	//! @brief	Throws if expression is untrue when function exits normally
	//! 
	//! @param	condExpr	Boolean expression
	//! 
	//! @remarks	Does nothing when exiting due to an exception being thrown
	//! @remarks	Does nothing when evaluated during stack unwinding
#	define PostCondition(condExpr)		_on_exit_sentry { if (!(condExpr)) throw ::nstd::postcondition_violated{#condExpr}; }
}