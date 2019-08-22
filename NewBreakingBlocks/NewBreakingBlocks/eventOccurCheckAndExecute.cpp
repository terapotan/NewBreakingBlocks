#include "eventOccurCheckAndExecute.h"
#include "dummyEventCheck1.h"
#include "dummyEventCheck2.h"
#include "dummyEventCheck3.h"
#include "dummyEventAction1.h"

eventOccurCheckAndExecute::eventOccurCheckAndExecute()
{

	//FIXME:追加の方法が冗長なような、、、
	//もっとシンプルにできる方法を考えないとだめかもしれない。
	this->executeEventOccurCheckClassesInAFrame.at(0).reset(new dummyEventCheck1);
	this->executeEventOccurCheckClassesInAFrame.at(1).reset(new dummyEventCheck2);
	this->executeEventOccurCheckClassesInAFrame.at(2).reset(new dummyEventCheck3);

	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("sss"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction1)));



	printfDx("EventCheckList:");

	//FIXME:後で関数にまとめること
	for (const auto &e : this->executeEventOccurCheckClassesInAFrame) {
		printfDx("%s,", (e->toStringForDebug()).c_str());
	}

	printfDx("\n");

}


void eventOccurCheckAndExecute::executeOccurCheckClasses()
{
	printfDx("EventQueueList:");

	for (const auto &e : this->executeEventOccurCheckClassesInAFrame) {
		std::string tmpStr = e->executeEventOccurCheck();

		if (tmpStr != EXECUTE_NOTHING) {
			this->executeEventExecuteClassesInAFrame.push_back(tmpStr);
		}
	}
	//FIXME:後で関数にまとめること
	for (const auto &e : this->executeEventExecuteClassesInAFrame) {
		printfDx("%s,", e.c_str());
	}
	printfDx("\n");
}

void eventOccurCheckAndExecute::executeEventExecuteClasses()
{
	printfDx("EventExecuseList:");
	printfDx("%s", "dummyEventAction1,dummyEventAction2,dummyEventAction3,");
	printfDx("\n");

	printfDx("EventAfterQueueListEmpty:%s", "Yes");
}

eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
