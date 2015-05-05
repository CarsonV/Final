#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Prey : public CircleShape
{
public:
	Prey();
	void changeDirectionX();
	void changeDirectionY();
	double getVX();
	double getVY();

	~Prey();
private:
	double vX, vY;
};

