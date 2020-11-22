#include "Ball.h"

void Ball::Update() {
	x += speedy;
	y += speedy;


	if (y < 0 || y > GameManager::getInstance()->height) {
		speedy = -speedy;
	}

	if (x < 0 || x > GameManager::getInstance()->width) {
		speedx = -speedx;
	}
}

void Ball::Draw() {
}