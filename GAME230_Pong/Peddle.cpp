#include "Peddle.h"
#include "GameManager.h"
#include<iostream>

void Peddle::Update() {
	//AI controled peddle
	if (AI) {
		y += speedY * GameManager::getInstance()->deltaTime;;
		if (y > GameManager::getInstance()->height - 100) {
			y = GameManager::getInstance()->height - 100;
			speedY *= -1;
		} else if (y < 0) {
			y = 0;
			speedY *= -1;
		}
	} else {
		//Mouse Control
		if (mouse) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(GameManager::getInstance()->window);
			localPosition.y = localPosition.y - 50;
			if (localPosition.y < 0) localPosition.y = 0;
			if (localPosition.y + 100 > GameManager::getInstance()->height) localPosition.y = GameManager::getInstance()->height - 100;

			if (y > localPosition.y)
				y -= std::max(speedY, y - localPosition.y) * GameManager::getInstance()->deltaTime;
			else
				y += std::max(speedY, localPosition.y - y) * GameManager::getInstance()->deltaTime;
		}
		//Keyboard Control
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				y -= speedY * GameManager::getInstance()->deltaTime;
				if (y < 0) y = 0;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				y += speedY * GameManager::getInstance()->deltaTime;
				if (y + 100 > GameManager::getInstance()->height)
					y = GameManager::getInstance()->height - 100;
			}
		}
	}

	int t = (int)y;
	for (int i = 0; i < 100; i++) {
		if (t + i < GameManager::getInstance()->height)
			if (x < GameManager::getInstance()->width / 2)
				GameManager::getInstance()->left[t + i] = true;
			else
				GameManager::getInstance()->right[t + i] = true;
	}

}

void Peddle::Draw() {
	shape.setPosition(x, y);
	GameManager::getInstance()->window.draw(shape);
}

Peddle::Peddle(float x, float y, bool AI, bool mouse) {
	this->x = x;
	this->y = y;
	this->AI = AI;
	this->mouse = mouse;

	speedX = 0.0f;
	speedY = 250.0f;

	shape.setSize(sf::Vector2f(10, 100));
	if (AI)
		shape.setFillColor(sf::Color(255, 255, 255));
	else
		shape.setFillColor(sf::Color(255, 0, 0));
}