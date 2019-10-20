#pragma once

class block
{
private:

	int blockLeftupCoordX;
	int blockLeftupCoordY;
	int blockImageHandle;
public:
	block();
	void setBlockCoordinate(int x, int y);
	void blockPaint();
	virtual ~block();
};

