#include "pch.h"
#include "NpcHealthManager.h"
NpcHealthManager::NpcHealthManager():
	m_Npcs{},
	m_HealthPackages{}
{

}
NpcHealthManager::~NpcHealthManager()
{
	for (npc* npc : m_Npcs)
	{
		delete npc;
	}
	for (Health* health : m_HealthPackages)
	{
		delete health;
	}
}

void NpcHealthManager::Draw() const
{
	for (npc* npc : m_Npcs)
	{
		npc->Draw();
	}
	for (Health* health : m_HealthPackages)
	{
		health->Draw();
	}
}
void NpcHealthManager::Update(float elapsedSec)
{
	for (npc* npc : m_Npcs)
	{
		npc->Update(elapsedSec);
	}
	for (Health* health : m_HealthPackages)
	{
		health->Update(elapsedSec);
	}
}

void NpcHealthManager::Add(const Point2f& position)
{
	m_Npcs.push_back(new npc(position));
	m_HealthPackages.push_back(new Health(Point2f(position.x + 20, position.y + 50)));
}
void NpcHealthManager::RemoveHealthPack(const int idx)
{
	delete m_HealthPackages[idx];
	m_HealthPackages.erase(m_HealthPackages.begin() + idx);

}
void NpcHealthManager::Remove(const int idx)
{
	delete m_HealthPackages[idx];
	m_HealthPackages.erase(m_HealthPackages.begin() + idx);

	delete m_Npcs[idx];
	m_Npcs.erase(m_Npcs.begin() + idx);
}

Point2f NpcHealthManager::GetPosition(const int idx) const noexcept
{
	return m_Npcs[idx]->GetPosition();
}
float NpcHealthManager::GetWidth(const int idx) const noexcept
{
	return m_Npcs[idx]->GetWidth();

}
float NpcHealthManager::GetHeight(const int idx) const noexcept
{
	return m_Npcs[idx]->GetHeight();
}

int NpcHealthManager::GetSize() const noexcept
{
	return m_Npcs.size(); 
}