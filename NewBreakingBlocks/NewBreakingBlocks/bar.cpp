#include "bar.h"
#include "imageLoadFailureExpection.h"
#include "realAndVirtualCoordinateSettings.h"


bar::bar()
{
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




void bar::setBarCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

int bar::getBarCoordinateX()
{
	return this->barLeftupCoordX;
}

int bar::getBarCoordinateY()
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

void bar::setBarVelocity(int ballVelocityX_PerFrame)
{
	this->barVelocityX_PerFrame = ballVelocityX_PerFrame;
}

void bar::moveBarAtTheSetVelocity()
{
	barLeftupCoordX += barVelocityX_PerFrame;
}

void bar::barPaint() {
	DrawGraph(convertToRealCoordinateX(barLeftupCoordX),
		convertToRealCoordinateY(barLeftupCoordY), barImageHandle,TRUE);
}


