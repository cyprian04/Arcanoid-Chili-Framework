#include "Paddle.h"

Paddle::Paddle( const RectF& rect_in)
	:
	rect(rect_in)
{
}

void Paddle::Draw(Graphics& gfx) 
{
	gfx.DrawRect(rect, Colors::LightGray);

	gfx.DrawRect(int(rect.left + LeftSide), int(rect.top) , int(rect.right - RightSide),int(rect.bottom) , Colors::Red);

}

void Paddle::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		rect.left-=3;
		rect.right-=3;
	}

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		rect.left += 3;
		rect.right += 3;
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
