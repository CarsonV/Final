#include "stdafx.h"
#include "Prey.h"


Prey::Prey()
{
	setRadius(8);
	setFillColor(Color::Green);
	vX = .8;
	vY = .8;
	setPosition(5, 50);

}

double Prey::getVX()
{
	return vX;
}

double Prey::getVY()
{
	return vY;
}



Prey::~Prey()
{
}
