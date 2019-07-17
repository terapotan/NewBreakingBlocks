#include "block.h"


block::block()
{
}


block::~block()
{
}

void block::blockPaint() {
	LoadGraphScreen(blockLeftupCoordX,blockLeftupCoordY, "../.././resource/block.png", TRUE);
}


void block::setObjectCoordinate(int x, int y) {
	this->blockLeftupCoordX = x;
	this->blockLeftupCoordY = y;
}