#pragma once
#include "nstd/experimental/Satisfies.h"
#include "../../src/StdLibrary.h"

namespace nstd
{
	template <typename Routine>
	class default_suspendable
	{
		using type = default_suspendable<Routine>;
		using handle_type = std::coroutine_handle<type>;

	public:
		Routine
		get_return_object() {
			return Routine {
				std::shared_ptr<handle_type>{
					new handle_type{handle_type::from_promise(*this)},
					[](handle_type* p) { p->destroy(); }
				}
			};
		}

		std::suspend_always 
		initial_suspend() noexcept {
			return {};
		}

		std::suspend_always 
		final_suspend() noexcept {
			return {};
		}

		void
		return_void() noexcept {
		}

		void
		unhandled_exception() {
			std::terminate();
		}
	};

	template <template<typename> typename SuspensionPolicy = default_suspendable>
	class SharedCoroutine
	{
		using type = SharedCoroutine<SuspensionPolicy>;

	public:
		using promise_type = SuspensionPolicy<type>;
		using handle_type = std::coroutine_handle<promise_type>;

	private:
		std::shared_ptr<handle_type> Handle;

	public:
		explicit
		SharedCoroutine(std::shared_ptr<handle_type> h) noexcept : Handle{h}
		{}
	
		satisfies(SharedCoroutine,
			IsDefaultConstructible noexcept,
			IsCopyable noexcept,
			IsMovable noexcept
		);

	public:
		bool
		resume() const {
			if (!this->Handle || this->Handle->done())
				return false;

			this->Handle->resume();
			return !this->Handle->done();
		}
	};

	using Coroutine = SharedCoroutine<default_suspendable>;
}