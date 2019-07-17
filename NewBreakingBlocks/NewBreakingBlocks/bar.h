#pragma once
#include "objectsOnTheScreen.h"

class bar : public objectsOnTheScreen
{
private:
	int barLeftupCoordX;
	int barLeftupCoordY;
public:
	bar();
	void barPaint();
	void setObjectCoordinate(int x, int y) override;
	virtual ~bar();
};

