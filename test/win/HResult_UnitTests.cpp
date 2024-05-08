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
#ifndef DISABLE_HRESULT_UNIT_TESTS
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

TEST(HResult, Str_CommonCodesStringified) 
{
	//! @test	Verify well-known error codes are stringified
	EXPECT_EQ(
		win::HResult{S_OK}.str(),
		"S_OK"
	);
	
	//! @test	Verify well-known error codes are stringified
	EXPECT_EQ(
		win::HResult{E_ACCESSDENIED}.str(),
		"E_ACCESSDENIED"
	);
}

TEST(HResult, Str_UnCommonCodesInHex) 
{
	//! @test	Verify uncommon error codes are represented by message (without unwanted whitespace) with code parenthesised in hex
	EXPECT_EQ(
		win::HResult{E_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED}.str(),
		"HD Audio widget does not support the connection list parameter. (0x80660003)"
	);
}

TEST(HResult, ThrowAlways_ThrowsForSuccessCode) 
{
	//! @test	Verify @c throwAlways() throws even for success codes
	EXPECT_THROW(
		win::HResult{S_OK}.throwAlways(),
		core::system_error
	);
}

TEST(HResult, ThrowAlways_ThrowsForFailureCode) 
{
	//! @test	Verify @c throwAlways() throws for failure codes
	EXPECT_THROW(
		win::HResult{E_ACCESSDENIED}.throwAlways(),
		core::system_error
	);
}

TEST(HResult, throwIfError_DoesNotThrowForSuccessCode) 
{
	//! @test	Verify @c throwIfError() doesn't throw for success codes
	EXPECT_NO_THROW(
		win::HResult{S_OK}.throwIfError("message")
	);
}

TEST(HResult, throwIfError_ThrowsForFailureCode) 
{
	//! @test	Verify @c throwIfError() throws for failure codes
	EXPECT_THROW(
		win::HResult{E_ACCESSDENIED}.throwIfError("message"),
		core::system_error
	);
}

TEST(HResult, BooleanOperator_ReturnsTrueForSuccessCode) 
{
	//! @test	Verify @c bool operator returns @c true for success codes
	EXPECT_TRUE(
		(bool)win::HResult{S_OK}
	);
}

TEST(HResult, BooleanOperator_ReturnsFalseForFailureCodes) 
{
	//! @test	Verify @c bool operator returns @c false for failure codes
	EXPECT_FALSE(
		(bool)win::HResult{E_NOTIMPL}
	);
}

TEST(HResult, BooleanOperator_ReturnsCodeProvidedAtConstruction) 
{
	//! @test	Verify @c ::HRESULT operator returns value provided at construction
	EXPECT_EQ(
		(::HRESULT)win::HResult{E_NOTIMPL},
		E_NOTIMPL
	);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif	// DISABLE_HRESULT_UNIT_TESTS