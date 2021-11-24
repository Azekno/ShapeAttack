#include "raylib.h"
#include "Game.h"

int main()
{
	Game game;

	InitWindow(640, 480, "Shape Attack");

	game.Init();

	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
	}

	game.Shutdown();
	CloseWindow();
} 