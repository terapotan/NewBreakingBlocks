#pragma once
#include <array>
#include <deque>
#include <string>
#include <unordered_map>
#include "eventExecuteClassInterface.h"
#include "eventOccurCheckClassInterface.h"


class eventOccurCheckAndExecute
{
private:
	std::array<std::unique_ptr<eventOccurCheckClassInterface>,2> eventOccurCheckClassesInAFrame;
	std::deque<std::string> eventExecuteClassesInAFrame;
	std::unordered_map<std::string, std::unique_ptr<eventExecuteClassInterface>> eventExecuteClassSpecificStringMap;
	void showEventOccurCheckClassesInAFrameForDebug();
	void showEventExecuteClassesInAFrameForDebug();
public:
	eventOccurCheckAndExecute();
	//���̊֐��͈ȉ��̗�O�̂����ꂩ�𑗏o����\��������܂��B
	//out_of_range,(�C�x���g�`�F�b�N�֐�����A���Ă��������C�x���g�N���X��������Ȃ���O)
	void executeOccurCheckClasses();
	void executeEventExecuteClasses();
	virtual ~eventOccurCheckAndExecute();

	eventOccurCheckAndExecute(const eventOccurCheckAndExecute&) = delete;
	eventOccurCheckAndExecute& operator=(const eventOccurCheckAndExecute&) = delete;
	eventOccurCheckAndExecute(eventOccurCheckAndExecute&&) = delete;
	eventOccurCheckAndExecute& operator=(eventOccurCheckAndExecute&&) = delete;
};

