#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(const Vec2& pos_in, float HalfWidth_in , float HalfHeight_in);
	void Draw(Graphics& gfx)const;
	void DoWallsCollision(const RectF& walls);
	bool DoBallCollision(Ball& ball);
	void Update(const Keyboard& kbd, float dt);
	void ResetColldown();
	RectF GetRect() const;
private:
	static constexpr float wingWidth = 15.0f;
	float HalfWidth;
	float HalfHeight;
	bool IsColldown = false;
	Vec2 pos;
};

