#include "stdafx.h"
#include <stdlib.h>
#include <SFML\Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "predator.h"
#include "Prey.h"

using namespace sf;
using namespace std;

//void simplechase(Prey, predator);
//void collisionPred(predator);
void predWall(predator&, FloatRect&, FloatRect&, FloatRect&, FloatRect&, FloatRect&);
void preyWall(Prey&, FloatRect&, FloatRect&, FloatRect&, FloatRect&, FloatRect&);

int _tmain(int argc, _TCHAR* argv[])
{
	
	RenderWindow window(VideoMode(800, 600), "Prey v Pred");//declares window
	// initializes all shapes required
	Prey prey1;
	predator pred1;
	RectangleShape top(Vector2f(800, 1));
	RectangleShape right(Vector2f(1, 600));
	RectangleShape left(Vector2f(1, 600));
	RectangleShape bot(Vector2f(800, 1));
	bot.setPosition(0, 600);
	right.setPosition(800, 0);

	int x;
	int y;

	while (window.isOpen()) // loops untill the window is closed ex. event loop
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.setFramerateLimit(60);
		//sets bounding boxes for the edges and both forms of objects
		FloatRect topBox = top.getGlobalBounds();
		FloatRect rightBox = right.getGlobalBounds();
		FloatRect leftBox = left.getGlobalBounds();
		FloatRect botBox = bot.getGlobalBounds();
		FloatRect prey1Box = prey1.getGlobalBounds();
		FloatRect pred1Box = pred1.getGlobalBounds();
		
		srand(time(NULL));
		x = rand() % 800;
		y = rand() % 600;

		//logic for the predator simple chase **MOVE TO FUNCTION**
		if (prey1.getPosition().x > pred1.getPosition().x)
		{
			pred1.move(1.0, 0);
		}
		if (prey1.getPosition().x < pred1.getPosition().x)
		{
			pred1.move(-1.0, 0);
		}
		if (prey1.getPosition().y > pred1.getPosition().y)
		{
			pred1.move(0, 1.0);
		}
		if (prey1.getPosition().y < pred1.getPosition().y)
		{
			pred1.move(0, -1.0);
		}
			
		//logic for prey simple evade **MOVE TO FUNCTION**
		if (prey1.getPosition().x > pred1.getPosition().x)
		{
			prey1.move(0.9, 0);
		}
		if (prey1.getPosition().x < pred1.getPosition().x)
		{
			prey1.move(-0.9, 0);		
		}
		if (prey1.getPosition().y > pred1.getPosition().y)
		{
			prey1.move(0, 0.9);
		}
		if (prey1.getPosition().y < pred1.getPosition().y)
		{
			prey1.move(0, -0.9);
		}

		if ((pred1Box.intersects(prey1Box)))
		{
			prey1.setPosition(x, y);
		}
			

		predWall(pred1, topBox, botBox, leftBox, rightBox, pred1Box);
		preyWall(prey1, topBox, botBox, leftBox, rightBox, prey1Box);
		window.clear();
		window.draw(prey1);
		window.draw(pred1);
		window.display();
	}
	return 0;
}

void simplechase(Prey prey1, predator pred1)
{
	if (prey1.getPosition().x > pred1.getPosition().x)
	{
		pred1.move(1, 0);
	}
	if (prey1.getPosition().x < pred1.getPosition().x)
	{
		pred1.move(-1, 0);
	}

	if (prey1.getPosition().y > pred1.getPosition().y)
	{
		pred1.move(0, 1);
	}
	if (prey1.getPosition().y < pred1.getPosition().y)
	{
		pred1.move(0, -1);
	}
}

void predWall(predator & pred1, FloatRect & topBox, FloatRect & botBox, FloatRect & leftBox, FloatRect & rightBox, FloatRect & pred1Box)
{

	if ((pred1Box.intersects(topBox)))
	{
		cout << "Pred:Hit top" << endl;
		pred1.move(0, 1);
	}
	if ((pred1Box.intersects(botBox)))
	{
		cout << "Pred:Hit bot" << endl;
		pred1.move(0, -1);
	}
	if ((pred1Box.intersects(rightBox)))
	{
		cout << "Pred:Hit right" << endl;
		pred1.move(-1, 0);
	}
	if ((pred1Box.intersects(leftBox)))
	{
		cout << "Pred:Hit left" << endl;
		pred1.move(1, 0);
	}
}

void preyWall(Prey & prey1, FloatRect & topBox, FloatRect & botBox, FloatRect & leftBox, FloatRect & rightBox, FloatRect & prey1Box)
{

	if ((prey1Box.intersects(topBox)))
	{
		cout << "Prey:Hit top" << endl;
		prey1.move(0, 0.9);
	}
	if ((prey1Box.intersects(botBox)))
	{
		cout << "Prey:Hit bot" << endl;
		prey1.move(0, -0.9);
	}
	if ((prey1Box.intersects(rightBox)))
	{
		cout << "Prey:Hit right" << endl;
		prey1.move(-0.9, 0);
		if ((prey1Box.intersects(topBox)))
		{
			prey1.move(-1, 1);
		}
	}
	if ((prey1Box.intersects(leftBox)))
	{
		cout << "Prey:Hit left" << endl;
		prey1.move(0.9, 0);
		if ((prey1Box.intersects(topBox)))
		{
			prey1.move(1, 1);
		}
	}
}





















/********YET TO IMPLEMENT*******
*	Corner Control
*	A* pathing
*	Functionalizing
*	Clean up Classes, add more functionallity
*	Implement Classes in a better way
*/