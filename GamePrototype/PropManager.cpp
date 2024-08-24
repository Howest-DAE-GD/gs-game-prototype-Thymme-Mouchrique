#include "pch.h"
#include "PropManager.h"

PropManager::PropManager() :
	m_NutsPath{ "Allergens/easy/nuts.png" },
	m_PollenPath{ "Allergens/easy/pollen.png" },
	m_GrassPath{"Allergens/easy/grass.png"},
	m_TreePath{"Allergens/easy/tree.png"},
	m_MilkPath{ "Allergens/easy/milk.png"},
	m_CheesePath{ "Allergens/easy/cheese.png"},
	m_ButterPath{"Allergens/easy/butter.png"},
	m_CatPath{ "Allergens/easy/cat.png"},
	m_DogPath{"Allergens/easy/dog.png"},
	m_HamsterPath{"Allergens/easy/hamster.png"},
	m_NeedlePath{ "Safe items/needle.png"},
	m_PillPath{ "Safe items/pill.png"},
	m_MedkitPath{ "Safe items/medkit.png"},
	m_ActiveProps{},
	m_Speed{75},
	m_PlayerPos{ 250, 0 },
	m_DiscardedAllergy{},
	m_RndGroup{rand() % 4},
	m_ClickedAllergy{},
	m_ClickedHealth{},
	m_ConsumedFood{},
	m_Score{}
{
	std::cout << std::endl;
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
		if (std::find(m_ActiveAllergies.begin(), m_ActiveAllergies.end(), m_ActiveProps[i]->GetName()) != m_ActiveAllergies.end() && !m_ActiveProps[i]->GetActive())
		{
			m_ActiveProps[i]->SetActive(true);
		}

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

		if (m_ActiveProps[i]->GetPosition().x >= m_PlayerPos.x && m_ActiveProps[i]->GetPosition().x <= m_PlayerPos.x + 25 &&
			m_ActiveProps[i]->GetPosition().y >= m_PlayerPos.y && m_ActiveProps[i]->GetPosition().y <= m_PlayerPos.y + 25)
		{
			if (m_ActiveProps[i]->GetPropType() == PropType::Allergy)
			{
				m_ClickedAllergy = true;
				DeleteProp(i);
			}
			else
			{
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
			m_ActiveProps.push_back(new Prop(m_MedkitPath, "medkit", PropType::Healing, Point2f(rand() % 600, 450)));
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
		if (m_Score > 20 && rand() % 3 == 2)
		{
			int rndHardObjects{ rand() % 4 };

			switch (rndHardObjects)
			{
			case 1:
				m_ActiveProps.push_back(new Prop("Allergens/medium/chocolate.png", "lactose", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 2:
				m_ActiveProps.push_back(new Prop("Allergens/medium/icecream.png", "lactose", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 3:
				m_ActiveProps.push_back(new Prop("Allergens/medium/herbal_tea.png", "floral", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 4:
				m_ActiveProps.push_back(new Prop("Allergens/medium/sweater.png", "pet", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			default:
				break;
			}
		}
		else
		{
			int rnd{ rand() % 12 + 1 };
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
				m_ActiveProps.push_back(new Prop(m_CatPath, "cat", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 5:
				m_ActiveProps.push_back(new Prop(m_CheesePath, "cheese", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 6:
				m_ActiveProps.push_back(new Prop(m_ButterPath, "butter", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 7:
				m_ActiveProps.push_back(new Prop(m_DogPath, "dog", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 8:
				m_ActiveProps.push_back(new Prop(m_HamsterPath, "hamster", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 9:
				m_ActiveProps.push_back(new Prop(m_GrassPath, "grass", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 10:
				m_ActiveProps.push_back(new Prop(m_TreePath, "tree", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 11:
				m_ActiveProps.push_back(new Prop("Allergens/easy/nuts2.png", "nuts", PropType::Allergy, Point2f(rand() % 600, 450)));
				break;
			case 12:
				m_ActiveProps.push_back(new Prop("Allergens/easy/nuts3.png", "nuts", PropType::Allergy, Point2f(rand() % 600, 450)));
			default:
				break;
			}
		}
	}
}

void PropManager::DeleteProp(int idx)
{
	m_ActiveProps.erase(m_ActiveProps.begin() + idx);
}

void PropManager::ChangePropSpeed(float speedToAdd)
{
	m_Speed = speedToAdd;
}

void PropManager::ProcessMouse(const SDL_MouseButtonEvent& e)
{
	
	for (int i = 0; i < m_ActiveProps.size(); i++)
	{

		if (e.x >= m_ActiveProps[i]->GetPosition().x - m_ActiveProps[i]->GetWidth() / 2 && e.x <= m_ActiveProps[i]->GetPosition().x + 60 &&
			e.y >= m_ActiveProps[i]->GetPosition().y - m_ActiveProps[i]->GetWidth() / 2 && e.y <= m_ActiveProps[i]->GetPosition().y + 60)
		{
			if (e.button == SDL_BUTTON_LEFT)
			{
				//consume item
				if (m_ActiveProps[i]->GetPropType() == PropType::Allergy && m_ActiveProps[i]->GetActive())
				{
					//if player consumes allergic item
					m_ClickedAllergy = true;
				}
				else if (m_ActiveProps[i]->GetPropType() == PropType::Healing)
				{
					//if player consumes healing item
					m_ClickedHealth = true;
				}
				
				else if (not m_ActiveProps[i]->GetActive() && m_ActiveProps[i]->GetPropType() == PropType::Allergy)
				{
					//if player consumes item that is fine
					m_ConsumedFood = true;
				}
				DeleteProp(i);
				return;
			}
			if (e.button == SDL_BUTTON_RIGHT)
			{
				//discard item
				if (m_ActiveProps[i]->GetPropType() == PropType::Allergy && m_ActiveProps[i]->GetActive())
				{
					m_DiscardedAllergy = true;
				}
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
	if (m_ClickedHealth)
	{
		m_ClickedHealth = false;
		return true;
	}
	return false;
}
bool PropManager::HasClickedAllergy()
{
	if (m_ClickedAllergy)
	{
		m_ClickedAllergy = false;
		return true;
	}
	return false;
}
bool PropManager::HasDiscardedAllergy()
{
	if (m_DiscardedAllergy)
	{
		m_DiscardedAllergy = false;
		return true;
	}
	return false;
}
bool PropManager::HasConsumedFood()
{
	if (m_ConsumedFood)
	{
		m_ConsumedFood = false;
		return true;
	}
	return false;
}

void PropManager::UpdateScore(int score)
{
	m_Score = score;
}

void PropManager::AddRandomAllergy()
{
	const std::vector<std::string> possibleAllergies = {
		"nuts", "pollen", "grass", "tree", "milk", "cheese", "butter", "cat", "dog", "hamster"
	};

	if (m_ActiveAllergies.size() < possibleAllergies.size())
	{
		int rnd{int( rand() % possibleAllergies.size()) };
		m_ActiveAllergies.push_back(possibleAllergies[rnd]);

		std::cout << "New Allergy Activated: " << possibleAllergies[rnd] << std::endl;
	}


}