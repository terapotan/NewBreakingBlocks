#include "bar.h"
#include "imageLoadFailureExpection.h"

bar::bar()
{
	//FIXME:画像読み込み失敗時の処理が実装されていない
	//画像読み込み失敗時はimageLoadFailuereExpection例外を送出するようにしなければならない
	barImageHandle = LoadGraph("../.././resource/bar.png");

	if (barImageHandle == -1) {
		imageLoadFailureExpection imageLoadInstance;
		throw imageLoadInstance;
	}


	GetGraphSize(barImageHandle, &(this->barWidth_Pixel), &(this->barHeight_Pixel));
}

bar::bar(int barLeftupCoordX, int barLeftupCoordY) : bar()
{
	this->barLeftupCoordX = barLeftupCoordX;
	this->barLeftupCoordY = barLeftupCoordY;
}


bar::~bar()
{
	DeleteGraph(barImageHandle);
}




void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

int bar::getObjectCoordinateX()
{
	return this->barLeftupCoordX;
}

int bar::getObjectCoordinateY()
{
	return this->barLeftupCoordY;
}

int bar::getBarWidthPixel()
{
	return this->barWidth_Pixel;
}

int bar::getBarHeightPixel()
{
	return this->barHeight_Pixel;
}

void bar::objectPaint() {
	DrawGraph(barLeftupCoordX, barLeftupCoordY, barImageHandle,TRUE);
}