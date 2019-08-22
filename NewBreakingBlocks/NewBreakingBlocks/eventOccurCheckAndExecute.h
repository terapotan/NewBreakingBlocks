#pragma once
#include <array>
#include <queue>
#include <string>
#include <unordered_map>
#include "eventExecuteClassInterface.h"
#include "eventCheckClassInterface.h"

class eventOccurCheckAndExecute
{
private:
	std::array<eventCheckClassInterface,3> executeEventCheckClassClassesInAFrame;
	std::queue<std::string> executeEventExecuteClassesInAFrame;
	std::unordered_map<std::string, eventExecuteClassInterface> eventExecuteClassSpecificStringMap;
public:
	eventOccurCheckAndExecute();
	virtual ~eventOccurCheckAndExecute();
};

