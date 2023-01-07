#pragma once
#include "Paddle.h"

Paddle::Paddle(const RectF& rect_in)
	:
	rect(rect_in)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, Colors::Red);
	gfx.DrawRect(int(rect.left + wingWidth), int(rect.top) ,int(rect.right - wingWidth), int(rect.bottom), Colors::White);
}

void Paddle::DoWallsCollision(RectF& walls)
{
	if (rect.left <= walls.left)
	{
		float tmp = walls.left - rect.left;
		rect.left += tmp;
		rect.right += tmp;
	}
	if (rect.right >= walls.right)
	{
		float tmp = walls.right - rect.right;
		rect.left += tmp;
		rect.right += tmp;
	}
}

void Paddle::DoPaddleCollision(Ball& ball)
{
	if (rect.IsOverLapping(ball.GetRect()))
	{
		if (ball.GetRect().right > rect.right || ball.GetRect().left < rect.left)
		{
			ball.ReboundX();
		}
		if (ball.GetRect().top > rect.top || ball.GetRect().bottom < rect.bottom)
		{
			ball.ReboundY();
		}
	}
}

void Paddle::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		rect.left-=3;
		rect.right-=3;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		rect.left+=3;
		rect.right+=3;
	}
}
