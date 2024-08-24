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

	void IncrementScore(); 
	void DecrementScore();

	int GetHearts() const noexcept;
	int GetScore() const noexcept;

	bool IsGameOver() const noexcept;
	void SetGameOver();

private:
	const float m_ScreenWidth;
	const float m_ScreenHeight;

	Texture* m_pScoreTexture;
	Texture* m_pHeartTexture;

	int m_NumHearts;
	const int m_NumMaxHearts;

	int m_Score;

	bool m_IsGameOver;


};

