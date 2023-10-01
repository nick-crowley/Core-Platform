/* o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o */ /*!
* @copyright	Copyright (c) 2023, Nick Crowley. All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions
*    and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of
*    conditions and the following disclaimer in the documentation and/or other materials provided
*    with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
* FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
* WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* The views and conclusions contained in the software and documentation are those of the author 
* and should not be interpreted as representing official policies, either expressed or implied, of
* the projects which contain it.
*/
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Preprocessor Directives o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#pragma once
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "library/core.Platform.h"
#include "win/Concurrency.h"
#include "nstd/Thread.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd 
{
	namespace detail 
	{
		template <typename T>
		class shared_state 
		{
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			using value_type = T;
			using state_type = std::variant<std::exception_ptr,value_type>;
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		private:
			std::optional<state_type>  Value;
			std::atomic_bool           IsValid = false;
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			satisfies(shared_state, 
				IsDefaultConstructible,
				IsMovable,
				NotCopyable,
				NotEqualityComparable,
				NotSortable
			);
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

			// o~=~-~=~-~=~-~=~-~=~-~=~-~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			bool constexpr
			valid() const {
				return this->IsValid;
			}
			// o~=~-~=~-~=~-~=~-~=~-~=~-~=o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~o
		public:
			value_type
			get_value() {
				if (!this->IsValid)
					throw std::runtime_error("Not ready");

				final_act(&) noexcept { this->Value.reset(); };
				if (std::holds_alternative<value_type>(*this->Value))
					return std::get<value_type>(*this->Value);
				else
					std::rethrow_exception(std::get<std::exception_ptr>(*this->Value));
			}
			
			void
			set_exception(std::exception_ptr) = delete;
			
			void
			set_value(value_type) = delete;

			void
			set_exception_at_thread_exit(std::exception_ptr ptr) {
				if (this->IsValid)
					throw std::runtime_error("Already set");

				this->Value = ptr;
				this->IsValid = true;
			}

			template <typename ValueType>
			void
			set_value_at_thread_exit(ValueType&& value) {
				if (this->IsValid)
					throw std::runtime_error("Already set");

				this->Value = std::forward<ValueType>(value);
				this->IsValid = true;
			}
		};
	}
	
	template <typename T>
	class future;

	template <std::invocable<stop_token> Function>
	future<std::invoke_result_t<Function,stop_token>>
	async(stop_token canx, Function&& fx);

	//! @brief	Non-standard future compatible with Windows wait functions
	template <typename T>
	class future 
	{
		template <std::invocable<stop_token> F>
		future<std::invoke_result_t<F,stop_token>>
		friend async(stop_token, F&&);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		using type = future<T>;
		using value_type = T;
		using state_type = detail::shared_state<value_type>;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		std::shared_ptr<state_type>  Result;
		thread                       mutable Worker;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		future(std::shared_ptr<state_type> state, thread thread)
		  : Result{std::move(state)}, 
		    Worker{std::move(thread)}
		{}
	
	public:
		future(type&& r) noexcept {
			r.swap(*this);
		}

		type&
		operator=(type&& r) noexcept {
			r.swap(*this);
			return *this;
		}

		~future() {
			if (this->Worker.joinable())
				this->Worker.detach();
		}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(future, 
			IsDefaultConstructible,
			NotCopyable,
			NotEqualityComparable,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		bool constexpr
		valid() const {
			return this->Result && this->Result->valid();
		}

		void
		wait() const {
			Invariant(this->Result != nullptr);
			core::win::waitFor(this->Worker.native_handle());
		}
		
		template <typename R, typename P>
		std::future_status
		wait_for(chrono::duration<R,P> timeout) const {
			Invariant(this->Result != nullptr);
			return core::win::waitFor(this->Worker.native_handle(), timeout) 
				? std::future_status::ready : std::future_status::timeout;
		}
		
		template <nstd::Clock Clock>
		std::future_status
		wait_until(chrono::time_point<Clock> deadline) const {
			Invariant(this->Result != nullptr);
			return core::win::waitUntil(this->Worker.native_handle(), deadline) 
				? std::future_status::ready : std::future_status::timeout;
		}
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		value_type
		get() {
			Invariant(this->Result != nullptr);
			return this->Result->get_value();
		}

		::HANDLE
		handle() {
			Invariant(this->Result != nullptr);
			return this->Worker.native_handle();
		}

		void
		swap(type& r) noexcept {
			this->Worker.swap(r.Worker);
			this->Result.swap(r.Result);
		}
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{
	template <std::invocable<stop_token> Function>
	future<std::invoke_result_t<Function,stop_token>>
	async(stop_token canx, Function&& fx)
	{
		using result_t = std::invoke_result_t<Function,nstd::stop_token>;
		auto state = std::make_shared<detail::shared_state<result_t>>();

		auto const
		wrapper = [state,fx](nstd::stop_token canx) {
			try {
				state->set_value_at_thread_exit(fx(canx));
			}
			catch (...) {
				state->set_exception_at_thread_exit(std::current_exception());
			}
		};

		return future<result_t>{
			state,
			thread{std::move(canx), std::move(wrapper)}
		};
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o