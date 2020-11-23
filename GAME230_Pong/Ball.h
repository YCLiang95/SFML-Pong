#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
	//The x, y postion of the ball
	float x, y;

	//The direction of the ball
	float speedx, speedy;

	clock_t lastTime;

	sf::CircleShape shape;

	Ball();

public:
	void Update();
	void Draw();
};