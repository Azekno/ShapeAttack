#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(const char* textureName, Vector2 unitSpawnPosition, Vector2 unitStartVelocity);
	~Circle();

	void Update(float deltaTime);
	void Draw();

	void DrawTextureWithPivot(const Texture& text, Vector2 pos, Vector2 pivot, float rot);

private:
	Image m_circleImage;
	Texture m_circleTexture;

	Vector2 m_textureDrawPos;

	float m_circleRotation;
};