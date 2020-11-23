#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Repulsor {
public:
	sf::CircleShape shape;
	float x, y;

	Repulsor();

public:
	void Update();
	void Draw();
};