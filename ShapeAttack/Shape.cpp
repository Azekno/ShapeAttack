#include "Shape.h"

Shape::Shape()
{
	m_health = 0;
	m_damage = 0;
	m_maxUnitSpeed = 0;
	m_attackRange = 0;
	m_detectionRange = 0;

	//m_unitPosition = { 0, 0 };
	m_unitVelocity = { 0, 0 };
}

Shape::~Shape()
{
}

void Shape::Update(float deltaTime)
{
}

void Shape::Draw()
{
}

void Shape::DrawUnitDetectionRange()
{
}

bool Shape::WithinRange(Shape* target)
{
	return false;
}
