#include "Poo.h"

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
