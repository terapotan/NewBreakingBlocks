#pragma once
#include "objectsOnTheScreen.h"

class bar : public objectsOnTheScreen
{
private:
	int barLeftupCoordX;
	int barLeftupCoordY;
	int barImageHandle;
	int barWidth_Pixel;
	int barHeight_Pixel;

public:
	bar();
	bar(int barLeftupCoordX, int barLeftupCoordY);
	void setObjectCoordinate(int x, int y) override;
	int getObjectCoordinateX();
	int getObjectCoordinateY();
	int getBarWidthPixel();
	int getBarHeightPixel();
	void objectPaint() override;
	virtual ~bar();
};

