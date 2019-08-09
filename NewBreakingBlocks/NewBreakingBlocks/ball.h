#pragma once
class ball
{
private:
	int ballLeftupCoordX;//画面右方向を正とする
	int ballLeftupCoordY;//画面下方向を正とする
	int ballVelocityX_PerFrame;//画面右方向を正とする
	int ballVelocityY_PerFrame;//画面下方向を正とする
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

