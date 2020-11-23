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
	radius = 50.0f;
	shape.setRadius(50.0f);
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
				std::cout << "Right Score!" << std::endl;
				dx = 400;
				dy = 300;
			}
		} else {
			int c = (int)(y + (dx - GameManager::getInstance()->width) * m);
			bool bounce = false;
			for (int i = 0; i < radius * 2; i++)
				if (c + i < GameManager::getInstance()-> height && GameManager::getInstance()->right[c + i] == true)
					bounce = true;
			if (bounce) {
				speedx = -speedx;
				dx = std::max(1.0f, dx);
				dx = std::min((float)GameManager::getInstance()->width - shape.getRadius() * 2, dx);
				std::cout << c << std::endl;
			} else {
				std::cout << c << std::endl;
				
				dx = 400;
				dy = 300;
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