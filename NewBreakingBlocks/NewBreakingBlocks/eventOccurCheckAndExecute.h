#pragma once
#include <array>
#include <queue>
#include <string>
#include <unordered_map>
#include "eventExecuteClassInterface.h"
#include "eventOccurCheckClassInterface.h"


class eventOccurCheckAndExecute
{
private:
	std::array<std::unique_ptr<eventOccurCheckClassInterface>,3> executeEventOccurCheckClassesInAFrame;
	std::queue<std::string> executeEventExecuteClassesInAFrame;
	std::unordered_map<std::string, eventExecuteClassInterface> eventExecuteClassSpecificStringMap;
public:
	eventOccurCheckAndExecute();
	//���̊֐��͈ȉ��̗�O�̂����ꂩ�𑗏o����\��������܂��B
	//out_of_range,(�C�x���g�`�F�b�N�֐�����A���Ă��������C�x���g�N���X��������Ȃ���O)
	void executeOccurCheckClasses();
	virtual ~eventOccurCheckAndExecute();
};

