#pragma once
#include "library/core.Platform.h"
#include "core/LogStream.h"
#include "core/ToString.h"

namespace core::detail
{
    // BUG: std::decay_t<T> so if T is char[N]
    template <typename T>
    constexpr bool is_stringish_v = meta::is_any_of_v<T,gsl::zstring,gsl::wzstring,
                                                        gsl::czstring,gsl::cwzstring,
#ifdef HAS_ATL_STRING
                                                        ATL::CString
#endif
                                                        std::string,std::wstring>;
}

namespace core
{
    struct LoggingSentry
    {
    private:
        template <typename T>
        using NameValuePair = std::pair<gsl::czstring,T>;

        using LoggingDelegate = std::function<void(LoggingSentry&)>;

        enum OutputStyle { Adorned, Bare };

    private:
        int 
        inline static thread_local s_callDepth = -1;

        char constexpr
        inline static s_padding[] = "           ";

    private:
        std::stringstream m_assembly;
        LoggingDelegate   m_onExit;
        LogStream&        m_output;
        int               m_uncaught;

    public:
        explicit
        LoggingSentry(LogStream& output) 
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
        
    private:
        std::string_view
        static padding() {
            return {s_padding, s_padding+std::clamp(s_callDepth,0,10)};
        }

    public:
        template <typename... Values>
        LoggingSentry& 
        onEntry(gsl::czstring function, const NameValuePair<Values>&... args) 
        {
            this->print(function, args...);
            return *this;
        }
    
        LoggingSentry& 
        onEntry(std::exception const& e) 
        {
            this->m_output << Failure{"{}+-> THROWN: {}", this->padding(), e.what()};
            return *this;
        }
    
        template <std::invocable<LoggingSentry&> Delegate>
        std::void_t<LoggingSentry&>
        onExit(Delegate&& fx)
        {
            this->m_onExit = fx;
        }

        template <typename... Values>
        void 
        print(gsl::czstring func, NameValuePair<Values> const&... args) 
        {
            this->write<Bare>(this->padding());
            this->write<Bare>(func);
            this->write<Bare>("(");

            if constexpr (sizeof...(Values) > 0) 
                this->writeArgs(args...);

            this->write<Bare>(")");
            this->m_output << Verbose{noformat,this->m_assembly.str()};
            this->m_assembly = std::stringstream{};
        }
    
        template <typename... Values>
        void 
        print(NameValuePair<Values> const&... args) 
        {
            if constexpr (sizeof...(Values) > 0) {
                this->write<Bare>(this->padding());
                this->write<Bare>("+-> ");
                this->writeArgs(args...);
                this->m_output << Verbose{noformat,this->m_assembly.str()};
            }
        }

    private:
        template <OutputStyle Style, typename T>
        void 
        write(T const& arg)
        {
            using ::to_string;
            using std::to_string;
            using core::to_string;
        
            if constexpr (Style == Adorned && detail::is_stringish_v<T>)
                this->m_assembly << '"';

            this->m_assembly << to_string(arg);

            if constexpr (Style == Adorned && detail::is_stringish_v<T>)
                this->m_assembly << '"';
        }
    
        template <typename T>
        void 
        writeArgs(NameValuePair<T> const& arg) 
        {
            this->write<Bare>(arg.first);
            this->write<Bare>("=");
            this->write<Adorned>(arg.second);
        }

        template <typename T, typename... Parameters>
        void 
        writeArgs(NameValuePair<T> const& arg, NameValuePair<Parameters> const&... args)
        {
            this->writeArgs(arg);
            this->write<Bare>(", ");
            this->writeArgs(args...);
        }
    };
}

#define _makeLoggingArgument(s,d,e)                                                                                         \
    std::make_pair(#e,e)

#define _makeLoggingArgumentList(...)                                                                                       \
    BOOST_PP_LIST_ENUM(BOOST_PP_LIST_TRANSFORM(_makeLoggingArgument, ~, BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__)))

#define logFunction(...)                                                                                                    \
    ::core::LoggingSentry loggingSentry{clog};                                                                              \
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
    clog << static_cast<std::exception const&>(e)
