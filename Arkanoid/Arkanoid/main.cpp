#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"

using namespace sf;
using namespace std;

unsigned const int windowSizeX = 1000;
unsigned const int windowSizeY = 600;


int main()
{
	Ball ball(500, 300, windowSizeX, windowSizeY);	// TODO - dodaæ funkcje ustawiaj¹c¹ zmienne statyczne z wielkoœciami okna
	RenderWindow window({ windowSizeX, windowSizeY }, "Hello World");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		ball.Update();
		window.draw(ball);
		window.display();
	}
}