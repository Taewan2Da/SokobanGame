#include "Target.h"

Target::Target(const Vector2& position)
	: DrawableActor("◎") // 도착지점 -> 플레이어와 충돌시 게임클리어
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Blue;
}