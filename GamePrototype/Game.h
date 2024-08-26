#pragma once
#include "BaseGame.h"
#include "Camera.h"
#include "Player.h"
#include "level.h"
#include "PropManager.h"
#include "GameUI.h"

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
	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;


	void InitLevel();
	void UpdateLevel(float elapedSec);
	void DrawLevel() const;
	void DeleteLevel();

	void InitPropManager();
	void UpdatePropManager(float elapedSec);
	void DrawPropManager() const;
	void DeletePropManager();

	void InitUI();
	void UpdateUI(float elapedSec);
	void DrawUI() const;
	void DeleteUI();
	GameUI* GetGameUI();


	Camera* m_pCamera;
	Player* m_pPlayer;
	Level* m_pLevel;
	PropManager* m_pPropManager;
	GameUI* m_pGameUI;

	float m_TimeSinceLastSpawn;
	float m_SpawnCooldown;

	//necessary to prevent loops
	bool m_HasProcessedScore3;
	bool m_HasProcessedScore10;
	bool m_HasProcessedScore20;
};
