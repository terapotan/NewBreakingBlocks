#pragma once
//��`�̃I�u�W�F�N�g�������Ă���ׂ��v�f�E�@�\�������Œ�`����B
//�v�����rectObject�̓C���^�t�F�[�X�Ƃ������Ƃł���B
//FIXME:�����������������֐������̃N���X�ɏ����A
//�����bar,ball�N���X�Ɍp�������邱��
typedef struct rectElements {
	int rectLeftUpCoordX;
	int rectLeftUpCoordY;
	int rectWidth;
	int rectHeight;
}rectElements;

class rectObject
{
protected:
	rectElements rectObjectElements;
public:
	//��`�I�u�W�F�N�g�̒l�ɃA�N�Z�X����O��
	//���̊֐����Ăяo������
	virtual void saveNowObjectStateToRectObject() = 0;
	const rectElements& getRectObjectElements();
	rectObject();
	~rectObject();
};

