#include "stdafx.h"
#include "setFailureEventOccurCheckClass.h"


setFailureEventOccurCheckClass::setFailureEventOccurCheckClass()
{
}

std::string setFailureEventOccurCheckClass::getExceptionTypeName() const
{
	return std::string("setFailureEventOccurCheckClass");
}

std::string setFailureEventOccurCheckClass::getDetailThisException() const
{
	return std::string("eventOccurCheckClassのインスタンスが配列の範囲外に書き込まれました。\n配列を要素数に合わせて拡張したか確認してください。");
}


setFailureEventOccurCheckClass::~setFailureEventOccurCheckClass()
{
}
