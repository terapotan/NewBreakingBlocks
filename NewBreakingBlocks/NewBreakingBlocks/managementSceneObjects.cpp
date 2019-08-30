#include "managementSceneObjects.h"

managementSceneObjects::managementSceneObjects()
{
	playDisplayImageManagement playInstance;
	ball ballInstance(0, 0, playInstance);
	bar barInstance(30000, 0, playInstance);
	eventOccurCheckAndExecute eventInstance;

	//hitJudgementBetweenObjects hitJudgementInstance;

}


managementSceneObjects::~managementSceneObjects()
{
}
