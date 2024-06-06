#include "pch.h"
#include "TreeManager.h"

TreeManager::TreeManager() :
	m_Trees{}

{

}
TreeManager::~TreeManager()
{
	for (Tree* t : m_Trees)
	{
		delete t;
	}
	m_Trees.clear();
}

void TreeManager::Draw() const
{
	for (Tree* tree : m_Trees)
	{
		tree->Draw();
	}
}
void TreeManager::Update(float elapsedSec)
{
	for (Tree* tree : m_Trees)
	{
		tree->Update(elapsedSec);
	}
}

void TreeManager::AddTree(const Point2f& position)
{
	m_Trees.push_back(new Tree(position));
}
void TreeManager::AddTree(Tree* tree)
{
	m_Trees.push_back(tree);
}

int TreeManager::GetSize() const noexcept
{
	return m_Trees.size();
}
Point2f TreeManager::GetPosition(const int idx) const noexcept
{
	return m_Trees[idx]->GetPosition();
}
float TreeManager::GetWidth(const int idx) const noexcept
{
	return m_Trees[idx]->GetWidth();
}
float TreeManager::GetHeight(const int idx) const noexcept
{
	return m_Trees[idx]->GetHeight();

}