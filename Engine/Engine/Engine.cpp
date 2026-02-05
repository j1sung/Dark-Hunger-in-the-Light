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
	}
	Engine::~Engine()
	{
	}
	void Engine::Run()
	{
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