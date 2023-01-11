#include "Paddle.h"

Paddle::Paddle( const RectF& rect_in)
	:
	rect(rect_in)
{
}

void Paddle::Draw(Graphics& gfx) 
{

	gfx.DrawRect(int(rect.left - LeftSide), int(rect.top) , int(rect.right + RightSide),int(rect.bottom) , Colors::White);
	gfx.DrawRect(rect, Colors::Red);

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
