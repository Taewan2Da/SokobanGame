#pragma once

#include <Actor/DrawableActor.h>

// 플레이어가 걸어다닐 수 있는 바닥(땅) 액터.
class fakeGround : public DrawableActor
{
	RTTI_DECLARATIONS(fakeGround, DrawableActor)

public:
	fakeGround(const Vector2& position);
};