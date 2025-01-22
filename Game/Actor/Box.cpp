#include "Box.h"

Box::Box(const Vector2& position)
	: DrawableActor("b") //가상벽(맞으면 시작지점으로 감)
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}