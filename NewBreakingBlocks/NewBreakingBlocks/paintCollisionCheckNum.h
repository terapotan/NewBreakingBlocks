#pragma once
#include "eventExecuteClassInterface.h"
class paintCollisionCheckNum :
	public eventExecuteClassInterface
{
public:
	paintCollisionCheckNum();
	void executeEventExecuteClass() override;
	virtual ~paintCollisionCheckNum();
};

