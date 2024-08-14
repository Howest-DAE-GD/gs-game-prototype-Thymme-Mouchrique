#include "pch.h"
#include "Player.h"
#include "iostream"

Player::Player(const Point2f& position) :
	m_Position{ position },
	m_pCharacter{ new Texture("character.png") }
{

}
Player::~Player()
{
	delete m_pCharacter;
}

void Player::Draw() const
{
	m_pCharacter->Draw(m_Position);
}
void Player::Update(float elapsedSec)
{
	
}
Point2f Player::GetPosition() const noexcept
{
	return m_Position;
}

float Player::GetWidth() const noexcept
{
	return m_pCharacter->GetWidth();
}

float Player::GetHeight() const noexcept
{
	return m_pCharacter->GetHeight();
}
