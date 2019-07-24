#pragma once
#include "objectsOnTheScreen.h"

class bar : public objectsOnTheScreen
{
private:
	int barLeftupCoordX;
	int barLeftupCoordY;
public:
	bar();
	void setObjectCoordinate(int x, int y) override;
	void objectPaint() override;
	virtual ~bar();
};

