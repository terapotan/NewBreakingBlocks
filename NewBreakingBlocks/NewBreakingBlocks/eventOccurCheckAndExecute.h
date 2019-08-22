#pragma once
#include <array>
#include <queue>
#include <string>
#include <unordered_map>
#include "eventExecuteClassInterface.h"
#include "eventOccurCheckClassInterface.h"


class eventOccurCheckAndExecute
{
private:
	std::array<std::unique_ptr<eventOccurCheckClassInterface>,3> executeEventOccurCheckClassesInAFrame;
	std::queue<std::string> executeEventExecuteClassesInAFrame;
	std::unordered_map<std::string, eventExecuteClassInterface> eventExecuteClassSpecificStringMap;
public:
	eventOccurCheckAndExecute();
	virtual ~eventOccurCheckAndExecute();
};

