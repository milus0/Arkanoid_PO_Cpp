#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Racket : public Drawable
{
public:
	Racket(float x,float y, int SizeX, int SizeY);
	Racket() = delete;
	~Racket() = default;
	float PositionOfLeftSideOfRacket();
	float PositionOfRightSideOfRacket();
	void Update();
private:
	int windowSizeX;
	int windowSizeY;
	float racketLenghtX { 200.0f };
	float racketLenghtY { 20.0f };
	float racketVelocity { 10.0f };
	Vector2f racketVelocityVector{ racketVelocity, 0.0f };


	RectangleShape racket;
	void draw(RenderTarget& target, RenderStates state) const override;
	//void Update();

};

