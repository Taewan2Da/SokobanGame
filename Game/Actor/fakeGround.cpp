#include "fakeGround.h"

fakeGround::fakeGround(const Vector2& position)
	: DrawableActor("f") // ����(�¾Ƶ� ������������ �ȵ��ư�)
{
	// ��ġ ����.
	this->position = position;
}

