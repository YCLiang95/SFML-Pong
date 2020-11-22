#pragma once
#include "main.h"

class Ball {
public:
	//The x, y postion of the ball
	double x, y;

	//The direction of the ball
	double speedx, speedy;

public:
	void Update();
	void Draw();
};