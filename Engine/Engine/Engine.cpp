#include "Engine/Engine.h"
#include "Level/Level.h"
#include "Core/Input.h"
#include "Util/Util.h"
#include "Render/Renderer.h"

#include <iostream>
#include <Windows.h>

namespace Dark
{
	// 정적 변수 초기화.
	Engine* Engine::instance = nullptr;

	Engine::Engine()
	{
		// 정적 변수 값 초기화.
		instance = this;

		// 입력 관리자 생성.
		input = new Input();

		// 설정 파일 로드.
		LoadSetting();

		// 렌더러 객체 생성.
		renderer = new Renderer(Vector2(setting.width, setting.height));

		// 커서 끄기.
		Util::TurnOffCursor();

		// 랜덤 종자값 설정.
		Util::SetRandomSeed();
	}
	Engine::~Engine()
	{
		// 메인 레벨 제거.
		SafeDelete(mainLevel);

		if (input)
		{
			delete input;
			input = nullptr;
		}

		// 렌더러 객체 제거.
		SafeDelete(renderer);
	}

	void Engine::Run()
	{
		// 고정밀 타이머 주파수 얻기(한번만) -> ex) 1초 1천만 tick 정도
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);

		// 프레임 계산용 변수.
		int64_t currentTime = 0;
		int64_t previousTime = 0;

		// 하드웨어 고정밀 타이머로 시간 얻기.
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);

		// 엔진 시작 직전에는 두 시간 값을 같게 맞춤. 
		// -> time.QuadPart로 같게 해야함! 0이면 다음 시간부터 차이 너무 커서 튐!
		currentTime = time.QuadPart;
		previousTime = currentTime;

		// famerate 0 방지 초기화
		setting.framerate = setting.framerate == 0.0f ? 60.0f : setting.framerate;

		float oneFrameTime = 1.0f / setting.framerate;

		// 엔진 루프
		while (!isQuit)
		{
			// 현재 시간 구하기.
			QueryPerformanceCounter(&time);
			currentTime = time.QuadPart;

			// tick 차이 (정수) - 프레임 시간 계산.
			int64_t deltaTicks = currentTime - previousTime;

			// 초 단위 변환. -> float로 썼음 (double 아닌 이유? 속도)
			float deltaTime = 
				static_cast<float>(deltaTicks) / static_cast<float>(frequency.QuadPart);

			// 스파이크 방지 -> 0.1f(100ms, 10fps)
			Util::ClampMax<float>(deltaTime, 0.1f);

			// 고정 프레임 기법.
			if (deltaTime >= oneFrameTime)
			{

				input->ProcessInput();

				// 프레임 처리.
				BeginPlay();
				Tick(deltaTime);
				Draw();
			}
		}

	}
	void Engine::QuitEngine()
	{
	}
	void Engine::SetNewLevel(Level* newLevel)
	{
	}
	Engine& Engine::Get()
	{
		// TODO: insert return statement here
	}
	void Input::ProcessInput()
	{
	}
	void Input::SavePreviousInputStates()
	{
	}
	void Engine::Shutdown()
	{
	}
	void Engine::LoadSetting()
	{
	}
	void Engine::BeginPlay()
	{
	}
	void Engine::Tick(float deltaTime)
	{
	}
	void Engine::Draw()
	{
	}
}