#include "eventOccurCheckAndExecute.h"
#include "callUnknownEventExecuteClassException.h"
#include "dummyEventCheck1.h"
#include "dummyEventCheck2.h"
#include "dummyEventCheck3.h"
#include "dummyEventAction1.h"
#include "dummyEventAction2.h"
#include "dummyEventAction3.h"

//FIXME:ヘッダーファイルの取り扱いについて、スコープが最小限になるように修正

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

	//FIXME:追加の方法が冗長なような、、、
	//もっとシンプルにできる方法を考えないとだめかもしれない。
	this->eventOccurCheckClassesInAFrame.at(0).reset(new dummyEventCheck1);
	this->eventOccurCheckClassesInAFrame.at(1).reset(new dummyEventCheck2);
	this->eventOccurCheckClassesInAFrame.at(2).reset(new dummyEventCheck3);

	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction1"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction1)));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction2"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction2)));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("dummyEventAction3"), std::unique_ptr<eventExecuteClassInterface>(new dummyEventAction3)));


	this->showEventOccurCheckClassesInAFrameForDebug();


}


void eventOccurCheckAndExecute::executeOccurCheckClasses()
{

	for (const auto &e : this->eventOccurCheckClassesInAFrame) {
		std::string tmpStr = e->executeEventOccurCheck();

		if (tmpStr != EXECUTE_NOTHING) {
			this->eventExecuteClassesInAFrame.push_back(tmpStr);
		}
	}

	this->showEventExecuteClassesInAFrameForDebug();
}

void eventOccurCheckAndExecute::executeEventExecuteClasses()
{
	printfDx("EventExecuseList:");

	while (!this->eventExecuteClassesInAFrame.empty()) {

		//mがint型でdecltype(m)::interatorとすると、int::iteratorと同じ意味になる
		//decltype(m)でmの型名を取得することが出来る。
		decltype(this->eventExecuteClassSpecificStringMap)::iterator it = this->eventExecuteClassSpecificStringMap.find(this->eventExecuteClassesInAFrame.front());

		//イベントチェッククラスが返してきた文字列に対応するイベントアクションクラスが存在しない場合
		//callUnknownEventExecuteClassException例外を投げる。
		if (it == this->eventExecuteClassSpecificStringMap.end()) {
			callUnknownEventExecuteClassException expectionInstance;
			throw expectionInstance;
		}

		(it->second)->executeEventExecuteClass();
		this->eventExecuteClassesInAFrame.pop_front();
	}
	printfDx("\n");

	printfDx("EventAfterQueueListEmpty:%s", "Yes");
}

eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
