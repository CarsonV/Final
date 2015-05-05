#include "stdafx.h"
#include "predator.h"


predator::predator()
{
	setRadius(8);
	setFillColor(Color::Red);
	vX = 1;
	vY = 1;
	setPosition(350, 206);
}

predator::~predator()
{
}

double predator::getVX()
{
	return vX;
}

double predator::getVY()
{
	return vY;
}