#pragma once
#include "eventExecuteClassInterface.h"
class dummyEventAction1 :
	public eventExecuteClassInterface
{
public:
	dummyEventAction1();
	void executeEventExecuteClass() override;
	virtual ~dummyEventAction1();
};

