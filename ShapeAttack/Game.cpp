#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter
#include "Circle.h"
#include "Square.h"

void Game::Init()
{
	SetTargetFPS(60);

	testImage = LoadImage("TestImage.png");

	testTexture = LoadTextureFromImage(testImage);

	m_circle = new Circle("CircleUnit.png");
	m_square = new Square("SquareUnit.png");

}

void Game::Shutdown()
{
	delete m_circle;
	m_circle = nullptr;
	delete m_square;
	m_square = nullptr;
}

void Game::Update()
{
	deltaTime = GetFrameTime();


	position += 10 * deltaTime;

	//Put game logic and input management here.
}

void Game::Draw()
{

	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS();


	BeginDrawing();	//Rendering code comes after this call...
	ClearBackground(WHITE);

	DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);

	m_circle->Draw();
	m_square->Draw();

	//DrawTexture(testTexture, position, 50, WHITE);

	EndDrawing();	//...and before this one.

}
