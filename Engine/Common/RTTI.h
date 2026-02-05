#pragma once

#include "Common/Common.h"

namespace Dark
{
	class DARK_API RTTI
	{
	public:
		// 런타임 타입 알려주는 함수
		virtual const size_t& GetType() const = 0;

		// 타입 검사 함수.
		// 객체 타입과 같은지?
		virtual bool Is(RTTI* const rtti) const
		{
			return false;
		}

		// 타입 ID와 같은지.
		virtual bool Is(const size_t id) const
		{
			return false;
		}

		// 타입 질문 함수.
		template<typename T>
		bool IsTypeOf()
		{
			return Is(T::TypeIdClass());
		}

		template<typename T>
		T* As()
		{
			if (Is(T::TypeIdClass()))
			{
				return (T*)this;
			}
			return nullptr;
		}

		template<typename T>
		const T* As() const
		{
			if (Is(T::TypeIdClass()))
			{
				return (T*)this;
			}
			return nullptr;
		}

	};
}

#define RTTI_DECLARATIONS(Type, ParentType)\
friend class RTTI;\
\
protected:\
	static const size_t TypeIdClass()\
	{\
		static int runTimeTypeId = 0;\
		return reinterpret_cast<size_t>(&runTimeTypeId);\
	}\
public:\
	virtual const size_t&& GetType() const override { return Type::TypeIdClass();}\
\
	using super = ParentType;\
\
	virtual bool Is(const size_t id) const override\
	{\
		if(id == TypeIdClass())\
		{\
			return true;\
		}\
		else\
		{\
			return ParentType::Is(id);\
		}\
}\
virtual bool Is(RTTI* const rtti) const override\
{\
	return Is(rtti->GetType());\
\}