#pragma once
#include "Board.h"

Board::Board(const RectF& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{
}

void Board::DrawBorder(Graphics& gfx)
{
	gfx.DrawRect(int(rect.left + padding), int(rect.top + padding), int(rect.left + padding + 5), int(rect.bottom - padding), c); //lewa//
	gfx.DrawRect(int(rect.left + padding), int(rect.bottom - padding - 5), int(rect.right - padding), int(rect.bottom - padding), c); //dó³//
	gfx.DrawRect(int(rect.right - padding - 5), int(rect.top + padding), int(rect.right - padding), int(rect.bottom - padding), c); // prawa//
	gfx.DrawRect(int(rect.left + padding), int(rect.top + padding), int(rect.right - padding), int(rect.top + padding + 5), c); // góra //
}
