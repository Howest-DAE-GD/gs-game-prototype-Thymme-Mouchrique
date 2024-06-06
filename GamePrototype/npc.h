#pragma once
#include <iostream>
#include "Texture.h"
class npc
{
public:
	explicit npc(const Point2f& position);
	~npc();

	void Draw() const;
	void Update(float elapsedSec);

	Point2f GetPosition() const noexcept;

	float GetWidth() const noexcept;
	float GetHeight() const noexcept;
public:
	const Point2f m_Position;
	Texture* m_pNpcTexture;
};

