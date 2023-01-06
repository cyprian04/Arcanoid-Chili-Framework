#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& LeftTop, const Vec2& bottomRight);
	RectF(const Vec2& LeftTop, float width, float height);
	bool IsOverLapping(const RectF& other);
public:
	float left;
	float right;
	float top;
	float bottom;
};
