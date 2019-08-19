#pragma once
//LoadGraph�֐��̖߂�l��-1�͊��ɗ\�񂳂�Ă��邽��
//-1�̓O���t�B�b�N�n���h���̒l�Ƃ��Ă͑��݂��Ȃ��B(DX���C�u���������h�L�������g�Q�ƁB)
constexpr int NULL_GRAPHICHANDLE = -1;
class playDisplayImageManagement
{
private:
	int barImageHandle = NULL_GRAPHICHANDLE;
	int blockImageHandle = NULL_GRAPHICHANDLE;
	int ballImageHandle = NULL_GRAPHICHANDLE;
public:
	playDisplayImageManagement();
	int getBarImageHandle() const;
	int getBlockImageHandle() const;
	int getBallImageHandle() const;
	virtual ~playDisplayImageManagement();
};

