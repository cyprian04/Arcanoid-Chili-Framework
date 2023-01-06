#pragma once
#include "Paddle.h"

Paddle::Paddle(const RectF& rect_in)
	:
	rect(rect_in)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, Colors::Red);
	gfx.DrawRect(int(rect.left + wingWidth), int(rect.top) ,int(rect.right - wingWidth), int(rect.bottom), Colors::White);
}
