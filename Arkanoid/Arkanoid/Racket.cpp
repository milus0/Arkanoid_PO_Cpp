#include "Racket.h"



Racket::Racket(float x, float y, int SizeX, int SizeY)
{
	this->windowSizeX = SizeX;
	this->windowSizeY = SizeY;	// TODO - do wyjebania
	racket.setPosition(x, y);
	racket.setFillColor(Color :: White);
	racket.setSize(Vector2f(racketLenghtX, racketLenghtY));
	racket.setOrigin(racketLenghtX/2, racketLenghtX/2);
}

void Racket::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->racket, state);
}

void Racket::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		if (PositionOfLeftSideOfRacket() >= racketVelocity)
		{
			racket.move(racketVelocityVector*-1.0f);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		if (PositionOfRightSideOfRacket() <= racketVelocity + windowSizeX)
		{
			racket.move(racketVelocityVector);
		}
	}
}

float Racket::PositionOfLeftSideOfRacket()
{
	return (this->racket.getPosition().x - racketLenghtX / 2);
}

float Racket::PositionOfRightSideOfRacket()
{
	return (this->racket.getPosition().x + racketLenghtX / 2);
}