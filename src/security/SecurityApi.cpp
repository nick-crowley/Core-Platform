/* o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o */ /*!
* @copyright	Copyright (c) 2018, Nick Crowley. All rights reserved.
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
#include "security/SecurityApi.h"
#include "security/Identifier.h"
#include "security/Descriptor.h"
#include "win/Function.h"

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o Name Imports o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o
using namespace core;
using namespace security;

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o Forward Declarations o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-o Global Definitions o-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
SharedSecurityApi
security::security_api()
{
	return std::make_shared<SecurityApi>(); 
}

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~o Local Definitions o-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

auto constexpr
intern convertSidToStringSid = win::function<1>(::ConvertSidToStringSidW);

auto constexpr
intern convertStringSidToSidW = win::function<1>(::ConvertStringSidToSidW);

auto constexpr
intern convertDescriptorToStringW = win::function<2>(::ConvertSecurityDescriptorToStringSecurityDescriptorW);

auto constexpr
intern convertStringToDescriptorW = win::function<2>(::ConvertStringSecurityDescriptorToSecurityDescriptorW);

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~o Construction & Destruction o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-o Copy & Move Semantics o~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o Static Methods o~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-o Instance Methods & Operators o+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
bool
SecurityApi::compareSid(std::span<std::byte const> lhs, std::span<std::byte const> rhs) const
{
	ThrowIfEmpty(lhs);
	ThrowIfEmpty(rhs);

	// Strip cv-qualifiers for API compatibility
	return ::EqualSid(ConstSidWrapper{lhs}.as_mutable(), 
	                  ConstSidWrapper{rhs}.as_mutable()) != FALSE;
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
bool
SecurityApi::compareSidPrefix(std::span<std::byte const> lhs, std::span<std::byte const> rhs) const
{
	ThrowIfEmpty(lhs);
	ThrowIfEmpty(rhs);

	// Strip cv-qualifiers for API compatibility
	return ::EqualPrefixSid(ConstSidWrapper{lhs}.as_mutable(), 
	                        ConstSidWrapper{rhs}.as_mutable()) != FALSE;
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::wstring
SecurityApi::descriptorToString(std::span<std::byte const> bytes) const
{
	ThrowIfEmpty(bytes);

	auto       descriptor = ConstDescriptorWrapper(bytes).as_mutable();
	auto const flags = DACL_SECURITY_INFORMATION|GROUP_SECURITY_INFORMATION|OWNER_SECURITY_INFORMATION|SACL_SECURITY_INFORMATION;

	// Attempt to convert 'bytes' to descriptor
	//! @todo	Throws @c ERROR_NONE_MAPPED if @c SID is not found
	//! @todo	Throws @c ERROR_INVALID_ACL if @c ACL is invalid
	auto const [_str, length] = convertDescriptorToStringW(descriptor, SDDL_REVISION_1, flags);
	nstd::unique_local_ptr_t<wchar_t[]> str{_str};
	
	// [SUCCESS] Copy descriptor-string on return
	return {&str[0], &str[length]};
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::vector<std::byte>
SecurityApi::descriptorFromString(std::wstring_view str) const
{
	ThrowIfEmpty(str);

	// Attempt to convert 'str' to descriptor
	//! @todo	Throws @c ERROR_NONE_MAPPED if @c SID is not found
	auto [_sd, length] = convertStringToDescriptorW(str.data(), SDDL_REVISION_1);
	nstd::unique_local_ptr_t<::SECURITY_DESCRIPTOR> descriptor{static_cast<::SECURITY_DESCRIPTOR*>(_sd)};

	// [SUCCESS] Copy descriptor into byte-array on return
	auto bytes = DescriptorWrapper(descriptor.get()).bytes();
	return {bytes.begin(), bytes.end()};
}
#if 0
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
AccessRight
SecurityApi::get_access_rights(registry::RegistryHandle handle) const
{
	ThrowIfEmpty(handle);
	using namespace std::string_literals;

	// Load NtQueryObject() from ntdll.dll
	DynamicLibrary ntdll(L"ntdll.dll", DynamicLibrary::Immediate, this->m_platform_api);
	auto           NtQueryObject = ntdll.load<decltype(::NtQueryObject)>("NtQueryObject"s);

	::PUBLIC_OBJECT_BASIC_INFORMATION obj    = {};
	::ULONG                           length = sizeof(obj);

	// Query object properties
	if (::NTSTATUS res = NtQueryObject(*handle, ObjectBasicInformation, &obj, length, nullptr);
		res != STATUS_SUCCESS) {
		platform::throw_exception_from_error(HERE, {res, platform::kernel_category(this->m_platform_api)});
	}

	// Retrieve access rights
	return static_cast<CustomRight>(obj.GrantedAccess);
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
std::vector<std::byte>
SecurityApi::get_file_security(filesystem::FileHandle handle, Information components) const
{
	ThrowIfEmpty(handle);
	ThrowIfUndefined(components);

	return this->_get_descriptor(handle, SE_FILE_OBJECT, components);
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
std::vector<std::byte>
SecurityApi::get_key_security(registry::RegistryHandle handle, Information components) const
{
	ThrowIfEmpty(handle);
	ThrowIfUndefined(components);

	return this->_get_descriptor(handle, SE_REGISTRY_KEY, components);
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
std::vector<std::byte>
SecurityApi::get_path_security(filesystem::FilePath file[[maybe_unused]],
							   Information          components[[maybe_unused]]) const
{
	ThrowIfEmpty(file);
	ThrowIfUndefined(components);

	return this->_get_descriptor(file, SE_FILE_OBJECT, components);
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::optional<Account>
SecurityApi::lookup_account(std::span<std::byte const>       sid,
							std::optional<std::wstring_view> system) const
{
	ThrowIfEmpty(sid);
	ThrowMissingIfNot(system, !system || !system->empty());

	const wchar_t* origin = system ? system->data() : nullptr;
	wchar_t        name[128]{}, domain[128]{};
	::DWORD        name_len = lengthof(name), domain_len = lengthof(domain);
	std::byte*     mutable_sid = const_cast<std::byte*>(sid.data());
	::SID_NAME_USE usage{};

	// Lookup account name
	if (auto res = ::LookupAccountSidW(
		  origin, mutable_sid, name, &name_len, domain, &domain_len, &usage);
		res == 0) {
		// [NOT-FOUND]
		if (this->m_platform_api->get_last_error().value() == ERROR_NONE_MAPPED) {
			return std::nullopt;
		}

		// [FAILURE] Throw appropriate exception
		platform::throw_exception_from_error(HERE, this->m_platform_api->get_last_error());
	}

	// [FOUND] Return all components
	return Account{
		{sid.begin(),sid.end()}, 
		{&name[0], &name[name_len]}, 
		{&domain[0], &domain[domain_len]}
	};
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::optional<Account>
SecurityApi::lookup_account(std::wstring_view                name,
							std::optional<std::wstring_view> system) const
{
	ThrowIfEmpty(name);
	ThrowMissingIfNot(system, !system || !system->empty());
	
	const wchar_t* origin = system ? system->data() : nullptr;
	wchar_t        domain[128]{};
	std::byte      sid[SECURITY_MAX_SID_SIZE];
	::DWORD        sid_len = lengthof(sid), domain_len = lengthof(domain);
	::SID_NAME_USE usage{};

	// Lookup account identifier
	if (auto res = ::LookupAccountNameW(
		  origin, name.data(), sid, &sid_len, domain, &domain_len, &usage);
		res == 0) {
		// [NOT-FOUND]
		if (this->m_platform_api->get_last_error().value() == ERROR_NONE_MAPPED) {
			return std::nullopt;
		}

		// [FAILURE] Throw appropriate exception
		platform::throw_exception_from_error(HERE, this->m_platform_api->get_last_error());
	}
	
	// [FOUND] Return all components
	return Account{
		{&sid[0], &sid[sid_len]}, 
		{name.begin(), name.end()}, 
		{&domain[0], &domain[domain_len]}
	};
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::vector<std::byte>
SecurityApi::make_descriptor() const
{
	std::vector<std::byte> bytes(sizeof(::SECURITY_DESCRIPTOR), std::byte{});

	// Initialize the buffer with an empty security descriptor
	if (!::InitializeSecurityDescriptor(DescriptorWrapper(bytes), SECURITY_DESCRIPTOR_REVISION)) {
		// [FAILURE] Throw appropriate exception
		platform::throw_exception_from_error(HERE, this->m_platform_api->get_last_error());
	}

	return std::move(bytes);
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
void
SecurityApi::set_key_security(registry::RegistryHandle   key,
							  std::span<std::byte const> bytes,
							  Information                components) const
{
	ThrowIfEmpty(key);
	ThrowIfEmpty(bytes);
	ThrowIfUndefined(components);

	// Strip const from descriptor for compatibility with system call
	DescriptorWrapper descriptor = ConstDescriptorWrapper(bytes).as_mutable();
	::SID *           owner = descriptor.Owner, *group = descriptor.Group;
	::ACL *           dacl = descriptor.Dacl, *sacl = descriptor.Sacl;

	// Set security descriptor
	if (::DWORD res = this->m_raw_api->set_security_info(
		  *key, SE_REGISTRY_KEY, to_underlying(components), owner, group, dacl, sacl);
		res != ERROR_SUCCESS) {
		platform::throw_exception_from_error(HERE, make_error_code(res));
	}
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
void
SecurityApi::set_path_security(filesystem::FilePath       path,
							   std::span<std::byte const> bytes,
							   Information                components) const
{
	ThrowIfEmpty(path);
	ThrowIfEmpty(bytes);
	ThrowIfUndefined(components);

	// Strip const from descriptor for compatibility with system call
	DescriptorWrapper descriptor = ConstDescriptorWrapper(bytes).as_mutable();
	::SID *           owner = descriptor.Owner, *group = descriptor.Group;
	::ACL *           dacl = descriptor.Dacl, *sacl = descriptor.Sacl;

	// Set security descriptor
	if (::DWORD res = this->m_raw_api->set_named_security_info(
		  path.wstring().data(), SE_FILE_OBJECT, to_underlying(components), owner, group, dacl, sacl);
		res != ERROR_SUCCESS) {
		platform::throw_exception_from_error(HERE, make_error_code(res));
	}
}
#endif
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::wstring
SecurityApi::sidToString(std::span<std::byte const> bytes) const
{
	ThrowIfEmpty(bytes);

	// Generate string representation
	wchar_t* const str = convertSidToStringSid(ConstSidWrapper{bytes}.as_mutable()); 
	final_act(&) { ::LocalFree(str); };

	return {str};
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
std::vector<std::byte>
SecurityApi::stringToSid(std::wstring_view str) const
{
	ThrowIfEmpty(str);

	// Generate binary representation
	::PSID sid = convertStringSidToSidW(str.data());
	final_act(&) { ::LocalFree(sid); };

	auto const bytes = SidWrapper{static_cast<::SID*>(sid)}.bytes();
	return {bytes.begin(), bytes.end()};
}
#if 0
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
std::vector<std::byte>
SecurityApi::_get_descriptor(HandleOrPath ident, ::SE_OBJECT_TYPE type, Information components) const
{
	::SID *                owner = {}, *group = {};
	::ACL *                dacl = {}, *sacl = {};
	::SECURITY_DESCRIPTOR* descriptor = {};
	::DWORD                res = {};

	// [PATH] Retrieve security descriptor
	if (std::holds_alternative<filesystem::FilePath>(ident)) {
		res = this->m_raw_api->get_named_security_info(std::get<filesystem::FilePath>(ident).wstring().data(),
													   type,
													   to_underlying(components),
													   &owner,
													   &group,
													   &dacl,
													   &sacl,
													   &descriptor);
	}
	// [HANDLE] Retrieve security descriptor
	else {
		::HANDLE handle = std::holds_alternative<filesystem::FileHandle>(ident)
							? *std::get<filesystem::FileHandle>(ident)
							: *std::get<registry::RegistryHandle>(ident);

		res = this->m_raw_api->get_security_info(
		  handle, type, to_underlying(components), &owner, &group, &dacl, &sacl, &descriptor);
	}
	
	// [FAILURE] Throw appropriate exception
	if (res != ERROR_SUCCESS) {
		platform::throw_exception_from_error(HERE, make_error_code(res));
	}
	// Free descriptor buffer after returning
	ON_EXIT(::LocalFree(descriptor));

	// Calculate size of resulant descriptor and return as bytes
	auto bytes = DescriptorWrapper(descriptor).bytes();
	return {bytes.begin(), bytes.end()};
}
#endif
// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o Non-member Methods & Operators o~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o

// o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-o End of File o~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~-~+~o
