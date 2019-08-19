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

	int tmpWidth, tmpHeight;
	
	GetGraphSize(barImageHandle, &tmpWidth, &tmpHeight);
	this->barWidth_Pixel = convertToVirtualCoordinate(tmpWidth);
	this->barHeight_Pixel = convertToVirtualCoordinate(tmpHeight);

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
	DrawGraph(convertToRealCoordinate(barLeftupCoordX),
		convertToRealCoordinate(barLeftupCoordY), barImageHandle,TRUE);
}


