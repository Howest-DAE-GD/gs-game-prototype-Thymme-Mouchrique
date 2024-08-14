#pragma once
#include "Texture.h"
#include "iostream"
class Level
{
public:
	Level();
	~Level();

	void Draw() const;
	void Update(float elapsedSec);

private:
	Texture* m_pBackground;
	



};

