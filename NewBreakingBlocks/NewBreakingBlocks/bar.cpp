#include "bar.h"


bar::bar()
{
	//FIXME:�摜�ǂݍ��ݎ��s���̏�������������Ă��Ȃ�
	//�摜�ǂݍ��ݎ��s����imageLoadFailuereExpection��O�𑗏o����悤�ɂ��Ȃ���΂Ȃ�Ȃ�
	barImageHandle = LoadGraph("../.././resource/bar.png");
}


bar::~bar()
{
	DeleteGraph(barImageHandle);
}




void bar::setObjectCoordinate(int x, int y) {
	this->barLeftupCoordX = x;
	this->barLeftupCoordY = y;
}

void bar::objectPaint() {
	DrawGraph(barLeftupCoordX, barLeftupCoordY, barImageHandle,TRUE);
}