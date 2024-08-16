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
	timeSinceLastSpawn = 4;
	spawnCooldown = 5;

	m_pPlayer = new Player(Point2f(250, 0));
	InitLevel();
	InitPropManager();
	InitUI();
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
	timeSinceLastSpawn += elapsedSec;
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

	if (timeSinceLastSpawn > spawnCooldown)
	{
		timeSinceLastSpawn = 0;
		int rnd{ rand() % 4 + 1};
		if (rnd == 1 || rnd == 2 || rnd == 3)
		{
			m_pPropManager->AddProp(false);
		}
		else
		{
			m_pPropManager->AddProp(true);
		}
	}
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