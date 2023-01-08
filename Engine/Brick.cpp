#pragma once
#include "Brick.h"

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

bool Brick::DoBallCollision(Ball& ball)
{
		if (!destroyed && rect.IsOverLapping(ball.GetRect()))
		{	
			Vec2 ballPos = ball.GetPosition();
			if (ballPos.x >= rect.right && ballPos.x < rect.left)
			{
				ball.ReboundX();
			}
			else
			{
				ball.ReboundY();
			}
			destroyed = true;
		}
	return destroyed;
}

