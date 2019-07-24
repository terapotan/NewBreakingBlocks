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

//FIXME:表示するたびに画像を読み込んでいる。これではあまりに処理が無駄だ。
//最初の画像表示だけ画像読み込みを行うようにしよう。
void block::objectPaint() {
	LoadGraphScreen(blockLeftupCoordX, blockLeftupCoordY, "../.././resource/block.png", TRUE);
}