#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Racket.h"

using namespace sf;
using namespace std;

unsigned const int windowSizeX = 1000;
unsigned const int windowSizeY = 600;


int main()
{
	Ball ball(windowSizeX/2, windowSizeY/2, windowSizeX, windowSizeY);	// TODO - dodaæ funkcje ustawiaj¹c¹ zmienne statyczne z wielkoœciami okna
	Racket racket(windowSizeX / 2, windowSizeY + 20, windowSizeX, windowSizeY);
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
		racket.Update();

		window.draw(ball);
		window.draw(racket);

		window.display();
	}
}