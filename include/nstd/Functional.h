#pragma once
#include "library/core.Platform.h"

namespace nstd
{
	template <typename Signature>
	class function 
	{
		static_assert(std::is_function_v<Signature>, "'Signature' must be of function type");
	};

	template <typename Result, typename... Parameters>
	class function<Result(Parameters...)>
	{
	private:
		using type = function<Result(Parameters...)>;
		using result_t = Result;
	
		struct ICallable
		{
			satisfies(ICallable,
				virtual IsDestructible
			);
		
			result_t
			virtual operator()(Parameters...) const abstract;
		};

		enum class CallType { Object, Function, Method };

		struct Callable : public ICallable
		{
			CallType  m_type;

			Callable(CallType t) : m_type{t}
			{}

			bool
			virtual operator==(Callable const&) const abstract;
		};

		template <typename CallableTarget>
		class FunctionObject : public Callable
		{
			using base = Callable;

		private:
			CallableTarget  m_object;

		public:
			FunctionObject(CallableTarget&& fx) 
			  : Callable{CallType::Object}, 
				m_object{std::move(fx)}
			{}
		
		public:
			result_t
			operator()(Parameters... args) const override
			{
				return this->m_object(std::forward<Parameters>(args)...);
			}

			bool
			operator==(Callable const& r) const override
			{
				if (this->m_type != r.m_type)
					return false;

				throw std::runtime_error("Function objects are incomparable");
			}
		};

		class FunctionPointer : public Callable
		{
			using base = Callable;
			using signature_t = Result(*)(Parameters...);

		private:
			signature_t  m_address;

		public:
			FunctionPointer(signature_t pfx) 
			  : Callable{CallType::Function}, 
				m_address{pfx}
			{}

		public:
			result_t
			operator()(Parameters... args) const override
			{
				return (*this->m_address)(std::forward<Parameters>(args)...);
			}

			bool
			operator==(Callable const& r) const override
			{
				return this->m_type == r.m_type
					&& this->m_address == static_cast<FunctionPointer const&>(r).m_address;
			}
		};

		template <typename Object>
		class MethodPointer : public Callable
		{
			using signature_t = Result (Object::*)(Parameters...);
			using const_signature_t = Result (Object::*)(Parameters...) const;
			using MaybeConstSignature = std::variant<signature_t, const_signature_t>;

			Object*             m_object;
			MaybeConstSignature m_method;

		public:
			MethodPointer(Object& obj, signature_t method) 
			  : Callable{CallType::Method}, m_object{&obj}, m_method{method}
			{}
		
			MethodPointer(Object& obj, const_signature_t method) 
			  : Callable{CallType::Method}, m_object{&obj}, m_method{method}
			{}
		
		private:
			result_t
			operator()(Parameters... args) const override
			{
				if (std::holds_alternative<signature_t>(this->m_method))
					return (this->m_object->*std::get<signature_t>(this->m_method))(std::forward<Parameters>(args)...);
				else
					return (this->m_object->*std::get<const_signature_t>(this->m_method))(std::forward<Parameters>(args)...);
			}

			bool
			operator==(Callable const& r) const override
			{
				return this->m_type == r.m_type
					&& this->m_object == static_cast<MethodPointer const&>(r).m_object
					&& this->m_method == static_cast<MethodPointer const&>(r).m_method;
			}
		};

	public:
		using result_type = result_t;

	private:
		std::shared_ptr<Callable>  m_callable;

	public:
		satisfies(function,
			IsSemiRegular
		);
		
		//! Construct from function pointer
		implicit
		function(result_t (*fx)(Parameters...))
		  : m_callable{std::make_shared<FunctionPointer>(fx)}
		{}

		//! Construct from non-const method
		template <typename Object> 
			requires std::is_class_v<Object>
		implicit
		function(Object& obj, result_t (Object::*method)(Parameters...))
		  : m_callable{std::make_shared<MethodPointer<Object>>(obj,method)}
		{}

		//! Construct from const method
		template <typename Object> 
			requires std::is_class_v<Object>
		implicit
		function(Object& obj, result_t (Object::*method)(Parameters...) const)
		  : m_callable{std::make_shared<MethodPointer<Object>>(obj,method)}
		{}
	
		//! Construct from function-object
		template <typename CallableTarget> 
			requires (std::is_class_v<CallableTarget> && std::is_invocable_v<CallableTarget,Parameters...>)
		explicit 
		function(CallableTarget&& t)
		  : m_callable{std::make_shared<FunctionObject>(std::move(t))}
		{}
	
		//! Prevent accidental construction from const-object to a non-const method
		template <typename Object> 
			requires std::is_class_v<Object>
		function(Object const&, result_t (Object::*)(Parameters...)) = delete;
	
		//! Prevent copy/move from delegates of different signatures
		template <typename Other> 
		function(function<Other> const&) = delete;

		//! Prevent copy/move from delegates of different signatures
		template <typename Other> 
		type& 
		operator=(function<Other> const&) = delete;
	
	public:
		result_type
		invoke(Parameters... args) const 
		{
			Expects(this->m_callable != nullptr);	//FIXME: Replace with core invariant validation macro
			return (*this->m_callable)(std::forward<Parameters>(args)...);
		}

		result_type 
		operator()(Parameters... args) const 
		{
			return this->invoke(std::forward<Parameters>(args)...);
		}

		bool
		operator==(type const& r) const
		{
			if (!this->m_callable || !r.m_callable)
				return !this->m_callable && !r.m_callable;

			return *this->m_callable == *r.m_callable;
		}
	
		bool
		operator!=(type const& r) const
		{
			return !(*this == r);
		}
	
		template <typename Other> bool operator==(function<Other> const&) const = delete;
		template <typename Other> bool operator!=(function<Other> const&) const = delete;
	};
}	// namespace nstd