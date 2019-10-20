#include "eventOccurCheckAndExecute.h"
#include "callUnknownEventExecuteClassException.h"
#include "setFailureEventOccurCheckClass.h"





#include <utility>

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

}


void eventOccurCheckAndExecute::executeOccurCheckClasses(managementSceneObjects& sceneObjects)
{
	auto firstElementInList = this->eventOccurCheckClassesInAFrame.begin();
	//1件もeventOccurCheckClassが登録されていない時は何もしない
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

		//mがint型でdecltype(m)::interatorとすると、int::iteratorと同じ意味になる
		//decltype(m)でmの型名を取得することが出来る。
		std::string keyCallEventExecuteClass = this->eventExecuteClassesInAFrame.front();
		decltype(this->eventExecuteClassSpecificStringMap)::iterator it = this->eventExecuteClassSpecificStringMap.find(keyCallEventExecuteClass);

		//イベントチェッククラスが返してきた文字列に対応するイベントアクションクラスが存在しない場合
		//callUnknownEventExecuteClassException例外を投げる。
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
