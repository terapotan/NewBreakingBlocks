#pragma once
#include "extendException.h"

class imageLoadFailureException : public extendException
{
public:
	imageLoadFailureException();
	virtual std::string getDetailThisException();
	virtual ~imageLoadFailureException();
};

