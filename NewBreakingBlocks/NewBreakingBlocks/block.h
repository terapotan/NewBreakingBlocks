#pragma once
#include "objectsOnTheScreen.h"

class block : public objectsOnTheScreen
{
private:
	int blockLeftupCoordX;
	int blockLeftupCoordY;
public:
	block();
	void blockPaint();
	void setObjectCoordinate(int x, int y) override;
	virtual ~block();
};

