#include "Player.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

//ġƮŰ
#include "Engine/Timer.h"
#include"Level/EndingLevel.h"

//�α� �ð���� 
#include <iostream>
#include <chrono>
#include <thread>
#include<windows.h>




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
	if (Engine::Get().GetKeyDown(VK_LEFT) || Engine::Get().GetKeyDown('A'))
	{
		//�ѹ� ������ 2ĭ�� �̵�
		for (int i = 0; i < 2;i++) {

			if (!refLevel->CanPlayerMove(Vector2(position.x - 1, position.y)))
			{
				return;
			}

			position.x -= 1;

			//// �̵� �������� Ȯ��.
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
			// �̵� �������� Ȯ��.
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
			// �̵� �������� Ȯ��.
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
			// �̵� �������� Ȯ��.
			if (!refLevel->CanPlayerMove(Vector2(position.x, position.y + 1)))
			{
				return;
			}

			position.y += 1;
		}
	}

	//�����̽��� �Է�Ƚ��
	static int spaceBarPressCount = 0;

	Engine::Get().SetCursorPosition(Vector2(40, 21));  // Ư�� ��ġ�� Ŀ�� �̵�
	std::cout << "�����̽��� ��� ���� Ƚ��: 3" << std::flush;  // ���� ��� ����⸦ ���� flush ���


	Engine::Get().SetCursorPosition(Vector2(40, 22));  // Ư�� ��ġ�� Ŀ�� �̵�
	std::cout << "�����̽��� ��� Ƚ��: " << spaceBarPressCount << std::flush;  // ���� ��� ����⸦ ���� flush ���

	//�����̽��� ������ ������ġ �̵����� ��밡��Ƚ�� 3
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
			std::cout << "�� �̻� �����̽��� ����� �Ұ����մϴ�." << std::flush;  // ���� ��� ����⸦ ���� flush ���
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); //0.5�� ���
			system("cls");
			
			}
		//11��° ���� ����̸��� ������ �̽��Ϳ���
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
			//��� ������ �Դٰ��� �غ�����
			Engine::Get().SetCursorPosition(Vector2(40, 21));
			std::cout << "�� �̻� �����̽��� ����� �Ұ����մϴ�." << std::flush;  // ���� ��� ����⸦ ���� flush ���
			std::this_thread::sleep_for(std::chrono::milliseconds(500)); //0.5�� ���
			system("cls");
			
		
		}
	
	}
}
