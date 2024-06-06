#pragma once
#include <iostream>
#include "Particle.h"
#include <vector>
class ParticleManager
{
public:
	ParticleManager();
	~ParticleManager();
	void Update(float elapsedSec);
	void Draw() const;
	void AddParticle(const Point2f& position);
	void AddParticle(Particle* particle);
	void RemoveParticle(int idx);
	std::vector<Point2f> GetPositions();
	float GetRadius(int idx);
private:
	std::vector<Particle*> m_Particles;
};