#include "pch.h"
#include "hud.h"

hud::hud(const Point2f& screenDimensions) :
	hud(screenDimensions.x, screenDimensions.y)
{

}
hud::hud(float screenWidth, float screenHeight):
	m_ScreenWidth{screenWidth},
	m_ScreenHeight{ screenHeight },
	m_Score{},
	m_ScoreTexture{new Texture("test", "font/font.ttf", 100, Color4f(1, 1, 1, 1))}
{

}

hud::~hud()
{
	delete m_ScoreTexture;
}

void hud::Draw() const
{
	const Point2f scoreTexturePosition{ m_ScreenWidth - m_ScoreTexture->GetWidth() - 5, m_ScreenHeight - m_ScoreTexture->GetHeight()};
	std::cout << scoreTexturePosition.x << std::endl;
	m_ScoreTexture->Draw(scoreTexturePosition);
}
void hud::Update()
{

}