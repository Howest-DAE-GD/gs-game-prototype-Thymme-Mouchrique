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
	std::cout << "---- Controls ---- " << std::endl;
	std::cout << "Left Click: Consume item" << std::endl;
	std::cout << "Right Click: Discard item" << std::endl;
	std::cout << std::endl;
	std::cout << "At the start of the game, you'll be given random allergies. As objects fall from the sky, it's your job to quickly spot them and decide-if it's one of your allergies, discard it! If it's safe, go ahead and grab it! Be quick, and stay sharp to keep the player safe from their allergies!" << std::endl;
	std::cout << std::endl;
	std::cout << "You score a point for munching on a safe snack that won't make you sneeze!" << std::endl;
	std::cout << "You lose a heart if you bite into something that makes your allergies go wild!" << std::endl;

	m_TimeSinceLastSpawn = 2.5;
	m_SpawnCooldown = 5;

	m_pPlayer = new Player(Point2f(250, 0));
	InitLevel();
	InitPropManager();
	InitUI();

	m_pPropManager->AddRandomAllergy();

	m_HasProcessedScore10 = false;
	m_HasProcessedScore20 = false;
	m_HasProcessedScore30 = false;
	m_HasProcessedScore40 = false;
}

void Game::Cleanup( )
{
	delete m_pPlayer;
	DeleteLevel();
	DeletePropManager();
	DeleteUI();
}

void Game::Update( float elapsedSec )
{
	m_TimeSinceLastSpawn += elapsedSec;
	m_pPlayer->Update(elapsedSec);
	
	UpdateLevel(elapsedSec);
	UpdatePropManager(elapsedSec);
	UpdateUI(elapsedSec);

	if (m_pPropManager->HasClickedAllergy())
	{
		m_pGameUI->DecrementHeart();
	}
	if (m_pPropManager->HasClickedHealth())
	{
		m_pGameUI->IncrementHeart();
	}
	if (m_pPropManager->HasDiscardedAllergy() || m_pPropManager->HasConsumedFood())
	{
		m_pGameUI->IncrementScore();
	}
	if (m_TimeSinceLastSpawn > m_SpawnCooldown)
	{
		m_TimeSinceLastSpawn = 0;
		int rnd{ rand() % 10 + 1};
		if (rnd == 10)
		{
			m_pPropManager->AddProp(true);
		}
		else
		{
			m_pPropManager->AddProp(false);
		}
	}
	
	if (m_pGameUI->GetScore() == 5)
	{
		m_SpawnCooldown = 3;
		m_pPropManager->ChangePropSpeed(100);
	}
	if (m_pGameUI->GetScore() == 10 && !m_HasProcessedScore10)
	{
		m_SpawnCooldown = 2.5;
		m_pPropManager->ChangePropSpeed(125);
		m_pPropManager->AddRandomAllergy();
		m_HasProcessedScore10 = true;
	}
	if (m_pGameUI->GetScore() == 15)
	{
		m_SpawnCooldown = 2;
		m_pPropManager->ChangePropSpeed(150);
	}
	if (m_pGameUI->GetScore() == 20 && !m_HasProcessedScore20)
	{
		m_SpawnCooldown = 1.5;
		m_pPropManager->ChangePropSpeed(175);
		m_pPropManager->AddRandomAllergy();
		m_HasProcessedScore20 = true;
	}
	if (m_pGameUI->GetScore() == 30 && !m_HasProcessedScore30)
	{
		m_SpawnCooldown = 1;
		m_pPropManager->ChangePropSpeed(200);
		m_pPropManager->AddRandomAllergy();
		m_HasProcessedScore30 = true;
	}
	if (m_pGameUI->GetScore() == 40 && !m_HasProcessedScore40)
	{
		m_SpawnCooldown = 0.5;
		m_pPropManager->ChangePropSpeed(225);
		m_pPropManager->AddRandomAllergy();
		m_HasProcessedScore40 = true;
	}
	m_pPropManager->UpdateScore(m_pGameUI->GetScore());
}

void Game::Draw( ) const
{
	ClearBackground();

	DrawLevel();

	DrawPropManager();
	m_pPlayer->Draw();
	DrawUI();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{

}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	m_pPropManager->ProcessMouse(e);
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.53f, 0.81f, 0.92f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

#pragma region Level
void Game::InitLevel()
{
	m_pLevel = new Level();
}
void Game::UpdateLevel(float elapedSec)
{
	m_pLevel->Update(elapedSec);
}
void Game::DrawLevel() const
{
	m_pLevel->Draw();
}
void Game::DeleteLevel()
{
	delete m_pLevel;
}
#pragma endregion Level
#pragma region PropManager
void Game::InitPropManager()
{
	m_pPropManager = new PropManager();
}
void Game::UpdatePropManager(float elapedSec)
{
	m_pPropManager->Update(elapedSec);
}
void Game::DrawPropManager() const
{
	m_pPropManager->Draw();
}
void Game::DeletePropManager()
{
	delete m_pPropManager;
}
#pragma endregion PropManager
#pragma region UI
void Game::InitUI()
{
	m_pGameUI = new GameUI(GetViewPort().width, GetViewPort().height);
}
void Game::UpdateUI(float elapsedSec)
{
	m_pGameUI->Update(elapsedSec);
}
void Game::DrawUI() const
{
	m_pGameUI->Draw();
}
void Game::DeleteUI()
{
	delete m_pGameUI;
}
#pragma endregion UI