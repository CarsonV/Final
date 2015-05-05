#pragma once
class Vector
{
public:
	float x;
	float y;
	

	Vector(void);
	Vector(float xi, float yi);
	float Magnitude(void);
	void Normalize(void);
	void Reverse(void);

	Vector& operator+=(Vector u);
	Vector& operator-=(Vector u);
	Vector& operator*=(float s);
	Vector& operator/=(float s);

	Vector operator-(void);
	~Vector();
};

