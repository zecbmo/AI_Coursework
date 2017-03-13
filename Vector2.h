#pragma once
#include "SFML\System.hpp"

class Vector2 : public sf::Vector2f
{
public:
	Vector2(float X, float Y) { x = X; y = Y; };
	Vector2();
	~Vector2();

	Vector2& normalize();

	Vector2& rotateBy(float degrees, const Vector2& center = Vector2());

	// returns trig angle
	float getAngle() const;

	float length();

	float lengthSq();

	float dot(const Vector2 &v2)const;

	int sign(const Vector2& v2)const;

	Vector2 perp()const;

	std::string toString();

};



Vector2 operator -(const Vector2& left, const Vector2& right);