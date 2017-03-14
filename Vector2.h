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
	
    void truncate(float max);




	const Vector2& operator+=(const Vector2 &rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	const Vector2& operator-=(const Vector2 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	const Vector2& operator*=(const float& rhs)
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}

	const Vector2& operator/=(const float& rhs)
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	bool operator==(const Vector2& rhs)const
	{
		if ((x == rhs.x) && (y == rhs.y))
		{
			return true;
		}

		return false;
	}

	bool operator!=(const Vector2& rhs)const
	{
		return (x != rhs.x) || (y != rhs.y);
	}

};



Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
Vector2 operator*(const Vector2 &lhs, float rhs);
Vector2 operator*(float lhs, const Vector2 &rhs);
Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs);
Vector2 operator/(const Vector2 &lhs, float val);

