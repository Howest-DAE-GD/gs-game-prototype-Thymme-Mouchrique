#pragma once
#include "Texture.h"
class Tree final
{
public:
	Tree(const Point2f& position);
	~Tree();

	void Draw() const;
	void Update(float elapsedSec);

	float GetWidth() const noexcept;
	float GetHeight() const noexcept;
	Point2f GetPosition() const noexcept;
private:
	Point2f m_Position;
	Texture* m_pTreeTexture;
	const float m_Scale;
};

