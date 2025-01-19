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
	if (Engine::Get().GetKeyDown(VK_LEFT) || Engine::Get().GetKeyDown(0x41))
	{
		//한번 누를때 2칸씩 이동
		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (refLevel->CanPlayerMove(
				Vector2(position.x - 1, position.y))
				)
			{
				position.x -= 1;
			}
		}

	}

	if (Engine::Get().GetKeyDown(VK_RIGHT) || Engine::Get().GetKeyDown(0x44))
	{
		//박스에 닿으면 초기위치로 이동하는데 2칸씩이동이라 1칸이동했을때 박스 만나면 초기위치로 이동하고 한칸 오른쪽으로 더 이동함
		// if(초기위치로 이동했으면 ){break} <- 이런 느낌으로 해야될거 같은데 모르겠음 @todo
		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (refLevel->CanPlayerMove(
				Vector2(position.x + 1, position.y))
				)
			{
				position.x += 1;
			}
		}
	
	}

	if (Engine::Get().GetKeyDown(VK_UP) || Engine::Get().GetKeyDown(0x57))
	{
		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (refLevel->CanPlayerMove(
				Vector2(position.x, position.y - 1))
				)
			{
				position.y -= 1;
			}
		}
	}

	if (Engine::Get().GetKeyDown(VK_DOWN) || Engine::Get().GetKeyDown(0x53))
	{
		for (int i = 0; i < 2;i++) {
			// 이동 가능한지 확인.
			if (refLevel->CanPlayerMove(
				Vector2(position.x, position.y + 1))
				)
			{
				position.y += 1;
			}
		}
	}

	//랜덤 위치 @Todo: 새로 짜야댐 안할가능성 높음
	//if (Engine::Get().GetKeyDown(VK_SPACE))
	//{
	//	if (refLevel->CanPlayerMove(
	//		Vector2(position.x%5, position.y%5))
	//		)

	//	{
	//		position.x %= 5;
	//		position.y %= 5;
	//	}

	//}
}
