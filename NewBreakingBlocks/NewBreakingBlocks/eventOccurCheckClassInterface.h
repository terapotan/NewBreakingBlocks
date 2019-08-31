#pragma once
#include<string>
#include "managementSceneObjects.h"

constexpr const char* EXECUTE_NOTHING = "";

class eventOccurCheckClassInterface
{
public:
	eventOccurCheckClassInterface();
	//自身のクラス名をこの関数の戻り値とすること
	virtual std::string toStringForDebug() = 0;

	//イベントチェックを行う
	//イベントチェックの結果イベントを発生させなければならないときは
	//eventExecuteClassInterfaceを実装しているクラスの名前を返す必要がある。
	//呼び出し元でクラスの名前に対応しているイベントが実行される。
	//イベントを発生させないときはstd::string(EXECUTE_NOTHING)を返す必要がある。
	virtual std::string executeEventOccurCheck(managementSceneObjects& sceneObjects) = 0;
	virtual ~eventOccurCheckClassInterface();
};
