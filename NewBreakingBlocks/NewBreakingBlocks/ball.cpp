#include "ball.h"
#include "imageLoadFailureExpection.h"

ball::ball()
{
	//�{�[���̉摜�Ƃ��ēǂݍ��މ摜�͈ȉ��̗v���𖞂����Ă���K�v������܂�
	//1:�摜�̏c���Ɖ����������l�ł���ǂݍ��މ摜�ɕ`�悳��Ă���}�`���~�ł��邱��
	//2:PNG�`���̉摜�ł��邱��
	//3:�~�̒��a���摜�̉���(�������͏c��)�Ɉ�v���Ă��邱��
	//2����������Ȃ��Ɖ摜�̓��ߏ������s���Ȃ��\��������܂�
	//1��3����������Ȃ��Ɠ����蔻�菈�����������s���Ȃ��\��������܂�

	ballImageHandle = LoadGraph("../.././resource/ball.png");

	if (ballImageHandle == -1) {
		imageLoadFailureExpection imageLoadInstance;
		throw imageLoadInstance;
	}


	
	int ballImageSizeX, ballImageSizeY;
	GetGraphSize(ballImageHandle, &ballImageSizeX, &ballImageSizeY);

	ballDiamater_Pixel = ballImageSizeX;

}

ball::ball(int ballLeftupCoordX, int ballLeftupCoordY) : ball()
{
	this->setObjectCoordinate(ballLeftupCoordX, ballLeftupCoordY);
}


ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setObjectCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

int ball::getObjectCoordinateX()
{
	return this->ballLeftupCoordX;
}

int ball::getObjectCoordinateY()
{
	return this->ballLeftupCoordY;
}

void ball::setBallVelocity(int ballVelocityX_PerFrame, int ballVelocityY_PerFrame)
{
	this->ballVelocityX_PerFrame = ballVelocityX_PerFrame;
	this->ballVelocityY_PerFrame = ballVelocityY_PerFrame;
}

int ball::getBallDiamaterPixel()
{
	return this->ballDiamater_Pixel;
}

void ball::moveBallAtTheSetVelocity()
{
	this->ballLeftupCoordX += this->ballVelocityX_PerFrame;
	this->ballLeftupCoordY += this->ballVelocityY_PerFrame;
}


void ball::objectPaint() {
	DrawGraph(ballLeftupCoordX, ballLeftupCoordY, ballImageHandle, TRUE);
}