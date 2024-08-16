#pragma once
#include "iostream"
#include "Texture.h"
enum class PropType {
	Allergy,
	Healing
};
class Prop
{
public:
	Prop(std::string texturePath, std::string objectName, PropType propType, Point2f position);
	~Prop();

	std::string GetName() const noexcept;
	Point2f GetPosition() const noexcept;
	void SetPosition(Point2f& NewPosition);
	float GetWidth() const noexcept;
	float GetHeight() const noexcept;
	PropType GetPropType() const noexcept;
	void Draw() const;
private:
	Texture* m_pPropTexture;
	std::string m_ObjectName;
	PropType m_pPropType;
	Point2f m_Position;
};

