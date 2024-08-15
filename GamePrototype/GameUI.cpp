#include "pch.h"
#include "GameUI.h"
GameUI::GameUI(float screenWidth, float screenHeight) :
	m_ScreenWidth(screenWidth),
	m_ScreenHeight(screenHeight),
	m_pHeartTexture{ new Texture("UI/heart.png") },
	m_NumHearts{ 3 },
	m_NumMaxHearts{5}

{

}

GameUI::~GameUI()
{
	delete m_pHeartTexture;
}

void GameUI::Update(float elapsedSec)
{

}
void GameUI::Draw() const
{
	for (int i = 0; i < m_NumHearts; i++)
	{
		float marginLeft{50};
		Point2f pos{ 20 + (i * marginLeft), m_ScreenHeight - m_pHeartTexture->GetHeight() - 10};
		m_pHeartTexture->Draw(pos);
	}
}

void GameUI::IncrementHeart()
{
	if (m_NumHearts < m_NumMaxHearts)
	{
		++m_NumHearts;
	}
}
void GameUI::DecrementHeart()
{
	if (m_NumHearts > 0)
	{
		--m_NumHearts;
	}
}
int GameUI::GetHearts() const noexcept
{
	return m_NumHearts;
}
