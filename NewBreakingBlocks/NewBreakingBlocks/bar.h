#pragma once
class bar
{
private:
	int barLeftupCoordX;
	int barLeftupCoordY;
public:
	bar();
	void barPaint();
	void setBarCoordinate(int x, int y);
	virtual ~bar();
};

