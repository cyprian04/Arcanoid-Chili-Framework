/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	walls(0.0f,float(gfx.ScreenWidth) ,0.0f , float(gfx.ScreenHeight)),
	ball(Vec2(210.0f, 250.0f), Vec2(-3.0f, -1.0f), Colors::Red),
	paddle(RectF(Vec2(400.0f, 500.0f), 100.0f, 20.0f)),
	soundPad(L"Sounds\\arkpad.wav")
{
	const Vec2 TopLeft(10.0f, 10.0f);
	int i = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y <col; y++)
		{
			bricks[i] = Brick(RectF( TopLeft + Vec2(x * width, y *height), width,  height), Colors::Blue);
			i++;
		}
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	paddle.Update(wnd.kbd);
	ball.Update();
	paddle.DoWallsCollision(walls);
	if (ball.DoWallsCollision(walls)) 
	{
		soundPad.Play();
	}

	for ( Brick& b:  bricks)
	{
		b.DoBallCollision(ball);
	}
	
	paddle.DoPaddleCollision(ball);
}

void Game::ComposeFrame()
{
	for (const Brick& b : bricks)
	{
		b.Draw(gfx);
	}
	ball.Draw(gfx);
	paddle.Draw(gfx);
}
