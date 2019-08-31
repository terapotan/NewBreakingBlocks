#include "userInputManagement.h"
#include "extendException.h"

userInputManagement::userInputManagement()
{
	this->previousKeyStateAll_DANGERPOINTER = new char[256];
	this->nowKeyStateAll_DANGERPOINTER = new char[256];
	this->checkKeyStateAll = 0;
}


userInputManagement::~userInputManagement()
{
	delete[](this->nowKeyStateAll_DANGERPOINTER);
	delete[](this->previousKeyStateAll_DANGERPOINTER);
}

void userInputManagement::setPreviousKeyStateAll()
{
	this->checkKeyStateAll = CheckHitKeyAll(DX_CHECKINPUT_KEY);
	GetHitKeyStateAll(this->previousKeyStateAll_DANGERPOINTER);
}

void userInputManagement::setNowKeyStateAll()
{
	this->checkKeyStateAll = CheckHitKeyAll(DX_CHECKINPUT_KEY);
	GetHitKeyStateAll(this->nowKeyStateAll_DANGERPOINTER);
}

int userInputManagement::isPreviousFrameNoPushAndNowFramePush(int checkHitKey)
{
	if (this->previousKeyStateAll_DANGERPOINTER[checkHitKey] == 0 && this->nowKeyStateAll_DANGERPOINTER[checkHitKey] == 1) {
		return 1;
	}
	else {
		return false;
	}
}

int userInputManagement::checkHitKeyAll()
{
	return this->checkKeyStateAll;
}
