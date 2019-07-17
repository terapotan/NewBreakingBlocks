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

void block::objectPaint() {
	LoadGraphScreen(blockLeftupCoordX, blockLeftupCoordY, "../.././resource/block.png", TRUE);
}