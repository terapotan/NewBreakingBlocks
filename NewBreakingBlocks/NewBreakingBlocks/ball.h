#pragma once
#include "rectObject.h"
class ball : public rectObject
{
private:
	//���̂̈ʒu�⑬�x�w��Ɏg�����W�͎��ۂ̍��W�ł͂Ȃ�
	//realAndVirtualCoordinateSettings.h���ɑ��݂���
	//virtualDrawScreenWidth,Height�̉��z���W�ł���B
	//�����o�ϐ��Ɋi�[����Ă�����W�̒l�����z���W�ł���B
	//���z���W�͕`�掞�Ɏ����W�ɕϊ������B

	//FIXME:���z���W���Ƃ킩��悤�ɕϐ��̖��O��ύX�����ق�������

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

