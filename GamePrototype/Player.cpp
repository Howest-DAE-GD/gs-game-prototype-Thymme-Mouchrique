#include "pch.h"
#include "Player.h"

Player::Player()
	:
	m_Health{100},
	m_Position{},
	m_MovingStateX{},
	m_MovingStateY{},
	m_PlayerTexture{ new Texture("player/player.png") }
{
	
}
Player::~Player()
{
	delete m_PlayerTexture;
}


void Player::Draw() const
{
	m_PlayerTexture->Draw(m_Position);
}

void Player::Update(float elapsedSec)
{
#pragma region movement
	const float speed{ 1000 };
	Point2f movePlayerPos{};

	if (m_Position.x > 0 && m_Position.y < 500)
	{
		switch (m_MovingStateX)
		{
		case Player::StateX::neutral:
			break;
		case Player::StateX::movingLeft:
			movePlayerPos.x -= speed * elapsedSec;
			break;
		case Player::StateX::movingRight:
			movePlayerPos.x += speed * elapsedSec;
			break;
		default:
			break;
		}
		switch (m_MovingStateY)
		{
		case Player::StateY::neutral:
			break;
		case Player::StateY::movingUp:
			movePlayerPos.y += speed * elapsedSec;
			break;
		case Player::StateY::movingDown:
			movePlayerPos.y -= speed * elapsedSec;
			break;
		default:
			break;
		}
		MovePlayer(movePlayerPos);
	}
	else {
		MovePlayer(Point2f(1, -1));
	}
#pragma endregion movement
}

void Player::MovePlayer(const Point2f& translate)
{
	m_Position.x += translate.x;
	m_Position.y += translate.y;
}


void Player::CheckKeyDown(const SDL_KeyboardEvent& e)
{
	if (e.keysym.scancode == SDL_SCANCODE_A || e.keysym.scancode == SDL_SCANCODE_LEFT)
	{
		m_MovingStateX = StateX::movingLeft;
	}
	else if (e.keysym.scancode == SDL_SCANCODE_D || e.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		m_MovingStateX = StateX::movingRight;
	}
	if (e.keysym.scancode == SDL_SCANCODE_W || e.keysym.scancode == SDL_SCANCODE_UP)
	{
		m_MovingStateY = StateY::movingUp;
	}
	else if (e.keysym.scancode == SDL_SCANCODE_S || e.keysym.scancode == SDL_SCANCODE_DOWN)
	{
		m_MovingStateY = StateY::movingDown;
	}
}
void Player::CheckKeyUp(const SDL_KeyboardEvent& e)
{
	if (e.keysym.scancode == SDL_SCANCODE_A || e.keysym.scancode == SDL_SCANCODE_LEFT || 
		e.keysym.scancode == SDL_SCANCODE_D || e.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		m_MovingStateX = StateX::neutral;
	}
	if (e.keysym.scancode == SDL_SCANCODE_W || e.keysym.scancode == SDL_SCANCODE_UP || 
		e.keysym.scancode == SDL_SCANCODE_S || e.keysym.scancode == SDL_SCANCODE_DOWN
)
	{
		m_MovingStateY = StateY::neutral;
	}
}