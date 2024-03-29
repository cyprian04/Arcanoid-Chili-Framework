#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite for DrawBall
	static void DrawBall( const Vec2& center,Graphics& gfx );
	static void DrawTitle(const Vec2& center, Graphics& gfx);
	static void DrawGameOver(const Vec2& center, Graphics& gfx);
	static void DrawReady(const Vec2& center, Graphics& gfx);
	static void DrawPoo(const Vec2& center, Graphics& gfx);

};