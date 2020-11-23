#include "Ball.h"
#include "GameManager.h"
#include <math.h>
#include <iostream>

Ball::Ball() {
	x = 400;
	y = 300;
	speedx = 400.0f;
	speedy = 300.0f;
	lastTime = clock();
	radius = 10.0f;
	shape.setRadius(10.0f);
	shape.setFillColor(sf::Color(255,255,255));
}

void Ball::Update() {
	float deltaTime = (float)(clock() - lastTime) / CLOCKS_PER_SEC * GameManager::getInstance()->timeScale;
	lastTime = clock();
	float  dx = x + speedx * deltaTime;
	float dy = y + speedy * deltaTime;

	if (dy < 0 || dy > GameManager::getInstance()->height - shape.getRadius() * 2) {
		speedy = -speedy;
		dy = std::max(dy, 1.0f);
		dy = std::min(GameManager::getInstance()->height - shape.getRadius() * 2, dy);
	}

	if (dx < 0 || dx > GameManager::getInstance()->width - shape.getRadius() * 2) {
		float a = dx - x;
		float b = dy - y;
		float m = 0;
		if (b == 0)
			m = 0;
		else
			m = a / b;

		if (dx < 0) {
			int c = (int)(dy + (0 - dx) * m);
			bool bounce = false;
			for (int i = 0; i < radius * 2; i++)
				if (c + i < GameManager::getInstance()->height && GameManager::getInstance()->left[c + i] == true)
					bounce = true;
			if (bounce){
				speedx = -speedx;
				dx = std::max(1.0f, dx);
				dx = std::min((float)GameManager::getInstance()->width - shape.getRadius() * 2, dx);
			} else {
				Reset(true);
				dx = x;
				dy = y;
			}
		} else {
			int c = (int)(y + (dx + radius - GameManager::getInstance()->width) * m);
			bool bounce = false;
			for (int i = 0; i < radius * 2; i++)
				if (c + i < GameManager::getInstance()-> height && GameManager::getInstance()->right[c + i] == true)
					bounce = true;
			if (bounce) {
				speedx = -speedx;
				dx = std::max(1.0f, dx);
				dx = std::min((float)GameManager::getInstance()->width - shape.getRadius() * 2, dx);
			} else {
				Reset();
				dx = x;
				dy = y;
			}
		}

	}

	x = dx;
	y = dy;
	shape.setPosition(x, y);
}

void Ball::Draw() {
	GameManager::getInstance()->window.draw(shape);
}

void Ball::Reset(bool left) {
	x = GameManager::getInstance()->width / 2;
	y = GameManager::getInstance()->height / 2;
	speedx = GameManager::getInstance()->width / 4 + rand() % (GameManager::getInstance()->width / 4);
	speedy = GameManager::getInstance()->height / 4 + rand() % (GameManager::getInstance()->height / 4);
	if (left) speedx *= -1;
	shape.setPosition(x, y);
}