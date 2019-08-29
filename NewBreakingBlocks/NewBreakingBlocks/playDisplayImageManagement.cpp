#include "playDisplayImageManagement.h"
#include "imageLoadFailureException.h"

inline void ifNullNothingDeleteGraph(int graphicHandle) {
	//�����O���t�B�b�N�n���h����NULL�l�Ȃ牽�����Ȃ�
	if (graphicHandle == NULL_GRAPHICHANDLE) {
		return;
	}
	//NULL�l�ȊO�Ȃ������s��
	DeleteGraph(graphicHandle);
}

playDisplayImageManagement::playDisplayImageManagement()
{


	//FIXME:�G���[�������璷�ł��邽�߁A
	//�����ƃV���v���ɏ�����悤�ɂ������B
	this->ballImageHandle = LoadGraph("../.././resource/ball.png");
	this->barImageHandle = LoadGraph("../.././resource/bar.png");
	this->blockImageHandle = LoadGraph("../.././resource/block.png");

	bool isBallImageLoadFail = (ballImageHandle == -1);
	bool isBarImageLoadFail= (barImageHandle == -1);
	bool isBlockImageLoadFail = (blockImageHandle == -1);

	imageLoadFailureException imageErrorInstance;

	if (isBallImageLoadFail) {
		this->ballImageHandle = NULL_GRAPHICHANDLE;
		imageErrorInstance.setThrowExceptionPlace(__FILE__, __LINE__);
		imageErrorInstance.setLoadFailureFileName("ball.png");
		throw imageErrorInstance;
	}
	else if (isBarImageLoadFail) {
		this->barImageHandle = NULL_GRAPHICHANDLE;
		imageErrorInstance.setThrowExceptionPlace(__FILE__, __LINE__);
		imageErrorInstance.setLoadFailureFileName("bar.png");
		throw imageErrorInstance;
	}
	else if (isBlockImageLoadFail) {
		this->blockImageHandle = NULL_GRAPHICHANDLE;
		imageErrorInstance.setThrowExceptionPlace(__FILE__, __LINE__);
		imageErrorInstance.setLoadFailureFileName("block.png");
		throw imageErrorInstance;
	}



}

int playDisplayImageManagement::getBarImageHandle() const
{
	return this->barImageHandle;
}

int playDisplayImageManagement::getBlockImageHandle() const
{
	return this->blockImageHandle;
}

int playDisplayImageManagement::getBallImageHandle() const
{
	return this->ballImageHandle;
}



playDisplayImageManagement::~playDisplayImageManagement()
{
	ifNullNothingDeleteGraph(this->ballImageHandle);
	ifNullNothingDeleteGraph(this->barImageHandle);
	ifNullNothingDeleteGraph(this->blockImageHandle);
}