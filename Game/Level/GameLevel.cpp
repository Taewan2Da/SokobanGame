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


//로그 시간대기 
#include <iostream>
#include <chrono>
#include <thread>
#include<windows.h>


GameLevel::GameLevel()
{
	// 커서 감추기.
	Engine::Get().SetCursorType(CursorType::NoCursor);

	// 맵 파일 불러와 레벨 로드.
	// 파일 읽기.

	FILE* file = nullptr;
	//맵 3개중에랜덤으로 한개 뽑기
	int randomCase = (rand() % 3) + 1;
	switch (randomCase)
	{
	case 1:
		fopen_s(&file, "../Assets/Maps/Map1.txt", "rb");
		break;
	case 2:
		fopen_s(&file, "../Assets/Maps/Map2.txt", "rb");
		break;
	case 3:
		fopen_s(&file, "../Assets/Maps/Map3.txt", "rb");
		break;
	}
		
	
	// 파일 처리.
	if (file == nullptr)
	{
		std::cout << "맵 파일 열기 실패.\n";
		__debugbreak();
		return;
	}



	// 파일 읽기.
	// 끝위치로 이동.
	fseek(file, 0, SEEK_END);

	// 이동한 위치의 FP 가져오기.
	size_t readSize = ftell(file);

	// FP 원위치.
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	// 파일 읽어서 버퍼에 담기.
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		std::cout << "읽어온 크기가 다름\n";
		__debugbreak();
		return;
	}

	buffer[readSize] = '\0';

	// 파일 읽을 때 사용할 인덱스.
	int index = 0;

	// 좌표 계산을 위한 변수 선언.
	int xPosition = 0;
	int yPosition = 0;

	// 해석 (파싱-Parcing).
	while (index < (int)bytesRead)
	{
		// 한 문자씩 읽기.
		char mapChar = buffer[index++];

		// 개행 문자인 경우 처리.
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// 맵 문자가 1이면 Wall 액터 생성.
		if (mapChar == '1')
		{
			Wall* wall = new Wall(Vector2(xPosition, yPosition));
			actors.PushBack(wall);
			map.PushBack(wall);
		}

		// 맵 문자가 2이면 Wall2 액터 생성.
		if (mapChar == '2')
		{
			Wall2* wall2 = new Wall2(Vector2(xPosition, yPosition));
			actors.PushBack(wall2);
			map.PushBack(wall2);
		}

		// 맵 문자가 3이면 Wall3 액터 생성.
		if (mapChar == '3')
		{
			Wall3* wall3 = new Wall3(Vector2(xPosition, yPosition));
			actors.PushBack(wall3);
			map.PushBack(wall3);
		}

		// 맵 문자가 4이면 Wall4 액터 생성.
		if (mapChar == '4')
		{
			Wall4* wall4 = new Wall4(Vector2(xPosition, yPosition));
			actors.PushBack(wall4);
			map.PushBack(wall4);
		}

		// 맵 문자가 5이면 Wall5 액터 생성.
		if (mapChar == '5')
		{
			Wall5* wall5 = new Wall5(Vector2(xPosition, yPosition));
			actors.PushBack(wall5);
			map.PushBack(wall5);
		}

		// 맵 문자가 6이면 Wall6 액터 생성.
		if (mapChar == '6')
		{
			Wall6* wall6 = new Wall6(Vector2(xPosition, yPosition));
			actors.PushBack(wall6);
			map.PushBack(wall6);
		}

		// 맵 문자가 .이면 그라운드 액터 생성.
		else if (mapChar == '.')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);
		}

		// 맵 문자가 i이면 가짜그라운드 액터 생성.
		else if (mapChar == 'i')
		{
			fakeGround* fakeground = new fakeGround(Vector2(xPosition, yPosition));
			actors.PushBack(fakeground);
			map.PushBack(fakeground);
		}

		// 맵 문자가 b이면 박스 액터 생성.(가상벽으로 교체)
		else if (mapChar == 'b')
		{
			Ground* ground = new Ground(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			Box* box = new Box(Vector2(xPosition, yPosition));
			actors.PushBack(box);
			boxes.PushBack(box);
		}

		// 맵 문자가 t이면 타겟 액터 생성.(도착지점으로 교체)
		else if (mapChar == 't')
		{
			Target* target = new Target(Vector2(xPosition, yPosition));
			actors.PushBack(target);
			map.PushBack(target);
			targets.PushBack(target);
		}

		// 맵 문자가 p이면 플레이어 액터 생성.
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
			//초기 위치
			actors.PushBack(player);
			playerInitialPosition = Vector2(xPosition, yPosition);
		}

		++xPosition;
	}



	// 버퍼 삭제.
	delete[] buffer;

	// 파일 닫기.
	fclose(file);
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// 게임이 클리어됐으면, 게임 종료 처리.
	if (CheckGameClear())
	{

		// 타이머.
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (!timer.IsTimeOut())
		{
			return;
		}

		// 커서 이동.
		Engine::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y);

		//엔딩화면으로 이동
		Engine::Get().LoadLevel(new EndingLevel());

	}
	
}

