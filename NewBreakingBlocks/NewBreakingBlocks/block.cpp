#include "block.h"


block::block()
{
	//FIXME:�摜�ǂݍ��ݎ��s���̏�������������Ă��Ȃ�
	//�摜�ǂݍ��ݎ��s����imageLoadFailuereExpection��O�𑗏o����悤�ɂ��Ȃ���΂Ȃ�Ȃ�

	blockImageHandle = LoadGraph("../.././resource/block.png");
}


block::~block()
{
}




void block::setObjectCoordinate(int x, int y) {
	this->blockLeftupCoordX = x;
	this->blockLeftupCoordY = y;
}


void block::objectPaint() {
	DrawGraph(blockLeftupCoordX, blockLeftupCoordY, blockImageHandle, TRUE);
}