#include "eventOccurCheckAndExecute.h"
#include "dummyEventCheck1.h"
#include "dummyEventCheck2.h"
#include "dummyEventCheck3.h"

eventOccurCheckAndExecute::eventOccurCheckAndExecute()
{

	//FIXME:追加の方法が冗長なような、、、
	//もっとシンプルにできる方法を考えないとだめかもしれない。
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
