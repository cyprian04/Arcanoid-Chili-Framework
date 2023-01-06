#pragma once
#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2& LeftTop, const Vec2& bottomRight)
	:
	 RectF(LeftTop.x, LeftTop.y, bottomRight.x, bottomRight.y )
{
}

RectF::RectF(const Vec2& LeftTop, float width, float height)
	:
	RectF(LeftTop.x, LeftTop.y, width, height)
{
}

bool RectF::IsOverLapping(const RectF& other)
{
	return other.top > top && other.bottom < bottom &&
		   other.left < right && other.right > left;
}
