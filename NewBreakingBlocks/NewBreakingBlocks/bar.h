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
	void setBarCoordinate(int x, int y);
	int getBarCoordinateX();
	int getBarCoordinateY();
	int getBarWidthPixel();
	int getBarHeightPixel();
	void barPaint();
	virtual ~bar();
};

