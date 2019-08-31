#pragma once
#include "eventOccurCheckClassInterface.h"
class shouldBallMoveCheck :
	public eventOccurCheckClassInterface
{
public:
	shouldBallMoveCheck();
	std::string toStringForDebug() override;
	std::string executeEventOccurCheck() override;
	virtual ~shouldBallMoveCheck();
};

