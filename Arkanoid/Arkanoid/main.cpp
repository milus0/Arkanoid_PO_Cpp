#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Racket.h"

using namespace sf;
using namespace std;

unsigned const int windowSizeX = 1000;
unsigned const int windowSizeY = 600;


template <class Object1, class Object2> bool CheckeColision(Object1& obj1, Object2& obj2)
{
	return (obj1.Right() >= obj2.Left() &&
			obj2.Right() >= obj1.Left() &&
			obj1.Top() >= obj2.Bottom() &&
			obj2.Bottom() >= obj1.Top() );
}

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