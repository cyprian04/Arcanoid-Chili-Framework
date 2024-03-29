/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "RectF.h"
#include "Brick.h"
#include "Ball.h"
#include "Sound.h"
#include "Paddle.h"
#include "FrameTimer.h"
#include "Board.h"
#include "Poo.h"
#include <random>
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board board;
	Ball ball;
	Sound soundPad;
	Sound soundBrick;
	Paddle paddle;
	float width = 50.0f;
	float height = 20.0f;
	static constexpr int row = 12;
	static constexpr int col = 3;
	static constexpr int nBricks = row * col;
	Brick bricks[nBricks];
	static constexpr int row2 = 6;
	static constexpr int col2 = 1;
	static constexpr int NumberOfStaticBricks = row2 * col2;
	Brick StaticBricks[NumberOfStaticBricks];
	FrameTimer ft;
	static constexpr int nPoo = 2;
	Poo poos[nPoo];
	int counter = 100;
	bool BeginGame = false;
	bool GameStarted = false;
	/********************************/
};