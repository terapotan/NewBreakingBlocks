#pragma once
#include "eventExecuteClassInterface.h"

class setVelocityBarRight :
	public eventExecuteClassInterface
{
public:
	setVelocityBarRight();
	void executeEventExecuteClass(managementSceneObjects& sceneObjects) override;
	virtual ~setVelocityBarRight();
};

