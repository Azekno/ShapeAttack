#include "Circle.h"

Circle::Circle(const char* textureName, Vector2 unitSpawnPosition, Vector2 unitSpawnVelocity)
{
	m_circleImage = LoadImage(textureName);
	m_circleTexture = LoadTextureFromImage(m_circleImage);

	m_unitPosition = unitSpawnPosition;
	m_unitVelocity = unitSpawnVelocity;
	m_textureDrawPos.x = m_circleTexture.width / 2;
	m_textureDrawPos.y = m_circleTexture.height / 2;
}

Circle::~Circle()
{
	UnloadTexture(m_circleTexture);
	UnloadImage(m_circleImage);
}

void Circle::Update(float deltaTime)
{
}

void Circle::Draw()
{
	DrawTextureWithPivot(m_circleTexture, m_unitPosition, m_textureDrawPos, 0.0f);
}

void Circle::DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos(rot * DEG2RAD);
	float sinTheta = sin(rot * DEG2RAD);

	Vector2 rotatedOffset;

	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos + rotatedOffset, rot, 1.0f, WHITE);
}
