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

void bar::objectPaint() {
	LoadGraphScreen(barLeftupCoordX, barLeftupCoordY, "../.././resource/bar.png", TRUE);
}