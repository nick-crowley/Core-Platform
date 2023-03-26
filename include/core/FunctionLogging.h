#pragma once
#include "library/core.Platform.h"
#include "core/LogStream.h"
#include "core/ToString.h"

namespace core::detail
{
    template <typename T>
    constexpr bool is_stringish_v = meta::AnyOf<std::decay_t<T>,
                                                gsl::zstring,gsl::wzstring,
                                                gsl::czstring,gsl::cwzstring,
#ifdef HAS_ATL_STRING
                                                ATL::CString,
#endif
                                                std::string_view,std::wstring_view,
                                                std::string,std::wstring>;
}

namespace core
{
    struct PlatformExport LoggingSentry
    {
    private:
        template <typename T>
        using NameValuePair = std::pair<gsl::czstring,T>;

        using LoggingDelegate = std::function<void(LoggingSentry&)>;

        enum OutputStyle { Adorned, Bare };

    private:
        char constexpr
        inline static ReturnMarker[] = "\xe2\x95\x9a\xe2\x95\x90\xe2\x96\xba\x20";  // UTF-8 encoded "╚═► "

    private:
        int               initialUncaught;
        std::stringstream lineBuffer;
        LoggingDelegate   exitFunctor;
        LogStream&        outputStream;

    public:
        explicit
        LoggingSentry(LogStream& output) 
          : outputStream{output}, initialUncaught{std::uncaught_exceptions()}
        {
        }

        ~LoggingSentry()
        {
            this->outputStream.outdent();
            if (this->exitFunctor)
                if (this->initialUncaught == std::uncaught_exceptions())
                    this->exitFunctor(*this);
        }
        
        satisfies(LoggingSentry,
            NotDefaultConstructible,
            NotCopyable,
            NotMovable,
            NotEqualityComparable,
            NotSortable
        );
        
    public:
        template <typename... Values>
        LoggingSentry& 
        onEntry(gsl::czstring function, NameValuePair<Values> const&... args) 
        {
            this->print(function, args...);
            this->outputStream.indent();
            return *this;
        }
    
        LoggingSentry& 
        onEntry(std::exception const& e) 
        {
            this->outputStream << Failure{"{}THROWN: {}", LoggingSentry::ReturnMarker, e.what()};
            return *this;
        }
    
        template <std::invocable<LoggingSentry&> Delegate>
        std::void_t<LoggingSentry&>
        onExit(Delegate&& fx)
        {
            this->exitFunctor = fx;
        }

        template <typename... Values>
        void 
        print(gsl::czstring func, NameValuePair<Values> const&... args) 
        {
            this->write<Bare>(func);
            this->write<Bare>("(");

            if constexpr (sizeof...(Values) > 0) 
                this->writeArgs(args...);

            this->write<Bare>(")");
            this->outputStream << Verbose{noformat,this->lineBuffer.str()};
            this->lineBuffer = std::stringstream{};
        }
    
        template <typename... Values>
        void 
        print(NameValuePair<Values> const&... args) 
        {
            if constexpr (sizeof...(Values) > 0) {
                this->write<Bare>(LoggingSentry::ReturnMarker);
                this->writeArgs(args...);
                this->outputStream << Verbose{noformat,this->lineBuffer.str()};
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
                this->lineBuffer << '"';

            this->lineBuffer << to_string(arg);

            if constexpr (Style == Adorned && detail::is_stringish_v<T>)
                this->lineBuffer << '"';
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

#define _makeNameValuePair(s,d,e)                                                                                           \
    std::make_pair(#e,e)

#define _makeNameValuePairSequence(...)                                                                                     \
    BOOST_PP_LIST_ENUM(BOOST_PP_LIST_TRANSFORM(_makeNameValuePair, ~, BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__)))

#define logFunction(...)                                                                                                    \
    ::core::LoggingSentry loggingSentry{clog};                                                                              \
    loggingSentry.onEntry(                                                                                                  \
        __FUNCTION__                                                                                                        \
        __VA_OPT__(, _makeNameValuePairSequence(__VA_ARGS__))                                                               \
    )

#define withRetVals(...)                                                                                                    \
    onExit([&](::core::LoggingSentry& s) {                                                                                  \
        return s.print(                                                                                                     \
			_makeNameValuePairSequence(__VA_ARGS__)                                                                         \
        );                                                                                                                  \
    })

#define logException(e)                                                                                                     \
    clog << static_cast<std::exception const&>(e)
