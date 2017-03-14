#pragma once

#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
#include <iomanip>

#include "Vector2.h"
#include "Matrix2D.h"

//a few useful constants
const int     MaxInt = (std::numeric_limits<int>::max)();
const double  MaxDouble = (std::numeric_limits<double>::max)();
const double  MinDouble = (std::numeric_limits<double>::min)();
const float   MaxFloat = (std::numeric_limits<float>::max)();
const float   MinFloat = (std::numeric_limits<float>::min)();

const double   Pi = 3.14159;
const double   TwoPi = Pi * 2;
const double   HalfPi = Pi / 2;
const double   QuarterPi = Pi / 4;

//returns a random integer between x and y
inline int   RandInt(int x, int y) { return rand() % (y - x + 1) + x; }

//returns a random double between zero and 1
inline double RandFloat() { return ((rand()) / (RAND_MAX + 1.0)); }

inline double RandInRange(double x, double y)
{
	return x + RandFloat()*(y - x);
}


inline void Vec2DRotateAroundOrigin(Vector2& v, double ang)
{
	//create a transformation matrix
	Matrix2D mat;

	//rotate
	mat.Rotate(ang);

	//now transform the object's vertices
	mat.TransformVector2Ds(v);
}