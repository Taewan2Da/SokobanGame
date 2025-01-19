#include "Player.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

Player::Player(const Vector2& position, GameLevel* level)
	: DrawableActor("��"), refLevel(level) // �÷��̾�
{
	// ��ġ ����.
	this->position = position;

	// ���� ����.
	color = Color::Yellow;

}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ESC ����.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		//Engine::Get().QuitGame();
		// �޴� ���.
		Game::Get().ToggleMenu();
	}

	// �����¿�.
	if (Engine::Get().GetKeyDown(VK_LEFT) || Engine::Get().GetKeyDown(0x41))
	{
		//�ѹ� ������ 2ĭ�� �̵�
		for (int i = 0; i < 2;i++) {
			// �̵� �������� Ȯ��.
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
		for (int i = 0; i < 2;i++) {
			// �̵� �������� Ȯ��.
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
			// �̵� �������� Ȯ��.
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
			// �̵� �������� Ȯ��.
			if (refLevel->CanPlayerMove(
				Vector2(position.x, position.y + 1))
				)
			{
				position.y += 1;
			}
		}
	}

	//���� ��ġ @Todo: ���� ¥�ߴ� ���Ұ��ɼ� ����
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