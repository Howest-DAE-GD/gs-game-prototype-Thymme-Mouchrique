#pragma once
#include <iostream>
class Camera final
{
public:
	Camera(float screenWidth, float screenHeight);

	void Aim(const Point2f& trackCenter);
	void Reset() const;

		void SetCanMove(bool canMove);
	bool IsCameraMoving() const noexcept;
private:
	float m_ScreenWidth;
	float m_ScreenHeight;

	float m_MaxHeight;
	float m_MaxWidth;

	bool m_IsMoving;

	//Camera can only move is game is progressing
	bool m_CanMove;

	Point2f m_PreviousCamera;

};

