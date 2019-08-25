#pragma once
#include "eventOccurCheckClassInterface.h"

class dummyEventCheck3 : public eventOccurCheckClassInterface
{
public:
	dummyEventCheck3();
	std::string toStringForDebug() override;
	std::string executeEventOccurCheck() override;
	virtual ~dummyEventCheck3();
};

