#pragma once
class ball
{
private:
	int ballLeftupCoordX;//��ʉE�����𐳂Ƃ���
	int ballLeftupCoordY;//��ʉ������𐳂Ƃ���
	int ballVelocityX_PerFrame;//��ʉE�����𐳂Ƃ���
	int ballVelocityY_PerFrame;//��ʉ������𐳂Ƃ���
	int ballDiamater_Pixel;
	int ballImageHandle;
public:
	ball();
	ball(int ballLeftupCoordX, int ballLeftupCoordY);
	void setBallCoordinate(int x, int y);
	int getBallCoordinateX();
	int getBallCoordinateY();
	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	int getBallDiamaterPixel();
	void moveBallAtTheSetVelocity();
	void ballPaint();
	virtual ~ball();
};

