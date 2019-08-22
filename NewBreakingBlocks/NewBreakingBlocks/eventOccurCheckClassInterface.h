#pragma once
#include<string>

class eventOccurCheckClassInterface
{
public:
	eventOccurCheckClassInterface();
	virtual std::string toStringForDebug() = 0;
	virtual ~eventOccurCheckClassInterface();
};

