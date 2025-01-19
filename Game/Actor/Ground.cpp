#include "Ground.h"

Ground::Ground(const Vector2& position)
	: DrawableActor("g") // 플레이어가 밟고 다니는 땅
{
	// 위치 설정.
	this->position = position;

	// 색상 지정.
	color = Color::White;
}