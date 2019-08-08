#pragma once

class bar
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
	void setObjectCoordinate(int x, int y);
	int getObjectCoordinateX();
	int getObjectCoordinateY();
	int getBarWidthPixel();
	int getBarHeightPixel();
	void objectPaint();
	virtual ~bar();
};

