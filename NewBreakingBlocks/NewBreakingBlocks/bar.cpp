#include "bar.h"
#include "realAndVirtualCoordinateSettings.h"


bar::bar(const playDisplayImageManagement& playInstance)
{
	barImageHandle = playInstance.getBarImageHandle();

	int tmpWidth, tmpHeight;
	
	GetGraphSize(barImageHandle, &tmpWidth, &tmpHeight);
	this->barWidth_Pixel = convertToVirtualCoordinate(tmpWidth);
	this->barHeight_Pixel = convertToVirtualCoordinate(tmpHeight);
}

bar::bar(int barLeftupCoordX, int barLeftupCoordY, const playDisplayImageManagement& playInstance) : bar(playInstance)
{
	this->barLeftupCoordX = barLeftupCoordX;
	this->barLeftupCoordY = barLeftupCoordY;
}


bar::~bar()
{
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

void bar::saveNowObjectStateToRectObject()
{
	this->rectObjectElements.rectLeftUpCoordX = this->barLeftupCoordX;
	this->rectObjectElements.rectLeftUpCoordY = this->barLeftupCoordY;
	this->rectObjectElements.rectWidth = this->barWidth_Pixel;
	this->rectObjectElements.rectHeight = this->barHeight_Pixel;
}


