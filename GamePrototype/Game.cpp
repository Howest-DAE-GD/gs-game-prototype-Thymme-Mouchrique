#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize()
{
	m_HitCooldown = 2.5f; 
	m_AddHealthCooldown = 0;
	InitNpc();
	InitPlayer();
	InitWorld();
	InitCamera();
	InitHud();
	InitParticleManager();
	InitSoundManager();
}

void Game::Cleanup( )
{
	DeleteNpc();
	DeletePlayer();
	DeleteWorld();
	DeleteCamera();
	DeleteHud();
	DeleteParticleManager();
	DeleteSoundManager();
}

void Game::Update( float elapsedSec )
{
	UpdateNpc(elapsedSec);
	UpdatePlayer(elapsedSec);
	UpdateWorld(elapsedSec);
	UpdateCamera(elapsedSec);
	UpdateHud(elapsedSec);
	UpdateParticleManager(elapsedSec);
	UpdateSoundManager(elapsedSec);
}

void Game::Draw( ) const
{
	ClearBackground();
	DrawWorld();
	DrawPlayer();
	DrawNpc();
	DrawParticleManager();
	DrawSoundManager();

	ResetCamera();
	DrawHud();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	PlayerCheckKeyDown(e);

	if (e.keysym.scancode == SDL_SCANCODE_P)
	{
		std::cout << m_pPlayer->GetPosition().x << ", " << m_pPlayer->GetPosition().y << std::endl;;
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	PlayerCheckKeyUp(e);

	if (e.keysym.scancode == SDL_SCANCODE_R)
	{
		if (m_GameWon or !m_pPlayer->IsDead())
		{
			Cleanup();
			Initialize();
		}
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{

}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.53f, 0.81f, 0.92f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
#pragma region HUD functions
void Game::InitHud()
{
	m_pHud = new hud(GetViewPort().width, GetViewPort().height);
}
void Game::DrawHud() const
{
	m_pHud->Draw();
}
void Game::UpdateHud(float elapsedSec)
{
	m_pHud->Update(elapsedSec);
	m_pHud->SetHealth(m_pPlayer->GetHealth());
}
void Game::DeleteHud()
{
	delete m_pHud;
}
#pragma endregion HUD functions

#pragma region Player Functions
void Game::InitPlayer()
{
	m_pPlayer = new Player();
}
void Game::UpdatePlayer(float elapsedSec)
{
	if (!m_pPlayer->IsDead())
	{
		if (m_pHud->GetScore() >= 500)
		{
			m_GameWon = true;
		}
		m_pPlayer->Update(elapsedSec);

		if (m_pHud->GetScore() > 1000)
		{
			m_pPlayer->SetCanMove(false);
		}
		else
		{
			m_pPlayer->SetCanMove(true);
		}

		if (m_HitCooldown >= 3)
		{
			for (int i = 0; i < m_pWorld->GetTreeManager()->GetSize(); i++)
			{
				if (m_pPlayer->GetPosition().x < m_pWorld->GetTreeManager()->GetPosition(i).x + m_pWorld->GetTreeManager()->GetWidth(i) && m_pPlayer->GetPosition().x + m_pPlayer->GetWidth() > m_pWorld->GetTreeManager()->GetPosition(i).x &&
					m_pPlayer->GetPosition().y < m_pWorld->GetTreeManager()->GetPosition(i).y + m_pWorld->GetTreeManager()->GetHeight(i) && m_pPlayer->GetPosition().y + m_pPlayer->GetHeight() > m_pWorld->GetTreeManager()->GetPosition(i).y)
				{
					m_HitCooldown = 0;
					m_pPlayer->UpdateHealth(25);
					m_pSoundManager->PlayCoughingSound();
				}
			}
		}
		if (m_AddHealthCooldown > 1)
		{
			for (int i = 0; i < m_pNpcHealthManager->GetSize(); i++)
			{
				if (m_pPlayer->GetPosition().x < m_pNpcHealthManager->GetPosition(i).x + m_pNpcHealthManager->GetWidth(i) && m_pPlayer->GetPosition().x + m_pPlayer->GetWidth() > m_pNpcHealthManager->GetPosition(i).x &&
					m_pPlayer->GetPosition().y < m_pNpcHealthManager->GetPosition(i).y + m_pNpcHealthManager->GetHeight(i) && m_pPlayer->GetPosition().y + m_pPlayer->GetHeight() > m_pNpcHealthManager->GetPosition(i).y)
				{
					m_AddHealthCooldown = 0;
					m_HitCooldown = 0;
					m_pPlayer->UpdateHealth(-25);
				}
			}
		}

		m_HitCooldown += elapsedSec;
		m_AddHealthCooldown += elapsedSec;
	}
	else
	{
		m_pHud->SetDead();
	}
}
void Game::DrawPlayer() const
{
	m_pPlayer->Draw();
}
void Game::PlayerCheckKeyDown(const SDL_KeyboardEvent& e)
{
	m_pPlayer->CheckKeyDown(e);
}
void Game::PlayerCheckKeyUp(const SDL_KeyboardEvent& e)
{
	m_pPlayer->CheckKeyUp(e);
}

void Game::DeletePlayer()
{
	delete m_pPlayer;
}

#pragma endregion Player Functions

#pragma region particle functions
void Game::InitParticleManager()
{
	m_ParticleManager = new ParticleManager();
}
void Game::UpdateParticleManager(float elapsedSec)
{
	m_ParticleManager->Update(elapsedSec);
}
void Game::DrawParticleManager() const
{
	m_ParticleManager->Draw();
}
void Game::DeleteParticleManager()
{
	delete m_ParticleManager;
}
#pragma endregion particle functions

#pragma region Sound functions
void Game::InitSoundManager()
{
	m_pSoundManager = new SoundManager();
	m_pSoundManager->PlayBackgroundSound();
}
void Game::UpdateSoundManager(float elapsedSec)
{
	m_pSoundManager->Update(elapsedSec);
}
void Game::DrawSoundManager() const
{
	m_pSoundManager->Draw();
}
void Game::DeleteSoundManager()
{
	delete m_pSoundManager;
}
#pragma endregion Sound functions

void Game::InitWorld()
{
	m_pWorld = new World();
}
void Game::DeleteWorld()
{
	delete m_pWorld;
}
void Game::DrawWorld() const
{
	m_pWorld->Draw();
}
void Game::UpdateWorld(float elapsedSec)
{
	m_pWorld->Update(elapsedSec);
	m_pWorld->UpdatePlayerPosition(m_pPlayer->GetPosition());
	m_pWorld->UpdateScore(m_pHud->GetScore());
	if (m_pWorld->MovePlayer())
	{
		m_pPlayer->SetPosition(m_pWorld->GetNewPlayerPos());
	}
}
#pragma region camera

void Game::InitCamera()
{
	m_pCamera = new Camera(GetViewPort().width, GetViewPort().height);
}
void Game::DeleteCamera()
{
	delete m_pCamera;
}
void Game::ResetCamera() const
{
	m_pCamera->Reset();
}
void Game::UpdateCamera(float elapsedSec)
{
	m_pCamera->Aim(m_pPlayer->GetPosition());
}
#pragma endregion camera



void Game::InitNpc()
{
	m_pNpcHealthManager = new NpcHealthManager();
	const int numHealths{ 10 };
	for (int i = 0; i < numHealths; i++)
	{
		int rnd{ std::rand() % 60001 };

		m_pNpcHealthManager->Add(Point2f(rnd, 82));
	}
	const Point2f npcPos{ 30090, 82 };
	m_pNpcHealthManager->Add(npcPos);
}
void Game::UpdateNpc(float elapsedSec)
{
	m_pNpcHealthManager->Update(elapsedSec);
}
void Game::DrawNpc() const
{
	m_pNpcHealthManager->Draw();
}

void Game::DeleteNpc()
{
	delete m_pNpcHealthManager;
}