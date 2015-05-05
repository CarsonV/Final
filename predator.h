#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp> 

using namespace sf;
class predator : public CircleShape
{
public:
	predator();
	double getVX();
	double getVY();
	~predator();
	
private:
	double vX, vY;
};