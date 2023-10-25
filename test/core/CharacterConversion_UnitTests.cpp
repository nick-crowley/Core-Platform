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
#ifndef DISABLE_CHARACTER_CONVERSION_UNIT_TESTS
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include <gtest/gtest.h>
#include <library/core.platform.h>
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
using namespace core;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
TEST(CharacterConversion_UT, narrow_NarrowsRepresentableToLatin1)
{
	//! @test  Verify @c core::narrow() converts wide-string characters representable in Latin-1 into equivalent narrow-string characters
	EXPECT_EQ(
		narrow(L"abc", CodePage::Latin1),
		"abc"
	);
}

TEST(CharacterConversion_UT, narrow_FailsForUnrepresentableLatin1)
{
	//! @test  Verify @c core::narrow() cannot narrow to Latin-1 a wide-string containing characters unrepresentable in Latin-1
	EXPECT_THROW(
		narrow(L"\u2764", CodePage::Latin1),
		std::invalid_argument
	);
}

TEST(CharacterConversion_UT, narrow_NarrowsRepresentableToUtf8)
{
	//! @test  Verify @c core::narrow() converts wide-string characters representable in Latin-1 into equivalent narrow-string characters
	EXPECT_EQ(
		narrow(L"abc", CodePage::Utf8),
		"abc"
	);
}

TEST(CharacterConversion_UT, narrow_NarrowsUnrepresentableToUtf8)
{
	//! @test  Verify @c core::narrow() encodes wide-string characters unrepresentable in Latin-1 into UTF-8 codepoints
	EXPECT_EQ(
		narrow(L"\u2764", CodePage::Utf8),
		reinterpret_cast<char const*>(u8"\u2764")
	);
}

TEST(CharacterConversion_UT, widen_widensRepresentableToLatin1)
{
	//! @test  Verify @c core::widen() converts narrow-string characters representable in Latin-1 into equivalent widen-string characters
	EXPECT_EQ(
		widen("abc", CodePage::Latin1),
		L"abc"
	);
}

TEST(CharacterConversion_UT, widen_widensRepresentableToUtf8)
{
	//! @test  Verify @c core::widen() converts narrow-string characters representable in Latin-1 into equivalent widen-string characters
	EXPECT_EQ(
		widen("abc", CodePage::Utf8),
		L"abc"
	);
}

TEST(CharacterConversion_UT, widen_widensUnrepresentableToUtf8)
{
	// 2764 vs 732b
	//! @test  Verify @c core::widen() encodes narrow-string characters unrepresentable in Latin-1 into UTF-8 codepoints
	EXPECT_EQ(
		widen(reinterpret_cast<char const*>(u8"\u2764"), CodePage::Utf8),
		L"\u2764"
	);
}


// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif	// DISABLE_CHARACTER_CONVERSION_UNIT_TESTS