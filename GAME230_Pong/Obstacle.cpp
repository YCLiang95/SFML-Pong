#include "Obstacle.h"
#include "GameManager.h"

void Obstacle::Update() {
	if (movingUp) {
		y -= 100.0f * GameManager::getInstance()->deltaTime;
		if (y < 0) {
			y = 0;
			movingUp = false;
		}
	} else {
		y += 100.0f * GameManager::getInstance()->deltaTime;
		if (y + 25 > GameManager::getInstance()->height) {
			y = GameManager::getInstance()->height - 25;
			movingUp = true;
		}
	}
	shape.setPosition(x, y);

	if (pow(GameManager::getInstance()->ball->x - x, 2) + pow(GameManager::getInstance()->ball->y - y, 2) <= pow(45, 2)){
		GameManager::getInstance()->ball->speedx *= -1;
	}

	if (pow(GameManager::getInstance()->ball2->x - x, 2) + pow(GameManager::getInstance()->ball2->y - y, 2) <= pow(45, 2)) {
		GameManager::getInstance()->ball2->speedx *= -1;
	}
}

void Obstacle::Draw() {
	GameManager::getInstance()->window.draw(shape);
}

Obstacle::Obstacle() {
	x = 412.5;
	y = 0;
	shape.setRadius(25);
	shape.setFillColor(sf::Color::Blue);
	movingUp = false;

	shape.setPosition(x, y);
}