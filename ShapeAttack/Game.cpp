#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter
#include "Circle.h"
#include "Square.h"
#include "GameWorld.h"

#define CIRCLE_COUNT 5
#define SQUARE_COUNT 5

void Game::Init()
{
	SetTargetFPS(60);

	testImage = LoadImage("TestImage.png");

	testTexture = LoadTextureFromImage(testImage);

	Vector2 circleStartPos = { 50, 30 };
	Vector2 squareStartPos = { 590, 30 };

	m_gameWorld = new GameWorld(1920, 1080);

	//m_circle = new Circle("CircleUnit.png");
	//m_square = new Square("SquareUnit.png");

	for (int i = 0; i < CIRCLE_COUNT; i++)
	{
		m_groupOfCircles.push_back(new Circle("CircleUnit.png", { circleStartPos.x, (circleStartPos.y + (circleStartPos.y * (i * 3))) }, { 0, 0 }));
	}
	for (int i = 0; i < SQUARE_COUNT; i++)
	{
		m_groupOfSquares.push_back(new Square("SquareUnit.png", { squareStartPos.x, (squareStartPos.y + (squareStartPos.y * (i * 3))) }, { 0, 0 }));
	}

}

void Game::Shutdown()
{
	//delete m_circle;
	//m_circle = nullptr;
	//delete m_square;
	//m_square = nullptr;
	for (int i = 0; i < CIRCLE_COUNT; i++)
	{
		delete m_groupOfCircles[i];
		m_groupOfCircles[i] = nullptr;
	}
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

	//m_circle->Draw();
	//m_square->Draw();
	for (int i = 0; i < CIRCLE_COUNT; i++)
	{
		m_groupOfCircles[i]->Draw();
	}
	for (int i = 0; i < SQUARE_COUNT; i++)
	{
		m_groupOfSquares[i]->Draw();
	}

	//DrawTexture(testTexture, position, 50, WHITE);

	EndDrawing();	//...and before this one.

}
