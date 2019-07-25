#include "ball.h"


ball::ball()
{
	ballImageHandle = LoadGraph("../.././resource/ball.png");
}


ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}


void ball::objectPaint() {
	DrawGraph(ballLeftupCoordX, ballLeftupCoordY, ballImageHandle, TRUE);
}