#pragma once
#include "texture.h"
class GameUI
{
public:
	GameUI(float screenWidth, float screenHeight);
	~GameUI();

	void Update(float elapsedSec);
	void Draw() const;
	
	void IncrementHeart();
	void DecrementHeart();
	int GetHearts() const noexcept;
private:
	const float m_ScreenWidth;
	const float m_ScreenHeight;
	Texture* m_pScore;
	Texture* m_pHeartTexture;

	int m_NumHearts;
	const int m_NumMaxHearts;
};

