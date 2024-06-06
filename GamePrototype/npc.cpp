#include "pch.h"
#include "npc.h"

npc::npc(const Point2f& position):
	m_Position{position},
	m_pNpcTexture{new Texture("Health/npc.png")}

{

}
npc::~npc()
{
	delete m_pNpcTexture;
}

void npc::Draw() const
{
	m_pNpcTexture->Draw(m_Position);
}
void npc::Update(float elapsedSec)
{

}

Point2f npc::GetPosition() const noexcept
{
	return m_Position;
}

float npc::GetWidth() const noexcept
{
	return m_pNpcTexture->GetWidth();
}
float npc::GetHeight() const noexcept
{
	return m_pNpcTexture->GetHeight();
}