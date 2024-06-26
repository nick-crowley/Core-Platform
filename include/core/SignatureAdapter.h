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
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Name Imports o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o Forward Declarations o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Macro Definitions o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Constants & Enumerations o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Class Declarations o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Function return-type(s) and parameter-types represented as type-lists
	*
	* @tparam	ReturnSequence		Indexed sequence of types returned by function
	* @tparam	ParamSequence		Indexed sequence of types used by function's parameter list 
	*/
	template <nstd::IndexedTuple ReturnSequence, nstd::IndexedTuple ParamSequence>
	struct FunctionSignature {};

	//! @brief	Function signature type represented as pair of type-lists
	template <typename Result, typename... Params>
	using FunctionSignature_t = FunctionSignature<nstd::make_indexed_tuple_t<Result>, nstd::make_indexed_tuple_t<Params...>>;

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Method return-type(s) and parameter-types represented as type-lists
	*
	* @tparam	Class				Class-type containing the method
	* @tparam	ReturnSequence		Indexed sequence of types returned by method
	* @tparam	ParamSequence		Indexed sequence of types used by method's parameter list 
	*/
	template <typename Class, nstd::IndexedTuple ReturnSequence, nstd::IndexedTuple ParamSequence>
	struct MethodSignature {};

	//! @brief	Method signature type represented as pair of type-lists
	template <typename Class, typename Result, typename... Params>
	using MethodSignature_t = MethodSignature<Class, nstd::make_indexed_tuple_t<Result>, nstd::make_indexed_tuple_t<Params...>>;
}
namespace core::meta 
{
	//! @brief	Query whether type is function signature
	template <typename T>
	metafunc is_function_signature : std::false_type {};

	template <nstd::IndexedTuple R, nstd::IndexedTuple P>
	metafunc is_function_signature<core::detail::FunctionSignature<R,P>> : std::true_type {};

	//! @brief	Query whether type is method signature
	template <typename T>
	metafunc is_method_signature : std::false_type {};

	template <typename C, nstd::IndexedTuple R, nstd::IndexedTuple P>
	metafunc is_method_signature<core::detail::MethodSignature<C,R,P>> : std::true_type {};
	
	//! @brief	Ensure type is function signature
	template <typename T>
	concept FunctionSignature = is_function_signature<T>::value;

	//! @brief	Ensure type is method signature
	template <typename T>
	concept MethodSignature = is_method_signature<T>::value;

	//! @brief	Ensure type is function or method signature
	template <typename T>
	concept AnySignature = FunctionSignature<T> || MethodSignature<T>;
}
namespace core::detail
{	
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Convert a method signature into a function signature
	*
	* @tparam	M		Method signature
	* 
	* @returns	core::detail::FunctionSignature		@c M without its class-type
	*/
	template <meta::MethodSignature M>
	metafunc StripMethodSignature;
	
	template <typename Class, nstd::IndexedTuple ReturnSequence, nstd::IndexedTuple ParamSequence>
	metafunc StripMethodSignature<MethodSignature<Class,ReturnSequence,ParamSequence>> {
		using type = FunctionSignature<ReturnSequence,ParamSequence>;
	};

	//! @brief	Function signature converted from a method signature
	template <meta::MethodSignature M>
	using StripMethodSignature_t = typename StripMethodSignature<M>::type;


#pragma region DeduceSignature
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Query function signature of a callable target
	*
	* @tparam	T		Callable target
	* 
	* @returns	core::detail::FunctionSignature<R,P> when @T is function, function-pointer, or function-object
	* @returns	core::detail::MethodSignature<C,R,P> when @T is method
	*/
	template <nstd::CallableTarget T>
	metafunc DeduceSignature; 
	
