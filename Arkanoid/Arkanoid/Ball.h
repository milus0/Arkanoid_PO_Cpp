#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public Drawable
{
public:
	Ball(float x, float y, int SizeX, int SizeY); // tworzenie naszego w�asnego konstruktora X,Y - koordynaty Ball
	Ball() = delete; // usuwanie standardoewgo konstruktora
	~Ball() = default; // ustawianie destruktora na domy�lny
	void Update();

	float Left();
	float Right();
	float Top();
	float Bottom();


private:
	int windowSizeX;
	int windowSizeY;

	CircleShape circle;
	float lenghtOfBallRay = { 8.0f };

	void draw(RenderTarget& target, RenderStates state) const override;

	float ballVelocity = {2.0f};
	Vector2f ballVelocityVector{ballVelocity, ballVelocity};
};

