#pragma once
#include "Paddle.h"
#include <cmath>

Paddle::Paddle(const Vec2& pos_in, float HalfWidth_in, float HalfHeight_in)
	:
	pos(pos_in),
	HalfWidth(HalfWidth_in),
	HalfHeight(HalfHeight_in)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	const RectF rect = GetRect();
	gfx.DrawRect(rect, Colors::Red);
	gfx.DrawRect(int(rect.left + wingWidth), int(rect.top) ,int(rect.right - wingWidth), int(rect.bottom), Colors::White);
}

void Paddle::DoWallsCollision(const RectF& walls)
{
	const RectF rect = GetRect();
	if (rect.left <= walls.left)
	{
		float tmp = walls.left - rect.left;
		pos.x += tmp;
	}
	if (rect.right >= walls.right)
	{
		float tmp = walls.right - rect.right;
		pos.x += tmp;
	}
}

bool Paddle::DoBallCollision(Ball& ball)
{
	if (!IsColldown)
	{
		const RectF rect = GetRect();
		if (rect.IsOverLapping(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetPosition();
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - rect.GetCenter()).x))
			{
				ball.ReboundY();
			}
			else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
			{
				ball.ReboundY();
			}
			else
			{
				ball.ReboundX();
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
		pos.x -=6 * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x+=6 * dt;
	}
}

void Paddle::ResetColldown()
{
	IsColldown = false;
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, HalfWidth, HalfHeight );
}
