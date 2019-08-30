#include "managementSceneObjects.h"


managementSceneObjects::managementSceneObjects()
{
	this->playDisplayImageManagementInstance.reset(new playDisplayImageManagement());

	this->ballInstance.reset(new ball(0, 0, this->playDisplayImageManagementInstance));
	this->barInstance.reset(new bar(30000, 0, this->playDisplayImageManagementInstance));
	this->eventOccurCheckAndExecuteInstance.reset(new eventOccurCheckAndExecute());
	this->hitJudgementBetweenObjectsInstance.reset(new hitJudgementBetweenObjects());

}


managementSceneObjects::~managementSceneObjects()
{
}
