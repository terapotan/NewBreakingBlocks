#include "shouldBarMoveCheck.h"
#include "userInputManagement.h"

shouldBarMoveCheck::shouldBarMoveCheck()
{
}

std::string shouldBarMoveCheck::toStringForDebug()
{
	return std::string("shouldBarMoveCheck");
}

std::string shouldBarMoveCheck::executeEventOccurCheck(managementSceneObjects& sceneObjects)
{

	if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
		return std::string("setVelocityBarLeft");
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
		return std::string("setVelocityBarRight");
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0) {
		return std::string("setVelocityBarNoMove");
	}

	return std::string(EXECUTE_NOTHING);
}


shouldBarMoveCheck::~shouldBarMoveCheck()
{
}
