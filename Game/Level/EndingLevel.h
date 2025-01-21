#pragma once

#include <Level/Level.h>

class EndingLevel : public Level
{
	RTTI_DECLARATIONS(EndingLevel, Level)

public:
	EndingLevel();
	~EndingLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	char* endingImage[1];
	int currentStep2 = 0;
};