#include "Engine/Engine.h"

#include <iostream>

using namespace Dark;

int main()
{
	Engine engine;
	engine.SetNewLevel(new GameLevel());
	engine.Run();

	return 0;
}