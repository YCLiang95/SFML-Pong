#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
public:
	sf::CircleShape shape;
	float x, y;

	Obstacle();

public:
	void Update();
	void Draw();

private:
	bool movingUp;
};