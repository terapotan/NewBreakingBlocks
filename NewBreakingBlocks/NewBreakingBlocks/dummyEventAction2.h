#pragma once
#include "eventExecuteClassInterface.h"
class dummyEventAction2 :
	public eventExecuteClassInterface
{
public:
	dummyEventAction2();
	void executeEventExecuteClass() override;
	virtual ~dummyEventAction2();
};

