#include "pch.h"
#include "GameUI.h"
GameUI::GameUI(float screenWidth, float screenHeight) :
	m_ScreenWidth(screenWidth),
	m_ScreenHeight(screenHeight),
	m_pHeartTexture{ new Texture("UI/heart.png") },
	m_pScoreTexture{new Texture("0", "UI/font.ttf", 25, Color4f(0, 0, 0, 1))},
	m_NumHearts{ 3 },
	m_NumMaxHearts{3},
	m_Score{0},
	m_IsGameOver{false},
	m_IsShowingAllergy{false},
	m_TimeElapsedSinceStartShowingAllergy{},
	m_showAllergyName{},
	m_pNewAllergyTexture{},
	m_pGameOverTexture{new Texture("ui/gameover.png")},
	m_ShowingAllergyMaxTimeShowing{5}
{

}
GameUI::~GameUI()
{
	delete m_pHeartTexture;
	delete m_pScoreTexture;
	delete m_pNewAllergyTexture;
	delete m_pGameOverTexture;
}

void GameUI::Update(float elapsedSec)
{
	delete m_pScoreTexture;
	m_pScoreTexture = new Texture(std::to_string(m_Score), "UI/font.ttf", 25, Color4f(0, 0, 0, 1));

	if (m_IsShowingAllergy)
	{
		m_TimeElapsedSinceStartShowingAllergy += elapsedSec;
		if (m_TimeElapsedSinceStartShowingAllergy >= 5)
		{
			m_TimeElapsedSinceStartShowingAllergy = 0;
			m_IsShowingAllergy = false;
		}
	}
	if (m_NumHearts == 0)
	{
		SetGameOver();
	}
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
		
		if (m_IsShowingAllergy)
		{
			const Point2f center{ m_ScreenWidth / 2 - m_pNewAllergyTexture->GetWidth() / 2, m_ScreenHeight / 2 - m_pNewAllergyTexture->GetHeight() / 2 };
			m_pNewAllergyTexture->Draw(center);
		}
		
	}
	else
	{
		const Point2f center{ m_ScreenWidth / 2 - m_pGameOverTexture->GetWidth() / 2, m_ScreenHeight / 2 - m_pGameOverTexture->GetHeight() / 2 };
		m_pGameOverTexture->Draw(center);
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
	std::cout << std::endl << "Game over! press ENTER to restart" << std::endl;
	std::cout << "You finished with a score of " << m_Score << "! " << std::endl;
	m_IsGameOver = true;
}

void GameUI::ShowNewAllergy(const std::string allergyName)
{
	m_showAllergyName = allergyName;
	delete m_pNewAllergyTexture;
	m_pNewAllergyTexture = new Texture("new allergy: " + allergyName, "UI/font.ttf", 40, Color4f{0.f, 0.f, 0.f, 1.f});
	m_IsShowingAllergy = true;
}
bool GameUI::IsShowingAllergy()
{
	return m_IsShowingAllergy;
}
void GameUI::ChangeShowingTime(float NumToAdd)
{
	m_ShowingAllergyMaxTimeShowing += NumToAdd;
}
float GameUI::GetShowingTime() const noexcept
{
	return m_ShowingAllergyMaxTimeShowing;
}