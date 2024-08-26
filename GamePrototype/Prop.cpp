#include "pch.h"
#include "Prop.h"
#include "utils.h"
Prop::Prop(std::string texturePath, std::string objectName, PropType propType, Point2f position) :
	m_pPropTexture{ new Texture(texturePath) },
	m_ObjectName{ objectName },
	m_pPropType{propType},
	m_Position{position},
	m_IsActive{false}
{

}
Prop::~Prop()
{
	delete m_pPropTexture;
}

std::string Prop::GetName() const noexcept
{
	return m_ObjectName;
}
Point2f Prop::GetPosition() const noexcept
{
	return m_Position;
}
void Prop::SetPosition(Point2f& NewPosition)
{
	m_Position = NewPosition;
}
float Prop::GetWidth() const noexcept
{
	return m_pPropTexture->GetWidth();
}
float Prop::GetHeight() const noexcept
{
	return m_pPropTexture->GetHeight();
}

void Prop::Draw() const
{
	m_pPropTexture->Draw(m_Position);

	utils::SetColor(Color4f(0.f, 0.f, 0.f, 1.f));

	// Retrieve the dimensions of the texture
	float textureWidth{ m_pPropTexture->GetWidth() };
	float textureHeight{ m_pPropTexture->GetHeight()};

	// Calculate the center of the object
	float objectCenterX{ m_Position.x + textureWidth / 2 };
	float objectCenterY{ m_Position.y + textureHeight / 2 };

	// Define the size of the cube/rectangle to match the texture size
	float cubeWidth{ textureWidth + 25 };
	float cubeHeight{textureHeight + 25 };

	// Calculate the top-left corner of the cube/rectangle
	float cubeX{ objectCenterX - cubeWidth / 2 };
	float cubeY{ objectCenterY - cubeHeight / 2 };

	// Define the Rectf for the cube/rectangle
	Rectf cubeRect{ cubeX, cubeY, cubeWidth, cubeHeight };
	//utils::DrawRect(cubeRect);
}

PropType Prop::GetPropType() const noexcept
{
	return m_pPropType;
}

void Prop::SetActive(bool active)
{
	m_IsActive = active;
}
bool Prop::GetActive() const noexcept
{
	return m_IsActive;
}
