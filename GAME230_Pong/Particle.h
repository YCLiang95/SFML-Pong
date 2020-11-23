#pragma once

class Particle {
public:
	float lifeSpan;
	float timeSinceCreated;

	float x, y;
	float speedx, speedy;

	void Update();
	void Draw();
};