#pragma once
#include "objectsOnTheScreen.h"

class ball: public objectsOnTheScreen
{
private:
	int ballLeftupCoordX;
	int ballLeftupCoordY;
	int ballImageHandle;
public:
	ball();
	void setObjectCoordinate(int x, int y) override;
	void objectPaint() override;
	virtual ~ball();
};

