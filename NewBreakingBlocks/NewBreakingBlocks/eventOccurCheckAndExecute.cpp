#include "eventOccurCheckAndExecute.h"
#include "callUnknownEventExecuteClassException.h"
#include "setFailureEventOccurCheckClass.h"





#include <utility>

//FIXME:�w�b�_�[�t�@�C���̎�舵���ɂ��āA�X�R�[�v���ŏ����ɂȂ�悤�ɏC��

void eventOccurCheckAndExecute::showEventOccurCheckClassesInAFrameForDebug()
{

	printfDx("EventOccurCheckClassesInAFrame:");

	for (const auto &e : this->eventOccurCheckClassesInAFrame) {
		printfDx("%s,", (e->toStringForDebug()).c_str());
	}

	printfDx("\n");
}

void eventOccurCheckAndExecute::showEventExecuteClassesInAFrameForDebug()
{
	printfDx("EventExecuteClassesInAFrame:");

	for (const auto &e : this->eventExecuteClassesInAFrame) {
		printfDx("%s,", e.c_str());
	}

	printfDx("\n");
}

eventOccurCheckAndExecute::eventOccurCheckAndExecute()
{

}


void eventOccurCheckAndExecute::executeOccurCheckClasses(managementSceneObjects& sceneObjects)
{
	auto firstElementInList = this->eventOccurCheckClassesInAFrame.begin();
	//1����eventOccurCheckClass���o�^����Ă��Ȃ����͉������Ȃ�
	if (*firstElementInList == nullptr) {
		return;
	}


	for (const auto &e : this->eventOccurCheckClassesInAFrame) {
		std::string tmpStr = e->executeEventOccurCheck(sceneObjects);

		if (tmpStr != EXECUTE_NOTHING) {
			this->eventExecuteClassesInAFrame.push_back(tmpStr);
		}
	}

	//this->showEventExecuteClassesInAFrameForDebug();
}

void eventOccurCheckAndExecute::executeEventExecuteClasses(managementSceneObjects& sceneObjects)
{
	//printfDx("EventExecuseList:");

	while (!this->eventExecuteClassesInAFrame.empty()) {

		//m��int�^��decltype(m)::interator�Ƃ���ƁAint::iterator�Ɠ����Ӗ��ɂȂ�
		//decltype(m)��m�̌^�����擾���邱�Ƃ��o����B
		std::string keyCallEventExecuteClass = this->eventExecuteClassesInAFrame.front();
		decltype(this->eventExecuteClassSpecificStringMap)::iterator it = this->eventExecuteClassSpecificStringMap.find(keyCallEventExecuteClass);

		//�C�x���g�`�F�b�N�N���X���Ԃ��Ă���������ɑΉ�����C�x���g�A�N�V�����N���X�����݂��Ȃ��ꍇ
		//callUnknownEventExecuteClassException��O�𓊂���B
		if (it == this->eventExecuteClassSpecificStringMap.end()) {
			callUnknownEventExecuteClassException expectionInstance(keyCallEventExecuteClass);
			expectionInstance.setThrowExceptionPlace(__FILE__, __LINE__);
			throw expectionInstance;
		}

		(it->second)->executeEventExecuteClass(sceneObjects);
		this->eventExecuteClassesInAFrame.pop_front();
	}
	//printfDx("\n");

	//printfDx("EventAfterQueueListEmpty:%s", "Yes");
}

std::list<std::unique_ptr<eventOccurCheckClassInterface>>& eventOccurCheckAndExecute::getEventOccurCheckClassList()
{
	return eventOccurCheckClassesInAFrame;
}

std::unordered_map<std::string, std::unique_ptr<eventExecuteClassInterface>>& eventOccurCheckAndExecute::getEventExecuteClassMap()
{
	return eventExecuteClassSpecificStringMap;
}




eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
