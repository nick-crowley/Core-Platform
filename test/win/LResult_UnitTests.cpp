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
#ifndef DISABLE_LRESULT_UNIT_TESTS
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include <gtest/gtest.h>
#include <library/core.Platform.h>
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
using namespace core;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

TEST(LResult, Str_ReturnsCorrectMessage) 
{
	//! @test	Verify error codes are stringified as expected
	EXPECT_EQ(
		win::LResult{ERROR_ACCESS_DENIED}.str(),
		"Access is denied."
	);
}

TEST(LResult, ThrowAlways_ThrowsForSuccessCode) 
{
	//! @test	Verify @c throwAlways() throws even for success codes
	EXPECT_THROW(
		win::LResult{ERROR_SUCCESS}.throwAlways(),
		win::system_error
	);
}

TEST(LResult, ThrowAlways_ThrowsForFailureCode) 
{
	//! @test	Verify @c throwAlways() throws for failure codes
	EXPECT_THROW(
		win::LResult{ERROR_ACCESS_DENIED}.throwAlways(),
		win::system_error
	);
}

TEST(LResult, throwIfError_DoesNotThrowForSuccessCode) 
{
	//! @test	Verify @c throwIfError() doesn't throw for success codes
	EXPECT_NO_THROW(
		win::LResult{ERROR_SUCCESS}.throwIfError("message")
	);
}

TEST(LResult, throwIfError_ThrowsForFailureCode) 
{
	//! @test	Verify @c throwIfError() throws for failure codes
	EXPECT_THROW(
		win::LResult{ERROR_ACCESS_DENIED}.throwIfError("message"),
		win::system_error
	);
}

TEST(LResult, BooleanOperator_ReturnsTrueForSuccessCode) 
{
	//! @test	Verify @c bool operator returns @c true for success codes
	EXPECT_TRUE(
		(bool)win::LResult{ERROR_SUCCESS}
	);
}

TEST(LResult, BooleanOperator_ReturnsFalseForFailureCodes) 
{
	//! @test	Verify @c bool operator returns @c false for failure codes
	EXPECT_FALSE(
		(bool)win::LResult{ERROR_PATH_NOT_FOUND}
	);
}

TEST(LResult, BooleanOperator_ReturnsCodeProvidedAtConstruction) 
{
	//! @test	Verify @c ::LRESULT operator returns value provided at construction
	EXPECT_EQ(
		(::LRESULT)win::LResult{ERROR_PATH_NOT_FOUND},
		ERROR_PATH_NOT_FOUND
	);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif	// DISABLE_LRESULT_UNIT_TESTS