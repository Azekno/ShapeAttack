#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>

class GameWorld
{
public:
	GameWorld(const char* textureName);
	~GameWorld();

	void Update();
	void Draw();

	int m_mineCount;

private:
	//Variables for the game background to be shown on screen

	Image m_backgroundImage;
	Texture m_backgroundtexture;

	Vector2 m_gameBackgroundPosition;
	Vector2 m_tiling;
	Vector2 m_offset;
	Rectangle m_quad;
};
