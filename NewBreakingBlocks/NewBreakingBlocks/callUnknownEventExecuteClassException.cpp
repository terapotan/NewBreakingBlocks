#include "callUnknownEventExecuteClassException.h"


callUnknownEventExecuteClassException::callUnknownEventExecuteClassException(std::string unknownClass)
{
	this->unknownEventExecuteClass = unknownClass;
}

std::string callUnknownEventExecuteClassException::getDetailThisException() const
{
	return std::string("ïsñæÇ»" + this->unknownEventExecuteClass + "Ç™åƒÇ—èoÇ≥ÇÍÇ‹ÇµÇΩÅB");
}

std::string callUnknownEventExecuteClassException::getExceptionTypeName() const
{
	return std::string("callUnknownEventExecuteClassException");
}


callUnknownEventExecuteClassException::~callUnknownEventExecuteClassException()
{
}
