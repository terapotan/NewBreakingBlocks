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

//FIXME:�\�����邽�тɉ摜��ǂݍ���ł���B����ł͂��܂�ɏ��������ʂ��B
//�ŏ��̉摜�\�������摜�ǂݍ��݂��s���悤�ɂ��悤�B

void ball::objectPaint() {
	LoadGraphScreen(ballLeftupCoordX, ballLeftupCoordY, "../.././resource/ball.png", TRUE);
}