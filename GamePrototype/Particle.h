#pragma once
#include <iostream>
class Particle
{
public:
	Particle();
	Particle(const Point2f& position);
	~Particle();

	void Draw() const;
	void Update(float elapsedSec);
	Point2f GetPosition() const;
	float GetRadius() const;
private:
	Point2f m_Position;
	Point2f m_InitialPosition;
	const float m_Radius;
	float m_Frequency; // Random frequency between 1 and 5
	float m_Amplitude;
	float m_Phase;
};

