#include "ball.h"
#include "imageLoadFailureExpection.h"

ball::ball()
{
	//ボールの画像として読み込む画像は以下の要件を満たしている必要があります
	//1:画像の縦幅と横幅が同じ値であり読み込む画像に描画されている図形が円であること
	//2:PNG形式の画像であること
	//3:円の直径が画像の横幅(もしくは縦幅)に一致していること
	//2が満たされないと画像の透過処理が行われない可能性があります
	//1と3が満たされないと当たり判定処理が正しく行われない可能性があります

	//FIXME:画像読み込み失敗及び画像形式不一致のエラーに対応していない
	//例外を用いてエラーメッセージを表示するようにしなければならない

	ballImageHandle = LoadGraph("../.././resource/ball.png");

	if (ballImageHandle == -1) {
		imageLoadFailureExpection imageLoadInstance;
		throw imageLoadInstance;
	}
	


	int ballImageSizeX, ballImageSizeY;
	GetGraphSize(ballImageHandle, &ballImageSizeX, &ballImageSizeY);

	ballRadius_Pixel = ballImageSizeX / 2;

}

ball::ball(int ballLeftupCoordX, int ballLeftupCoordY) : ball()
{
	this->setObjectCoordinate(ballLeftupCoordX, ballLeftupCoordY);
}


ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

void ball::setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame)
{
	this->ballVelocityX_PerFrame = ballVelocityX_PerFrame;
	this->ballVelocityY_PerFrame = ballVelocityY_PerFrame;
}

int ball::getBallRadiusPixel()
{
	return this->ballRadius_Pixel;
}

void ball::moveBallAtTheSetVelocity()
{
	this->ballLeftupCoordX += this->ballVelocityX_PerFrame;
	this->ballLeftupCoordY += this->ballVelocityY_PerFrame;
}


void ball::objectPaint() {
	DrawGraph(ballLeftupCoordX, ballLeftupCoordY, ballImageHandle, TRUE);
}