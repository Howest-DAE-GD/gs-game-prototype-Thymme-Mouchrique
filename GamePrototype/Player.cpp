#include "pch.h"
#include "Player.h"
#include <BaseGame.h>
Player::Player()
	:
	m_Health{100},
	m_Position{100, 100},
	m_pPlayerTexture{ new Texture("player/player.png") },
	m_pCoughingSound{ new SoundEffect("player/sound/cough.mp3") },
	m_IsOnGround{false},
	m_IsJumping{false},
	m_Speed{ 300.f },
	m_CanMove{true},
	m_IsVelocityIncreasing{},
	m_IsDead{}
{

}
Player::~Player()
{
	delete m_pPlayerTexture;
	delete m_pCoughingSound;
}


void Player::Draw() const
{
	m_pPlayerTexture->Draw(m_Position);
}

void Player::Update(float elapsedSec)
{
	if (!m_IsDead)
	{
		if (m_Health <= 0)
		{
			m_IsDead = true;
		}
		if (m_CanMove)
		{
#pragma region movement
			const int mass{ 70 };
			const float gravity{ -9.81f * mass };

			if (!m_IsOnGround)
			{
				m_Velocity.y = m_Velocity.y + gravity * elapsedSec;
				m_Position.y = m_Position.y + m_Velocity.y * elapsedSec;
			}
			if (m_Position.y <= 80)
			{
				m_Velocity.y = 0;
				m_IsJumping = false;
				m_IsOnGround = true;
			}
			if (m_Position.x < 30090)
			{
				m_Position.x += m_Speed * elapsedSec;
			}
#pragma endregion movement
		}
	}
}

void Player::MovePlayer(const Point2f& translate)
{
	m_Velocity.x += translate.x;
}

void Player::SetPosition(const Point2f& newPos)
{
	m_Position.x = newPos.x;
	m_Position.y = newPos.y;
}
void Player::SetCanMove(const bool canMove)
{
	m_CanMove = canMove;
}
void Player::CheckKeyDown(const SDL_KeyboardEvent& e)
{
	
	if (e.keysym.scancode == SDL_SCANCODE_SPACE)
	{
		Jump();

	}
}
void Player::CheckKeyUp(const SDL_KeyboardEvent& e)
{

}
void Player::Jump()
{
	if (!m_IsJumping)
	{
		m_IsOnGround = false;
		m_IsJumping = true;
		m_Velocity.y += 400.f;
	}
	else
	{
		if (m_Velocity.y < 800 && m_Velocity.y > 0)
		{
			m_Velocity.y += 25.f;
		}
	}
}
int Player::GetHealth() const
{
	return m_Health;
}

void Player::UpdateHealth(int healthToSubtract)
{
	if (m_Health > 0 && m_Health < 100)
	{
		m_Health -= healthToSubtract;
	}
}

Point2f Player::GetPosition() const
{
	return m_Position;
}

float Player::GetWidth() const
{
	return m_pPlayerTexture->GetWidth();
}
float Player::GetHeight() const
{
	return m_pPlayerTexture->GetHeight();
}

bool Player::IsOnGround() const noexcept
{
	return m_IsOnGround;
}
bool Player::IsDead() const noexcept
{
	return m_IsDead;
}