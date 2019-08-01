#pragma once
#include "objectsOnTheScreen.h"
class ball: public objectsOnTheScreen
{
private:
	int ballLeftupCoordX;//画面右方向を正とする
	int ballLeftupCoordY;//画面下方向を正とする
	int ballVelocityX_PerFrame;//画面右方向を正とする
	int ballVelocityY_PerFrame;//画面下方向を正とする
	int ballRadius_Pixel;
	int ballImageHandle;
public:
	ball();
	ball(int ballLeftupCoordX, int ballLeftupCoordY);
	void setObjectCoordinate(int x, int y) override;
	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	int getBallRadiusPixel();
	void moveBallAtTheSetVelocity();
	void objectPaint() override;
	virtual ~ball();
};

