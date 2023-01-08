#pragma once
#include "Brick.h"
#include <assert.h>
#include <cmath>
Brick::Brick( const RectF& rect_in, Color c)
	:
	rect(rect_in),
	c(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{	
		gfx.DrawRect(rect.GetExpanded(-padding), c);
	}
}

bool Brick::CheckBallCollision(Ball& ball) const
{
	return !destroyed && rect.IsOverLapping(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	Vec2 ballPos = ball.GetPosition();

	if(std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x)) 
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundY();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
