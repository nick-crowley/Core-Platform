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
#include "core/ToHexString.h"
#include "win/SystemError.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Extensible Windows status-code categorized as either success/failure (32-bit)
	*/
	class PlatformExport HResult
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		::HRESULT Value;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		constexpr
		implicit
		HResult(::HRESULT val) noexcept : Value{val}
		{}
		
		template <nstd::AnyArithmeticExcept<long,::HRESULT> T>
		constexpr
		implicit 
		HResult(T, std::source_location = std::source_location::current()) noexcept = delete;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(HResult,
			NotDefaultConstructible,
            constexpr IsCopyable noexcept,
			constexpr IsEqualityComparable noexcept,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		::HRESULT constexpr
		code() const noexcept {
			return this->Value;
		}

		std::string
		str() const;
		
		[[noreturn]] 
		void 
		throwAlways() const {
			throw system_error{this->Value};
		}
		
		template <typename... Params>
		[[noreturn]] 
		void 
		throwAlways(std::string_view msg, Params&&... args) const {
			throw system_error{this->Value, 
			                   std::vformat(msg,std::make_format_args(args...))};
		}
		
		template <typename... Params>
		void 
		throwIfError(std::string_view msg, Params&&... args) const {
			if (FAILED(this->Value))
				throw system_error{this->Value, 
				                   std::vformat(msg,std::make_format_args(args...))};
		}
		
		constexpr
		explicit operator
		bool() const noexcept {
			return SUCCEEDED(this->Value);
		}

		constexpr
		implicit operator
		::HRESULT() const noexcept {
			return this->Value;
		}
		
		template <nstd::AnyArithmeticExcept<::HRESULT> T>
		constexpr
		implicit operator
		T() const noexcept = delete;
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o

	};
	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Windows status-code which throws when assigned a failure value
	*/
	class ThrowingHResult
	{
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	private:
		::HRESULT Value = S_OK;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		implicit
		ThrowingHResult(::HRESULT val, std::source_location loc = std::source_location::current()) 
		  : Value{val}
		{
			if (FAILED(val))
				throw system_error{val, HResult{val}.str()};
		}
		
		template <nstd::AnyArithmeticExcept<long,::HRESULT> T>
		implicit
		ThrowingHResult(T, std::source_location = std::source_location::current()) = delete;

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	public:
		satisfies(ThrowingHResult,
			IsDefaultConstructible,
			NotCopyConstructible,
			IsCopyAssignable,
			IsEqualityComparable noexcept,
			NotSortable
		);
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
		
		// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
	};
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win
{
	std::string
	inline to_string(HResult const& hr)
	{
		return hr.str();
	}

	std::wstring
	to_wstring(HResult const&) = delete;


	template <nstd::AnyOf<long,::HRESULT> T>
	bool constexpr
	operator==(T value, HResult r) noexcept {
		return value == r.code();
	}
		
	template <nstd::AnyOf<long,::HRESULT> T>
	bool constexpr
	operator==(HResult l, T value) noexcept {
		return value == l.code();
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::win::testing
{
	//! @test	Verify @c win::HResult equality relationship is well-defined
	static_assert(requires(win::HResult lhs, win::HResult rhs) { 
		lhs == rhs; 
		lhs != rhs; 
		rhs == lhs;
		lhs != rhs; 
	});
	
	//! @test	Verify @c win::HResult equality relationship with @c ::HRESULT is well-defined
	static_assert(requires(win::HResult lhs, ::HRESULT rhs) { 
		lhs == rhs; 
		lhs != rhs; 
		rhs == lhs;
		rhs != lhs;
	});
	
	template <typename T>
	concept CanOnlyBeConstructedFromHRESULT = requires(::HRESULT v) { T(v); }
	                                       && !requires(bool     v) { T(v); }
	                                       && !requires(char     v) { T(v); }
	                                       && !requires(wchar_t  v) { T(v); }
	                                       && !requires(int      v) { T(v); }
	                                       && !requires(unsigned v) { T(v); }
	                                       && !requires(float    v) { T(v); }
	                                       && !requires(double   v) { T(v); }
	                                       && !requires(void*    v) { T(v); };

	//! @test	Verify @c win::HResult can only be constructed from @c ::HRESULT
	static_assert(CanOnlyBeConstructedFromHRESULT<win::HResult>);
	
	template <typename T>
	concept CanOnlyConvertToBoolAndHRESULT = requires(::HRESULT v, T t) { v = t;   }
	                                      && requires(T t)              { (bool)t; }
	                                      && !requires(bool     v, T t) { v = t;   }
	                                      && !requires(char     v, T t) { v = t;   }
	                                      && !requires(wchar_t  v, T t) { v = t;   }
	                                      && !requires(int      v, T t) { v = t;   }
	                                      && !requires(unsigned v, T t) { v = t;   }
	                                      && !requires(float    v, T t) { v = t;   }
										  && !requires(double   v, T t) { v = t;   }
	                                      && !requires(void*    v, T t) { v = t;   };

	//! @test	Verify @c win::HResult can only be converted to @c bool and @c ::HRESULT
	static_assert(CanOnlyConvertToBoolAndHRESULT<win::HResult>);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o