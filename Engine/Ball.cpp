#include "Ball.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

void Ball::Draw( Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}
