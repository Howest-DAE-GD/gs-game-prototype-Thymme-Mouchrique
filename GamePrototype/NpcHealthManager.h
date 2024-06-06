#pragma once
#include "Health.h"
#include "npc.h"
#include <vector>
#include <iostream>
class NpcHealthManager
{
public:
	NpcHealthManager();
	~NpcHealthManager();

	void Draw() const;
	void Update(float elapsedSec);

	void Add(const Point2f& position);
	void RemoveHealthPack(const int idx);
	void Remove(const int idx);

private:
	std::vector<npc*> m_Npcs;
	std::vector<Health*> m_HealthPackages;
};

