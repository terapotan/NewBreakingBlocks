#pragma once
#include "extendException.h"
class setFailureEventOccurCheckClass :
	public extendException
{
public:
	setFailureEventOccurCheckClass();
	std::string getExceptionTypeName() const override;
	std::string getDetailThisException() const override;
	virtual ~setFailureEventOccurCheckClass();
};

