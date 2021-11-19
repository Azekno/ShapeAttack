#include "Square.h"

Square::Square(const char* textureName)
{
	m_squareImage = LoadImage(textureName);
	m_squareTexture = LoadTextureFromImage(m_squareImage);

	m_unitPosition = { 540, 220 };
	m_textureDrawPos.x = m_squareTexture.width / 2;
	m_textureDrawPos.y = m_squareTexture.height / 2;
}

Square::~Square()
{
	UnloadTexture(m_squareTexture);
	UnloadImage(m_squareImage);
}

void Square::Update(float deltaTime)
{
}

void Square::Draw()
{
	DrawTextureWithPivot(m_squareTexture, m_unitPosition, m_textureDrawPos, 0.0f);
}

void Square::DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos(rot * DEG2RAD);
	float sinTheta = sin(rot * DEG2RAD);

	Vector2 rotatedOffset;

	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos + rotatedOffset, rot, 1.0f, WHITE);
}