	template <typename... Params>
	metafunc DeduceSignature<void(Params...)> { 
		using type = FunctionSignature<
			nstd::empty_indexed_tuple_t,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	template <typename R, typename... Params>
	metafunc DeduceSignature<R(Params...)> { 
		using type = FunctionSignature<
			nstd::unary_indexed_tuple_t<R>,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	template <typename R, typename... Params>
	metafunc DeduceSignature<R(*)(Params...)> { 
		using type = typename DeduceSignature<R(Params...)>::type;
	};

	template <typename T, typename... Params>
	metafunc DeduceSignature<void(T::*)(Params...)> { 
		using type = MethodSignature<
			T,
			nstd::empty_indexed_tuple_t,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	template <typename T, typename... Params>
	metafunc DeduceSignature<void(T::*)(Params...) const> { 
		using type = MethodSignature<
			T const,
			nstd::empty_indexed_tuple_t,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};
	
	template <typename R, typename T, typename... Params>
	metafunc DeduceSignature<R(T::*)(Params...)> { 
		using type = MethodSignature<
			T,
			nstd::unary_indexed_tuple_t<R>,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	template <typename R, typename T, typename... Params>
	metafunc DeduceSignature<R(T::*)(Params...) const> { 
		using type = MethodSignature<
			T const,
			nstd::unary_indexed_tuple_t<R>,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	template <nstd::CallableTarget T>
	metafunc DeduceSignature {
		static_assert(nstd::FunctionObject<T>);

		using type = StripMethodSignature_t<
			typename DeduceSignature<decltype(&T::operator())>::type
		>;
	};
	
	//! @brief	Ensure signature of @c T can be deduced
	template <typename T>
	concept DeducibleSignature = requires {
		typename DeduceSignature<T>::type;
	};

	//! @brief	Function signature of a callable target
	template <DeducibleSignature T>
	using DeduceSignature_t = typename DeduceSignature<T>::type;
#pragma endregion
	

#pragma region SignatureAdapter
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Function object adapter which delegates to a callable target with N out-parameters
	*
	* @tparam	CallableTarget		Unadapted callable target
	* @tparam	Signature			Signature of @c CallableTarget
	*/
	template <nstd::CallableTarget CallableTarget, meta::AnySignature Signature = DeduceSignature_t<CallableTarget>>
	struct SignatureAdapter;

	// Specialization: Function without return-parameters
	template <typename CallableTarget, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        FunctionSignature<
	                            nstd::empty_indexed_tuple_t,
	                            nstd::indexed_tuple<ParamTuple,std::index_sequence<ParamIdx...>>
	                       >>
	{
		CallableTarget	Callable;

	public:
		void
		operator()(std::tuple_element_t<ParamIdx,ParamTuple>... args) const {
			this->Callable(args...);
		}
	};

	// Specialization: Function with single return parameter
	template <typename CallableTarget, typename Result, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        FunctionSignature<
	                            nstd::unary_indexed_tuple_t<Result>,
	                            nstd::indexed_tuple<ParamTuple,std::index_sequence<ParamIdx...>>
	                       >>
	{
		CallableTarget	Callable;

	public:
		Result
		operator()(std::tuple_element_t<ParamIdx,ParamTuple>... args) const {
			Result  retval {};
			this->Callable(args..., &retval);
			return std::move(retval);
		}
	};
	
	// Specialization: Function with multiple return parameters
	template <typename CallableTarget, typename ResultTuple, size_t... ResultIdx, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        FunctionSignature<
	                            nstd::indexed_tuple<ResultTuple,std::index_sequence<ResultIdx...>>,
	                            nstd::indexed_tuple<ParamTuple,std::index_sequence<ParamIdx...>>
	                       >>
	{
		CallableTarget	Callable;

	public:
		ResultTuple
		operator()(std::tuple_element_t<ParamIdx,ParamTuple>... args) const {
			ResultTuple  retvals;
			this->Callable(args..., std::addressof(std::get<ResultIdx>(retvals))...);
			return std::move(retvals);
		}
	};

	// Specialization: Method without return-parameters
	template <typename CallableTarget, typename Class, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        MethodSignature<
	                            Class,
	                            nstd::empty_indexed_tuple_t,
	                            nstd::indexed_tuple<ParamTuple,std::index_sequence<ParamIdx...>>
	                       >>
	{
		CallableTarget	Callable;

	public:
		void
		operator()(Class& obj, std::tuple_element_t<ParamIdx,ParamTuple>... args) const {
			this->Callable(obj, args...);
		}
	};

	
	// Specialization: Method with single return parameter
	template <typename CallableTarget, typename Class, typename Result, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        MethodSignature<
	                            Class,
	                            nstd::unary_indexed_tuple_t<Result>,
	                            nstd::indexed_tuple<ParamTuple,std::index_sequence<ParamIdx...>>
	                       >>
	{
		CallableTarget	Callable;

	public:
		Result
		operator()(Class& obj, std::tuple_element_t<ParamIdx,ParamTuple>... args) const {
			Result  retval {};
			this->Callable(obj, args..., &retval);
			return std::move(retval);
		}
	};
	
	// Specialization: Method with multiple return parameters
	template <typename CallableTarget, typename Class, typename ResultTuple, size_t... ResultIdx, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        MethodSignature<
	                            Class,
	                            nstd::indexed_tuple<ResultTuple,std::index_sequence<ResultIdx...>>,
	                            nstd::indexed_tuple<ParamTuple,std::index_sequence<ParamIdx...>>
	                       >>
	{
		CallableTarget	Callable;

	public:
		ResultTuple
		operator()(Class& obj, std::tuple_element_t<ParamIdx,ParamTuple>... args) const {
			ResultTuple  retvals;
			this->Callable(obj, args..., std::addressof(std::get<ResultIdx>(retvals))...);
			return std::move(retvals);
		}
	};
#pragma endregion


#pragma region AdaptedSignature
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Generates the adapted function signature given N parameters are out-parameters
	*
	* @tparam	NumResults		Number of result parameters
	* @tparam	Signature		Function signature to adapt
	*/
	template <unsigned NumResults, meta::FunctionSignature Signature>
	metafunc AdaptedSignature;

	// Specialization: N==0: Replace return-type with void
	template <typename ResultSequence, typename... Params>
	metafunc AdaptedSignature<0,
	                          FunctionSignature<
	                              ResultSequence,
	                              nstd::make_indexed_tuple_t<Params...>
	                         >> 
	{
		using type = FunctionSignature<
			nstd::empty_indexed_tuple_t,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	// Specialization: N==1: Replace return-type with last parameter
	template <typename ResultSequence, typename FinalParam, typename... Params>
	metafunc AdaptedSignature<1,
	                          FunctionSignature<
	                              ResultSequence,
	                              nstd::make_indexed_tuple_t<Params..., FinalParam>
	                         >> 
	{
		using type = FunctionSignature<
			nstd::unary_indexed_tuple_t<std::remove_pointer_t<FinalParam>>,
			nstd::make_indexed_tuple_t<Params...>
		>;
	};

	// Specialization: N>1: Replace return-type tuple of final N parameters
	template <unsigned NumResults, typename ResultSequence, typename... Params>
	metafunc AdaptedSignature<NumResults,
	                          FunctionSignature<
	                              ResultSequence,
	                              nstd::make_indexed_tuple_t<Params...>
	                         >> 
	{
		static_assert(NumResults <= sizeof...(Params));

		unsigned constexpr static NumArguments = sizeof...(Params)-NumResults;

		using unadapted_params_t = std::tuple<Params...>;
		using params_tuple_t = nstd::tuple_first_n_t<NumArguments,unadapted_params_t>;
		using result_tuple_t = nstd::tuple_transform_t<
			nstd::tuple_last_n_t<NumResults,unadapted_params_t>, std::remove_pointer_t
		>;
		
		using type = FunctionSignature<
			nstd::indexed_tuple<result_tuple_t, std::make_index_sequence<NumResults>>,
			nstd::indexed_tuple<params_tuple_t, std::make_index_sequence<NumArguments>>
		>;
	};

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Query the adapted function signature from an existing signature
	*
	* @tparam	NumResults		Number of result parameters
	* @tparam	Signature		Function signature to adapt
	*/
	template <unsigned NumResults, meta::FunctionSignature Signature>
	using AdaptedSignature_t = typename AdaptedSignature<NumResults,Signature>::type;
#pragma endregion

}  // namespace detail

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-o Non-member Methods o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o

// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~o Global Functions o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail 
{
	//! @brief	Wrapper for @c std::is_default_constructible
	metafunc is_default_constructible {
		template <typename T>
		metafunc apply : std::is_default_constructible<T>
		{};
	};


	//! @brief	Retrieve function signature return type sequence
	template <meta::FunctionSignature Signature>
	metafunc SignatureReturnTypes : std::type_identity<meta::undefined_t> {};
	
	template <typename... ReturnTypes, typename Idx, typename ParamTuple>
	struct SignatureReturnTypes< 
		FunctionSignature<nstd::indexed_tuple<std::tuple<ReturnTypes...>, Idx>, ParamTuple>
	> : std::type_identity<mpl::vector<ReturnTypes...>> {};

	template <meta::FunctionSignature Signature>
	using SignatureReturnTypes_t = typename SignatureReturnTypes<Signature>::type;


	//! @brief	Query whether every element of an adapted function signature is <e>default constructible</e>
	template <meta::FunctionSignature Signature>
	bool constexpr
	ValidResultsTuple_v = mpl::count_if_v<SignatureReturnTypes_t<Signature>, is_default_constructible> == mpl::size_v<SignatureReturnTypes_t<Signature>>;
	

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Construct signature adapter for callable target
	*
	* @tparam	NumResults		Number of result parameters
	* @tparam	CallableTarget	Any callable target type
	* 
	* @param	fx	Callable target
	*/
	template <unsigned NumResults, nstd::CallableTarget CallableTarget>
		requires ValidResultsTuple_v<AdaptedSignature_t<NumResults,DeduceSignature_t<CallableTarget>>>
	SignatureAdapter<CallableTarget, AdaptedSignature_t<NumResults,DeduceSignature_t<CallableTarget>>> constexpr 
	adaptSignature(CallableTarget fx) noexcept 
	{
		return {fx};
	}
}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-~o Test Code o~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o
namespace core::detail::testing {

#pragma region core::detail::DeduceSignature Unit Tests
	// Functions
	static_assert(std::is_same_v<
		DeduceSignature_t<void ()>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::empty_indexed_tuple_t>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<int ()>,
		FunctionSignature<nstd::unary_indexed_tuple_t<int>, nstd::empty_indexed_tuple_t>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void (int)>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int>>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void (int,long)>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long>>
	>);
	
	// Function pointers
	static_assert(std::is_same_v<
		DeduceSignature_t<void(*)()>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::empty_indexed_tuple_t>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<int(*)()>,
		FunctionSignature<nstd::unary_indexed_tuple_t<int>, nstd::empty_indexed_tuple_t>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(*)(int)>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int>>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(*)(int,long)>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long>>
	>);
	
	// Method pointers
	struct TestClass;
	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)()>,
		MethodSignature<TestClass, nstd::empty_indexed_tuple_t, nstd::empty_indexed_tuple_t>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<int(TestClass::*)()>,
		MethodSignature<TestClass, nstd::unary_indexed_tuple_t<int>, nstd::empty_indexed_tuple_t>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)(int)>,
		MethodSignature<TestClass, nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int>>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)(int,long)>,
		MethodSignature<TestClass, nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long>>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)(int) const>,
		MethodSignature<TestClass const, nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int>>
	>);
	
	// Function Object
	struct VoidTestFunctor {
		void operator()();
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<VoidTestFunctor>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::empty_indexed_tuple_t>
	>);

	struct NullaryTestFunctor {
		int operator()() const;
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<NullaryTestFunctor>,
		FunctionSignature<nstd::unary_indexed_tuple_t<int>, nstd::empty_indexed_tuple_t>
	>);
	
	struct UnaryTestFunctor {
		int operator()(int) const;
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<UnaryTestFunctor>,
		FunctionSignature<nstd::unary_indexed_tuple_t<int>, nstd::unary_indexed_tuple_t<int>>
	>);
	
	struct BinaryTestFunctor {
		void operator()(int,long) const;
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<BinaryTestFunctor>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long>>
	>);
#pragma endregion

#pragma region core::detail::ValidResultsTuple Unit Tests
	
	//! @test  Verify @c ValidResultsTuple_v detects @c unsigned is default constructible
	static_assert(mpl::count_if_v<mpl::vector<void>, is_default_constructible> == 0);
	static_assert(mpl::count_if_v<mpl::vector<int>, is_default_constructible> == 1);
	static_assert(mpl::count_if_v<mpl::vector<void, int>, is_default_constructible> == 1);
	static_assert(mpl::count_if_v<mpl::vector<int, int>, is_default_constructible> == 2);
	static_assert(mpl::count_if_v<mpl::vector<void, void>, is_default_constructible> == 0);

	//! @test  Verify @c ValidResultsTuple_v detects @c unsigned is default constructible
	static_assert(ValidResultsTuple_v<
		FunctionSignature<nstd::unary_indexed_tuple_t<unsigned>, nstd::empty_indexed_tuple_t>
	>);

	//! @test  Verify @c ValidResultsTuple_v detects @c void is @e not default constructible
	static_assert(!ValidResultsTuple_v<
		FunctionSignature<nstd::unary_indexed_tuple_t<void>, nstd::empty_indexed_tuple_t>
	>);
	
	//! @test  Verify @c ValidResultsTuple_v detects @c void* is default constructible
	static_assert(ValidResultsTuple_v<
		FunctionSignature<nstd::unary_indexed_tuple_t<void*>, nstd::empty_indexed_tuple_t>
	>);

	//! @test  Verify @c ValidResultsTuple_v detects a single type which is not default constructible amongst many that are
	static_assert(!ValidResultsTuple_v<
		FunctionSignature<nstd::make_indexed_tuple_t<int, void, bool>, nstd::empty_indexed_tuple_t>
	>);

	//! @test  Verify @c ValidResultsTuple_v detects a single type which is not default constructible amongst many that are
	static_assert(!ValidResultsTuple_v<
		FunctionSignature<nstd::make_indexed_tuple_t<void, int, bool>, nstd::empty_indexed_tuple_t>
	>);

	//! @test  Verify @c ValidResultsTuple_v detects a single type which is not default constructible amongst many that are
	static_assert(!ValidResultsTuple_v<
		FunctionSignature<nstd::make_indexed_tuple_t<int, bool, void>, nstd::empty_indexed_tuple_t>
	>);

	//! @test  Verify @c ValidResultsTuple_v detects when all types are default constructible
	static_assert(ValidResultsTuple_v<
		FunctionSignature<nstd::make_indexed_tuple_t<int, bool>, nstd::empty_indexed_tuple_t>
	>);
	
	//! @test  Verify @c ValidResultsTuple_v detects when no types are default constructible
	static_assert(!ValidResultsTuple_v<
		FunctionSignature<nstd::make_indexed_tuple_t<void, void>, nstd::empty_indexed_tuple_t>
	>);
#pragma endregion

#pragma region core::detail::AdaptedSignature Unit Tests
	// Test: Pre-existing return type, if present, is replaced with void
	static_assert(std::is_same_v<
		AdaptedSignature_t<0, FunctionSignature<nstd::unary_indexed_tuple_t<unsigned>, nstd::make_indexed_tuple_t<int>>>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int>>
	>);

	// Test: When N == 0 and return-type is void, signature is unchanged
	static_assert(std::is_same_v<
		AdaptedSignature_t<0, FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long>>>,
		FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long>>
	>);
	
	// Test: When N == 1, the last parameter is removed, transformed, and becomes the return type
	static_assert(std::is_same_v<
		AdaptedSignature_t<1, FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long*>>>,
		FunctionSignature<nstd::unary_indexed_tuple_t<long>, nstd::make_indexed_tuple_t<int>>
	>);
	
	// Test: When N == 1, transforming the last parameter replaces any pre-existing return type
	static_assert(std::is_same_v<
		AdaptedSignature_t<1, FunctionSignature<nstd::unary_indexed_tuple_t<bool>, nstd::make_indexed_tuple_t<int,long*>>>,
		FunctionSignature<nstd::unary_indexed_tuple_t<long>, nstd::make_indexed_tuple_t<int>>
	>);
	
	// Test: When N > 1, the final N parameters are removed, transformed, and become a return type tuple
	static_assert(std::is_same_v<
		AdaptedSignature_t<2, FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<int,long*,long*>>>,
		FunctionSignature<nstd::make_indexed_tuple_t<long,long>, nstd::make_indexed_tuple_t<int>>
	>);
	
	// Test: As above
	static_assert(std::is_same_v<
		AdaptedSignature_t<3, FunctionSignature<nstd::empty_indexed_tuple_t, nstd::make_indexed_tuple_t<float,long*,float*,char**>>>,
		FunctionSignature<nstd::make_indexed_tuple_t<long,float,char*>, nstd::make_indexed_tuple_t<float>>
	>);
	
	// Test: When N > 1, transforming the final parameters replaces any pre-existing return type
	static_assert(std::is_same_v<
		AdaptedSignature_t<2, FunctionSignature<nstd::unary_indexed_tuple_t<float>, nstd::make_indexed_tuple_t<int,long*,long*>>>,
		FunctionSignature<nstd::make_indexed_tuple_t<long,long>, nstd::make_indexed_tuple_t<int>>
	>);
	
#pragma endregion

}
// o~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=-o End of File o-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~-~=~o