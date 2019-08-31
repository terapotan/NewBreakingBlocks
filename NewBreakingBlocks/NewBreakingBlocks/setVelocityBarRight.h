#pragma once
#include "eventExecuteClassInterface.h"
class setVelocityBarRight :
	public eventExecuteClassInterface
{
public:
	setVelocityBarRight();
	void executeEventExecuteClass() override;
	virtual ~setVelocityBarRight();
};

