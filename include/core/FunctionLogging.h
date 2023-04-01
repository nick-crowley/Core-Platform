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
#include "core/LogStream.h"
#include "core/ToString.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

#define _makeNameValuePair(s,d,e)                                                                 \
    std::make_pair(#e,e)

#define _makeNameValuePairSequence(...)                                                           \
    BOOST_PP_LIST_ENUM(                                                                           \
        BOOST_PP_LIST_TRANSFORM(_makeNameValuePair, ~, BOOST_PP_VARIADIC_TO_LIST(__VA_ARGS__))    \
    )

//! @brief  Log function entry/exit and specified arguments
//! 
//! @param[in]  ... Function arguments
#define logFunction(...)                                                                          \
    ::core::LoggingSentry loggingSentry{clog};                                                    \
    loggingSentry.onEntry(                                                                        \
        __FUNCTION__                                                                              \
        __VA_OPT__(, _makeNameValuePairSequence(__VA_ARGS__))                                     \
    )

//! @brief  Log specified variables upon function exit
//! 
//! @param[in]  ... Function variables
#define withRetVals(...)                                                                          \
    onExit([&](::core::LoggingSentry& s) {                                                        \
        return s.print(                                                                           \
            _makeNameValuePairSequence(__VA_ARGS__)                                               \
        );                                                                                        \
    })

//! @brief  Log a caught exception
//! 
//! @param[in]  ... Exception derived from @c std::exception
#define logException(e)                                                                           \
    clog << static_cast<std::exception const&>(e)

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core
{
    struct PlatformExport LoggingSentry
    {
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Types & Constants o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    private:
        template <typename T>
        using NameValuePair = std::pair<gsl::czstring,T>;

        using LoggingDelegate = std::function<void(LoggingSentry&)>;

        enum OutputStyle { Adorned, Bare };

    private:
        char constexpr
        inline static ReturnMarker[] = "\xe2\x95\x9a\xe2\x95\x90\xe2\x96\xba\x20";  // UTF-8 encoded "╚═► "
        
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Representation o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    private:
        int               initialUncaught;
        std::stringstream lineBuffer;
        LoggingDelegate   exitFunctor;
        LogStream&        outputStream;

        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Construction & Destruction o=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
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
        
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Copy & Move Semantics o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o
    public:
        satisfies(LoggingSentry,
            NotDefaultConstructible,
            NotCopyable,
            NotMovable,
            NotEqualityComparable,
            NotSortable
        );
        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=o Static Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o

        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~o Observer Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o

        // o~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Mutator Methods & Operators o~-~=~-~=~-~=~-~=~-~=~-~=~-~o
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
        
            if constexpr (Style == Adorned && nstd::Stringish<T>)
                this->lineBuffer << '"';

            this->lineBuffer << to_string(arg);

            if constexpr (Style == Adorned && nstd::Stringish<T>)
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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o