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
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include "nstd/experimental/implicit.h"
#include "win/SystemError.h"
#include "../../src/library/PlatformExport.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win::detail
{
	std::string 
	PlatformExport formatMessage(::LRESULT err);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Long return-type frequently used by user-mode Windows APIs
	*/
	class LResult
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		::LRESULT Value;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		constexpr implicit
		LResult(::LRESULT val, std::source_location loc = std::source_location::current()) noexcept
		  : Value{val}
		{
		}
		
		template <nstd::AnyArithmeticExcept<long,::LRESULT> T>
		constexpr implicit
		LResult(T, std::source_location = std::source_location::current()) noexcept = delete;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(LResult,
			NotDefaultConstructible,
			constexpr IsCopyable noexcept,
			constexpr IsEqualityComparable noexcept,
			NotSortable,
			NotArithmetic
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		::LRESULT constexpr
		code() const noexcept {
			return this->Value;
		}

		std::string 
		str() const {
			return detail::formatMessage(this->Value);
		}
		
		[[noreturn]] void 
		throwAlways(std::string_view msg) const {
			throw system_error{this->Value, msg};
		}
		
		template <typename... Params>
			requires nstd::AtLeastOneType<Params...>
		[[noreturn]] void 
		throwAlways(std::string_view msg, Params&&... args) const {
			throw system_error{this->Value, std::vformat(msg,std::make_format_args(args...))};
		}

		template <typename... Params>
		[[noreturn]] void 
		throwAlways(std::wstring_view, Params&&...) const = delete;
		
		void 
		throwIfError(std::string_view msg) const {
			if (this->Value != ERROR_SUCCESS)
				throw system_error{this->Value, msg};
		}

		template <typename... Params>
			requires nstd::AtLeastOneType<Params...>
		void 
		throwIfError(std::string_view msg, Params&&... args) const {
			if (this->Value != ERROR_SUCCESS)
				throw system_error{this->Value, std::vformat(msg,std::make_format_args(args...))};
		}

		template <typename... Params>
		[[noreturn]] void 
		throwIfError(std::wstring_view, Params&&...) const = delete;
		
		std::wstring
		wstr() const {
			return cwiden(this->str());
		}
		
		constexpr explicit 
		operator bool() const noexcept {
			return this->Value == ERROR_SUCCESS;
		}

		constexpr implicit 
		operator ::LRESULT() const noexcept {
			return this->Value;
		}
		
		template <nstd::AnyArithmeticExcept<::LRESULT> T>
		constexpr implicit 
		operator T() const noexcept = delete;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
		
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Status-code returned by @c GetLastError()
	*/
	class LastError : public LResult 
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		implicit
		LastError(std::source_location loc = std::source_location::current()) 
			: LResult{::GetLastError(), loc} 
		{}
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(LastError,
			IsCopyable,
			IsEqualityComparable,
			NotSortable,
			NotArithmetic
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Success-only status-code which throws when assigned a failure code
	*/
	class ThrowingLResult
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		::LRESULT Value;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		implicit
		ThrowingLResult(::LRESULT val, std::source_location loc = std::source_location::current())
		  : Value{val}
		{
			if (val != ERROR_SUCCESS)
				throw system_error{val};
		}
		
		template <nstd::AnyArithmeticExcept<long,::LRESULT> T>
		implicit 
		ThrowingLResult(T, std::source_location = std::source_location::current()) = delete;
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(ThrowingLResult,
			NotDefaultConstructible,
			NotCopyable,
			IsEqualityComparable,
			NotSortable,
			NotArithmetic
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{	
	template <nstd::AnyOf<long,::LRESULT> T>
	bool constexpr
	operator==(T value, LResult r) noexcept {
		return value == r.code();
	}
		
	template <nstd::AnyOf<long,::LRESULT> T>
	bool constexpr
	operator==(LResult l, T value) noexcept {
		return value == l.code();
	}
	

	template <nstd::AnyOf<long,::LRESULT> T>
	bool constexpr
	operator==(T value, LastError r) noexcept {
		return value == r.code();
	}
		
	template <nstd::AnyOf<long,::LRESULT> T>
	bool constexpr
	operator==(LastError l, T value) noexcept {
		return value == l.code();
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win::testing
{
	//! @test	Verify @c win::LResult equality relationship is well-defined
	static_assert(requires(win::LResult lhs, win::LResult rhs) { 
		lhs == rhs; 
		lhs != rhs; 
		rhs == lhs;
		lhs != rhs; 
	});
	
	//! @test	Verify @c win::LResult equality relationship with @c ::LRESULT is well-defined
	static_assert(requires(win::LResult lhs, ::LRESULT rhs) { 
		lhs == rhs; 
		lhs != rhs; 
		rhs == lhs;
		rhs != lhs;
	});

	template <typename T>
	concept CanOnlyBeConstructedFromLRESULT = requires(::LRESULT v) { T(v); }
	                                       && !requires(bool     v) { T(v); }
	                                       && !requires(char     v) { T(v); }
	                                       && !requires(wchar_t  v) { T(v); }
	                                       && !requires(int      v) { T(v); }
	                                       && !requires(unsigned v) { T(v); }
	                                       && !requires(float    v) { T(v); }
	                                       && !requires(double   v) { T(v); }
	                                       && !requires(void*    v) { T(v); };

	//! @test	Verify @c win::LResult can only be constructed from @c ::LRESULT
	static_assert(CanOnlyBeConstructedFromLRESULT<win::LResult>);
	
	template <typename T>
	concept CanOnlyConvertToBoolAndLRESULT = requires(::LRESULT v, T t) { v = t;   }
	                                      && requires(T t)              { (bool)t; }
	                                      && !requires(bool     v, T t) { v = t;   }
	                                      && !requires(char     v, T t) { v = t;   }
	                                      && !requires(wchar_t  v, T t) { v = t;   }
	                                      && !requires(int      v, T t) { v = t;   }
	                                      && !requires(unsigned v, T t) { v = t;   }
	                                      && !requires(float    v, T t) { v = t;   }
										  && !requires(double   v, T t) { v = t;   }
	                                      && !requires(void*    v, T t) { v = t;   };

	//! @test	Verify @c win::LResult can only be converted to @c bool and @c ::LRESULT
	static_assert(CanOnlyConvertToBoolAndLRESULT<win::LResult>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o