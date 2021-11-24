#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square(const char* textureName, Vector2 unitSpawnPosition, Vector2 unitSpawnVelocity);
	~Square();

	void Update(float deltaTime);
	void Draw();

	void DrawTextureWithPivot(const Texture& text, Vector2 pos, Vector2 pivot, float rot);

private:
	Image m_squareImage;
	Texture m_squareTexture;

	Vector2 m_textureDrawPos;

	float squareRotation;
};