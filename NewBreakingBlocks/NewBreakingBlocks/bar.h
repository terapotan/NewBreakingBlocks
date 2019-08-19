#pragma once
#include "rectObject.h"
#include "playDisplayImageManagement.h"

class bar : public rectObject
{
private:
	//���̂̈ʒu�⑬�x�w��Ɏg�����W�͎��ۂ̍��W�ł͂Ȃ�
	//realAndVirtualCoordinateSettings.h���ɑ��݂���
	//virtualDrawScreenWidth,Height�̉��z���W�ł���B
	//�����o�ϐ��Ɋi�[����Ă�����W�̒l�����z���W�ł���B
	//���z���W�͕`�掞�Ɏ����W�ɕϊ������B

	int barLeftupCoordX;
	int barLeftupCoordY;
	int barVelocityX_PerFrame;
	int barImageHandle;
	int barWidth_Pixel;
	int barHeight_Pixel;

public:
	bar(const playDisplayImageManagement& playInstance);
	bar(int barLeftupCoordX, int barLeftupCoordY, const playDisplayImageManagement& playInstance);

	void setBarCoordinate(int x, int y);
	int getBarCoordinateX();
	int getBarCoordinateY();
	int getBarWidthPixel();
	int getBarHeightPixel();

	void setBarVelocity(int ballVelocityX_PerFrame);
	void moveBarAtTheSetVelocity();

	void barPaint();

	void saveNowObjectStateToRectObject() override;

	virtual ~bar();
};

