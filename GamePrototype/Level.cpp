#include "pch.h"
#include "Level.h"

Level::Level() :
	m_pBackground{ new Texture("Level/background.png") }
{

}
Level::~Level()
{
	delete m_pBackground;
}

void Level::Draw() const
{
	m_pBackground->Draw();
}
void Level::Update(float elapsedSec)
{

}