#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& LeftTop, const Vec2& BottomRight);
	RectF(const Vec2& LeftTop, float height, float width);
	static RectF GetPosition(const Vec2& center, float halfWidth, float halfHeight);
	bool isOverllaping(const RectF& rect) const;
public:
	float left;
	float right;
	float top;
	float bottom;
};
