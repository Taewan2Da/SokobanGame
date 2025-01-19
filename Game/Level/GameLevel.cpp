#include "GameLevel.h"
#include "Engine/Engine.h"

#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"
#include "Actor/Player.h"
#include "Actor/fakeGround.h"
#include"Game/Game.h"
#include"Level/EndingLevel.h"

#include "Engine/Timer.h"


GameLevel::GameLevel()
{
	// Ŀ�� ���߱�.
	Engine::Get().SetCursorType(CursorType::NoCursor);

	// �� ���� �ҷ��� ���� �ε�.
	// ���� �б�.
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/Maps/Test.txt", "rb");

	// ���� ó��.
	if (file == nullptr)
	{
		std::cout << "�� ���� ���� ����.\n";
		__debugbreak();
		return;
	}

	// ���� �б�.
	// ����ġ�� �̵�.
	fseek(file, 0, SEEK_END);

	// �̵��� ��ġ�� FP ��������.
	size_t readSize = ftell(file);

	// FP ����ġ.
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	// ���� �о ���ۿ� ���.
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		std::cout << "�о�� ũ�Ⱑ �ٸ�\n";
		__debugbreak();
		return;
	}

	buffer[readSize] = '\0';

	// ���� ���� �� ����� �ε���.
	int index = 0;

	// ��ǥ ����� ���� ���� ����.
	int xPosition = 0;
	int yPosition = 0;

	// �ؼ� (�Ľ�-Parcing).
	while (index < (int)bytesRead)
	{
		// �� ���ھ� �б�.
		char mapChar = buffer[index++];

		// ���� ������ ��� ó��.
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// �� ���ڰ� 1�̸� Wall ���� ����.
		if (mapChar == '1')
		{
			Wall* wall = new Wall(Vector2(xPosition, yPosition));
			actors.PushBack(wall);
			map.PushBack(wall);
		}

		// �� ���ڰ� 2�̸� Wall2 ���� ����.
		if (mapChar == '2')
		{
			Wall2* wall2 = new Wall2(Vector2(xPosition, yPosition));
			actors.PushBack(wall2);
			map.PushBack(wall2);
		}

		// �� ���ڰ� 3�̸� Wall3 ���� ����.
		if (mapChar == '3')
		{
			Wall3* wall3 = new Wall3(Vector2(xPosition, yPosition));
			actors.PushBack(wall3);
			map.PushBack(wall3);
		}

		// �� ���ڰ� 4�̸� Wall4 ���� ����.
		if (mapChar == '4')
		{
			Wall4* wall4 = new Wall4(Vector2(xPosition, yPosition));
			actors.PushBack(wall4);
			map.PushBack(wall4);
		}

		// �� ���ڰ� 5�̸� Wall5 ���� ����.
		if (mapChar == '5')
		{
			Wall5* wall5 = new Wall5(Vector2(xPosition, yPosition));
			actors.PushBack(wall5);
			map.PushBack(wall5);
		}

		// �� ���ڰ� 6�̸� Wall6 ���� ����.
		if (mapChar == '6')
		{
			Wall6* wall6 = new Wall6(Vector2(xPosition, yPosition));
			actors.PushBack(wall6);
			map.PushBack(wall6);
		}

		// �� ���ڰ� .�̸� �׶��� ���� ����.
		else if (mapChar == '.')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);
		}

		// �� ���ڰ� i�̸� ��¥�׶��� ���� ����.
		else if (mapChar == 'i')
		{
			fakeGround* fakeground = new fakeGround(Vector2(xPosition, yPosition));
			actors.PushBack(fakeground);
			map.PushBack(fakeground);
		}

		// �� ���ڰ� b�̸� �ڽ� ���� ����.(�������� ��ü)
		else if (mapChar == 'b')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			Box* box = new Box(Vector2(xPosition, yPosition));
			actors.PushBack(box);
			boxes.PushBack(box);
		}

		// �� ���ڰ� t�̸� Ÿ�� ���� ����.(������������ ��ü)
		else if (mapChar == 't')
		{
			Target* target = new Target(Vector2(xPosition, yPosition));
			actors.PushBack(target);
			map.PushBack(target);
			targets.PushBack(target);
		}

		// �� ���ڰ� p�̸� �÷��̾� ���� ����.
		else if (mapChar == 'p')
		{
			fakeGround* fakeground = new fakeGround(Vector2(xPosition, yPosition));
			actors.PushBack(fakeground);
			map.PushBack(fakeground);
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			player = new Player(
				Vector2(xPosition, yPosition),
				this
			);
			actors.PushBack(player);
			playerInitialPosition = Vector2(xPosition, yPosition);
		}

		++xPosition;
	}

	// ���� ����.
	delete[] buffer;

	// ���� �ݱ�.
	fclose(file);
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ������ Ŭ���������, ���� ���� ó��.
	if (CheckGameClear())
	{

		// Ÿ�̸�.
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (!timer.IsTimeOut())
		{
			return;
		}

		// Ŀ�� �̵�.
		Engine::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y);

		//����ȭ������ �̵�
		//Log("asdf");
		//Sleep(1000);
		Engine::Get().LoadLevel(new EndingLevel());
		//Game::Get().EndingScreen(); //<- ���� �ߴ��ǵ� ���ľߴ�(����)
		//@todo - intro�� �����ϰ� ����� Ŭ���� ���� ������ ����
		//Engine::Get().LoadLevel(new EndingLevel()); <-���� include ������ �ϸ� ��
	}
	
}

