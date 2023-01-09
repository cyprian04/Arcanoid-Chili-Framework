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
	ball(Vec2(210.0f, 250.0f), Vec2(3.0f, -4.0f), Colors::Red),
	paddle(RectF(Vec2(400.0f, 500.0f), 100.0f, 20.0f)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav")
{
	const Vec2 TopLeft(100.0f, 50.0f);

	Color color[4] = { Colors::Green, Colors::Red, Colors::Blue, Colors::Magenta };

	int i = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y <col; y++)
		{
			bricks[i] = Brick(RectF(TopLeft + Vec2(x * width, y * height), width, height), color[y]);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();

	float elapsedTime = ft.Mark();
	if (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.025f, elapsedTime);
		elapsedTime -= dt;
		UpdateModel(dt);
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	paddle.Update(wnd.kbd, dt * 60.0f);
	paddle.DoWallsCollision(walls);
	ball.Update(dt * 60.0f);

	int brickIndex;
	float LenghtSq;
	bool CollisionHappend = false;
	for (int i = 0; i < nBricks; i++)
	{
		if (bricks[i].CheckBallCollision(ball)) 
		{
			const float NewLenghtSq = (ball.GetPosition() - bricks[i].GetCenter()).GetLengthSq();
			if (CollisionHappend)
			{
				if (NewLenghtSq < LenghtSq) 
				{
					LenghtSq = NewLenghtSq;
					brickIndex = i;
				}
			}
			else
			{
				LenghtSq = NewLenghtSq;
				CollisionHappend = true;
				brickIndex = i;
			}
		}
	}

	if (CollisionHappend)
	{
		paddle.ResetColldown();
		bricks[brickIndex].ExecuteBallCollision(ball);
		soundBrick.Play();
	}
	if (paddle.DoBallCollision(ball))
	{
		soundPad.Play();
	}

	if (ball.DoWallsCollision(walls)) 
	{
		paddle.ResetColldown();
		soundPad.Play();
	}
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
