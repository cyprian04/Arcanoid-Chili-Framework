#include "Paddle.h"

Paddle::Paddle( const RectF& rect_in)
	:
	rect(rect_in)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, Colors::LightGray);

	gfx.DrawRect(int(rect.left + LeftSide), int(rect.top) , int(rect.right - RightSide),int(rect.bottom) , Colors::Red);

}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		rect.left-=5 * dt;
		rect.right-=5 * dt;
	}

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		rect.left += 5 * dt;
		rect.right += 5 * dt;
	}
}

bool Paddle::DoWallCollision(const RectF& walls)
{
	bool collided = false;
	if (rect.left <= walls.left)
	{
		float tmp = rect.left - walls.left;
		rect.left -= tmp;
		rect.right -= tmp;
		collided = true;

	}
	if (rect.right > walls.right)
	{
		const float tmp = walls.right - rect.right;
		rect.right += tmp;
		rect.left += tmp;

		collided = true;
	}
	return collided;
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	RectF ballPos = ball.GetRect();
	if (rect.isOverllaping(ballPos))
	{
		if (ballPos.left >= rect.left && ballPos.right <= rect.right)
		{
			ball.ReboundY();
			return true;
		}
		else
		{
			ball.ReboundX();
			return true;
		}
	}
	return false;
}
