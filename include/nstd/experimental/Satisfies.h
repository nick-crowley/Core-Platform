#pragma once
#ifndef CorePlatform_h_included
#	error Including this header directly may cause a circular dependency; include <corePlatform.h> directly
#endif
#include "../src/libBoost.h"

namespace nstd
{	
    
#define _DefaultConstructibleDecl(className)    className()
#define _DestructibleDecl(className)            ~className()
#define _CopyAssignableDecl(className)          className& operator=(className const&)
#define _CopyConstructibleDecl(className)       className(className const&)
#define _MoveAssignableDecl(className)          className& operator=(className&&)
#define _MoveConstructibleDecl(className)       className(className&&)
#define _EqualityComparableDecl(className)      bool operator==(className const&) const
#define _SortableDecl(className)                auto operator<=>(className const&) const

#define _MakeDefaultedConceptMacro(_declMacro)  BOOST_PP_COMMA() _declMacro BOOST_PP_COMMA() = default BOOST_PP_COMMA()
#define _MakeDeletedConceptMacro(_declMacro)    BOOST_PP_COMMA() _declMacro BOOST_PP_COMMA() = delete BOOST_PP_COMMA()

// Defaulted named requirements
#define IsDefaultConstructible		_MakeDefaultedConceptMacro(_DefaultConstructibleDecl)
#define IsDestructible		        _MakeDefaultedConceptMacro(_DestructibleDecl)
#define IsCopyAssignable            _MakeDefaultedConceptMacro(_CopyAssignableDecl)
#define IsCopyConstructible         _MakeDefaultedConceptMacro(_CopyConstructibleDecl)
#define IsMoveAssignable            _MakeDefaultedConceptMacro(_MoveAssignableDecl)
#define IsMoveConstructible         _MakeDefaultedConceptMacro(_MoveConstructibleDecl)
#define IsEqualityComparable        _MakeDefaultedConceptMacro(_EqualityComparableDecl)
#define IsSortable                  _MakeDefaultedConceptMacro(_SortableDecl)

// Deleted named requirements
#define NotDefaultConstructible		_MakeDeletedConceptMacro(_DefaultConstructibleDecl)
#define NotDestructible		        _MakeDeletedConceptMacro(_DestructibleDecl)
#define NotCopyAssignable           _MakeDeletedConceptMacro(_CopyAssignableDecl)
#define NotCopyConstructible        _MakeDeletedConceptMacro(_CopyConstructibleDecl)
#define NotMoveAssignable           _MakeDeletedConceptMacro(_MoveAssignableDecl)
#define NotMoveConstructible        _MakeDeletedConceptMacro(_MoveConstructibleDecl)
#define NotEqualityComparable       _MakeDeletedConceptMacro(_EqualityComparableDecl)
#define NotSortable                 _MakeDeletedConceptMacro(_SortableDecl)

//! @brief	Re-order elements of 4-tuple: {prefix, concept(class-name), enabled, postfix}
#define _expandConceptSubsequence(className,seq)      \
	BOOST_PP_SEQ_ELEM(0,seq) BOOST_PP_SEQ_ELEM(1,seq)(className) BOOST_PP_SEQ_ELEM(3,seq) BOOST_PP_SEQ_ELEM(2,seq)

// Accessors for retrieving state components
#define _getStateIdx(state)       BOOST_PP_SEQ_ELEM(0,state)
#define _getStateN(state)         BOOST_PP_SEQ_ELEM(1,state)
#define _getStateClassName(state) BOOST_PP_SEQ_ELEM(2,state)
#define _getStateConcepts(state)  BOOST_PP_SEQ_ELEM(3,state)

//! @brief	Define 4-tuple state: {idx, sizeof(concepts), class-name, {concepts}}
#define _makeConceptState(name,seq)   (0)(BOOST_PP_SEQ_SIZE(seq))(name)(seq) 

//! @brief	Define predicate: idx < sizeof(concepts)
#define _whileIdxLessThanN(r,state)   BOOST_PP_LESS(_getStateIdx(state), _getStateN(state)) 

//! @brief	Define stride of 4: {idx + 4, sizeof(concepts), class-name, {concepts}}
#define _IdxPlusEqualsFour(r,state)	  (BOOST_PP_ADD(_getStateIdx(state),4))(_getStateN(state))(_getStateClassName(state))(_getStateConcepts(state))  

//! @brief	Define loop body: fx("todo", subset(concepts,idx,4));
#define _ExpandFourTupleAtIdx(r,state) _expandConceptSubsequence(_getStateClassName(state), BOOST_PP_SEQ_SUBSEQ(_getStateConcepts(state),_getStateIdx(state),4)); 

//! @brief	Consume input sequence as blocks of 4-tuples: {prefix, concept, enabled, postfix}
#define _expandConceptSequence(className,seq) 	  \
	BOOST_PP_FOR(								  \
		_makeConceptState(className,seq),		  \
		_whileIdxLessThanN,						  \
		_IdxPlusEqualsFour,						  \
		_ExpandFourTupleAtIdx			          \
	)

//! @brief	Expands named requirements into defaulted/deleted method declarations
#define satisfies(className, ...)		\
	__VA_OPT__(_expandConceptSequence(className,BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

} // namespace nstd
