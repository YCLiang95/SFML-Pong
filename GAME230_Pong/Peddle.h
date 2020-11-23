#pragma once
#include <SFML/Graphics.hpp>

class Peddle {
public:
	float x, y;
	float speedX, speedY;

	bool AI;
	bool mouse;

	clock_t lastTime;

	sf::RectangleShape shape;

public:
	Peddle(float x, float y, bool AI, bool mouse);

	void Update();
	void Draw();
};