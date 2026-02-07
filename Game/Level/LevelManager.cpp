#include "LevelManager.h"

LevelManager& LevelManager::Get()
{
	static LevelManager instance;
	return instance;
}

void LevelManager::Initialize(Engine* engine)
{
	this->engine = engine;
}

void LevelManager::RegisterLevel(State state, Level* level)
{
	const int idx = static_cast<int>(state);
	if (levels.size() <= idx)
	{
		levels.resize(idx + 1, nullptr);
	}
	levels[idx] = level;
}

void LevelManager::SetState(State state)
{
	current = state;
	const int idx = static_cast<int>(state);
	if (engine && idx < static_cast<int>(levels.size()) && levels[idx])
	{
		engine->SetNewLevel(levels[idx]);
	}
}

void LevelManager::ToggleMenu()
{
	if (current == State::GamePlay)
	{
		SetState(State::Menu);
	}
	else
	{
		SetState(State::GamePlay);
	}
}
