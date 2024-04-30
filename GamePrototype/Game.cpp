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
	InitPlayer();
	InitHud();
}

void Game::Cleanup( )
{
	DeletePlayer();
	DeleteHud();
}

void Game::Update( float elapsedSec )
{
	UpdatePlayer(elapsedSec);
	UpdateHud(elapsedSec);
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawPlayer();
	DrawHud();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	PlayerCheckKeyDown(e);
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	PlayerCheckKeyUp(e);
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
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
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
	m_pPlayer->Update(elapsedSec);
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

