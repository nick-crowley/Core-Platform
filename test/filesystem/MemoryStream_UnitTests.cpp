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
#ifndef DISABLE_MEMORY_STREAM_UNIT_TESTS
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Header Files o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#include <gtest/gtest.h>
#include <filesystem/MemoryStream.h>
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
using namespace core;
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
TEST(MemoryStream_UT, Constructor_ThrowsWhenEmpty) 
{
	//! @test  Verify @c filesystem::MemoryStream constructor throws when input range is empty
	EXPECT_THROW(
		filesystem::MemoryStream<std::byte>{{}},
		std::invalid_argument
	);
}

TEST(MemoryStream_UT, Length_ReturnsLength) 
{
	wchar_t buffer[32];

	//! @test  Verify @c filesystem::MemoryStream::length() returns length of input buffer, in characters
	EXPECT_EQ(
		filesystem::MemoryStream<wchar_t>{buffer}.length(),
		32
	);
}

TEST(MemoryStream_UT, Read_ReturnsContents) 
{
	char buffer[] {"abcdefgh"};
	std::vector const expected {'a','b','c','d','e','f','g','h'};

	//! @test  Verify @c filesystem::MemoryStream::read() returns content of buffer
	EXPECT_EQ(
		filesystem::MemoryStream<char>{buffer}.read(8),
		expected
	);
}

TEST(MemoryStream_UT, Write_WritesContents) 
{
	char buffer[] {"abcdefgh"};
	std::string const expected {'e','f','g','h','e','f','g','h'};

	//! @test  Verify @c filesystem::MemoryStream::read() returns content of buffer
	EXPECT_EQ(
		filesystem::MemoryStream<char>{buffer}.write(std::vector{'e','f','g','h'}),
		4
	);
	EXPECT_EQ(
		buffer,
		expected
	);
}

TEST(MemoryStream_UT, Write_ThrowsWhenStreamIsConst)
{
	char const buffer[] {"abcdefgh"};
	
	//! @test  Verify @c filesystem::MemoryStream::write() throws when element type is @c const
	EXPECT_THROW(
		filesystem::MemoryStream<char const>{buffer}.write(std::vector<char>{'e','f','g','h'}),
		std::logic_error
	);
	
	//! @post  @c filesystem::MemoryStream::write() didn't write to the stream
	EXPECT_STREQ(
		buffer,
		"abcdefgh"
	);
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
#endif	// DISABLE_MEMORY_STREAM_UNIT_TESTS