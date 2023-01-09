#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2& LeftTop, Vec2& BottomRight)
{
	RectF(LeftTop.x, BottomRight.x, LeftTop.y, BottomRight.y);
}

RectF::RectF(const Vec2& LeftTop, float height, float width)
{
	RectF(LeftTop.x, width, LeftTop.y, height);
}
