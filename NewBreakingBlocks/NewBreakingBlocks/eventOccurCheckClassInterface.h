#pragma once
#include<string>
constexpr const char* EXECUTE_NOTHING = "";

class eventOccurCheckClassInterface
{
public:
	eventOccurCheckClassInterface();
	virtual std::string toStringForDebug() = 0;

	//�C�x���g�`�F�b�N���s��
	//�C�x���g�`�F�b�N�̌��ʃC�x���g�𔭐������Ȃ���΂Ȃ�Ȃ��Ƃ���
	//eventExecuteClassInterface���������Ă���N���X�̖��O��Ԃ��K�v������B
	//�Ăяo�����ŃN���X�̖��O�ɑΉ����Ă���C�x���g�����s�����B
	//�C�x���g�𔭐������Ȃ��Ƃ���std::string(EXECUTE_NOTHING)��Ԃ��K�v������B
	virtual std::string executeEventOccurCheck() = 0;
	virtual ~eventOccurCheckClassInterface();
};

