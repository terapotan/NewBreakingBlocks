#pragma once
class objectsOnTheScreen
{
private:
	int objectCoordinateX;
	int objectCoordinateY;
public:
	objectsOnTheScreen();
	virtual void setObjectCoordinate(int x, int y) = 0;
	virtual ~objectsOnTheScreen();
};