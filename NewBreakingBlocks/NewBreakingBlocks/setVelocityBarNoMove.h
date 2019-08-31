#pragma once
#include "eventExecuteClassInterface.h"

class setVelocityBarNoMove :
	public eventExecuteClassInterface
{
public:
	setVelocityBarNoMove();
	void executeEventExecuteClass(managementSceneObjects& sceneObjects);
	virtual ~setVelocityBarNoMove();
};

