#include "IntroLevel.h"
#include "Engine/Engine.h"
#include "Level/GameLevel.h"

IntroLevel::IntroLevel()
{
	introImage[0] = nullptr;
	introImage[1] = nullptr;

	FILE* file = nullptr;
	fopen_s(&file, "../Assets/ScreenText/FirstScreen.txt", "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		size_t length = ftell(file);
		rewind(file);

		introImage[0] = new char[length + 1];
		fread(introImage[0], 1, length, file);
		introImage[0][length] = '\0';

		fclose(file);
	}

	fopen_s(&file, "../Assets/ScreenText/GameRule.txt", "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		size_t length = ftell(file);
		rewind(file);

		introImage[1] = new char[length + 1];
		fread(introImage[1], 1, length, file);
		introImage[1][length] = '\0';

		fclose(file);
	}

	Engine::Get().SetCursorType(CursorType::NoCursor);
}

IntroLevel::~IntroLevel()
{
	for (auto* image : introImage)
	{
		if (image)
		{
			delete[] image;
		}
	}
}

void IntroLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// 아무 키나 눌리면, 화면 바꾸거나 다른 레벨로 이동.
	//if (Engine::Get().AnyKeyDown())
	//테스트로 엔터키
	if (Engine::Get().GetKeyDown(VK_RETURN))
	{
		// 보여줄 인트로 화면이 남았으면 다음 단계로 이동.
		if (currentStep < 1)
		{
			++currentStep;
			system("cls");
		}

		// 인트로 다 보여줬으면, 레벨 전환.
		else
		{
			system("cls");
			Engine::Get().LoadLevel(new GameLevel());
		}
	}
}

void IntroLevel::Draw()
{
	Super::Draw();

	// 현재 인트로 화면 보여주기.
	Engine::Get().SetCursorPosition(0, 0);
	Log("%s", introImage[currentStep]);
}