#include "Target.h"

Target::Target(const Vector2& position)
	: DrawableActor("E")
{
	// ��ġ ����.
	this->position = position;

	// ���� ����.
	color = Color::Blue;
}