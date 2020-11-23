#pragma once

class Particle {
public:
	float lifeSpan;
	float timeSinceCreated;

	float x, y;
	float speedx, speedy;

	sf::CircleShape shape;

	void Update();
	void Draw();
};