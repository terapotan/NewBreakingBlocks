#pragma once
#include "eventOccurCheckClassInterface.h"

class dummyEventCheck3 : public eventOccurCheckClassInterface
{
public:
	dummyEventCheck3();
	std::string toStringForDebug() override;
	virtual ~dummyEventCheck3();
};

