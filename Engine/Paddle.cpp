#pragma once
#include "Paddle.h"
#include <cmath>

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

bool Paddle::DoBallCollision(Ball& ball)
{
	if (!IsColldown)
	{
		if (rect.IsOverLapping(ball.GetRect()))
		{
			Vec2 ballPos = ball.GetPosition();
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - rect.GetCenter()).x))
			{
				ball.ReboundY();
			}
			else if (ball.GetRect().right >= rect.left && ball.GetRect().left <= rect.right)
			{
				ball.ReboundY();
			}
			else
			{
				ball.ReboundY();
			}
			IsColldown = true;
			return true;
		}
	}
	return false;
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		rect.left-=6 * dt;
		rect.right-=6 * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		rect.left+=6;
		rect.right+=6;
	}
}

void Paddle::ResetColldown()
{
	IsColldown = false;
}
