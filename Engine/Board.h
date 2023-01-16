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
	RectF rect;
	Color c;
	const float padding = 20.0f;
public:
	float left;
	float right;
	float top;
	float bottom;
};	
