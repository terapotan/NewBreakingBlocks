#include "eventOccurCheckAndExecute.h"
#include "dummyEventCheck1.h"
#include "dummyEventCheck2.h"
#include "dummyEventCheck3.h"

eventOccurCheckAndExecute::eventOccurCheckAndExecute()
{

	//FIXME:�ǉ��̕��@���璷�Ȃ悤�ȁA�A�A
	//�����ƃV���v���ɂł�����@���l���Ȃ��Ƃ��߂�������Ȃ��B
	this->executeEventOccurCheckClassesInAFrame.at(0).reset(new dummyEventCheck1);
	this->executeEventOccurCheckClassesInAFrame.at(1).reset(new dummyEventCheck2);
	this->executeEventOccurCheckClassesInAFrame.at(2).reset(new dummyEventCheck3);

	printfDx("EventCheckList:");
	for (const auto &e : this->executeEventOccurCheckClassesInAFrame) {
		printfDx("%s,", (e->toStringForDebug()).c_str());
	}

}


void eventOccurCheckAndExecute::executeOccurCheckClasses()
{
	for (const auto &e : this->executeEventOccurCheckClassesInAFrame) {
		e->executeEventOccurCheck();
	}
}

eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
