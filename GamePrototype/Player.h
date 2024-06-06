#pragma once
#include "texture.h"
#include <SoundEffect.h>
#include <iostream>
class Player
{
public:

	enum class State {
		neutral,
		movingLeft,
		movingRight,
	};


	explicit Player();
	~Player();
	
	void Update(float elapsedSec);
	void Draw() const;
	void MovePlayer(const Point2f& translate);
	void CheckKeyDown(const SDL_KeyboardEvent& e);
	void CheckKeyUp(const SDL_KeyboardEvent& e);

	int GetHealth() const;
	Point2f GetPosition() const;
	void SetPosition(const Point2f& setPosition);
	void SetCanMove(const bool canMove);
	void UpdateHealth(int healthToSubtract);
	float GetWidth() const;
	float GetHeight() const;
	
private:
	void Jump();
	int m_Health;
	Point2f m_Position;
	Point2f m_Velocity;
	Texture* m_pPlayerTexture;
	const float m_Speed;
	bool m_IsJumping;
	bool m_IsOnGround;
	bool m_CanMove;
	SoundEffect* m_pCoughingSound;

};

