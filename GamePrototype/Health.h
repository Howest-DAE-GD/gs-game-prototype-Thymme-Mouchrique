#pragma once
#include <iostream>
#include "Texture.h"
class Health
{
public:
	Health(const Point2f position);
	~Health();

	void Draw() const;
	void Update(float elapedSec);

	float GetWidth() const noexcept;
	float GetHeight() const noexcept;
	Point2f GetPosition() const noexcept;

private:
	Point2f m_Position;
	Texture* m_pTexture;
};

