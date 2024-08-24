#include "pch.h"
#include "GameUI.h"
GameUI::GameUI(float screenWidth, float screenHeight) :
	m_ScreenWidth(screenWidth),
	m_ScreenHeight(screenHeight),
	m_pHeartTexture{ new Texture("UI/heart.png") },
	m_pScoreTexture{new Texture("0", "UI/font.ttf", 25, Color4f(0, 0, 0, 1))},
	m_NumHearts{ 3 },
	m_NumMaxHearts{5},
	m_Score{0},
	m_IsGameOver{false}
{

}
GameUI::~GameUI()
{
	delete m_pHeartTexture;
	delete m_pScoreTexture;
}

void GameUI::Update(float elapsedSec)
{
	delete m_pScoreTexture;
	m_pScoreTexture = new Texture(std::to_string(m_Score), "UI/font.ttf", 25, Color4f(0, 0, 0, 1));
}
void GameUI::Draw() const
{
	if (!m_IsGameOver)
	{
		for (int i = 0; i < m_NumHearts; i++)
		{
			float marginLeft{ 50 };
			Point2f pos{ 20 + (i * marginLeft), m_ScreenHeight - m_pHeartTexture->GetHeight() - 10 };
			m_pHeartTexture->Draw(pos);
		}

		const Point2f rightUpperCorner{ m_ScreenWidth - m_pScoreTexture->GetWidth() - 10, m_ScreenHeight - m_pScoreTexture->GetHeight() - 10 };
		m_pScoreTexture->Draw(rightUpperCorner);
	}
	else
	{

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



void GameUI::IncrementScore()
{
	++m_Score;
}
void GameUI::DecrementScore()
{
	if (m_Score > 0)
	{
		--m_Score;
	}
}
int GameUI::GetScore() const noexcept
{
	return m_Score;
}
bool GameUI::IsGameOver() const noexcept
{
	return m_IsGameOver;
}
void GameUI::SetGameOver()
{
	m_IsGameOver = true;
}