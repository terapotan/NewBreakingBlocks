#pragma once
class objectsOnTheScreen
{
public:
	objectsOnTheScreen();
	virtual void setObjectCoordinate(int x, int y) = 0;
	virtual void objectPaint() = 0;
	virtual ~objectsOnTheScreen();
};