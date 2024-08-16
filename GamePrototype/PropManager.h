#pragma once
#include "Texture.h"
#include "vector"
#include "iostream"
#include "Prop.h"

class PropManager
{
public:
	explicit PropManager();
	~PropManager();

	void Update(float elapsedSec);
	void Draw() const;
	
	void AddProp(bool healingItem);
	void DeleteProp(int idx);

	void ChangeSpeed(float speedToAdd);


	void ProcessMouse(const SDL_MouseButtonEvent& e);
	
	int GetPropsNumber() const noexcept;
	bool HasClickedHealth();
	bool HasClickedAllergy();

private:
	//allergys
	Texture* m_pNuts;
	Texture* m_pCat;
	Texture* m_pPollen;
	Texture* m_pMilk;

	//healing
	Texture* m_pNeedle;
	Texture* m_pPill;
	Texture* m_pMedkit;
	float m_Speed;

	//i know this approach is horrible lol
	//std::vector<Texture*> m_ActiveProps;
	//std::vector<Point2f> m_Positions;
	//std::vector<PropType> m_PropTypes;

	//new approach
	std::vector<Prop*> m_ActiveProps;
	std::string m_NutsPath;
	std::string m_PollenPath;
	std::string m_MilkPath;
	std::string m_CatPath;
	std::string m_PillPath;
	std::string m_NeedlePath;
	std::string m_MedkitPath;



	//since player pos is fixed
	const Point2f m_PlayerPos;

	bool clickedHealth;
	bool clickedAllergy;

};

