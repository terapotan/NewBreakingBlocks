#include "block.h"
#include "imageLoadFailureExpection.h"

block::block()
{
	//FIXME:�摜�ǂݍ��ݎ��s���̏�������������Ă��Ȃ�
	//�摜�ǂݍ��ݎ��s����imageLoadFailuereExpection��O�𑗏o����悤�ɂ��Ȃ���΂Ȃ�Ȃ�

	blockImageHandle = LoadGraph("../.././resource/block.png");

	if (blockImageHandle == -1) {
		imageLoadFailureExpection imageLoadInstance;
		throw imageLoadInstance;
	}
}


block::~block()
{
}




void block::setBlockCoordinate(int x, int y) {
	this->blockLeftupCoordX = x;
	this->blockLeftupCoordY = y;
}


void block::blockPaint() {
	DrawGraph(blockLeftupCoordX, blockLeftupCoordY, blockImageHandle, TRUE);
}