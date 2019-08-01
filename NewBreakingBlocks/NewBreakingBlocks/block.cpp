#include "block.h"


block::block()
{
	//FIXME:画像読み込み失敗時の処理が実装されていない
	//画像読み込み失敗時はimageLoadFailuereExpection例外を送出するようにしなければならない

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