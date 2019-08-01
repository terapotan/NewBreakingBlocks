#include "bar.h"


bar::bar()
{
	//FIXME:画像読み込み失敗時の処理が実装されていない
	//画像読み込み失敗時はimageLoadFailuereExpection例外を送出するようにしなければならない
	barImageHandle = LoadGraph("../.././resource/bar.png");
}


bar::~bar()
{
	DeleteGraph(barImageHandle);
}




void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

void bar::objectPaint() {
	DrawGraph(barLeftupCoordX, barLeftupCoordY, barImageHandle,TRUE);
}