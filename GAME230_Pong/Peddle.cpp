#include "Peddle.h"
#include "GameManager.h"

void Peddle::Update() {
	//AI controled peddle
	if (AI) {
	}

	else {
		//Mouse Control
		if (mouse) {
		}
		//Keyboard Control
		else {
		}
	}
}

void Peddle::Draw() {
	GameManager::getInstance()->window.draw(shape);
}