#pragma once
#include "ball.h"
#include "bar.h"
#include "hitJudgementBetweenObjects.h"
#include "eventOccurCheckAndExecute.h"

class managementSceneObjects
{
private:
	std::shared_ptr<playDisplayImageManagement> playDisplayImageManagementInstance;
	std::shared_ptr<bar> barInstance;
	std::shared_ptr<ball> ballInstance;
	std::shared_ptr<hitJudgementBetweenObjects> hitJudgementBetweenObjects;
	std::shared_ptr<eventOccurCheckAndExecute> eventOccurCheckAndExecuteInstance;

public:
	managementSceneObjects();
	virtual ~managementSceneObjects();
};

