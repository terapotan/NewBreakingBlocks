#include "callUnknownEventExecuteClassException.h"


callUnknownEventExecuteClassException::callUnknownEventExecuteClassException(std::string unknownClass)
{
	this->unknownEventExecuteClass = unknownClass;
}

std::string callUnknownEventExecuteClassException::getDetailThisException() const
{
	return std::string("�s����" + this->unknownEventExecuteClass + "���Ăяo����܂����B");
}

std::string callUnknownEventExecuteClassException::getExceptionTypeName() const
{
	return std::string("callUnknownEventExecuteClassException");
}


callUnknownEventExecuteClassException::~callUnknownEventExecuteClassException()
{
}
