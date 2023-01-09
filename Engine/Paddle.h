#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(const RectF& rect_in);
	void Draw(Graphics& gfx)const;
	void DoWallsCollision(RectF& walls);
	bool DoBallCollision(Ball& ball);
	void Update(const Keyboard& kbd);
	void ResetColldown();
private:
	static constexpr float wingWidth = 20.0f;
	RectF rect;
	bool IsColldown = false;
};

