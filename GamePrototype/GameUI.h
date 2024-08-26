#pragma once
#include "texture.h"
#include "iostream"
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

	void ShowNewAllergy(const std::string allergyName);
	bool IsShowingAllergy();

	void ChangeShowingTime(float NumToAdd);
	float GetShowingTime() const noexcept;

private:
	const float m_ScreenWidth;
	const float m_ScreenHeight;

	Texture* m_pScoreTexture;
	Texture* m_pHeartTexture;
	Texture* m_pNewAllergyTexture;
	Texture* m_pGameOverTexture;


	int m_NumHearts;
	const int m_NumMaxHearts;

	int m_Score;

	bool m_IsGameOver;

	bool m_IsShowingAllergy;
	float m_TimeElapsedSinceStartShowingAllergy;
	float m_ShowingAllergyMaxTimeShowing;
	
	std::string m_showAllergyName;
};

