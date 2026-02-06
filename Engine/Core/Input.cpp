#include "Input.h"

#include <Windows.h>
#include <iostream>
#include <cassert>

namespace Dark
{
	// 전역 변수 초기화.
	Input* Input::instance = nullptr;

	Input::Input()
	{
		// 객체가 초기화되면 자기 자신의 주소를 저장.
		instance = this;
	}
	Input::~Input()
	{
	}
	bool Input::GetKeyDown(int keyCode)
	{
		return keyStates[keyCode].isKeyDown && !keyStates[keyCode].wasKeyDown;
	}
	bool Input::GetKeyUp(int keyCode)
	{
		return !keyStates[keyCode].isKeyDown && keyStates[keyCode].wasKeyDown;
	}
	bool Input::GetKey(int keyCode)
	{
		return keyStates[keyCode].isKeyDown;
	}
	bool Input::GetMouseButtonDown(int buttonCode)
	{
		// buttonCode가 0이거나 1인지 확인.
		// 이 검사를 통과 못하면 debugbreak가 동작함. -> #include <cassert> 필요
		assert(buttonCode == 0 || buttonCode == 1);

		int keyCode = 0;
		if (buttonCode == 0)
		{
			keyCode = VK_LBUTTON;
		}
		else if (buttonCode == 1)
		{
			keyCode = VK_RBUTTON;
		}

		return keyStates[keyCode].isKeyDown && !keyStates[keyCode].wasKeyDown;
	}
	bool Input::GetMouseButtonUp(int buttonCode)
	{
		// buttonCode가 0이거나 1인지 확인.
		// 이 검사를 통과 못하면 debugbreak가 동작함.
		assert(buttonCode == 0 || buttonCode == 1);

		int keyCode = 0;
		if (buttonCode == 0)
		{
			keyCode = VK_LBUTTON;
		}
		else if (buttonCode == 1)
		{
			keyCode = VK_RBUTTON;
		}

		return !keyStates[keyCode].isKeyDown && keyStates[keyCode].wasKeyDown;
	}
	bool Input::GetMouseButton(int buttonCode)
	{
		// buttonCode가 0이거나 1인지 확인.
		// 이 검사를 통과 못하면 debugbreak가 동작함.
		assert(buttonCode == 0 || buttonCode == 1);

		int keyCode = 0;
		if (buttonCode == 0)
		{
			keyCode = VK_LBUTTON;
		}
		else if (buttonCode == 1)
		{
			keyCode = VK_RBUTTON;
		}

		return keyStates[keyCode].isKeyDown;
	}

	Input& Input::Get()
	{
		
	}
}