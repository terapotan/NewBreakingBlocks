#include "ball.h"


ball::ball()
{
}


ball::~ball()
{
}

void ball::ballPaint() {
	LoadGraphScreen(ballLeftupCoordX, ballLeftupCoordY, "../.././resource/ball.png", TRUE);
}

void ball::setBallCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}