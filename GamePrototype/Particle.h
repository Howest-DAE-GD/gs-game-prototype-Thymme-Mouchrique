#pragma once
class Particle
{
public:
	Particle();
	Particle(const Point2f& position);
	~Particle();

	void Draw() const;
	void Update(float elapsedSec);

private:
	Point2f m_Position;
	const float m_Radius;
};

