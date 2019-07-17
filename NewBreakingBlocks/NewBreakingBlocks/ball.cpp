#include "ball.h"


ball::ball()
{
}


ball::~ball()
{
}





void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

void ball::objectPaint() {
	LoadGraphScreen(ballLeftupCoordX, ballLeftupCoordY, "../.././resource/ball.png", TRUE);
}