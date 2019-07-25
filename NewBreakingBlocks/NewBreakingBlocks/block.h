#pragma once
#include "objectsOnTheScreen.h"

class block : public objectsOnTheScreen
{
private:
	int blockLeftupCoordX;
	int blockLeftupCoordY;
	int blockImageHandle;
public:
	block();
	void setObjectCoordinate(int x, int y) override;
	void objectPaint() override;
	virtual ~block();
};

