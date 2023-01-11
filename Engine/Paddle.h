#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"
class Paddle
{
public:
	Paddle(const RectF& rect_in);
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd, float dt);
	bool DoWallCollision(const RectF& walls);
	bool DoBallCollision( Ball& ball) const;
private:
	static constexpr float LeftSide= 10.0f;
	static constexpr float RightSide = 10.0f;
	RectF rect;
};

