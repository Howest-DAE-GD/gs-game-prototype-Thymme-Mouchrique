#pragma once
#include "Texture.h"
#include "vector"
#include "iostream"
#include "Prop.h"
#include "GameUI.h"
#include "SoundEffect.h"
class PropManager
{
public:
	explicit PropManager();
	~PropManager();

	void Update(float elapsedSec);
	void Draw() const;
	
	void AddProp(bool healingItem);
	void DeleteProp(int idx);

	//base speed is 75
	void AddPropSpeed(float speedToAdd);

	void ProcessMouse(const SDL_MouseButtonEvent& e);
	
	int GetPropsNumber() const noexcept;
	bool HasClickedHealth();
	bool HasClickedAllergy();
	bool HasDiscardedAllergy();
	bool HasConsumedFood();

	float GetSpeed() const noexcept;
	void UpdateScore(int score);
	void AddRandomAllergy();

	void LinkGameUI(GameUI* gameUI);

private:
	//healing
	float m_Speed;
	GameUI* m_GameUI;
	std::vector<Prop*> m_ActiveProps;
	std::vector<std::string> m_ActiveAllergies;

	//nuts
	std::string m_NutsPath;

	//pollen
	std::string m_PollenPath;
	std::string m_GrassPath;
	std::string m_TreePath;

	//lactose
	std::string m_MilkPath;
	std::string m_CheesePath;
	std::string m_ButterPath;

	//pet allergy
	std::string m_CatPath;
	std::string m_DogPath;
	std::string m_HamsterPath;

	//healing items
	std::string m_PillPath;
	std::string m_NeedlePath;
	std::string m_MedkitPath;

	//since player pos is fixed
	const Point2f m_PlayerPos;

	bool m_ClickedHealth;
	bool m_ClickedAllergy;
	bool m_DiscardedAllergy;
	bool m_ConsumedFood;

	//0: lactose intollerant, 1: Pet allergy, 2: Floral sensitivity, 3: nut allergy
	int m_RndGroup;

	int m_Score;

	SoundEffect* m_Click;
	SoundEffect* m_Buzz;
};

