#pragma once
//��`�̃I�u�W�F�N�g�������Ă���ׂ��v�f�E�@�\�������Œ�`����B
//�v�����rectObject�̓C���^�t�F�[�X�Ƃ������Ƃł���B
//FIXME:�����������������֐������̃N���X�ɏ����A
//�����bar,ball�N���X�Ɍp�������邱��
class rectObject
{
protected:
	int rectLeftUpCoordX;
	int rectLeftUpCoordY;
	int rectWidth;
	int rectHeight;
public:
	//��`�I�u�W�F�N�g�̒l�ɃA�N�Z�X����O��
	//���̊֐����Ăяo������
	virtual void saveNowObjectStateToRectObject() = 0;
	int getRectLeftUpCoordX();
	int getRectLeftUpCoordY();
	int getRectWidth();
	int getRectHeight();
	rectObject();
	~rectObject();
};

