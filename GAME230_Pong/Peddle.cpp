#include "Peddle.h"
#include "GameManager.h"
#include<iostream>

void Peddle::Update() {

	float deltaTime = (float)(clock() - lastTime) / CLOCKS_PER_SEC * GameManager::getInstance()->timeScale;
	lastTime = clock();

	//AI controled peddle
	if (AI) {

	} else {
		//Mouse Control
		if (mouse) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(GameManager::getInstance()->window);
			localPosition.y = localPosition.y - 50;
			if (localPosition.y < 0) localPosition.y = 0;
			if (localPosition.y + 100 > GameManager::getInstance()->height) localPosition.y = GameManager::getInstance()->height - 100;

			if (y > localPosition.y)
				y -= std::max(speedY, y - localPosition.y) * deltaTime;
			else
				y += std::max(speedY, localPosition.y - y) * deltaTime;
		}
		//Keyboard Control
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				y -= speedY * deltaTime;
				if (y < 0) y = 0;
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				y += speedY * deltaTime;
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
	speedY = 150.0f;

	lastTime = clock();

	shape.setSize(sf::Vector2f(10, 100));
	shape.setFillColor(sf::Color(255, 255, 255));

}