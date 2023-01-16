#pragma once
#include "Board.h"

Board::Board(const RectF& rect_in, Color c_in)
	:
	left(rect_in.left),
	right(rect_in.right),
	top(rect_in.top),
	bottom(rect_in.bottom),
	c(c_in)
{
}

void Board::DrawBorder(Graphics& gfx)
{
	gfx.DrawRect(int(left + padding), int(top + padding), int(left + padding + 5), int(bottom - padding), c); //lewa//
	gfx.DrawRect(int(left + padding), int(bottom - padding - 5), int(right - padding), int(bottom - padding), c); //dó³//
	gfx.DrawRect(int(right - padding - 5), int(top + padding), int(right - padding), int(bottom - padding), c); // prawa//
	gfx.DrawRect(int(left + padding), int(top + padding), int(right - padding), int(top + padding + 5), c); // góra //
}
