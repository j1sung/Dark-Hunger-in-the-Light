#pragma once

#include "Math/Vector2.h"
#include "Math/Color.h"

#include <time.h>

using namespace Dark;

// 헬퍼(Helper)기능 제공.
namespace Util
{
	// Clamp: 어떤 값을 두 수 사이로 고정할 때 사용하는 함수.
	template<typename T>
	T Clamp(T value, T min, T max)
	{
		if (value < min)
		{
			value = min;
		}
		else if(value > max)
		{
			value = max;
		}
		return value;
	}

	template<typename T>
	T ClampMax(T value, T max)
	{
		return value > max ? max : value;
	}
}

// 메모리 정리 함수.
template<typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

template<typename T>
void SafeDeleteArray(T*& t)
{
	if (t)
	{
		delete[] t;
		t = nullptr;
	}
}