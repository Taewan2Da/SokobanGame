#pragma once

#include <Actor/DrawableActor.h>

// �÷��̾ �ɾ�ٴ� �� �ִ� �ٴ�(��) ����.
class fakeGround : public DrawableActor
{
	RTTI_DECLARATIONS(fakeGround, DrawableActor)

public:
	fakeGround(const Vector2& position);
};