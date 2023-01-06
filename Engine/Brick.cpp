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
		gfx.DrawRect(rect, c);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
		if (!destroyed && rect.IsOverLapping(ball.GetRect()))
		{	
			if (ball.GetRect().right > rect.right || ball.GetRect().left < rect.left)
			{
				ball.ReboundX();
			}
			if (ball.GetRect().top > rect.top || ball.GetRect().bottom < rect.bottom)
			{
				ball.ReboundY();
			}
			destroyed = true;
		}
	return destroyed;
}

