#include "setVelocityBarRight.h"


setVelocityBarRight::setVelocityBarRight()
{
}

void setVelocityBarRight::executeEventExecuteClass(managementSceneObjects& sceneObjects)
{
	std::shared_ptr<bar> barInstance = sceneObjects.barInstance;
	barInstance->setBarVelocity(100);
	barInstance->moveBarAtTheSetVelocity();
}


setVelocityBarRight::~setVelocityBarRight()
{
}
