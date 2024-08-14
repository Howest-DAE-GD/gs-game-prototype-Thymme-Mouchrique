#pragma once
#include "Texture.h"
#include "vector"
class PropManager
{
public:
	explicit PropManager();
	~PropManager();

	void Update(float elapsedSec);
	void Draw() const;
	
	void AddProp();
	void DeleteProp(int idx);

	void ChangeSpeed();


	void ProcessMouse(const SDL_MouseButtonEvent& e);
	
private:
	//alllergys
	Texture* m_pNuts;
	//Texture* m_pCatHair;
	Texture* m_pPollen;
	Texture* m_pMilk;

	//healing
	Texture* m_pNeedle;

	float m_Speed;

	//i know this approach is horrible lol
	std::vector<Texture*> m_ActiveProps;
	std::vector<Point2f> m_Positions;

};

