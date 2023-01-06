#pragma once
#include "Brick.h"

Brick::Brick( const RectF& rect_in, Color c)
	:
	rect(rect_in),
	c(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	gfx.DrawRect(rect, c);
}
