#pragma once
#include "objectsOnTheScreen.h"

class ball: public objectsOnTheScreen
{
private:
	int ballLeftupCoordX;
	int ballLeftupCoordY;
public:
	ball();
	void ballPaint();
	void setObjectCoordinate(int x, int y) override;
	virtual ~ball();
};

