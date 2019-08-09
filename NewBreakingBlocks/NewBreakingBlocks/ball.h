#pragma once
class ball
{
private:
	int ballLeftupCoordX;//‰æ–Ê‰E•ûŒü‚ğ³‚Æ‚·‚é
	int ballLeftupCoordY;//‰æ–Ê‰º•ûŒü‚ğ³‚Æ‚·‚é
	int ballVelocityX_PerFrame;//‰æ–Ê‰E•ûŒü‚ğ³‚Æ‚·‚é
	int ballVelocityY_PerFrame;//‰æ–Ê‰º•ûŒü‚ğ³‚Æ‚·‚é
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

