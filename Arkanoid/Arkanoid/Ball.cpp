#include "Ball.h"



Ball::Ball(float x, float y, int SizeX, int SizeY)
{
	this->windowSizeX = SizeX;
	this->windowSizeY = SizeY;
	circle.setPosition(x, y);	// Ustawiamy pozycjê kulki
	circle.setRadius(this->lenghtOfBallRay); // ustawiamy d³ugoœæ jej promienia
	circle.setFillColor(Color::White); // Ustawiamy kolor kulki
	circle.setOrigin(this->lenghtOfBallRay, this->lenghtOfBallRay); // Ustawianie œrodka kulki
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->circle, state);
}

void Ball::Update()
{
	circle.move(this->ballVelocityVector);
	if (Left() <= 0)
	{
		ballVelocityVector.x *= -1;
	}
	else if(Right() >= windowSizeX)
	{
		ballVelocityVector.x *= -1;
	}
	else if (Top() <= 0)
	{
		ballVelocityVector.y *= -1;
	}
	else if (Bottom() >= windowSizeY)
	{
		ballVelocityVector.y *= -1;
	}
}

float Ball::Left()
{
	return (this->circle.getPosition().x - circle.getRadius());
}

float Ball::Right()
{
	return (this->circle.getPosition().x + circle.getRadius());
}

float Ball::Top()
{
	return (this->circle.getPosition().y - circle.getRadius());
}

float Ball::Bottom()
{
	return (this->circle.getPosition().y + circle.getRadius());
}

