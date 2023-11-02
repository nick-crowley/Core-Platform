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

#ifndef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#	error Core-Platform requires _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS be defined
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#	error Core-Platform requires _CRT_SECURE_NO_WARNINGS be defined
#endif

#ifndef _SCL_SECURE_NO_WARNINGS
#	error Core-Platform requires _SCL_SECURE_NO_WARNINGS be defined
#endif
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include <algorithm>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <concepts>
#include <compare>
#include <coroutine>
#include <exception>
#include <filesystem>
#include <format>
#include <future>
#include <functional>
#include <iterator>
#include <locale>
#include <memory>
#include <new>
#include <numeric>
#include <optional>
#include <ranges>
#include <regex>
#if defined(__clang__) && !defined(__cpp_consteval)
#	define __cpp_consteval 202211L
#	include <source_location>
#	undef __cpp_consteval 
#else
#	include <source_location>
#endif
#include <stdexcept>
#include <thread>
#include <type_traits>
#include <utility>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <streambuf>

#include <list>
#include <map>
#include <span>
#include <set>
#include <string>
#include <string_view>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>

#include <cassert>
#include <cctype>
#include <cstddef>

#ifndef GSL_THROW_ON_CONTRACT_VIOLATION
#	error Core-Platform requires GSL_THROW_ON_CONTRACT_VIOLATION be defined
#endif

#include <gsl/gsl>
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core {
	namespace ranges = std::ranges;
	namespace views = std::ranges::views;
	namespace chrono = std::chrono;

	using namespace std::string_view_literals;

	std::nullopt_t constexpr
	inline nullopt = std::nullopt;
}

namespace core::filesystem {
	using namespace std::filesystem;
}

namespace nstd {
	namespace ranges = std::ranges;
	namespace views = std::ranges::views;
	namespace chrono = std::chrono;
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o