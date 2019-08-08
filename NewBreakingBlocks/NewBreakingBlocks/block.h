#pragma once

class block
{
private:
	int blockLeftupCoordX;
	int blockLeftupCoordY;
	int blockImageHandle;
public:
	block();
	void setObjectCoordinate(int x, int y);
	void objectPaint();
	virtual ~block();
};

