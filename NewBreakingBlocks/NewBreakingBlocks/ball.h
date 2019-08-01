#pragma once
#include "objectsOnTheScreen.h"
class ball: public objectsOnTheScreen
{
private:
	int ballLeftupCoordX;//��ʉE�����𐳂Ƃ���
	int ballLeftupCoordY;//��ʉ������𐳂Ƃ���
	int ballVelocityX_PerFrame;//��ʉE�����𐳂Ƃ���
	int ballVelocityY_PerFrame;//��ʉ������𐳂Ƃ���
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

