#include "ball.h"
#include "imageLoadFailureExpection.h"
#include "realAndVirtualCoordinateSettings.h"

ball::ball(const playDisplayImageManagement& playInstance)
{
	//�{�[���̉摜�Ƃ��ēǂݍ��މ摜�͈ȉ��̗v���𖞂����Ă���K�v������܂�
	//1:�摜�̏c���Ɖ����������l�ł���ǂݍ��މ摜�ɕ`�悳��Ă���}�`���~�ł��邱��
	//2:PNG�`���̉摜�ł��邱��
	//3:�~�̒��a���摜�̉���(�������͏c��)�Ɉ�v���Ă��邱��
	//2����������Ȃ��Ɖ摜�̓��ߏ������s���Ȃ��\��������܂�
	//1��3����������Ȃ��Ɠ����蔻�菈�����������s���Ȃ��\��������܂�


	this->ballImageHandle = playInstance.getBallImageHandle();

	int ballImageSizeX, ballImageSizeY;
	GetGraphSize(ballImageHandle, &ballImageSizeX, &ballImageSizeY);

	ballDiamater_Pixel = convertToVirtualCoordinate(ballImageSizeX);
}

ball::ball(int ballLeftupCoordX, int ballLeftupCoordY, const playDisplayImageManagement& playInstance) : ball(playInstance){
	this->setBallCoordinate(ballLeftupCoordX, ballLeftupCoordY);
	this->ballImageHandle = playInstance.getBallImageHandle();
}

void ball::saveNowObjectStateToRectObject()
{
	this->rectObjectElements.rectLeftUpCoordX = this->ballLeftupCoordX;
	this->rectObjectElements.rectLeftUpCoordY = this->ballLeftupCoordY;
	this->rectObjectElements.rectWidth = this->ballDiamater_Pixel;
	this->rectObjectElements.rectHeight = this->ballDiamater_Pixel;
}

ball::~ball()
{
	DeleteGraph(ballImageHandle);
}

void ball::setBallCoordinate(int x, int y) {
	this->ballLeftupCoordX = x;
	this->ballLeftupCoordY = y;
}

int ball::getBallCoordinateX()
{
	return this->ballLeftupCoordX;
}

int ball::getBallCoordinateY()
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


void ball::ballPaint() {
	DrawGraph(convertToRealCoordinate(ballLeftupCoordX), 
		convertToRealCoordinate(ballLeftupCoordY), ballImageHandle, TRUE);
}