#pragma once
#include "Texture.h"

class Player
{
public:
	Player(const Point2f& position);
	~Player();
	
	void Update(float elapsedSec);
	void Draw() const;

	Point2f GetPosition() const noexcept;

	float GetWidth() const noexcept;
	float GetHeight() const noexcept;


private:
	Point2f m_Position;
	Texture* m_pCharacter;
};

