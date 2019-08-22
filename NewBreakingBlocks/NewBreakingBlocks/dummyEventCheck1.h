#pragma once
#include"eventOccurCheckClassInterface.h"

class dummyEventCheck1 : public eventOccurCheckClassInterface
{
public:
	dummyEventCheck1();
	std::string toStringForDebug() override;
	virtual ~dummyEventCheck1();
};

