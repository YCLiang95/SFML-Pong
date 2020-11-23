#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Ball {
public:
	//The x, y postion of the ball
	float x, y;

	float radius;

	//The direction of the ball
	float speedx, speedy;

	sf::CircleShape shape;
	//sf::SoundBuffer buffer;
	//sf::Sound sound;

	Ball();

public:
	void Update();
	void Draw();
	void Reset(bool left = false);
};