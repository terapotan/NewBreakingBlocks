#include "setVelocityBarLeft.h"


setVelocityBarLeft::setVelocityBarLeft()
{
}

void setVelocityBarLeft::executeEventExecuteClass(managementSceneObjects& sceneObjects)
{
	std::shared_ptr<bar> barInstance = sceneObjects.barInstance;
	barInstance->setBarVelocity(-500);
	barInstance->moveBarAtTheSetVelocity();

}



setVelocityBarLeft::~setVelocityBarLeft()
{
}
