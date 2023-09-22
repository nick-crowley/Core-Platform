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
#include "../src/libBoost.h"
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace nstd
{	
#define _DefaultConstructibleDecl(className)    className()
#define _DestructibleDecl(className)            ~className()
#define _PolymorphicDecl(className)             virtual ~className()
#define _CopyAssignableDecl(className)          className& operator=(className const&)
#define _CopyConstructibleDecl(className)       className(className const&)
#define _MoveAssignableDecl(className)          className& operator=(className&&)
#define _MoveConstructibleDecl(className)       className(className&&)
#define _EqualityComparableDecl(className)      bool operator==(className const&) const
#define _SortableDecl(className)                auto operator<=>(className const&) const
#define _AddableDecl(className)                 className operator+(auto const&) const
#define _AddAssignableDecl(className)           className& operator+=(auto const&) const
#define _SubtractableDecl(className)            className operator-(auto const&) const
#define _SubtractAssignableDecl(className)      className& operator-=(auto const&) const
#define _NegatableDecl(className)               className operator-() const
#define _MultipliableDecl(className)            className operator*(auto const&) const
#define _MultiplyAssignableDecl(className)      className& operator*=(auto const&) const
#define _DividableDecl(className)               className operator/(auto const&) const
#define _DivideAssignableDecl(className)        className& operator/=(auto const&) const

#define _MakeDefaultedConceptMacro(...)         BOOST_PP_COMMA() BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) BOOST_PP_COMMA() = default BOOST_PP_COMMA()
#define _MakeDeletedConceptMacro(...)           BOOST_PP_COMMA() BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) BOOST_PP_COMMA() = delete BOOST_PP_COMMA()
#define _MakePureConceptMacro(decl)             BOOST_PP_COMMA() (virtual decl) BOOST_PP_COMMA() = 0 BOOST_PP_COMMA()

// Individual concepts (positive case)
#define IsDefaultConstructible		_MakeDefaultedConceptMacro(_DefaultConstructibleDecl)
#define IsDestructible		        _MakeDefaultedConceptMacro(_DestructibleDecl)
#define IsPolymorphic		        _MakeDefaultedConceptMacro(_PolymorphicDecl)
#define IsAbstract		            _MakePureConceptMacro(_DestructibleDecl)
#define IsCopyAssignable            _MakeDefaultedConceptMacro(_CopyAssignableDecl)
#define IsCopyConstructible         _MakeDefaultedConceptMacro(_CopyConstructibleDecl)
#define IsMoveAssignable            _MakeDefaultedConceptMacro(_MoveAssignableDecl)
#define IsMoveConstructible         _MakeDefaultedConceptMacro(_MoveConstructibleDecl)
#define IsEqualityComparable        _MakeDefaultedConceptMacro(_EqualityComparableDecl)
#define IsSortable                  _MakeDefaultedConceptMacro(_SortableDecl)

// Individual concepts (negative case)
#define NotDefaultConstructible		_MakeDeletedConceptMacro(_DefaultConstructibleDecl)
#define NotDestructible		        _MakeDeletedConceptMacro(_DestructibleDecl)
#define NotPolymorphic		        _MakeDefaultedConceptMacro(_DestructibleDecl)
#define NotCopyAssignable           _MakeDeletedConceptMacro(_CopyAssignableDecl)
#define NotCopyConstructible        _MakeDeletedConceptMacro(_CopyConstructibleDecl)
#define NotMoveAssignable           _MakeDeletedConceptMacro(_MoveAssignableDecl)
#define NotMoveConstructible        _MakeDeletedConceptMacro(_MoveConstructibleDecl)
#define NotEqualityComparable       _MakeDeletedConceptMacro(_EqualityComparableDecl)
#define NotSortable                 _MakeDeletedConceptMacro(_SortableDecl)

// Composite concepts
#define IsCopyable                  _MakeDefaultedConceptMacro(_CopyConstructibleDecl, _CopyAssignableDecl)
#define IsMovable                   _MakeDefaultedConceptMacro(_MoveConstructibleDecl, _MoveAssignableDecl)
#define IsSemiRegular               _MakeDefaultedConceptMacro(_DefaultConstructibleDecl, _CopyConstructibleDecl, _CopyAssignableDecl, _MoveConstructibleDecl, _MoveAssignableDecl)
#define IsRegular                   _MakeDefaultedConceptMacro(_DefaultConstructibleDecl, _CopyConstructibleDecl, _CopyAssignableDecl, _MoveConstructibleDecl, _MoveAssignableDecl, _EqualityComparableDecl)
#define NotCopyable                 _MakeDeletedConceptMacro(_CopyConstructibleDecl, _CopyAssignableDecl)
#define NotMovable                  _MakeDeletedConceptMacro(_MoveConstructibleDecl, _MoveAssignableDecl)
#define NotArithmetic               _MakeDeletedConceptMacro(_AddableDecl, _AddAssignableDecl, _SubtractableDecl, _SubtractAssignableDecl, _NegatableDecl, _MultipliableDecl, _MultiplyAssignableDecl, _DividableDecl, _DivideAssignableDecl)

//! @brief	Expand 4-tuple: {prefix, class-name, postfix, enabled} with concept-name 'prefix concept(class-name) postfix enabled'
#define _expandConceptDeclaration(r,state,conceptDecl)      \
	BOOST_PP_SEQ_ELEM(0,state) conceptDecl(BOOST_PP_SEQ_ELEM(1,state)) BOOST_PP_SEQ_ELEM(2,state) BOOST_PP_SEQ_ELEM(3,state);

//! @brief	Define another 4-tuple state: {prefix, class-name, postfix, enabled}
#define _makeDeclarationState(className,components)  (BOOST_PP_SEQ_ELEM(0,components))(className)(BOOST_PP_SEQ_ELEM(3,components))(BOOST_PP_SEQ_ELEM(2,components))

//! @brief	Iterate over concept-decls within 4-tuple: {prefix, {concept-decls}, enabled, postfix}
#define _expandConceptSubsequence(className,components)      \
	BOOST_PP_SEQ_FOR_EACH(_expandConceptDeclaration, _makeDeclarationState(className,components), BOOST_PP_SEQ_ELEM(1,components))

// Accessors for retrieving state components
#define _getStateIdx(state)       BOOST_PP_SEQ_ELEM(0,state)
#define _getStateN(state)         BOOST_PP_SEQ_ELEM(1,state)
#define _getStateClassName(state) BOOST_PP_SEQ_ELEM(2,state)
#define _getStateConcepts(state)  BOOST_PP_SEQ_ELEM(3,state)

//! @brief	Define 4-tuple state: {idx, sizeof({parameters}), class-name, {parameters}}
#define _makeConceptState(name,params)   (0)(BOOST_PP_SEQ_SIZE(params))(name)(params) 

//! @brief	Define predicate: idx < sizeof({parameters})
#define _whileIdxLessThanN(r,state)   BOOST_PP_LESS(_getStateIdx(state), _getStateN(state)) 

//! @brief	Define stride of 4 with new state: {idx + 4, sizeof(parameters), class-name, {parameters}}
#define _IdxPlusEqualsFour(r,state)	  (BOOST_PP_ADD(_getStateIdx(state),4))(_getStateN(state))(_getStateClassName(state))(_getStateConcepts(state))  

//! @brief	Define loop body: fx(class-name, subset(parameters,idx,4));
#define _ExpandFourTupleAtIdx(r,state) _expandConceptSubsequence(_getStateClassName(state), BOOST_PP_SEQ_SUBSEQ(_getStateConcepts(state),_getStateIdx(state),4))

//! @brief	Consume {parameter, ...} sequence as series of 4-tuples: {prefix, {concepts-decls}, enabled, postfix}
#define _expandConceptSequence(className,params)                                                  \
	BOOST_PP_FOR(                                                                                 \
		_makeConceptState(className,params),                                                      \
		_whileIdxLessThanN,                                                                       \
		_IdxPlusEqualsFour,                                                                       \
		_ExpandFourTupleAtIdx                                                                     \
	)

//! @brief	Expands supported concepts into defaulted/deleted method declarations
//! 
//! @param	className   Class name (without namespace qualifier)
//! @param	concept     First named-requirement to declare as defaulted or deleted
//! @param	nextConcept [optional] Second named-requirement to declare as defaulted or deleted
//! @param	    ...     [optional] Third named-requirement... and so on
#define satisfies(className, ...)		\
	__VA_OPT__(_expandConceptSequence(className,BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

} 
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o