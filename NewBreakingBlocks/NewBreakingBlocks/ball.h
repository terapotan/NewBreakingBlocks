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
	//FIXME:objectsOnTheScreenの存在価値がないような気がする
	//本当にobjectsOnTheScreenを用意する必要があるか判断し、必要ならそうなるように変更
	//そうでないなら、削除・変更を行いたい
	void setObjectCoordinate(int x, int y);
	int getObjectCoordinateX();
	int getObjectCoordinateY();
	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	int getBallDiamaterPixel();
	void moveBallAtTheSetVelocity();
	void objectPaint();
	virtual ~ball();
};

