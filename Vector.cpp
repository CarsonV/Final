#include "stdafx.h"
#include "Vector.h"
#include <math.h>

 
Vector::Vector()
{
	x = 0;
	y = 0;
}

Vector::Vector(float xi, float yi)
{
	x = xi;
	y = yi;
}

float Vector::Magnitude(void)
{
	return (float)sqrt(x*x + y*y);
}

void Vector::Normalize(void)
{
	const float tol = 0.0001f;
	float m = (float)sqrt(x*x + y*y);
	if (m <= tol)
		m = 1;
	x /= m;
	y /= m;

	if (fabs(x) < tol)
		x = 0.0f;
	if (fabs(y) < tol)
		y = 0.0f;
}

void Vector::Reverse(void)
{
	x = -x;
	y = -y;
}

Vector& Vector::operator+=(Vector u)
{
	x += u.x;
	y += u.y;
	return *this;
}

Vector& Vector::operator-=(Vector u)
{
	x -= u.x;
	y -= u.y;
	return *this;
}

Vector& Vector::operator*=(float s)
{
	x *= s;
	y *= s;
	return *this;
}

Vector& Vector::operator/=(float s)
{
	x /= s;
	y /= s;
	return *this;
}

Vector Vector::operator-(void)
{
	return Vector(-x, -y);
}
Vector::~Vector()
{
}
