#pragma once
class block
{
private:
	int blockLeftupCoordX;
	int blockLeftupCoordY;
public:
	block();
	void blockPaint();
	void setBlockCoordinate(int x, int y);
	virtual ~block();
};

