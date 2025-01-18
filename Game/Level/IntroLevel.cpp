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

	// �ƹ� Ű�� ������, ȭ�� �ٲٰų� �ٸ� ������ �̵�.
	//if (Engine::Get().AnyKeyDown())
	//�׽�Ʈ�� ����Ű
	if (Engine::Get().GetKeyDown(VK_RETURN))
	{
		// ������ ��Ʈ�� ȭ���� �������� ���� �ܰ�� �̵�.
		if (currentStep < 1)
		{
			++currentStep;
			system("cls");
		}

		// ��Ʈ�� �� ����������, ���� ��ȯ.
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

	// ���� ��Ʈ�� ȭ�� �����ֱ�.
	Engine::Get().SetCursorPosition(0, 0);
	Log("%s", introImage[currentStep]);
}