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

void Ball::ReboundX()
{
	vel.x =- vel.x;
}

void Ball::ReboundY()
{
	vel.y =- vel.y;
}

bool Ball::DoWallCollision(const RectF& walls)
{
		bool collided = false;
		const RectF ballPos = GetRect();

		if (walls.left > ballPos.left)
		{
			float tmp = walls.left - ballPos.left;
			pos.x += tmp;
			ReboundX();
			collided = true;
		}
		if (walls.right < ballPos.right)
		{
			float tmp = walls.right - ballPos.right;
			pos.x += tmp;
			ReboundX();
			collided = true;
		}
		if (walls.top > ballPos.top)
		{
			float tmp = walls.top - ballPos.top;
			pos.y += tmp;
			ReboundY();
			collided = true;
		}
		if (walls.bottom < ballPos.bottom)
		{
			float tmp = walls.bottom - ballPos.bottom;
			pos.y += tmp;
			ReboundY();
			collided = true;
		}
		return collided;
}

RectF Ball::GetRect() const
{
	return RectF::GetPosition(pos,radius, radius);
}


