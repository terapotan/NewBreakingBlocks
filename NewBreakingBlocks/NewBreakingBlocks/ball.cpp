#include "ball.h"


ball::ball()
{
}


ball::~ball()
{
}





void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

//FIXME:表示するたびに画像を読み込んでいる。これではあまりに処理が無駄だ。
//最初の画像表示だけ画像読み込みを行うようにしよう。

void ball::objectPaint() {
	LoadGraphScreen(ballLeftupCoordX, ballLeftupCoordY, "../.././resource/ball.png", TRUE);
}