#include "fakeGround.h"

fakeGround::fakeGround(const Vector2& position)
	: DrawableActor("f") // 가상벽(맞아도 시작지점으로 안돌아감)
{
	// 위치 설정.
	this->position = position;
}

