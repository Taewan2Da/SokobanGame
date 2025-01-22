#include "Player.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

//치트키
#include "Engine/Timer.h"
#include"Level/EndingLevel.h"

//로그 시간대기 
#include <iostream>
#include <chrono>
#include <thread>
#include<windows.h>




Player::Player(const Vector2& position, GameLevel* level)
	: DrawableActor("★"), refLevel(level) // 플레이어
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Yellow;

}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ESC 종료.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		//Engine::Get().QuitGame();
		// 메뉴 토글.
		Game::Get().ToggleMenu();
	}

	// 상하좌우.
	if (Engine::Get().GetKeyDown(VK_LEFT) || Engine::Get().GetKeyDown('A'))
	{
		//한번 누를때 2칸씩 이동
		for (int i = 0; i < 2;i++) {

			if (!refLevel->CanPlayerMove(Vector2(position.x - 1, position.y)))
			{
				return;
			}

			position.x -= 1;

			//// 이동 가능한지 확인.
			//if (refLevel->CanPlayerMove(
			// 
			//	Vector2(position.x - 1, position.y))
			//	)
			//{
			//	position.x -= 1;
			//}
			//else
			//{
			//	return;
			//}
		}

	}

	if (Engine::Get().GetKeyDown(VK_RIGHT) || Engine::Get().GetKeyDown('D'))
	{

		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (!refLevel->CanPlayerMove(Vector2(position.x + 1, position.y)))    
			{
				return;
			}

			position.x += 1;
		}

	}

	if (Engine::Get().GetKeyDown(VK_UP) || Engine::Get().GetKeyDown('W'))
	{
		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (!refLevel->CanPlayerMove(Vector2(position.x, position.y - 1)))
			{
				return;
			}

			position.y -= 1;
		}
	}

	if (Engine::Get().GetKeyDown(VK_DOWN) || Engine::Get().GetKeyDown('S'))
	{
		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (!refLevel->CanPlayerMove(Vector2(position.x, position.y + 1)))
			{
				return;
			}

			position.y += 1;
		}
	}

	//스페이스바 입력횟수
	static int spaceBarPressCount = 0;

	Engine::Get().SetCursorPosition(Vector2(40, 21));  // 특정 위치로 커서 이동
	std::cout << "스페이스바 사용 가능 횟수: 3" << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용


	Engine::Get().SetCursorPosition(Vector2(40, 22));  // 특정 위치로 커서 이동
	std::cout << "스페이스바 사용 횟수: " << spaceBarPressCount << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용

	//스페이스바 누를시 지정위치 이동가능 사용가능횟수 3
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		spaceBarPressCount++;
		if (spaceBarPressCount < 4)
		{
			if (refLevel->CanPlayerMove(
				Vector2(position.x, position.y))
				)

			{
				position.x = 52;
				position.y = 11;
			}
		
		}
		
			else if (spaceBarPressCount < 11)
			{
			system("cls");
			Engine::Get().SetCursorPosition(Vector2(52, 8));
			std::cout << "  /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(52, 9));
			std::cout << " ( o.o ) " << std::flush;
			Engine::Get().SetCursorPosition(Vector2(52, 10));
			std::cout << "  > ^ <" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(40, 12));
			std::cout << "더 이상 스페이스바 사용이 불가능합니다." << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); //0.5초 대기
			system("cls");
			
			}
		//11번째 부터 고양이많이 나오는 이스터에그
		else
		{

			system("cls");
			Engine::Get().SetCursorPosition(Vector2(22, 8));
			std::cout << "  /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(22, 9));
			std::cout << " ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(22, 10));
			std::cout << "  > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <" << std::flush;

			Engine::Get().SetCursorPosition(Vector2(22, 12));
			std::cout << "  /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(22, 13));
			std::cout << " ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(22, 14));
			std::cout << "  > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <" << std::flush;

			Engine::Get().SetCursorPosition(Vector2(22, 17));
			std::cout << "  /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\    /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(22, 18));
			std::cout << " ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )  ( o.o )" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(22, 19));
			std::cout << "  > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <    > ^ <" << std::flush;
			//계속 누르면 왔다갔다 해보려고
			Engine::Get().SetCursorPosition(Vector2(40, 21));
			std::cout << "더 이상 스페이스바 사용이 불가능합니다." << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); //0.5초 대기
			system("cls");
			
		
		}
	
	}
}
