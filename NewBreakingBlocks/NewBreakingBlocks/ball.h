#pragma once
#include "rectObject.h"
#include "playDisplayImageManagement.h"

class ball : public rectObject
{
private:
	//���̂̈ʒu�⑬�x�w��Ɏg�����W�͎��ۂ̍��W�ł͂Ȃ�
	//realAndVirtualCoordinateSettings.h���ɑ��݂���
	//virtualDrawScreenWidth,Height�̉��z���W�ł���B
	//�����o�ϐ��Ɋi�[����Ă�����W�̒l�����z���W�ł���B
	//���z���W�͕`�掞�Ɏ����W�ɕϊ������B
	//�摜�̑傫�����̐��l�����z���W�ł���


	int ballLeftupCoordX;//��ʉE�����𐳂Ƃ���
	int ballLeftupCoordY;//��ʉ������𐳂Ƃ���
	int ballVelocityX_PerFrame;//��ʉE�����𐳂Ƃ���
	int ballVelocityY_PerFrame;//��ʉ������𐳂Ƃ���
	int ballDiamater_Pixel;
	int ballImageHandle;
public:
	ball(const playDisplayImageManagement& playInstance);
	ball(int ballLeftupCoordX, int ballLeftupCoordY, const playDisplayImageManagement& playInstance);
	void setBallCoordinate(int x, int y);
	int getBallCoordinateX();
	int getBallCoordinateY();
	int getBallDiamaterPixel();

	void setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame);
	void moveBallAtTheSetVelocity();

	void ballPaint();

	void saveNowObjectStateToRectObject() override;
	virtual ~ball();
};

