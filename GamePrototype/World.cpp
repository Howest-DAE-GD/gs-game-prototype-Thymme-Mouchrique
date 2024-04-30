#include "pch.h"
#include "World.h"


World::World():
	m_pBackground{new Texture("World/background.png")}
{

}
World::~World()
{
	delete m_pBackground;
}

void World::Draw() const
{
	m_pBackground->Draw();
}