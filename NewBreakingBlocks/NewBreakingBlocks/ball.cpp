#include "ball.h"


ball::ball()
{
	ballImageHandle = LoadGraph("../.././resource/ball.png");
}

ball::ball(int ballLeftupCoordX, int ballLeftupCoordY) : ball()
{
	this->setObjectCoordinate(ballLeftupCoordX, ballLeftupCoordY);
}


ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

void ball::setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame)
{
	this->ballVelocityX_PerFrame = ballVelocityX_PerFrame;
	this->ballVelocityY_PerFrame = ballVelocityY_PerFrame;
}

void ball::moveBallAtTheSetVelocity()
{
	this->ballLeftupCoordX += this->ballVelocityX_PerFrame;
	this->ballLeftupCoordY += this->ballVelocityY_PerFrame;
}


void ball::objectPaint() {
	DrawGraph(ballLeftupCoordX, ballLeftupCoordY, ballImageHandle, TRUE);
}