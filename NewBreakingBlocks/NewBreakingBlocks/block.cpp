#include "block.h"


block::block()
{
}


block::~block()
{
}




void block::setObjectCoordinate(int x, int y) {
	this->blockLeftupCoordX = x;
	this->blockLeftupCoordY = y;
}

//FIXME:�\�����邽�тɉ摜��ǂݍ���ł���B����ł͂��܂�ɏ��������ʂ��B
//�ŏ��̉摜�\�������摜�ǂݍ��݂��s���悤�ɂ��悤�B
void block::objectPaint() {
	LoadGraphScreen(blockLeftupCoordX, blockLeftupCoordY, "../.././resource/block.png", TRUE);
}