#pragma once
#include "eventOccurCheckClassInterface.h"
class isHitBallAndBar :
	public eventOccurCheckClassInterface
{
public:
	isHitBallAndBar();
	virtual ~isHitBallAndBar();
	std::string toStringForDebug() override;
	std::string executeEventOccurCheck(managementSceneObjects& sceneObjects) override;
};

