#pragma once
#include "Ball.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in,  Color c)
	:
	pos(pos_in),
	vel(vel_in),
	c(c),
	GameOver(false)
{
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

bool Ball::DoWallsCollision(const Board& walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	}
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
		LifeLeft--;
		if (LifeLeft == 0)
		{
			GameOver = true;
		}
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

void Ball::DrawLivesLeft(Graphics& gfx, const Board& walls) const
{
	int a = 20;
	for (int i = 0; i < LifeLeft; i++)
	{
		gfx.DrawCircle(700 + a, 550, 10, Colors::Red);
		a += 20;
	}
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius );
}

Vec2 Ball::GetPosition() const
{
	return pos;
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

bool Ball::GetGameOver() const
{
	return GameOver;
}
