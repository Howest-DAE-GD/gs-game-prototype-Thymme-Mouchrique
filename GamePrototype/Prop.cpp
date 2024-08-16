#include "pch.h"
#include "Prop.h"
Prop::Prop(std::string texturePath, std::string objectName, PropType propType, Point2f position) :
	m_pPropTexture{ new Texture(texturePath) },
	m_ObjectName{ objectName },
	m_pPropType{propType},
	m_Position{position}
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
}

PropType Prop::GetPropType() const noexcept
{
	return m_pPropType;
}