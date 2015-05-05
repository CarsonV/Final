#pragma once
#include "predator.h"
#include "Prey.h"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;

class world
{
public:
	world();
	unsigned int getScreenWidth();
	unsigned int getScreenHeight();
	bool offTop(Shape&);
	bool offBottom(Shape&);
	bool offLeft(Shape&);
	bool offRight(Shape&);
	~world();

private:
	unsigned int screenWidth, screenHeight;
};