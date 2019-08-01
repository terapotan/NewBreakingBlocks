#pragma once
#include "objectsOnTheScreen.h"
class ball: public objectsOnTheScreen
{
private:
	int ballLeftupCoordX;//‰æ–Ê‰E•ûŒü‚ğ³‚Æ‚·‚é
	int ballLeftupCoordY;//‰æ–Ê‰º•ûŒü‚ğ³‚Æ‚·‚é
	int ballVelocityX_PerFrame;//‰æ–Ê‰E•ûŒü‚ğ³‚Æ‚·‚é
	int ballVelocityY_PerFrame;//‰æ–Ê‰º•ûŒü‚ğ³‚Æ‚·‚é
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

