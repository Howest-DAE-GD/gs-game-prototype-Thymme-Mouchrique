#pragma once
#include "Tree.h"
#include <iostream>
#include <vector>
class TreeManager final
{
public:
	TreeManager();
	~TreeManager();

	void Draw() const;
	void Update(float elapsedSec);

	void AddTree(const Point2f& position);
	void AddTree(Tree* tree);

	int GetSize() const noexcept;
	Point2f GetPosition(const int idx) const noexcept;

	float GetWidth(const int idx) const noexcept;
	float GetHeight(const int idx) const noexcept;

private:
	std::vector<Tree*> m_Trees;
};

