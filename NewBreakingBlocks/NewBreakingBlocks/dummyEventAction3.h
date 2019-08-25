#pragma once
#include "eventExecuteClassInterface.h"
class dummyEventAction3 :
	public eventExecuteClassInterface
{
public:
	dummyEventAction3();
	void executeEventExecuteClass() override;
	virtual ~dummyEventAction3();
};

