#include "bar.h"


bar::bar()
{
}


bar::~bar()
{
}




void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

//FIXME:�\�����邽�тɉ摜��ǂݍ���ł���B����ł͂��܂�ɏ��������ʂ��B
//�ŏ��̉摜�\�������摜�ǂݍ��݂��s���悤�ɂ��悤�B
void bar::objectPaint() {
	LoadGraphScreen(barLeftupCoordX, barLeftupCoordY, "../.././resource/bar.png", TRUE);
}