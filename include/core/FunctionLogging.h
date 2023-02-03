#pragma once
#include "library/core.Platform.h"

namespace core::detail
{
    std::wstring 
    inline to_wstring(char const* s) { 
        return {s, s+strlen(s)}; 
    }
    
    std::wstring 
    inline to_wstring(wchar_t const* s) { 
        return {s, s+wcslen(s)}; 
    }

    std::wstring 
    inline to_wstring(std::string const& s) { 
        return {s.begin(), s.end()}; 
    }

    std::wstring 
    inline to_wstring(std::wstring const& ws) { 
        return ws; 
    }

#ifdef __ATLSTR_H__
    std::wstring 
    inline to_wstring(ATL::CString const& s) { 
        return s.GetString(); 
}
#endif

    template <typename Enum> 
        requires std::is_enum_v<Enum>
    std::wstring 
    inline to_wstring(Enum&& e) { 
        return L"todo"; 
    }

    // BUG: std::decay_t<T> so if T is char[N]
    // BUG: Include non-const character arrays
    template <typename T>
    constexpr bool is_stringish_v = 
#ifdef __ATLSTR_H__
        meta::is_any_of_v<T,char*,wchar_t*,char const*,wchar_t const*,std::string,std::wstring,ATL::CString>;
#else
        meta::is_any_of_v<T,char*,wchar_t*,char const*,wchar_t const*,std::string,std::wstring>;
#endif
}

namespace core::meta
{
    template <typename T> 
    concept WStringCompatible = requires(T&& value) 
    { 
	    to_wstring(value); 
    };
}

template <typename T>
std::wstring 
to_wstring(T** value)
{
    if constexpr (core::meta::is_any_of_v<std::remove_const_t<T>,char,wchar_t>)
        return !value ? L"nullptr" : L'\'' + to_wstring(*value) + L'\'';
    else if constexpr (core::meta::WStringCompatible<T*> || core::meta::WStringCompatible<T>)
        return !value ? L"nullptr" : L'*' + to_wstring(*value);
    else
        return !value ? L"nullptr" : L"0x" + std::to_wstring(reinterpret_cast<uintptr_t>(value));
}

template <typename T>
std::wstring 
to_wstring(T* value) requires (!std::is_integral_v<T>)
{
    if constexpr (core::meta::WStringCompatible<T>)
        return !value ? L"nullptr" : L'*' + to_wstring(*value);
    else
        return !value ? L"nullptr" : L"0x" + std::to_wstring(reinterpret_cast<uintptr_t>(value));
}

std::wstring 
inline to_wstring(BOOL const* value)
{
    return !value ? L"nullptr" 
        : (*value ? L"TRUE" : L"FALSE");
}

std::wstring 
inline to_wstring(DWORD const* value)
{
    return !value ? L"nullptr" 
        : ((LONG)*value < 0 ? std::to_wstring((LONG)*value) : std::to_wstring(*value));
}

namespace core
{
    std::add_lvalue_reference_t<std::wostream>
    extern clog;

    struct LoggingSentry
    {
    private:
        template <typename T>
        using argument_t = std::pair<T,char const*>;

        enum OutputStyle { Adorned, Bare };

        int 
        inline static thread_local s_callDepth = -1;

    private:
        std::function<void(LoggingSentry&)> m_onExit;
        std::wostream& m_output;
        int m_uncaught;

    public:
        explicit
        LoggingSentry(std::wostream& output) 
            : m_output{output}, m_uncaught{std::uncaught_exceptions()}
        {
            ++s_callDepth;
        }

        ~LoggingSentry()
        {
            if (this->m_onExit)
                if (this->m_uncaught == std::uncaught_exceptions())
                    this->m_onExit(*this);
            --s_callDepth;
        }
        
        satisfies(LoggingSentry,
            NotDefaultConstructible,
            NotCopyable,
            NotMovable,
            NotEqualityComparable,
            NotSortable
        );
        
    public:
        template <typename... Parameters>
        LoggingSentry& 
        onEntry(char const* function, const argument_t<Parameters>&... args) 
        {
            this->print(function, args...);
            return *this;
        }
    
        LoggingSentry& 
        onEntry(std::exception const& e) 
        {
            this->prefix();
            this->m_output << "+-> THROWN: " << e.what() << std::endl;
            return *this;
        }
    
        template <typename LoggingDelegate>
        void 
        onExit(LoggingDelegate&& fx)
        {
            this->m_onExit = fx;
        }

        template <typename... Parameters>
        void 
        print(char const* ident, argument_t<Parameters> const&... args) 
        {
            this->prefix();

            this->write<Bare>(ident);
            this->write<Bare>(L"(");

            if constexpr (sizeof...(Parameters) > 0) 
                this->write(args...);

            this->write<Bare>(L")");

            this->m_output << std::endl;
        }
    
        template <typename... Parameters>
        void 
        print(argument_t<Parameters> const&... args) 
        {
            if constexpr (sizeof...(Parameters) > 0) {
                this->prefix();
                this->write<Bare>(L"+-> ");
                this->write(args...);
                this->m_output << std::endl;
            }
        }

    private:
        void
        prefix() 
        {
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
            this->m_output << std::put_time(&tm, L"[%H:%M:%S]")
                           << " P-" << ::GetCurrentProcessId() 
                           << " T-" << ::GetCurrentThreadId() 
                           << " : ";
            for (int i = 0; i < s_callDepth; ++i)
                this->m_output << "  ";
        }

        template <OutputStyle Style, typename T>
        void 
        write(T const& arg)
        {
            using ::to_wstring;
            using std::to_wstring;
            using detail::to_wstring;
        
            if constexpr (Style == Adorned && detail::is_stringish_v<T>)
                this->m_output << '"';

            this->m_output << to_wstring(arg);

            if constexpr (Style == Adorned && detail::is_stringish_v<T>)
                this->m_output << '"';
        }
    
        template <typename T>
        void 
        write(argument_t<T> const& arg) 
        {
            this->write<Bare>(arg.second);
            this->write<Bare>("=");
            this->write<Adorned>(arg.first);
        }

        template <typename T, typename... Parameters>
        void 
        write(argument_t<T> const& arg, argument_t<Parameters> const&... args)
        {
            this->write(arg);
            this->write<Bare>(", ");
            this->write(args...);
        }
    };
}

#define _makeLoggingArgument(s,d,e)                                                                                         \
    std::make_pair(e,#e)

#define _makeLoggingArgumentList(...)                                                                                       \
    BOOST_PP_LIST_ENUM(BOOST_PP_LIST_TRANSFORM(_makeLoggingArgument, ~, BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__)))

#define logFunction(...)                                                                                                    \
    ::core::LoggingSentry loggingSentry{clog};                                                                         \
    loggingSentry.onEntry(                                                                                                  \
        __FUNCTION__                                                                                                        \
        __VA_OPT__(, _makeLoggingArgumentList(__VA_ARGS__))                                                                 \
    )

#define withRetVals(...)                                                                                                    \
    onExit([&](::core::LoggingSentry& s) {                                                                                  \
        return s.print(                                                                                                     \
			_makeLoggingArgumentList(__VA_ARGS__)                                                                           \
        );                                                                                                                  \
    })

#define logException(e)                                                                                                     \
    ::core::LoggingSentry loggingSentry{clog};                                                                         \
    loggingSentry.onEntry(e)
