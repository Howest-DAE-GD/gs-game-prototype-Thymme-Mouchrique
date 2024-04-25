#pragma once
#include "texture.h"
#include <iostream>
class hud
{
public:
	explicit hud(const Point2f& screenDimensions);
	explicit hud(float screenWidth, float screenHeight);
	~hud();

	void Draw() const;
	void Update();
private:
	float m_ScreenWidth;
	float m_ScreenHeight;

	//TTF_Font m_pFont;
	Texture* m_ScoreTexture;
	int m_Score;
};



