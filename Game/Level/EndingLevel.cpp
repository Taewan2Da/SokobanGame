#include "EndingLevel.h"
#include "Engine/Engine.h"
#include "Level/GameLevel.h"

EndingLevel::EndingLevel()
{
	endingImage[0] = nullptr;
	
	system("cls");

	FILE* file = nullptr;
	fopen_s(&file, "../Assets/ScreenText/EndingScreen.txt", "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		size_t length = ftell(file);
		rewind(file);

		endingImage[0] = new char[length + 1];
		fread(endingImage[0], 1, length, file);
		endingImage[0][length] = '\0';

		fclose(file);
	}
	Engine::Get().SetCursorType(CursorType::NoCursor);
}

EndingLevel::~EndingLevel()
{
	for (auto* image : endingImage)
	{
		if (image)
		{
			delete[] image;
		}
	}
}

void EndingLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_RETURN))
	{
		exit(0);
		
	}
}

void EndingLevel::Draw()
{
	Super::Draw();

	// 현재 인트로 화면 보여주기.
	Engine::Get().SetCursorPosition(0, 0);
	Log("%s", endingImage[currentStep2]);
}
