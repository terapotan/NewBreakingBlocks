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
	//FIXME:objectsOnTheScreen�̑��݉��l���Ȃ��悤�ȋC������
	//�{����objectsOnTheScreen��p�ӂ���K�v�����邩���f���A�K�v�Ȃ炻���Ȃ�悤�ɕύX
	//�����łȂ��Ȃ�A�폜�E�ύX���s������
	void setObjectCoordinate(int x, int y);
	int getObjectCoordinateX();
	int getObjectCoordinateY();
	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	int getBallDiamaterPixel();
	void moveBallAtTheSetVelocity();
	void objectPaint();
	virtual ~ball();
};

