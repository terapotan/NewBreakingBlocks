#pragma once
#include "ball.h"
#include "bar.h"
#include "hitJudgementBetweenObjects.h"
#include "eventOccurCheckAndExecute.h"

//���̃N���X��1�񂵂����̂��쐬���邱�Ƃ��o���Ȃ�
//���̂��쐬����ꍇ�́AmanagementSceneObjects::getInstance()��p���邱�ƁB
//�Ăяo������std::shared_ptr<typeClass> = managementSceneObjects.typeClass�̌`���Ŏ󂯎�邱�ƁB
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

