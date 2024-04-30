#include "pch.h"
#include "Particle.h"

Particle::Particle() :
	m_Position{},
	m_Radius{rand() % 10 + 15}
{

}
Particle::Particle(const Point2f& position)
{

}
Particle::~Particle()
{

}

void Particle::Update(float elapsedSec)
{
	
}

void Particle::Draw() const
{

}