void GameLevel::Draw()
{

	// �� �׸���.
	for (auto* actor : map)
	{
		// �÷��̾� ��ġ Ȯ��.
		if (actor->Position() == player->Position())
		{
			continue;
		}

		// �ڽ� ��ġ Ȯ��.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (actor->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// �� ���� �׸���.
		if (shouldDraw)
		{
			actor->Draw();
		}
	}

	// Ÿ�� �׸���.
	for (auto* target : targets)
	{
		// �÷��̾� ��ġ Ȯ��.
		if (target->Position() == player->Position())
		{
			continue;
		}

		// �ڽ� ��ġ Ȯ��.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (target->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// Ÿ�� ���� �׸���.
		if (shouldDraw)
		{
			target->Draw();
		}
	}

	// �ڽ� �׸���.
	for (auto* box : boxes)
	{
		box->Draw();
	}

	// �÷��̾� �׸���.
	player->Draw();
}

bool GameLevel::CanPlayerMove(const Vector2& position)
{
	// ������ Ŭ����� ��� �ٷ� ����.
	if (isGameClear)
	{
		return false;
	}

	// �ڽ� �˻�.
	Box* searchedBox = nullptr;
	for (auto* box : boxes)
	{
		if (box->Position() == position)
		{
			searchedBox = box;
			break;
		}
	}

	// �ڽ��� ������ ������������ �ǵ��ư���
	if (searchedBox)
	{
		// �÷��̾ �ʱ� ��ġ�� �ǵ���
		player->SetPosition(playerInitialPosition);

		//����� ����()
		//std::cout << "�ڽ��� ����! �÷��̾ �ʱ� ��ġ�� �̵��մϴ�.\n";
		return false;
	}

	// �̵��Ϸ��� ��ġ�� ���� �ִ��� Ȯ��.
	DrawableActor* searchedActor = nullptr;

	// ���� �̵��Ϸ��� ��ġ�� ���� ã��.
	for (auto* actor : map)
	{
		if (actor->Position() == position)
		{
			searchedActor = actor;
			break;
		}
	}

	// �˻��� ���Ͱ� ������ Ȯ��.
	if (searchedActor->As<Wall>())
	{
		return false;
	}

	// �˻��� ���Ͱ� �̵� ������ ����(��/Ÿ��)���� Ȯ��.
	if (searchedActor->As<Ground>()
		|| searchedActor->As<Target>() || searchedActor->As<fakeGround>())
	{
		return true;
	}

	return false;
}

//�÷��̾�� Ÿ���� �浹�ϸ� ����Ŭ���� @todo:�����ؾߴ�
bool GameLevel::CheckGameClear()
{
	// �÷��̾�� Ÿ�� �浹 üũ
	for (auto* target : targets)
	{
		if (player->Position() == target->Position())  // �÷��̾ Ÿ�ٿ� ������
		{
			isGameClear = true;
			return true;
		}
	}

	return false;

}

