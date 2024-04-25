#pragma once
#include "BaseGame.h"
#include "Player.h"
#include "hud.h"
class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:
	hud* m_pHud;
	Player* m_pPlayer;

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;

	void InitPlayer();
	void UpdatePlayer(float elapsedSec);
	void DrawPlayer() const;
	void PlayerCheckKeyDown(const SDL_KeyboardEvent& e);
	void PlayerCheckKeyUp(const SDL_KeyboardEvent& e);
	void DeletePlayer();

	void InitHud();
	void DrawHud() const;
	void UpdateHud();
	void DeleteHud();
};