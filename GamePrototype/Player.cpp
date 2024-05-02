#include "pch.h"
#include "Player.h"
Player::Player()
	:
	m_Health{100},
	m_Position{100, 100},
	m_MovingStateX{},
	m_MovingStateY{},
	m_pPlayerTexture{ new Texture("player/player.png") },
	m_pCoughingSound{ new SoundEffect("player/sound/cough.mp3") }
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

	//m_pCoughingSound->Play(1);
	//TODO: randomize
#pragma region movement
	const float speed{ 1000 };
	Point2f movePlayerPos{};

	if (m_Position.x >= 0 and m_Position.x + m_pPlayerTexture->GetWidth() <= 1280)
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
	}
	else
	{
		
	}
	if (m_Position.y > 0 and m_Position.y + m_pPlayerTexture->GetHeight() <= 720 )
	{
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
	else
	{

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