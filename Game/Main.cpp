#include <iostream>
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"
#include "Level/IntroLevel.h"

#include <cstdlib>

int main()
{
	// �޸� ���� Ȯ��.
	CheckMemoryLeak();
	system("mode con: cols=100 lines=40"); //�ܼ�â ���������

	Game game;
	game.LoadLevel(new IntroLevel());
	game.Run();
}