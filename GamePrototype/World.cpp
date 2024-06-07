#include "pch.h"
#include "World.h"

#include <iostream>
World::World() :
	m_pBackground{ new Texture("World/background.png") },
	m_pPharmacy{new Texture("World/pharmacy.png")},
	m_BackgroundPosX1{ 0.0f },
	m_BackgroundPosX2{ m_pBackground->GetWidth() },
	m_BackgroundPosX3{ m_BackgroundPosX2 + m_pBackground->GetWidth() },
	m_ScrollSpeed{ 150.f },
	m_Position{},
	m_NewPlayerPos{},
	m_MovePlayer{},
	m_pTreeManager{ new TreeManager() },
	m_pParticleManager{new ParticleManager()},
	m_Score{}
{
	for (int i = 0; i < 100; i++)
	{
		Point2f position{float((std::rand() % 500) + 500 * i), 82};

		if (i > 0)
		{
			if (position.x - m_pTreeManager->GetPosition(i-1).x < 100)
			{
				position = Point2f{ float((std::rand() % 500) + 500 * i), 82 };
			}
		}
		m_pTreeManager->AddTree(new Tree(position));
	}
	for (int i = 0; i < m_pTreeManager->GetSize(); i++)
	{
		for (int p = 0; p < 10; p++)
		{
			Point2f pos{ m_pTreeManager->GetPosition(i) };

			const float randomOffsetX{-50 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (50 - (-50))))};
			const float randomOffsetY{-50 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (50 - (-50))))};
			pos.x += randomOffsetX;
			pos.y += randomOffsetY + 50;

			m_pParticleManager->AddParticle(new Particle(pos));
		}
		
	}
}
World::~World()
{
	delete m_pBackground;
	delete m_pTreeManager;
	delete m_pPharmacy;
	delete m_pParticleManager;
}

void World::Draw() const
{
	m_pTreeManager->Draw();
	m_pParticleManager->Draw();
	m_pBackground->Draw(Point2f{ m_BackgroundPosX1, 0 });

	for (int i = 0; i < 10; i++)
	{
		m_pBackground->Draw(Point2f{ m_BackgroundPosX2 * i, 0 });
	}
	const Point2f buildingPos{ 30082, 82 };
	m_pPharmacy->Draw(buildingPos);

}

void World::Update(float elapsedSec)
{
	m_pTreeManager->Update(elapsedSec);
	m_pParticleManager->Update(elapsedSec);
	if (m_Score > 1000)
	{
		std::cout << "won " << std::endl;
	}
}

void World::UpdatePlayerPosition(const Point2f& position)
{
	m_Position = position;
}

Point2f World::GetNewPlayerPos()
{
	if (m_MovePlayer)
	{
		return m_NewPlayerPos;
		m_MovePlayer = false;
	}
}

bool World::MovePlayer() const noexcept
{
	return m_MovePlayer;
}

float World::GetWidth() const noexcept
{
	return m_pBackground->GetWidth();
}
float World::GetHeight() const noexcept
{
	return m_pBackground->GetHeight();
}

void World::UpdateScore(const float newScore)
{
	m_Score = newScore;
}

ParticleManager* World::GetParticleManager() const noexcept
{
	return m_pParticleManager;
}


TreeManager* World::GetTreeManager() const noexcept
{
	return m_pTreeManager;
}