void GameLevel::Draw()
{

	// 맵 그리기.
	for (auto* actor : map)
	{
		// 플레이어 위치 확인.
		if (actor->Position() == player->Position())
		{
			continue;
		}

		// 박스 위치 확인.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (actor->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// 맵 액터 그리기.
		if (shouldDraw)
		{
			actor->Draw();
		}
	}

	// 타겟 그리기.
	for (auto* target : targets)
	{
		// 플레이어 위치 확인.
		if (target->Position() == player->Position())
		{
			continue;
		}

		// 박스 위치 확인.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (target->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// 타겟 액터 그리기.
		if (shouldDraw)
		{
			target->Draw();
		}
	}

	// 박스 그리기.
	for (auto* box : boxes)
	{
		box->Draw();
	}

	// 플레이어 그리기.
	player->Draw();
}


bool GameLevel::CanPlayerMove(const Vector2& position)
{

	// 박스 검색.
	Box* searchedBox = nullptr;
	for (auto* box : boxes)
	{
		if (box->Position() == position)
		{
			searchedBox = box;
			break;
		}
	}

	// 박스에 닿으면 시작지점으로 되돌아가기
	if (searchedBox)
	{
		// 플레이어를 초기 위치로 되돌림
		player->SetPosition(playerInitialPosition);
		static int count = 0;
		//(20,10)위치에 충돌알림 로그 출력
		for (int ix = 0; ix < 17;ix++)
		{
			int x = rand() % 60 + 25;
			int y = rand() % 25;
			Engine::Get().SetCursorPosition(Vector2(x, y));  // 특정 위치로 커서 이동
			std::cout << "충돌!!!!" << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 0.3초 대기

		system("cls");

		if (count < 9)
		{
			//setCursorPosition(x2, y2);
			Engine::Get().SetCursorPosition(Vector2(50, 8));
			std::cout << "  /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(50, 9));
			std::cout << " ( o.o ) " << std::flush;
			Engine::Get().SetCursorPosition(Vector2(50, 10));
			std::cout << "  > ^ <" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(50, 12));
			count++;
			std::cout << "충돌횟수: " << count << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용
			std::this_thread::sleep_for(std::chrono::seconds(1));  // 1초 대기
			system("cls");
		}else if(count < 19)
		{
			//setCursorPosition(x2, y2);
			Engine::Get().SetCursorPosition(Vector2(47, 8));
			std::cout << "  /\\_/\\    /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(47, 9));
			std::cout << " ( o.o )  ( o.o )" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(47, 10));
			std::cout << "  > ^ <    > ^ <" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(50, 12));
			count++;
			std::cout << "충돌횟수: " << count << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용
			std::this_thread::sleep_for(std::chrono::seconds(1));  // 1초 대기
			system("cls");
		}
		else
		{
			//setCursorPosition(x2, y2);
			Engine::Get().SetCursorPosition(Vector2(42, 8));
			std::cout << "  /\\_/\\    /\\_/\\    /\\_/\\" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(42, 9));
			std::cout << " ( o.o )  ( o.o )  ( o.o )" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(42, 10));
			std::cout << "  > ^ <    > ^ <    > ^ <" << std::flush;
			Engine::Get().SetCursorPosition(Vector2(50, 12));
			count++;
			std::cout << "충돌횟수: " << count << std::flush;  // 이전 출력 덮어쓰기를 위해 flush 사용
			std::this_thread::sleep_for(std::chrono::seconds(1));  // 1초 대기
			system("cls");
		}
		


		return false;
	}

	// 이동하려는 위치에 벽이 있는지 확인.
	DrawableActor* searchedActor = nullptr;

	// 먼저 이동하려는 위치의 액터 찾기.
	for (auto* actor : map)
	{
		if (actor->Position() == position)
		{
			searchedActor = actor;
			break;
		}
	}

	// 검색한 액터가 벽인지 확인.
	if (searchedActor->As<Wall>())
	{
		return false;
	}

	// 검색한 액터가 이동 가능한 액터(땅/타겟)인지 확인.
	if (searchedActor->As<Ground>()
		|| searchedActor->As<Target>() || searchedActor->As<fakeGround>())
	{
		return true;
	}

	return false;
}



//플레이어와 타겟이 충돌하면 게임클리어
bool GameLevel::CheckGameClear()
{
	// 플레이어와 타겟 충돌 체크
	for (auto* target : targets)
	{
		if (player->Position() == target->Position())  // 플레이어가 타겟에 닿으면
		{
			//isGameClear = true;
			return true;
		}
	}

	return false;

}

