#include "dummyEventCheck2.h"


dummyEventCheck2::dummyEventCheck2()
{
}

std::string dummyEventCheck2::toStringForDebug()
{
	return std::string("dummyEventCheck2");
}

std::string dummyEventCheck2::executeEventOccurCheck()
{
	return std::string(EXECUTE_NOTHING);
}


dummyEventCheck2::~dummyEventCheck2()
{
}
