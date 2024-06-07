#include "pch.h"
#include "Particle.h"
#include <utils.h>
//placeholder for particles

Particle::Particle() :
	m_Position{},
	m_Radius{float(rand() % 1 + 5)}
{

}
Particle::Particle(const Point2f& position)
	:
	m_Position{ position },
	m_InitialPosition{ position },
	m_Radius{ float(rand() % 1 + 5) }
{

}
Particle::~Particle()
{

}

void Particle::Update(float elapsedSec)
{
	//m_Position.x = m_InitialPosition.x + m_Amplitude * sin(m_Frequency * elapsedSec + m_Phase);
}

void Particle::Draw() const
{
	utils::SetColor(Color4f(1, 1, 1, 1));
	utils::FillEllipse(m_Position, m_Radius, m_Radius);
}

Point2f Particle::GetPosition() const
{
	return m_Position;
}

float Particle::GetRadius() const
{
	return m_Radius;
}