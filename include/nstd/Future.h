#pragma once
#include "library/core.Platform.h"
#include "win/Concurrency.h"
#include "win/StoppableThread.h"
#include "win/SmartHandle.h"

namespace nstd 
{
	namespace detail 
	{
		template <typename T>
		class shared_state 
		{
			using value_type = T;
			using state_type = std::variant<std::exception_ptr,value_type>;

		private:
			std::optional<state_type>  m_value;
			std::atomic_bool           m_valid = false;

		public:
			satisfies(shared_state, 
				IsDefaultConstructible,
				IsMovable,
				NotCopyable,
				NotEqualityComparable,
				NotSortable
			);

		public:
			bool constexpr
			valid() const {
				return this->m_valid;
			}

		public:
			value_type
			get_value() {
				if (!this->m_valid)
					throw std::runtime_error("Not ready");

				final_act(&) { this->m_value.reset(); };
				if (std::holds_alternative<value_type>(*this->m_value))
					return std::get<value_type>(*this->m_value);
				else
					std::rethrow_exception(std::get<std::exception_ptr>(*this->m_value));
			}
			
			void
			set_exception(std::exception_ptr) = delete;
			
			void
			set_value(value_type) = delete;

			void
			set_exception_at_thread_exit(std::exception_ptr ptr) {
				if (this->m_valid)
					throw std::runtime_error("Already set");

				this->m_value = ptr;
				this->m_valid = true;
			}

			template <typename ValueType>
			void
			set_value_at_thread_exit(ValueType&& value) {
				if (this->m_valid)
					throw std::runtime_error("Already set");

				this->m_value = std::forward<ValueType>(value);
				this->m_valid = true;
			}
		};
	}
	
	template <typename T>
	class future;

	template <std::invocable<core::win::ThreadStopToken> Function>
	future<std::invoke_result_t<Function,core::win::ThreadStopToken>>
	async(core::win::ThreadStopToken canx, Function&& fx);

	template <typename T>
	class future 
	{
		template <std::invocable<core::win::ThreadStopToken> F>
		future<std::invoke_result_t<F,core::win::ThreadStopToken>>
		friend async(core::win::ThreadStopToken, F&&);

		using value_type = T;
		using state_type = detail::shared_state<value_type>;
		
	private:
		std::shared_ptr<state_type>        m_state;
		mutable core::win::StoppableThread m_thread;

	private:
		future(std::shared_ptr<state_type> state, core::win::StoppableThread thread)
		  : m_state{std::move(state)}, 
		    m_thread{std::move(thread)}
		{}
		
	public:
		satisfies(future, 
			IsMovable,
			NotCopyable,
			NotEqualityComparable,
			NotSortable
		);

		~future() {
			if (this->m_thread.joinable())
				this->m_thread.detach();
		}

	public:
		bool constexpr
		valid() const {
			return this->m_state->valid();
		}

		void
		wait() const {
			core::win::waitFor(this->m_thread.native_handle());
		}
		
		template <typename R, typename P>
		std::future_status
		wait_for(std::chrono::duration<R,P> timeout) const {
			return core::win::waitFor(this->m_thread.native_handle(), timeout) 
				? std::future_status::ready : std::future_status::timeout;
		}
		
		template <core::meta::Clock Clock>
		std::future_status
		wait_until(std::chrono::time_point<Clock> deadline) const {
			return core::win::waitUntil(this->m_thread.native_handle(), deadline) 
				? std::future_status::ready : std::future_status::timeout;
		}
		
	public:
		value_type
		get() {
			return this->m_state->get_value();
		}

		::HANDLE
		handle() {
			return this->m_thread.native_handle();
		}
	};

	
	template <std::invocable<core::win::ThreadStopToken> Function>
	future<std::invoke_result_t<Function,core::win::ThreadStopToken>>
	async(core::win::ThreadStopToken canx, Function&& fx)
	{
		using result_t = std::invoke_result_t<Function,core::win::ThreadStopToken>;
		auto state = std::make_shared<detail::shared_state<result_t>>();

		auto const
		wrapper = [state,fx](core::win::ThreadStopToken canx) {
			try {
				state->set_value_at_thread_exit(fx(canx));
			}
			catch (...) {
				state->set_exception_at_thread_exit(std::current_exception());
			}
		};

		return future<result_t>{
			state,
			core::win::StoppableThread{std::move(canx), std::move(wrapper)}
		};
	}
}
