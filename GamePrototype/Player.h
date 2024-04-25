#pragma once
#include "texture.h"
#include <iostream>
class Player
{
public:

	enum class StateX {
		neutral,
		movingLeft,
		movingRight,
	};
	enum class StateY {
		neutral, 
		movingUp,
		movingDown,
	};

	explicit Player();
	~Player();
	
	void Update(float elapsedSec);
	void Draw() const;
	void MovePlayer(const Point2f& translate);
	void CheckKeyDown(const SDL_KeyboardEvent& e);
	void CheckKeyUp(const SDL_KeyboardEvent& e);
private:
	int m_Health;
	Point2f m_Position;
	Texture* m_PlayerTexture;
	StateX m_MovingStateX;
	StateY m_MovingStateY;
};

