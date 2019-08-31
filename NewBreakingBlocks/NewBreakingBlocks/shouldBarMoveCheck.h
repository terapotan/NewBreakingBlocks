#pragma once
#include "eventOccurCheckClassInterface.h"
class shouldBarMoveCheck :
	public eventOccurCheckClassInterface
{
public:
	shouldBarMoveCheck();
	std::string toStringForDebug() override;
	std::string executeEventOccurCheck(managementSceneObjects& sceneObjects) override;
	virtual ~shouldBarMoveCheck();
};

