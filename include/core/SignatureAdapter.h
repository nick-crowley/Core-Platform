#pragma once
#include "library/core.Platform.h"

namespace core::detail
{
	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Function return-type(s) and parameter-types represented as type-lists
	*
	* @tparam	ReturnSequence		Indexed sequence of types returned by function
	* @tparam	ParamSequence		Indexed sequence of types used by function's parameter list 
	*/
	template <nstd::AnyIndexedTuple ReturnSequence, nstd::AnyIndexedTuple ParamSequence>
	struct FunctionSignature {};

	//! @brief	Function signature type represented as pair of type-lists
	template <typename Result, typename... Params>
	using FunctionSignature_t = FunctionSignature<nstd::MakeIndexedTuple<Result>, nstd::MakeIndexedTuple<Params...>>;

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Method return-type(s) and parameter-types represented as type-lists
	*
	* @tparam	Class				Class-type containing the method
	* @tparam	ReturnSequence		Indexed sequence of types returned by method
	* @tparam	ParamSequence		Indexed sequence of types used by method's parameter list 
	*/
	template <typename Class, nstd::AnyIndexedTuple ReturnSequence, nstd::AnyIndexedTuple ParamSequence>
	struct MethodSignature {};

	//! @brief	Method signature type represented as pair of type-lists
	template <typename Class, typename Result, typename... Params>
	using MethodSignature_t = MethodSignature<Class, nstd::MakeIndexedTuple<Result>, nstd::MakeIndexedTuple<Params...>>;
}
namespace core::meta 
{
	//! @brief	Query whether type is function signature
	template <typename T>
	metafunc is_function_signature : std::false_type {};

	template <nstd::AnyIndexedTuple R, nstd::AnyIndexedTuple P>
	metafunc is_function_signature<core::detail::FunctionSignature<R,P>> : std::true_type {};

	//! @brief	Query whether type is method signature
	template <typename T>
	metafunc is_method_signature : std::false_type {};

	template <typename C, nstd::AnyIndexedTuple R, nstd::AnyIndexedTuple P>
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
	
	template <typename Class, nstd::AnyIndexedTuple ReturnSequence, nstd::AnyIndexedTuple ParamSequence>
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
	template <meta::CallableTarget T>
	metafunc DeduceSignature; 
	
	template <typename... Params>
	metafunc DeduceSignature<void(Params...)> { 
		using type = FunctionSignature<
			nstd::EmptyIndexedTuple,
			nstd::MakeIndexedTuple<Params...>
		>;
	};

	template <typename R, typename... Params>
	metafunc DeduceSignature<R(Params...)> { 
		using type = FunctionSignature<
			nstd::UnaryIndexedTuple<R>,
			nstd::MakeIndexedTuple<Params...>
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
			nstd::EmptyIndexedTuple,
			nstd::MakeIndexedTuple<Params...>
		>;
	};

	template <typename T, typename... Params>
	metafunc DeduceSignature<void(T::*)(Params...) const> { 
		using type = MethodSignature<
			T const,
			nstd::EmptyIndexedTuple,
			nstd::MakeIndexedTuple<Params...>
		>;
	};
	
	template <typename R, typename T, typename... Params>
	metafunc DeduceSignature<R(T::*)(Params...)> { 
		using type = MethodSignature<
			T,
			nstd::UnaryIndexedTuple<R>,
			nstd::MakeIndexedTuple<Params...>
		>;
	};

	template <typename R, typename T, typename... Params>
	metafunc DeduceSignature<R(T::*)(Params...) const> { 
		using type = MethodSignature<
			T const,
			nstd::UnaryIndexedTuple<R>,
			nstd::MakeIndexedTuple<Params...>
		>;
	};

