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
#ifndef DISABLE_REFLECTION_SYSTEM_TESTS
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include <gtest/gtest.h>
#include <core/LogStream.h>
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
using namespace core;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

enum E1 : unsigned { V1, V2 };

class C1 {};

struct S1 {};

union U1 {};

namespace N1 {
	union U1 {};
	
	class C2 {};

	namespace N2 {
		class C3 {};
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

TEST(Reflection_UT, ClassName_ReturnsCorrectNameForClasses) 
{
	//! @test	Verify class name is correct and unadorned
	EXPECT_EQ(
		core::class_name_v<C1>,
		"C1"
	);
}

TEST(Reflection_UT, ClassName_ReturnsCorrectNameForStructs) 
{
	//! @test	Verify class name is correct and unadorned
	EXPECT_EQ(
		core::class_name_v<S1>,
		"S1"
	);
}

TEST(Reflection_UT, ClassName_ReturnsCorrectNameForNestedType) 
{
	//! @test	Verify class name is correct and namespace is present
	EXPECT_EQ(
		core::class_name_v<N1::C2>,
		"N1::C2"
	);
}

TEST(Reflection_UT, ClassName_ReturnsCorrectNameForDoubledNestedType) 
{
	//! @test	Verify class name is correct and multiple namespaces are present
	EXPECT_EQ(
		core::class_name_v<N1::N2::C3>,
		"N1::N2::C3"
	);
}

TEST(Reflection_UT, EnumeratorName_ReturnsCorrectNameForEnumerator) 
{
	//! @test	Verify class name is correct and doesn't include the enumeration type
	EXPECT_EQ(
		core::enumerator_name(E1::V1),
		"V1"
	);
}

TEST(Reflection_UT, IsValidEnumerator_ReturnsFalseForInvalidEnumerator) 
{
	//! @test	Verify invalid value is detected as invalid
	EXPECT_FALSE(
		core::is_valid_enumerator((E1)42)
	);
}

TEST(Reflection_UT, UnqualifiedClassName_ReturnsCorrectNameForNestedType) 
{
	//! @test	Verify class name is correct and namespace is stripped
	EXPECT_EQ(
		core::unqualified_class_name_v<N1::C2>,
		"C2"
	);
}

TEST(Reflection_UT, UnqualifiedClassName_ReturnsCorrectNameForDoubledNestedType) 
{
	//! @test	Verify class name is correct and multiple namespaces are all stripped
	EXPECT_EQ(
		core::unqualified_class_name_v<N1::N2::C3>,
		"C3"
	);
}

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif	// DISABLE_REFLECTION_SYSTEM_TESTS