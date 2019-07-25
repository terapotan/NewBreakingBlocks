#include "bar.h"


bar::bar()
{
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