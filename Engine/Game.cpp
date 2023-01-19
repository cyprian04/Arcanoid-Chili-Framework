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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(Board(RectF(0.0f, float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)), Colors::Blue)),
	ball(Vec2(210.0f, 250.0f), Vec2(4.0f, -6.0f), Colors::Red),
	paddle(Vec2(400.0f, board.bottom - 50), 35.0f, 6.0f),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav")
{
	Color color[4] = { Colors::Green, Colors::Red, Colors::Yellow, Colors::Magenta };

	int i = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y <col; y++)
		{
			bricks[i] = Brick(RectF(board.TopLeft + Vec2(x * width, y * height), width, height), color[y]);
			i++;
		}
	}
	poos[0].Respawn(board, 0);	
	poos[1].Respawn(board, 1);
}

void Game::Go()
{
	gfx.BeginFrame();

	float elapsedTime = ft.Mark();
	if (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		GameStarted = true;
	}

	if (GameStarted && !ball.GetGameOver())
	{
		paddle.Update(wnd.kbd, dt * 60.0f);
		paddle.DoWallsCollision(board);
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

		if (ball.DoWallsCollision(board)) 
		{
			paddle.ResetColldown();
			soundPad.Play();
		}

		for( Poo& p: poos)
		{
			p.Update(dt * 60.0f);
			p.DoWallsCollision(board);
			p.DoPaddleCollision(paddle, ball);
			if (p.DoBallCollision(ball))
			{
				p.Respawn(board);
			}
		}
	}
}

void Game::ComposeFrame()
{
	const Vec2 Center(400.0f, 300.0f);
	if (!GameStarted)
	{
		SpriteCodex::DrawTitle(Center, gfx);
	}
	else  
	{
		if (ball.GetGameOver())
		{
		  SpriteCodex::DrawGameOver(Center, gfx);
		}

		for (const Brick& b : bricks)
		{
			b.Draw(gfx);
		}

		for (const Poo& p : poos)
		{
			p.Draw(gfx);
		}
		paddle.Draw(gfx);
		board.DrawBorder(gfx);
		ball.Draw(gfx);
		ball.DrawLivesLeft(gfx, board);
	}
}
