#pragma once
#include <SFML/Graphics.hpp>

class Peddle {
public:
	float x, y;
	float speedX, speedY;

	bool AI;
	bool mouse;

	sf::RectangleShape shape;

public:
	Peddle(float x, float y, bool AI, bool mouse) {
		this->x = x;
		this->y = y;
		this->AI = AI;
		this->mouse = mouse;
		shape.setSize(sf::Vector2f(20, 50));
		shape.setFillColor(sf::Color(255,255,255));

	}

	void Update();
	void Draw();
};