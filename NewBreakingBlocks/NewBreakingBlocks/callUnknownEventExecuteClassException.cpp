#include "callUnknownEventExecuteClassException.h"


callUnknownEventExecuteClassException::callUnknownEventExecuteClassException(std::string unknownClass)
{
	this->unknownEventExecuteClass = unknownClass;
}

std::string callUnknownEventExecuteClassException::getDetailThisException() const
{
	return std::string("不明な" + this->unknownEventExecuteClass + "が呼び出されました。");
}

std::string callUnknownEventExecuteClassException::getExceptionTypeName() const
{
	return std::string("callUnknownEventExecuteClassException");
}


callUnknownEventExecuteClassException::~callUnknownEventExecuteClassException()
{
}
