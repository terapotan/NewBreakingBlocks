#include "dummyEventCheck1.h"


dummyEventCheck1::dummyEventCheck1()
{
}

std::string dummyEventCheck1::toStringForDebug()
{
	return std::string("dummyEventCheck1");
}

std::string dummyEventCheck1::executeEventOccurCheck()
{
	return std::string("dummyEventAction1");
}


dummyEventCheck1::~dummyEventCheck1()
{
}
