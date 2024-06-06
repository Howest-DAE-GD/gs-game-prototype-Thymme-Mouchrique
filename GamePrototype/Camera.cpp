#include "pch.h"
#include "Camera.h"

#include "pch.h"
#include "Camera.h"

Camera::Camera(float screenWidth, float screenHeight)
	: m_ScreenWidth{ screenWidth },
	m_ScreenHeight{ screenHeight },
	m_MaxHeight{},
	m_MaxWidth{},
	m_IsMoving{ false },
	m_CanMove{ true }
{

}
void Camera::Aim(const Point2f& trackCenter)
{
	float cameraX{ (trackCenter.x - m_ScreenWidth / 3.0f)  };
	float cameraY{ 0 }; //no vertical tracking

	glPushMatrix();
	glTranslatef(-cameraX, -cameraY, 0);
}
void Camera::Reset() const
{
	glPopMatrix();	
}

bool Camera::IsCameraMoving() const noexcept
{
	if (m_CanMove)
	{
		return m_IsMoving;
	}
	return false;
}

void Camera::SetCanMove(bool canMove)
{
	m_CanMove = canMove;
}