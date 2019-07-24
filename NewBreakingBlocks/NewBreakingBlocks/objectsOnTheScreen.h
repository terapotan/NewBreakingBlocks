#pragma once
class objectsOnTheScreen
{
public:
	objectsOnTheScreen();
	virtual void setObjectCoordinate(int x, int y);
	virtual void objectPaint();
	virtual ~objectsOnTheScreen();
};