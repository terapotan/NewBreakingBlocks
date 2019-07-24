#include "bar.h"


bar::bar()
{
}


bar::~bar()
{
}




void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

//FIXME:表示するたびに画像を読み込んでいる。これではあまりに処理が無駄だ。
//最初の画像表示だけ画像読み込みを行うようにしよう。
void bar::objectPaint() {
	LoadGraphScreen(barLeftupCoordX, barLeftupCoordY, "../.././resource/bar.png", TRUE);
}