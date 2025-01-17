#pragma once

#include <Level/Level.h>

class IntroLevel : public Level
{
	RTTI_DECLARATIONS(IntroLevel, Level)

public:
	IntroLevel();
	~IntroLevel();

	virtual void Update(float delatTime) override;
	virtual void Draw() override;

private:
	char* introImage[2];
	int currentStep = 0;
};