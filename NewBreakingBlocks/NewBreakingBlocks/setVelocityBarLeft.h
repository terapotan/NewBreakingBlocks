#pragma once
#include "eventExecuteClassInterface.h"
class setVelocityBarLeft :
	public eventExecuteClassInterface
{
public:
	setVelocityBarLeft();
	void executeEventExecuteClass() override;
	virtual ~setVelocityBarLeft();
};

