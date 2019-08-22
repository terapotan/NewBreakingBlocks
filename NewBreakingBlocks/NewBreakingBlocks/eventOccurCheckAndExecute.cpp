#include "eventOccurCheckAndExecute.h"
#include "dummyEventCheck1.h"
#include "dummyEventCheck2.h"
#include "dummyEventCheck3.h"
#include "dummyEventAction1.h"
#include "dummyEventAction2.h"
#include "dummyEventAction3.h"
//FIXME:�w�b�_�[�t�@�C���̎�舵���ɂ��āA�X�R�[�v���ŏ����ɂȂ�悤�ɏC��

eventOccurCheckAndExecute::eventOccurCheckAndExecute()
{

	//FIXME:�ǉ��̕��@���璷�Ȃ悤�ȁA�A�A
	//�����ƃV���v���ɂł�����@���l���Ȃ��Ƃ��߂�������Ȃ��B
	this->eventOccurCheckClassesInAFrame.at(0).reset(new dummyEventCheck1);
	this->eventOccurCheckClassesInAFrame.at(1).reset(new dummyEventCheck2);
	this->eventOccurCheckClassesInAFrame.at(2).reset(new dummyEventCheck3);

	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction1"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction1)));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction2"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction2)));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction3"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction3)));

	printfDx("EventCheckList:");

	//FIXME:��Ŋ֐��ɂ܂Ƃ߂邱��
	for (const auto &e : this->eventOccurCheckClassesInAFrame) {
		printfDx("%s,", (e->toStringForDebug()).c_str());
	}

	printfDx("\n");

}


void eventOccurCheckAndExecute::executeOccurCheckClasses()
{
	printfDx("EventQueueList:");

	for (const auto &e : this->eventOccurCheckClassesInAFrame) {
		std::string tmpStr = e->executeEventOccurCheck();

		if (tmpStr != EXECUTE_NOTHING) {
			this->eventExecuteClassesInAFrame.push_back(tmpStr);
		}
	}
	//FIXME:��Ŋ֐��ɂ܂Ƃ߂邱��
	for (const auto &e : this->eventExecuteClassesInAFrame) {
		printfDx("%s,", e.c_str());
	}
	printfDx("\n");
}

void eventOccurCheckAndExecute::executeEventExecuteClasses()
{
	printfDx("EventExecuseList:");
	//FIXME:��ŗ�O����(�L�[�ɑΉ�����l��������Ȃ�)������Ƃ����ƁB
	while (!this->eventExecuteClassesInAFrame.empty()) {
		decltype(this->eventExecuteClassSpecificStringMap)::iterator it = this->eventExecuteClassSpecificStringMap.find(this->eventExecuteClassesInAFrame.front());
		(it->second)->executeEventExecuteClass();
		this->eventExecuteClassesInAFrame.pop_front();
	}
	printfDx("\n");

	printfDx("EventAfterQueueListEmpty:%s", "Yes");
}

eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
