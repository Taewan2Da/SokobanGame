#include "Player.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"




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

	Engine::Get().SetCursorPosition(Vector2(25, 19));  // 특정 위치로 커서 이동
	std::cout << "스페이스바 사용 가능 횟수: 3" << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용


	Engine::Get().SetCursorPosition(Vector2(25, 20));  // 특정 위치로 커서 이동
	std::cout << "스페이스바 사용 횟수: " << spaceBarPressCount << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용

	//스페이스바 누를시 지정위치 이동가능 사용가능횟수 3
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		if (spaceBarPressCount < 3)
		{
			if (refLevel->CanPlayerMove(
				Vector2(position.x, position.y))
				)

			{
				position.x = 37;
				position.y = 9;
			}
			spaceBarPressCount++;
		}
			
	}
}
