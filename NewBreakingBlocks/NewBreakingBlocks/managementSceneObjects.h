#pragma once
#include "ball.h"
#include "bar.h"
#include "hitJudgementBetweenObjects.h"
#include "userInputManagement.h"

//実体を作成する場合は、managementSceneObjects::getInstance()を用いること。
//呼び出し側はstd::shared_ptr<typeClass> = managementSceneObjects.typeClassの形式で受け取ること。
//このクラスには、複数のクラス間で共有することが妥当なオブジェクトを入れること。(基本型、int・char等はここに置かないこと)
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



