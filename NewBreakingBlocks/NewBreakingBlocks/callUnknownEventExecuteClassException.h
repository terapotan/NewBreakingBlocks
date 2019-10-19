#pragma once
#include "extendException.h"

class callUnknownEventExecuteClassException : public extendException
{
private:
	std::string unknownEventExecuteClass = "";
public:
	callUnknownEventExecuteClassException(std::string unknownClass);
	std::string getDetailThisException() const override;
	std::string getExceptionTypeName() const override;
	~callUnknownEventExecuteClassException();
};

