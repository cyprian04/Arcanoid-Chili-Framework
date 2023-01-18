#pragma once
#include "Ball.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in,  Color c)
	:
	pos(pos_in),
	vel(vel_in),
	c(c),
	GameOver(false),
	rng(rd()),
	los(4.0f, 7.0f)
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
	if (vel.x > 0.0f)
	{
		vel.x = -los(rng);
	}
	else
	{
		vel.x = los(rng);
	}
}

void Ball::ReboundY()
{
	if (vel.y > 0.0f)
	{
		vel.y = -los(rng);
	}
	else
	{
		vel.y = los(rng);
	}
}

void Ball::DrawLivesLeft(Graphics& gfx, const Board& walls) const
{
	int a = -60;
	for (int i = 0; i < LifeLeft; i++)
	{
		gfx.DrawCircle(int(walls.right + a), int(walls.bottom - 20), 10, Colors::Red);
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

bool Ball::SetGameOver()
{
	GameOver = true;
	return GameOver;
}
