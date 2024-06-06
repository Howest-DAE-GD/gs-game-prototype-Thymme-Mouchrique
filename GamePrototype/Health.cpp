#include "pch.h"
#include "Health.h"
Health::Health(const Point2f position) :
	m_pTexture{new Texture("Health/health.png")},
	m_Position{position}
{

}
Health::~Health()
{
	delete m_pTexture;
}

void Health::Draw() const
{

	m_pTexture->Draw(m_Position);
}
void Health::Update(float elapedSec)
{

}

float Health::GetWidth() const noexcept
{
	return m_pTexture->GetWidth();
}
float Health::GetHeight() const noexcept
{
	return m_pTexture->GetHeight();
}
Point2f Health::GetPosition() const noexcept
{
	return m_Position;
}