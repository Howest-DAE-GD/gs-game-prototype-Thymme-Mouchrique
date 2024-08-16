#include "pch.h"
#include "PropManager.h"

PropManager::PropManager() :
	m_NutsPath{ "Allergens/nuts.png" },
	m_PollenPath{ "Allergens/pollen.png" },
	m_MilkPath{ "Allergens/milk.png"},
	m_CatPath{ "Allergens/cat.png"},
	m_NeedlePath{ "Safe items/needle.png"},
	m_PillPath{ "Safe items/pill.png"},
	m_MedkitPath{ "Safe items/medkit.png"},
	m_ActiveProps{},
	m_Speed{75},
	m_PlayerPos{ 250, 0 }
{
	
}
PropManager::~PropManager()
{
	for (Prop* prop : m_ActiveProps)
	{
		delete prop;
	}
	m_ActiveProps.clear();
}
void PropManager::Update(float elapsedSec)
{
	for (int i = 0; i < m_ActiveProps.size(); i++)
	{
		// Calculate the direction
		float directionX = m_PlayerPos.x - m_ActiveProps[i]->GetPosition().x;
		float directionY = m_PlayerPos.y - m_ActiveProps[i]->GetPosition().y;
		// Normalize the direction vector
		float distance = std::sqrt(directionX * directionX + directionY * directionY);
		directionX /= distance;
		directionY /= distance;
		Point2f newPos{m_ActiveProps[i]->GetPosition()};

		// Update the allergy position
		newPos.x += directionX * m_Speed * elapsedSec;
		newPos.y += directionY * m_Speed * elapsedSec;

		m_ActiveProps[i]->SetPosition(newPos);

		if (m_ActiveProps[i]->GetPropType() == PropType::Allergy)
		{
			if (m_ActiveProps[i]->GetPosition().x >= m_PlayerPos.x && m_ActiveProps[i]->GetPosition().x <= m_PlayerPos.x + 25 &&
				m_ActiveProps[i]->GetPosition().y >= m_PlayerPos.y && m_ActiveProps[i]->GetPosition().y <= m_PlayerPos.y + 25)
			{
				clickedAllergy = true;
				DeleteProp(i);
			}
		}
	}
}
void PropManager::Draw() const
{
	for (Prop* prop : m_ActiveProps)
	{
		prop->Draw();
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
			m_ActiveProps.push_back( new Prop(m_MedkitPath, "medkit", PropType::Healing, Point2f(rand() % 600, 450)));
			break;
		case 2:
			m_ActiveProps.push_back(new Prop(m_PillPath, "pill", PropType::Healing, Point2f(rand() % 600, 450)));
			break;
		case 3:
			m_ActiveProps.push_back(new Prop(m_NeedlePath, "needle", PropType::Healing, Point2f(rand() % 600, 450)));
			break;
		default:
			break;
		}
	}
	else
	{
		int rnd{ rand() % 5 + 1 };

		switch (rnd)
		{
		case 1:
			m_ActiveProps.push_back(new Prop(m_MilkPath, "milk", PropType::Allergy, Point2f(rand() % 600, 450)));
			break;
		case 2:
			m_ActiveProps.push_back(new Prop(m_PollenPath, "pollen", PropType::Allergy, Point2f(rand() % 600, 450)));
			break;
		case 3:
			m_ActiveProps.push_back(new Prop(m_NutsPath, "nuts", PropType::Allergy, Point2f(rand() % 600, 450)));
			break;
		case 4: 
			m_ActiveProps.push_back(new Prop(m_CatPath, "nuts", PropType::Allergy, Point2f(rand() % 600, 450)));
		default:
			break;
		}
	
	}
}

void PropManager::DeleteProp(int idx)
{
	m_ActiveProps.erase(m_ActiveProps.begin() + idx);
}

void PropManager::ChangeSpeed(float speedToAdd)
{

}

void PropManager::ProcessMouse(const SDL_MouseButtonEvent& e)
{
	
	for (int i = 0; i < m_ActiveProps.size(); i++)
	{
		if (e.x >= m_ActiveProps[i]->GetPosition().x && e.x <= m_ActiveProps[i]->GetPosition().x + m_ActiveProps[i]->GetWidth() &&
			e.y >= m_ActiveProps[i]->GetPosition().y && e.y <= m_ActiveProps[i]->GetPosition().y + m_ActiveProps[i]->GetHeight())
		{
			if (e.button == SDL_BUTTON_LEFT)
			{
				//consume item
				if (m_ActiveProps[i]->GetPropType() == PropType::Allergy)
				{
					clickedAllergy = true;
				}
				else if (m_ActiveProps[i]->GetPropType() == PropType::Healing)
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