#include "pch.h"
#include "ParticleManager.h"


ParticleManager::ParticleManager()
{

}
ParticleManager::~ParticleManager()
{
	for (Particle* par : m_Particles)
	{
		delete par;
	}
}

void ParticleManager::Update(float elapsedSec)
{
	for (Particle* par : m_Particles)
	{
		par->Update(elapsedSec);
	}
}
void ParticleManager::Draw() const
{
	for (Particle* par : m_Particles)
	{
		par->Draw();
	}
}
void ParticleManager::AddParticle(const Point2f& position)
{
	AddParticle(new Particle(position));
}
void ParticleManager::AddParticle(Particle* particle)
{
	m_Particles.push_back(particle);
}
void ParticleManager::RemoveParticle(int idx)
{
	delete m_Particles[idx];
	m_Particles.erase(m_Particles.begin() + idx);
}

std::vector<Point2f> ParticleManager::GetPositions()
{
	std::vector<Point2f> positions{};
	for (Particle* par : m_Particles)
	{
		positions.push_back(par->GetPosition());
	}

	return positions;
}

float ParticleManager::GetRadius(int idx)
{
	return m_Particles[idx]->GetRadius();
}