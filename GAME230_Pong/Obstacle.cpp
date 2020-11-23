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
}

void Obstacle::Draw() {
	GameManager::getInstance()->window.draw(shape);
}

Obstacle::Obstacle() {
	x = GameManager::getInstance()->width / 2 + 12.5f;
	y = 0;
	shape.setRadius(25);
	shape.setFillColor(sf::Color::Blue);
	movingUp = false;

	shape.setPosition(x, y);
}