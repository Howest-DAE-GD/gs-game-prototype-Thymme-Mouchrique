#include "pch.h"
#include "hud.h"
#include <sstream>
#include <iomanip>

hud::hud(const Point2f& screenDimensions) :
	hud(screenDimensions.x, screenDimensions.y)
{

}
hud::hud(float screenWidth, float screenHeight):
	m_ScreenWidth{screenWidth},
	m_ScreenHeight{ screenHeight },
	m_Score{1},
	m_ScoreTexture{ new Texture(" ", "font/font.ttf", 25, Color4f(1, 1, 1, 1)) },
	m_TimerTexture{new Texture(" ", "font/font.ttf", 25, Color4f(1, 1, 1, 1))},
	m_pGameOverTexture{new Texture("hud/gameover.png")},
	m_GameOver{}
{

}

hud::~hud()
{
	delete m_ScoreTexture;
	delete m_TimerTexture;
	delete m_pGameOverTexture;
}

void hud::Draw() const
{
	//score 
	const Point2f scoreTexturePosition{ m_ScreenWidth - m_ScoreTexture->GetWidth() - 5, m_ScreenHeight - m_ScoreTexture->GetHeight()};
	m_ScoreTexture->Draw(scoreTexturePosition);

	//health bar 
	const Rectf healthBarPosition{ 10, m_ScreenHeight - 30, 200, 20 };
	utils::DrawRect(healthBarPosition);

	utils::SetColor(Color4f{ 1, 0, 0, 1 });
	utils::FillRect(Rectf(healthBarPosition.left, healthBarPosition.bottom, m_PlayerHealth * 2, healthBarPosition.height));

	//timer
	//const Point2f timerTexturePosition(m_ScreenWidth / 2 - m_TimerTexture->GetWidth() / 2, m_ScreenHeight - 100);
	//m_TimerTexture->Draw(timerTexturePosition);
	if (m_GameOver)
	{
		const Point2f centerPos{ m_ScreenWidth / 2 - m_pGameOverTexture->GetWidth() / 2, m_ScreenHeight / 2 - m_pGameOverTexture->GetHeight() / 2 };
		m_pGameOverTexture->Draw(centerPos);
	}
}
void hud::Update(float elapsedSec)
{
	m_Score += 5 * elapsedSec;
	UpdateHealthbar();
	UpdateScoreTexture();
	UpdateTimer(elapsedSec);
}

void hud::UpdateHealthbar()
{

}

void hud::UpdateScoreTexture()
{
	if (!m_GameOver)
	{
		delete m_ScoreTexture;
		m_ScoreTexture = new Texture(std::to_string(int(m_Score)), "font/font.ttf", 25, Color4f(1, 1, 1, 1));

	}
}

void hud::SetHealth(const int playerHealth)
{
	m_PlayerHealth = playerHealth;
}

void hud::UpdateTimer(float elapsedSec)
{
	m_Timer += elapsedSec;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << m_Timer;

	delete m_TimerTexture;
	m_TimerTexture = new Texture(stream.str(), "font/font.ttf", 25, Color4f(1, 1, 1, 1));
}

float hud::GetScore() const noexcept
{
	return m_Score;
}

void hud::SetDead()
{
	m_GameOver = true;
}
