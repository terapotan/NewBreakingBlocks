#include "bar.h"


bar::bar()
{
}


bar::~bar()
{
}

void bar::barPaint() {
	LoadGraphScreen(barLeftupCoordX,barLeftupCoordY, "../.././resource/bar.png", TRUE);
}


void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}