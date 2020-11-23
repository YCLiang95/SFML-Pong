#include "Ball.h"
#include "GameManager.h"
#include <math.h>
#include <iostream>

Ball::Ball() {
	x = 400;
	y = 300;
	speedx = 240.0f;
	speedy = 180.0f;
	lastTime = clock();
	shape.setRadius(50.0f);
	shape.setFillColor(sf::Color(255,255,255));
}

void Ball::Update() {
	float deltaTime = (float)(clock() - lastTime) / CLOCKS_PER_SEC;
	lastTime = clock();
	x += speedx * deltaTime;
	y += speedy * deltaTime;

	if (y < 0 || y > GameManager::getInstance()->height - shape.getRadius() * 2) {
		speedy = -speedy;
		y = std::max(y, 1.0f);
		y = std::min(GameManager::getInstance()->height - shape.getRadius() * 2, y);
	}

	if (x < 0 || x > GameManager::getInstance()->width - shape.getRadius() * 2) {
		speedx = -speedx;
		x = std::max(1.0f, x);
		x = std::min((float)GameManager::getInstance()->width - shape.getRadius() * 2, x);
	}

	shape.setPosition(x, y);
}

void Ball::Draw() {
	GameManager::getInstance()->window.draw(shape);
}