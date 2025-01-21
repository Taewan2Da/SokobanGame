#include <iostream>
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"
#include "Level/IntroLevel.h"

#include <cstdlib>

int main()
{
	// 메모리 누수 확인.
	CheckMemoryLeak();
	system("mode con: cols=100 lines=40"); //콘솔창 사이즈고정

	Game game;
	game.LoadLevel(new IntroLevel());
	game.Run();
}