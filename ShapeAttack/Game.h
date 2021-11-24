#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>

class GameWorld;
class Circle;
class Square;

class Game
{
private:
	Image testImage;
	Texture testTexture;

	Circle* m_circle;
	Square* m_square;
	GameWorld* m_gameWorld;

	std::vector<Circle*> m_groupOfCircles;
	std::vector<Square*> m_groupOfSquares;

	float deltaTime;

	float position = 50.0f;
public:
	Game() {}

	void Init();

	void Shutdown();

	void Update();

	void Draw();

};