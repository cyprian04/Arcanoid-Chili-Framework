#pragma once
#include "Board.h"

Board::Board(const RectF& rect_in, Color c_in)
	:
	left(rect_in.left + padding),
	right(rect_in.right - padding),
	top(rect_in.top  + padding),
	bottom(rect_in.bottom - padding),
	c(c_in),
	TopLeft(int(Graphics::ScreenWidth /8), rect_in.top + padding + 30),
	TopRight(int(Graphics::ScreenWidth /1) - 100, rect_in.top + padding + 30),
	AdjustBrickPos(int(Graphics::ScreenWidth / 8), rect_in.top + padding + 130)
{
}

void Board::DrawBorder(Graphics& gfx)
{
	gfx.DrawRect(int(left), int(top), int(left + 5), int(bottom), c); //lewa//
	gfx.DrawRect(int(left), int(bottom - 5), int(right), int(bottom), c); //dó³//
	gfx.DrawRect(int(right - 5), int(top), int(right), int(bottom), c); // prawa//
	gfx.DrawRect(int(left), int(top), int(right), int(top + 5), c); // góra //
}
