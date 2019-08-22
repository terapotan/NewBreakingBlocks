#pragma once
#include "eventOccurCheckClassInterface.h"

class dummyEventCheck2 : public eventOccurCheckClassInterface
{
public:
	dummyEventCheck2();
	std::string toStringForDebug() override;
	virtual ~dummyEventCheck2();
};

