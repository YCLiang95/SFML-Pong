#include "Repulsor.h"
#include "GameManager.h"

void Repulsor::Update() {
	if (GameManager::getInstance()->isRunning) {
		if (abs((GameManager::getInstance()->ball->x - x)) + abs((GameManager::getInstance()->ball->y - y)) < 200.0f) {
			GameManager::getInstance()->ball->speedx -= (x - GameManager::getInstance()->ball->x)* GameManager::getInstance()->deltaTime;
			GameManager::getInstance()->ball->speedy -= (y - GameManager::getInstance()->ball->y)* GameManager::getInstance()->deltaTime;
		}

		if (abs((GameManager::getInstance()->ball2->x - x)) + abs((GameManager::getInstance()->ball2->y - y)) < 200.0f) {
			GameManager::getInstance()->ball2->speedx -= (x - GameManager::getInstance()->ball2->x) * GameManager::getInstance()->deltaTime;
			GameManager::getInstance()->ball2->speedy -= (y - GameManager::getInstance()->ball2->y)* GameManager::getInstance()->deltaTime;
		}
	}
}

void Repulsor::Draw() {
	GameManager::getInstance()->window.draw(shape);
}

Repulsor::Repulsor() {
	x = 400;
	y = 300;
	shape.setRadius(25);
	shape.setFillColor(sf::Color::Green);

	shape.setPosition(x, y);
}