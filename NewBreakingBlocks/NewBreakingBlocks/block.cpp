#include "block.h"
#include "imageLoadFailureExpection.h"

block::block()
{
	//FIXME:‰æ‘œ“Ç‚Ýž‚ÝŽ¸”sŽž‚Ìˆ—‚ªŽÀ‘•‚³‚ê‚Ä‚¢‚È‚¢
	//‰æ‘œ“Ç‚Ýž‚ÝŽ¸”sŽž‚ÍimageLoadFailuereExpection—áŠO‚ð‘—o‚·‚é‚æ‚¤‚É‚µ‚È‚¯‚ê‚Î‚È‚ç‚È‚¢

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