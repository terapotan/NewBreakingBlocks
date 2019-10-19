#include "setVelocityBarNoMove.h"


setVelocityBarNoMove::setVelocityBarNoMove()
{
}

void setVelocityBarNoMove::executeEventExecuteClass(managementSceneObjects& sceneObjects)
{
	std::shared_ptr<bar> barInstance = sceneObjects.barInstance;
	barInstance->setBarVelocity(0);
	barInstance->moveBarAtTheSetVelocity();

}


setVelocityBarNoMove::~setVelocityBarNoMove()
{
}
