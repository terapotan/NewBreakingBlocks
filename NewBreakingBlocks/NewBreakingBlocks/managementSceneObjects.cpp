#include "managementSceneObjects.h"
#include "extendException.h"

managementSceneObjects::managementSceneObjects()
{
	//FIXME:以下の行をこのクラスから追い出したい
	//データを実際に挿入するクラスと、管理するクラスは別にしたい
	//そうすればシーンごとに使いまわしが出来る
	this->playDisplayImageManagementInstance.reset(new playDisplayImageManagement());

	this->ballInstance.reset(new ball(0, 0, this->playDisplayImageManagementInstance));
	this->barInstance.reset(new bar(30000, 0, this->playDisplayImageManagementInstance));
	
	this->userInputManagementInstance.reset(new userInputManagement());
}



managementSceneObjects::~managementSceneObjects()
{
}
