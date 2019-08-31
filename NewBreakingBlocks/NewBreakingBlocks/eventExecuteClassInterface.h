#pragma once
#include "managementSceneObjects.h"

class eventExecuteClassInterface
{
public:
	eventExecuteClassInterface();
	virtual void executeEventExecuteClass(managementSceneObjects& sceneObjects) = 0;
	virtual ~eventExecuteClassInterface();
};

