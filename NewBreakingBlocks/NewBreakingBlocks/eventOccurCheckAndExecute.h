#pragma once
#include <list>
#include <deque>
#include <string>
#include <unordered_map>
#include "eventExecuteClassInterface.h"
#include "eventOccurCheckClassInterface.h"
#include "managementSceneObjects.h"

class eventOccurCheckAndExecute
{
private:
	std::list<std::unique_ptr<eventOccurCheckClassInterface>> eventOccurCheckClassesInAFrame;
	std::deque<std::string> eventExecuteClassesInAFrame;
	std::unordered_map<std::string, std::unique_ptr<eventExecuteClassInterface>> eventExecuteClassSpecificStringMap;
	void showEventOccurCheckClassesInAFrameForDebug();
	void showEventExecuteClassesInAFrameForDebug();
public:
	eventOccurCheckAndExecute();
	
	void executeOccurCheckClasses(managementSceneObjects& sceneObjects);
	void executeEventExecuteClasses(managementSceneObjects& sceneObjects);
	virtual ~eventOccurCheckAndExecute();

	eventOccurCheckAndExecute(const eventOccurCheckAndExecute&) = delete;
	eventOccurCheckAndExecute& operator=(const eventOccurCheckAndExecute&) = delete;
	eventOccurCheckAndExecute(eventOccurCheckAndExecute&&) = delete;
	eventOccurCheckAndExecute& operator=(eventOccurCheckAndExecute&&) = delete;
};

