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
	 RectF(LeftTop.x,bottomRight.x ,LeftTop.y , bottomRight.y )
{
}

RectF::RectF(const Vec2& LeftTop, float width, float height)
	:
	RectF(LeftTop.x, LeftTop.x + width,  LeftTop.y, LeftTop.y + height)
{
}

bool RectF::IsOverLapping(const RectF& other)const 
{
	return other.top < bottom && other.bottom > top &&
		   other.left < right && other.right > left;
}

RectF RectF::FromCenter(const Vec2& center, float Halfwidth, float Halfheight)
{
	Vec2 Half(Halfwidth, Halfheight);
	return RectF(center - Half, center + Half);
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left + right) / 2.0f, (top + right) /2.0f);
}
