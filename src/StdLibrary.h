#pragma once

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
#include <source_location>
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

namespace core {
	namespace ranges = std::ranges;
	namespace views = std::ranges::views;
	namespace chrono = std::chrono;
}

namespace core::filesystem {
	using namespace std::filesystem;
}