	template <meta::CallableTarget T>
	metafunc DeduceSignature {
		static_assert(meta::FunctionObject<T>);

		using type = StripMethodSignature_t<
			typename DeduceSignature<decltype(&T::operator())
		>::type>;
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
	template <meta::CallableTarget CallableTarget, meta::AnySignature Signature = DeduceSignature_t<CallableTarget>>
	struct SignatureAdapter;

	// Specialization: Function without return-parameters
	template <typename CallableTarget, typename ParamTuple, size_t... ParamIdx>
	struct SignatureAdapter<CallableTarget, 
	                        FunctionSignature<
	                            nstd::EmptyIndexedTuple,
	                            nstd::IndexedTuple<ParamTuple,std::index_sequence<ParamIdx...>>
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
	                            nstd::UnaryIndexedTuple<Result>,
	                            nstd::IndexedTuple<ParamTuple,std::index_sequence<ParamIdx...>>
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
	                            nstd::IndexedTuple<ResultTuple,std::index_sequence<ResultIdx...>>,
	                            nstd::IndexedTuple<ParamTuple,std::index_sequence<ParamIdx...>>
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
	                            nstd::EmptyIndexedTuple,
	                            nstd::IndexedTuple<ParamTuple,std::index_sequence<ParamIdx...>>
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
	                            nstd::UnaryIndexedTuple<Result>,
	                            nstd::IndexedTuple<ParamTuple,std::index_sequence<ParamIdx...>>
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
	                            nstd::IndexedTuple<ResultTuple,std::index_sequence<ResultIdx...>>,
	                            nstd::IndexedTuple<ParamTuple,std::index_sequence<ParamIdx...>>
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
	                              nstd::MakeIndexedTuple<Params...>
	                         >> 
	{
		using type = FunctionSignature<
			nstd::EmptyIndexedTuple,
			nstd::MakeIndexedTuple<Params...>
		>;
	};

	// Specialization: N==1: Replace return-type with last parameter
	template <typename ResultSequence, typename FinalParam, typename... Params>
	metafunc AdaptedSignature<1,
	                          FunctionSignature<
	                              ResultSequence,
	                              nstd::MakeIndexedTuple<Params..., FinalParam>
	                         >> 
	{
		using type = FunctionSignature<
			nstd::UnaryIndexedTuple<std::remove_pointer_t<FinalParam>>,
			nstd::MakeIndexedTuple<Params...>
		>;
	};

	// Specialization: N>1: Replace return-type tuple of final N parameters
	template <unsigned NumResults, typename ResultSequence, typename... Params>
	metafunc AdaptedSignature<NumResults,
	                          FunctionSignature<
	                              ResultSequence,
	                              nstd::MakeIndexedTuple<Params...>
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
			nstd::IndexedTuple<result_tuple_t, std::make_index_sequence<NumResults>>,
			nstd::IndexedTuple<params_tuple_t, std::make_index_sequence<NumArguments>>
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

	/* ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` */ /*!
	* @brief	Construct signature adapter for callable target
	*
	* @tparam	NumResults		Number of result parameters
	* @tparam	CallableTarget	Any callable target type
	* 
	* @param	fx	Callable target
	*/
	template <unsigned NumResults, meta::CallableTarget CallableTarget> 
	SignatureAdapter<CallableTarget, AdaptedSignature_t<NumResults,DeduceSignature_t<CallableTarget>>> constexpr 
	adaptSignature(CallableTarget fx) noexcept 
	{
		return {fx};
	}

}  // namespace detail

namespace core::detail::testing {

#pragma region core::detail::DeduceSignature Unit Tests
	// Functions
	static_assert(std::is_same_v<
		DeduceSignature_t<void ()>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::EmptyIndexedTuple>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<int ()>,
		FunctionSignature<nstd::UnaryIndexedTuple<int>, nstd::EmptyIndexedTuple>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void (int)>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int>>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void (int,long)>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long>>
	>);
	
	// Function pointers
	static_assert(std::is_same_v<
		DeduceSignature_t<void(*)()>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::EmptyIndexedTuple>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<int(*)()>,
		FunctionSignature<nstd::UnaryIndexedTuple<int>, nstd::EmptyIndexedTuple>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(*)(int)>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int>>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(*)(int,long)>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long>>
	>);
	
