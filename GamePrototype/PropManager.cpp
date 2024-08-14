#include "pch.h"
#include "PropManager.h"

PropManager::PropManager():
	m_pNuts{new Texture("Allergens/nuts.png")},
	m_pPollen{new Texture("Allergens/pollen.png")},
	m_pMilk{new Texture("Allergens/milk.png")},
	m_Positions{},
	m_ActiveProps{},


{
	
}
PropManager::~PropManager()
{
	delete m_pNuts;
	delete m_pPollen;
	delete m_pMilk;
}
void PropManager::Update(float elapsedSec)
{

}
void PropManager::Draw() const
{
	for (int i = 0; i < m_ActiveProps.size(); i++)
	{
		m_ActiveProps[i]->Draw(m_Positions[i]);
	}
}



void PropManager::AddProp()
{
	
}

void PropManager::DeleteProp(int idx)
{

}

void PropManager::ChangeSpeed()
{

}

void PropManager::ProcessMouse(const SDL_MouseButtonEvent& e)
{

}