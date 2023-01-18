#include "Poo.h"

Poo::Poo() 
	:
	rng(rd()),
	PosLos(250, 450),
	VelLos(-3.0f, 3.0f)
{
}
void Poo::Init(const Vec2& pos_in, const Vec2& vel_in)
{
	pos = pos_in;
	vel = vel_in;
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