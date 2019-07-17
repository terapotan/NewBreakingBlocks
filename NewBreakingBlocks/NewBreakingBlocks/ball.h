#pragma once
class ball
{
private:
	int ballLeftupCoordX;
	int ballLeftupCoordY;
public:
	ball();
	void ballPaint();
	void setBallCoordinate(int x, int y);
	virtual ~ball();
};

