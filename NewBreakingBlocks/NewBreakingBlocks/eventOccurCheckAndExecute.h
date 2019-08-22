#pragma once
#include <array>
#include <deque>
#include <string>
#include <unordered_map>
#include "eventExecuteClassInterface.h"
#include "eventOccurCheckClassInterface.h"


class eventOccurCheckAndExecute
{
private:
	std::array<std::unique_ptr<eventOccurCheckClassInterface>,3> executeEventOccurCheckClassesInAFrame;
	std::deque<std::string> executeEventExecuteClassesInAFrame;
	std::unordered_map<std::string, eventExecuteClassInterface> eventExecuteClassSpecificStringMap;
public:
	eventOccurCheckAndExecute();
	//この関数は以下の例外のいずれかを送出する可能性があります。
	//out_of_range,(イベントチェック関数から帰ってきた発生イベントクラスが見つからない例外)
	void executeOccurCheckClasses();
	void executeEventExecuteClasses();
	virtual ~eventOccurCheckAndExecute();
};

