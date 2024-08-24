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

	const Rectf rect{ m_Position.x - m_pPropTexture->GetWidth() / 2, m_Position.y - m_pPropTexture->GetHeight() / 2, 70, 70};
	
	utils::DrawRect(rect);
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
