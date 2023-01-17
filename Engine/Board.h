#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
class Board
{
public:
	Board(const RectF& rect_in, Color c_in);
	void DrawBorder(Graphics& gfx);
private:
	Color c;
	const float padding = 0.0f;
public:
	const Vec2 TopLeft;
	float left;
	float right;
	float top;
	float bottom;
};	
