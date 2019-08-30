#pragma once
#include "ball.h"
#include "bar.h"
#include "hitJudgementBetweenObjects.h"
#include "eventOccurCheckAndExecute.h"

//このクラスは1回しか実体を作成することが出来ない
//実体を作成する場合は、managementSceneObjects::getInstance()を用いること。
//呼び出し側はstd::shared_ptr<typeClass> = managementSceneObjects.typeClassの形式で受け取ること。
class managementSceneObjects
{
private:
	managementSceneObjects();
public:
	virtual ~managementSceneObjects();

	std::shared_ptr<playDisplayImageManagement> playDisplayImageManagementInstance;
	std::shared_ptr<bar> barInstance;
	std::shared_ptr<ball> ballInstance;
	std::shared_ptr<hitJudgementBetweenObjects> hitJudgementBetweenObjectsInstance;
	std::shared_ptr<eventOccurCheckAndExecute> eventOccurCheckAndExecuteInstance;

	managementSceneObjects(const managementSceneObjects&) = delete;
	managementSceneObjects& operator=(const managementSceneObjects&) = delete;
	managementSceneObjects(managementSceneObjects&&) = delete;
	managementSceneObjects& operator=(managementSceneObjects&&) = delete;

	static managementSceneObjects& getInstance() {
		static managementSceneObjects returnInstance;
		return returnInstance;
	}
};

