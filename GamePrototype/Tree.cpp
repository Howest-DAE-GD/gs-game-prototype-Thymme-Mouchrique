#include "pch.h"
#include "Tree.h"
#include <iostream>
Tree::Tree(const Point2f& position):
	m_Position{position},
	m_pTreeTexture{},
	m_Scale{4}

{
	int random{ std::rand() % 4 + 1 };
	switch (random)
	{
	case 1:
		m_pTreeTexture = new Texture("World/trees/1.png");
		break;
	case 2:
		m_pTreeTexture = new Texture("World/trees/2.png");
		break;
	case 3:
		m_pTreeTexture = new Texture("World/trees/3.png");
		break;
	case 4:
		m_pTreeTexture = new Texture("World/trees/4.png");
		break;
	default:

		break;
	}
}
Tree::~Tree()
{
	delete m_pTreeTexture;
}

void Tree::Draw() const
{
	const Rectf test(m_Position.x, m_Position.y, m_pTreeTexture->GetWidth() / m_Scale, m_pTreeTexture->GetHeight() / m_Scale);
	m_pTreeTexture->Draw(test);
}
void Tree::Update(float elapsedSec)
{

}

float Tree::GetWidth() const noexcept
{
	return m_pTreeTexture->GetWidth() / m_Scale;
}
float Tree::GetHeight() const noexcept
{
	return m_pTreeTexture->GetHeight() / m_Scale;
}

Point2f Tree::GetPosition() const noexcept
{
	return m_Position;
}