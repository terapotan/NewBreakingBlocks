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
	std::array<std::unique_ptr<eventOccurCheckClassInterface>,2> eventOccurCheckClassesInAFrame;
	std::deque<std::string> eventExecuteClassesInAFrame;
	std::unordered_map<std::string, std::unique_ptr<eventExecuteClassInterface>> eventExecuteClassSpecificStringMap;
	void showEventOccurCheckClassesInAFrameForDebug();
	void showEventExecuteClassesInAFrameForDebug();
public:
	eventOccurCheckAndExecute();
	//この関数は以下の例外のいずれかを送出する可能性があります。
	//out_of_range,(イベントチェック関数から帰ってきた発生イベントクラスが見つからない例外)
	void executeOccurCheckClasses();
	void executeEventExecuteClasses();
	virtual ~eventOccurCheckAndExecute();

	eventOccurCheckAndExecute(const eventOccurCheckAndExecute&) = delete;
	eventOccurCheckAndExecute& operator=(const eventOccurCheckAndExecute&) = delete;
	eventOccurCheckAndExecute(eventOccurCheckAndExecute&&) = delete;
	eventOccurCheckAndExecute& operator=(eventOccurCheckAndExecute&&) = delete;
};

