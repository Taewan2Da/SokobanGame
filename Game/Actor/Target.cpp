#include "Target.h"

Target::Target(const Vector2& position)
	: DrawableActor("��") // �������� -> �÷��̾�� �浹�� ����Ŭ����
{
	// ��ġ ����.
	this->position = position;

	// ���� ����.
	color = Color::Blue;
}