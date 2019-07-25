#include "block.h"


block::block()
{
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