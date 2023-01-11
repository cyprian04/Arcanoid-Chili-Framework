#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(const RectF& rect_in);
	void Draw(Graphics& gfx) ;
	void Update(const Keyboard& kbd);
	bool DoWallCollision(const RectF& walls);
private:
	static constexpr float LeftSide= 10.0f;
	static constexpr float RightSide = 10.0f;
	RectF rect;
};

