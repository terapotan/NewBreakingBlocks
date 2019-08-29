#pragma once
#include "extendException.h"

class imageLoadFailureException : public extendException
{
private:
	std::string loadFailureFileName;
public:
	imageLoadFailureException();
	virtual std::string getDetailThisException() const override;
	virtual std::string getExceptionTypeName() const override;
	void setLoadFailureFileName(std::string failureFileName);
	virtual ~imageLoadFailureException();
};

