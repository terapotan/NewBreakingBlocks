#include "block.h"
#include "imageLoadFailureExpection.h"

block::block()
{
	//FIXME:画像読み込み失敗時の処理が実装されていない
	//画像読み込み失敗時はimageLoadFailuereExpection例外を送出するようにしなければならない

	//FIXME:画像リソースの管理を一元化したい

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