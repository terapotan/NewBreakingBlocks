#pragma once
#include "eventExecuteClassInterface.h"
class paintCollisionCheckNum :
	public eventExecuteClassInterface
{
public:
	paintCollisionCheckNum();
	void executeEventExecuteClass(managementSceneObjects& sceneObjects) override;
	virtual ~paintCollisionCheckNum();
};

