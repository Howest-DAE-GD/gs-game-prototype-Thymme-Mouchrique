#include "pch.h"
#include "PropManager.h"

PropManager::PropManager() :
	m_pNuts{ new Texture("Allergens/nuts.png") },
	m_pPollen{ new Texture("Allergens/pollen.png") },
	m_pMilk{ new Texture("Allergens/milk.png") },
	m_pCat{new Texture("Allergens/cat.png")},
	m_pNeedle{ new Texture("Safe items/needle.png") },
	m_pPill{ new Texture("Safe items/pill.png") },
	m_pMedkit{new Texture("Safe items/medkit.png")},
	m_Positions{},
	m_ActiveProps{},
	m_PropTypes{},
	m_Speed{75},
	m_PlayerPos{ 250, 0 }
{
	
}
PropManager::~PropManager()
{
	m_ActiveProps.clear();
	m_Positions.clear();
	m_PropTypes.clear();

	delete m_pNuts;
	delete m_pNeedle;
	delete m_pPollen;
	delete m_pMilk;
	delete m_pPill;
	delete m_pMedkit;
	delete m_pCat;
}
void PropManager::Update(float elapsedSec)
{
	for (Point2f& pos : m_Positions)
	{
		// Calculate the direction
		float directionX = m_PlayerPos.x - pos.x;
		float directionY = m_PlayerPos.y - pos.y;

		// Normalize the direction vector
		float distance = std::sqrt(directionX * directionX + directionY * directionY);
		directionX /= distance;
		directionY /= distance;

		// Update the allergy position
		pos.x += directionX * m_Speed * elapsedSec;
		pos.y += directionY * m_Speed * elapsedSec;
	}
}
void PropManager::Draw() const
{
	for (int i = 0; i < m_ActiveProps.size(); i++)
	{
		m_ActiveProps[i]->Draw(m_Positions[i]);
	}
}

void PropManager::AddProp(bool healingItem)
{
	if (healingItem)
	{
		int rnd{ rand() % 3 + 1 };

		switch (rnd)
		{
		case 1:
			m_ActiveProps.push_back(m_pMedkit);
			break;
		case 2:
			m_ActiveProps.push_back(m_pPill);
			break;
		case 3:
			m_ActiveProps.push_back(m_pNeedle);
			break;
		default:
			break;
		}
		m_Positions.push_back(Point2f(rand() % 600, 450));
		m_PropTypes.push_back(PropType::Healing);
	}
	else
	{
		int rnd{ rand() % 4 + 1 };

		switch (rnd)
		{
		case 1:
			m_ActiveProps.push_back(m_pMilk);
			break;
		case 2:
			m_ActiveProps.push_back(m_pPollen);
			break;
		case 3:
			m_ActiveProps.push_back(m_pNuts);
			break;
		default:
			break;
		}
		m_Positions.push_back(Point2f(rand() % 600, 450));
		m_PropTypes.push_back(PropType::Allergy);
	}
}

void PropManager::DeleteProp(int idx)
{
	m_ActiveProps.erase(m_ActiveProps.begin() + idx);
	m_PropTypes.erase(m_PropTypes.begin() + idx);
	m_Positions.erase(m_Positions.begin() + idx);
}

void PropManager::ChangeSpeed(float speedToAdd)
{

}

void PropManager::ProcessMouse(const SDL_MouseButtonEvent& e)
{
	
	for (int i = 0; i < m_ActiveProps.size(); i++)
	{
		if (e.x >= m_Positions[i].x && e.x <= m_Positions[i].x + m_ActiveProps[i]->GetWidth() &&
			e.y >= m_Positions[i].y && e.y <= m_Positions[i].y + m_ActiveProps[i]->GetHeight())
		{
			if (e.button == SDL_BUTTON_LEFT)
			{
				//consume item
				if (m_PropTypes[i] == PropType::Allergy)
				{
					clickedAllergy = true;
				}
				else if (m_PropTypes[i] == PropType::Healing)
				{
					clickedHealth = true;
				}
				DeleteProp(i);
				return;
			}
			if (e.button == SDL_BUTTON_RIGHT)
			{
				//discard item
				DeleteProp(i);
				return;
			}
		}
	}
}

int PropManager::GetPropsNumber() const noexcept
{
	return m_ActiveProps.size();
}

bool PropManager::HasClickedHealth()
{
	if (clickedHealth)
	{
		clickedHealth = false;
		return true;
	}
	return false;
}
bool PropManager::HasClickedAllergy()
{
	if (clickedAllergy)
	{
		clickedAllergy = false;
		return true;
	}
	return false;
}