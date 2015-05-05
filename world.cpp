#include "stdafx.h"
#include "world.h"


world::world()
{
	screenWidth = 800;
    screenHeight = 600;
}

unsigned int world::getScreenHeight()
{
	return screenHeight;
}

unsigned int world::getScreenWidth()
{
	return screenWidth;
}

world::~world()
{
}
