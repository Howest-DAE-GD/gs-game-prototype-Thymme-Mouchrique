#include "pch.h"
#include "hud.h"

hud::hud(const Point2f& screenDimensions) :
	hud(screenDimensions.x, screenDimensions.y)
{

}
hud::hud(float screenWidth, float screenHeight):
	m_ScreenWidth{screenWidth},
	m_ScreenHeight{ screenHeight },
	m_Score{1},
	m_ScoreTexture{ new Texture(" ", "font/font.ttf", 100, Color4f(1, 1, 1, 1)) }
{

}

hud::~hud()
{
	delete m_ScoreTexture;
}

void hud::Draw() const
{
	const Point2f scoreTexturePosition{ m_ScreenWidth - m_ScoreTexture->GetWidth() - 5, m_ScreenHeight - m_ScoreTexture->GetHeight()};
	m_ScoreTexture->Draw(scoreTexturePosition);
}
void hud::Update(float elapsedSec)
{



	UpdateScoreTexture();
}

void hud::UpdateScoreTexture()
{
	delete m_ScoreTexture;
	m_ScoreTexture = new Texture(std::to_string(m_Score), "font/font.ttf", 100, Color4f(1, 1, 1, 1));
}
