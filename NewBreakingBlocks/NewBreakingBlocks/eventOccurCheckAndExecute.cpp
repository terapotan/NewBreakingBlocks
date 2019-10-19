#include "eventOccurCheckAndExecute.h"
#include "callUnknownEventExecuteClassException.h"
#include "setFailureEventOccurCheckClass.h"

#include "shouldBarMoveCheck.h"
#include "isHitBallAndBar.h"

#include "setVelocityBarLeft.h"
#include "setVelocityBarRight.h"
#include "setVelocityBarNoMove.h"
#include "paintCollisionCheckNum.h"


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
	try {
		//FIXME:以下の行をこのクラスから追い出したい
		//データを実際に挿入するクラスと、管理するクラスは別にしたい
		//そうすればシーンごとに使いまわしが出来る
		this->eventOccurCheckClassesInAFrame.push_back(std::unique_ptr<shouldBarMoveCheck>(new shouldBarMoveCheck()));
		this->eventOccurCheckClassesInAFrame.push_back(std::unique_ptr<isHitBallAndBar>(new isHitBallAndBar()));
		
	}
	catch (const std::out_of_range& tmpException) {
		setFailureEventOccurCheckClass exceptionUserInstance;
		exceptionUserInstance.setThrowExceptionPlace(__FILE__, __LINE__);
		throw exceptionUserInstance;
	}
	
	//FIXME:以下の行をこのクラスから追い出したい
	//データを実際に挿入するクラスと、管理するクラスは別にしたい
	//そうすればシーンごとに使いまわしが出来る
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("setVelocityBarLeft"), std::unique_ptr<setVelocityBarLeft>(new setVelocityBarLeft())));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("setVelocityBarRight"), std::unique_ptr<setVelocityBarRight>(new setVelocityBarRight())));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("setVelocityBarNoMove"), std::unique_ptr<setVelocityBarNoMove>(new setVelocityBarNoMove())));
	(this->eventExecuteClassSpecificStringMap).insert(std::make_pair(std::string("paintCollisionCheckNum"), std::unique_ptr<paintCollisionCheckNum>(new paintCollisionCheckNum())));


	//this->showEventOccurCheckClassesInAFrameForDebug();


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

eventOccurCheckAndExecute::~eventOccurCheckAndExecute()
{
}
