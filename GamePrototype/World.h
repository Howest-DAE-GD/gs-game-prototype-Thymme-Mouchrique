#pragma once
#include "texture.h"
class World
{
	World();
	~World();

	void Draw() const;
	void Update();
private:
	Texture* m_pBackground;
};

