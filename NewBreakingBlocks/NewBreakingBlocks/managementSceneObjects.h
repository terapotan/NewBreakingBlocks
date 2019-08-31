#pragma once
#include "ball.h"
#include "bar.h"
#include "hitJudgementBetweenObjects.h"
#include "userInputManagement.h"

//���̂��쐬����ꍇ�́AmanagementSceneObjects::getInstance()��p���邱�ƁB
//�Ăяo������std::shared_ptr<typeClass> = managementSceneObjects.typeClass�̌`���Ŏ󂯎�邱�ƁB
//���̃N���X�ɂ́A�����̃N���X�Ԃŋ��L���邱�Ƃ��Ó��ȃI�u�W�F�N�g�����邱�ƁB(��{�^�Aint�Echar���͂����ɒu���Ȃ�����)
class managementSceneObjects
{
private:
public:
	virtual ~managementSceneObjects();
	managementSceneObjects();

	std::shared_ptr<playDisplayImageManagement> playDisplayImageManagementInstance;
	std::shared_ptr<bar> barInstance;
	std::shared_ptr<ball> ballInstance;
	std::shared_ptr<userInputManagement> userInputManagementInstance;
	std::shared_ptr<hitJudgementBetweenObjects> hitJudgementBetweenObjectsInstance;

	managementSceneObjects(const managementSceneObjects&) = delete;
	managementSceneObjects& operator=(const managementSceneObjects&) = delete;
	managementSceneObjects(managementSceneObjects&&) = delete;
	managementSceneObjects& operator=(managementSceneObjects&&) = delete;

};



