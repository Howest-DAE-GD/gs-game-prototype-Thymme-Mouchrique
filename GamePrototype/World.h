#pragma once
#include "texture.h"
#include "ParticleManager.h"
#include "TreeManager.h"
#include "npc.h"
#include "NpcHealthManager.h"
class World
{
public:
	World();
	~World();

	void UpdatePlayerPosition(const Point2f& position);
	void Draw() const;
	void Update(float elapedSec);
	Point2f GetNewPlayerPos();
	bool MovePlayer() const noexcept;
	void UpdateScore(const float newScore);

	float GetWidth() const noexcept;
	float GetHeight() const noexcept;
	ParticleManager* GetParticleManager() const noexcept;
	TreeManager* GetTreeManager() const noexcept;
private:
	Texture* m_pBackground;
	Texture* m_pPharmacy;
	float m_BackgroundPosX1;
	float m_BackgroundPosX2;
	float m_BackgroundPosX3;
	float m_ScrollSpeed;
	float m_Score;
	bool m_MovePlayer;
	Point2f m_Position;
	Point2f m_NewPlayerPos;
	TreeManager* m_pTreeManager;
	ParticleManager* m_pParticleManager;
};

