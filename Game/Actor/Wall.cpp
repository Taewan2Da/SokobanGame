#include "Wall.h"

Wall::Wall(const Vector2& position)
	: DrawableActor("│")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}

Wall2::Wall2(const Vector2& position)
	: DrawableActor("─")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}

Wall3::Wall3(const Vector2& position)
	: DrawableActor("┌")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}

Wall4::Wall4(const Vector2& position)
	: DrawableActor("┐")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}

Wall5::Wall5(const Vector2& position)
	: DrawableActor("└")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}

Wall6::Wall6(const Vector2& position)
	: DrawableActor("┘")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Green;
}
