#include "eventOccurCheckAndExecute.h"
#include "callUnknownEventExecuteClassException.h"
#include "setFailureEventOccurCheckClass.h"

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

	//FIXME:�ǉ��̕��@���璷�Ȃ悤�ȁA�A�A
	//�����ƃV���v���ɂł�����@���l���Ȃ��Ƃ��߂�������Ȃ��B

	try {
		/*
		this->eventOccurCheckClassesInAFrame.at(0).reset(new dummyEventCheck1);
		this->eventOccurCheckClassesInAFrame.at(1).reset(new dummyEventCheck2);
		this->eventOccurCheckClassesInAFrame.at(2).reset(new dummyEventCheck3);
		*/
	}
	catch (const std::out_of_range& tmpException) {
		setFailureEventOccurCheckClass exceptionUserInstance;
		exceptionUserInstance.setThrowExceptionPlace(__FILE__, __LINE__);
		throw exceptionUserInstance;
	}
	/*
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction1"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction1)));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction2"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction2)));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction3"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction3)));
	*/

	//this->showEventOccurCheckClassesInAFrameForDebug();


}


void eventOccurCheckAndExecute::executeOccurCheckClasses()
{
	//1����eventOccurCheckClass���o�^����Ă��Ȃ����͉������Ȃ�
	if (this->eventOccurCheckClassesInAFrame.at(0) == nullptr) {
		return;
	}


	for (const auto &e : this->eventOccurCheckClassesInAFrame) {
		std::string tmpStr = e->executeEventOccurCheck();

		if (tmpStr != EXECUTE_NOTHING) {
			this->eventExecuteClassesInAFrame.push_back(tmpStr);
		}
	}

	//this->showEventExecuteClassesInAFrameForDebug();
}

void eventOccurCheckAndExecute::executeEventExecuteClasses()
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

		(it->second)->executeEventExecuteClass();
		this->eventExecuteClassesInAFrame.pop_front();
	}
	//printfDx("\n");

	//printfDx("EventAfterQueueListEmpty:%s", "Yes");
}

eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