	// Method pointers
	struct TestClass;
	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)()>,
		MethodSignature<TestClass, nstd::EmptyIndexedTuple, nstd::EmptyIndexedTuple>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<int(TestClass::*)()>,
		MethodSignature<TestClass, nstd::UnaryIndexedTuple<int>, nstd::EmptyIndexedTuple>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)(int)>,
		MethodSignature<TestClass, nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int>>
	>);

	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)(int,long)>,
		MethodSignature<TestClass, nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long>>
	>);
	
	static_assert(std::is_same_v<
		DeduceSignature_t<void(TestClass::*)(int) const>,
		MethodSignature<TestClass const, nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int>>
	>);
	
	// Function Object
	struct VoidTestFunctor {
		void operator()();
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<VoidTestFunctor>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::EmptyIndexedTuple>
	>);

	struct NullaryTestFunctor {
		int operator()() const;
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<NullaryTestFunctor>,
		FunctionSignature<nstd::UnaryIndexedTuple<int>, nstd::EmptyIndexedTuple>
	>);
	
	struct UnaryTestFunctor {
		int operator()(int) const;
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<UnaryTestFunctor>,
		FunctionSignature<nstd::UnaryIndexedTuple<int>, nstd::UnaryIndexedTuple<int>>
	>);
	
	struct BinaryTestFunctor {
		void operator()(int,long) const;
	};
	static_assert(std::is_same_v<
		DeduceSignature_t<BinaryTestFunctor>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long>>
	>);
#pragma endregion
	
#pragma region core::detail::AdaptedSignature Unit Tests
	// Test: Pre-existing return type, if present, is replaced with void
	static_assert(std::is_same_v<
		AdaptedSignature_t<0, FunctionSignature<nstd::UnaryIndexedTuple<unsigned>, nstd::MakeIndexedTuple<int>>>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int>>
	>);

	// Test: When N == 0 and return-type is void, signature is unchanged
	static_assert(std::is_same_v<
		AdaptedSignature_t<0, FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long>>>,
		FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long>>
	>);
	
	// Test: When N == 1, the last parameter is removed, transformed, and becomes the return type
	static_assert(std::is_same_v<
		AdaptedSignature_t<1, FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long*>>>,
		FunctionSignature<nstd::UnaryIndexedTuple<long>, nstd::MakeIndexedTuple<int>>
	>);
	
	// Test: When N == 1, transforming the last parameter replaces any pre-existing return type
	static_assert(std::is_same_v<
		AdaptedSignature_t<1, FunctionSignature<nstd::UnaryIndexedTuple<bool>, nstd::MakeIndexedTuple<int,long*>>>,
		FunctionSignature<nstd::UnaryIndexedTuple<long>, nstd::MakeIndexedTuple<int>>
	>);
	
	// Test: When N > 1, the final N parameters are removed, transformed, and become a return type tuple
	static_assert(std::is_same_v<
		AdaptedSignature_t<2, FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<int,long*,long*>>>,
		FunctionSignature<nstd::MakeIndexedTuple<long,long>, nstd::MakeIndexedTuple<int>>
	>);
	
	// Test: As above
	static_assert(std::is_same_v<
		AdaptedSignature_t<3, FunctionSignature<nstd::EmptyIndexedTuple, nstd::MakeIndexedTuple<float,long*,float*,char**>>>,
		FunctionSignature<nstd::MakeIndexedTuple<long,float,char*>, nstd::MakeIndexedTuple<float>>
	>);
	
	// Test: When N > 1, transforming the final parameters replaces any pre-existing return type
	static_assert(std::is_same_v<
		AdaptedSignature_t<2, FunctionSignature<nstd::UnaryIndexedTuple<float>, nstd::MakeIndexedTuple<int,long*,long*>>>,
		FunctionSignature<nstd::MakeIndexedTuple<long,long>, nstd::MakeIndexedTuple<int>>
	>);
	
#pragma endregion
	

}