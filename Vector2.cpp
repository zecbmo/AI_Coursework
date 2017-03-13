#include "Vector2.h"

Vector2::Vector2()
{
}

Vector2::~Vector2()
{
}

Vector2& Vector2::normalize()
{
	float length = (float)(x*x + y*y);
	if (length == 0.f)
		return *this;
	length = sqrt(1.f / length);
	x = (x * length);
	y = (y * length);
	return *this;
}

Vector2& Vector2::rotateBy(float degrees, const Vector2& center)
{
	degrees *= 3.14159f / 180.f;
	const float cs = cos(degrees);
	const float sn = sin(degrees);

	x -= center.x;
	y -= center.y;

	float nx = x*cs - y*sn;
	float ny = (x*sn + y*cs);

	x = nx;
	y = ny;

	x += center.x;
	y += center.y;
	return *this;


}

// returns trig angle
float Vector2::getAngle() const
{
	if (y == 0)
		return x < 0 ? 180 : 0;
	else if (x == 0)
		return y < 0 ? 270 : 90;

	if (y > 0)
		if (x > 0)
			return atan(y / x) * 180.f / 3.14159f;
		else
			return 180.0 - atan(y / -x) * 180.f / 3.14159f;
	else
		if (x > 0)
			return 360.0 - atan(-y / x) * 180.f / 3.14159f;
		else
			return 180.0 + atan(-y / -x) * 180.f / 3.14159f;
}

float Vector2::length()
{
	return sqrt(x*x + y*y);
}

float Vector2::lengthSq()
{
	return (x*x + y*y);
}

float Vector2::dot(const Vector2 &v2)const
{
	return x*v2.x + y*v2.y;
}

int Vector2::sign(const Vector2& v2)const
{
	if (y*v2.x > x*v2.y)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

Vector2 Vector2::perp()const
{
	return Vector2(-y, x);
}

std::string Vector2::toString()
{
	std::string returnString;

	returnString += "(x: ";
	returnString += std::to_string(x);
	returnString += " || y: ";
	returnString += std::to_string(y);;
	returnString += ")";
	

	return returnString;
}



Vector2 operator -(const Vector2& left, const Vector2& right)
{
	sf::Vector2f l(left);
	sf::Vector2f r(right);
	sf::Vector2f fin = l - r;
	Vector2 v(fin.x, fin.y);
	return v;
}