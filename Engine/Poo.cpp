#include "Poo.h"

Poo::Poo()
	:
	rng(rd()),
	VelLos(-2.0f, 2.0f)
{
}

void Poo::Respawn(const Board& brd)
{
	const Vec2 PosDt = brd.TopLeft;
	pos = PosDt;
	const Vec2 VelDt(VelLos(rng), VelLos(rng));
	vel = VelDt;
}

void Poo::Update(float dt)
{
	pos += vel * dt;
}

void Poo::Draw(Graphics& gfx) const
{
		SpriteCodex::DrawPoo(pos, gfx);	
}

void Poo::DoWallsCollision(const Board& walls)
{
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
	}
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
	}
	if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
	}
}

bool Poo::DoBallCollision(Ball& ball)
{
		const RectF rect = GetRect();
		if (rect.IsOverLapping(ball.GetRect()))
		{
			ball.IncreseLives();
			return true;
		}
	return false;
}

bool Poo::DoPaddleCollision(const Paddle& pad, Ball& ball)
{
	const RectF rect = GetRect();
	if (rect.IsOverLapping(pad.GetRect()))
	{
		return ball.SetGameOver();
	}
	return false;
}

void Poo::ReboundX()
{
	vel.x = -vel.x;
}

void Poo::ReboundY()
{
	vel.y = -vel.y;
}

RectF Poo::GetRect()
{
	return RectF::FromCenter(pos, radius, radius);
}