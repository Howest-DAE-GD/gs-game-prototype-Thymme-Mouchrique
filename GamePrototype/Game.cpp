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
	m_pPlayer = new Player(Point2f(250, 0));
	InitLevel();
}

void Game::Cleanup( )
{
	delete m_pPlayer;
	DeleteLevel();
}

void Game::Update( float elapsedSec )
{
	m_pPlayer->Update(elapsedSec);
	
	UpdateLevel(elapsedSec);
}

void Game::Draw( ) const
{
	ClearBackground();
	
	DrawLevel();
	m_pPlayer->Draw();
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