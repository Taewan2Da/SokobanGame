#include "Ground.h"

Ground::Ground(const Vector2& position)
	: DrawableActor("g") // �÷��̾ ��� �ٴϴ� ��
{
	// ��ġ ����.
	this->position = position;

	// ���� ����.
	color = Color::White;
}