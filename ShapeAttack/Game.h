#pragma once

#include "raylib.h"

class Circle;
class Square;

class Game
{
private:
	Image testImage;
	Texture testTexture;

	Circle* m_circle;
	Square* m_square;

	float deltaTime;

	float position = 50.0f;
public:
	Game() {}

	void Init();

	void Shutdown();

	void Update();

	void Draw();

};