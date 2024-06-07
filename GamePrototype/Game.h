#pragma once
#include "BaseGame.h"
#include "Player.h"
#include "hud.h"
#include "ParticleManager.h"
#include "SoundManager.h"
#include "World.h"
#include "Camera.h"

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
	ParticleManager* m_ParticleManager;
	SoundManager* m_pSoundManager;
	World* m_pWorld;
	Camera* m_pCamera;
	NpcHealthManager* m_pNpcHealthManager;

	bool m_GameWon;
	float m_HitCooldown;
	float m_AddHealthCooldown;

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
	void UpdateHud(float elapsedSec);
	void DeleteHud();

	void InitParticleManager();
	void UpdateParticleManager(float elapsedSec);
	void DrawParticleManager() const;
	void DeleteParticleManager();

	void InitSoundManager();
	void UpdateSoundManager(float elapsedSec);
	void DrawSoundManager() const;
	void DeleteSoundManager();

	void InitWorld(); 
	void DeleteWorld();
	void DrawWorld() const;
	void UpdateWorld(float elapsedSec); 

	void InitCamera();
	void DeleteCamera();
	void ResetCamera() const;
	void UpdateCamera(float elapsedSec);

	void InitNpc();
	void UpdateNpc(float elapsedSec);
	void DrawNpc() const;
	void DeleteNpc();
};
