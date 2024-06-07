#pragma once
#include "texture.h"
#include <utils.h>
#include <iostream>
class hud
{
public:
	explicit hud(const Point2f& screenDimensions);
	explicit hud(float screenWidth, float screenHeight);
	~hud();

	void Draw() const;
	void Update(float elapsedSec);
	void SetHealth(const int playerHealth);
	float GetScore() const noexcept;
	void SetDead();
private:
	void UpdateScoreTexture();
	void UpdateHealthbar();
	void UpdateTimer(float elapsedSec);
	float m_ScreenWidth;
	float m_ScreenHeight;

	//TTF_Font m_pFont;
	Texture* m_ScoreTexture;
	Texture* m_TimerTexture;
	Texture* m_pGameOverTexture;
	float m_Score;
	int m_PlayerHealth;
	float m_Timer;
	bool m_GameOver;
};



