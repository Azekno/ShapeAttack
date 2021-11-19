#pragma once
#include "MathFunctions.h"

class Shape
{
public:
	Shape();
	virtual ~Shape();

	virtual void Update(float deltaTime);
	virtual void Draw();

	//Movement Functions
	void SetPosition(Vector2 position) { m_unitPosition = position; }
	Vector2 GetPosition() { return m_unitPosition; }
	void SetVelocity(Vector2 velocity) { m_unitVelocity = velocity; }
	Vector2 GetVelocity() { return m_unitVelocity; }

	void DrawUnitDetectionRange();
	bool WithinRange(Shape* target);
	

	Shape* m_targetUnit = nullptr;
	Vector2 m_unitPosition;
	Vector2 m_unitVelocity;
	Vector2 m_textureDrawPos;

	//Values that will represent all units in the game
	float m_health;
	float m_damage;
	float m_maxUnitSpeed;
	float m_attackRange;
	float m_detectionRange;

	float m_deltaTime;
};
