#pragma once

#include <vector>
#include "Engine/Engine.h"
#include "Level/Level.h"

using namespace Dark;

enum class State
{ 
	Menu = 0,
	GamePlay = 1,
};

class LevelManager
{
public:
	static LevelManager& Get();

	void Initialize(Engine* engine);
	void RegisterLevel(State state, Level* level);
	void SetState(State state);
	void ToggleMenu();

private:
	Engine* engine = nullptr;
	std::vector<Level*> levels;
	State current = State::GamePlay;
};
